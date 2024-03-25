filename = input().strip()
target = input().strip()
newText = input().strip()


def isEqual(s1, target):
    if len(s1) != len(target):
        return False
    s1 = s1.lower()
    target = target.lower()
    for i in range(len(s1)):
        if target[i] != '?' and target[i] != s1[i]:
            return False
    return True


with open(filename, 'r') as f:
    for line in f:
        line = line.strip()
        output = ""
        word = ""
        for i in line:
            if i == '/':
                if isEqual(word, target):
                    word = newText
                output += word+"/"
                word = ""
            else:
                word += i
        output += word
        print(output)