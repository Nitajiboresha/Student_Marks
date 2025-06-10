# 🚀 Quick Start Guide - Student Marks System

## 🎯 Overview
This guide will get you up and running with the Student Marks Management System in under 5 minutes!

## 📋 Prerequisites
- **C Compiler** (GCC recommended)
- **Node.js** v14+ and npm
- **Terminal/Command Line** access
- **Web Browser** (Chrome, Firefox, Safari, Edge)

## ⚡ Quick Setup

### 1. Navigate to Project Directory
```bash
cd /Users/douglasochiengjr/Desktop/Student_Marks
```

### 2. C Implementation - Quick Test
```bash
# Build the C program
make clean && make

# Run with sample data (automatic input)
echo "2\nJohn Doe\n85\n90\n78\n88\n92\nJane Smith\n75\n80\n85\n90\n95" | ./marks_program

# View the generated report
open student_marks/index.html  # macOS
# or double-click student_marks/index.html in file explorer
```

### 3. Web Application - Quick Start
```bash
# Install dependencies and start server
make web-setup
make web-start
```

The server will start on `http://localhost:3000`

## 🔑 Demo Credentials

### Admin Access
- **Username:** `admin`
- **Password:** `admin123`
- **Features:** View all students, add new students

### Student Access
| Username | Password | Student |
|----------|----------|----------|
| john.doe | johndoe | John Doe |
| jane.smith | janesmith | Jane Smith |
| alice.johnson | alicejohnson | Alice Johnson |
| bob.wilson | bobwilson | Bob Wilson |

## 🎮 Try It Out

### C Program Demo
1. Run `make run`
2. Enter `2` for number of students
3. Enter student data:
   - Name: `Test Student`
   - Math: `95`
   - English: `87`
   - Kiswahili: `92`
   - Science: `89`
   - Computer Studies: `94`
4. View `student_marks/index.html` for beautiful report

### Web App Demo
1. Open `http://localhost:3000`
2. Login as admin (`admin` / `admin123`)
3. View all student data with grades and statistics
4. Try logging in as a student to see individual view

## 📊 What You'll See

### C Program Output
- Beautiful HTML report with:
  - Professional styling
  - Color-coded pass/fail status
  - Letter grades (A, B, C, D, F)
  - Responsive design
  - Generation timestamp

### Web Application
- Modern login interface
- Dashboard with student data
- Real-time statistics
- Mobile-responsive design
- Role-based access control

## 🛠️ Available Commands

```bash
# C Implementation
make              # Build program
make run          # Build and run
make debug        # Build with debug symbols
make clean        # Clean build files

# Web Implementation  
make web-setup    # Install Node.js dependencies
make web-start    # Start production server
make web-dev      # Start development server

# Help
make help         # Show all available commands
```

## 🔧 Troubleshooting

### C Compilation Issues
```bash
# Ensure GCC is installed
gcc --version

# If compilation fails, try:
make clean
make debug
```

### Web Server Issues
```bash
# Check if Node.js is installed
node --version
npm --version

# Reinstall dependencies if needed
cd backend
npm install

# Check if port 3000 is available
lsof -i :3000
```

### Common Solutions
- **Port 3000 in use**: Kill existing process or change port in `backend/server.js`
- **Permission errors**: Ensure you have write permissions in the project directory
- **Module not found**: Run `make web-setup` to install dependencies

## 📱 Access Points

- **Web App**: `http://localhost:3000`
- **Health Check**: `http://localhost:3000/health`
- **C Report**: `student_marks/index.html` (after running C program)

## 🎉 Next Steps

1. **Explore the Code**: Check out the improved architecture
2. **Customize**: Modify subjects, grade scales, or styling
3. **Extend**: Add new features using the modular design
4. **Deploy**: Consider containerization for production use

## 💡 Tips

- Use `make web-dev` for development with auto-reload
- Check `IMPROVEMENTS.md` for detailed enhancement information
- The C program creates a `student_marks` directory automatically
- Web app data is stored in memory (resets on server restart)

---

**🚀 Happy coding! Your enhanced Student Marks System is ready to use!**

