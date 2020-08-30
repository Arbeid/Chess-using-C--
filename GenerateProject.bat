call rmdir bin/s bin-int/s

call del Project.sln

call Vendor\bin\Premake\premake5.exe vs2019

PAUSE