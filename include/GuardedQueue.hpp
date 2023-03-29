#pragma once

#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>

namespace DataModel {
class GuardedQueue {
  public:
  void writeToQueue(const std::string&);
  void readFromQueue(); 
  friend std::string stringToSSH(const std::string&);

  private:
  std::queue<std::string> messagesQueue_;
  std::mutex messagesMutex_;
  std::condition_variable conditionVariable_;
};
} /* DataModel */
