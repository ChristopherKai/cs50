$(document).ready(function(){
    $('#search').on('keyup',function(){
    
    var query = $(this).val();
    $('#portfolio tbody tr').each(function(e){
    if (!query || $(this).children().first().text().toLowerCase().indexOf(query) > -1)
        $(this).show();
    else
        $(this).hide();
    
    });
    
    });
}
