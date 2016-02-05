function dy = rhs_projectileB(t,y)

global eps;

dy = zeros(2,1);

dy(1) = y(2);

dy(2) = -eps/(y(1)+1).^2;
