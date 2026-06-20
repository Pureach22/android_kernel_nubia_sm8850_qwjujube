__int64 __fastcall ufs_qcom_phy_dump_regs(__int64 a1, int a2, int a3, __int64 a4)
{
  unsigned __int64 v9; // x23
  __int64 v10; // x22
  unsigned __int64 v11; // x26
  unsigned __int64 v12; // x27
  int v13; // w0
  bool v14; // cf
  unsigned __int64 StatusReg; // x24
  __int64 v16; // x26

  if ( (((unsigned __int8)a3 | (unsigned __int8)a2) & 3) != 0 )
    return 4294967274LL;
  v9 = a3;
  v10 = _kmalloc_noprof(a3, 3520);
  if ( !v10 )
    return 4294967284LL;
  while ( a3 )
  {
    v11 = 0;
    v12 = v9;
    while ( 1 )
    {
      v13 = readl_relaxed(*(_QWORD *)(a1 + 24) + a2 + v11);
      if ( (v11 & 0x8000000000000000LL) != 0 )
        break;
      if ( v9 < v11 )
        break;
      v14 = v12 >= 4;
      v12 -= 4LL;
      if ( !v14 )
        break;
      *(_DWORD *)(v10 + v11) = v13;
      v11 += 4LL;
      if ( v11 >= a3 )
        goto LABEL_11;
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v16 = *(_QWORD *)(StatusReg + 80);
    v9 = a3;
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v10 = _kmalloc_noprof(a3, 3520);
    *(_QWORD *)(StatusReg + 80) = v16;
    if ( !v10 )
      return 4294967284LL;
  }
LABEL_11:
  print_hex_dump(&unk_8422, a4, 2 * (unsigned int)(a3 > 4), 16, 4, v10, a3, 0);
  kfree(v10);
  return 0;
}
