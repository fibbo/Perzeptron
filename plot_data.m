A = importdata('example29bmomterm1_error.txt');
B = importdata('example29bmomterm1_output.txt');
error = A.data;
output = B.data(:,1);
expoutput = B.data(:,2);

output0 = double.empty;
x0 = int32.empty;
output1 = double.empty;
x1 = int32.empty;
for idx = 1:numel(output)
    if expoutput(idx) > 0.5
        output1 = [output1 output(idx)];
        x1      = [x1 idx];
    else
        output0 = [output0 output(idx)];
        x0      = [x0 idx];
    end
end
            
x = 1:5000;
mmax = 1000;
subplot(2,1,1)
hold on
plot(x,error(:,1),'r')%plot(x,error([4500:5000],1)) only plots the last 501 data points of the 1st column
xlim([0 mmax])
title('Error^2')
subplot(2,1,2)
hold on
plot(x0,output0,'r');
xlim([0 mmax])
plot(x1,output1,'r-');
xlim([0 mmax])
title('The output seperated at 0.5 plotted together')

A = importdata('example29bmomterm2_error.txt');
B = importdata('example29bmomterm2_output.txt');
error = A.data;
output = B.data(:,1);
expoutput = B.data(:,2);

output0 = double.empty;
x0 = int32.empty;
output1 = double.empty;
x1 = int32.empty;
for idx = 1:numel(output)
    if expoutput(idx) > 0.5
        output1 = [output1 output(idx)];
        x1      = [x1 idx];
    else
        output0 = [output0 output(idx)];
        x0      = [x0 idx];
    end
end
            
x = 1:5000;
mmax = 1000;
subplot(2,1,1)
hold on
plot(x,error(:,1),'b')%plot(x,error([4500:5000],1)) only plots the last 501 data points of the 1st column
xlim([0 mmax])
title('Error^2')
subplot(2,1,2)
hold on
plot(x0,output0,'b');
xlim([0 mmax])
plot(x1,output1,'b');
xlim([0 mmax])
title('The output seperated at 0.5 plotted together')

A = importdata('example29bmomterm3_error.txt');
B = importdata('example29bmomterm3_output.txt');
error = A.data;
output = B.data(:,1);
expoutput = B.data(:,2);

output0 = double.empty;
x0 = int32.empty;
output1 = double.empty;
x1 = int32.empty;
for idx = 1:numel(output)
    if expoutput(idx) > 0.5
        output1 = [output1 output(idx)];
        x1      = [x1 idx];
    else
        output0 = [output0 output(idx)];
        x0      = [x0 idx];
    end
end
            
x = 1:5000;
mmax = 1000;
subplot(2,1,1)
hold on
plot(x,error(:,1),'g')%plot(x,error([4500:5000],1)) only plots the last 501 data points of the 1st column
xlim([0 mmax])
title('Error^2')
subplot(2,1,2)
hold on
plot(x0,output0,'g');
xlim([0 mmax])
plot(x1,output1,'g-');
xlim([0 mmax])
title('The output seperated at 0.5 plotted together')