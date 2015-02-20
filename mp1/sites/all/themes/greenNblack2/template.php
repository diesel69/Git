<?php



/**
* IE detector
*/
function greenNblack_ie_detect()
{
    if (isset($_SERVER['HTTP_USER_AGENT']) && 
    (strpos($_SERVER['HTTP_USER_AGENT'], 'MSIE') !== false))
        return true;
    else
        return false;
}

/**
* Add pngFix script to fix .png transparensy bug in IE6
*/

if (greenNblack_ie_detect()){
drupal_add_js(drupal_get_path('theme', 'greenNblack') . '/js/jquery.pngFix.js', 'theme');
}

function greenNblack_footer($message){
$message.='<div id="author_link">Design by <a href="http://cmstuning.com/">CMStuning</a></div>';
return $message;
}



/**
* Altering search form
*/

function phptemplate_search_theme_form($form) {
$form['#prefix']='<div id="search" class="container-inline">';
$form['#suffix']='</div>';
unset ($form['submit']);
 
$form['search_theme_form']['#title'] = t('Search');
 
return drupal_render($form);
}
?>