<?php

function top_posters_views_data() {
  $data['users']['user_posts_number'] = array(
    'title' => t('Posts number'),
    'help' => t('Retrieve number of users posts.'),
    'field' => array(
      'handler' => 'top_posters_views_handler_field_user_posts_number',
    ),
    'filter' => array(
			'handler' => 'views_handler_filter_numeric',
    )
  );
  return $data;
}


function top_posters_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'top_posters') .'/views',
    ),
    'handlers' => array(
      'top_posters_views_handler_field_user_posts_number' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
* Implementation of hook_views_pre_render().
*/
function top_posters_views_pre_render(&$view) {

  if ($view->name == 'top_posters') {
    drupal_add_css(drupal_get_path('module', 'top_posters') . '/top_posters.css');
  }
}
