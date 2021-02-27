Test = int(input())

while Test:
    ans = ""
    p = input()
    ktim = p.split(' ')
    t = ktim[0].split(':')
    if ktim[1] == 'AM':
        if(t[0] == '12'):
            t = int(t[1])
        else:
            t = int(t[0]+t[1])
    else:
        if(t[0] == '12'):
            t[0] = '00'
        x = int(t[0])+12
        t = int(str(x)+t[1])
    # print(t)
    k = int(input())
    for i in range(k):
        tim = input()
        timing = tim.split(' ')
        t1 = timing[0].split(':')
        t2 = timing[2].split(':')

        if timing[1] == 'AM':
            if(t1[0] == '12'):
                t1 = int(t1[1])
            else:
                t1 = int(t1[0]+t1[1])
        else:
            if(t1[0] == '12'):
                t1[0] = '00'
            x = int(t1[0])+12
            t1 = int(str(x)+t1[1])
        
        if timing[3] == 'AM':
            if(t2[0] == '12'):
                t2 = int(t2[1])
            else:
                t2 = int(t2[0]+t2[1])
        else:
            if(t2[0] == '12'):
                t2[0] = '00'
            x = int(t2[0])+12
            t2 = int(str(x)+t2[1])
        # print(t1,t2)
        if t>=t1 and t<=t2:
            ans = ans + '1'
        else:
            ans = ans + '0'
    print(ans)
    Test -= 1
