#24k-0737
import sympy as sp
q1 = 15.0e-6  
q2 = 6.0e-6   
x1 = 2.0      
k = 8.99e9    
x = sp.Symbol('x')
F13 = k * q1 / (x1 - x)**2
F23 = k * q2 / x**2
equation = sp.Eq(F13, F23)
solution = sp.solve(equation, x)
x3 = [sol.evalf() for sol in solution]
print(f"x coordinate of q3: {x3}")
