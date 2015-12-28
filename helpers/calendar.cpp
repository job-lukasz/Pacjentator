#include "calendar.h"

Calendar::Calendar(){
}

int Calendar::getMounthLength(int mounth,int year){
    int mounthLength;
    if((mounth<7&&mounth%2==0)||(mounth>8&&mounth%2==1)){
        mounthLength=30;
        if(mounth==2){
            mounthLength=QDate::isLeapYear(year)?29:28;
        }
    }
    else{
        mounthLength=31;
    }
    return mounthLength;
}

