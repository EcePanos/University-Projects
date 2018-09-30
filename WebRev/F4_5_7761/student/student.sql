
CREATE TABLE IF NOT EXISTS `student` (
  `idstudent` VARCHAR(45) NOT NULL,
  `surname` VARCHAR(45) NULL,
  `name` VARCHAR(45) NULL,
  `semester` INT NULL,
  `sector` VARCHAR(45) NULL,
  `entryyear` INT NULL,
  PRIMARY KEY (`idstudent`))
ENGINE = InnoDB;

