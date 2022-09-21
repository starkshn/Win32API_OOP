#pragma once

class Object;

struct EVENT
{
	EVENT_TYPE	_eventType;
	DWORD_PTR	_objectPtr;
	DWORD_PTR	_objectType;
};

class EventManager
{
	SINGLE(EventManager);

private:
	vector<EVENT>	_vecEvents;
	vector<Object*> _vecDead;

private:
	void ExcuteEvent(const EVENT& e);

public:
	void update();

public:
	void AddEvent(const EVENT& e) { _vecEvents.push_back(e); }



};

