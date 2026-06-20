__int64 __fastcall lim_disable_ht_he_dynamic_smps(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  unsigned int v20; // w8

  if ( *(_DWORD *)(a1 + 7036)
    || (result = wlan_reg_is_24ghz_ch_freq(a2), (result & 1) != 0)
    && ((v20 = *(unsigned __int8 *)(a1 + 154), v20 > 0xD) || ((1 << v20) & 0x3001) == 0) )
  {
    qdf_trace_msg(0x35u, 8u, "%s: Disable HT D-SMPS", a3, a4, a5, a6, a7, a8, a9, a10, "lim_disable_ht_dynamic_smps");
    *(_WORD *)(a1 + 7266) |= 0xCu;
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Disable HE D-SMPS",
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               "lim_disable_he_dynamic_smps");
    *(_QWORD *)(a1 + 8681) &= ~0x400000000000uLL;
  }
  return result;
}
