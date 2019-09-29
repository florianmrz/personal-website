 <?php
  $fehler = "";
  $name = $_POST['name'];
  $mail = $_POST['mail'];
  $text = $_POST['text'];
  if (empty($name)) {
    $fehler .= "<li>der Absendername fehlt</li>" ;
  }
  if (empty($mail)) {
    $fehler .= "<li>die Mailadresse fehlt</li>" ;
  }
  if (empty($text)) {
    $fehler .= "<li>keine Nachricht eingetragen</li>" ;
  }
  if (empty($fehler)) {
    if (get_magic_quotes_gpc()) {
      $text = stripslashes($text);
    }
    $return = chr(13).chr(10);
    $an = "adresse@domain.de" ;
    $betreff = "Mein Kontaktformular" ;
    $von = "From: Kontaktformular <null@MeineHTML.de>" ;
    $datum = "Datum: ".date("j.n.Y").$return;
    $zeit = "Zeit:  ".date("H:i").$return;
    $abs = "Von:   ".$name." <".$mail.">".$return;
    $trennen = "-----------------------------------------------".$return;
    $nachricht = $datum.$zeit.$abs.$trennen.$text;
    mail($an,$betreff,$nachricht,$von);
  }
  ?>
  <html>
  <head>
    <title>Kontakt-Formular</title>
  </head>
  <body>
  <?php
  if (empty($fehler)) {
    $return = chr(13).chr(10);
    $nachricht = strip_tags($nachricht);
    $nachricht = htmlentities($nachricht);
    $nachricht = str_replace($return,"<br>",$nachricht);
    echo "<p>Ihre Nachricht wurde versendet.</p>" ;
    echo "<p>$nachricht</p>" ;
  } else {
    echo "<p>Ihre Nachricht wurde nicht gesendet, weil</p>" ;
    echo "<ul>$fehler</ul>" ;
  }
  ?>
  </body>
  </html>