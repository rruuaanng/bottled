function [alpha,beta] = test_clarke_direct_2p_verify(a,b)
    alpha = a;
    x0 = (sqrt(3) * a) / 3;
    x1 = (2 * sqrt(3) * b) / 3;
    beta = x0 + x1;
end

