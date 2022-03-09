#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

vi memo3;
vi memo4;

int pow(int n) {
	if (memo3[n] < 0) {
		memo3[n] = (1 << n) - 1;
	}

	return memo3[n];
}

int solve(int n) {
	if (memo4[n] < 0) {
		auto mn = int{ 987654321 };
		for (int k = 1; k < n; ++k) {
			const auto& ans = solve(n - k) + pow(k) + solve(n - k);

			if (ans < mn) {
				mn = ans;
			}
		}

		memo4[n] = mn;
	}

	return memo4[n];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	memo3 = vi(13, -1);
	memo3[1] = 1;

	memo4 = vi(13, -1);
	memo4[1] = 1;

	for (int n = 1; n <= 12; ++n) {
		cout << solve(n) << '\n';
	}

	return 0;
}