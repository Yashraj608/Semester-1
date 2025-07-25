#24k-0737
import scipy.constants as const
import sympy as sp
mass_sphere = 10.0e-3
distance = 1.0
force = 1.00e4
electrons_per_atom = 47
molar_mass_silver = 107.87
avogadro_number = const.Avogadro
atoms_per_gram = avogadro_number / molar_mass_silver
atoms_in_sphere = atoms_per_gram * (mass_sphere * 1000)
total_electrons = electrons_per_atom * atoms_in_sphere
k = const.k_e
q = sp.Symbol('q')
equation = sp.Eq(k * (q * q) / (distance ** 2), force)
solution = sp.solve(equation, q)
charge_needed = abs(solution[0])
electron_charge = const.e
fraction_electrons_transferred = charge_needed / (total_electrons * electron_charge)
print(f"Fraction of electrons transferred: {fraction_electrons_transferred:.2e}")
