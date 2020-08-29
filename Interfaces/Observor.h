#pragma once
#include <list>

class IObservor
{
public:
	virtual ~IObservor() {};
	virtual void Update() = 0;
};

class ISubject
{
public:
	virtual ~ISubject() {};
	virtual void Attach(IObservor* observor) = 0;
	virtual void Detach(IObservor* ovservor) = 0;
	virtual void Notify() = 0;
};

class Subject : public ISubject
{
public:
	virtual ~Subject(){}

	void Attach(IObservor* observor) override {
		observors.push_back(observor);
	}
	void Detach(IObservor* observor) override {
		observors.remove(observor);
	}
	void Notify() override {
		auto iterator = observors.begin();
		while (iterator != observors.end())
		{
			(*iterator)->Update();
			++iterator;
		}
	}

private:
	std::list<IObservor*> observors;
};