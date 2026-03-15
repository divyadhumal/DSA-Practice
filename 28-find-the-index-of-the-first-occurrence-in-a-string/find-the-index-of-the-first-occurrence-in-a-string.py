class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(haystack)
        m = len(needle)

        for i in range(n - m + 1):   # possible starting index
            j = 0

            while j < m and haystack[i + j] == needle[j]:
                j += 1

            if j == m:   # full match found
                return i

        return -1
        