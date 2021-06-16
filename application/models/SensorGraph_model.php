<?php 

class SensorGraph_model extends CI_Model{

    public function getSensor() {
        $this->db->from('data_sensor');
        $this->db->limit(5);
        $this->db->order_by('id', 'DESC');
        return $this->db->get()->result_array();
    }

}