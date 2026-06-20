__int64 __fastcall clk_hfpll_enable(__int64 a1)
{
  unsigned int *v2; // x20
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x20
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int **)(a1 - 16);
  v3 = *(_QWORD *)(a1 + 24);
  v8 = 0;
  v4 = raw_spin_lock_irqsave(a1 + 144);
  v5 = *v2;
  v6 = v4;
  regmap_read(v3, v5, &v8);
  if ( (v8 & 7) == 0 )
    _clk_hfpll_enable(a1);
  raw_spin_unlock_irqrestore(a1 + 144, v6);
  _ReadStatusReg(SP_EL0);
  return 0;
}
