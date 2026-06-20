__int64 __fastcall wlan_crypto_free_key(
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
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 result; // x0

  if ( !a1 )
    return qdf_trace_msg(0x1Cu, 2u, "%s: given key ptr is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_crypto_free_key");
  v10 = *(_QWORD *)a1;
  if ( v10 )
  {
    _qdf_mem_free(v10);
    *(_QWORD *)a1 = 0;
  }
  v11 = *(_QWORD *)(a1 + 8);
  if ( v11 )
  {
    _qdf_mem_free(v11);
    *(_QWORD *)(a1 + 8) = 0;
  }
  v12 = *(_QWORD *)(a1 + 16);
  if ( v12 )
  {
    _qdf_mem_free(v12);
    *(_QWORD *)(a1 + 16) = 0;
  }
  v13 = *(_QWORD *)(a1 + 24);
  if ( v13 )
  {
    _qdf_mem_free(v13);
    *(_QWORD *)(a1 + 24) = 0;
  }
  v14 = *(_QWORD *)(a1 + 32);
  if ( v14 )
  {
    _qdf_mem_free(v14);
    *(_QWORD *)(a1 + 32) = 0;
  }
  v15 = *(_QWORD *)(a1 + 40);
  if ( v15 )
  {
    _qdf_mem_free(v15);
    *(_QWORD *)(a1 + 40) = 0;
  }
  v16 = *(_QWORD *)(a1 + 48);
  if ( v16 )
  {
    _qdf_mem_free(v16);
    *(_QWORD *)(a1 + 48) = 0;
  }
  result = *(_QWORD *)(a1 + 56);
  if ( result )
  {
    result = _qdf_mem_free(result);
    *(_QWORD *)(a1 + 56) = 0;
  }
  *(_WORD *)(a1 + 132) = 0;
  *(_BYTE *)(a1 + 134) = 0;
  return result;
}
