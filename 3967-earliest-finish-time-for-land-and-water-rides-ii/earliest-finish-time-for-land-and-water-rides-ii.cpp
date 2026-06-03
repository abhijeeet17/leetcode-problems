class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        long long ans = LLONG_MAX;

        vector<pair<int, int>> water(m); 
        for (int i = 0; i < m; i++) {
            water[i] = {waterStartTime[i], waterDuration[i]};
        }

        sort(water.begin(), water.end());

        vector<int> wStart(m);
        vector<long long> prefMinDur(m), suffMinOpenFinish(m);

        for (int i = 0; i < m; i++) {
            wStart[i] = water[i].first;
        }

        prefMinDur[0] = water[0].second;
        for (int i = 1; i < m; i++) {
            prefMinDur[i] = min(prefMinDur[i - 1],
                                (long long)water[i].second);
        }

        suffMinOpenFinish[m - 1] =
            (long long)water[m - 1].first + water[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffMinOpenFinish[i] =
                min(suffMinOpenFinish[i + 1],
                    (long long)water[i].first + water[i].second);
        }

        for (int i = 0; i < n; i++) {
            long long A = (long long)landStartTime[i] + landDuration[i];

            int pos = upper_bound(wStart.begin(), wStart.end(), A) - wStart.begin() - 1;

            long long best = LLONG_MAX;

            if (pos >= 0) {
                best = min(best, A + prefMinDur[pos]);
            }

            if (pos + 1 < m) {
                best = min(best, suffMinOpenFinish[pos + 1]);
            }

            ans = min(ans, best);
        }
        vector<pair<int, int>> land(n); 
        for (int i = 0; i < n; i++) {
            land[i] = {landStartTime[i], landDuration[i]};
        }

        sort(land.begin(), land.end());

        vector<int> lStart(n);
        vector<long long> prefMinLandDur(n), suffMinLandOpenFinish(n);

        for (int i = 0; i < n; i++) {
            lStart[i] = land[i].first;
        }

        prefMinLandDur[0] = land[0].second;
        for (int i = 1; i < n; i++) {
            prefMinLandDur[i] =
                min(prefMinLandDur[i - 1],
                    (long long)land[i].second);
        }

        suffMinLandOpenFinish[n - 1] =
            (long long)land[n - 1].first + land[n - 1].second;

        for (int i = n - 2; i >= 0; i--) {
            suffMinLandOpenFinish[i] =
                min(suffMinLandOpenFinish[i + 1],
                    (long long)land[i].first + land[i].second);
        }

        for (int j = 0; j < m; j++) {
            long long B = (long long)waterStartTime[j] + waterDuration[j];

            int pos = upper_bound(lStart.begin(), lStart.end(), B) - lStart.begin() - 1;

            long long best = LLONG_MAX;
            if (pos >= 0) {
                best = min(best, B + prefMinLandDur[pos]);
            }
            if (pos + 1 < n) {
                best = min(best, suffMinLandOpenFinish[pos + 1]);
            }

            ans = min(ans, best);
        }

        return (int)ans;
    }
};