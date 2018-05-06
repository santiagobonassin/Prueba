<?php
include_once "Empleado.php";
require_once "interfaces.php";
class Fabrica implements IArchivo
{
    private $_cantidadMaxima;
    private $_empleados=array();
    private $_razonSocial;

    public function __construct($razonSocial)
    {
        $this->_razonSocial=$razonSocial;
        $this->_cantidadMaxima=7;
        $this->_empleados=array();
    }
    public function AgregarEmpleado($emp)
    {
        if(count($this->_empleados)<$this->_cantidadMaxima)
        {       
            array_push($this->_empleados,$emp);
            $this->EliminarEmpleadosRepetidos();
            return true;
        }
        else
        {
            return false;
        }
    }
    public function CalcularSueldos()
    {
        $sueldos=0;
        foreach($this->_empleados as $empleado)
        {
            $sueldos+=$empleado->GetSueldo();
        }
        return $sueldos;
    }
    public function EliminarEmpleado($emp)
    {
        for($i=0;$i<count($this->_empleados);$i++)
        {
            if($this->_empleados[$i]->GetLegajo()==$emp->GetLegajo())
            {
                unset($this->_empleados[$i]);
                return true;
            }
        }
        return false;
    }
    private function EliminarEmpleadosRepetidos()
    {
        if(count($this->_empleados)>1)
        {
            $this->_empleados = array_unique($this->_empleados);
        }       
    }
    public function ToString()
    {
        $cadena="";
        $cadena.=$this->_razonSocial."<br>";
        $cadena.="Empleados:"."<br>";
        foreach($this->_empleados as $empleado)
        {
            $cadena.=$empleado->ToString();
        }
        $cadena.="<br>";
        return $cadena;
    }
    public function GuardarEnArchivo($nombreArchivo)
    {
        $archivo=fopen($nombreArchivo,"w");

        foreach($this->_empleados as $empleado)
        {
            fwrite($archivo,$empleado->ToString()."\r\n");
        }
        fclose($archivo);
    }
    public function TraerDeArchivo($nombreArchivo)
    {
        $archivo=fopen($nombreArchivo,"r");
        $empleados="";
        while(!feof($archivo))
        {
            $empleados=fgets($archivo);
            $empleados=explode("-",$empleados);
            if(trim($empleados[0])!="")
            {
                $emp=new Empleado($empleados[0],$empleados[1],$empleados[2],$empleados[3],$empleados[4],$empleados[5],$empleados[6]);
                $emp->SetPathFoto($empleados[7]);
                $this->AgregarEmpleado($emp);
            }
        }
        fclose($archivo);
    }
    public function GetEmpleados()
    {
        return $this->_empleados;
    }
}
?>