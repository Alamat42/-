function [MW] = funk (x0, y0, z0)
MW=[x0^2+y0^2+z0; x0*y0*z0; z0+y0-x0]
MW=-MW
endfunction
