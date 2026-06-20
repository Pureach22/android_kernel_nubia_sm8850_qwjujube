__int64 __fastcall scm_purge_scan_results(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x1
  unsigned int v20; // w20
  _QWORD *v21; // x21
  __int64 v22; // x22
  __int64 v23; // x0
  __int64 v24; // x0
  _QWORD *v26; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v27[2]; // [xsp+10h] [xbp-10h] BYREF

  v27[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = nullptr;
  v27[0] = nullptr;
  if ( a1 )
  {
    v10 = qdf_list_peek_front((_QWORD *)a1, v27);
    v19 = v27[0];
    if ( v27[0] )
    {
      do
      {
        qdf_list_peek_next((_QWORD *)a1, v19, &v26);
        v21 = v27[0];
        v20 = qdf_list_remove_node(a1, v27[0]);
        if ( !v20 )
        {
          v22 = v21[3];
          if ( v22 )
          {
            v23 = *(_QWORD *)(v22 + 1320);
            if ( v23 )
              _qdf_mem_free(v23);
            v24 = *(_QWORD *)(v22 + 1896);
            if ( v24 )
              _qdf_mem_free(v24);
            _qdf_mem_free(v22);
          }
          _qdf_mem_free((__int64)v21);
        }
        v19 = v26;
        v26 = nullptr;
        v27[0] = v19;
      }
      while ( v19 );
    }
    else
    {
      v20 = v10;
    }
    if ( *(_DWORD *)(a1 + 16) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "qdf_list_destroy");
    _qdf_mem_free(a1);
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: scan_result is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "scm_purge_scan_results");
    v20 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v20;
}
