%Sean Basler
%Lab1 Section 5
%*****************
clc; clear all;

a = [3,8;1,9];
b = [4,9;1,6];
c = [1;2];

d = a + b;
e = a - b;

f = a * b;
f1 = a * c;

g = a / b;
g1 = a \ c; %multiplying c with inverse of a
%**************************

h = a .* b;
h1 = a ./ b;
h2 = b .^ 2;

%**************************
%Q2
a = [1.5, 3.3;6.0, -4.5; -2.5, 0.7];
b = [0.5,0.3;-0.1,0.2;0.4,-0.3];
c = [1,2;1,2];
d = [3.1,1.4,-0.3;-0.5,1.6,0.1];

e = a-(b*c^(2))+2*d';
%**************************
%Q3
b = [1,2,3;1,2,3;1,2,3;];
c = [1,2,3;1,2,3;1,2,3;];
d = [1,2,3;1,2,3;1,2,3;];

f = b-c*(d)^(4);