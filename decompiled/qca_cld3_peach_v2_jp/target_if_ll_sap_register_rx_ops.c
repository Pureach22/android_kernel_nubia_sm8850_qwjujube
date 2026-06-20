_QWORD *__fastcall target_if_ll_sap_register_rx_ops(_QWORD *result)
{
  *result = wlan_ll_sap_fw_bearer_switch_req;
  result[1] = wlan_ll_sap_oob_connect_response;
  return result;
}
