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
#ifndef ALGORITHM_CPP_ACISORT_H
#define ALGORITHM_CPP_ACISORT_H

template<typename T, typename N>
class ACISort {
public:
    virtual void sort(T* data, const N &n) = 0 ;
    virtual void print(T* data, const N &n) {
        for (N i = 0; i < n; ++i) {
            std::cout << data[i] << ",";
        }
        std::cout << std::endl;
    };
};


#endif //ALGORITHM_CPP_ACISORT_H
