#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include <stack>

#include "WordLadder.h"

using namespace std;

WordLadder :: WordLadder(const string & filename)
{
    ifstream inFS;
    string word;
    
    inFS.open(filename.c_str());
    if(!inFS.is_open())
    {
        cout << endl;
        cout << "Error opening " << filename << endl;
        return;
    }   
    while(!inFS.eof())
    {
        inFS >> word;
        if(word.size() != 5)
        {
            cout << "Error word is not 5 letters long" << endl;
            return;
        }
        else
        {
            dict.push_back(word);
        }
    }
    inFS.close();
}


void WordLadder :: outputLadder(const string &start, const string &end, const string &outputFile)
{
    ofstream outFS;
    outFS.open(outputFile.c_str());
    if(!outFS.is_open())
    {
        cout << endl;
        cout << "Error opening output file" << endl;
        return;
    }
    if(!inDict(start))
    {
        cout << "Error: word does not exist in the dictionary" << endl;
        return;
    }
    if(!inDict(end))
    {
        cout << "Error: word does not exist in the dictionary" << endl;
        return;
    }
    

        if (start == end) {
        cout << start << endl;
        outFS << start << endl;
        return; 
    }
    
    stack<string> words;
    words.push( start );
    
    queue< stack<string> > ladders;
    ladders.push( words );
    
    while (!ladders.empty()) 
    {  
        for(list<string>::iterator i=dict.begin(); i != dict.end();i++ ) 
        { 
            
            
            if ( matchCheck(ladders.front().top(), *i) ) 
            { 
                if (*i == end) 
                {    
                    
                    stack<string> outputStack;  
                                                
                    while ( !ladders.front().empty() ) 
                    {
                        outputStack.push( ladders.front().top() );
                        ladders.front().pop();  
                    }                           
                    
                    while ( !outputStack.empty() ) 
                    {
                        
                        cout << outputStack.top() << ' ';
                        outFS << outputStack.top() << ' ';
                        outputStack.pop(); 
                    }
                    
                    cout << *i << endl; 
                    outFS << *i << endl;
                    
                    return;
                    
                }
                
                stack<string> temp = ladders.front();
                temp.push( *i );
                ladders.push(temp);
                
                dict.erase(i);    
                i--;                    
            }
        }
                
        ladders.pop();
    }
    if(ladders.empty())
    {
        cout << "No Word Ladder Found!!" << endl;
        outFS <<"No Word Ladder Found!!" << endl;
    }
    // else
    // {   
    //     //out ladder part
    //     while(!ladders.empty())
    //     {
    //         string wow;
    //         for(int i = 0; i < 5; ++i)
    //         {
    //             wow += ladders.front().top();
    //             ladders.front().pop();
    //         }
    //         // cout << wow << " ";
    //         outFS << wow;
    //         ladders.pop();
    //     }
    // }
    outFS.close();
}
bool WordLadder :: inDict(const string& s)
{
    for( list<string>::iterator i = dict.begin(); i != dict.end();i++ ) 
    {
        if (s == *i) 
        {
            return true;
        }
    }
    
    return false;
}

bool WordLadder:: matchCheck( const string& word, const string& compare ) 
{
    
    int counter = 0;
    
    for (unsigned i = 0; i < word.size(); i++) 
    {
        if (compare.at(i) != word.at(i)) 
        {
            counter++;  
        }
    }
    
    if (counter > 1) 
    {  
        return false;
    }
    
    return true;        
}
