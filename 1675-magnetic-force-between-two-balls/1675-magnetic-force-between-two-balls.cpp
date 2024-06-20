#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position.back() - position[0];
        int best_force = 0;

        auto canPlaceBalls = [&](int min_force) {
            int count = 1;
            int last_position = position[0];

            for (int i = 1; i < position.size(); ++i) {
                if (position[i] - last_position >= min_force) {
                    ++count;
                    last_position = position[i];
                    if (count == m) {
                        return true;
                    }
                }
            }
            return false;
        };

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlaceBalls(mid)) {
                best_force = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return best_force;
    }
};
