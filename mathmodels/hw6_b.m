function hw6_b
% t goes from 0 to 8
% the initial conditions are 1 and 0
tspan = [0 5];
y0 = [50; 50];
% call ODE solver ”ode45” to solve the system
% determined by f (see the end of the code), tspan
%and y0
[t, y] = ode45(@f, tspan, y0);
% the solutions are returned to variable y
% y(:, 1) and y(:, 2) are the data for R(t) and J(t)
hold off
plot(t, y(:, 1), t, y(:, 2));
axis([-100 100 -100 100]);
% add legend
%legend('Romeo', 'Juliet', 2);
% set the background color to white
set(gcf, 'Color', 'w');
% the system: y(1) is R, y(2) is J
function dydt = f(t, y)
a = 4;
b = -1;
dydt = [a*y(1) + b*y(2)
b*y(1) + a*y(2)];