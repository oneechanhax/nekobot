
/*
 *
 * Intake
 */

#include <sleepy_discord/message.h>

#include "util/functional.hpp" // CMEvent

// For use by client.cpp to give us the messages as they come in
void MessageRecieve(const SleepyDiscord::Message&);

// Register your function to recieve a message when one is recieved
extern CMEvent<const SleepyDiscord::Message&> message_event;
