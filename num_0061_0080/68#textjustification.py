"""
68. Text Justification

Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Note:
    - A word is defined as a character sequence consisting of non-space characters only.
    - Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    - The input array words contains at least one word.
"""

class Solution:
    def fullJustify(self, words, maxWidth: int) :
        i, N, result = 0, len(words), []
        while i < N:
            # decide how many words to be put in one line
            oneLine, j, currWidth, positionNum, spaceNum = [words[i]], i + 1, len(words[i]), 0, maxWidth - len(words[i])
            while j < N and currWidth + 1 + len(words[j]) <= maxWidth:
                oneLine.append(words[j])
                currWidth += 1 + len(words[j])
                spaceNum -= len(words[j])
                positionNum, j = positionNum + 1, j + 1
            i = j
            # decide the layout of one line
            if i < N and positionNum:
                spaces = [' ' * int((spaceNum / positionNum + (k < spaceNum % positionNum))) for k in range(positionNum)] + ['']
            else: # last line or the line only has one word
                spaces = [' '] * positionNum + [' ' * int(maxWidth - currWidth)]
            result.append(''.join([s for pair in zip(oneLine, spaces) for s in pair]))
        return result

def main():
    words = ["Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"]
    print(Solution().fullJustify(words, 20))

if __name__ == "__main__":
    main()