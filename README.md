# Project2_NaySanHtut

## Files
- `main.cpp`: Student, Art_Student and Physics_Student classes and the main program
- `student_info.dat`: output file with all 10 students (5 art, 5 physics)

## How to Compile
```bash
g++ -std=c++11 -Wall -o students main.cpp
```

## How to Run
```bash
./students
```
This creates `student_info.dat` in the same folder and prints `Wrote 10 student records to student_info.dat`.

## How to Check the Output
```bash
vim student_info.dat
```
Quit vim with `:q`.

The file should list the 5 art students first, then the 5 physics students. Each record shows the program, name, GPA, level, enrollment and graduation terms, and the art emphasis or physics concentration.

To count the records:
```bash
grep -c "Name:" student_info.dat
```
It should print `10`.

## Troubleshooting
- `No such file or directory` when compiling: you are in the wrong folder. Use `cd` to move into the project folder.
- `g++: command not found`: the compiler is not installed on that machine.
- `Error: could not open student_info.dat for writing`: you don't have write permission in the current folder.
- A student shows `Unknown Unknown`, `GPA: 0` or year `0`: the setter calls for that student are missing in `main()`.
- vim says `Swap file ".student_info.dat.swp" already exists`: quit vim, run `rm .student_info.dat.swp`, and open the file again.
