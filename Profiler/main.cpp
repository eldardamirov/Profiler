//
//  main.cpp
//  Profiler
//
//  Created by Эльдар Дамиров on 11.10.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//

#include <iostream>
#include <chrono>

typedef std::chrono::steady_clock::time_point timePoint;


int main() 
    {
    
    return 0;
    }


class LogDuration
    {
    public:
        LogDuration() : start ( std::chrono::steady_clock::now() )
            {
            
            }
            
        ~LogDuration()
            {
            finish = std::chrono::steady_clock::now();
            
            auto duration = ( finish - start );
            
            std::cerr << std::chrono::duration_cast <std::chrono::milliseconds> ( duration ).count() << "ms" << "\n";
            }
        
    private:
        timePoint start;
        timePoint finish;
    
    
    
    
    };
