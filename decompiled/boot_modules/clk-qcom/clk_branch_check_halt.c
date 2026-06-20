__int64 __fastcall clk_branch_check_halt(__int64 a1, int a2)
{
  int v4; // w21
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x8
  int v8; // w9
  bool v9; // zf
  int v10; // w8
  int v11; // w11
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(a1 + 10);
  v5 = *(_QWORD *)(a1 + 40);
  v6 = *(unsigned int *)(a1 + 4);
  v13 = 0;
  regmap_read(v5, v6, &v13);
  v7 = 1LL << *(_BYTE *)(a1 + 9);
  v8 = v13;
  _ReadStatusReg(SP_EL0);
  v9 = (v8 & (unsigned int)v7) == 0;
  v10 = v9;
  v11 = !v9;
  if ( v4 != 1 )
    v10 = v11;
  return (v10 ^ a2) & 1;
}
