f = @(x) (sin(x.^3));

x=5.201; 
fprintf('f(%.8f) = %.10e \n',x,f(x))
x= -8323.6;
fprintf('f(%.8f) = %.10e \n',x,f(x))
x= 0.0003;
fprintf('f(%.8f) = %.10e \n',x,f(x))

