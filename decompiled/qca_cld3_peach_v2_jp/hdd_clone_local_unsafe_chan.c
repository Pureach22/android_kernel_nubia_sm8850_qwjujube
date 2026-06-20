__int64 __fastcall hdd_clone_local_unsafe_chan(__int64 a1, _QWORD *a2, __int16 *a3)
{
  __int64 result; // x0
  __int16 v5; // w20
  _QWORD *v6; // x21
  __int16 *v7; // x22
  __int64 v8; // x23
  void *v9; // x0
  void *v10; // x19

  result = 4294967274LL;
  if ( a1 && a3 )
  {
    if ( *(unsigned __int16 *)(a1 + 640) >= 0x66u )
      v5 = 102;
    else
      v5 = *(_WORD *)(a1 + 640);
    if ( !*(_WORD *)(a1 + 640) )
    {
      v10 = nullptr;
      goto LABEL_10;
    }
    v6 = a2;
    v7 = a3;
    v8 = a1;
    v9 = (void *)_qdf_mem_malloc(2LL * (v5 & 0x7FFF), "hdd_clone_local_unsafe_chan", 14864);
    if ( v9 )
    {
      v10 = v9;
      qdf_mem_copy(v9, (const void *)(v8 + 642), (unsigned __int16)(2 * v5));
      a3 = v7;
      a2 = v6;
LABEL_10:
      *a2 = v10;
      *a3 = v5;
      return 0;
    }
    return 4294967284LL;
  }
  return result;
}
