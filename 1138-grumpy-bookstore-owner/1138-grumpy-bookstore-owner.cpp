#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int baseSatisfaction = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                baseSatisfaction += customers[i];
            }
        }
        
        int additionalSatisfaction = 0;
        int currentAdditional = 0;
        
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                currentAdditional += customers[i];
            }
        }
        
        additionalSatisfaction = currentAdditional;
        
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i] == 1) {
                currentAdditional += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                currentAdditional -= customers[i - minutes];
            }
            additionalSatisfaction = max(additionalSatisfaction, currentAdditional);
        }
        
        return baseSatisfaction + additionalSatisfaction;
    }
};
