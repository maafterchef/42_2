#!/usr/bin/php
<?php

    $con=mysqli_connect("127.0.0.1","root","Quilava156","ft_shop");
    if (mysqli_connect_errno())
    {
        echo "Failed to connect to MySQL: ".mysqli_connect_error();
    }

/*    $table = "CREATE TABLE items
    (
        PID INT NOT NULL AUTO_INCREMENT,
        PRIMARY KEY(PID),
        name VARCHAR(50),
        cat VARCHAR(50),
        description VARCHAR(100),
        price FLOAT
    )";
    if (mysqli_query($con, $table))
    {
            echo "Table items created successfully\n";
    }
    else
    {
        echo "Error creating table: " . mysqli_error($con)."\n";
    }
*/
    $usr = "CREATE TABLE usrs
    (
        PID INT NOT NULL AUTO_INCREMENT,
        PRIMARY KEY(PID),
        first_name VARCHAR(255),
        last_name VARCHAR(255),
        pass VARCHAR(255),
        mail VARCHAR(255)
    )";
    if (mysqli_query($con, $usr))
    {
            echo "Table usrs created successfully\n";
    }
    else
    {
        echo "Error creating table: " . mysqli_error($con)."\n";
    }
    mysqli_close($con);
?>