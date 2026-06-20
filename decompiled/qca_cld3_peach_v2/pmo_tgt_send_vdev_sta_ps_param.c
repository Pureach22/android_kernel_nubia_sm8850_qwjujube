__int64 __fastcall pmo_tgt_send_vdev_sta_ps_param(__int64 a1, unsigned int a2, unsigned int a3)
{
  _DWORD *v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  v6 = *(_DWORD **)(wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(a1 + 216) + 80LL), 4u) + 328);
  if ( v6 )
  {
    if ( *(v6 - 1) != -1990808338 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v6)(a1, a2, a3);
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: send_vdev_param_set_req is null",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "pmo_tgt_send_vdev_sta_ps_param");
    return 29;
  }
}
