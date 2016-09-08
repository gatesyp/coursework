f = @(x) ((exp(x)) .* sin(x) ) ./ ((x.^2) + 1)

h = 1;
x1 = 3:h:7;
y1 = f(x1);
figure(1)

h = .01;
x2 = 3:h:7;
y2 = f(x2);
plot(x1,y1, 'o', x2, y2)
