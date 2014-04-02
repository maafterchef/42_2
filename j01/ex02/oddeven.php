#!/usr/bin/php
<?php

$check = 1;

while ($check)
{
	$line = FALSE;
	echo ("Entrez un nombre: ");
	if ($check = fscanf(STDIN, "%s", $line))
	{	if (is_numeric($line))
		{
			$var = intval($line);
				echo ("Le chiffre ".$var." est ");
				if ($var%2 == 1)
		   		echo ("Impair\n");
					else
					echo ("Pair\n");
		}
		else
			echo "'".$line."' n'est pas un chiffre\n";
	}
}
echo "\n";
?>