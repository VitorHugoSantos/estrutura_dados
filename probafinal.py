import math 
print("|  Programa para calcular a estimativa de média ou estimativa de proporção |")
print("   =======================================================================")
print(" ")
lop = 1

while lop == 1:
    escolha = int(input("| Digite 1 se quiser estimativa de média ou 2 se quiser a estimativa de proporção "))
    if escolha == 1:
        N = int(input("| Digite o valor da população (N) "))
        n = int(input("| Digite o valor da amostra (n) "))
        x = float(input("| Digite o valor da média (x) "))
        s = float(input("| Digite o valor do desvio padrão (S) "))
        z = int(input("| Digite o valor do grau de confiança (gc) em % "))

        if z == 99 :
            z = 2.58
        if z == 95 :
            z = 1.96
        if z == 90 :
            z = 1.65

        correcao = n/N
        media = x

        if correcao > 0.05 : 
            e = (z * s/(math.sqrt(n))) * math.sqrt(N-n/N-1)
            resx1 = x - e
            resx2 = x + e

        else :
            e = (z * s/math.sqrt(n))
            resx1 = x - e
            resx2 = x + e
        print(" ")
        print("==============================================================")
        print("|Erro de: {0:.2f}".format(e))
        print("|A estimativa pontual é: {0:.2f}".format(media))
        print("|A estimativa itervalar é {0:.2f} a {1:.2f}".format(resx1,resx2))
        print("==============================================================")
        print(" ")

    if escolha == 2:
        N = int(input("| Digite o valor da população (N) "))
        n = int(input("| Digite o valor da amostra (n) "))
        z = int(input("| Digite o valor do grau de confiança (gc) em % "))
        p = float(input("| Digite o proporção amostral (p) (Entre 0 e 1) "))

        if z == 99 :
            z = 2.58
        if z == 95 :
            z = 1.96
        if z == 90 :
            z = 1.65

        correcao = n/N

        if correcao > 0.05 : 
            e2 = (z * math.sqrt(p*(1-p)/n)) * math.sqrt((N-n)/(N-1))
            resp1 = p - e2
            resp2 = p + e2  
        else :
            e2 = (z * math.sqrt(p*(1-p)/n))
            resp1 = p - e2
            resp2 = p + e2

        print(" ")
        print("==============================================================")
        print("|Erro de: {0:.2f}% ".format(e2*100))
        print("|A estimativa pontual é: {0:.2f}%".format(p*100))
        print("|A estimativa itervalar é {0:.2f}% " "a {1:.2f}% ".format((resp1*100),(resp2*100)))
        print("==============================================================")
        print(" ")
    lop = int(input("| Digite 1 se deseja continuar e 0 se deseja sair "))
    print(" ")
print("| Programa feito por Vitor Hugo Bittencourt |")
print("=============================================")
        

