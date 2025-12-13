/*
================================================================================
                            RATE LIMITER - CLOUDFLARE STYLE
================================================================================

PROBLEM STATEMENT:
------------------
Design a Rate Limiter class that controls how many requests a user can make
within a sliding time window.

Implement the RateLimiter class:
- RateLimiter(int maxRequests, int windowSizeInSeconds)
    Initializes the rate limiter with:
    - maxRequests: maximum number of requests allowed per window
    - windowSizeInSeconds: the size of the sliding window in seconds

- bool shouldAllow(int userId, int timestampInSeconds)
    Returns true if the request should be allowed, false if it should be 
    rate-limited. If allowed, the request is recorded.

The rate limiter uses a SLIDING WINDOW approach:
- At any given timestamp T, only requests in the range [T - windowSize + 1, T]
  are considered.
- Old requests outside this window should be discarded.

CONSTRAINTS:
- 1 <= maxRequests <= 1000
- 1 <= windowSizeInSeconds <= 3600
- 1 <= userId <= 10^6
- 0 <= timestampInSeconds <= 10^9
- Timestamps are given in non-decreasing order for each userId
- At most 10^5 calls to shouldAllow

================================================================================
EXAMPLE 1:
----------
Input:
    RateLimiter limiter(3, 5);  // 3 requests per 5 seconds
    limiter.shouldAllow(1, 1);  // User 1 at t=1
    limiter.shouldAllow(1, 2);  // User 1 at t=2
    limiter.shouldAllow(1, 3);  // User 1 at t=3
    limiter.shouldAllow(1, 4);  // User 1 at t=4 (4th request in window [0,4])
    limiter.shouldAllow(1, 6);  // User 1 at t=6 (window is now [2,6])

Output: [true, true, true, false, true]

Explanation:
    t=1: First request for user 1. Count=1. ALLOWED.
    t=2: Second request. Count=2. ALLOWED.
    t=3: Third request. Count=3. ALLOWED.
    t=4: Fourth request. Window [0,4] has 3 requests already. DENIED.
    t=6: Window slides to [2,6]. Request at t=1 expires. Count=2. ALLOWED.

================================================================================
EXAMPLE 2:
----------
Input:
    RateLimiter limiter(2, 3);  // 2 requests per 3 seconds
    limiter.shouldAllow(1, 1);  // User 1
    limiter.shouldAllow(2, 1);  // User 2 (different user!)
    limiter.shouldAllow(1, 2);  // User 1
    limiter.shouldAllow(2, 2);  // User 2
    limiter.shouldAllow(1, 3);  // User 1 (3rd in window [1,3])
    limiter.shouldAllow(2, 3);  // User 2 (3rd in window [1,3])

Output: [true, true, true, true, false, false]

Explanation:
    Each user has their own independent rate limit.
    User 1: t=1 (count=1), t=2 (count=2), t=3 (count=2, DENIED)
    User 2: t=1 (count=1), t=2 (count=2), t=3 (count=2, DENIED)

================================================================================
EXAMPLE 3:
----------
Input:
    RateLimiter limiter(1, 1);  // 1 request per 1 second (strict)
    limiter.shouldAllow(1, 0);
    limiter.shouldAllow(1, 0);  // Same timestamp!
    limiter.shouldAllow(1, 1);  // New window
    limiter.shouldAllow(1, 1);  // Same timestamp again

Output: [true, false, true, false]

Explanation:
    t=0: First request. ALLOWED.
    t=0: Same second, already at limit. DENIED.
    t=1: Window [1,1], old request expired. ALLOWED.
    t=1: Same second, at limit. DENIED.

================================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

// ============================================================================
// YOUR SOLUTION HERE - IMPLEMENT THE RateLimiter CLASS
// ============================================================================

class RateLimiter {
private:
    // TODO: Add your data members here
    unordered_map<int, deque<int>> freq;
    int max_requests;
    int window_size;

public:
    RateLimiter(int maxRequests, int windowSizeInSeconds) {
        max_requests = maxRequests;
        window_size = windowSizeInSeconds;
    }
    
    bool shouldAllow(int userId, int timestampInSeconds) {
        
        auto& p = freq[userId];

        int start_window = timestampInSeconds - window_size + 1;
        while(!p.empty() && p.front() < start_window){
            p.pop_front();
        }

        if(p.size() < max_requests){
            p.push_back(timestampInSeconds);
            return true;
        }

        
        // Return true if request is allowed, false otherwise
        // If allowed, record the request
        return false;
    }
};

// ============================================================================
// TEST CASES - DO NOT MODIFY
// ============================================================================

void runTest(int testNum, vector<bool>& results, vector<bool>& expected) {
    cout << "Test " << testNum << ": ";
    bool passed = true;
    for (size_t i = 0; i < results.size(); i++) {
        if (results[i] != expected[i]) {
            passed = false;
            cout << "FAILED at index " << i << " (expected " 
                 << (expected[i] ? "true" : "false") 
                 << ", got " << (results[i] ? "true" : "false") << ")" << endl;
            break;
        }
    }
    if (passed) {
        cout << "PASSED" << endl;
    }
}

void testCase1() {
    // Basic sliding window test
    RateLimiter limiter(3, 5);  // 3 requests per 5 seconds
    
    vector<bool> results;
    results.push_back(limiter.shouldAllow(1, 1));  // true
    results.push_back(limiter.shouldAllow(1, 2));  // true
    results.push_back(limiter.shouldAllow(1, 3));  // true
    results.push_back(limiter.shouldAllow(1, 4));  // false (4th in window)
    results.push_back(limiter.shouldAllow(1, 6));  // true (t=1 expired)
    
    vector<bool> expected = {true, true, true, false, true};
    runTest(1, results, expected);
}

void testCase2() {
    // Multiple users - independent limits
    RateLimiter limiter(2, 3);  // 2 requests per 3 seconds
    
    vector<bool> results;
    results.push_back(limiter.shouldAllow(1, 1));  // true (user 1)
    results.push_back(limiter.shouldAllow(2, 1));  // true (user 2)
    results.push_back(limiter.shouldAllow(1, 2));  // true (user 1)
    results.push_back(limiter.shouldAllow(2, 2));  // true (user 2)
    results.push_back(limiter.shouldAllow(1, 3));  // false (user 1 at limit)
    results.push_back(limiter.shouldAllow(2, 3));  // false (user 2 at limit)
    
    vector<bool> expected = {true, true, true, true, false, false};
    runTest(2, results, expected);
}

void testCase3() {
    // Strict limit - same timestamp edge case
    RateLimiter limiter(1, 1);  // 1 request per 1 second
    
    vector<bool> results;
    results.push_back(limiter.shouldAllow(1, 0));  // true
    results.push_back(limiter.shouldAllow(1, 0));  // false (same ts)
    results.push_back(limiter.shouldAllow(1, 1));  // true (new window)
    results.push_back(limiter.shouldAllow(1, 1));  // false (same ts)
    
    vector<bool> expected = {true, false, true, false};
    runTest(3, results, expected);
}

// ============================================================================
// EDGE CASE TESTS - UNCOMMENT WHEN READY TO SUBMIT
// ============================================================================


void testCase4_LargeWindowJump() {
    // Large time jump - all requests expire
    RateLimiter limiter(2, 5);
    
    vector<bool> results;
    results.push_back(limiter.shouldAllow(1, 1));   // true
    results.push_back(limiter.shouldAllow(1, 2));   // true
    results.push_back(limiter.shouldAllow(1, 3));   // false
    results.push_back(limiter.shouldAllow(1, 100)); // true (huge jump, all expired)
    results.push_back(limiter.shouldAllow(1, 101)); // true
    results.push_back(limiter.shouldAllow(1, 102)); // false
    
    vector<bool> expected = {true, true, false, true, true, false};
    runTest(4, results, expected);
}

void testCase5_BoundaryCondition() {
    // Exact boundary - request expires exactly at window edge
    RateLimiter limiter(2, 3);  // window size 3
    
    vector<bool> results;
    results.push_back(limiter.shouldAllow(1, 1));  // true, window [1,1]
    results.push_back(limiter.shouldAllow(1, 2));  // true, window [1,2]
    results.push_back(limiter.shouldAllow(1, 3));  // false, window [1,3], count=2
    results.push_back(limiter.shouldAllow(1, 4));  // true! window [2,4], t=1 JUST expired
    
    vector<bool> expected = {true, true, false, true};
    runTest(5, results, expected);
}

void testCase6_ZeroTimestamp() {
    // Timestamp starting at 0
    RateLimiter limiter(3, 2);
    
    vector<bool> results;
    results.push_back(limiter.shouldAllow(1, 0));  // true
    results.push_back(limiter.shouldAllow(1, 0));  // true
    results.push_back(limiter.shouldAllow(1, 0));  // true
    results.push_back(limiter.shouldAllow(1, 0));  // false
    results.push_back(limiter.shouldAllow(1, 1));  // false (still in window)
    results.push_back(limiter.shouldAllow(1, 2));  // true (t=0 expired)
    
    vector<bool> expected = {true, true, true, false, false, true};
    runTest(6, results, expected);
}

void testCase7_ManyUsers() {
    // Many different users
    RateLimiter limiter(1, 10);
    
    vector<bool> results;
    for (int user = 1; user <= 5; user++) {
        results.push_back(limiter.shouldAllow(user, 1));  // all true
    }
    for (int user = 1; user <= 5; user++) {
        results.push_back(limiter.shouldAllow(user, 2));  // all false
    }
    
    vector<bool> expected = {true, true, true, true, true, 
                             false, false, false, false, false};
    runTest(7, results, expected);
}

void testCase8_WindowSizeOne() {
    // Window size of 1 - only current second counts
    RateLimiter limiter(2, 1);
    
    vector<bool> results;
    results.push_back(limiter.shouldAllow(1, 5));   // true
    results.push_back(limiter.shouldAllow(1, 5));   // true
    results.push_back(limiter.shouldAllow(1, 5));   // false
    results.push_back(limiter.shouldAllow(1, 6));   // true (new window)
    results.push_back(limiter.shouldAllow(1, 7));   // true (new window)
    
    vector<bool> expected = {true, true, false, true, true};
    runTest(8, results, expected);
}

void testCase9_HighLimit() {
    // High request limit
    RateLimiter limiter(100, 10);
    
    vector<bool> results;
    // First 100 should pass
    for (int i = 0; i < 100; i++) {
        results.push_back(limiter.shouldAllow(1, 1));
    }
    // 101st should fail
    results.push_back(limiter.shouldAllow(1, 1));
    
    vector<bool> expected(100, true);
    expected.push_back(false);
    runTest(9, results, expected);
}

void testCase10_ComplexScenario() {
    // Complex real-world scenario
    RateLimiter limiter(5, 10);  // 5 requests per 10 seconds
    
    vector<bool> results;
    // Burst of requests
    results.push_back(limiter.shouldAllow(1, 1));   // true (1)
    results.push_back(limiter.shouldAllow(1, 1));   // true (2)
    results.push_back(limiter.shouldAllow(1, 2));   // true (3)
    results.push_back(limiter.shouldAllow(1, 2));   // true (4)
    results.push_back(limiter.shouldAllow(1, 3));   // true (5)
    results.push_back(limiter.shouldAllow(1, 3));   // false (6th)
    
    // Wait for some to expire
    results.push_back(limiter.shouldAllow(1, 11));  // true (t=1 expired, count=3)
    results.push_back(limiter.shouldAllow(1, 11));  // true (count=4)
    results.push_back(limiter.shouldAllow(1, 12));  // true (t=2 expired, count=4)
    results.push_back(limiter.shouldAllow(1, 12));  // true (count=5)
    results.push_back(limiter.shouldAllow(1, 12));  // false (count=5)
    
    vector<bool> expected = {true, true, true, true, true, false,
                             true, true, true, true, false};
    runTest(10, results, expected);
}


// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main() {
    cout << "========================================" << endl;
    cout << "     RATE LIMITER - TEST SUITE" << endl;
    cout << "========================================" << endl << endl;
    
    // Basic test cases
    testCase1();
    testCase2();
    testCase3();
    
    // Uncomment these when ready to test edge cases:
    testCase4_LargeWindowJump();
    testCase5_BoundaryCondition();
    testCase6_ZeroTimestamp();
    testCase7_ManyUsers();
    testCase8_WindowSizeOne();
    testCase9_HighLimit();
    testCase10_ComplexScenario();
    
    cout << endl << "========================================" << endl;
    cout << "         ALL TESTS COMPLETE" << endl;
    cout << "========================================" << endl;
    
    return 0;
}

/*
================================================================================
HINTS (Don't look until you've tried!):
================================================================================

HINT 1: Data Structure
    - Use a deque (double-ended queue) per user to store timestamps
    - unordered_map<int, deque<int>> maps userId -> their request timestamps

HINT 2: Sliding Window Logic
    - Before checking if request is allowed, remove all timestamps that are
      outside the current window: timestamp < (currentTime - windowSize + 1)
    - Use while loop to pop from front of deque

HINT 3: Algorithm
    1. Get/create the deque for this userId
    2. Remove expired timestamps from front
    3. Check if deque.size() < maxRequests
    4. If yes: push current timestamp, return true
    5. If no: return false

HINT 4: Time Complexity
    - shouldAllow: O(k) amortized where k = expired requests removed
    - Space: O(n * m) where n = users, m = maxRequests

================================================================================
SOLUTION TEMPLATE (Implement this in the class above):
================================================================================

class RateLimiter {
private:
    int maxRequests;
    int windowSize;
    unordered_map<int, deque<int>> userRequests;
    
public:
    RateLimiter(int maxRequests, int windowSizeInSeconds) 
        : maxRequests(maxRequests), windowSize(windowSizeInSeconds) {}
    
    bool shouldAllow(int userId, int timestampInSeconds) {
        auto& requests = userRequests[userId];
        
        // Remove expired requests
        int windowStart = timestampInSeconds - windowSize + 1;
        while (!requests.empty() && requests.front() < windowStart) {
            requests.pop_front();
        }
        
        // Check limit
        if (requests.size() < maxRequests) {
            requests.push_back(timestampInSeconds);
            return true;
        }
        return false;
    }
};

================================================================================
FOLLOW-UP QUESTIONS (System Design Discussion):
================================================================================

1. "How would you scale this to handle millions of users?"
   - Distributed Redis with user-based sharding
   - Each Redis instance handles a subset of users (consistent hashing)

2. "How would you handle this across multiple servers?"
   - Centralized rate limiting with Redis (INCR + EXPIRE)
   - Or: Sticky sessions to route same user to same server

3. "What if a server goes down?"
   - Redis replication for high availability
   - Accept slightly higher rate temporarily vs blocking all

4. "Token Bucket vs Sliding Window - trade-offs?"
   - Token Bucket: smoother, allows bursts, more complex
   - Sliding Window: simpler, stricter, can be memory-heavy

5. "How to handle clock skew between servers?"
   - Use centralized timestamp (Redis TIME command)
   - Or: NTP synchronization + small tolerance

================================================================================
*/