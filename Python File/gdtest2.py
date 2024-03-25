x = input().split()
ally = {}
enemy = {}
while x[0] != 'End':
    if x[0] == 'Ally':
        allcoun = x[1:]
        for i in range(len(allcoun)):
            for j in range(i+1,len(allcoun)):
                if allcoun[i] not in ally:
                    ally[allcoun[i]] = allcoun[j]
                if allcoun[j] not in ally:
                    ally[allcoun[j]] = allcoun[i]
    elif x[0] == 'Enemy':
        allcoun = x[1:]
        for i in range(len(allcoun)):
            for j in range(i+1,len(allcoun)):
                if allcoun[i] not in enemy:
                    enemy[allcoun[i]] = allcoun[j]
                if allcoun[j] not in enemy:
                    enemy[allcoun[j]] = allcoun[i]
    x = input().split()
    print(ally)
    print(enemy)