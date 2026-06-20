__int64 __fastcall wlan_twt_cfg_set_mac_responder_flag(__int64 a1, unsigned __int8 a2, char a3)
{
  __int64 comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  if ( a2 > 2u )
    return 16;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( comp_private_obj )
  {
    *(_BYTE *)(comp_private_obj + 88) = *(_BYTE *)(comp_private_obj + 88) & ~(1 << a2) | ((a3 & 1) << a2);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: twt psoc priv obj is null",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_twt_cfg_set_mac_responder_flag");
    return 29;
  }
}
