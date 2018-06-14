int changePossibilities(int amount, vector<int>& coins) {
	int result = 0;
	helper(amount, coins, 0, 0, result);
	
	return result;
	
}

void helper(int amount, vector<int>& coins, int idx_coin, int current_sum, int & numOfWays)
{
	if (amount == current_sum)
	{
		numOfWays++;
		return;
	}
	
	if(amount < current_sum)
	{
		return;
	}
	
	for(int i = idx_coin; i < coins.size(); i++)
	{
		helper(amount, coins, i, current_sum + coins[i], numOfWays);
	}
	
	return;
}