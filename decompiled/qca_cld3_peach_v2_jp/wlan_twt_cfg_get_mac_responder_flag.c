__int64 __fastcall wlan_twt_cfg_get_mac_responder_flag(__int64 a1, unsigned __int8 a2, _BYTE *a3)
{
  __int64 result; // x0
  __int64 comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  int v16; // w8

  if ( a2 > 2u )
    return 16;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( comp_private_obj )
  {
    v15 = comp_private_obj;
    result = 0;
    v16 = (*(unsigned __int8 *)(v15 + 88) >> a2) & 1;
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
      "wlan_twt_cfg_get_mac_responder_flag");
    LOBYTE(v16) = 0;
    result = 29;
  }
  *a3 = v16;
  return result;
}
