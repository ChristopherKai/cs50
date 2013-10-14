$(document).ready(function() {

    // key pressed in search field, so filter table
    $('#search').on('keyup', function() {

        // determine symbol we're searching for
        var query = $(this).val();

        // iterate over each row in the table
        $('#table-portfolio tbody tr').each(function(e) {

            // check if the symbol cell contains the query
            if (!query || $(this).children().first().text().toLowerCase().indexOf(query) > -1)
                $(this).show();

            // no match, so hide row
            else
                $(this).hide();
        });
    });

    // load table into ticker
    $('#table-portfolio tbody tr').each(function(e) {

        // get the cells in the row
        var children = $(this).children();

        // add all rows to ticker except the last, which is cash
        if (children.length > 2)
            $('#ticker').append('<span>' + children.eq(0).text() + ' ' + children.eq(3).text() + '</span> ');
    });

    // animate the ticker
    function animateTicker() {

        // move ticker text all the way off to the right
        $('#ticker').css({ marginLeft: '100%' });

        // animate ticker text all the way off to the left, and restart animation when done
        $('#ticker').animate({ marginLeft: '-100%' }, 10000, 'linear', animateTicker);
    }

    // start animation loop
    animateTicker();
});
