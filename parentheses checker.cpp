
#include <iostream> 
using namespace std;
bool parentheses(string p);
const int maxsize=10;
template<class T>
class stack
{
	int topindex;
	T entry[maxsize];
	
	public:
	stack()
	{
	
	topindex = 0;
	
	}
	bool empty()
	{
	
	return (topindex==0);
	
	}
	bool push(T item)
	{
		if(topindex==maxsize)
		return 0;
		entry[topindex]=item;
		topindex++;
		return 1;
	}
	bool pop()
	 {
     	if(topindex==0)
		 return 0;
		topindex--;
		return 1;
	}
	bool top(T &item)
	{
		if(topindex==0)
		return 0;
		item=entry[topindex-1];
		return 1 ;
	}
} ;

int main() 
{ 
	string p ;
	cin>>p ;
	
  if (parentheses(p)) 
  cout << "=====>  valid"<<endl; 
  
  else 
  cout << "=====> Not valid"<<endl; 
}

bool parentheses(string p) 
{   
    stack<char> s; 
    char c; 
    for (int i = 0; i < p.length(); i++)  
    { 
        if ( p[i] == '['|| p[i] == '('|| p[i] == '{') 
		{ 
            s.push(p[i]); 
            continue; 
        } 
     if (s.empty()) return false; 
            
        switch (p[i]) 
		{ 
        case ')': s.top(c); s.pop();     
			if (c == '{' || c == '[') return false; break; 
		
		case ']': s.top(c); s.pop();
         	if (c == '(' || c == '{') return false; break;
        
		case '}': s.top(c); s.pop(); 
            if (c == '(' || c == '[')return false; break; 
        } 

    } 
return (s.empty()); 
} 