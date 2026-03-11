import psutil
print(psutil.virtual_memory())

%load_ext memory_profiler
%memit your_function()
