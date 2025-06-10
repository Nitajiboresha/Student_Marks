const express = require('express');
const router = express.Router();
const studentController = require('../controllers/studentController');

router.post('/login', studentController.login);
router.get('/marks/:studentId', studentController.getMarks);

module.exports = router;