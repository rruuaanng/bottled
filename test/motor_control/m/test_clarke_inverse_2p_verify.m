function [a,b,c] = test_clarke_inverse_2p_verify(alpha,beta)
a = alpha;
b = (0 - alpha + sqrt(3) * beta) / 2;
c = (0 - alpha - sqrt(3) * beta) / 2;
end

