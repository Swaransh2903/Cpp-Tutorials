// beginWord = "hit" endWord = "cog" wordList = [hot,dot,dog,lot,log,cog], We need to find the shortest transformation 
// sequence that'll convert beginWord to endWord. At a time we can only transform one character. Here for example
// the shortest transformation sequence would be : hit->hot->dot->dog->cog (i.e length = 5).Note: that whenever
// we are transforming , the transformed word should exist in the word list.

// Approach? : Now we know that whenever we are standing at a particular word , we can change any character to any 
// other character (from a to z) and possibly that word can exist in the word list and there can also be a possibility
// of occurence of multiple words in the word list by changing the same character into 2 different characters or by
// changing 2 different characters of the same word. So if we can traverse through each word character by character
// and apply (a to z) transformation on every character of it , we can get one particular sequence that can be a 
// probable answer and finally if we apply min(length) , we get the required ans

#include<stdio.h>
using namespace std;
int main()
{
    vector<string> wordList;
    string startWord,endWord;

    // we'll be taking a queue of pair, wherein the pair.first will contain the transformed word and pair.second
    // will contain the number of transformation steps in order to reach that word from source
    queue<pair<string,int>> q;
    q.push({startWord,1});

    // Why are we taking this set ? -> this set is acting like a visited array , so that if let's say by following
    // one set of transformation we reach a particular word and it is possible to reach that via another set of
    // transformation we don't consider it because it will be unnecessarily increase the iteration steps.Note : that
    // it will never be possible that we are reaching that word via a shorter length from any other path because
    // we are doing a level wise bfs traversal
    unordered_set<string> st(wordList.begin(),wordList.end());
    // this is like saying that since we visited the startWord we no more require it in the set.
    st.erase(startWord);
    while(!q.empty())
    {
        string currWord = q.front().first;
        int steps = q.front().second;
        q.pop();

        // if the word that's there in the queue currently is your required word, simply return it because since we
        // did level order traversal alongwith trying out all possibilities , we are rest assured that we obtained
        // this word by following the shortest transformation sequence.
        if(currWord == endWord)
            return steps;
        for(int i = 0;i < currWord.size();i++)
        {
            char currChar = currWord[i];
            for(char ch = 'a'; ch <= 'z';ch++)
            {
                currWord[i] = ch;
                // if it's there in the set , that means it's there in the wordList and this word has yet not been
                // considered so we can consider it as a possibility in forming the shortest sequence
                if(st.find(currWord) != st.end())
                {
                    st.erase(currWord);
                    q.push({currWord,steps+1});
                }
            }
            // after applying the transition on a character , it's very important to revert the changes , because
            // at a time we are only allowed to make changes - one char per word
            currWord[i] = currChar;
        }
    }
    // if the queue becomes empty, that means we tried out all possibility and were still not able to achieve the
    // endWord so we return 0

    // T.C - O(N*26*wordlength) - since all words will be of equal length, the outer loop iterates over the word length
    // whereas the inner loop iterates for each of the 26 characters ( so : 26*wordLength) and in the worst case we'll
    // be pushing all the words that exist in the wordList to form the shortest sequence so  (N*26*wordLength)
    return 0;
}