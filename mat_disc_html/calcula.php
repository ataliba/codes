<?php
  
  $number1 = $HTTP_POST_VARS["number1"];
  $number2 = $HTTP_POST_VARS["number2"];
  $status = $HTTP_POST_VARS["status"];
  
echo "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">"
    ."<html><head><title>Untitled Document</title>"
    ."<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\">"
    ."</head><body>";
   

 switch($status)
  {
    case "mmc":
	 {
	    $a = $aa = $number1;
		$b = $bb = $number2;
		
		while($bb != 0)
		 {
		   $resto = $aa % $bb;
		   $aa = $bb;
		   $bb = $resto;
		  }
	   
	    $resultado = (($a * $b) / $aa);   
          echo "<center>";		   
	  echo "<p>(========================================)<br>"
	      ."( Resultado dos Calculos do MMC dos Numeros Digitados )<br>"
          ."(========================================)</p>"
          ."<p>#&nbsp; MMC($number1,$number2) = $resultado</p>"
          ."<p>&nbsp;</p>"
          ."<br><br><a href=\"index.html\">Voltar</a><br><br>";
          echo "</center>";
      break;
	  }
	case "mdc":
	  {
	     $a = $number1;
		 $b = $number2;
		 
		 while($b != 0)
		  {
		    $resto = $a % $b;
			$a = $b;
			$b = $resto;
		   }
	     echo "<center>";	   	
	     echo "<p>(========================================)<br>"
             ."( Resultado dos Calculos do MDC dos Numeros Digitados )<br>"
             ."(========================================)</p>"
             ."<p># MDC($number1,$number2) = $a </p>"
             ."<p align=\"center\">&nbsp;</p>"
             ."<br><br><a href=\"index.html\">Voltar</a><br><br>";
	     echo "</center>";
             break;	  
	  }
	case "ambos":
	  {
	      $a = $aa = $number1;
		$b = $bb = $number2;
		
		while($bb != 0)
		 {
		   $resto = $aa % $bb;
		   $aa = $bb;
		   $bb = $resto;
		  }
	   
	    $resultado = (($a * $b) / $aa);   
          echo "<center>";		   
	  echo "<p>(========================================)<br>"
	      ."( Resultado dos Calculos do MMC dos Numeros Digitados )<br>"
          ."(========================================)</p>"
          ."<p>#&nbsp; MMC($number1,$number2) = $resultado</p>"
          ."<p>&nbsp;</p>";
          echo "</center>";
	  
	   $a = $number1;
		 $b = $number2;
		 
		 while($b != 0)
		  {
		    $resto = $a % $b;
			$a = $b;
			$b = $resto;
		   }
	     echo "<center>";	   	
	     echo "<p>(========================================)<br>"
             ."( Resultado dos Calculos do MDC dos Numeros Digitados )<br>"
             ."(========================================)</p>"
             ."<p># MDC($number1,$number2) = $a </p>"
             ."<p align=\"center\">&nbsp;</p>"
             ."<br><br><a href=\"index.html\">Voltar</a><br><br>";
	     echo "</center>";
             break;	  
	     
	  }
	}
  
 echo "<p align=\"center\">Programa feito por <a href=\"mailto:ataliba@ataliba.eti.br\">Ataliba Teixeira </a><br>Todos os direitos reservados</p>"
      ."<p>&nbsp;</p>"
      ."<p>&nbsp;</p><p>&nbsp; </p></body></html>";
	  
?>	  
