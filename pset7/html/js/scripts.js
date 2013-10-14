/***********************************************************************
 * scripts.js
 *
 * Computer Science 50
 * Problem Set 7
 *
 * Global JavaScript, if any.
 **********************************************************************/
  function blink()
          {
              var div = document.getElementById('greeting');
              if (div.style.visibility == "hidden")
              {
                  div.style.visibility = "visible";
              }
              else
              {
                  div.style.visibility = "hidden";
              }
          }

          // blink every 500ms
          window.setInterval(blink, 500);
