
string decodeString(string s) 
{
	stack<int> intStack;
	stack<char> charStack;
	string result = "";
	
	string curr = "";
	
	for(int i = 0; i < s.length(); i++)
	{
		int counter = 0;
		
		if(s[i] >= '0' && s[i] <= '9')
		{
			while(s[i] >= '0' && s[i] <= '9')
			{
				counter = counter * 10 + (s[i] - '0');
				i++;
			}
			i--;
			intStack.push(counter);
		}
		else if(s[i] == ']')
		{
			curr = "";
			counter = 0;
			if(!intStack.empty())
			{
				counter = intStack.top();
				intStack.pop();
			}
			
			while(!charStack.empty() && charStack.top()!='[')
			{
				curr = charStack.top() + curr;
				charStack.pop();
			}
			if(!charStack.empty() && charStack.top() == '[')
			{
				charStack.pop();
			}
			for(int j = 0; j < counter; j++)
			{
				result = result + curr;
			}
			for(int j = 0; j < result.length(); j++)
			{
				charStack.push(result[j]);
			}
			
			result = "";                
			
		}
		else if (s[i] == '[')
		{
			if(s[i-1] >= '0' && s[i-1] <= '9')
			{
				charStack.push(s[i]);
			}
			else
			{
				charStack.push(s[i]);
				intStack.push(1);
			}
		}
		else
		{
			charStack.push(s[i]);
		}
	}
	while(!charStack.empty())
	{
		result = charStack.top() + result;
		charStack.pop();
	}
	return result;
	
	
}
