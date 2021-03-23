import string

cipher = "BPCPVT HIPQAT QPIIAT TMXHI"
alphabet = string.ascii_uppercase

for i in range(len(alphabet)):
    moved_alphabet = alphabet[i:] + alphabet[0:i]
    key_map = {moved_alphabet[i]: alphabet[i] for i in range(len(alphabet))}
    plaintext = ''

    for letter in cipher:
        if letter == ' ':
            plaintext += letter
        else:
            plaintext += key_map[letter]
    print(plaintext)