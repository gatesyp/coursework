function [xp,xm] = quadform (a, b, c)
if(b<0)
  xp = (-b-sqrt(b^2-(4*a*c))) / (2*a);
  xm = c / (a*xp);

 else
  xm = (-b+sqrt(b^2-(4*a*c))) / (2*a);
  xp = c / (a*xm);
end
