#ifndef __MY_CONTEXT__
#define __MY_CONTEXT__

#include "state.h"

#include <memory>
#include <iostream>

class Context
{
public:
    static std::shared_ptr<Context> GetInstance() {
        if (_instance == nullptr)
            _instance = std::make_shared<Context>(ConcreteStateBegin::GetInstance());
        return _instance;
    }

    void Request() {
        if (_currentState == nullptr)
        {
            std::cout << "[Context] [ERROR] currentState is null_ptr" << std::endl;
            return;
        }
        std::cout << "[Context] Current State: " << _currentState->GetStateName() << std::endl;
        std::shared_ptr<State> nextState = _currentState->Handle();
        TransitionTo(nextState);
    }
private:    
    void TransitionTo(std::shared_ptr<State> nextState_in) {
        std::cout << "[Context] Transition: " << _currentState->GetStateName() 
                  << " -> " << nextState_in->GetStateName() << std::endl;
        _currentState = nextState_in;
    }
private:
    std::shared_ptr<State> _currentState;

    static std::shared_ptr<Context> _instance;
    //私有化构造和析构
    Context(std::shared_ptr<State> initstate) 
        : _currentState(initstate)
    { }
    ~Context() {}
    //禁止拷贝构造和赋值运算
    Context(const Context& rhs) = delete;
    Context& operator = (const Context& rhs) = delete;
};//class Context
std::shared_ptr<Context> Context::_instance = nullptr;

#endif