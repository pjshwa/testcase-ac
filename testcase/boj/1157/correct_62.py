# https://www.acmicpc.net/source/50351707
s = input()

mx_cnt = 0
mx_ch = ''
has_multiple = False
mp = {}
for c_raw in s:
    c = c_raw.upper()
    if c in mp:
        mp[c] += 1
    else:
        mp[c] = 1
    if mp[c] > mx_cnt:
        mx_cnt = mp[c]
        mx_ch = c
        has_multiple = False
    elif mp[c] == mx_cnt:
        has_multiple = True

if has_multiple:
    print('?')
else:
    print(mx_ch.upper())
