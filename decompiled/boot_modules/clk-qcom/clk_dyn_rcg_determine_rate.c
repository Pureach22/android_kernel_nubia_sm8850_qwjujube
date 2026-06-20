__int64 __fastcall clk_dyn_rcg_determine_rate(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 result; // x0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v5 = *(unsigned int *)(a1 - 64);
  v7 = 0;
  regmap_read(v4, v5, &v7);
  result = freq_tbl_determine_rate(
             a1,
             *(_QWORD *)(a1 - 8),
             a2,
             *(_QWORD *)(a1 + 16LL * ((v7 & (unsigned int)(1LL << *(_BYTE *)(a1 - 60))) != 0) - 32));
  _ReadStatusReg(SP_EL0);
  return result;
}
