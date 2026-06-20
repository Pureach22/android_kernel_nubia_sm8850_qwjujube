__int64 __fastcall clk_alpha_pll_stromer_determine_rate(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  unsigned __int64 v3; // x10

  v2 = *(_QWORD *)(a2 + 8);
  v3 = (unsigned int)*(_QWORD *)(a2 + 32);
  if ( v2 % v3 )
    v2 = 1000
       * (((unsigned int)(v2 / v3) * *(_QWORD *)(a2 + 32)
         + (((unsigned __int64)(unsigned int)(((v2 % v3) << 32) / v3) * *(_QWORD *)(a2 + 32)) >> 32)
         + 999)
        / 0x3E8);
  *(_QWORD *)(a2 + 8) = v2;
  return 0;
}
