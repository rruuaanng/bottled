function [alpha,beta] = test_park_inverse_2p_verify(q,d,angle)
angle_deg = deg2rad(angle);

alpha = (d * cos(angle_deg)) - (q * sin(angle_deg));
beta = (d * sin(angle_deg)) + (q * cos(angle_deg));
end

