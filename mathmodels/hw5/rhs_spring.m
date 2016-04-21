function dy = rhs_spring(t,y)

global eps;
global l;

dy = zeros(2,1);

dy(1) = y(2);

dy(2) = -(sqrt(y(1).^2 +1) - l) * y(1)/(sqrt(y(1).^2 + 1)) - (eps*y(2)); 