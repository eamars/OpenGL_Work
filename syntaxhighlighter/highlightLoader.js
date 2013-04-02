eval(function()
{
try 
 {
  doHighlight();
 }
 catch(e)
 {
  var elem = document.createElement('SCRIPT');
  elem.src="http://crux-framework-tools.googlecode.com/svn/trunk/misc/highlight/highlight.js";
  var theBody = document.getElementsByTagName('body')[0];
  theBody.appendChild(elem);
 }
})();