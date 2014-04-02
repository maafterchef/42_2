#!/usr/bin/php
<?php

if ($argc >1)
{
    $str = preg_replace('/\s+\z/', '', $argv[1]);
    $str = preg_replace('/\A\s+/', '', $str);
    $str = preg_replace('/\s+/', ' ', $str);
	$tab = explode(' ', $str);
    $i = 0;
    foreach ($tab as $val)
    {
        if ($i != 0)
            echo $val." ";
        $i++;
    }
    echo $tab[0]."\n";
}    
?>