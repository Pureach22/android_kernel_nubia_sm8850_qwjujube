__int64 __fastcall mlo_get_chan_freq_by_bssid(__int64 a1, const void *a2)
{
  __int64 v4; // x0
  __int64 v5; // x21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _QWORD *scan_result; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  unsigned int v32; // w20
  _QWORD v34[2]; // [xsp+0h] [xbp-10h] BYREF

  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34[0] = 0;
  v4 = _qdf_mem_malloc(0x2D8u, "mlo_get_chan_freq_by_bssid", 2098);
  if ( v4 )
  {
    v5 = v4;
    *(_BYTE *)(v4 + 16) = 1;
    qdf_mem_copy((void *)(v4 + 70), a2, 6u);
    scan_result = scm_get_scan_result(a1, v5, v6, v7, v8, v9, v10, v11, v12, v13);
    _qdf_mem_free(v5);
    if ( scan_result )
    {
      if ( *((_DWORD *)scan_result + 4) )
      {
        qdf_list_peek_front(scan_result, v34);
        if ( v34[0] )
        {
          v31 = *(_QWORD *)(v34[0] + 24LL);
          if ( v31 )
          {
            v32 = *(char *)(v31 + 1192);
LABEL_11:
            scm_purge_scan_results((__int64)scan_result, v23, v24, v25, v26, v27, v28, v29, v30);
            goto LABEL_12;
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: scan list empty",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "mlo_get_chan_freq_by_bssid");
      }
      v32 = 0;
      goto LABEL_11;
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: scan list empty",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "mlo_get_chan_freq_by_bssid");
    v32 = 0;
  }
  else
  {
    v32 = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v32;
}
