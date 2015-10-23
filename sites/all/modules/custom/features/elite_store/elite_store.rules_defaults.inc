<?php
/**
 * @file
 * elite_store.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function elite_store_default_rules_configuration() {
  $items = array();
  $items['rules_store_assign_manager_role'] = entity_import('rules_config', '{ "rules_store_assign_manager_role" : {
      "LABEL" : "Upgrade Store Manager",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "manager", "store" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--store" : { "bundle" : "store" } },
      "DO" : [
        { "user_add_role" : {
            "account" : [ "node:field-store-manager" ],
            "roles" : { "value" : { "4" : "4" } }
          }
        }
      ]
    }
  }');
  $items['rules_store_email_manager_id'] = entity_import('rules_config', '{ "rules_store_email_manager_id" : {
      "LABEL" : "Email Store ID to manager",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "store", "validation" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--store" : { "bundle" : "store" } },
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "Your store\\u0027s unique ID",
            "message" : "Your store\\u0027s unique ID is: [node:field-store-id]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_store_role_manager'] = entity_import('rules_config', '{ "rules_store_role_manager" : {
      "LABEL" : "Upgrade Store Manager",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "manager", "store" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_update" : [] },
      "DO" : []
    }
  }');
  return $items;
}
