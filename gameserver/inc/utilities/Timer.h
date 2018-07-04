#pragma once

#include <chrono>
#include <thread>

using namespace std;

template<typename Functor>
class Timer
{
 public:
  Timer(std::chrono::seconds duration, Functor functor) :
    running(false),
    functor(functor),
    interval(interval),
    threadptr(nullptr)
  {};

  void start();
  void stop();

 private:
  void loop();

  bool running;
  std::chrono::seconds interval;
  Functor functor;
  std::shared_ptr<std::thread> threadptr;
};

template<typename Functor>
void Timer<Functor>::start() {
  if (threadptr == nullptr) {
    running = true;
    threadptr = make_shared<thread>([this] () { loop(); });
  }
}

template<typename Functor>
void Timer<Functor>::stop() {
  running = false;

  threadptr->join();
  threadptr.reset();
}

template<typename Functor>
void Timer<Functor>::loop() {
  while (running) {
    functor();
    this_thread::sleep_for(interval);
  }
}
