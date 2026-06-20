__int64 __fastcall wma_vdev_set_he_config(
        __int64 *a1,
        unsigned __int8 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( (unsigned int)wma_vdev_set_param(*a1, a2, 0x8004u, *(_DWORD *)(a3 + 304), a4, a5, a6, a7, a8, a9, a10, a11) )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to set HE Config",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_vdev_set_he_config");
  return qdf_trace_msg(
           0x36u,
           8u,
           "%s: HE_STA_OBSSPD: PD_MIN: %d PD_MAX: %d SEC_CH_ED: %d TX_PWR: %d",
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           "wma_vdev_set_he_config",
           (unsigned int)(char)*(_DWORD *)(a3 + 304),
           (unsigned int)((__int16)*(_DWORD *)(a3 + 304) >> 8),
           (unsigned int)((int)(*(_DWORD *)(a3 + 304) << 8) >> 24),
           (unsigned int)(*(int *)(a3 + 304) >> 24));
}
