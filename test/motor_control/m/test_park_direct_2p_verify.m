function [q,d] = test_park_direct_2p_verify(alpha, beta, angle)
angle_deg = deg2rad(angle);
d = (alpha * cos(angle_deg)) + (beta * sin(angle_deg));
q = (0 - alpha * sin(angle_deg)) + (beta * cos(angle_deg));
end

