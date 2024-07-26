#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int row,colm;
    char ch;
    cin>>row>>colm>>ch;
    vector<string>vec(row);
    vector<char>deputy;

    for(size_t i=0;i<row;i++)
    {
        string star;
        cin>>star;
        vec[i]=star;
    }
    vector<vector<char>> TheMatrix;
    for (int i = 0; i < vec.size(); ++i)
    {
        vector<char> split;
        for (int j = 0; j < vec[i].size(); ++j)
        {
            split.push_back(vec[i][j]);
        }
        TheMatrix.push_back(split);
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0; j<colm;j++)
        {
            char above='.';
            char below='.';
            char left='.';
            char right='.';
            char look = TheMatrix[i][j];
            if(look == ch)
            {
                if(i>0)
                    above = TheMatrix[i-1][j];
                if(i<row-1)
                    below = TheMatrix[i+1][j];
                if(j>0)
                    left = TheMatrix[i][j-1];
                if(j<colm-1)
                    right = TheMatrix[i][j+1];
                if (above!='.' && above!=ch)
                {
                     deputy.push_back(above);
                }
                if (below!='.'&& below!=ch && below!=above)
                {
                    deputy.push_back(below);
                }
                if (left!='.'&& left!=ch && left!=above && left!=below)
                {
                    deputy.push_back(left);
                }
                if (right!='.'&& right!=ch && right!=above && right!=below && right!=left)
                {
                    deputy.push_back(right);
                }
            }
        }
    }
    sort(deputy.begin(), deputy.end());
    auto last = unique(deputy.begin(), deputy.end());
    deputy.erase(last, deputy.end());
    cout <<deputy.size()<<endl;
    return 0;
}
