#!/usr/bin/php
<?
    if ($argc > 1)
    {
        echo preg_replace('/[\s\t]+/', ' ', $argv[1])."\n";   
    }
?>