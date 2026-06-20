__int64 __fastcall scm_scan_get_entry_by_mac_addr(__int64 a1, int *a2, unsigned int *a3)
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
  __int16 v15; // w8
  int v16; // w9
  __int64 v17; // x21
  _QWORD *scan_result; // x19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x21
  __int64 v28; // x8
  size_t v29; // x0
  void *v30; // x0
  unsigned int v31; // w20
  _QWORD v33[2]; // [xsp+0h] [xbp-10h] BYREF

  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33[0] = 0;
  v6 = _qdf_mem_malloc(0x2D0u, "scm_scan_get_entry_by_mac_addr", 2297);
  if ( v6 )
  {
    *(_BYTE *)(v6 + 16) = 1;
    v15 = *((_WORD *)a2 + 2);
    v16 = *a2;
    v17 = v6;
    *(_WORD *)(v6 + 74) = v15;
    *(_DWORD *)(v6 + 70) = v16;
    scan_result = scm_get_scan_result(a1, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    _qdf_mem_free(v17);
    if ( scan_result )
    {
      if ( *((_DWORD *)scan_result + 4) )
      {
        qdf_list_peek_front(scan_result, v33);
        v27 = v33[0];
        if ( v33[0] )
        {
          v28 = *(_QWORD *)(v33[0] + 24LL);
          if ( v28 )
          {
            v29 = *(unsigned int *)(v28 + 1704);
            *a3 = v29;
            v30 = (void *)_qdf_mem_malloc(v29, "scm_scan_get_entry_by_mac_addr", 2321);
            *((_QWORD *)a3 + 1) = v30;
            if ( !v30 )
            {
              v31 = 2;
              goto LABEL_12;
            }
            qdf_mem_copy(v30, *(const void **)(*(_QWORD *)(v27 + 24) + 1712LL), *a3);
          }
        }
        v31 = 0;
      }
      else
      {
        v31 = 4;
      }
LABEL_12:
      scm_purge_scan_results((__int64)scan_result, v19, v20, v21, v22, v23, v24, v25, v26);
      goto LABEL_13;
    }
    v31 = 4;
  }
  else
  {
    v31 = 2;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v31;
}
