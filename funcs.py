import re

def agatc(text):
    occurences_len = []
    pattern = re.compile(r"(AGATC)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 5)))
    return int((max(occurences_len) / 5))

def ttttttct(text):
    occurences_len = []
    pattern = re.compile(r"(TTTTTTCT)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 8)))
    return int((max(occurences_len) / 8))

def aatg(text):
    occurences_len = []
    pattern = re.compile(r"(AATG)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 4)))
    return int((max(occurences_len) / 4))

def tctag(text):
    occurences_len = []
    pattern = re.compile(r"(TCTAG)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 5)))
    return int((max(occurences_len) / 5))

def gata(text):
    occurences_len = []
    pattern = re.compile(r"(GATA)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 4)))
    return int((max(occurences_len) / 4))

def tatc(text):
    occurences_len = []
    pattern = re.compile(r"(TATC)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 4)))
    return int((max(occurences_len) / 4))

def gaaa(text):
    occurences_len = []
    pattern = re.compile(r"(GAAA)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 4)))
    return int((max(occurences_len) / 4))

def tctg(text):
    occurences_len = []
    pattern = re.compile(r"(TCTG)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 4)))
    return int((max(occurences_len) / 4))