__int64 __fastcall cm_get_rssi_snr_by_bssid(__int64 a1, const void *a2, _BYTE *a3, _BYTE *a4)
{
  __int64 v8; // x0
  _WORD *v9; // x23
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _QWORD *scan_result; // x21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  __int64 v36; // x9
  unsigned int v37; // w20
  _QWORD v39[2]; // [xsp+0h] [xbp-10h] BYREF

  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39[0] = 0;
  if ( a4 )
    *a4 = 0;
  if ( a3 )
    *a3 = 0;
  v8 = _qdf_mem_malloc(0x2D0u, "cm_get_rssi_snr_by_bssid", 270);
  if ( v8 )
  {
    v9 = (_WORD *)v8;
    *(_BYTE *)(v8 + 16) = 1;
    qdf_mem_copy((void *)(v8 + 70), a2, 6u);
    *v9 |= 8u;
    scan_result = scm_get_scan_result(a1, (__int64)v9, v10, v11, v12, v13, v14, v15, v16, v17);
    _qdf_mem_free((__int64)v9);
    if ( scan_result )
    {
      if ( *((_DWORD *)scan_result + 4) )
      {
        qdf_list_peek_front(scan_result, v39);
        v35 = v39[0];
        if ( v39[0] && (v36 = *(_QWORD *)(v39[0] + 24LL)) != 0 )
        {
          if ( a3 )
            *a3 = *(_BYTE *)(v36 + 60);
          v37 = 0;
          if ( a4 )
            *a4 = *(_BYTE *)(*(_QWORD *)(v35 + 24) + 61LL);
        }
        else
        {
          v37 = 0;
        }
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: scan list empty",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "cm_get_rssi_snr_by_bssid");
        v37 = 29;
      }
      scm_purge_scan_results((__int64)scan_result, v27, v28, v29, v30, v31, v32, v33, v34);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: scan list empty",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "cm_get_rssi_snr_by_bssid");
      v37 = 29;
    }
  }
  else
  {
    v37 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v37;
}
