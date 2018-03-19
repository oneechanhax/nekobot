
/*
 *
 * Nekobot
 *
 */

// Requires
const rq_discordjs = require('discord.js');

// Util functions
Function IsArray(input) {
	try
		if (typeof data == 'object' && typeof data.length == 'number')
			return true;
	return false;
}

// Events
class s_EventMgr {
	constructor() {
		// Event Callbacks
		var message_rcv_events = [];
		// Event Recieves
		this.message_rcv = (message) => {
		}
	}
}
var EventMgr = new s_EventMgr;

// Command Class
class Command {
	constructor(command_callers, description, permissions, args, callback) {
		this.command_callers = command_callers;
		this.description = description;
		this.permissions = permissions;
		this.args = args;
		this.callback = callback;
		this.registered = false;
	}
	Register(event_mgr) {
		this.event_mgr = event_mgr; // Save this to destruct later
		this.registered = true;
	}
	event(msg) {
		// Do stuff
		// Test for perms
		// Create args
		// Call callback
		//this.callback(msg, args)
	}
	destructor() {
		this.event_mgr;
	}
}

// Mods!
class Mod {
	constructor(name, description) {
		this.name = name;
		this.description = description;
		this.commands = [];
		this.events = [];
	}
	// Used to register a command in a dirived class
	registerCommand(command) {
		this.instance.commands.addCommand(this.id, command);
	}
	//destructor
}


// An instance of an account
class s_BotInstance {
	constructor(token) {
		// Setup the discord client
		this.DSClient = new rq_discordjs.Client();
		this.DSClient.login(token);
		this.DSClient.on("ready", () => { console.log('Ready as ${DiscordClient.user.tag}!'); });
		this.DSClient.on('message', (message) => { EventMgr.message_rcv(message);	});
		//this.DSClient.on('guildMemberAdd', (member) => { try { instanceManager.get(member.guild).events.emit('guildMemberAdd', member); } catch (e) { console.log(e); }});
		//this.DSClient.on('guildMemberRemove', (member) => { try { instanceManager.get(member.guild).events.emit('guildMemberRemove', member); } catch (e) { console.log(e); }});
	}
	destructor() {
		delete(this.DSClient);
	}
}

// Login to our main bot
const { token } = require('./data/auth.json');
var main_instance = new s_BotInstance(token);
