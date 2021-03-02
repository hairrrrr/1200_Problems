@echo off 
copy orders.i%1 orders.in
copy orders.o%1 orders.std
orders
test
@echo on
