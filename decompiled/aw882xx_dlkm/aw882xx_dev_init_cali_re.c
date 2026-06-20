__int64 __fastcall aw882xx_dev_init_cali_re(__int64 a1)
{
  unsigned int v3; // w3
  __int64 *v4; // x8
  __int64 v5; // x1
  __int64 *v6; // x8
  __int64 v7; // x1
  int v8; // w8
  __int64 *v9; // x8
  __int64 v10; // x1

  if ( !*(_BYTE *)(a1 + 649) )
  {
    v4 = *(__int64 **)(a1 + 112);
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    printk(&unk_257B5, v5, "aw882xx_dev_init_cali_re");
    return 0;
  }
  if ( *(_DWORD *)(a1 + 652) )
    return 0;
  if ( (unsigned int)aw882xx_cali_read_re_from_nvram() )
  {
    v9 = *(__int64 **)(a1 + 112);
    v10 = v9[14];
    if ( !v10 )
      v10 = *v9;
    printk(&unk_22FE4, v10, "aw882xx_dev_init_cali_re");
    *(_DWORD *)(a1 + 652) = 0;
    *(_BYTE *)(a1 + 664) = 0;
    return 0;
  }
  else
  {
    v3 = *(_DWORD *)(a1 + 652);
    if ( v3 < *(_DWORD *)(a1 + 64) || v3 > *(_DWORD *)(a1 + 60) )
    {
      v6 = *(__int64 **)(a1 + 112);
      v7 = v6[14];
      if ( !v7 )
        v7 = *v6;
      printk(&unk_223E9, v7, "aw882xx_dev_init_cali_re");
      v8 = *(unsigned __int8 *)(a1 + 665);
      *(_DWORD *)(a1 + 652) = 0;
      if ( v8 )
        *(_BYTE *)(a1 + 664) = -1;
      return 4294967274LL;
    }
    else
    {
      if ( !*(_BYTE *)(a1 + 665) )
        return 0;
      *(_BYTE *)(a1 + 664) = 1;
      return 0;
    }
  }
}
