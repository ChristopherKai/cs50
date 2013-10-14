  $(document).ready(function() {

      $('#form-quote input[name=stock]').typeahead({
            source:SYMBOL,
      });
      
      // load data via ajax when form is submitted
      $('#form-quote').on('submit', function() {

          // determine symbol
          var symbol = $('#form-quote input[name=stock]').val();

          // send request to quote.php
          $.ajax({
              url: 'quote.php',
              type: 'POST',
              data: {
                  stock: symbol
              },
              success: function(response) {
                  $('#price').text(response);
              }
          });
          return false;

      });
  });
  
