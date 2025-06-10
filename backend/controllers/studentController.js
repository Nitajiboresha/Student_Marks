const studentModel = require('../models/studentModel');

exports.login = (req, res) => {
    const { username, password } = req.body;
    if (username === 'admin' && password === 'password') {
        res.json({ success: true, message: 'Login successful' });
    } else {
        res.status(401).json({ success: false, message: 'Invalid credentials' });
    }
};

exports.getMarks = (req, res) => {
    const studentId = req.params.studentId;
    const student = studentModel.getStudentById(studentId);
    if (student) {
        res.json(student);
    } else {
        res.status(404).json({ success: false, message: 'Student not found' });
    }
};