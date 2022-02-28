import re
import string



def itemCount():
    frequency = {}
    fname = open('CS210_Project_Three_Input_File.txt', 'r')
    item_string = fname.read().lower()
    match_pattern = re.findall(r'\b[a-z]{3,15}\b', item_string)
 
    for word in match_pattern:
        count = frequency.get(word,0)
        frequency[word] = count + 1
     
    frequency_list = frequency.keys()

    print('\nAll items purchased + purchase frequency: ')

    for words in frequency_list:
        print (words, frequency[words])
    
def itemFrequency(item):
    with open('CS210_Project_Three_Input_File.txt') as f:
            return ''.join(f).count(item)
      