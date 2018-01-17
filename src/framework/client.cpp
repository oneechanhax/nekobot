
/*
 *
 *  This file is for handling many of the normal discord actions
 *
 *
 */

#include <iostream> // std::cout

#include "../../sleepy-discord/include/sleepy_discord/sleepy_discord.h" // The main discord interface
#include "events.hpp" // To call commands

#include "client.hpp"

// The main instance of the bot
class CatMainInstance : public SleepyDiscord::DiscordClient {
public:
  void onReady(std::string* ready) {
    std::cout(ready);
  }
  void onMessage(SleepyDiscord::Message message) {
    CallCommand(SleepyDiscord::Message message);
};
}
