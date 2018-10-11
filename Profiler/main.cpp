//
//  main.cpp
//  Profiler
//
//  Created by Эльдар Дамиров on 11.10.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//

#include "profiler.h"


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
