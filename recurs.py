import string

def recurs(str,i):
    if (i==len(str)-1):
        return min(str[0],str[i])
    else:
        return recurs(str,i+1)

str = raw_input('Enter the string: ')
if str[0] in string.hexdigits and str[-1] in string.hexdigits:
    print 'Smaller is',recurs(string.lower(str),0)
else:
    print 'Not hexadecimal numbers'
