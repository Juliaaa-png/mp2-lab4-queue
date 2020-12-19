#include"gtest.h"
#include "../Queue/Queue.h"

TEST(Queue, can_create_queue)
{
    ASSERT_NO_THROW(TQueue<int> a(3));
}

TEST(Queue, throws_when_create_queue_with_negative_size)
{
    ASSERT_ANY_THROW(TQueue<int> a(-1));
}

TEST(Queue, can_get_size)
{
    TQueue<int> a(3);
    a.Push(3);
    ASSERT_NO_THROW(a.GetSize());
    EXPECT_EQ(1, a.GetSize());
}

TEST(Queue, can_copy_the_queue)
{
    TQueue<int> a(3);
    a.Push(3);
    ASSERT_NO_THROW(TQueue<int> copy(a));
}


TEST(Queue, can_assign_queue_of_the_same_data_types_and_size)
{
    TQueue<int> a(3);
    TQueue<int> b(3);
    a.Push(1);
    a.Push(5);
    b.Push(2);
    ASSERT_NO_THROW(b = a);
    EXPECT_EQ(a.GetSize(), b.GetSize());
    EXPECT_EQ(a.GetHead(), b.GetHead());
}
TEST(Queue, can_assign_queue_of_the_same_data_types_and_different_size)
{
    TQueue<int> a(5);
    TQueue<int> b(3);
    a.Push(1);
    a.Push(5);
    b.Push(2);
    ASSERT_NO_THROW(b = a);
    EXPECT_EQ(a.GetSize(), b.GetSize());
    EXPECT_EQ(a.GetHead(), b.GetHead());
}

TEST(Queue, can_compare_queue)
{
    TQueue<int> a(3);
    TQueue<int> b(3);
    a.Push(5);
    b.Push(3);
    ASSERT_NO_THROW(b == a);
}

TEST(Queue, comparing_the_queue_with_itself_gives_the_truth)
{
    TQueue<int> a(3);
    EXPECT_EQ(true, a == a);
}

TEST(Queue, can_check_the_queue_for_emptiness)
{
    TQueue<int> a(3);
    ASSERT_NO_THROW(a.Empty());
}

TEST(Queue, initially_the_queue_is_empty)
{
    TQueue<int> a(3);
    EXPECT_EQ(true, a.Empty());
}

TEST(Queue, can_check_the_queue_for_completeness)
{
    TQueue<int> a(3);
    ASSERT_NO_THROW(a.Full());
}

TEST(Queue, if_the_queue_size_is_equal_to_the_size_then_the_stack_is_full)
{
    int size = 2;
    TQueue<int> a(size);
    a.Push(1);
    a.Push(2);
    EXPECT_EQ(a.GetSize(), size);
    EXPECT_EQ(true, a.Full());
}

TEST(Queue, can_add_item_to_incomplete_queue)
{
    TQueue<int> a(3);
    ASSERT_NO_THROW(a.Push(3));
}

TEST(Queue, cant_add_item_to_the_full_queue)
{
    TQueue<int> a(1);
    a.Push(3);
    ASSERT_ANY_THROW(a.Push(3));
}

TEST(Queue, can_see_what_is_at_the_top_of_non_empty_queue)
{
    TQueue<int> a(3);
    a.Push(3);
    ASSERT_NO_THROW(a.SeeHead());
}


TEST(Queue, cant_look_at_the_top_of_empty_queue)
{
    TQueue <int> a(3);
    ASSERT_ANY_THROW(a.GetHead());
}

TEST(Queue, can_take_an_element_from_non_empty_non_empty_queue)
{
    TQueue<int> a(3);
    a.Push(3);
    ASSERT_NO_THROW(a.GetHead());
}

TEST(Queue, cant_take_an_element_from_an_empty_stack)
{
    TQueue<int> a(3);
    ASSERT_ANY_THROW(a.GetHead());
}