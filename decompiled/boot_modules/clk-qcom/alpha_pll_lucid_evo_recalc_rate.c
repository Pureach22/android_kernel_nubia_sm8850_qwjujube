unsigned __int64 __fastcall alpha_pll_lucid_evo_recalc_rate(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 v6; // x9
  int v7; // w10
  bool v8; // zf
  char v9; // w10
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 40);
  v11[0] = 0;
  v5 = *(_QWORD *)(a1 + 24);
  regmap_read(v5, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(v4 + 1), (char *)v11 + 4);
  v6 = *(_QWORD *)(a1 - 40);
  HIDWORD(v11[0]) = WORD2(v11[0]);
  regmap_read(v5, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(v6 + 3), v11);
  v7 = *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 4LL) - *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL);
  _ReadStatusReg(SP_EL0);
  v8 = v7 == 4;
  v9 = 16;
  if ( v8 )
    v9 = 32;
  return 1000 * (((((unsigned __int64)LODWORD(v11[0]) * a2) >> v9) + HIDWORD(v11[0]) * a2 + 999) / 0x3E8);
}
