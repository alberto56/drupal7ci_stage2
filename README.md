Dummy Drupal 7 site for demonstration purposes
==============================================

This is a Drupal 7 site meant for demonstration purposes. It contains an image gallery. It is a fully functional Drupal 7 site which can be deployed (installed) using few commands [without cloning the database](http://dcycleproject.org/blog/48/do-not-clone-database).

Prerequisites
-------------

 * [Drush (Drupal shell)](https://github.com/drush-ops/drush)

Initial installation
--------------------

    git clone https://github.com/alberto56/drupal7ci_stage2.git
    cd https://github.com/alberto56/drupal7ci_stage2.git
    echo 'create database ci_stage2'|mysql -uroot -proot
    drush si --db-url=mysql://root:root@localhost/ci_stage2 -y
    drush en demo_deploy -y
    drush en devel_generate -y
    drush generate-content 50

Upgrading
---------

All changes to the site should be done via a [site deployment module](http://dcycleproject.org/blog/44/what-site-deployment-module) and changes to each environment's database should be done through update hooks. If these procedures are followed, updating your installation can be done like this:

    drush vset maintenance_mode 1
    git pull origin master
    drush updb -y
    drush cc all
    drush vset maintenance_mode 0
