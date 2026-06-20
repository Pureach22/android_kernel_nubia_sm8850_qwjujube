__int64 __fastcall qcedev_check_sha_params(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w8
  int v5; // w8
  void *v6; // x0
  __int64 v7; // x9
  unsigned int v8; // w8
  int v9; // w12
  __int64 v10; // x3

  v4 = *(_DWORD *)(a1 + 316);
  if ( v4 != 4 )
  {
    a3 = *(unsigned int *)(a1 + 256);
    if ( (unsigned int)(a3 - 17) >= 0xFFFFFFF0 )
    {
      if ( v4 >= 5 )
      {
        printk(&unk_12D42, "qcedev_check_sha_params", v4, a4);
        return 4294967274LL;
      }
      if ( (*(_DWORD *)(a1 + 316) & 6) == 2 )
      {
        if ( !*(_QWORD *)(a1 + 304) )
        {
          v6 = &unk_12AB6;
          goto LABEL_24;
        }
        if ( !*(_DWORD *)(a1 + 312) )
        {
          printk(&unk_1265D, "qcedev_check_sha_params", 0, a4);
          return 4294967274LL;
        }
      }
      goto LABEL_12;
    }
LABEL_18:
    printk(&unk_121A1, "qcedev_check_sha_params", a3, a4);
    return 4294967274LL;
  }
  if ( (*(_BYTE *)(a2 + 28) & 1) == 0 )
  {
    v6 = &unk_11D59;
    goto LABEL_24;
  }
  a3 = *(unsigned int *)(a1 + 256);
  if ( (unsigned int)(a3 - 17) <= 0xFFFFFFEF )
    goto LABEL_18;
  v5 = *(_DWORD *)(a1 + 312);
  if ( v5 != 16 && v5 != 32 )
  {
    v6 = &unk_12244;
LABEL_24:
    printk(v6, "qcedev_check_sha_params", a3, a4);
    return 4294967274LL;
  }
LABEL_12:
  v7 = 0;
  v8 = 0;
  do
  {
    if ( v7 == 256 )
    {
      __break(0x5512u);
      return qcedev_hash_init(a1, a2, a3);
    }
    v9 = *(_DWORD *)(a1 + 8 + v7);
    if ( __CFADD__(v8, v9) )
    {
      v6 = &unk_12B2F;
      goto LABEL_24;
    }
    v7 += 16;
    v8 += v9;
  }
  while ( 16LL * (unsigned int)a3 != v7 );
  v10 = *(unsigned int *)(a1 + 260);
  if ( v8 == (_DWORD)v10 )
    return 0;
  printk(&unk_124BC, "qcedev_check_sha_params", v8, v10);
  return 4294967274LL;
}
