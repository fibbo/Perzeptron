A = importdata('set1_error.txt');
B = importdata('set1_output.txt');
error = A.data;
output = B.data(:,1);
expoutput = B.data(:,2);

output0 = double.empty;
x0 = int32.empty;
output1 = double.empty;
x1 = int32.empty;
output2 = double.empty;
x2 = int32.empty;
output3 = double.empty;
x3 = int32.empty;

for idx = 1:numel(output)
    if expoutput(idx) == 0.9
        output1 = [output1 output(idx)];
        x1      = [x1 idx];
    elseif expoutput(idx) == 0.1
        output0 = [output0 output(idx)];
        x0      = [x0 idx];
    end
end
            
x = 1:5000;
mmax = 5000;
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


A = importdata('set2_error.txt');
B = importdata('set2_output.txt');
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


A = importdata('set3_error.txt');
B = importdata('set3_output.txt');
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
subplot(2,1,1)
hold on
plot(x,error(:,1),'g')%plot(x,error([4500:5000],1)) only plots the last 501 data points of the 1st column
xlim([0 mmax])
title('Error^2')
hleg1 = legend('m = 0.','m = 0.2', 'm = 0.4','Location','NorthEast');
subplot(2,1,2)
hold on
plot(x0,output0,'g');
xlim([0 mmax])
plot(x1,output1,'g-');
xlim([0 mmax])
title('The calculated output')