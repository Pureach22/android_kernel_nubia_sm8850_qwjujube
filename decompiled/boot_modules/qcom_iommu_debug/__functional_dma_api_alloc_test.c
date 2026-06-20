__int64 __fastcall _functional_dma_api_alloc_test(__int64 *a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 result; // x0
  __int64 v7; // x1
  unsigned __int8 *v8; // x21
  __int64 v9; // x1
  __int64 v10; // x24
  unsigned int v11; // w27
  char v12; // w28
  __int64 v13; // x22
  int v14; // w25
  __int64 v15; // x1
  bool v16; // zf
  __int64 v17; // x1
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[14];
  if ( !v4 )
    v4 = *a1;
  v18[0] = 0;
  printk(&unk_CAE7, v4);
  seq_printf(a2, "Allocating coherent buffer");
  v5 = dma_alloc_attrs(a1, 759808, v18, 3264, 0);
  if ( v5 )
  {
    v7 = a1[14];
    v8 = (unsigned __int8 *)v5;
    if ( !v7 )
      v7 = *a1;
    printk(&unk_CFA4, v7);
    seq_printf(a2, "  -> SUCCEEDED\n");
    v9 = a1[14];
    if ( !v9 )
      v9 = *a1;
    printk(&unk_D371, v9);
    seq_printf(a2, "Using coherent buffer");
    v10 = 0;
    v11 = 0;
    v12 = 1;
    do
    {
      v13 = v10 << 10;
      while ( 1 )
      {
        memset(v8, 165, 0xB9800u);
        v8[v13] = v10 + (unsigned __int16)v10 / 0xFFu + 1;
        v14 = (unsigned __int16)((unsigned __int16)v10 % 0xFFu + 1);
        if ( v14 != (unsigned __int8)(v10 + (unsigned __int16)v10 / 0xFFu + 1) )
          break;
        ++v10;
        v13 += 1024;
        if ( v10 == 742 )
        {
          if ( (v12 & 1) != 0 )
          {
            v17 = a1[14];
            if ( !v17 )
              v17 = *a1;
            printk(&unk_CFA4, v17);
            seq_printf(a2, "  -> SUCCEEDED\n");
            v11 = 0;
          }
          goto LABEL_21;
        }
      }
      v15 = a1[14];
      if ( !v15 )
        v15 = *a1;
      printk(&unk_CC9E, v15);
      seq_printf(a2, "  -> FAILED on iter %d since %d != %d\n", v10, v8[v13], v14);
      v12 = 0;
      v16 = v10++ == 741;
      v11 = -22;
    }
    while ( !v16 );
LABEL_21:
    dma_free_attrs(a1, 759808, v8, v18[0], 0);
    result = v11;
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
