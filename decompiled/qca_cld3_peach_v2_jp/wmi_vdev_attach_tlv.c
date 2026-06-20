__int64 __fastcall wmi_vdev_attach_tlv(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  _QWORD *v11; // x8

  if ( !result )
    return qdf_trace_msg(
             0x31u,
             2u,
             "%s: null wmi handle",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "wmi_vdev_attach_tlv",
             v9,
             v10);
  v11 = *(_QWORD **)(result + 728);
  v11[333] = extract_vdev_delete_resp_tlv;
  v11[342] = extract_vdev_stopped_param_tlv;
  v11[332] = extract_vdev_start_resp_tlv;
  v11[438] = extract_vdev_peer_delete_all_response_event_tlv;
  v11[336] = extract_tbttoffset_num_vdevs_tlv;
  v11[334] = extract_tbttoffset_update_params_tlv;
  v11[335] = extract_ext_tbttoffset_update_params_tlv;
  v11[337] = extract_ext_tbttoffset_num_vdevs_tlv;
  v11[338] = extract_muedca_params_tlv;
  v11[265] = send_vdev_set_neighbour_rx_cmd_tlv;
  v11[58] = send_beacon_send_cmd_tlv;
  v11[267] = send_vdev_config_ratemask_cmd_tlv;
  v11[582] = send_peer_filter_set_tx_cmd_tlv;
  v11[249] = send_peer_vlan_config_cmd_tlv;
  if ( v11 )
    v11[553] = vdev_param_sr_prohibit_send_tlv;
  return result;
}
