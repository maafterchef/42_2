<!DOCTYPE HTML> 
<html>
    <head>
            <title>42_shop - Inscription</title>
            <style>
                .error {color: #FF0000;}
            </style>
    </head>
    <body>
    <?php
        $con=mysqli_connect("127.0.0.1","root","Quilava156","ft_shop");
        if (mysqli_connect_errno())
        {
            echo "Failed to connect to MySQL: " . mysqli_connect_error();
        }
        mysql_query("SET NAMES 'utf8'");

        $first_name = $last_name = $mail = $pass = "";
        $f_check =  "";
        $l_check = $m_check = $p_check = $p_check2 = "";

        if ($_SERVER["REQUEST_METHOD"] == "POST")
        {
            if (empty($_POST["f_name"]))
                $f_check = "Votre prenom est requis";
            else
            {
                $first_name = valid($_POST["f_name"]);
                if (!preg_match("/^[a-zA-Z ]*$/", $first_name))
                    $f_check = "Prenom invalide";
            }
            if (empty($_POST["l_name"]))
                $l_check = "Votre nom est requis";
            else
            {
                $last_name = valid($_POST["l_name"]);
                if (!preg_match("/^[a-zA-Z ]*$/", $last_name))
                    $l_check = "Nom invalide";
            }
            if (empty($_POST["mail"]))
                $m_check = "Votre adresse e-mail est requise";
            else
            {
                $mail = valid($_POST["mail"]);
                if (!preg_match("/([\w\-]+\@[\w\-]+\.[\w\-]+)/",$mail))
                    $m_check = "Adresse e-mail invalide";
                else
                {
                    $res = mysqli_query($con, "SELECT * FROM usrs WHERE mail = '$mail'");
                    $data = mysqli_fetch_array($res, MYSQLI_NUM);
                    if ($data[0] > 1)
                        $m_check = "Adresse e-mail deja utilisee";
                }
            }
            if (empty($_POST["pass_1"]) || empty($_POST["pass_2"]))
                $p_check = "Le mot de passe est obligatoire";
            else
            {
                $p_check = hash("whirlpool", $_POST["pass_1"]);
                $p_check2 = hash("whirlpool", $_POST["pass_2"]);
                if ($p_check != $p_check2)
                    $p_check = "Les deux mots de passe sont differents";
                else
                {
                    $pass = $p_check;
                    $p_check = "";
                    $p_check2 = "";
                }
            }
            if ($f_check == "" && $l_check == "" && $m_check ==="" && $p_check == "" && $p_check2 == "")
            {
                $new = "INSERT INTO usrs (first_name, last_name, mail, pass)
                VALUES ('$first_name', '$last_name', '$mail', '$pass')";
                if (!mysqli_query($con, $new))
                {
                    die('Error: ' . mysqli_error($con));
                }
                echo "1 record added";
            }
        }

        function valid($data)
        {
            $data = trim($data);
            $data = stripslashes($data);
            $data = htmlspecialchars($data);
            return $data;
        }
    mysqli_close($con);
    ?>
    
            <h2>Inscrivez vous sur 42_shop</h2>
            <p><span class="error">Champ requis</span></p>
            <form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']);?>">
                Prenom: <input type="text" name="f_name" value="<?php echo $first_name;?>">
                <span class="error">* <?php echo $f_check;?></span>
                <br />
                Nom: <input type="text" name="l_name" value="<?php echo $last_name;?>">
                <span class="error">* <?php echo $l_check;?></span>
                <br />
                Mot de passe: <input type="text" name="pass_1">
                <span class="error">* <?php echo $p_check;?></span>
                <br />
                Repetez le mot de passe: <input type="text" name="pass_2">
                <span class="error">*</span>
                <br />
                Adresse e-mail: <input type="text" name="mail" value="<?php echo $mail;?>">
                <span class="error">* <?php echo $m_check;?></span>
                <br />
                <input type="submit" name="submit" value="Valider"> 
            </form>
            <br />
        </body>
    </html>