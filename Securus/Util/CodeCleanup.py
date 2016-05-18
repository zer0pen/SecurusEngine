import codecs
import glob
import sys

for src in glob.glob("../Securus/*.h") + glob.glob("../Securus/*.cpp"):
    inp = outp = src
    content = ""
    with codecs.open(inp, "rU", "utf-8") as infile:
        content = infile.read()
    with codecs.open(outp, "w", "utf-8") as output:
        for line in content.splitlines():
            newline = line.rstrip(" \t")
            output.write(newline + "\r\n")

    print("{} Done.".format(src))
