    #include<iostream>
    using namespace std;
    
    
    void readSparse(int m,int n)
    {
    	int i,j,count,A[10][10];
    	for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> A[i][j];
                if (A[i][j] == 0)
                    count++;
            }
        }
        if (count > ((m * n) / 2))
            cout << "The matrix is a sparse matrix.\n ";
    	else
            cout << "The given matrix is not a sparse matrix.\n ";
            for (i = 0; i < m; i++)
        {
            	for (j = 0; j < n; j++)	
                	cout << A[i][j] << " ";
            	cout << "\n ";
        }
        
    	
	}
    int main ()
    {
        int A[10][10], i, j, m, n, count = 0;
        cout << "Enter number of rows and columns : ";
        cin >> m >> n;
        cout << "Enter array elements : ";
        readSparse(m,n);
        
        return 0;
    }
