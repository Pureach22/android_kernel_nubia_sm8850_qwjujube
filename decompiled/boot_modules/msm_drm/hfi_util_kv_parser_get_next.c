__int64 __fastcall hfi_util_kv_parser_get_next(__int64 a1, int a2, _DWORD *a3, _QWORD *a4, _DWORD *a5)
{
  unsigned int v5; // w9
  __int64 v6; // x8
  unsigned int v7; // w10
  __int64 v8; // x10
  void *v10; // x0

  if ( !a1 || !a4 )
  {
    printk(&unk_27D002, "hfi_util_kv_parser_get_next");
    return (unsigned int)-22;
  }
  v5 = 0;
  *(_DWORD *)(a1 + 4) += a2;
  *a3 = 0;
  *a4 = 0;
  *a5 = 0;
  v7 = *(_DWORD *)a1;
  v6 = *(unsigned int *)(a1 + 4);
  if ( *(_DWORD *)a1 != (_DWORD)v6 )
  {
    if ( v7 < (unsigned int)v6 )
    {
      v10 = &unk_24F7EB;
    }
    else
    {
      if ( v7 - (unsigned int)v6 > 1 )
      {
        v8 = *(_QWORD *)(a1 + 8);
        v5 = 0;
        *(_DWORD *)(a1 + 4) = v6 + 1;
        *a3 = *(_DWORD *)(v8 + 4 * v6);
        *a4 = *(_QWORD *)(a1 + 8) + 4LL * *(unsigned int *)(a1 + 4);
        *a5 = *(_DWORD *)a1 - *(_DWORD *)(a1 + 4);
        return v5;
      }
      v10 = &unk_2313BF;
    }
    printk(v10, "hfi_util_kv_parser_get_next");
    return (unsigned int)-22;
  }
  return v5;
}
