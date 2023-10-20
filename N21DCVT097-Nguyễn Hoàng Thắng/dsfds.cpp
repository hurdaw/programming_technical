#include <bits/stdc++.h>
using namespace std;

void timtongmax(int n, int *a) {
	int best = INT_MIN, sum = 0;
	for (int i = 0; i <= n; i++) {
		sum = max(a[i], sum + a[i]);
		best = max(best, sum);
	}
	
	cout << best << "\n";
}

void timvitrimax(int n, int *a) {
	int best = INT_MIN, sum = 0;
	int best_start = 0, best_end = 0, current_start = 0;
	for (int i = 0; i < n; i++) {
		if (sum + a[i] < a[i]) {
			current_start = i;
			sum = a[i];
		} else {
			sum += a[i];
		}
		
		if (best < sum) {
			best = sum;
			best_start = current_start;
			best_end = i;
		}
	}
	cout << best << "\n";
	cout << "vi tri bat dau tu " << best_start << " toi " << best_end << endl;
}

int main() {
	int n;
	int a[1000];
	
	cout << "nhap n: ";
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		cout << "nhap phan tu thu " << i << ": ";
		cin >> a[i];
	}
	
	timtongmax(n, a);
	timvitrimax(n, a);
}