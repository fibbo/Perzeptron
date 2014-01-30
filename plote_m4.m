clear;

run('import_error_momterm4.m');
run('import_output_momterm4.m');
output0 = double.empty;
x0 = int32.empty;
output1 = double.empty;
x1 = int32.empty;
for idx = 1:numel(output_m4)
    if output_m4(idx) > 0.5
        output1 = [output1 output_m4(idx)];
        x1      = [x1 idx];
    else
        output0 = [output0 output_m4(idx)];
        x0      = [x0 idx];
    end
end
            
x = 1:5000;
subplot(2,1,1)
hold on
plot(x,error_m4(:,1),'b')%plot(x,error([4500:5000],1)) only plots the last 501 data points of the 1st column
title('Error^2')
subplot(2,1,2)
hold on
plot(x0,output0,'b-');
plot(x1,output1,'b-');
title('The output seperated at 0.5 plotted together')
% title('Output for inputs that should return 0.1')
% subplot(2,2,3)
% plot(x1,output1);
% title('Output for inputs that should return 0.9')
% subplot(2,2,4)
% plot(x,error)
% title('Error^2')