#include <bits/stdc++.h>
using namespace std;

// lower case english alphabet
class Trie {
public:
	Trie *next[26];
	bool isWord;
	
	Trie() {
		isWord=false;
		for (auto &i : next) i=NULL;
	}
	
	void insert(string word) {
		int l=word.length();
		Trie* trieI;
		for (int i=0; i<l; i++)
		{
			if(i==0)
			{
				trieI=this;
			}
			if (trieI->next[word[i]-'a']==NULL)
				trieI->next[word[i]-'a']=new Trie();
			trieI = trieI->next[word[i]-'a'];
		}
		trieI->isWord=true;
	}
	
	bool search(string word, bool isPrefix=false) {
		int l=word.length();
		Trie* trieI;
		for (int i=0; i<l; i++)
		{
			if(i==0)
			{
				trieI=this;
			}
			if(trieI->next[word[i]-'a']==NULL)
				return false;
			trieI = trieI->next[word[i]-'a'];
		}
		if(isPrefix)
			return true;
		return trieI->isWord;
	}
	
	bool startsWith(string prefix) {
		return search(prefix, true);
	}
};
