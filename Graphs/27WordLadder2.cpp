// This question is an extension of the previous question but herein we need to find all the possible combinations
// of shortest transformation sequence

#include<stdio.h> 
using namespace std;
int main()
{
    vector<string> wordList;
    string beginWord,endWord;
    
    // take a set containing all the words of the word list as we did before.
    unordered_set<string> st(wordList.begin(),wordList.end());

    // Now since we are trying to solve this problem via bfs and since this time we don't require the length but the
    // sequence itself, instead of taking a queue of integers(that stored length at each level), we are taking a
    // queue of vector of strings(that will be storing all the possible combinations of sequences at a particular
    // level that can be a possible candidate for the resultant sequence.)
    queue<vector<string>> q;

    q.push({beginWord});

    // this vector of strings will actually contain all the strings that were pushed inside our queue's vector,while
    // traversing for a particular level.Assume that we are traversing through a particular level and we get a word
    // that's there in the wordList, we push it in the queue's vector considering that it might be a part of the final
    // sequence, however in contrary to the previous approach we'll not erase this string from the set(in other words
    // mark it as visited) because there can be a possibility that we reach this string via some other sequence of
    // strings too(since we need to get all possible combinations of shortest sequence and since we are traversing
    // level wise both will account to the final ans if we get the endWord via following these sequences). So basically,
    // we are storing all the strings used in a particular level in a vector , so that once the iteration for that
    // particular level is over, we can get all of them erased.
    vector<string> usedOnLvl;
    usedOnLvl.push_back(beginWord);

    int level = 0;
    // this will be used to store our final answer.
    vector<vector<string>> ans;

    while(!q.empty())
    {
        // this time the value in the queue is the sequence we have formulated by traversing till the previous lvl
        vector<string> currSequence = q.front();
        q.pop();

        // Now when we would've completed all the iterations for a particular level , we would've stored all the words
        // used to form the transitions in the usedOnLvl vector and the currSequence size would've increased by 1 compared
        // to the level we are on(because we initialized level with 0) and so remove all the words that were used in the
        // previous level(so that they aren't considered again after a level has completed)
        if(currSequence.size() > level)
        {
            level++;
            for(auto it:usedOnLvl)
                st.erase(it);
        }

        // the word from which we have to look for future transformations will always be the last word that was
        // added to the vector 
        string currWord = currSequence.back();

        // let's say we find the endWord:
        if(currWord == endWord)
        {
            // this indicates that we are forming the first sequence
            if(ans.size() == 0)
                ans.push_back(currSequence);
            // if it's not the first sequence , we first check whether it's length is equivalent to the shortest 
            // length sequence that's already there in the ans vector:
            else if(ans[0].size() == currSequence.size())
                ans.push_back(currSequence);
        }
        
        // standard stuff that we did in word Ladder to obtain all possible transformations from a particular word
        for(int i = 0;i < currWord.size();i++)
        {
            char currChar = word[i];
            for(char ch = 'a';ch <= 'z';ch++)
            {
                currWord[i] = ch;
                // if that word is a part of the wordList
                if(st.find(currWord) != st.end())
                { 
                    currSequence.push_back(currWord);
                    q.push_back(currSequence);
                    // mark as visited on the level
                    usedOnLvl.push_back(currWord);
                    // now since inside this loop we are considering the different valid transitions by transforming
                    // the characters of a given word, after we've pushed the sequence in the queue we need to get that
                    // word out of the currSequence so that we can make way for any other word formed by transition of any
                    // character on the same level.
                    currSequence.pop_back();
                }
            }
            // restore the original word after you've checked for a single character transition because accn to the
            // quesn we are only allowed one character transition per word
            word[i] = currChar;
        }
    }
}