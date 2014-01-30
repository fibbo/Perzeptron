clear;
run('import_error.m');
run('import_output.m');
output0 = double.empty;
x0 = int32.empty;
output1 = double.empty;
x1 = int32.empty;
for idx = 1:numel(output)
    if output(idx) > 0.5
        output1 = [output1 output(idx)];
        x1      = [x1 idx];
    else
        output0 = [output0 output(idx)];
        x0      = [x0 idx];
    end
end
            
x = 1:5000;
subplot(2,1,1)
hold all
plot(x,error(:,1),'b')%plot(x,error([4500:5000],1)) only plots the last 501 data points of the 1st column
title('Error^2')
subplot(2,1,2)
hold all
plot(x0,output0,'b-');
plot(x1,output1,'r-');
title('The output seperated at 0.5 plotted together')
hold all
run('import_error_momterm.m');
run('import_output_momterm.m');
output0 = double.empty;
x0 = int32.empty;
output1 = double.empty;
x1 = int32.empty;
for idx = 1:numel(output)
    if output(idx) > 0.5
        output1 = [output1 output(idx)];
        x1      = [x1 idx];
    else
        output0 = [output0 output(idx)];
        x0      = [x0 idx];
    end
end
            
x = 1:5000;
hold all
subplot(2,1,1)
plot(x,error(:,1),'r')%plot(x,error([4500:5000],1)) only plots the last 501 data points of the 1st column
title('Error^2')
subplot(2,1,2)
plot(x0,output0,'g-');
plot(x1,output1,'k-');
title('The output seperated at 0.5 plotted together')
% title('Output for inputs that should return 0.1')
% subplot(2,2,3)
% plot(x1,output1);
% title('Output for inputs that should return 0.9')
% subplot(2,2,4)
% plot(x,error)
% title('Error^2')