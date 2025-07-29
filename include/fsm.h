#ifndef __MY_FSM__
#define __MY_FSM__

#include "state.h"
#include <memory>

/**
 * @brief 状态机也是一个单例的类，不需要进行实例化
 */
class FiniteStateMachine
{
public:
    void Handle()
    {
        _curState->Handle();
    }
private:
    std::shared_ptr<State> _curState;
};


#endif