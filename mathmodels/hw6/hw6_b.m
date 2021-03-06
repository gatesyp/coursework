function hw6_b
% t goes from 0 to 1
% for complete picture, also plot from 0 to -1
tspan = [0 1];
% play with the initial conditions?
% start:increment size:end condition

for k = -10:2:10
    for i = -10:2:10
        y0 = [i; k];
% solve the ODE, store in y
        [t, y] = ode45(@f, tspan, y0);
% y(:, 1nand y(:, 2) are the data for R(t) and J(t)
        hold on
% plot the two functions parametrically
        plot(y(:, 1), y(:, 2));
% center the plot about origin
        axis([-20 20 -20 20]);
    end
end
grid on
hold off
% add legend
% legend('Romeo', 'Juliet', 2);
% set the background color to white
set(gcf, 'Color', 'w');
% the system: y(1) is R, y(2) is J
% change conditions a and b
% a^2 < b^2 is saddle point
% a^2 > b^2 is stable node
function dydt = f(t, y)
a = 3;
b = -1;
dydt = [a*y(1) + b*y(2)
b*y(1) + a*y(2)];