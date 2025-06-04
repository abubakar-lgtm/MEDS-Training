def exp(x, terms=20):
    result = 1.0  
    term = 1.0    
    
    for n in range(1, terms):
        term *= x / n  
        result += term
    
    return result

import math

x = 2
print("Taylor:", exp(x))
print("Math lib:", math.exp(x))

    
