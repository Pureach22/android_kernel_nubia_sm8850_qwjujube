__int64 __fastcall lim_log_he_6g_cap(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  unsigned int v10; // w8

  v10 = *(unsigned __int16 *)(a10 + 1);
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: min_mpdu_space: %0d, max_mpdu_len_exp: %0x, max_mpdu_len %0x, smps %0x, rd %0x rx_ant_ptn %d tx_ant_ptn %d",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           "lim_log_he_6g_cap",
           v10 & 7,
           (v10 >> 3) & 7,
           (v10 >> 8) & 7,
           (v10 >> 11) & 3,
           (v10 >> 13) & 1,
           (v10 >> 14) & 1,
           v10 >> 15);
}
