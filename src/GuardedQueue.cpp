#include <iostream>
#include <openssl/evp.h>
#include <GuardedQueue.hpp> 
#include <sstream>
#include <iomanip>


using namespace DataModel;

std::string stringToSSH(const std::string& value){
  const EVP_MD* md = EVP_sha256();
  unsigned char hash[EVP_MAX_MD_SIZE];
  unsigned int hash_len;
  EVP_Digest(value.c_str(), value.size(), hash, &hash_len, md, NULL);

  std::stringstream ss;
  for(auto i = 0; i != hash_len; ++i){
    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned int>(hash[i]); 
  }

  return ss.str();
}

void GuardedQueue::readFromQueue(){
  std::unique_lock lock(messagesMutex_); 
  conditionVariable_.wait(lock, [&]{ return !messagesQueue_.empty(); });
  std::cout << "Message value is: " << messagesQueue_.front() << std::endl;
  std::cout << "Hashed value of message is: " << stringToSSH(messagesQueue_.front()) << std::endl; 
  messagesQueue_.pop();
}

void GuardedQueue::writeToQueue(const std::string& value){
  std::unique_lock lock(messagesMutex_);
  messagesQueue_.push(value);
  conditionVariable_.notify_one();
}
