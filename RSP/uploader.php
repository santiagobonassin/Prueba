<?php
$op = isset($_POST["op"]) ? $_POST["op"] : null;
switch ($op)
{
    case "subirFoto":
        $objRetorno = new stdClass();
        $objRetorno->Ok = false;

        $destino = "../fotos/" . $_FILES["foto"]['name'];
        
        if(move_uploaded_file($_FILES["foto"]["tmp_name"], $destino))
        {
            $objRetorno->Ok = true;
            $objRetorno->Path = $destino;
        }
        echo json_encode($objRetorno);
        break;

    default:
        echo ":(";
        break;
}
?>