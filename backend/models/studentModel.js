const students = [
    { id: '1', name: 'John Doe', marks: [85.5, 90.0, 78.2, 88.8, 92.1] },
    { id: '2', name: 'Jane Smith', marks: [75.0, 80.0, 85.0, 90.0, 95.0] }
];

exports.getStudentById = (id) => {
    return students.find(student => student.id === id);
};