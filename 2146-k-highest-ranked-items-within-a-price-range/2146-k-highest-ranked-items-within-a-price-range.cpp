
class Solution {
public:
	int dx[4] = { -1, +1, 0, 0};
	int dy[4] = {0, 0, +1, -1};
	int n, m;
	bool is_valid(int new_x, int new_y, vector<vector<int>>&dist, vector<vector<int>>&grid)
	{
		if (new_x < 0 || new_x >= n)
		{
			return false;
		}
		if (new_y < 0 || new_y >= m)
		{
			return false;
		}
		if (grid[new_x][new_y] == 0)
		{
			return false;
		}
		if (dist[new_x][new_y] != 0)
		{
			return false;//As this node/ block is already visited
		}
		return true;
	}
	vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k)
	{
		n = grid.size();
		m = grid[0].size();
		vector<vector<int>>probable_ans;//Storing all the possible Probable answer
		vector<vector<int>>dist(n, vector<int>(m, 0));//Storing the distance of each grid from start
		//No Need to take visited array as we can check if the cell is visited or not using
		int curr_x = start[0];
		int curr_y = start[1];
		queue<pair<int, int>>que;
		que.push({curr_x, curr_y});
		int distance = 0;
		dist[curr_x][curr_y] = 1;
		while (!que.empty())
		{
			int sz = que.size();
			while (sz--)
			{
				auto curr = que.front();
				que.pop();

				curr_x = curr.first;
				curr_y = curr.second;
				//if current cell lies in given pricing range push it into probable answer
				if (grid[curr_x][curr_y] != 0 and grid[curr_x][curr_y] >= pricing[0] and grid[curr_x][curr_y] <= pricing[1])
				{
					probable_ans.push_back({dist[curr_x][curr_y], grid[curr_x][curr_y], curr_x, curr_y});
				}
				//iterate over all the possible answers
				for (int i = 0; i < 4; i++)
				{
					int new_x = curr_x + dx[i];
					int new_y = curr_y + dy[i];
					if (is_valid(new_x, new_y, dist, grid))
					{
						dist[new_x][new_y] = dist[curr_x][curr_y] + 1;
						que.push({new_x, new_y});
					}
				}
			}
		}
		sort(probable_ans.begin(), probable_ans.end());//store k best answer in this, if there are less then K, then print only those
		vector<vector<int>>res;
		//cerr << probable_ans.size() << '\n';
		for (int i = 0; i < probable_ans.size(); i++)
		{
			if (i == k)
			{	// As best K Answers are stored, break
				break;
			}
			res.push_back({probable_ans[i][2], probable_ans[i][3]});
		}
		return res;

	}
};