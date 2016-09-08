% the 'o' is an optional third parameter
% that formats the graph of x1,y1
% Second approach
x = 5:1:10;
y = sqrt((x.^3) + 1) .* sin(x);
figure(1)
hold on
plot(x,y,'o')
x = 5:.01:10;
y = sqrt((x.^3) + 1) .* sin(x);
plot(x,y)