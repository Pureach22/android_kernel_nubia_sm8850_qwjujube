__int64 __fastcall wlan_twt_psoc_set_pmo_enable(__int64 a1, int a2)
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

  comp_private_obj = wlan_twt_psoc_get_comp_private_obj();
  if ( comp_private_obj )
  {
    *(_DWORD *)(comp_private_obj + 80) &= ~a2;
    qdf_trace_msg(
      0x96u,
      8u,
      "%s: Psoc twt_disabled %x",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_twt_psoc_set_pmo_enable");
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: twt_psoc_obj is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_twt_psoc_set_pmo_enable");
    return 4;
  }
}
