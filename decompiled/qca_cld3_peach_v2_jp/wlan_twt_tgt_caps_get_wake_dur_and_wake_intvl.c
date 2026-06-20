__int64 __fastcall wlan_twt_tgt_caps_get_wake_dur_and_wake_intvl(
        __int64 a1,
        _DWORD *a2,
        _DWORD *a3,
        _DWORD *a4,
        _DWORD *a5)
{
  __int64 comp_private_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned __int16 *v18; // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( comp_private_obj )
  {
    v18 = (unsigned __int16 *)comp_private_obj;
    *a2 = v18[16];
    *a3 = v18[17];
    *a4 = v18[18];
    *a5 = v18[19];
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: null twt psoc priv obj",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_twt_tgt_caps_get_wake_dur_and_wake_intvl");
    return 16;
  }
}
