<?php
    require("../includes/config.php"); 
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $rows = query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"]);
        $stock = lookup($_POST["symbol"]);
        if($stock === false)
            apologize("Doesnt exist such a stock!");
        
        if ((preg_match("/^\d+$/", $_POST["shares"]) == true))
        {
            if ($rows[0]["cash"] < $stock["price"] * $_POST["shares"])  
                apologize("You don't have so much cash!"); 
            $rows[0]["cash"] -=  $stock["price"] * $_POST["shares"];
            $_POST["symbol"] = mb_strtoupper($_POST["symbol"]);
            query("UPDATE users SET cash = ?",$rows[0]["cash"]);
            if (query("INSERT INTO stock (id,symbol,shares) VALUES (?,?,?)",$_SESSION["id"],$_POST["symbol"],$_POST["shares"]) === false)
            {
                $shares = query("SELECT shares FROM stock WHERE id = ? AND symbol = ?",$_SESSION["id"],$stock["symbol"]);
                $shares[0]["shares"] += $_POST["shares"];
                query("UPDATE stock SET shares = ? WHERE id =? AND symbol = ?",$shares[0]["shares"],$_SESSION["id"],$stock["symbol"]);
            }    
            query("INSERT INTO history (transaction,date,id,symbol,shares,price) VALUES(?,CURRENT_TIMESTAMP,?,?,?,?)",
                                        "BUY",$_SESSION["id"],$stock["symbol"],$_POST["shares"],$_POST["shares"]*$stock["price"]);
            redirect("index.php");
        }
        else
            apologize("A non-negative number please!");
    }
    else
        render("buy_form.php",["title"=>"buy"]);  
    
    
?>
