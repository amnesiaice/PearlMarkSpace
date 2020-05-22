//
//  Pearl_1_1.cpp
//  PearlMark
//
//  Created by Amn Ice on 2020/5/21.
//

#include "Pearl_1_1.hpp"
#include <fstream>
#include <iostream>

std::string DecadTree::sPrefixBuffer = "";
bool        DecadTree::sIsNeedPrefix = false;

void Pearl_1_1()
{
    std::cout<<"Pearl_1_1"<<std::endl;
    std::cout<<"TODO: generate 10000000 record then profile the running time."<<std::endl;
    
    std::fstream input_file;
    input_file.open("Input.txt");
    //read
    
    DecadTree* root = new DecadTree;
    while(input_file.peek()!=EOF)
    {
        DecadTree* current_node = root;
        std::string line;
        getline(input_file, line);
        
        for(int i = 0; i < line.length(); i++)
        {
            int digit = line[i] - '0';
            current_node = current_node->AddChild(digit);
        }
    }
    
    root->Print();

}


DecadTree::~DecadTree() { 
    for(int i = 0; i < cMaxDigitIndex; i++)
    {
        if(mChild[i] != nullptr)
            delete mChild[i];
    }
}


DecadTree* DecadTree::AddChild(int inIndex)
{
    if(mChild[inIndex] == nullptr)
    {
        DecadTree* node = new DecadTree;
//        node->SetDigit(inDigit);
        node->SetLayer(mLayer+1);
        mChild[inIndex] = node;
        return node;
    }
    
    return mChild[inIndex];
}

void DecadTree::Print()
{
    if(mLayer>=cMaxLayer-1)
    {
        sIsNeedPrefix = true;
        sPrefixBuffer.pop_back();
        std::cout<<std::endl;
        return;
    }
    
    for(int i = 0; i < cMaxDigitIndex; i++)
    {
        if(mChild[i] == nullptr)
            continue;
        
        if(sIsNeedPrefix)
        {
            sIsNeedPrefix = false;
            std::cout<<sPrefixBuffer;
        }
        std::cout<<i;
        sPrefixBuffer+=std::to_string(i);
        mChild[i]->Print();
        
    }
    sPrefixBuffer.pop_back();
}

