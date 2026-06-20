__int64 __fastcall clk_alpha_pll_postdiv_set_rate(__int64 a1, __int64 a2, __int64 a3)
{
  return regmap_update_bits_base(
           *(_QWORD *)(a1 + 24),
           *(_DWORD *)(a1 - 16) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 8) + 5LL),
           (unsigned int)(0xFFFFFFFFFFFFFFFFLL >> -*(_BYTE *)(a1 - 12)) << 8,
           ((unsigned int)((a2 + a3 - 1) / (unsigned __int64)(unsigned int)a2) << 8) - 256,
           0,
           0,
           0);
}
