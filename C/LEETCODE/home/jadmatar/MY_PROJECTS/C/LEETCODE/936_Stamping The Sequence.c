/*
 * @lc app=leetcode id=936 lang=c
 *
 * [936] Stamping The Sequence
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* movesToStamp(char* stamp, char* target, int* returnSize) {
    int TargetSize=strlen(target);
    int StampSize=strlen(stamp);
    int t[TargetSize];
    for(int i=0;i<=TargetSize-StampSize;i++)
    {
        for(int j=0;j<StampSize;j++)
        {
            if(target[i+j]==stamp[j] || target[i+j]=='?')
            {
                target[i]='?';
                t[i]=i;
            }
        }
    }
}
// @lc code=end

