__int64 __fastcall send_disconnect_roam_params_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x22
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "send_disconnect_roam_params_tlv", 0x188Cu);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 52232204;
  v13[1] = *(_DWORD *)a2;
  v13[2] = *(unsigned __int8 *)(a2 + 4);
  v13[3] = *(_DWORD *)(a2 + 8);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: RSO_CFG: vdev_id:%d enable:%d self_roaming_re_enable_time %d ",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_disconnect_roam_params_tlv");
  wmi_mtrace(0xB014u, v13[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x10u,
             0xB014u,
             "send_disconnect_roam_params_tlv",
             0x189Fu,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_ROAM_DEAUTH_CONFIG_CMDID",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "send_disconnect_roam_params_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
