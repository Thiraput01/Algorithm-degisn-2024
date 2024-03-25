# - เขียนในเซลล์นี้เท่านั้น 
# - ถ้าต้องการเขียนฟังก์ชันเพิ่ม ก็เขียนในเซลล์นี้

# ตัวแปรต่อไปนี้เป็นตัวแปรที่กำหนดค่าสีเพื่อเอาไว้ใช้ในโปรแกรม (ห้ามแก้ไข)
RESET = '\033[0m'
RED = '\033[;31m'
GREEN = '\033[;32m'
BLUE = '\033[;34m'
HIGHLIGHT = '\033[;103m'

# ---------------------------------------------------
def red(s):
    # ลบบรรทัด pass แล้วเขียนโค้ดของนิสิตแทน
    return RED + str(s) + RESET
# ---------------------------------------------------
def green(s):
    # ลบบรรทัด pass แล้วเขียนโค้ดของนิสิตแทน
    return GREEN + str(s) + RESET
# ---------------------------------------------------
def blue(s):
    # ลบบรรทัด pass แล้วเขียนโค้ดของนิสิตแทน
    return BLUE + str(s) + RESET
# ---------------------------------------------------
def highlight(s):
    # ลบบรรทัด pass แล้วเขียนโค้ดของนิสิตแทน
    return HIGHLIGHT + str(s) + RESET
# ---------------------------------------------------
def color_text(s, color):
    # ลบบรรทัด pass แล้วเขียนโค้ดของนิสิตแทน
    if color.upper() == 'RED':
        return red(s)
    elif color.upper() == 'GREEN':
        return green(s)
    elif color.upper() == 'BLUE':
        return blue(s)
    else:
        return s
# ---------------------------------------------------
def color_tag(s):
    # ลบบรรทัด pass แล้วเขียนโค้ดของนิสิตแทน
    first_1 = s.find('<')
    last_1 = s.find('>')
    first_2 = s.find('<',first_1+1)
    color = s[first_1+1:last_1]
    text = s[last_1+1:first_2]
    if color.lower() == 'red':
        return red(text)
    elif color.lower() == 'green':
        return green(text)
    elif color.lower() == 'blue':
        return blue(text)
    else:
        return text
        
    
# ---------------------------------------------------
def highlight_words(s, words):
    # ลบบรรทัด pass แล้วเขียนโค้ดของนิสิตแทน
    word_1 = [e.lower() for e in words] # = ['print', 'ดาว', 'มิใช่']
    word_2 = [e.upper() for e in words] # = ['PRINT', 'ดาว', 'มิใช่']
    word = []
    for k in range(len(words)):
        if word_1[k] == word_2[k]:
            word.append(word_1[k])
        else:
            word.append(word_1[k])
            word.append(word_2[k])
    #word = ['print', 'PRINT', 'ดาว', 'มิใช่']
    f = 0 ; l = 0
    for i in word:
        f = s.find(i) 
        l = f + len(i)
        while f != -1:
            s = s[:f] + highlight(i) + s[l:]
            f = s.find(i,f+len(highlight(i)))
            l = f + len(i)
        f = 0 ; l = 0
    return s
    #สามารถ Highlight ทั้งตัวพิมพ์เล็ก - พิมพ์ใหญ่ได้
        
    
# ---------------------------------------------------
def display_tag_file(filename):
    # ลบบรรทัด pass แล้วเขียนโค้ดของนิสิตแทน
    fn = open(filename, "r", encoding = 'utf-8')
    for line in fn:
        start = line.find('<')
        stop = line.find('<',start+1) + 3
        while start != -1:
            line = line[:start] + color_tag(line[start:stop]) + line[stop:]
            start = line.find('<',start+len(color_tag(line[start:stop])))
            stop = line.find('<',start+1) + 3
        print(line)
            
    fn.close()
    
display_tag_file('มหาจุฬาลงกรณ์-tag.txt')
