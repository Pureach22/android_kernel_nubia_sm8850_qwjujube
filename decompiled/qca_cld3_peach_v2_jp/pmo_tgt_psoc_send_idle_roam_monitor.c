__int64 __fastcall pmo_tgt_psoc_send_idle_roam_monitor(__int64 a1, unsigned int a2)
{
  _DWORD *v4; // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  v4 = *(_DWORD **)(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 456);
  if ( v4 )
  {
    if ( *(v4 - 1) != -132374536 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, _QWORD))v4)(a1, a2);
  }
  else
  {
    qdf_trace_msg(0x4Du, 2u, "%s: NULL fp", v5, v6, v7, v8, v9, v10, v11, v12, "pmo_tgt_psoc_send_idle_roam_monitor");
    return 29;
  }
}
