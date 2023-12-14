#include "pch.h"
#include "CppUnitTest.h"
#include "../пр11.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest111
{
    TEST_CLASS(UnitTest111)
    {
    public:

        TEST_METHOD(TestMethod1)
        {

            char testFileName[] = "testFileProcess.bin";
            char testOutputFileName[] = "testFileOutput.bin";

            int inputData[] = { 5, 7 };
            int expectedOutput[] = { 5, 12 };

            std::ofstream outfile(testFileName, std::ios::binary);
            for (const auto& num : inputData) {
                outfile.write(reinterpret_cast<const char*>(&num), sizeof(num));
            }
            outfile.close();

            ProcessBIN1(testFileName, testOutputFileName);

            std::ifstream file(testOutputFileName);
            Assert::IsTrue(file.good(), L"Output file not created.");

            int result[2];
            file.read(reinterpret_cast<char*>(&result), sizeof(result));

            for (size_t i = 0; i < 2; ++i) {
                Assert::AreEqual(expectedOutput[i], result[i]);

            }
        }
        };
    }

