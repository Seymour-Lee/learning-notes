import os

dir_path = '.'
outf = open('list_markdown.txt', 'w')

strs = os.listdir(dir_path)

for str in sorted(strs):
    if str.find(".cpp") != -1:
        name = '### ' + str[:-4]
        outf.write(name + "\n\n")

outf.close()