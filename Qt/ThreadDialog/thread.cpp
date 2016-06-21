#include "thread.h"
#include<iostream>

Thread::Thread()
{
    stopped = false;
}
void Thread::run()
{
    while(!stopped)
        std::cerr << qPrintable(messageStr);
    stopped = false;
    std::cerr << std::endl;
}
void Thread::stop()
{
    stopped = true;
}
void Thread::setMessage(const QString &message)
{
    messageStr = message;
}
