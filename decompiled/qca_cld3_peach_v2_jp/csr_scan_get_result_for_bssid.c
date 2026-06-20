__int64 __fastcall csr_scan_get_result_for_bssid(__int64 a1, const void *a2, _QWORD *a3)
{
  __int64 v6; // x0
  _WORD *v7; // x22
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _QWORD *scan_result; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  *a3 = 0;
  v6 = _qdf_mem_malloc(0x2D0u, "csr_scan_get_result_for_bssid", 964);
  if ( !v6 )
    return 2;
  v7 = (_WORD *)v6;
  *(_BYTE *)(v6 + 16) = 1;
  qdf_mem_copy((void *)(v6 + 70), a2, 6u);
  *v7 |= 8u;
  scan_result = scm_get_scan_result(*(_QWORD *)(a1 + 21560), (__int64)v7, v8, v9, v10, v11, v12, v13, v14, v15);
  _qdf_mem_free((__int64)v7);
  if ( scan_result )
  {
    if ( *((_DWORD *)scan_result + 4) )
    {
      *a3 = scan_result;
      return 0;
    }
    scm_purge_scan_results((__int64)scan_result, v17, v18, v19, v20, v21, v22, v23, v24);
  }
  return 16;
}
