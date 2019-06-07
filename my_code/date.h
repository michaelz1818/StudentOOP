//
//  date.hpp
//  OOPSu19
//
//  Created by Michael Zhao on 6/7/19.
//  Copyright © 2019 Michael Zhao. All rights reserved.
//

#ifndef date_hpp
#define date_hpp

#include <string>
#include <vector>

class Date {
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
public:
    Date(int d, int m, int y);
private:
    int day;
    int month;
    int year;
};



#endif /* date_hpp */
