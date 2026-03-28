class Solution:
    #def canConstruct(self, ransomNote: str, magazine: str) -> bool:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        freq = {}

        # Step 1: count characters in magazine
        for ch in magazine:
            freq[ch] = freq.get(ch, 0) + 1

        # Step 2: try to use characters
        for ch in ransomNote:
            if freq.get(ch, 0) == 0:
                return False
            freq[ch] -= 1

        return True    