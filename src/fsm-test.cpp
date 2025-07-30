/**
 * @file fsm-test.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-07-30
 * 
 * @copyright Copyright (c) 2025
 * 
 * @note 
 * 改善的方向：
 * 用图这个数据结构，允许提前设置好状态跳转
 * 之后就完全不需要在ConcreteState中的Handle函数给出要切入的下一个状态
 * 输入一个curState、一个index(以支持多output的state)
 * 获得一个nexState
 * 
 * ConcreteState的Handle函数给出具体状态下的任务处理过程
 * Context负责调用起具体函数的Handle方法，以及自动进行状态跳转
 * 状态跳转图负责给出具体逻辑下handle函数执行完后的下一个状态
 * 
 * 变化：ConcreteState、ConcreteState的Handle方法，状态跳转图
 * 稳定：不同状态下不同动作的调用、动作结束后状态的跳转
 */

#include <iostream>

int main()
{
    std::cout << "hello fsm" << std::endl; 
}