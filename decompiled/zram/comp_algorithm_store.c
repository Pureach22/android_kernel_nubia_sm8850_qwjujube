__int64 __fastcall comp_algorithm_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v6; // x22
  size_t v7; // x0
  size_t v8; // x21
  __int64 v9; // x0
  __int64 v10; // x20
  char *v11; // x0

  v6 = *(_QWORD *)(*(_QWORD *)(a1 - 224) + 88LL);
  v7 = strlen(s);
  if ( v7 > 0x7F )
    return -7;
  v8 = v7;
  v9 = kstrdup(s, 3264);
  if ( !v9 )
    return -12;
  v10 = v9;
  if ( v8 && *(_BYTE *)(v9 + v8 - 1) == 10 )
    *(_BYTE *)(v9 + v8 - 1) = 0;
  if ( zcomp_available_algorithm(v9) )
  {
    down_write(v6 + 32);
    if ( *(_QWORD *)(v6 + 216) )
    {
      up_write(v6 + 32);
      kfree(v10);
      printk(&unk_B5B3);
      return -16;
    }
    else
    {
      v11 = *(char **)(v6 + 224);
      if ( v11 != "lzo-rle" )
        kfree(v11);
      *(_QWORD *)(v6 + 224) = v10;
      up_write(v6 + 32);
    }
  }
  else
  {
    kfree(v10);
    return -22;
  }
  return a4;
}
