<?php

    require("../includes/config.php"); 
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["stock"]);
        if ($stock === false)
            exit;
        else
            echo "a share of ".$stock["name"]."costs".$stock["price"];
        
    }
    else
        render("quote_form.php");    
?>
