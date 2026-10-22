#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Enums
enum Semester { SPRING, SUMMER, FALL };
enum Level { UNDERGRAD, GRAD };
enum ArtEmphasis { ART_STUDIO, ART_HISTORY, ART_EDUCATION }; // I used camel case for this despite the instructions showing snake case
enum PhysicsConcentration { BIOPHYSICS, EARTH_AND_PLANETARY_SCIENCES };

inline std::string toString(Semester s) {
    switch (s) {
        case SPRING: return "Spring";
        case SUMMER: return "Summer";
        default:     return "Fall";
    }
}

inline std::string toString(Level l) {
    return (l == UNDERGRAD) ? "Undergraduate" : "Graduate"; // learned this trick on youtube
}

inline std::string toString(ArtEmphasis e) {
    switch (e) {
        case ART_STUDIO:  return "Art Studio";
        case ART_HISTORY: return "Art History";
        default:          return "Art Education";
    }
}

inline std::string toString(PhysicsConcentration c) {
    return (c == BIOPHYSICS) ? "Biophysics" : "Earth and Planetary Sciences";
}

// Base class
class Student {
    public:
        Student() {
            first_name = "Unknown";
            last_name = "Unknown";
            gpa = 0.0;
            grad_year = 0;
            grad_semester = SPRING;
            enrolled_year = 0;
            enrolled_semester = FALL;
            level = UNDERGRAD;
        }
        
        virtual ~Student() {} // good habit for base-class destructors

        // Setters
        void setName(const std::string &first, const std::string &last) { first_name = first; last_name = last; }
        void setGPA(double g) { gpa = g; }
        void setGPA(const std::string &g) { gpa = std::stod(g); } // this allows setGPA("3.9")
        void setGradYear(int y) { grad_year = y; }
        void setGradSemester(Semester s){ enrolled_semester = s; }
        void setEnrolledYear(int y) { enrolled_year = y; }
        void setEnrolledSemester(Semester s) { enrolled_semester = s; }
        void setLevel(Level l) { level = l; }

        // Getters
        std::string getFirstName() const { return first_name; }
        std::string getLastName() const { return last_name; }
        double getGPA() const { return gpa; }
        int getGradYear() const { return grad_year; }
        Semester getGradSemester() const { return grad_semester; }
        int getEnrolledYear() const { return enrolled_year; }
        Semester getEnrolledSemester() const { return enrolled_semester; }
        Level getLevel() const { return level; }

        void write(std::ostream &out) const {
            out << "Name: " << first_name << " " << last_name << "\n"
                << "GPA: " << gpa << "\n"
                << "Level: " << toString(level) << "\n"
                << "Enrolled: " << toString(enrolled_semester) << " " << enrolled_year << "\n"
                << "Graduation: " << toString(grad_semester) << " " << grad_year << "\n";
        }
    private:
        std::string first_name;
        std::string last_name;
        double gpa;
        int grad_year;
        Semester grad_semester;
        int enrolled_year;
        Semester enrolled_semester;
        Level level;
};

// Derived class: Art_Student
class Art_Student : public Student { // Inherits from Student
    public:
        Art_Student() {
            art_emphasis = ART_STUDIO;
        }
        virtual ~Art_Student() {}

        void setArtEmphasis(ArtEmphasis e) { art_emphasis = e; }
        ArtEmphasis getArtEmphasis() const { return art_emphasis; }

        void write(std::ostream &out) const {
            out << "Program: Art\n";
            Student::write(out);
            out << "Art Emphasis: " << toString(art_emphasis) << "\n";
        }

    private:
        ArtEmphasis art_emphasis;
};

// Derived class: Physics_Student
class Physics_Student : public Student {
    public:
        Physics_Student() { 
            concentration = BIOPHYSICS;
        }
        virtual ~Physics_Student() {}

        void setConcentration(PhysicsConcentration c) { concentration = c; }
        PhysicsConcentration getConcentration() const { return concentration; }

        void write(std::ostream &out) const {
            out << "Program: Physics\n";
            Student::write(out);
            out << "Concentration: " << toString(concentration) << "\n";
        }

    private:
        PhysicsConcentration concentration;
};

// Main function
int main(void) {
    // Art Students
    std::vector<Art_Student *> art_students; // Shown in the project 2 instructions
    for (int i = 0; i < 5; i++) { // 5 because it says 5 objects
        art_students.push_back(new Art_Student);
    }

    art_students[0]->setName("Reiner", "Fritz"); // all this will be made up and varied results
    art_students[0]->setGPA("3.9");
    art_students[0]->setEnrolledYear(2022);
    art_students[0]->setEnrolledSemester(FALL);
    art_students[0]->setGradYear(2026);
    art_students[0]->setGradSemester(SPRING);
    art_students[0]->setLevel(UNDERGRAD);
    art_students[0]->setArtEmphasis(ART_STUDIO);

    art_students[1]->setName("Eren", "Yeager");
    art_students[1]->setGPA(3.5);
    art_students[1]->setEnrolledYear(2021);
    art_students[1]->setEnrolledSemester(SPRING);
    art_students[1]->setGradYear(2025);
    art_students[1]->setGradSemester(FALL);
    art_students[1]->setLevel(UNDERGRAD);
    art_students[1]->setArtEmphasis(ART_HISTORY);

    art_students[2]->setName("Kamaboko", "Gonpachiro");
    art_students[2]->setGPA(3.7);
    art_students[2]->setEnrolledYear(2025);
    art_students[2]->setEnrolledSemester(FALL);
    art_students[2]->setGradYear(2027);
    art_students[2]->setGradSemester(SPRING);
    art_students[2]->setLevel(GRAD);
    art_students[2]->setArtEmphasis(ART_EDUCATION);

    art_students[3]->setName("Akane", "Samira");
    art_students[3]->setGPA(3.1);
    art_students[3]->setEnrolledYear(2021);
    art_students[3]->setEnrolledSemester(FALL);
    art_students[3]->setGradYear(2025);
    art_students[3]->setGradSemester(SPRING);
    art_students[3]->setLevel(UNDERGRAD);
    art_students[3]->setArtEmphasis(ART_STUDIO);

    art_students[4]->setName("Raitetsu", "Rover");
    art_students[4]->setGPA(3.3);
    art_students[4]->setEnrolledYear(2024);
    art_students[4]->setEnrolledSemester(SPRING);
    art_students[4]->setGradYear(2026);
    art_students[4]->setGradSemester(FALL);
    art_students[4]->setLevel(GRAD);
    art_students[4]->setArtEmphasis(ART_HISTORY);


    // Physics Students
    std::vector<Physics_Student *> physics_students;
    for (int i = 0; i < 5; i++) {
        physics_students.push_back(new Physics_Student);
    }

    physics_students[0]->setName("Akari", "Hotaru");
    physics_students[0]->setGPA(3.7);
    physics_students[0]->setEnrolledYear(2022);
    physics_students[0]->setEnrolledSemester(FALL);
    physics_students[0]->setGradYear(2026);
    physics_students[0]->setGradSemester(SPRING);
    physics_students[0]->setLevel(UNDERGRAD);
    physics_students[0]->setConcentration(BIOPHYSICS);

    physics_students[1]->setName("Yume", "Hoshiyumi");
    physics_students[1]->setGPA(3.5);
    physics_students[1]->setEnrolledYear(2022);
    physics_students[1]->setEnrolledSemester(FALL);
    physics_students[1]->setGradYear(2024);
    physics_students[1]->setGradSemester(SPRING);
    physics_students[1]->setLevel(GRAD);
    physics_students[1]->setConcentration(EARTH_AND_PLANETARY_SCIENCES);

    physics_students[2]->setName("Aquamarine", "Hoshino");
    physics_students[2]->setGPA(3.0);
    physics_students[2]->setEnrolledYear(2023);
    physics_students[2]->setEnrolledSemester(SPRING);
    physics_students[2]->setGradYear(2027);
    physics_students[2]->setGradSemester(FALL);
    physics_students[2]->setLevel(UNDERGRAD);
    physics_students[2]->setConcentration(BIOPHYSICS);

    physics_students[3]->setName("Aoi", "Shiba");
    physics_students[3]->setGPA(3.6);
    physics_students[3]->setEnrolledYear(2022);
    physics_students[3]->setEnrolledSemester(FALL);
    physics_students[3]->setGradYear(2026);
    physics_students[3]->setGradSemester(SPRING);
    physics_students[3]->setLevel(UNDERGRAD);
    physics_students[3]->setConcentration(BIOPHYSICS);

    physics_students[4]->setName("Minami", "Hoshizora");
    physics_students[4]->setGPA(4.0);
    physics_students[4]->setEnrolledYear(2022);
    physics_students[4]->setEnrolledSemester(FALL);
    physics_students[4]->setGradYear(2026);
    physics_students[4]->setGradSemester(SPRING);
    physics_students[4]->setLevel(UNDERGRAD);
    physics_students[4]->setConcentration(BIOPHYSICS);

    // Single file
    std::ofstream outfile("student_info.dat"); // I found this to work instead of the one in the instructions
    if (!outfile.is_open()) {
        std::cerr << "Error: could not open student_info.dat for writing\n";
        return 1;
    }

    outfile << "===== ART STUDENTS =====\n\n";
    for (std::size_t i = 0; i < art_students.size(); i++) {
        art_students[i]->write(outfile);
        outfile << "\n";
    }

    outfile << "===== PHYSICS STUDENTS =====\n\n";
    for (std::size_t i = 0; i < physics_students.size(); i++) {
        physics_students[i]->write(outfile);
        outfile << "\n";
    }
    outfile.close();

    std::cout << "Wrote " << art_students.size() + physics_students.size() << " student records to student_info.dat\n";

    // Free all allocationted memory
    for (std::size_t i = 0; i < art_students.size(); i++) {
        delete art_students[i];
    }
    art_students.clear();

    for (std::size_t i = 0; i < physics_students.size(); i++) {
        delete physics_students[i];
    }
    physics_students.clear();

    return 0;
}
