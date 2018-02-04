<?php
// do the command: php -q clever.php "how are you?"
function get_string_between($string, $start, $end){
    $string = ' ' . $string;
    $ini = strpos($string, $start);
    if ($ini == 0) return '';
    $ini += strlen($start);
    $len = strpos($string, $end, $ini) - $ini;
    return substr($string, $ini, $len);
}

$url = "https://www.cleverbot.com/getreply";
$key = ""; //your cleverbot API key
$input = rawurlencode ($argv[1]);
$a =  "<script>ProcessReply (" . file_get_contents ("$url?input=$input&key=$key") . ")</script>";

echo get_string_between($a,"\"output\":\"","\",\"conversation");

?>
