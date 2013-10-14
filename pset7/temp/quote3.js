$(document).ready(function() {

    // create autocomplete from list of stock symbols
    $('#form-quote input[name=symbol]').typeahead({
        source: SYMBOLS
    });

    // load data via ajax when form is submitted
    $('#form-quote').on('submit', function() {

        // determine symbol
        var symbol = $('#form-quote input[name=symbol]').val();

        // send request to quote.php
        $.ajax({
            url: 'quote.php',
            type: 'POST',
            data: {
                symbol: symbol
            },
            success: function(response) {
                $('#price').text(response);
            }
        });

        // since we're overridding form submission, make sure it doesn't submit
        return false;
    });
});
