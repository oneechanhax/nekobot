
/*
 *
 * This file is for maintaining control over the discord clients created by sleepydiscord
 *
 */

#include <vector>
#include <iostream>
#include <websocketpp_websocket.h>

class CatDsClient : public SleepyDiscord::DiscordClient {
    private:
    void onReady() {
      puts("ready\n");
    }
};


std::vector<CatDsClient> clients;
