__int64 __fastcall clk_byte2_recalc_rate(__int64 a1, __int64 a2)
{
  int v4; // w8
  int v5; // w9
  __int64 v6; // x0
  __int64 v7; // x20
  int vdd_level; // w0
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 - 48);
  v5 = *(unsigned __int8 *)(a1 + 144);
  v6 = *(_QWORD *)(a1 + 24);
  v10 = 0;
  regmap_read(v6, (unsigned int)(v4 + v5 + 4), &v10);
  v7 = _clk_rcg2_recalc_rate(a1, a2, v10);
  if ( *(_QWORD *)(a1 + 64) )
  {
    vdd_level = clk_find_vdd_level(a1, a1 + 48, v7);
    if ( vdd_level >= 1 )
      *(_DWORD *)(a1 + 76) = vdd_level;
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
