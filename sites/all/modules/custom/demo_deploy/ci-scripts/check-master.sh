# see https://github.com/drush-ops/drush/issues/212 for the use of grep -v 
# this won't work unless you set your base_url in sites/default/settings.php

drush vset maintenance_mode 1
drush updb -y
drush cc all
drush cron
drush vset maintenance_mode 0

MYTESTGROUP=demo
RESULT=$(drush test-run $MYTESTGROUP 2>&1)
echo $RESULT
echo $RESULT | grep -v '\[error\]'
