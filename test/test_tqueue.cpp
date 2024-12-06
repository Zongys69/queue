#include "tqueue.h"
#include <gtest.h>

TEST(Queue, can_create_empty_queue) {
    ASSERT_NO_THROW(Queue<int> q(5)); // ”казываем емкость, пуста€ очередь.
}

TEST(Queue, can_create_queue_with_specified_capacity) {
    ASSERT_NO_THROW(Queue<int> q(10));
}


TEST(Queue, can_create_queue_by_copy) {
    Queue<int> q(5);
    q.push(1);
    q.push(2);

    Queue<int> q1(q); 

    ASSERT_EQ(q1.front(), 1); 
    q1.pop();
    ASSERT_EQ(q1.front(), 2);
    q1.pop();
    ASSERT_TRUE(q1.isEmpty());
}

TEST(Queue, can_push_element) {
    Queue<int> q(5);
    q.push(1);
    ASSERT_EQ(q.front(), 1);
}

TEST(Queue, can_pop_element) {
    Queue<int> q(5);
    q.push(1);
    q.push(2);
    q.pop();
    ASSERT_EQ(q.front(), 2);
}

TEST(Queue, cant_pop_element_from_empty_queue) {
    Queue<int> q(5);
    ASSERT_ANY_THROW(q.pop());
}

TEST(Queue, can_get_size_of_queue) {
    Queue<int> q(15);
    for (int i = 0; i < 15; ++i) {
        q.push(i);
    }
    ASSERT_EQ(q.getSize(), 15);
}

TEST(Queue, can_get_size_after_pop) {
    Queue<int> q(15);
    for (int i = 0; i < 15; ++i) {
        q.push(i);
    }
    q.pop();
    ASSERT_EQ(q.getSize(), 14);
}

TEST(Queue, can_watch_element_by_front) {
    Queue<int> q(5);
    q.push(1);
    q.push(2);
    ASSERT_EQ(q.front(), 1);
}


TEST(Queue, can_get_size_after_front) {
    Queue<int> q(5);
    q.push(1);
    q.push(2);
    ASSERT_EQ(q.getSize(), 2);
}

TEST(Queue, can_use_isEmpty) {
    Queue<int> q(5);
    ASSERT_TRUE(q.isEmpty());
}

TEST(Queue, cant_use_isEmpty_from_not_empty_queue) {
    Queue<int> q(5);
    q.push(1);
    ASSERT_FALSE(q.isEmpty());
}

TEST(Queue, is_full) {
    Queue<int> q(2);
    q.push(1);
    q.push(2);
    ASSERT_TRUE(q.isFull());
}

TEST(Queue, is_not_full) {
    Queue<int> q(2);
    q.push(1);
    ASSERT_FALSE(q.isFull());
}

TEST(Queue, test_push_pop) {
    Queue<int> s(3); 

    s.push(1);
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(1);
    s.pop();
    s.pop();

    EXPECT_EQ(1, s.top());
}