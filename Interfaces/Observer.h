#pragma once
#include <list>

class IObserver {
public:
	virtual ~IObserver() = default;
	virtual void Update() = 0;
};

class ISubject {
public:
	virtual ~ISubject() = default;
	virtual void Attach(IObserver* observer) = 0;
	virtual void Detach(IObserver* observer) = 0;
	virtual void Notify() = 0;
};

class Subject : public ISubject {
public:
	~Subject() override = default;

	void Attach(IObserver* observer) override {
		observers.push_back(observer);
	}
	void Detach(IObserver* observer) override {
		observers.remove(observer);
	}
	void Notify() override {
		auto iterator = observers.begin();
		while (iterator != observers.end())
		{
			(*iterator)->Update();
			++iterator;
		}
	}

private:
	std::list<IObserver*> observers;
};