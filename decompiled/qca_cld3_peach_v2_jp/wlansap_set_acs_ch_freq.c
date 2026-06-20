__int64 __fastcall wlansap_set_acs_ch_freq(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const char *v14; // x2
  __int64 result; // x0
  unsigned int v16; // w21
  unsigned int cu_for_freq; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  if ( !a2 )
    return qdf_trace_msg(
             0x39u,
             2u,
             "%s: Invalid sap_debug",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlansap_set_acs_ch_freq");
  if ( *(_DWORD *)(a2 + 728) == 2 )
    v14 = "%s: Selecting DCS freq %d";
  else
    v14 = "%s: Selecting ACS freq %d";
  *(_DWORD *)(a2 + 8LL * (*(_DWORD *)(a2 + 728) == 2)) = a3;
  result = qdf_trace_msg(0x39u, 8u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "wlansap_set_acs_ch_freq", a3);
  if ( a3 )
  {
    result = policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a2 + 12));
    if ( (result & 1) != 0 )
    {
      v16 = *(unsigned __int8 *)(a2 + 12);
      cu_for_freq = wlan_ll_sap_get_cu_for_freq(*(_QWORD *)(a1 + 21560), a3);
      result = wlan_ll_sap_set_cur_freq_unused_cu(*(_QWORD *)(a1 + 21552), v16, cu_for_freq);
      if ( (_DWORD)result )
        return qdf_trace_msg(
                 0x39u,
                 8u,
                 "%s: failed to update freq %d cu",
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 "wlansap_update_current_freq_cu",
                 a3);
    }
  }
  return result;
}
