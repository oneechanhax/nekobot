
/*
 *
 * This file is for maintaining control over the discord clients created by sleepydiscord
 *
 */

#include <mutex>
#include <iostream>
#include <sleepy_discord/websocketpp_websocket.h>
#include <sleepy_discord/snowflake.h>

#include "util/functional.hpp"
#include "intake.hpp"

#include "client.hpp"

// Needs to be pointers because virtual funcs
//std::vector<SleepyDiscord::DiscordClient*> clients;

// A slave client for the main bot
class CatDsClient : public SleepyDiscord::DiscordClient {
public:
  std::thread async_thread;
  CatDsClient(const char* token) : SleepyDiscord::DiscordClient(token, 2) {
    // Start our thread
    async_thread = std::thread(&SleepyDiscord::DiscordClient::run, this);
    async_thread.detach();
    // Add our client
    //clients.push_back(this);
  }
  using SleepyDiscord::DiscordClient::DiscordClient;
  void onMessage(SleepyDiscord::Message message) {
    if (message.author.ID == SleepyDiscord::Snowflake<SleepyDiscord::User>("119674592712196098")) {
      try {
        this->deleteMessage(message.channelID, message.ID);
        message.reply(this, message.content);
      } catch(...){}
    }
    MessageRecieve(message);
	}
  /*virtual ~CatDsClient(){
    // Remove the client from the array
    auto find = std::find(clients.begin(), clients.end(), this);
    if (find != clients.end())
      clients.erase(find);
  }*/
};

CatDsClient uhh("NDM1OTk0NTE1NDY0M/* kys fag*/PI7CvnGzYHxi3MIrfcL4o");
//ez
/*void NewClient(const char* token) {
  new CatDsClient(token);
}*/

// Try to send a message using one of the clients
SleepyDiscord::Message SendMessage(const char* cid, const char* text){
  /*for(auto i : clients) {
    try {
      // first one to successfully return gets it!
      return i->sendMessage(SleepyDiscord::Snowflake<SleepyDiscord::Channel>(cid), text, false);
    } catch(...) {}
  }*/
  // If nothing worked, we shold return something at least... please compare the result of this to SleepyDiscord::Message() to ensure nothing went wrong..
  return SleepyDiscord::Message();
}
