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
#ifndef ALGORITHM_CPP_ACINSERTSORT_H
#define ALGORITHM_CPP_ACINSERTSORT_H
#include "ACISort.h"

template<typename T, typename N>
class ACInsertSort : public ACISort<T,N>{
public:
    virtual void sort(T* data, const N &n) override {
        // 步长是1的插入排序
        sort(data, n, 1);
    }
    virtual void sort(T* data, const N &n, const N &inc){
        T temp;
        for (N i = 0; i < inc; i++){
            sort(data, n, inc, i);
        }
    }
    virtual void sort(T* data, const N &n, const N &inc, const N &s){
        T temp;
        N i,j;
        for (i = s; i < n; i += inc){
              temp = data[i];
              // 把比temp小的元素往后移
             for (j = i; j > s; j -= inc) {
                 if (data[j-inc] > temp){
                     data[j] = data[j-inc];
             // 找到了合适位置跳出循环
                 } else{
                     break;
                 }
             }
             // 把temp插入合适位置
             data[j] = temp;
        }
    }
};
#endif //ALGORITHM_CPP_ACINSERTSORT_H
