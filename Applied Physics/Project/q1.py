#24k-0737
q = 1.602e-19  
m = 9.109e-31  
E = 200        
v_i = 3.00e6   
length = 0.100 
F = q * E
a = F / m
print(f"Acceleration of the electron: {a} m/s^2")

t = length / v_i
print(f"Time to travel through the field: {t} seconds")
mass_silver = 10.0         
molar_mass_silver = 107.87 
N_A = 6.022e23             
n_moles = mass_silver / molar_mass_silver
n_atoms = n_moles * N_A
n_electrons_pin = n_atoms * 47
print(f"Number of electrons in the silver pin: {n_electrons_pin}")
Q = 1.00e-3   
n_added_electrons = Q / q
print(f"Number of added electrons: {n_added_electrons}")
additional_electrons_ratio = n_added_electrons / 1e9
print(f"Added electrons for every 10^9 electrons: {additional_electrons_ratio}")
