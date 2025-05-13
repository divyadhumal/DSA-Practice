class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

    // Count frequency of each task
    for (char task : tasks)
        freq[task - 'A']++;

    sort(freq.begin(), freq.end());

    int maxFreq = freq[25] - 1; // -1 because the last one doesn't need a gap after it
    int idleSlots = maxFreq * n;

    // Fill idle slots with remaining task frequencies
    for (int i = 24; i >= 0 && idleSlots > 0; i--) {
        idleSlots -= min(freq[i], maxFreq);
    }

    idleSlots = max(0, idleSlots); // If negative, we don't need extra idle time

    return tasks.size() + idleSlots;

    }
};
//TC- O(N + 26 log 26) → N = number of tasks, 26 = number of uppercase letters

//SC- O(1) - since the size of freq is fixed at 2