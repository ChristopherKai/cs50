<?php
     require("../includes/config.php"); 

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $rows = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        if (crypt($_POST["original"], $rows[0]["hash"]) == $rows[0]["hash"])
        {
            if ($_POST["new"] == $_POST["confirmation"])
            {
                $new = crypt($_POST["new"]);
                query("UPDATE users SET hash = ? WHERE id = ?",$new,$_SESSION["id"]);
                redirect("login.php");
            }
            else
                apologize("Passwords don't match!");
        }
        else
            apologize("You typed wrong password!");
    }
    else
        render("changepassword.php",["title"=>"Change Password"]);
    
?>
