__int64 __fastcall ufsqcom_dump_regs(__int64 a1, __int64 a2, unsigned __int64 a3, __int64 a4, int a5)
{
  __int64 v8; // x23
  __int64 v11; // x22
  unsigned __int64 v12; // x24
  unsigned __int64 v13; // x26
  int v14; // w0
  bool v15; // cf
  unsigned __int64 StatusReg; // x24
  __int64 v17; // x26

  if ( (((unsigned int)a3 | (unsigned int)a2) & 3LL) != 0 )
    return 4294967274LL;
  LODWORD(v8) = a5;
  v11 = _kmalloc_noprof(a3, 2336);
  if ( !v11 )
    return 4294967284LL;
  while ( a3 )
  {
    if ( (unsigned int)v8 <= 6 )
    {
      v12 = 0;
      v13 = a3;
      v8 = a1 + 24LL * (unsigned int)v8;
      a1 = 4912;
      while ( 1 )
      {
        v14 = readl(*(_QWORD *)(v8 + 4912) + a2 + v12);
        if ( (v12 & 0x8000000000000000LL) != 0 )
          break;
        if ( v12 > a3 )
          break;
        v15 = v13 >= 4;
        v13 -= 4LL;
        if ( !v15 )
          break;
        *(_DWORD *)(v11 + v12) = v14;
        v12 += 4LL;
        if ( v12 >= a3 )
          goto LABEL_12;
      }
      __break(1u);
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v17 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v11 = _kmalloc_noprof(a3, 2336);
    *(_QWORD *)(StatusReg + 80) = v17;
    if ( !v11 )
      return 4294967284LL;
  }
LABEL_12:
  print_hex_dump(&unk_19A10, a4, 2 * (unsigned int)(a3 > 4), 16, 4, v11, a3, 0);
  kfree(v11);
  return 0;
}
