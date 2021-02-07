INSERT INTO Grade VALUES('1','Intern','ITN','1','3');
INSERT INTO Grade VALUES('2','Admin Assistant','ADMIN','2','6');
INSERT INTO Grade VALUES('3','Admin Supervisor','ADMSUP','5','11');
INSERT INTO Grade VALUES('4','Admin Office Manager','ADMMGR','10','15');
INSERT INTO Grade VALUES('5','Receptionist','RECEP','3','8');
INSERT INTO Grade VALUES('6','Security','SEC','4','9');
INSERT INTO Grade VALUES('7','Security Team Leader','SECTL','6','10');
INSERT INTO Grade VALUES('8','Widget Maker','WIDGET','6','15');
INSERT INTO Grade VALUES('9','Senior Engineer','SNRENG','10','20');
INSERT INTO Grade VALUES('10','Production Manager','PRODMGR','11','21');
INSERT INTO Grade VALUES('11','Senior Manager','SNRMGR','15','30');
INSERT INTO Grade VALUES('12','Director','DIR','12','30');

INSERT INTO Employee VALUES('1','Dr','Daniel','Dare','dan@wwi.com','2005-05-13','2009-01-12','0','','12',NULL);
INSERT INTO Employee VALUES('2','Lady','Sarah','Important','sarah@wwi.com','2005-06-15',NULL,'1','','12',NULL);
INSERT INTO Employee VALUES('3','Ms','Alice','Alive','alice.alive@wwi.com','2010-06-15',NULL,'1','','10','2');
INSERT INTO Employee VALUES('4','Dr','Xander','Mander','x@wwi.com','2010-04-18',NULL,'1','555-1234','9','3');
INSERT INTO Employee VALUES('5','Professor','Jenny','Generator','jenny@wwi.com','2011-12-23',NULL,'1','','8','4');
INSERT INTO Employee VALUES('6','Ms','Gemma','Hardasnails','gemma@wwi.com','2011-08-13',NULL,'1','2222','7','2');
INSERT INTO Employee VALUES('7','HRH','Prince','Caspian','prince@wwi.com','2017-09-01',NULL,'1','000-111','4','5');
INSERT INTO Employee VALUES('8','Mr','Brian','Knuckles','knuckleduster@wwi.com','2008-07-01','2010-09-30','0','','6','6');
INSERT INTO Employee VALUES('9','Mr','Bob','Punch','bob@wwi.com','2008-07-01',NULL,'1','2222','6','6');
INSERT INTO Employee VALUES('10','Mrs','Natalie','Nononsense','natalie@wwi.com','2010-10-13',NULL,'1','2222','6','6');
INSERT INTO Employee VALUES('11','Mr','Euan','Young','euan@wwi.com','2017-11-01',NULL,'1','','1','7');

INSERT INTO FileItem VALUES('1','Royal crown','Vault C','7');
INSERT INTO FileItem VALUES('2','Letter of commendation','S:\HR\Employees\Commendation-787.docx','10');

INSERT INTO Skill VALUES('3','Cage Fighting');
INSERT INTO Skill VALUES('9','Copy writing');
INSERT INTO Skill VALUES('2','Database Design');
INSERT INTO Skill VALUES('10','Flemish Horse Riding');
INSERT INTO Skill VALUES('1','SQL');
INSERT INTO Skill VALUES('4','Unicycling');
INSERT INTO Skill VALUES('7','Video Editing');
INSERT INTO Skill VALUES('8','Video Filming');
INSERT INTO Skill VALUES('6','Widget Consultancy');
INSERT INTO Skill VALUES('5','Widget Design');

INSERT INTO EmployeeSkill VALUES('7','10','2016-05-18');
INSERT INTO EmployeeSkill VALUES('4','7','2017-08-23');
INSERT INTO EmployeeSkill VALUES('6','3','2018-01-11');
INSERT INTO EmployeeSkill VALUES('2','1','2007-11-14');
INSERT INTO EmployeeSkill VALUES('11','7','2018-02-11');
INSERT INTO EmployeeSkill VALUES('10','4','2017-12-01');
INSERT INTO EmployeeSkill VALUES('7','7','2018-01-12');
INSERT INTO EmployeeSkill VALUES('7','8','2018-01-12');

INSERT INTO Project VALUES('1','Mega Widgets','A massive widget project to build the biggest ever widget ever seen','1','0','2005-02-01','2007-03-11');
INSERT INTO Project VALUES('2','World Domination','The ongoing project to achieve utter and complete world domination','1','1','2010-01-01',NULL);
INSERT INTO Project VALUES('3','Widgets for All','Global widget project for customer','0','0','2012-11-14',NULL);
INSERT INTO Project VALUES('4','Blue Widget','Blue widget project','1','0','2013-01-18','2013-01-30');
INSERT INTO Project VALUES('5','Project Octopus','Project Octopus.','0','1','2009-04-07',NULL);
INSERT INTO Project VALUES('6','Green Widgets','Can we build green widgets?','1','0','2010-04-17',NULL);

INSERT INTO Assignment VALUES('5','7');
INSERT INTO Assignment VALUES('5','2');
INSERT INTO Assignment VALUES('2','8');
INSERT INTO Assignment VALUES('6','4');
INSERT INTO Assignment VALUES('5','10');
INSERT INTO Assignment VALUES('6','5');
INSERT INTO Assignment VALUES('6','2');
INSERT INTO Assignment VALUES('4','2');

INSERT INTO Expense VALUES('1','4','5','Lunch for plotting','138.6','1');
INSERT INTO Expense VALUES('2','7','2','Phone charger','17.99','1');
INSERT INTO Expense VALUES('3','4',NULL,'Wine to help me forget','38.2','1');
INSERT INTO Expense VALUES('4','11',NULL,'Tea for the office','3.99','0');
INSERT INTO Expense VALUES('5','11','5','Large Fake Octopus','99.99','1');
INSERT INTO Expense VALUES('6','9','5','Monorail Survey','1200','1');

INSERT INTO Payslip VALUES('1','4','8000','500','1600','400','6500','2018-02-01','2018-01-31','XFR-LLOYD-71429');
INSERT INTO Payslip VALUES('2','4','8000','500','1600','400','6500','2018-02-28','2018-02-28','XFR-LLOYD-89234');
INSERT INTO Payslip VALUES('3','2','6000','0','2500','500','3000','2017-04-30','2017-04-29','MORDOR-666');
INSERT INTO Payslip VALUES('4','4','4000','500','1000','300','3200','2017-09-30','2017-09-28','XFER-FISHFISHFISH');

INSERT INTO Contract VALUES('1','Intern Contract 2018','2018-01-01','2019-01-01',NULL,'11');
INSERT INTO Contract VALUES('2','Director Contract','2005-05-13','2019-05-13','2009-01-12','1');
INSERT INTO Contract VALUES('3','Director Contract','2017-01-01','2027-01-01',NULL,'2');

INSERT INTO Equipment VALUES('1','Phone','Samsung','S9','Samsung S9 Mobile Phone','Insert SIM and switch on','0');
INSERT INTO Equipment VALUES('2','Phone','Samsung','S9','Samsung S9 Mobile Phone','Insert SIM and switch on','0');
INSERT INTO Equipment VALUES('3','Hotspot','Huwai','Hotspot XL','Mobile 4G Hotspot','Charge with micro USB. Turn on and wait for green light to show solid (stop flashing).','0');
INSERT INTO Equipment VALUES('4','Tablet','Apple','iPad','Apple iPad Large','Large screen Apple iPad','1');
INSERT INTO Equipment VALUES('5','Extension Cable',NULL,NULL,'10m Orange 1 gang extension cable','Plug in, done','0');
INSERT INTO Equipment VALUES('6','Magic Box','Wizard','MagicBox 2','A magic box','Do not open the magic box','0');
INSERT INTO Equipment VALUES('7','Video Camera','Sony','DV-24-6ABX','Sony DV Video Camera','Insert digital 8 tape, charge and switch on.','0');
INSERT INTO Equipment VALUES('8','Camera','Pentax','PX-50','Pentax SLR camera capable of video','Use SD card, AA batteries in compartment','0');
INSERT INTO Equipment VALUES('9','Camera','Canon','5D-III','Canon 5D Mark 3 SLR and Video Camera','Full frame 5D camera - charge and use','1');
INSERT INTO Equipment VALUES('10','Camera','Canon','4Z','Canon 4Z stills and video camera','Turn on, point, shoot','0');

INSERT INTO EquipmentLoan VALUES('7','3','2017-03-11',NULL,'1','For use demoing to customers');
INSERT INTO EquipmentLoan VALUES('2','1','2018-01-13','2018-01-14','0','On call borrowed phone');
INSERT INTO EquipmentLoan VALUES('11','6','2018-02-01','2019-11-11','1','Lent the intern the magic box TO GUARD AND NOT OPEN');
INSERT INTO EquipmentLoan VALUES('11','4','2017-12-01','2017-12-05','0','Lend iPad - came back damaged');
INSERT INTO EquipmentLoan VALUES('11','10','2018-02-01','2019-02-01','1','Loan of video camera for promotional filming');

