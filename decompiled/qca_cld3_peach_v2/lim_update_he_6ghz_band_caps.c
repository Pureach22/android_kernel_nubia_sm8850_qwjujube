__int64 __fastcall lim_update_he_6ghz_band_caps(__int64 a1, const void *a2, __int64 a3)
{
  unsigned int v4; // w8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  qdf_mem_copy((void *)(a3 + 246), a2, 4u);
  v4 = *(unsigned __int16 *)(a3 + 247);
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: min_mpdu_space: %0d, max_mpdu_len_exp: %0x, max_mpdu_len %0x, smps %0x, rd %0x rx_ant_ptn %d tx_ant_ptn %d",
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           v12,
           "lim_log_he_6g_cap",
           v4 & 7,
           (v4 >> 3) & 7,
           (v4 >> 8) & 7,
           (v4 >> 11) & 3,
           (v4 >> 13) & 1,
           (v4 >> 14) & 1,
           v4 >> 15);
}
