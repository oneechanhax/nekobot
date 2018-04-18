
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
SleepyDiscord::Message SendMessage(const char*, const char*, bool);
