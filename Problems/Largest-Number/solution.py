import itertools
newls = list(map(int, input().split()))

result = []

for permutation in itertools.permutations(str(number) for number in newls):
   result.append(''.join(permutation))

maximum = max(result, key=int)
print(str(maximum))
