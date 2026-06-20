__int64 __fastcall qfprom_reg_read(__int64 *a1, int a2, void *a3, size_t a4)
{
  __int64 v4; // x24
  char v7; // w21
  signed int v8; // w26
  signed int v9; // w25
  unsigned __int64 v10; // x22
  __int64 v11; // x23
  __int64 v12; // x27
  int v13; // w0
  __int64 v14; // x8
  unsigned __int64 v15; // x1
  unsigned __int64 v16; // x8
  size_t v17; // x9
  unsigned __int64 StatusReg; // x27
  __int64 v20; // x28

  v4 = a1[2];
  v7 = a2;
  if ( read_raw_data == 1 && *a1 )
    v4 = *a1;
  v8 = a2 & 0xFFFFFFFC;
  v9 = (a2 + a4 + 3) & 0xFFFFFFFC;
  v10 = (int)(v9 - (a2 & 0xFFFFFFFC));
  v11 = _kmalloc_noprof(v10, 3520);
  if ( !v11 )
  {
LABEL_23:
    printk(&unk_7661, "qfprom_reg_read");
    return 4294967284LL;
  }
  while ( 1 )
  {
    if ( v9 > v8 )
    {
      v12 = 0;
      v4 += v8;
      while ( 1 )
      {
        v13 = readl_relaxed(v4 + v12);
        v14 = (int)v12;
        v15 = v10 >= (int)v12 ? v10 - (int)v12 : 0LL;
        if ( v15 <= 3 )
          break;
        if ( (v12 & 0x80000000) != 0 || v10 < (int)v12 || v10 - (int)v12 < 4 )
          goto LABEL_21;
        v12 += 4;
        *(_DWORD *)(v11 + v14) = v13;
        if ( v8 + v12 >= v9 )
          goto LABEL_15;
      }
      _fortify_panic(17);
LABEL_21:
      __break(1u);
      goto LABEL_22;
    }
LABEL_15:
    v16 = v7 & 3;
    v17 = v10 - v16;
    if ( v10 < v16 )
      v17 = 0;
    if ( v17 >= a4 )
      break;
LABEL_22:
    _fortify_panic(16);
    StatusReg = _ReadStatusReg(SP_EL0);
    v20 = *(_QWORD *)(StatusReg + 80);
    v10 = v9 - v8;
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v11 = _kmalloc_noprof(v10, 3520);
    *(_QWORD *)(StatusReg + 80) = v20;
    if ( !v11 )
      goto LABEL_23;
  }
  memcpy(a3, (const void *)(v11 + v16), a4);
  kfree(v11);
  return 0;
}
