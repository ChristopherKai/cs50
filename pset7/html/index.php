<?php

    // configuration
    require("../includes/config.php"); 
    
    $rows = query("SELECT symbol, shares FROM stock WHERE id = ?",$_SESSION["id"]);
    $cash = query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"]);
    $positions = [];
    if ($rows == NULL)
        render("portfolio.php",["cash"=>$cash[0]["cash"],"title"=>"Portfolio","positions"=>$positions]);
    else
    {
        foreach ($rows as $row)
        {
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
                $positions[] = [
                                "name" => $stock["name"],
                                "price" => $stock["price"],
                                "shares" => $row["shares"],
                                "symbol" => $row["symbol"]
                                ];
            }
        }
        // render portfolio
        render("portfolio.php", ["positions" => $positions, "title" => "Portfolio","cash"=>$cash[0]["cash"]]);
     }

?>
