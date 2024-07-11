import random
# Zalgo works by stacking diacritics on top of each other.
def zalgo(text, intensity):
    result = ""
    for char in text:
        for j in range(intensity):
            # 768-800 marks the range of unicode where all the characters are diacritics.
            result += chr(random.randrange(768, 880)) # Stacks another diacitic
        result += char # At the end of all the diacritics for a particular character, that character is added.
    return result
print(zalgo("Zalgo Text", 2))
