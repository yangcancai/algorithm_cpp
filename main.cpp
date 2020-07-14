/*
            This file is part of: 
               algorithm_cpp
            https://github.com/yangcancai/algorithm_cpp
   Copyright (c) 2020 algorithm_cpp. All rights reserved.
   Created by yangcancai  on 2020/7/12.
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
#include <iostream>
#include "sort/ACISort.h"
#include "sort/ACShellSort.h"
#include "sort/ACQuickSort.h"
void do_task(ACISort<int,int> *s){
    int data[] = {1000,-1,1,102,1,-1,7};
    int data1[] = {1,2,3,4,5,6,7,8};
    int data2[] = {8,7,6,5,4,3,2,1,0};
    s->sort(data,sizeof(data)/sizeof(int));
    s->print(data,sizeof(data)/sizeof(int));
    s->sort(data1, sizeof(data1)/sizeof(int));
    s->print(data1,sizeof(data1)/sizeof(int));
    s->sort(data2, sizeof(data2)/sizeof(int));
    s->print(data2,sizeof(data2)/sizeof(int));
}
int main(){
    std::cout << "test sort..." << std::endl;
    // 希尔排序
    ACISort<int, int>* s = new ACShellSort<int,int>();
    std::cout << "shellinsert short: " << std::endl;
    do_task(s);
    // 插入排序
    ACISort<int, int>* s1 = new ACInsertSort<int,int>();
    std::cout << "insert short: " << std::endl;
    do_task(s1);
    // 快速排序
    ACISort<int, int>* s2 = new ACQuickSort<int,int>();
    std::cout << "quick short: " << std::endl;
    do_task(s2);
    delete s;
    delete s1;
    delete s2;
    getchar();
    return 0;
}