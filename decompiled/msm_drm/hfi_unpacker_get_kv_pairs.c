__int64 __fastcall hfi_unpacker_get_kv_pairs(_QWORD *a1, __int64 a2, unsigned int a3, int a4, __int64 a5)
{
  __int64 v5; // x8
  _DWORD *v6; // x9
  int v7; // w8
  _DWORD *v8; // x9
  __int64 v9; // x11

  if ( a1 && a2 && *a1 && (v5 = *(_QWORD *)(a2 + 24)) != 0 )
  {
    v6 = (_DWORD *)(v5 + a3);
    if ( *v6 == a4 )
    {
      if ( a4 )
      {
        v7 = 0;
        v8 = v6 + 1;
        do
        {
          v9 = a5 + 16LL * v7++;
          *(_DWORD *)v9 = *v8;
          *(_QWORD *)(v9 + 8) = v8 + 1;
          v8 += *((unsigned __int8 *)v8 + 3) + 1;
        }
        while ( a4 != v7 );
      }
      return 0;
    }
    else
    {
      printk(&unk_2156A9, "hfi_unpacker_get_kv_pairs");
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    printk(&unk_253204, "hfi_unpacker_get_kv_pairs");
    return 0xFFFFFFFFLL;
  }
}
