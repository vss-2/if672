def dnfp(array):
        i = j = 0
        k = len(array)
        m = k//2

        while j < k:
                if(array[j] < array[m]):
                        array[i], array[j] = array[j], array[i]
                        i += 1
                        j += 1
                elif(array[j] > array[m]):
                        k -= 1
                        array[j], array[k] = array[k], array[j]
                else:
                        print('avance', array[j])
                        j += 1
        return array

print(dnfp([2,2,0,1,1,0]))