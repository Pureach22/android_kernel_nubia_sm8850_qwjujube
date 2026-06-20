__int64 __fastcall hdd_stop_sap_due_to_invalid_channel(__int64 a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 4496);
  v21[0] = 0;
  result = _osif_vdev_sync_op_start(*(_QWORD *)(v2 + 32), v21, "hdd_stop_sap_due_to_invalid_channel");
  if ( !(_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: work started for sap session[%d]",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_stop_sap_due_to_invalid_channel",
      *(unsigned __int8 *)(a1 - 4488));
    v12 = *(_QWORD *)(a1 - 4224);
    wlan_hdd_stop_sap(a1 - 4496);
    wlansap_cleanup_cac_timer(v12);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: work finished for sap",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "hdd_stop_sap_due_to_invalid_channel");
    result = _osif_vdev_sync_op_stop(v21[0], "hdd_stop_sap_due_to_invalid_channel");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
