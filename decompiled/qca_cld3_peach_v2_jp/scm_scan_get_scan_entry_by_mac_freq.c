__int64 __fastcall scm_scan_get_scan_entry_by_mac_freq(__int64 a1, unsigned __int8 *a2, unsigned __int16 a3)
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
  int v15; // w22
  __int64 v16; // x21
  int v17; // w9
  _QWORD *scan_result; // x19
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
  __int64 v35; // x0
  __int64 v36; // x20
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x6
  __int64 v40; // x7
  _QWORD v42[2]; // [xsp+10h] [xbp-10h] BYREF

  v42[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42[0] = 0;
  v6 = _qdf_mem_malloc(0x2D0u, "scm_scan_get_scan_entry_by_mac_freq", 2248);
  if ( v6 )
  {
    v15 = a3;
    v16 = v6;
    *(_BYTE *)(v6 + 16) = 1;
    *(_DWORD *)(v6 + 268) = v15;
    *(_WORD *)(v6 + 18) = 1;
    v17 = *(_DWORD *)a2;
    *(_WORD *)(v6 + 74) = *((_WORD *)a2 + 2);
    *(_DWORD *)(v6 + 70) = v17;
    scan_result = scm_get_scan_result(a1, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    _qdf_mem_free(v16);
    if ( scan_result && *((_DWORD *)scan_result + 4) )
    {
      qdf_list_peek_front(scan_result, v42);
      if ( v42[0] && (v35 = *(_QWORD *)(v42[0] + 24LL)) != 0 )
        v36 = util_scan_copy_cache_entry_0(v35);
      else
        v36 = 0;
LABEL_13:
      scm_purge_scan_results((__int64)scan_result, v27, v28, v29, v30, v31, v32, v33, v34);
      goto LABEL_14;
    }
    if ( a2 )
    {
      v37 = *a2;
      v38 = a2[1];
      v39 = a2[2];
      v40 = a2[5];
    }
    else
    {
      v39 = 0;
      v37 = 0;
      v38 = 0;
      v40 = 0;
    }
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: Scan entry for bssid:%02x:%02x:%02x:**:**:%02xand freq %d not found",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "scm_scan_get_scan_entry_by_mac_freq",
      v37,
      v38,
      v39,
      v40,
      v15);
    v36 = 0;
    if ( scan_result )
      goto LABEL_13;
  }
  else
  {
    v36 = 0;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v36;
}
