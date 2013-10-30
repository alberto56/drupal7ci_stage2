<?php
/**
 * @file
 * demo_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function demo_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'positionnement';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-slideshow-block' => array(
          'module' => 'views',
          'delta' => 'slideshow-block',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['positionnement'] = $context;

  return $export;
}
