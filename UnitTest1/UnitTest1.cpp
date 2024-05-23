#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12_12_TREE/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestCreateNode)
        {
            Note testPerson = { "Doe", "John", "1234567890", {1, 4, 1990} };

            TreeNode* newNode = createNode(testPerson);

            Assert::IsNotNull(newNode);

            Assert::AreEqual(testPerson.lastName, newNode->data.lastName);
            Assert::AreEqual(testPerson.firstName, newNode->data.firstName);
            Assert::AreEqual(testPerson.phoneNumber, newNode->data.phoneNumber);
            Assert::AreEqual(testPerson.birthDate[0], newNode->data.birthDate[0]);
            Assert::AreEqual(testPerson.birthDate[1], newNode->data.birthDate[1]);
            Assert::AreEqual(testPerson.birthDate[2], newNode->data.birthDate[2]);

            Assert::IsNull(newNode->left);
            Assert::IsNull(newNode->right);

            delete newNode;
        }

    };
}
