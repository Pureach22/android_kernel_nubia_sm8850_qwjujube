__int64 __fastcall hdd_acs_response_timeout_handler(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x21
  unsigned int v19; // w22
  __int64 v20; // x19
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  __int64 v31; // x0
  const char *v32; // x2
  unsigned int v33; // w1
  unsigned __int64 v40; // x10

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_acs_response_timeout_handler");
  if ( !a1 )
  {
    v32 = "%s: invalid timer context";
    goto LABEL_13;
  }
  v18 = *((_QWORD *)a1 + 1);
  if ( !v18 || *(_DWORD *)v18 != 1885692259 )
  {
    v32 = "%s: invalid adapter or adapter has invalid magic";
LABEL_13:
    v33 = 2;
    return qdf_trace_msg(0x33u, v33, v32, v10, v11, v12, v13, v14, v15, v16, v17, "hdd_acs_response_timeout_handler");
  }
  v19 = *a1;
  v20 = *(_QWORD *)(v18 + 24);
  result = _wlan_hdd_validate_context(
             v20,
             (__int64)"hdd_acs_response_timeout_handler",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17);
  if ( !(_DWORD)result )
  {
    v30 = *(_QWORD *)(v18 + 52824);
    if ( (*(_QWORD *)(v30 + 4416) & 8) != 0 )
    {
      _X8 = (unsigned __int64 *)(v30 + 4416);
      __asm { PRFM            #0x11, [X8] }
      do
        v40 = __ldxr(_X8);
      while ( __stxr(v40 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: ACS timeout happened for %s reason %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_acs_response_timeout_handler",
        *(_QWORD *)(v18 + 32) + 296LL,
        v19);
      if ( v19 == 2 )
        return hdd_lte_coex_restart_sap(v18, v20);
      v31 = *(_QWORD *)(v30 + 272);
      if ( v19 == 1 )
      {
        wlan_sap_update_next_channel(v31, 0, 0);
        return sme_update_new_channel_event(*(_QWORD *)(v20 + 16), *(unsigned __int8 *)(v30 + 8));
      }
      if ( !v19 )
      {
        wlan_sap_set_vendor_acs(v31, 0);
        return wlan_hdd_cfg80211_start_acs(v30);
      }
      v32 = "%s: invalid reason for timer invoke";
      v33 = 4;
      return qdf_trace_msg(0x33u, v33, v32, v10, v11, v12, v13, v14, v15, v16, v17, "hdd_acs_response_timeout_handler");
    }
  }
  return result;
}
