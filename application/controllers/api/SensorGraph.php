<?php
use Restserver\Libraries\REST_Controller;
defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use __autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */
//To Solve File REST_Controller not found
require APPPATH . 'libraries/REST_Controller.php';
require APPPATH . 'libraries/Format.php';

/**
 * This is an example of a few basic user interaction methods you could use
 * all done with a hardcoded array
 *
 * @package         CodeIgniter
 * @subpackage      Rest Server
 * @category        Controller
 * @author          Phil Sturgeon, Chris Kacerguis
 * @license         MIT
 * @link            https://github.com/chriskacerguis/codeigniter-restserver
 */

 class SensorGraph extends REST_Controller{
     
    public function __construct()
     {
        parent::__construct();
        $this->load->model('SensorGraph_model', 'sensorgraph');
     }

     public function index_get(){
        $data = $this->sensorgraph->getSensor();
        
        if ($data) {
            $this->response($data, REST_Controller::HTTP_OK);
        } else{
            $this->response([
                'status' => false,
                'message' => 'Not Found Data'
            ], REST_Controller::HTTP_NOT_FOUND);
        }
     }


 }