
vector<vector<int>> zeromat = {{0,0},{0,0}}; // zero matrix
vector<vector<int>> idenmat = {{1,0},{0,1}}; // identity matrix

vector<vector<int>> mul(vector<vector<int>> a , vector<vector<int>> b)
{
	// multiply 2 square matrices

	int n = a.size();
	vector<vector<int>> c(n , vector<int> (n , 0));
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < n ; j ++)
		{
			for(int k = 0 ; k < n ; k ++)
			{
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	return c;
}


vector<vector<int>> power(vector<vector<int>> x, int n) 
{
	// calculate matrix X^n
	
	if(n<0) return zeromat;
    vector<vector<int>>  pow = idenmat;
    
    while(n)
    {
        if (n & 1)
        {
            pow = mul(pow,x);
        }

        n = n >> 1;
        x = mul(x,x);
    }

    return pow;
}
