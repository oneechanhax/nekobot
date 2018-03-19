
// Command Class
class Command {
	constructor(command_callers, description, permissions, callback) {
		this.command_callers = command_callers;
		this.description = description;
		this.permissions = permissions;
		this.callback = callback;
		this.registered = false;
	}
	Register() {
		this.registered = true;
	}
}

module.exports = Command;
