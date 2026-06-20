__int64 __fastcall clk_rcg_set_parent(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x0
  __int64 v5; // x1
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v5 = *(unsigned int *)(a1 - 48);
  v7 = 0;
  regmap_read(v4, v5, &v7);
  regmap_write(
    *(_QWORD *)(a1 + 24),
    *(unsigned int *)(a1 - 48),
    v7 & ~(7 << *(_BYTE *)(a1 - 24))
  | (*(unsigned __int8 *)(*(_QWORD *)(a1 - 16) + 2LL * a2 + 1) << *(_BYTE *)(a1 - 24)));
  _ReadStatusReg(SP_EL0);
  return 0;
}
