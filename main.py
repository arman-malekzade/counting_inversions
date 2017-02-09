def merge_and_count(l1,l2):
    merged=[]
    i=0
    j=0
    inversions=0
    while(i<len(l1) and j<len(l2)):
        if(l1[i]<=l2[j]):
            merged.append(l1[i])
            i=i+1
        else:
            merged.append(l2[j])
            inversions=inversions+(len(l1)-i)
            j=j+1
    if(i==len(l1)):
        while(j!=len(l2)):
            merged.append(l2[j])
            j=j+1
    else:
        while(i!=len(l1)):
            merged.append(l1[i])
            i=i+1
    return inversions,merged
def sort_and_count(l):
    if(len(l)==1):
        return 0,l
    else:
        first_half=l[:len(l)/2]
        second_half=l[len(l)/2:]
        tup1=sort_and_count(first_half)
        tup2=sort_and_count(second_half)
        tup3=merge_and_count(tup1[1],tup2[1])
        return tup1[0]+tup2[0]+tup3[0],tup3[1]
l=[1,5,4,8,10,2,6,9,12,11,3,7]
print sort_and_count(l)
