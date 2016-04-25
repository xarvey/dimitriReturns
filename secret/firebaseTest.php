<?php
require_once 'firebaseLib.php';
// --- This is your Firebase URL
$url = 'https://epicsuprc.firebaseio.com/';
// --- Use your token from Firebase here
$token = 'LKWz7g6fTWHrl4FG405vjofLkx3eIVsHDTyV1u34';
// --- Here is your parameter from the http GET
$arduino_data = $_GET['arduino_data'];
$arduino_data_post = $_POST['name'];
// --- Set up your Firebase url structure here
$firebasePath = '/';
/// --- Making calls
$fb = new fireBase($url, $token);
$dateTime = new DateTime();
$dataTimeTimeStamp = $dateTime->getTimestamp();
$test = array(
    "time" => $dataTimeTimeStamp,
    "data" => $arduino_data
);

$response = $fb->push($firebasePath. '/' , $test);


?>

<html> Test Page </html>
