def longest_prefix(words):
    for i in range(len(words[0])):
        c = words[0][i]
    for j in range(1,len(words)):
        if i >= len(words[j]) or \
           c != words[j][i]:
            return words[j][:i]
    return words[0]
print(longest_prefix(['programming','program','progtagonist']))