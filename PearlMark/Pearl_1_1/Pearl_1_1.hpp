//
//  Pearl_1_1.hpp
//  PearlMark
//
//  Created by Amn Ice on 2020/5/21.
//

#ifndef Pearl_1_1_hpp
#define Pearl_1_1_hpp

#include <stdio.h>
#include <string>
void Pearl_1_1();

class DecadTree
{
public:
    static const int        cMaxDigitIndex = 10;
    static const int        cMaxLayer = 7;
    
    void                    SetLayer(int inLayer)   { mLayer = inLayer; }
    int                     GetLayer()              { return mLayer; }
    DecadTree*              AddChild(int inIndex);
    void                    Print();
    
private:
    static std::string      sPrefixBuffer;
    static bool             sIsNeedPrefix;
    
    DecadTree*              mChild[cMaxDigitIndex] = { nullptr };
    int                     mLayer = -1; //  root node use -1 as laye
    
    
    ~DecadTree();
};
#endif /* Pearl_1_1_hpp */
