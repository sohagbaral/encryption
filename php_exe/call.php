<?php

header('Location: http://localhost/aera/results1.html');
$phase1="sohag";
$cha1="1";

$phrase1=$_POST['phrase'];
$cha1=$_POST['cha'];
if($cha1<"1")
{$cha1="1";
 $phrase1="rsxlmrkcmwctviwirxclivi";}
if($cha>"2")
{$cha1="2";
 $phrase1="jkpdejc[eo[lnaoajp[dana";}

$code= shell_exec("jaras.exe $cha1 $phrase1");

?>