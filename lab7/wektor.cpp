#include "wektor.h"
#include "DBObject.h"
#include "towar.h"
using namespace std;

//helpers
    int nameComparator(const void * t1,const void * t2)
    {   
        
    DBObject * d1 = (DBObject *)(t1);
    DBObject * d2 = (DBObject *)(t2);
    
    const char * s1 = (const char *)(*d1);
    const char * s2 = (const char *)(*d2);
    
    if(strcmp(s1,s2)==0)return(0);   //if they are equal
    
        for(int i=0;s1[i]!=0;i++)
        {     
              if(s1[i] > s2[i])return(1);
              else if(s1[i] < s2[i])return(-2);
        }
    
    return (-2);  //hey if they are not equal and s1 not greater than s2 then s2 is greater
    }

int priceComparator(const void * t1,const void * t2)
    {   
        
    towar * o1 = (towar *)(t1);
    towar * o2 = (towar *)(t2);
    
    double d1 = (o1)->getPrice();
    double d2 = (o2)->getPrice();
    
    if(d1 == d2)return(0);   //if they are equal
    
    if( d1 > d2 ) return 1;
    
    return (-1); 
    }
