import random, os
from string import ascii_lowercase, ascii_uppercase
from msvcrt import kbhit


def random_map():
    alphabet = list(ascii_lowercase)
    map = {}
    while alphabet:
        letter = alphabet.pop(0)
        random_letter = random.choice(alphabet)
        map[letter] = random_letter
        map[random_letter] = letter
        alphabet.remove(random_letter)
    return map

def encrypt(text, map):
    encrypted_text = ''
    for letter in text:
        if letter.lower() in map:
            if letter.isupper():
                encrypted_text += map[letter.lower()].upper()
            else:
                encrypted_text += map[letter]
        else:
            encrypted_text += letter
    return encrypted_text

def decrypt(text, map):
    decrypted_text = ''
    for letter in text:
        if letter.lower() in map:
            if letter.isupper():
                decrypted_text += map[letter.lower()].upper()
            else:
                decrypted_text += map[letter]
        else:
            decrypted_text += letter
    return decrypted_text

lower = dict([(item, index + 1) for index, item in enumerate(ascii_lowercase)])
upper = dict([(item, index + 1) for index, item in enumerate(ascii_uppercase)])

def find_value(value):
    for key, val in lower.items():
        if val == value:
            return str(key) 

def rot13(message):
    result = ''
    for char in message:
        if not char.isalpha():
            result += char
        else:
            if char in lower.keys():
                var = int(lower[char]) + 13 
                if var > 26:
                    var -= 26
                result += find_value(var)
            else:
                var = int(upper[char]) + 13 
                if var > 26:
                    var -= 26
                result += find_value(var).upper()  
  
    return result


map = random_map()
while True:
    os.system('cls')
    print('1. Insert value to encode by Arbitrary substitution of letters')
    print('2. Insert file to encode by Arbitrary substitution of letters')
    print('3. Insert value to encode by ROT13')
    print('4. Insert file to encode by ROT13')
    print('5. Exit')
    choice = input("Choice the option: ")
    
    if choice == '1':
        os.system('cls')
        message = input('Please enter a message: ')
        print('Message encrypted:', encrypt(message, map))
        print('Message decrypted:', decrypt(encrypt(message, map), map))
        print('\nClick enter to continue...')
        while not kbhit():
            pass
     
    elif choice == '2':
        os.system('cls')
        file_name = input('Please enter a name of the file: ')

        dirname = os.path.dirname(__file__)
        path = f'{dirname}\{file_name}'

        try:
            with open(path, 'r') as file:
                message = file.read()
                print('Message encrypted:', encrypt(message, map))
                print('Message decrypted:', decrypt(encrypt(message, map), map))
        except FileNotFoundError:
            os.system('cls')
            print('Insert valid file name!')
        
        print('\nClick enter to continue...')
        while not kbhit():
            pass
    
    elif choice == '3':
        os.system('cls')
        message = input('Please enter a message: ')
        print('Message before:', message)
        print('Message after:', rot13(message))
        print('\nClick enter to continue...')
        while not kbhit():
            pass
        
    elif choice == '4':
        os.system('cls')
        file_name = input('Please enter a name of the file: ')

        dirname = os.path.dirname(__file__)
        path = f'{dirname}\{file_name}'

        try:
            with open(path, 'r') as file:
                message = file.read()
                print('Message before:', message)
                print('Message after:', rot13(message)) 
        except FileNotFoundError:
            os.system('cls')
            print('Insert valid file name!')

        print('\nClick enter to continue...')
        while not kbhit():
            pass

    elif choice == '5':
        exit()
