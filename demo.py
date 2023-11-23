class Test:
    def proc(self, data=[]):
        data.append('end')
        return data

t1 = Test()
print(t1.proc())
print(t1.proc())

t2 = Test()
print(t2.proc(data=['hello']))
print(t1.proc(data=['hello']))
print(t1.proc(data=['hello']))
print(t1.proc(data=[]))
print(t1.proc())