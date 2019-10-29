import math 

N = int(input("Digite o valor da população (N) "))
n = int(input("Digite o valor da amostra (n) "))
x = float(input("Digite o valor da média (x) "))
s = float(input("Digite o valor do desvio padrão (S) "))
z = int(input("Digite o valor do grau de confiança (z) em % "))
p = float(input("(p)"))

if z == 99 :
    z = 2.58
if z == 95 :
    z = 1.96
if z == 90 :
    z == 1.65

correcao = n/N
media = x
if correcao < 0.05 : 
    e = (z * s/(math.sqrt(n))) * math.sqrt(N-n/N-1)
    resx1 = x - e
    resx2 = x + e

    e2 = (z * math.sqrt((p*(1-p))/n)) * math.sqrt(N-n/N-1)
    resp1 = p - e2
    resp2 = p + e2  
else :
    prtx1 = (z * s/math.sqrt(n))
    resx1 = x - prtx1
    resx2 = x + prtx1

    prtp1 = (z * math.sqrt(p*(1-p)/n))
    resp1 = x - prtp1
    resp2 = x + prtp1

print("Correção", correcao)
print("A estimativa pontual é ", media)
print("A estimativa itervalar é ", resx1, " a ", resx2)
print("A estimativa itervalar é ", resp1, " a ", resp2)

    
