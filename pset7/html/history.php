<?php
    require("../includes/config.php");
    $rows = query("SELECT transaction,date,symbol,shares,price FROM history WHERE id = ?",$_SESSION["id"]);
    render("history.php",["title"=>"history","rows"=>$rows]);
?>
