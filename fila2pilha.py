class Queue:
	def __init__(self):
		self.s1 = []
		self.s2 = []
		return

	def enqueue(self, value):
		s1, s2 = self.s1, self.s2
		s2.append(value)
		for i in range(-len(s1), 0, +1):
			s2.append(s1[i])
		s1 = s2.copy()
		s2 = []
		self.s1, self.s2 = s1, s2
		print(s1, s2)
		return
	
	def dequeue(self):
		return self.s1.pop()

q = Queue()
q.enqueue(1)
q.enqueue(2)
print(q.dequeue())
q.enqueue(3)
q.enqueue(4)
print(q.dequeue())
q.enqueue(5)
print(q.dequeue())
print(q.dequeue())
q.enqueue(6)
print(q.dequeue())
print(q.dequeue())
