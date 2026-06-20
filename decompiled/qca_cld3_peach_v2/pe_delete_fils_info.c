__int64 __fastcall pe_delete_fils_info(
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
  _QWORD *v9; // x19
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 result; // x0
  const char *v22; // x2

  if ( !a1 || !*(_BYTE *)(a1 + 70) )
  {
    v22 = "%s: session is not valid";
    return qdf_trace_msg(0x35u, 8u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "pe_delete_fils_info");
  }
  v9 = *(_QWORD **)(a1 + 9976);
  if ( !v9 )
  {
    v22 = "%s: fils info not found";
    return qdf_trace_msg(0x35u, 8u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "pe_delete_fils_info");
  }
  v11 = v9[1];
  if ( v11 )
    _qdf_mem_free(v11);
  v12 = v9[3];
  if ( v12 )
    _qdf_mem_free(v12);
  v13 = v9[5];
  if ( v13 )
    _qdf_mem_free(v13);
  v14 = v9[7];
  if ( v14 )
    _qdf_mem_free(v14);
  v15 = v9[82];
  if ( v15 )
    _qdf_mem_free(v15);
  v16 = v9[84];
  if ( v16 )
    _qdf_mem_free(v16);
  v17 = v9[86];
  if ( v17 )
    _qdf_mem_free(v17);
  v18 = v9[90];
  if ( v18 )
    _qdf_mem_free(v18);
  v19 = v9[92];
  if ( v19 )
    _qdf_mem_free(v19);
  v20 = v9[201];
  if ( v20 )
    _qdf_mem_free(v20);
  result = _qdf_mem_free((__int64)v9);
  *(_QWORD *)(a1 + 9976) = 0;
  return result;
}
