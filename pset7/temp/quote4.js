$(document).ready(function() {

    // create autocomplete
    $('#form-quote input[name=symbol]').typeahead({

        // load autocomplete data from suggest.php
        source: function(query, callback) {
            $.ajax({
                url: 'suggest.php',
                type: 'POST',
                dataType: 'json',
                data: {
                    symbol: query
                },
                success: function(response) {
                    callback(response.symbols);
                }
            });
        }
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
