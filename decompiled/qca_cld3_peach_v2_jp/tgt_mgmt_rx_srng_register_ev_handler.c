__int64 __fastcall tgt_mgmt_rx_srng_register_ev_handler(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 (__fastcall *v11)(_QWORD); // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x35u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0xA5u,
      2u,
      "%s: psoc priv is NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "tgt_mgmt_rx_srng_register_ev_handler");
    return 16;
  }
  v11 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 24);
  if ( !v11 )
    return 16;
  if ( *((_DWORD *)v11 - 1) != -770124015 )
    __break(0x8228u);
  return v11(a1);
}
