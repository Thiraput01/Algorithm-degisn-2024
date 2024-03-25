def match(word,pattern,include_chars,exclude_chars):
    ans = False
    inc = list(include_chars)
    if len(word) == len(pattern):
        for i in range(len(pattern)):
            if pattern[i] != '?':
                if pattern[i] == word[i]:
                    ans = True
            else:
                if word[i] not in exclude_chars:
                    ans = True
                if len(inc) != 0:
                    
                    if word[i] in inc:
                        ans = True
                        inc.remove(word[i])
                        if len(inc) == 0:
                            return True
                        else:
                            ans = False
                    else:
                        ans = False
                else:
                    pass
                    
        
    return ans            
                    
            
            
print(match("MACMA", "?????", "AMMA", "OK")) #True

                    