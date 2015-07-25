class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> result;
		if (matrix.empty() || matrix[0].empty())
			return result;

		int maxRows = matrix.size() - 1;
		int maxCols = matrix[0].size() - 1;
		int startRow = 0;
		int startCol = 0;
		int row = 0;
		int col = 0;
		while (startRow <= maxRows && startCol <= maxCols)
		{
			//left -> right
			for (col = startCol; col <= maxCols && startRow <= maxRows; col++)
				result.push_back(matrix[startRow][col]);
			++startRow;

			//up -> down
			for (row = startRow; row <= maxRows && startCol <= maxCols; row++)
				result.push_back(matrix[row][maxCols]);
			--maxCols;

			//right -> left
			for (col = maxCols; col >= startCol && startRow <= maxRows; col--)
				result.push_back(matrix[maxRows][col]);
			--maxRows;

			//down -> up
			for (row = maxRows; row >= startRow && startCol <= maxCols; row--)
				result.push_back(matrix[row][startCol]);
			++startCol;
		}

		return result;
    }
};