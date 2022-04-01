#pragma once
#include <memory>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <algorithm>
#include <functional>


//Queue class
//Cannot just use std::queue as we we require locks to prevent overlapping
template <typename T>
class Queue
{
private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_cond;
public:
    T Pop(){
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cond.wait(lock, [this]{return !m_queue.empty();});
        auto val = m_queue.front();
        m_queue.pop();
        return val;
    };

    void Pop(T& i){
        std::unique_lock<std::mutex> lock(m_mutex);
        if (m_queue.empty() == true){
            return;
        }

        i = m_queue.front();
        m_queue.pop();
    };

    void Push(const T& i){
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.push(i);
        m_cond.notify_one();
    };

    Queue() = default;
    Queue(const Queue&) = delete;
    Queue operator=(const Queue&) = delete;
};