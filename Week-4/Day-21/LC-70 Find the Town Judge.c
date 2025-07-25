int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int trustScore[n + 1]; // Indexing from 1 to n
    for (int i = 0; i <= n; i++) {
        trustScore[i] = 0;
    }

    for (int i = 0; i < trustSize; i++) {
        int a = trust[i][0];
        int b = trust[i][1];
        trustScore[a]--;  // person a trusts someone
        trustScore[b]++;  // person b is trusted
    }

    for (int i = 1; i <= n; i++) {
        if (trustScore[i] == n - 1) {
            return i; // found the judge
        }
    }

    return -1; // judge not found
}
