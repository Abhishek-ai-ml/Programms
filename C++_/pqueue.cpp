#include <iostream>
 
using namespace std;
#define MAX 5
 
//Declaration of priority queue
class PQueue
{
    private:
        int ele[MAX][MAX];
        int count;
 
    public:
        PQueue();
        void insertWithPriority(int priority, int item );
        int GetNext(int *item);
        int PeekAtNext(int *item);
         
};
 
//Initialize priority queue
PQueue:: PQueue()
{
    int i=0;
    count = 0;
      
    //All priority value set to -1
    for( i = 0; i < MAX ; i++ )
    {
        ele[i][1] = -1 ;    
    }
}
 
//Insert item with priority in queue
void PQueue:: insertWithPriority(int priority, int item )
{
    int i = 0;
    if( count == MAX )
    {
        cout<< "\nPriority Queue is overflow";
        return;
    }
 
    for ( i = 0; i < MAX; i++ )
    {
        if( ele[i][1] == -1)
            break;
    }
     
    ele[i][0] = item;
    ele[i][1] = priority;
 
    count++;
    cout<<"\nInserted item is : "<< item;
}
 
//Remove & get element with highest priority in queue
int PQueue:: GetNext(int *item)
{
    int i = 0,max,pos=0;
 
    if( count == 0 )
    {
        cout<<"\nPriority Queue is underflow";
        return -1;
    }
     
    max = ele[0][1];
    for ( i = 1; i < MAX; i++ )
    {
        if( max < ele[i][1] )
        {
            pos = i;
            max = ele[i][1];
        }
    }
     
    *item = ele[pos][0];    
    ele[pos][1] = -1;
 
    count--;
    return 0;   
}
 
//Get element with highest priority without removing it from queue
int PQueue:: PeekAtNext(int *item)
{
    int i = 0,max,pos=0;
 
    if( count == 0 )
    {
        cout<<"\nPriority Queue is underflow";
        return -1;
    }
     
    max = ele[0][1];
    for ( i = 1; i < MAX; i++ )
    {
        if( max < ele[i][1] )
        {
            pos = i;
            max = ele[i][1];
        }
    }
     
    *item = ele[pos][0];    
 
    return 0;   
}
 
 
int main()
{
    int item;
    PQueue q = PQueue();
     
     
 
    q.insertWithPriority( 1, 10 );
    q.insertWithPriority( 2, 20 );
    q.insertWithPriority( 3, 30 );
    q.insertWithPriority( 4, 40 );
    q.insertWithPriority( 5, 50 );
    q.insertWithPriority( 6, 60 );
 
    if( q.PeekAtNext( &item) == 0 )
        cout<<"\nPeek Item : "<< item;
 
 
    if( q.GetNext( &item) == 0 )
        cout<<"\nItem : "<< item;
     
    if( q.PeekAtNext( &item) == 0 )
        cout<<"\nPeek Item : "<< item;
 
    if( q.GetNext( &item) == 0 )
        cout<<"\nItem : "<< item;
    if( q.GetNext( &item) == 0 )
        cout<<"\nItem : "<< item;
 
     
    if( q.PeekAtNext( &item) == 0 )
        cout<<"\nPeek Item : "<< item;
 
    if( q.GetNext( &item) == 0 )
        cout<<"\nItem : "<< item;
    if( q.GetNext( &item) == 0 )
        cout<<"\nItem : "<< item;
    if( q.GetNext( &item) == 0 )
        cout<<"\nItem : "<< item;
 
    cout<< endl;
     
    return 0;
}