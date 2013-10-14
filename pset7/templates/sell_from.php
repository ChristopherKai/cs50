<form action ="sell.php" method="post">
    <select>
        <?php
            foreach($rows as $symbol)
            echo '<option value = "'.$symbol["symbol"] .'">';        
        ?>
    </select>
    <input type="submit" value="Sell!">
</form>
