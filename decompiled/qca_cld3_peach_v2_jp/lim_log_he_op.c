__int64 __fastcall lim_log_he_op(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  unsigned int v11; // w8
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  __int64 v24; // [xsp+0h] [xbp-30h]

  v11 = *(_DWORD *)(a10 + 1);
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: bss_color 0x%x pe_dur 0x%x twt req  0x%x txop_rts_thres  0x%x vht_op 0x%x part color 0x%x Co-located 0x"
             "%x color dis 0x%x basic mcs nss 0x%x",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "lim_log_he_op",
             *(_BYTE *)(a10 + 5) & 0x3F,
             v11 & 7,
             (v11 >> 3) & 1,
             (v11 >> 8) & 0x3FF,
             (v11 >> 18) & 1,
             (*(unsigned __int8 *)(a10 + 5) >> 6) & 1,
             (v11 >> 19) & 1,
             *(unsigned __int8 *)(a10 + 5) >> 7,
             *(unsigned __int16 *)(a10 + 6));
  v23 = *(_DWORD *)(a10 + 1);
  if ( (*(_BYTE *)(a11 + 8764) & 1) == 0 && (v23 & 0x40000) != 0 )
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: VHT Info: ch_bw %d cntr_freq0 %d cntr_freq1 %d",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "lim_log_he_op",
             *(unsigned __int8 *)(a10 + 8),
             *(unsigned __int8 *)(a10 + 9),
             *(unsigned __int8 *)(a10 + 10));
  if ( (v23 & 0x200000) != 0 )
  {
    LODWORD(v24) = *(unsigned __int8 *)(a10 + 16);
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: 6G_op_info:ch_bw %d cntr_freq0 %d cntr_freq1 %d dup_bcon %d, min_rate %d",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "lim_log_he_op",
             *(_BYTE *)(a10 + 13) & 3,
             *(unsigned __int8 *)(a10 + 14),
             *(unsigned __int8 *)(a10 + 15),
             (*(unsigned __int8 *)(a10 + 13) >> 2) & 1,
             v24);
  }
  return result;
}
