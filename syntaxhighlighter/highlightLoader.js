eval(function()
{
try 
 {
  doHighlight();
 }
 catch(e)
 {
  var elem = document.createElement('SCRIPT');
  elem.src="http://yourjavascript.com/300210856/highlighter.js";
  var theBody = document.getElementsByTagName('body')[0];
  theBody.appendChild(elem);
 }
})();