__int64 __fastcall clk_rcg2_recalc_rate(__int64 a1, __int64 a2)
{
  int v4; // w8
  int v5; // w9
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 - 48);
  v5 = *(unsigned __int8 *)(a1 + 144);
  v6 = *(_QWORD *)(a1 + 24);
  v8 = 0;
  regmap_read(v6, (unsigned int)(v4 + v5 + 4), &v8);
  result = _clk_rcg2_recalc_rate(a1, a2, v8);
  _ReadStatusReg(SP_EL0);
  return result;
}
