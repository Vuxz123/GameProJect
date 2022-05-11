#pragma once
#include "GameObject.h"
#include <functional>
#include <map>

class AbOb :
    public GameObject
{
protected:
	std::function<void(SDL_Event* Event)> actionevent;
	std::function<void()> actiontick;
	std::map<std::string, int> variable;

public:

	AbOb(){
		actionevent = [=](SDL_Event* Event) {
			return;
		};
		actiontick = [=]() {
			return;
		};
	}

	void setEvent(std::function<void(SDL_Event* Event)> _actionevent) {
		actionevent = _actionevent;
	}

	void setTick(std::function<void()> _actiontick) {
		actiontick = _actiontick;
	}

	void init(SDL_Renderer* renderer) override{}

	void render(SDL_Renderer* renderer) override{}

	void eventCheck(SDL_Event* Event) override{
		actionevent(Event);
	}

	void tick() override{
		actiontick();
	}

	void free() override{}

	void addVar(std::string name, int k) {
		variable.insert(std::pair<std::string, int>(name, k));
	}

	int getVar(std::string name) {
		return variable[name];
	}

	void setVar(std::string name, int k) {
		if (variable.find(name) != variable.end()) {
			variable[name] = k;
		}
		return;
	}
};

