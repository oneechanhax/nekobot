
/*
 *
 * This is client.cpps header.
 * You will interface with discord through here.
 *
 * You wont have access to the discord clients directly but for multiclient functionality we do this.
 *
 */

#include <sleepy_discord/sleepy_discord.h>

#include "util/functional.hpp"

// Try to send a message using one of the clients
SleepyDiscord::Message SendMessage(const char*, const char*);

// Macro for replying with with messages
inline SleepyDiscord::Message ReplyMessage(const SleepyDiscord::Message& message, const char* text){
  return SendMessage(((const std::string&)message.channelID).c_str(), text);
}

void NewClient(const char* token);
