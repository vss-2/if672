def main(N, trust):
        s, t, u = set(), set(), set()
        for i in trust:
                s.add(i[0])
                t.add(i[1])
        u = s.union(t)
        if(trust == []):
                return 1
        t = t.difference(s)
        for n in t:
                for i in trust:
                        if([i[0],n] not in trust):
                                return -1
                        else:
                                continue
        if(len(t) == 0):
                return -1
        return t.pop()
               

# print(main(3, trust = [[1,2],[2,3]]))
# print(main(4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]))
# print(main(2, trust = [[1,2]]))
# print(main(3, trust = [[1,3],[2,3],[3,1]]))
