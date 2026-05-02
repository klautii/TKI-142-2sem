#include "CppUnitTest.h"﻿
#include "../decision/PriorityQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriorityQueueTests
{
    TEST_CLASS(PriorityQueueConstructorTests)
    {
    public:
        TEST_METHOD(DefaultConstructor_CreatesEmptyQueue)
        {
            PriorityQueue pq;

            Assert::IsTrue(pq.isEmpty());
            Assert::AreEqual(0, (int)pq.getSize());
        }

        TEST_METHOD(InitializerListConstructor_CreatesQueueWithElements)
        {
            PriorityQueue pq = { {1, 3}, {2, 1}, {3, 5} };

            Assert::IsFalse(pq.isEmpty());
            Assert::AreEqual(3, (int)pq.getSize());

            int value = 0;
            pq.peekMax(value);
            Assert::AreEqual(3, value);
        }
    };

    TEST_CLASS(PriorityQueueOperationTests)
    {
    public:
        TEST_METHOD(Push_AddsElementsWithPriority)
        {
            PriorityQueue pq;
            pq.push(10, 2);
            pq.push(20, 3);
            pq.push(30, 1);

            Assert::AreEqual(3, (int)pq.getSize());

            int value = 0;
            pq.peekMax(value);
            Assert::AreEqual(20, value);
        }

        TEST_METHOD(PopMax_RemovesAndReturnsHighestPriority)
        {
            PriorityQueue pq = { {10, 2}, {20, 3}, {30, 1} };
            int value = 0;

            Assert::IsTrue(pq.popMax(value));
            Assert::AreEqual(20, value);
            Assert::AreEqual(2, (int)pq.getSize());

            Assert::IsTrue(pq.popMax(value));
            Assert::AreEqual(10, value);
            Assert::AreEqual(1, (int)pq.getSize());

            Assert::IsTrue(pq.popMax(value));
            Assert::AreEqual(30, value);
            Assert::IsTrue(pq.isEmpty());

            Assert::IsFalse(pq.popMax(value));
        }
    };

    TEST_CLASS(PriorityQueueOperatorTests)
    {
    public:
        TEST_METHOD(AssignmentOperator_CopiesQueue)
        {
            PriorityQueue pq1 = { {1, 1}, {2, 2}, {3, 3} };
            PriorityQueue pq2;

            pq2 = pq1;

            Assert::AreEqual(pq1.getSize(), pq2.getSize());
            Assert::AreEqual(pq1.toString(), pq2.toString());
        }

        TEST_METHOD(MoveOperator_MovesQueue)
        {
            PriorityQueue pq1 = { {1, 1}, {2, 2}, {3, 3} };
            std::string originalStr = pq1.toString();
            size_t originalSize = pq1.getSize();

            PriorityQueue pq2 = std::move(pq1);

            Assert::AreEqual(originalSize, pq2.getSize());
            Assert::AreEqual(originalStr, pq2.toString());
            Assert::IsTrue(pq1.isEmpty());
        }

        TEST_METHOD(ShiftLeftOperator_AddsElement)
        {
            PriorityQueue pq;
            pq << std::make_pair(10, 2);
            pq << std::make_pair(20, 3);

            Assert::AreEqual(2, (int)pq.getSize());

            int value = 0;
            pq.peekMax(value);
            Assert::AreEqual(20, value);
        }

        TEST_METHOD(ShiftRightOperator_ExtractsElement)
        {
            PriorityQueue pq = { {10, 2}, {20, 3} };
            std::pair<int, int> element;

            pq >> element;

            Assert::AreEqual(20, element.first);
            Assert::AreEqual(3, element.second);
            Assert::AreEqual(1, (int)pq.getSize());
        }
    };

    TEST_CLASS(PriorityQueueUtilityTests)
    {
    public:
        TEST_METHOD(ToString_ReturnsCorrectFormat)
        {
            PriorityQueue pq = { {1, 3}, {2, 1}, {3, 2} };
            std::string expected = "(1, 3) -> (3, 2) -> (2, 1)";

            Assert::AreEqual(expected, pq.toString());
        }

        TEST_METHOD(Clear_RemovesAllElements)
        {
            PriorityQueue pq = { {1, 1}, {2, 2}, {3, 3} };

            pq.clear();

            Assert::IsTrue(pq.isEmpty());
            Assert::AreEqual(0, (int)pq.getSize());
        }

        TEST_METHOD(PeekMethods_DoNotRemoveElements)
        {
            PriorityQueue pq = { {10, 2}, {20, 3}, {30, 1} };
            int value = 0;

            Assert::IsTrue(pq.peekMax(value));
            Assert::AreEqual(20, value);
            Assert::AreEqual(3, (int)pq.getSize());

            Assert::IsTrue(pq.peekMin(value));
            Assert::AreEqual(30, value);
            Assert::AreEqual(3, (int)pq.getSize());
        }
    };
}