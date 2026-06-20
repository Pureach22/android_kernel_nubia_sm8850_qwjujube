__int64 __fastcall tgt_mgmt_rx_srng_send_reap_threshold(__int64 a1, unsigned int a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x35u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0xA5u,
      2u,
      "%s: psoc priv is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "tgt_mgmt_rx_srng_send_reap_threshold");
    return 16;
  }
  v13 = *(_DWORD **)(comp_private_obj + 16);
  if ( !v13 )
    return 16;
  if ( *(v13 - 1) != 787953853 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v13)(a1, a2);
}
