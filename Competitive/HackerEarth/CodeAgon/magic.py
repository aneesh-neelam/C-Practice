import math
import fractions

s = raw_input()
N = int(s)

count = 0

for a in range(1, N + 1):
	factors = []
	print(str(a))
	factN = math.factorial(a)
	for i in range(1, a + 1):
		factors.append(i)

	for i in range(a + 1, (factN / 2) + 1) :
		if factN % i == 0:
			factors.append(i)

	factors.append(factN)

	for elt in factors:
		for elt2 in factors[factors.index(elt):]:
			if elt * elt2 == factN:
				tmp = fractions.gcd(elt2, elt)
				if tmp == 1 and elt < elt2:
					count += 1
					print(str(elt) + ', ' + str(elt2))


print(str(count - 1))