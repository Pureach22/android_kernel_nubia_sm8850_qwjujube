__int64 __fastcall wlan_twt_check_all_twt_support(__int64 a1, int a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v14; // [xsp+8h] [xbp-8h]

  if ( a2 != 255 )
    return 0;
  v14 = v3;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( comp_private_obj )
  {
    if ( *(_BYTE *)(comp_private_obj + 26) )
      return 0;
    else
      return 11;
  }
  else
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: null twt psoc priv obj",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_twt_tgt_caps_get_all_twt_enabled",
      v2,
      v14);
    return 4;
  }
}
