h = 1;
x = 5:h:10;
y = sqrt((x.^3) + 1) .* sin(x);
figure(1)
plot(x,y)
h = .01;
x = 5:h:10;
y = sqrt((x.^3) + 1) .* sin(x);
figure(2)
plot(x,y)