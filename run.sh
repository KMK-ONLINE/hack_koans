#! /usr/bin/env bash

hhvm -m d ./vendor/bin/phpunit about_asserts.hh
hhvm -m d ./vendor/bin/phpunit about_null.hh
hhvm -m d ./vendor/bin/phpunit about_arrays.hh


