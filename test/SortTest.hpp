/*
            This file is part of: 
               algorithm_cpp
            https://github.com/yangcancai/algorithm_cpp
   Copyright (c) 2020 algorithm_cpp. All rights reserved.
   Created by yangcancai  on 2020/7/18.
   algorithm_cpp is open-source software and you can redistribute it and/or modify
   it under the terms of the License; besides, anyone who use this file/software must include this copyright announcement.
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
       http://www.apache.org/licenses/LICENSE-2.0
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#ifndef ALGORITHM_CPP_SORTTEST_H
#define ALGORITHM_CPP_SORTTEST_H
#include <gtest/gtest.h>
#include "sort/ACShellSort.h"
#include "sort/ACQuickSort.h"
#include "sort/ACInsertSort.h"
#define SAFE_DELETE(p) do { if(p) delete(p);p=nullptr; } while(0)
class SortTest : public ::testing::Test{
protected:
    SortTest():m_pData(nullptr),m_pQuickSort(nullptr),m_pInsertSort(nullptr),m_pShellSort(nullptr){

    }
    void SetUp() override {
        srand((unsigned int)time(nullptr));
        m_pQuickSort = new ACQuickSort<int,int>();
        m_pShellSort = new ACShellSort<int,int>();
        m_pInsertSort = new ACInsertSort<int,int>();
    }
    void TearDown() override {
            SAFE_DELETE(m_pInsertSort);
            SAFE_DELETE(m_pQuickSort);
            SAFE_DELETE(m_pShellSort);
            SAFE_DELETE(m_pData);
    }
    void DoRandAndSort(ACISort<int,int>* pSort, const int &n, const std::string &who){
        for (int i = n-1; i >= 0 ; i--) {
            m_pData[i] = rand();
        }
        std::string BeforeSort = ShowResult(n);
        pSort->sort(m_pData, n);
        DoCheck(n, BeforeSort, who);
    }
    void DoCheck(const int &n, const std::string &BeforeSort, const std::string &who) {
        for (int j = 0; j < n - 1; ++j) {
            ASSERT_LE(m_pData[j], m_pData[j + 1]) <<
            "who:" << who << std::endl <<
            "BeforeSort:" << BeforeSort << std::endl
            << "show result:" << ShowResult(n);
        }
    }
    const std::string ShowResult(const int &n){
        std::string result;
        for (int i = 0; i < n - 1; ++i) {
           result += std::to_string(m_pData[i]) + ",";
        }
        result += std::to_string(m_pData[n-1]);
        return result;
    }
    void DoTask(){
        for (int i = 0; i < 1000; ++i) {
            int n = rand()%100;
            SAFE_DELETE(m_pData);
            m_pData = new int[n];
            DoRandAndSort(m_pShellSort, n, "ACShellSort");
            DoRandAndSort(m_pInsertSort, n, "ACInsertSort");
            DoRandAndSort(m_pQuickSort, n, "ACQuickSort");
        }
    }
    ACISort<int,int> *m_pShellSort;
    ACISort<int, int> *m_pQuickSort;
    ACISort<int, int> *m_pInsertSort;
    int* m_pData;
};
TEST_F(SortTest, IsEmptyInitiallly){
    EXPECT_EQ(m_pData, nullptr);
    EXPECT_NE(m_pShellSort, nullptr);
    EXPECT_NE(m_pInsertSort, nullptr);
    EXPECT_NE(m_pQuickSort, nullptr);
}
TEST_F(SortTest, SortWorks){
     DoTask();
}
#endif //ALGORITHM_CPP_SORTTEST_H
