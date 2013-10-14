-- MySQL dump 10.13  Distrib 5.5.28, for Linux (i686)
--
-- Host: localhost    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.28

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `transaction` varchar(255) NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `id` int(10) unsigned NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  `price` decimal(10,0) unsigned NOT NULL,
  PRIMARY KEY (`date`,`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES ('BUY','2013-01-24 12:03:53',23,'A',3,133),('BUY','2013-01-24 12:04:23',23,'A',1,44),('SELL','2013-01-24 12:10:18',23,'A',12,532),('SELL','2013-01-24 12:19:27',23,'DV',1,24),('BUY','2013-01-24 13:34:57',26,'D',10,534),('SELL','2013-01-24 13:35:29',26,'D',10,534);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stock`
--

DROP TABLE IF EXISTS `stock`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `stock` (
  `id` int(10) unsigned NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`,`symbol`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stock`
--

LOCK TABLES `stock` WRITE;
/*!40000 ALTER TABLE `stock` DISABLE KEYS */;
/*!40000 ALTER TABLE `stock` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=27 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'caesar','$1$50$GHABNWBNE/o4VL7QjmQ6x0',9466.4000),(2,'cs50','$1$50$ceNa7BV5AoVQqilACNLuC1',9466.4000),(3,'jharvard','$1$50$RX3wnAMNrGIbgzbRYrxM1/',9466.4000),(4,'malan','$1$HA$azTGIMVlmPi9W9Y12cYSj/',9466.4000),(5,'nate','$1$50$sUyTaTbiSKVPZCpjJckan0',9466.4000),(6,'rbowden','$1$50$lJS9HiGK6sphej8c4bnbX.',9466.4000),(7,'skroob','$1$Dd6Oks9X$8R7L9e.CYfR.JsST5ofx2/',9466.4000),(8,'tmacwilliam','$1$50$91ya4AroFPepdLpiX.bdP1',9466.4000),(9,'zamyla','$1$50$Suq.MOtQj51maavfKvFsW1',9466.4000),(23,'song','$1$fT.M3SkK$DdtOqQRPIWqyQ67bHN.Bs.',9466.4000),(24,'new','$1$r1yt3e8N$kavMansPwEMZ2M2n8Emag/',9466.4000),(25,'myname','$1$8x6vmZXD$GFXjrmLlZ04DCApXZ.ys01',9466.4000),(26,'yunqin','$1$8gRMZARu$iv7gy.CAytbo0s03k7Ft7/',10000.0000);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-01-24  8:42:36
