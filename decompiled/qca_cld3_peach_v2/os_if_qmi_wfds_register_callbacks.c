_QWORD *__fastcall os_if_qmi_wfds_register_callbacks(_QWORD *result)
{
  *result = os_if_qmi_wfds_init;
  result[1] = os_if_qmi_wfds_deinit;
  result[2] = os_if_qmi_wfds_send_config_msg;
  result[3] = os_if_qmi_wfds_send_req_mem_msg;
  result[4] = os_if_qmi_wfds_ipcc_map_n_cfg_msg;
  result[5] = os_if_qmi_wfds_send_misc_req_msg;
  return result;
}
