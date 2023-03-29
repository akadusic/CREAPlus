Requirements:
0. CMake - At least 3.0.0 version. I used 3.25.5 version. 

1. OpenSSL library 
  You can find OpenSSL library on this link: https://github.com/openssl/openssl. There you can find out how to build and install this library.
  Used for function which converts strings to hash value. 

2. Clang(15.0.7 version) or GCC(12.2.1) compiler - I compiled on both and it worked well.
 
3. Steps to run program:
  a) Unzip the creaplustask.zip.
  b) cd creaplustask
  c) mkdir build && cd build
  d) cmake .. 
  e) make
  f) ./creaplustask
