unsigned __int16 *__fastcall lim_dump_he_info(
        unsigned __int16 *result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  unsigned __int16 *v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v10 = a2 + 0x2000;
  if ( *(_BYTE *)(a2 + 8676) == 1 )
  {
    v11 = result;
    result = (unsigned __int16 *)wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a2 + 16), a3, a4, a5, a6, a7, a8, a9, a10);
    if ( result )
      return (unsigned __int16 *)qdf_trace_msg(
                                   0x35u,
                                   8u,
                                   " HE info: bss_color %d default_pe %d ul mu %d, rx_pream_puncturing %d MCS LT_80: tx: "
                                   "0x%x, rx: 0x%x, 160: tx: 0x%x, rx: 0x%x",
                                   v12,
                                   v13,
                                   v14,
                                   v15,
                                   v16,
                                   v17,
                                   v18,
                                   v19,
                                   *(_BYTE *)(v10 + 553) & 0x3F,
                                   *(_DWORD *)(v10 + 549) & 7,
                                   (*(_DWORD *)(v10 + 497) >> 7) & 3,
                                   (*(_QWORD *)((char *)v11 + 21777) >> 57) & 0xFLL,
                                   result[11959],
                                   result[11958],
                                   result[11961],
                                   result[11960]);
  }
  return result;
}
