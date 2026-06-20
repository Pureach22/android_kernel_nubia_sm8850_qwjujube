__int64 __fastcall wlan_twt_tgt_caps_get_nudge_enabled(__int64 a1, _BYTE *a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( comp_private_obj )
  {
    v12 = comp_private_obj;
    *a2 = *(_BYTE *)(v12 + 25);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: null twt psoc priv obj",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_twt_tgt_caps_get_nudge_enabled");
    return 16;
  }
}
