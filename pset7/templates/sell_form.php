<form action ="sell.php" method="post">
    <select name = "symbol">
        <?php
            foreach($rows as $symbol)
                echo '<option value = "'.$symbol["symbol"] .'">'.$symbol["symbol"]."</option>";        
        ?>
    </select>
    <br/>
    <input type="submit" value="Sell!" class="btn btn-primary">
</form>
