#include?<iostream>
#include?<vector>
#include?<queue>

#define?endl?"\n"
#define?MAX?5000010
using?namespace?std;

int?N, L;
int?Arr[MAX];

void?Input()
{
	cin? >> N? >> L;
	for?(int?i? = 1;?i? <= N;?i++)?cin? >> Arr[i];
}

void?Solution()
{
	deque<pair<int, int>>?DQ;
	for?(int?i? = 1;?i? <= N;?i++)
	{
		if?(DQ.empty() == false)
		{
			if?(DQ.front().second? < i? - L? + 1)?DQ.pop_front();
		}
		while?(DQ.empty() == false? && DQ.back().first? > Arr[i])?DQ.pop_back();
		DQ.push_back(make_pair(Arr[i], i));
		cout? << DQ.front().first? << "?";
	}
	cout? << endl;
}

void?Solve()
{
	Input();
	Solution();
}

int?main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//????freopen("Input.txt",?"r",?stdin);
	Solve();

	return?0;
}


