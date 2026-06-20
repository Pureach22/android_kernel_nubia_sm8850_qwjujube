__int64 __fastcall cm_find_roam_candidate(__int64 a1, unsigned int *a2, __int64 a3)
{
  int v3; // w8
  int *v4; // x22
  int v5; // w9
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x23
  __int16 v19; // w9
  int v20; // w10
  _QWORD *scan_result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w22
  __int64 v31; // x21
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x20
  size_t v41; // x0
  void *v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 result; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  _QWORD v60[3]; // [xsp+8h] [xbp-18h] BYREF

  v60[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (int *)(a3 + 1);
  v3 = *(_DWORD *)(a3 + 1);
  v5 = *(unsigned __int16 *)(a3 + 5);
  v60[0] = 0;
  if ( !(v3 | v5) || !*(_DWORD *)(a3 + 8) )
  {
    result = 16;
    goto LABEL_10;
  }
  v9 = _qdf_mem_malloc(0x2D8u, "cm_find_roam_candidate", 7258);
  if ( !v9 )
  {
    result = 2;
    goto LABEL_10;
  }
  v18 = v9;
  *(_BYTE *)(v9 + 16) = 1;
  v19 = *((_WORD *)v4 + 2);
  v20 = *v4;
  *(_WORD *)(v9 + 18) = 1;
  *(_WORD *)(v9 + 74) = v19;
  *(_DWORD *)(v9 + 70) = v20;
  *(_DWORD *)(v9 + 268) = *(_DWORD *)(a3 + 8);
  scan_result = scm_get_scan_result(a1, v9, v10, v11, v12, v13, v14, v15, v16, v17);
  if ( !scan_result )
  {
    _qdf_mem_free(v18);
    v30 = 0;
LABEL_14:
    qdf_trace_msg(
      0x68u,
      4u,
      "%s: vdev %d cm_id 0x%x: no valid candidate found, num_bss %d",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "cm_find_roam_candidate",
      *((unsigned __int8 *)a2 + 9),
      *a2,
      v30);
    result = 13;
    goto LABEL_10;
  }
  v30 = *((_DWORD *)scan_result + 4);
  v31 = (__int64)scan_result;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: num_entries found %d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "cm_find_roam_candidate",
    *((unsigned __int8 *)a2 + 9),
    *a2,
    v30);
  _qdf_mem_free(v18);
  if ( !*(_DWORD *)(v31 + 16) )
  {
    scm_purge_scan_results(v31, v32, v33, v34, v35, v36, v37, v38, v39);
    goto LABEL_14;
  }
  qdf_list_peek_front((_QWORD *)v31, v60);
  v40 = v60[0];
  v41 = *(unsigned int *)(*(_QWORD *)(v60[0] + 24LL) + 1888LL);
  *(_DWORD *)(a3 + 12) = v41;
  if ( (_DWORD)v41 )
  {
    v42 = (void *)_qdf_mem_malloc(v41, "cm_find_roam_candidate", 7299);
    *(_QWORD *)(a3 + 16) = v42;
    if ( v42 )
    {
      qdf_mem_copy(v42, *(const void **)(*(_QWORD *)(v40 + 24) + 1896LL), *(unsigned int *)(a3 + 12));
      scm_purge_scan_results(v31, v43, v44, v45, v46, v47, v48, v49, v50);
      result = 0;
    }
    else
    {
      *(_DWORD *)(a3 + 12) = 0;
      result = 2;
    }
  }
  else
  {
    result = 4;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
