__int64 __fastcall scm_scan_get_entry_by_bssid(__int64 result, unsigned __int8 *a2)
{
  __int64 v3; // x19
  __int64 v4; // x21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD *scan_result; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x4
  __int64 v31; // x5
  __int64 v32; // x6
  __int64 v33; // x7
  __int64 v34; // x20
  __int64 v35; // [xsp+0h] [xbp-10h] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  if ( result )
  {
    v3 = result;
    result = _qdf_mem_malloc(0x2D0u, "scm_scan_get_entry_by_bssid", 2454);
    if ( result )
    {
      v4 = result;
      *(_BYTE *)(result + 16) = 1;
      qdf_mem_copy((void *)(result + 70), a2, 6u);
      scan_result = scm_get_scan_result(v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
      _qdf_mem_free(v4);
      if ( scan_result && *((_DWORD *)scan_result + 4) )
      {
        qdf_list_peek_front(scan_result, &v35);
        if ( v35 )
        {
          result = *(_QWORD *)(v35 + 24);
          if ( result )
            result = util_scan_copy_cache_entry_0(result);
        }
        else
        {
          result = 0;
        }
LABEL_14:
        v34 = result;
        scm_purge_scan_results((__int64)scan_result, v22, v23, v24, v25, v26, v27, v28, v29);
        result = v34;
        goto LABEL_15;
      }
      if ( a2 )
      {
        v30 = *a2;
        v31 = a2[1];
        v32 = a2[2];
        v33 = a2[5];
      }
      else
      {
        v32 = 0;
        v30 = 0;
        v31 = 0;
        v33 = 0;
      }
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: Scan entry for bssid: %02x:%02x:%02x:**:**:%02x not found",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "scm_scan_get_entry_by_bssid",
        v30,
        v31,
        v32,
        v33,
        v35,
        v36);
      result = 0;
      if ( scan_result )
        goto LABEL_14;
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
