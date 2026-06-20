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
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  unsigned int v21; // w8

  v11 = a1 + 0x2000;
  if ( *(_DWORD *)(a1 + 7036)
    || (result = wlan_reg_is_24ghz_ch_freq(a2), (result & 1) != 0)
    && ((v21 = *(unsigned __int8 *)(a1 + 154), v21 > 0xD) || ((1 << v21) & 0x3001) == 0 || a1 && !*(_BYTE *)(v11 + 2504)) )
  {
    qdf_trace_msg(0x35u, 8u, "%s: Disable HT D-SMPS", a3, a4, a5, a6, a7, a8, a9, a10, "lim_disable_ht_dynamic_smps");
    *(_WORD *)(a1 + 7266) |= 0xCu;
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Disable HE D-SMPS",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "lim_disable_he_dynamic_smps");
    *(_QWORD *)(v11 + 489) &= ~0x400000000000uLL;
  }
  return result;
}
