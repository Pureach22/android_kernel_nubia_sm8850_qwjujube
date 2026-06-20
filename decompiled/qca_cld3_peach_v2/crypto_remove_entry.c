__int64 __fastcall crypto_remove_entry(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int16 v14; // w8
  unsigned int v15; // w22
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 result; // x0
  _QWORD *v24; // x8
  __int64 v25; // x10
  _QWORD *v26; // x9
  _QWORD *v27; // x10
  _QWORD *v28; // x9

  v14 = *(_WORD *)a2 ^ *(unsigned __int8 *)(a2 + 9) ^ *(_WORD *)(a2 + 2) ^ *(_WORD *)(a2 + 4);
  v15 = ((v14 >> *(_DWORD *)(a1 + 76)) ^ v14) & *(_DWORD *)(a1 + 72);
  qdf_trace_msg(
    0x1Cu,
    4u,
    "%s: crypto remove entry key index %d link id %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "crypto_remove_entry",
    v15);
  v16 = *(_QWORD *)(a2 + 16);
  if ( v16 )
  {
    _qdf_mem_free(v16);
    *(_QWORD *)(a2 + 16) = 0;
  }
  v17 = *(_QWORD *)(a2 + 24);
  if ( v17 )
  {
    _qdf_mem_free(v17);
    *(_QWORD *)(a2 + 24) = 0;
  }
  v18 = *(_QWORD *)(a2 + 32);
  if ( v18 )
  {
    _qdf_mem_free(v18);
    *(_QWORD *)(a2 + 32) = 0;
  }
  v19 = *(_QWORD *)(a2 + 40);
  if ( v19 )
  {
    _qdf_mem_free(v19);
    *(_QWORD *)(a2 + 40) = 0;
  }
  v20 = *(_QWORD *)(a2 + 48);
  if ( v20 )
  {
    _qdf_mem_free(v20);
    *(_QWORD *)(a2 + 48) = 0;
  }
  v21 = *(_QWORD *)(a2 + 56);
  if ( v21 )
  {
    _qdf_mem_free(v21);
    *(_QWORD *)(a2 + 56) = 0;
  }
  v22 = *(_QWORD *)(a2 + 64);
  if ( v22 )
  {
    _qdf_mem_free(v22);
    *(_QWORD *)(a2 + 64) = 0;
  }
  result = *(_QWORD *)(a2 + 72);
  if ( result )
  {
    result = _qdf_mem_free(result);
    *(_QWORD *)(a2 + 72) = 0;
  }
  v24 = (_QWORD *)(a2 + 152);
  v25 = *(_QWORD *)(a2 + 152);
  v26 = *(_QWORD **)(a2 + 160);
  *(_WORD *)(a2 + 148) = 0;
  *(_BYTE *)(a2 + 150) = 0;
  if ( v25 )
    v27 = (_QWORD *)(v25 + 160);
  else
    v27 = (_QWORD *)(*(_QWORD *)(a1 + 80) + 16LL * v15 + 8);
  *v27 = v26;
  *v26 = *(_QWORD *)(a2 + 152);
  *v24 = 0;
  *(_QWORD *)(a2 + 160) = 0;
  v28 = *(_QWORD **)(a3 + 8);
  *(_QWORD *)(a2 + 160) = v28;
  *v28 = a2;
  *(_QWORD *)(a3 + 8) = v24;
  return result;
}
