#24k-0737
import numpy as np
k = 8.99e9
lambda_charge = 35.0e-9
y = -0.15
x_start = 0.0
x_end = 0.4
def electric_field_x(x):
    r = np.sqrt(x**2 + y**2)
    dE = k * lambda_charge / r**2
    dE_x = dE * (x / r)
    return dE_x
E_x = np.trapz([electric_field_x(x) for x in np.linspace(x_start, x_end, 1000)], np.linspace(x_start, x_end, 1000))
print(f"The electric field at the origin due to the line of charge is {E_x:.2e} N/C in the positive x-direction.")
