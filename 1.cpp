/*
Assumption:
	1: t will contain all the unique characters in s
	2: characters in both strings will only be lower case letters from 'a' to 'z'

*/


string sortByStrings(string s, string t)
{
	vector<int> counter(26, 0);
	//Store the counter for each letter in string S
	for(int i = 0; i < s.length(); i++)
	{
		counter[s[i] - 'a']++;
	}
	
	string result = "";
	//Print out in the order of T each letter in S
	for(int j = 0; j < t.length(); j++)
	{
		int count = counter[t[j] - 'a'];
		for(int z = 0; z < count; z++)
		{
			result = result + t[j];
		}
		
	}

	return result;
		
}