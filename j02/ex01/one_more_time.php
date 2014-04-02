#!/usr/bin/php
<?php
    function ft_check_day($day)
    {
        $days = array("lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche");
        foreach ($days as $elem)
        {
            if (strcasecmp($elem, $day) == 0)
                return TRUE;
        }
        return FALSE;
    }

    function ft_check_month($month)
    {
        $months = array("janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre");
        $i = 1;
        foreach ($months as $elem)
        {
                if (strcasecmp($elem, $month) == 0)
                    return $i;
                $i++;
        }
        return 0;
    }

    function ft_check_date($array)
    {
        if (!isset($array[0]) || !isset($array[2]))
            return 0;
        if (ft_check_day($array[0]) === FALSE)
            return 0;
        return ft_check_month($array[2]);
    }

    date_default_timezone_set('Europe/Paris');
    if ($argc > 1)
    {
        $str = preg_replace('/:/', ' ', $argv[1]);
        $array = explode(' ', $str);
        $check = ft_check_date($array);
        if ($check == 0)
            echo "Wrong Format\n";
        else
            echo mktime($array[4], $array[5], $array[6], $check, $array[1], $array[3])."\n";
    }
?>