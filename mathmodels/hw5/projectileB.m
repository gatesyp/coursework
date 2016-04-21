%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% This script numerically solves 2nd-order ODE
% 
% d^2y/dt^2 = -eps/(1+y)^2, y(0)=0, dy/dt(0)=eps
%
% and then plots the solution.
%
% The right-hand side of the equation is defined in 
% the matlab function file 'rhs_projectileB.m'. 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
hold on

global eps;
global l;
l = 1000;          % Declare epsilon as global.
eps = 0;     % Set the value of epsilon.

init = [0 50];   % Set the initial condition of the ODE.

t = [0 50];     % Define the time interval over which solution will be computed.  
                  % You may need to change the right end point to see the long-term
                  % behavior of the solution, depending on epsilon. 


% Set some options used in the next command.  Do not worry about this for now.
options = odeset('RelTol',1e-8, 'AbsTol',1e-8);

% Numerically solve the equation.  See 'ode45' in matlab help for more info on this commmand. 
[T,Y] = ode45(@rhs_spring,t,init,options);
%hold on 

% for loop goes here
% for 
%hold odd
% Plot the solution. 

% position
subplot(2,1,1)
set(gca,'FontSize',24)
plot(Y(:,1),Y(:,2))   

title('level curves')

hold off
%% velocity
%subplot(2,1,2)
%set(gca,'FontSize',24)
%plot(T,Y(:,2))
%title(['y'' versus tau, eps=', num2str(eps)])

% To save the plots for printing, uncomment the following line.

%saveas(gcf,'eps2.pdf');