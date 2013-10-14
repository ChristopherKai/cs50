<?php
    require("../includes/config.php");
    $rows = query("SELECT symbol, shares FROM stock WHERE id = ?",$_SESSION["id"]);
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        if (isset($_POST["symbol"]))
            $stock = lookup($_POST["symbol"]);
        else
            apologize("You must choose a symbol");
         $cash = query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"]);
         $cash[0]["cash"] += $rows[0]["shares"] * $stock["price"];
         query("DELETE FROM stock WHERE symbol = ? AND id = ?",$stock["symbol"],$_SESSION["id"]);
         query("UPDATE users SET cash = ? WHERE id = ?",$cash[0]["cash"],$_SESSION["id"]);
         query("INSERT INTO history (transaction,date,id,symbol,shares,price) VALUES(?,CURRENT_TIMESTAMP,?,?,?,?)",
                                        "SELL",$_SESSION["id"],$stock["symbol"],$rows[0]["shares"],$stock["price"]*$rows[0]["shares"]);
         redirect("index.php");
         
        
        
    }
    else
        render("sell_form.php",["title"=>"sell","rows"=>$rows]);  
    
?>
