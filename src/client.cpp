
/*
 *
 * This file is for maintaining control over the discord clients created by sleepydiscord
 *
 */

#include <iostream>
#include <sleepy_discord/websocketpp_websocket.h>
#include <sleepy_discord/snowflake.h>

#include "util/functional.hpp"
#include "intake.hpp"

#include "client.hpp"

// Needs to be pointers because virtual funcs
std::vector<SleepyDiscord::DiscordClient*> clients;

// A slave client for the main bot
class CatDsClient : public SleepyDiscord::DiscordClient {
public:
  std::thread async_thread;
  CatDsClient(const char* token) : SleepyDiscord::DiscordClient(token, 2) {
    // Start our thread
    async_thread = std::thread(&SleepyDiscord::DiscordClient::run, this);
    async_thread.detach();
    // Add our client
    clients.push_back(this);
  }
  using SleepyDiscord::DiscordClient::DiscordClient;
  void onMessage(SleepyDiscord::Message message) {
    MessageRecieve(message);
	}
  virtual ~CatDsClient(){
    // Remove the client from the array
    auto find = std::find(clients.begin(), clients.end(), this);
    if (find != clients.end())
      clients.erase(find);
  }
};

// slaves
CatDsClient lol_bad1("NDM1NjY5MzQ0OT/*lol bad*/rhFouqTo6hU3qOBcgDErgu4-JyY_E");
CatDsClient lol_bad2("NDM1OTk0NTE1NDY0MTI2/*cant see them huh...*/SF6hXC0ALw");

// Try to send a message using one of the clients
SleepyDiscord::Message SendMessage(const char* cid, const char* text){
  for(auto i : clients) {
    try {
      // first one to successfully return gets it!
      return i->sendMessage(SleepyDiscord::Snowflake<SleepyDiscord::Channel>(cid), text, false);
    } catch(...) {}
  }
  // If nothing worked, we shold return something at least... please compare the result of this to SleepyDiscord::Message() to ensure nothing went wrong..
  return SleepyDiscord::Message();
}
