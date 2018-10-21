syms x y;
M=[x^2+y^2-1,log(x)+2*y+1];
eps=input('Введите точность: ')
x0=input('Введите x0: ')
y0=input('Введите y0: ')
k=0;
DX=[eps*2,eps*2];
while(  abs(DX(1,:))>eps)
W=jacobian(M);
W1=subs(W,x,x0);
W1=subs(W1,y,y0);
W2=double(W1);
DX=inv(W2)*func(x0,y0);
x0=x0+DX(1,:);
y0=y0+DX(2,:);
k=k+1;
end
sprintf('\nx=%f  \ny=%f  \nk=%f', x0, y0, k)