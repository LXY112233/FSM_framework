#ifndef __MY_STATE__
#define __MY_STATE__

#include <iostream>
#include <memory>
#include <string>

class State {
public:
    std::shared_ptr<State> _nextState;
    virtual bool Handle() = 0;
    virtual ~State() {}
};

/**
 * @brief Begin为初始状态，在输入start后，进入A状态，no input single output
 */
class ConcreteStateBegin: public State {
public:
    static std::unique_ptr<ConcreteStateBegin> GetInstance() {
        
    }
    
    virtual bool Handle() override {
        std::cout << "current state is Begin, enter 'start', go to A state" << std::endl;      
          
        std::string user_input;
        std::cin >> user_input;

        do {
            if(user_input == "start")
            {
                
            }
            else
            {

            }
        } while (user_input != "start");
    }

private:
    static std::unique_ptr<ConcreteStateBegin> _instance;
    //私有化构造和析构
    ConcreteStateBegin();
    ~ConcreteStateBegin();
    //禁止拷贝构造和赋值运算
    ConcreteStateBegin(const ConcreteStateBegin& rhs) = delete;
    ConcreteStateBegin& operator = (const ConcreteStateBegin& rhs) = delete;
};






/**
 * @brief A状态下，输入A后，进入B状态，multiple input single output
 */
class ConcreteStateA : public State
{

};





/**
 * @brief B状态下，输入B后，进入C状态，single input insgle output
 */
class ConcreteStateB : public State
{

};





/**
 * @brief C状态下，输入C后，进入A状态，输入end后，进入end状态，single input multiple output
 */
class ConcreteStateC : public State
{

};





/**
 * @brief End状态下，打印“current state is end，quit the program”后，结束程序
 */
class ConcreteStateEnd: public State
{

};

#endif