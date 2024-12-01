#include <iostream>
#include <vector>
#include <algorithm> // for min_element
using namespace std;
long long long_solution(int n, vector<long long> a, vector<long long> b) {
    long long mod = 1e9 + 7;
    // Handle the case where n is 0
    if (n == 0) {
        return 0;
    }
    // Find the indices of the minimum elements in arrays a and b
    int ind1 = min_element(a.begin(), a.end()) - a.begin();
    int ind2 = min_element(b.begin(), b.end()) - b.begin();
    long long sum = 0;
    // Calculate the sum based on the minimum elements
    for (int i = 0; i < n; i++) {
        // Skip indices of the minimum elements
        if (i != ind1 && i != ind2) {
            sum = (sum + min(a[ind1] * b[i], b[ind2] * a[i])) % mod;
        }
    }
    // Add the product of the two minimum elements if they are different
    if (ind1 != ind2) {
        sum = (sum + a[ind1] * b[ind2]) % mod;
    }
    return sum; // Return the calculated sum
}
int main() {
    // Example usage
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    long long result = long_solution(n, a, b);
    cout<< result << endl;  
}