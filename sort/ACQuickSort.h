/*
            This file is part of: 
               algorithm_cpp
            https://github.com/yangcancai/algorithm_cpp
   Copyright (c) 2020 algorithm_cpp. All rights reserved.
   Created by yangcancai  on 2020/7/14.
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
#ifndef ALGORITHM_CPP_ACQUICKSORT_H
#define ALGORITHM_CPP_ACQUICKSORT_H
#include "ACISort.h"
// 快速排序
template<typename T, typename N>
class ACQuickSort : public ACISort<T,N> {
public:
    void sort(T* data, const N &n) override {
        if (n == 0 || n == 1) return;
        N i = 0;
        N j = n - 1;
        N t = i;
        bool is_right = true;
        while(i <= j){
            if (is_right) {
                if (data[j] < data[t]) {
                    this->swap(data[j], data[t]);
                    is_right = false;
                    t = j;
                }
                j--;
            }else{
                if (data[i] > data[t]) {
                    this->swap(data[t], data[i]);
                    is_right = true;
                    t = i;
                }
                i++;
            }
        }
        sort(data, t);
        sort(data + t+1, n - t-1);
    }
};


#endif //ALGORITHM_CPP_ACQUICKSORT_H
