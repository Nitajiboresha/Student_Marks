const express = require('express');
const bodyParser = require('body-parser');
const path = require('path');

const app = express();
const PORT = 3000;

// Middleware
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

// Test route
app.get('/health', (req, res) => {
    res.json({ status: 'OK', message: 'Server is working!' });
});

// Import and use routes
try {
    const studentRoutes = require('./routes/studentRoutes');
    app.use('/api', studentRoutes);
    console.log('Student routes loaded successfully');
} catch (error) {
    console.error('Error loading student routes:', error.message);
}

// Static files
app.use(express.static(path.join(__dirname, '../frontend')));

// Default route
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, '../frontend/login.html'));
});

// Start server
app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
    console.log(`Health check: http://localhost:${PORT}/health`);
    console.log(`Frontend: http://localhost:${PORT}/`);
});
