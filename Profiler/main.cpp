//
//  main.cpp
//  Profiler
//
//  Created by Эльдар Дамиров on 11.10.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//

#include <iostream>
#include <chrono>

class LogDuration;

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
    LogDuration UNIQ_ID ( __LINE__ ) { message };    // defines unique identifier in term of single .cpp file;

typedef std::chrono::steady_clock::time_point timePoint;

class LogDuration
    {
    /*
    wrap code block in {} to measure its work time, e.g:
    {
    LogDuration thisBlockDuration;
    ...
    }
    */
    
    public:
        explicit LogDuration ( const std::string& messageTemp = "" ) : // explicit as no any other object should be converted into LogDuration;
            start ( std::chrono::steady_clock::now() ), 
            message ( messageTemp + ": " )
            {
            
            }
            
        ~LogDuration()
            {
            finish = std::chrono::steady_clock::now();
            
            auto duration = ( finish - start );
            
            std::cerr << message << std::chrono::duration_cast <std::chrono::milliseconds> ( duration ).count() << "ms" << "\n";
            }
        
    private:
        timePoint start;
        timePoint finish;
        std::string message; // message provided in console log;

    };


int main() 
    {
    
    {
    LOG_DURATION ( "Test" );
    
    for ( auto i = 0; i < INT_MAX; i++ )
        {
        LOG_DURATION ( std::to_string ( i ) );
        
        }
    }
    
    return 0;
    }
