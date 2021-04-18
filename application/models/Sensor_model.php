<?php 

class Sensor_model extends CI_Model{

    public function sendData($data){
        $this->db->insert('data_sensor', $data);
        return $this->db->affected_rows();
    }

    public function getSensor(){
        $this->db->from('data_sensor');
        $this->db->limit(1);
        $this->db->order_by('id', 'DESC');
        return $this->db->get()->result_array();
    }
    
}