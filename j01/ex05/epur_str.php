#!/usr/bin/php
<?php

if ($argc == 2)
{
	$str = preg_replace('/\s+\z/', '', $argv[1]);
	$str = preg_replace('/\A\s+/', '', $str);
	echo preg_replace('/\s+/', ' ', $str)."\n";
}
?>