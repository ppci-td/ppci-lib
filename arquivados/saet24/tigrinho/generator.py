import random
import scipy
import numpy as np
import math
import matplotlib.pyplot as plt
import pprint
global_words = []

f = open('in_out/in_4.txt', 'w')

def create_word(word):
    global_words.append(word)

def display_words(n, w):
    f.write(f'{n}\n')
    for word in w:
        f.write(f'{word} ')
    f.write('\n')

def gen_words_tex(mean, stdev, num_words = 20):
    # print('Generating words\n')
    tex_words = {}
    text = []
    for i in range(num_words):
        word = math.trunc(np.random.normal(mean, stdev))
        text.append(word)
        if word not in global_words:
           create_word(word)
           tex_words[word] = 1
           continue

        if tex_words.get(word):
            tex_words[word] += 1   
            continue
        tex_words[word] = 1
    return tex_words, text
        
n1 = 100
n2 = 100
text1_wc, text1 = gen_words_tex(100, 50, n1)
text2_wc, text2 = gen_words_tex(150, 50, n2)

display_words(n1, text1)
display_words(n2, text2)

ss = random.randint(10, max(15, int(min(n1, n2)/4)))
# print(ss)
f.write(f'{ss}\n')

_, sentence = gen_words_tex(10, 2, ss)

for i in  sentence:
    f.write(f'{i} ')
f.write('\n')
# for i in range(ss):
    # idx = random.randint(0, len(global_words)-1)
    # print(global_words[idx], end=" ")
# print()
f.close()