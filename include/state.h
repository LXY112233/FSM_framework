#ifndef __MY_STATE__
#define __MY_STATE__

#include <iostream>
#include <memory>
#include <string>

class State 
{
public:
    //获取状态名，方便调试
    virtual std::string GetStateName() const = 0;
    //Handle()，负责逻辑处理
    virtual std::shared_ptr<State> Handle() = 0;
    virtual ~State() {}
};

/**
 * @brief Begin为初始状态，在输入start后，进入A状态，no input single output
 */
class ConcreteStateBegin: public State 
{
public:
    // GetInstance方法不支持多线程环境去调用，如果同时进入if(_instance == nullptr)的判断，会构造出多个对象
    static std::shared_ptr<ConcreteStateBegin> GetInstance() 
    {
        if (_instance == nullptr)
        {
            _instance = std::make_shared<ConcreteStateBegin>();
        }
        return _instance;
    }

    virtual std::string GetStateName() const override {
        return "Begin";
    }
    
    virtual std::shared_ptr<State> Handle() override 
    {
        std::cout << "current state is Begin, enter 'start', go to A state" << std::endl;      
        std::string user_input;
        while (true)
        {
            std::cin >> user_input;
            if(user_input == "start")
            {
                //State执行完操作了，返回要切入的下一个状态
                return ConcreteStateA::GetInstance();
                break;
            }
            else
            {
                std::cout << "Invalid input, please enter 'start'" << std::endl;
            }
        }
    }

private:
    static std::shared_ptr<ConcreteStateBegin> _instance;
    //私有化构造和析构
    ConcreteStateBegin() {}
    ~ConcreteStateBegin() {}
    //禁止拷贝构造和赋值运算
    ConcreteStateBegin(const ConcreteStateBegin& rhs) = delete;
    ConcreteStateBegin& operator = (const ConcreteStateBegin& rhs) = delete;
};
//_instance字段虽然是private的，但是static修饰后允许类外初始化一次，这并不是类外访问，这是初始化
std::shared_ptr<ConcreteStateBegin> ConcreteStateBegin::_instance = nullptr; 






/**
 * @brief A状态下，输入A后，进入B状态，multiple input single output
 */
class ConcreteStateA : public State
{
public:
static std::shared_ptr<ConcreteStateA> GetInstance() 
    {
        if (_instance == nullptr)
        {
            _instance = std::make_shared<ConcreteStateA>();
        }
        return _instance;
    }
private:
    static std::shared_ptr<ConcreteStateA> _instance;
    //私有化构造和析构
    ConcreteStateA() {}
    ~ConcreteStateA() {}
    //禁止拷贝构造和赋值运算
    ConcreteStateA(const ConcreteStateA& rhs) = delete;
    ConcreteStateA& operator = (const ConcreteStateA& rhs) = delete;
};
//_instance字段虽然是private的，但是static修饰后允许类外初始化一次，这并不是类外访问，这是初始化
std::shared_ptr<ConcreteStateA> ConcreteStateA::_instance = nullptr; 



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