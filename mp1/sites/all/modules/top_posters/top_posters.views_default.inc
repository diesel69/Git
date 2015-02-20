<?php

function top_posters_views_default_views() {
  $view = new view;
  $view->name = 'top_posters';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->override_option('fields', array(
    'name' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
     'link_to_user' => 0,
     'overwrite_anonymous' => 1,
     'anonymous_text' => 'Guest',
     'exclude' => 0,
     'id' => 'name',
     'table' => 'users',
     'field' => 'name',
     'relationship' => 'none',
    ),
    'user_posts_number' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 1,
        'text' => '([user_posts_number])',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'exclude' => 0,
      'id' => 'user_posts_number',
      'table' => 'users',
      'field' => 'user_posts_number',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Default');
  $handler->override_option('items_per_page', 10);
  $handler->override_option('style_plugin', 'list');
  $handler->override_option('style_options', array(
    'type' => 'ul',
  ));
  $handler = $view->new_display('block', 'Top Posters', 'block_1');
  $handler->override_option('title', 'Top Posters');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  return array('top_posters' => $view);
}
