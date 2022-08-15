<?php
$result = array("status" => "failure");
if(isset($_POST["code"]))
{
	$code = stripslashes(trim($_POST["code"]));

	if($handle1 = fopen("temp/code.c", "w"))
	{

		fwrite($handle1, $code);
		$exec_out = "temp/". time() .".o";
		$handle = popen('gcc temp/code.c -o '. $exec_out .' 2>&1', 'r');
		$output = array();
		while($line = fgets($handle))
		{
			$output[] = $line;
		}
		//print_r($output);
		fclose($handle1);

		if(count($output) == 0)
		{
			$result = array("status" => "success", "errors" => null, "output" => $exec_out);
		}
		else
		{
			array_shift($output);


			$err_lines = array();
			$i = 0;
			foreach($output as $line)
			{
				$line_arr = explode(":", $line, 4);
			


					if($err_lines[$i-1]["line_no"] == $line_arr[1])
					{
						if(trim($line_arr[2]) == "error")
							$err_lines[$i-1]["error"] .= " ". $line_arr[3];
						else
							$err_lines[$i-1]["warning"] .= " ". $line_arr[3];
					}
					else
					{
						$err_lines[$i]["line_no"] = $line_arr[1];
						if(trim($line_arr[2]) == "error")
							$err_lines[$i]["error"] = $line_arr[3];
						else
							$err_lines[$i]["warning"] = $line_arr[3];
						$i++;
	
					}


			}
			$result = array("status" => "success", "errors" => $err_lines, "output" => $exec_out);
		}
	}	
	else
	{
		$result = array("status" => "failure");
	}
}
echo json_encode($result);
?>
