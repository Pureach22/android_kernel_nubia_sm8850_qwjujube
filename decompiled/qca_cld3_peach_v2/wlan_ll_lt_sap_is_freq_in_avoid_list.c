__int64 __fastcall wlan_ll_lt_sap_is_freq_in_avoid_list(__int64 a1, unsigned int a2)
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
  __int64 v12; // x20
  char is_freq_in_avoid_list; // w0

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x34u);
  if ( comp_private_obj )
  {
    v12 = comp_private_obj;
    ll_lt_sap_flush_old_entries();
    is_freq_in_avoid_list = ll_lt_sap_is_freq_in_avoid_list(v12, a2);
  }
  else
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: psoc_ll_sap_obj is null",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_ll_lt_sap_is_freq_in_avoid_list");
    is_freq_in_avoid_list = 0;
  }
  return is_freq_in_avoid_list & 1;
}
