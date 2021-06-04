# -*- coding: utf-8 -*-
import sys
sys.path.append('C:/Users/Домашний/Desktop/PoKoEv/')
import pokoev
print(pokoev.matrix_number([[-1,2,-2],[2,-1,5],[3,-2,4]],100))
print(pokoev.matrix_multi([[1,2,3],[4,5,6],[7,8,9]],[[1,0,0],[0,1,0],[0,0,1]]))
print(pokoev.sum_matr([[-1,2,-2],[2,-1,5],[3,-2,4]],[[324,2,10],[2,-36,5],[63,-2,40]]))
print(pokoev.matrix_transpose([[-1,2,-2,25],[2,-1,5,34],[3,-2,4,23],[0,-200,5,-23]]))
print(pokoev.Rotation([[-1,2,-2,25],[2,-1,5,34],[3,-2,4,23],[0,-200,5,-23]],[10,2,-27,34]))
print(pokoev.Zeydel([[-1,2,0],[2,-1,1],[3,-2,1]],[-1,-2,0],0.001))