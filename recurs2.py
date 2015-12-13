import string
def recurs(str,i):
    return min(str[0],str[i]) if (i==len(str)-1) else recurs(str,i+1)
str = raw_input('Enter the string: ')
print ('Smaller is',recurs(string.lower(str),0)) if (str[0] in string.hexdigits and str[-1] in string.hexdigits)\
    else 'Not hexadecimal numbers'
