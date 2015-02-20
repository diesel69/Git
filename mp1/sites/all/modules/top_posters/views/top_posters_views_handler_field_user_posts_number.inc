<?php

class top_posters_views_handler_field_user_posts_number extends views_handler_field {

  function query() {
    $this->ensure_my_table();

    $join = new views_join();
    $join->construct('node', 'users', 'uid', 'uid');
 	  $this->query->add_table('node', NULL, $join, 'node');

	  $this->field_alias = $this->query->add_field('', 'node.nid', 'user_posts_number', array('count' => TRUE));

    // Something terrible with Views groupby - it causes to this code
    // to get rid of all list of fields in GROUP BY sql
    // Addintional info - http://drupal.org/node/385158, but code above is better
    // TODO: check for documantion.
	  $this->query->add_groupby('users.uid');
    foreach($this->query->fields as $key => $field) {
      $this->query->fields[$key]['aggregate'] = 1;
    }

    // TODO: This code have to be expanded by sort handle
    $this->query->add_orderby('', '', 'DESC', 'user_posts_number');

    // TODO: This code have to be expanded by filter handle
    $this->query->add_having(0, 'user_posts_number > 0');
  }

  function render($values) {
    $value = $values->{$this->field_alias};
    return check_plain($value);
  }
}