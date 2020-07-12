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
#include "sort/ACInsertSort.h"
int main(){
    int data[] = {1000,-1,1,102,1,-1};
    int n = sizeof(data)/ sizeof(int);
    // 希尔排序
    ACInsertSort<int, int>* s = new ACShellSort<int,int>();
    s->sort(data,n);
    s->print(data, n);
    // 插入排序
    ACInsertSort<int, int>* s1 = new ACInsertSort<int,int>();
    s1->sort(data,n);
    s1->print(data, n);
    delete s;
    getchar();
    return 0;
}