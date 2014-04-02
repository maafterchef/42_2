#!/usr/bin/php
<?php

if ($argc > 1)
{
	$i = 1;
	while ($i < $argc)
	{
		$str = preg_replace('/\s+\z/', '', $argv[$i]);
		$str = preg_replace('/\A\s+/', '', $str);
		$str = preg_replace('/\s+/', ' ', $str);
		if ($i == 1)
		{
			$tab = explode(' ', $str);
		} else 
		{
		  $ptr = explode(' ', $str);
		  foreach ($ptr as $val) {
			array_push($tab, $val);
		  }
		}
		$i++;
	}
	asort($tab);
	foreach ($tab as $val) {
			echo $val."\n";
	}
}

?>