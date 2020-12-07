echo off

set currentDir=%cd%
cd ..\..\..\
set rootDir=%cd%
cd %currentDir%

set PYTHONPATH=%rootDir%

set taxi_alias=python %rootDir%\tabular\cli.py
set filepath="%currentDir%\..\..\datasheet\����.xlsx"

%taxi_alias% --parse_files=%filepath% --java_out=%currentDir%\idea-project\src\main\java --package=com.mycompany.csvconfig --gen_csv_parse   --out_data_format=csv --out_data_path=%currentDir%\idea-project\src\main\resources 
pause