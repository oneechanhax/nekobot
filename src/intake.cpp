
/*
 *
 * This file is responcible for intaking messages from discord and and processing them through events
 *
 */

#include <algorithm>
#include <mutex>

#include "util/functional.hpp"
#include "util/chrono.hpp"

#include "intake.hpp"

// We use this to prevent multiple clients from activating message event multiple times
CatFastMap<SleepyDiscord::Message, CatTimer> message_pool;

CMEvent<const SleepyDiscord::Message&> message_event;

// We process it through the pool to make sure we dont get duplicates
void MessageRecieve(const SleepyDiscord::Message& intake) {
  static std::mutex lock;
  std::lock_guard<std::mutex> guard(lock);

  // Clear out old messages
  for(auto it = message_pool.begin(); it != message_pool.end(); it++)
    if(it->second.CheckTime(std::chrono::seconds(5)))
      message_pool.erase(it->first);

  // Check if it exists already
  auto find = message_pool.find(intake);
  if(find != message_pool.end())
    return;

  // Register the event
  CatTimer timer;
  timer.Reset(); // reset to ensure timer has the time of NOW!
  message_pool.insert({intake, timer});
  printf("Diks: %s", intake.content);
  message_event(intake);
}
