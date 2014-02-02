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
    elseif expoutput(idx) == 0.6
        output0 = [output0 output(idx)];
        x0      = [x0 idx];
%     elseif expoutput(idx) == 0.4
%         output2 = [output2 output(idx)];
%         x2      = [x2 idx];
    else
        output3 = [output3 output(idx)];
        x3      = [x3 idx];
    end
end
            
x = 1:numel(error);
mmax = 10000;
subplot(2,1,1)
hold on
plot(x,error(:,1),'r')%plot(x,error([4500:5000],1)) only plots the last 501 data points of the 1st column
xlim([0 mmax])
title('Error^2')
subplot(2,1,2)
hold on
plot(x0,output0,'r');
xlim([0 mmax])
plot(x1,output1,'g-');
xlim([0 mmax])
%plot(x2,output2,'k-');
%xlim([0 mmax])
plot(x3,output3,'b-');
xlim([0 mmax])
title('The output')
