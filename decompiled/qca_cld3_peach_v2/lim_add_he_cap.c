void *__fastcall lim_add_he_cap(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  void *result; // x0
  unsigned int v8; // w8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  if ( a4 && (*(_BYTE *)(a3 + 164) & 1) != 0 )
  {
    result = qdf_mem_copy((void *)(a3 + 168), (const void *)(a4 + 3372), 0x3Cu);
    if ( *(_BYTE *)(a2 + 8764) == 1 )
    {
      qdf_mem_copy((void *)(a3 + 246), (const void *)(a4 + 3432), 4u);
      v8 = *(unsigned __int16 *)(a3 + 247);
      return (void *)qdf_trace_msg(
                       0x35u,
                       8u,
                       "%s: min_mpdu_space: %0d, max_mpdu_len_exp: %0x, max_mpdu_len %0x, smps %0x, rd %0x rx_ant_ptn %d tx_ant_ptn %d",
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       "lim_log_he_6g_cap",
                       v8 & 7,
                       (v8 >> 3) & 7,
                       (v8 >> 8) & 7,
                       (v8 >> 11) & 3,
                       (v8 >> 13) & 1,
                       (v8 >> 14) & 1,
                       v8 >> 15);
    }
  }
  return result;
}
