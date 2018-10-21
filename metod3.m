syms x y z
M=[x^2+y^2+z, x*y*z, z+y-x]
x0=0.5
y0=0.5;
z0=0.5;
%while(   >eps)
W=jacobian(M)
X=[x0,y0,z0]
W1=subs(W,x,x0);
W1=subs(W1,y,y0);
W1=subs(W1,z,z0);
W2=double(W1)
DX=inv(W2)*funk(x0,y0,z0)

