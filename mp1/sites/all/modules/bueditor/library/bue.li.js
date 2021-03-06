// $Id: bue.li.js,v 1.3.2.2 2010/03/03 05:36:33 ufku Exp $

//Automatically insert a new list item when enter-key is pressed at the end of a list item.
//Requires: none
BUE.preprocess.li = function(E, $) {

  $(E.textArea).keyup(function(e) {
    if (!e.ctrlKey && !e.shiftKey && !e.originalEvent.altKey && e.keyCode == 13) {
      var prefix = E.getContent().substr(0, E.posSelection().start);
      /<\/li>\s*$/.test(prefix) && E.tagSelection('<li>', '</li>');
    }
  });
 
};