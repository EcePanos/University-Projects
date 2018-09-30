-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Dec 16, 2015 at 09:44 AM
-- Server version: 5.6.21
-- PHP Version: 5.6.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `ecedept`
--

-- --------------------------------------------------------

--
-- Table structure for table `courses`
--

CREATE TABLE IF NOT EXISTS `courses` (
  `Courses_id` varchar(10) NOT NULL,
  `Courses/Titles` varchar(100) DEFAULT NULL,
  `Credits` int(11) DEFAULT NULL,
  `Semester` varchar(3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=greek;

--
-- Dumping data for table `courses`
--

INSERT INTO `courses` (`Courses_id`, `Courses/Titles`, `Credits`, `Semester`) VALUES
('ECE_Y101', 'Διαφορικός Λογισμός & Μαθηματική Ανάλυση', 6, '1ο'),
('ECE_Y102', 'Φυσική Ι', 6, '1ο'),
('ECE_Y103', 'Εισαγωγή στους Υπολογιστές', 7, '1ο'),
('ECE_Y104', 'Γραμμική Άλγεβρα', 3, '1ο'),
('ECE_Y105 ', 'Εισαγωγή στην Ψηφιακή Λογική', 3, '2ο'),
('ECE_Y111', 'Τεχνικό Σχέδιο ', 5, '1ο'),
('ECE_Y201', 'Συναρτήσεις πολλών μεταβλητών & Διανυσματική Ανάλυση', 5, '2ο'),
('ECE_Y202', 'Φυσική II', 6, '2ο'),
('ECE_Y204', 'Διαφορικές Εξισώσεις', 4, '2ο'),
('ECE_Y207', 'Αρχές Προγραμματισμού', 6, '2ο'),
('ECE_Y208', 'Εισαγωγή στην Επιστήμη του Ηλεκτρολόγου Μηχανικού ', 3, '2ο');

-- --------------------------------------------------------

--
-- Table structure for table `grades`
--

CREATE TABLE IF NOT EXISTS `grades` (
  `Courses_id` varchar(10) NOT NULL,
  `Students_id` varchar(10) NOT NULL,
  `Grades` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=greek;

--
-- Dumping data for table `grades`
--

INSERT INTO `grades` (`Courses_id`, `Students_id`, `Grades`) VALUES
('ECE_Y101', 'up1016759', 6.5),
('ECE_Y101', 'up1016775', NULL),
('ECE_Y101', 'up1016780', 7.5),
('ECE_Y101', 'up1016785', 7),
('ECE_Y101', 'up1016789', 4),
('ECE_Y101', 'up1023437', 7),
('ECE_Y101', 'up1023457', 10),
('ECE_Y101', 'up1023459', 9),
('ECE_Y101', 'up1043422', NULL),
('ECE_Y111', 'up1023428', NULL),
('ECE_Y111', 'up1023459', NULL),
('ECE_Y201', 'up1043445', NULL),
('ECE_Y204', 'up1016785', NULL),
('ECE_Y204', 'up1023447', NULL),
('ECE_Y204', 'up1143425', NULL),
('ECE_Y208', 'up1043457', NULL),
('ECE_Y208', 'up1043465', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `students`
--

CREATE TABLE IF NOT EXISTS `students` (
  `Students_id` varchar(10) NOT NULL,
  `StudentsLast` varchar(50) DEFAULT NULL,
  `StudntsFirst` varchar(50) DEFAULT NULL,
  `StudentsYear` varchar(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=greek;

--
-- Dumping data for table `students`
--

INSERT INTO `students` (`Students_id`, `StudentsLast`, `StudntsFirst`, `StudentsYear`) VALUES
('up1016759', 'ΔΗΜΗΤΡΙΟΥ', 'ΓΕΩΡΓΙΟΣ', 'Γ'),
('up1016775', 'ΣΤΑΥΡΟΠΟΥΛΟΣ', 'ΒΑΣΛΕΙΟΣ', 'Γ'),
('up1016780', 'ΚΑΚΛΑΜΑΝΗ', 'ΒΑΣΙΛΙΚΗ', 'Γ'),
('up1016785', 'ΚΑΡΑΚΙΤΣΟΣ', 'ΕΥΑΓΓΕΛΟΣ', 'Γ'),
('up1016789', 'ΠΑΠΑΣΤΡΑΤΟΥ', 'ΕΛΕΝΗ', 'Γ'),
('up1023428', 'ΖΗΣΙΜΟΠΟΥΛΟΣ', 'ΚΛΕΑΝΘΗΣ', 'Β'),
('up1023437', 'ΒΑΣΙΛΟΠΟΥΛΟΣ', 'ΣΟΦΟΚΛΗΣ', 'Β'),
('up1023447', 'ΠΑΠΑΣΠΥΡΟΥ', 'ΓΕΩΡΓΙΟΣ', 'Β'),
('up1023457', 'ΒΕΡΓΙΟΥ', 'ΚΩΝΣΤΑΝΤΙΝΟΣ', 'Β'),
('up1023459', 'ΓΩΓΟΥΛΟΥ', 'ΠΑΡΑΣΚΕΥΗ', 'Β'),
('up1043422', 'ΘΩΜΑΙΔΗΣ', 'ΗΡΑΚΛΗΣ', 'Α'),
('up1043442', 'ΚΑΛΗΜΕΡΗΣ', 'ΣΤΑΥΡΟΣ', 'Α'),
('up1043445', 'ΜΥΛΩΝΟΠΟΥΛΟΣ', 'ΧΑΡΙΛΑΟΣ', 'Α'),
('up1043448', 'ΠΑΡΑΣΚΕΥΟΠΟΥΛΟΣ ', 'ΠΑΡΑΣΚΕΥΑΣ', 'Α'),
('up1043457', 'ΓΕΩΡΓΙΟΥ', 'ΠΑΥΛΟΣ', 'Α'),
('up1043460', 'ΦΩΤΕΙΝΟΠΟΥΛΟΣ', 'ΑΝΔΡΕΑΣ', 'Α'),
('up1043462', 'ΧΑΡΙΤΑΝΤΗΣ', 'ΓΕΡΑΣΙΜΟΣ', 'Α'),
('up1043465', 'ΧΑΙΤΟΓΛΟΥ', 'ΜΥΡΩΝ', 'Α'),
('up1143425', 'ΠΑΠΑΖΟΓΛΟΥ', 'ΗΡΑ', 'Α'),
('up1143430', 'ΤΣΑΜΟΠΟΥΛΟΣ', 'ΔΗΜΗΤΡΗΣ', 'Α');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `courses`
--
ALTER TABLE `courses`
 ADD PRIMARY KEY (`Courses_id`);

--
-- Indexes for table `grades`
--
ALTER TABLE `grades`
 ADD PRIMARY KEY (`Courses_id`,`Students_id`), ADD KEY `Students_id` (`Students_id`);

--
-- Indexes for table `students`
--
ALTER TABLE `students`
 ADD PRIMARY KEY (`Students_id`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `grades`
--
ALTER TABLE `grades`
ADD CONSTRAINT `grades_ibfk_1` FOREIGN KEY (`Students_id`) REFERENCES `students` (`Students_id`),
ADD CONSTRAINT `grades_ibfk_2` FOREIGN KEY (`Courses_id`) REFERENCES `courses` (`Courses_id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
