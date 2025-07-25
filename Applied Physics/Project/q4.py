#24k-0737
# Given values
E = 890  # Electric field in N/C
r = 0.750  # Radius in meters
k = 8.99e9  # Coulomb's constant in N*m^2/C^2
# Calculate the net charge Q
Q = (E * r**2) / k
# Output the result
print(f"The net charge within the sphere's surface is {Q:.2e} C.")
# Part (b) analysis
if E < 0:
    charge_nature = "negative"
else:
    charge_nature = "positive"
print(f"The electric field points radially toward the center, indicating the charge is {charge_nature}. The charge is uniformly distributed over the shell.")
