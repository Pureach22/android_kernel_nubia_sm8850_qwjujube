__int64 __fastcall aw_dev_mode1_pll_check(__int64 a1)
{
  unsigned int v2; // w20
  void (__fastcall *v3)(__int64, __int64, int *); // x8
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 *v7; // x8
  __int64 v8; // x1
  __int64 result; // x0
  __int64 *v10; // x8
  __int64 v11; // x1
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v2 = 0;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  while ( 1 )
  {
    v3 = *(void (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
    v4 = *(_QWORD *)(a1 + 120);
    v5 = *(unsigned int *)(a1 + 528);
    if ( *((_DWORD *)v3 - 1) != 1983062130 )
      __break(0x8228u);
    v3(v4, v5, &v12);
    if ( (*(_DWORD *)(a1 + 544) & ~v12) == 0 )
      break;
    usleep_range_state(2000, 2010, 2);
    if ( v2++ >= 9 )
    {
      v7 = *(__int64 **)(a1 + 112);
      v8 = v7[14];
      if ( !v8 )
        v8 = *v7;
      printk(&unk_26A14, v8, "aw_dev_mode1_pll_check");
      result = 0xFFFFFFFFLL;
      goto LABEL_13;
    }
  }
  v10 = *(__int64 **)(a1 + 112);
  v11 = v10[14];
  if ( !v11 )
    v11 = *v10;
  printk(&unk_22D82, v11, "aw_dev_mode1_pll_check");
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
