-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Φιλοξενητής: 127.0.0.1
-- Χρόνος δημιουργίας: 07 Δεκ 2015 στις 12:42:54
-- Έκδοση διακομιστή: 5.6.21
-- Έκδοση PHP: 5.6.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Βάση δεδομένων: `secretary`
--

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `application`
--

CREATE TABLE IF NOT EXISTS `application` (
  `CodeId` smallint(4) NOT NULL,
  `StudentId` varchar(10) NOT NULL,
  `ApplictionId` smallint(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=greek;

--
-- Άδειασμα δεδομένων του πίνακα `application`
--

INSERT INTO `application` (`CodeId`, `StudentId`, `ApplictionId`) VALUES
(1, 'up1000', 5),
(2, 'up2015', 2),
(3, 'up4321', 2),
(4, 'up2340', 3),
(5, 'up1623', 4),
(6, 'up2245', 1),
(7, 'up2156', 4),
(8, 'up3210', 2),
(9, 'up3216', 7),
(10, 'up1225', 6),
(11, 'up1123', 5),
(12, 'up1180', 6),
(13, 'up1240', 6),
(14, 'up3223', 4),
(15, 'up1089', 2),
(16, 'up1057', 4),
(17, 'up1230', 4),
(18, 'up1235', 5),
(19, 'up2248', 2),
(20, 'up1057', 1),
(21, 'up1230', 3);

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `certificate`
--

CREATE TABLE IF NOT EXISTS `certificate` (
  `CertificateID` smallint(2) NOT NULL,
  `CertificateName` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=greek;

--
-- Άδειασμα δεδομένων του πίνακα `certificate`
--

INSERT INTO `certificate` (`CertificateID`, `CertificateName`) VALUES
(1, 'Στρατολογία'),
(2, 'ΤΣΜΕΔΕ'),
(3, 'Επικυρωμένη Φωτοτυπία '),
(4, 'Εφορία'),
(5, 'Φοιτητική Εστία'),
(6, 'Ξένες Αρχές'),
(7, 'Απλή Φωτοτυπία ');

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `students`
--

CREATE TABLE IF NOT EXISTS `students` (
  `StudentsId` varchar(10) NOT NULL,
  `LastName` varchar(100) NOT NULL,
  `FirstName` varchar(100) NOT NULL,
  `FirstYear` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=greek;

--
-- Άδειασμα δεδομένων του πίνακα `students`
--

INSERT INTO `students` (`StudentsId`, `LastName`, `FirstName`, `FirstYear`) VALUES
('up1000', 'ΝΙΚΟΛΟΠΟΥΛΟΣ', 'ΔΗΜΗΤΡΙΟΣ', 2002),
('up1125', 'ΕΥΘΥΜΙΟΥ', 'ΠΑΝΑΓΙΩΤΗΣ', 2000),
('up1225', 'ΚΑΝΕΛΛΟΠΟΥΛΟΣ', 'ΠΕΤΡΟΣ', 2001),
('up1623', 'ΠΑΥΛΟΠΟΥΛΟΣ', 'ΒΑΣΙΛΕΙΟΣ', 2014),
('up2015', 'ΣΓΟΥΡΙΔΗ', 'ΜΑΡΙΑ', 2012),
('up2256', 'ΡΟΥΒΑΛΗΣ', 'ΑΝΔΡΕΑΣ', 2011),
('up2340', 'ΠΑΠΑΚΩΣΤΑ', 'ΕΛΕΝΗ', 2014),
('up2341', 'ΛΑΜΠΡΙΔΗΣ', 'ΚΩΝΣΤΑΝΤΙΝΟΣ', 2013),
('up3210', 'ΒΓΕΝΟΠΟΥΛΟΣ', 'ΗΛΙΑΣ', 2012),
('up3216', 'ΘΩΜΟΠΟΥΛΟΣ', 'ΓΕΩΡΓΙΟΣ', 2004),
('up2156', 'ΣΩΤΗΡΙΟΥ', 'ΠΕΡΙΚΛΗΣ', 2010),
('up3223', 'ΜΗΤΡΟΠΟΥΛΟΣ', 'ΧΡΟΝΗΣ', 2008),
('up1057', 'ΡΟΔΟΠΟΥΛΟΣ', 'ΓΕΩΡΓΙΟΣ', 2011),
('up1230', 'ΣΤΑΥΡΟΠΟΥΛΟΣ', 'ΧΡΗΣΤΟΣ', 2009),
('up442', 'ΠΑΠΑΔΗΜΗΤΡΙΟΥ', 'ΜΥΡΤΩ', 2013),
('up4549', 'ΒΟΥΛΓΑΡΗ', 'ΕΛΕΝΗ', 2014);

--
-- Ευρετήρια για άχρηστους πίνακες
--

--
-- Ευρετήρια για πίνακα `application`
--
ALTER TABLE `application`
 ADD PRIMARY KEY (`CodeId`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
