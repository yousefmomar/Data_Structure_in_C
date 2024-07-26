import random
LVL_CH=10
LVL=1
total=0
while LVL<=10:

    tn=random.randint(1,10)

    print("LEVEL",LVL)
    print("===========")

    score=100
    Chances=1
    while Chances<=LVL_CH:

        punish=100/LVL_CH
        
        gn=int(input("Guess the number:"))

        if gn==tn:
            LVL+=1
            LVL_CH-=1
            total+=score
            print("YOU WIN!!")
            print("This Level score:",round(score,2),"\n")
            break
        elif gn>tn :
            score-=punish
            print("Go Lower!\n")
        elif gn<tn :
            score-=punish
            print("Go Higher!\n")

        Chances+=1
        
    else:
        print("GAME OVER!!\n")

round(total,2)    
print("Final Score:",round(total,2),"\n")
print("THE END")




