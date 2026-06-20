__int64 __fastcall wlan_get_rssi_by_bssid(__int64 a1, const void *a2, _DWORD *a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _WORD *v15; // x22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD *scan_result; // x20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  __int64 result; // x0
  _QWORD v43[2]; // [xsp+0h] [xbp-10h] BYREF

  v43[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43[0] = 0;
  v6 = _qdf_mem_malloc(0x2D0u, "wlan_get_rssi_by_bssid", 2871);
  if ( v6 )
  {
    v15 = (_WORD *)v6;
    *(_BYTE *)(v6 + 16) = 1;
    qdf_mem_copy((void *)(v6 + 70), a2, 6u);
    *v15 |= 8u;
    scan_result = scm_get_scan_result(a1, (__int64)v15, v16, v17, v18, v19, v20, v21, v22, v23);
    _qdf_mem_free((__int64)v15);
    if ( scan_result )
    {
      if ( *((_DWORD *)scan_result + 4) )
      {
        qdf_list_peek_front(scan_result, v43);
        if ( v43[0] )
        {
          v41 = *(_QWORD *)(v43[0] + 24LL);
          if ( v41 )
            *a3 = *(char *)(v41 + 60);
        }
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: scan list empty",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "wlan_get_rssi_by_bssid");
      }
      result = scm_purge_scan_results((__int64)scan_result, v33, v34, v35, v36, v37, v38, v39, v40);
    }
    else
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: scan list empty",
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 "wlan_get_rssi_by_bssid");
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Unable to allocate memory",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "wlan_get_rssi_by_bssid");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
