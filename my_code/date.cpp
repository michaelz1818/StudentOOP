//
//  date.cpp
//  OOPSu19
//
//  Created by Michael Zhao on 6/7/19.
//  Copyright © 2019 Michael Zhao. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "date.h"

using namespace std;

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

ostream& operator<<(ostream& os, const Date& date){
    os << date.month << "." << date.day << "." << date.year;
    return os;
}
