__int64 __fastcall ufs_qcom_phy_save_regs(_QWORD *a1, int a2, int a3, char *s2)
{
  _QWORD *v5; // x23
  _QWORD *i; // x22
  const char *v11; // x0
  unsigned __int64 v12; // x24
  unsigned __int64 StatusReg; // x26
  int v14; // w27
  __int64 v15; // x0
  __int64 v16; // x0
  _QWORD *v17; // x1
  unsigned __int64 v18; // x21

  if ( (((unsigned __int8)a3 | (unsigned __int8)a2) & 3) != 0 )
    return 4294967274LL;
  v5 = a1 + 59;
  for ( i = (_QWORD *)a1[59]; i != v5; i = (_QWORD *)*i )
  {
    v11 = (const char *)i[2];
    if ( v11 && !strcmp(v11, s2) )
    {
      v12 = a3;
      if ( !a3 )
        return 0;
      goto LABEL_16;
    }
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  v14 = *(_DWORD *)(StatusReg + 68);
  *(_DWORD *)(StatusReg + 68) = v14 | 0x80000;
  v15 = devm_kmalloc(a1[2], 40, 2336);
  if ( v15 )
  {
    v12 = a3;
    i = (_QWORD *)v15;
    v16 = devm_kmalloc(a1[2], a3, 2336);
    i[3] = v16;
    if ( v16 )
    {
      *(_DWORD *)(StatusReg + 68) &= v14 | 0xFFF7FFFF;
      v17 = (_QWORD *)a1[60];
      i[2] = s2;
      i[4] = a3;
      if ( i == v5 || v17 == i || (_QWORD *)*v17 != v5 )
      {
        _list_add_valid_or_report(i, v17, v5);
        if ( !a3 )
          return 0;
      }
      else
      {
        a1[60] = i;
        *i = v5;
        i[1] = v17;
        *v17 = i;
        if ( !a3 )
          return 0;
      }
LABEL_16:
      v18 = 0;
      do
      {
        *(_DWORD *)(i[3] + v18) = readl_relaxed((unsigned int *)(a1[3] + a2 + v18));
        v18 += 4LL;
      }
      while ( v18 < v12 );
      return 0;
    }
  }
  *(_DWORD *)(StatusReg + 68) &= v14 | 0xFFF7FFFF;
  return 4294967284LL;
}
