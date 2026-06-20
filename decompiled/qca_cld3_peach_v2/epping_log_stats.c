__int64 __fastcall epping_log_stats(
        _QWORD *a1,
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
  int v11; // [xsp+10h] [xbp-10h]

  v11 = *(_DWORD *)(*a1 + 116LL);
  return qdf_trace_msg(
           0x33u,
           1u,
           "%s: txCount = %lu, txDrop = %lu, tx_bytes = %lu, rxCount = %lu, rxDrop = %lu, rx_bytes = %lu, tx_acks = %u\n",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a2,
           a1[18],
           a1[24],
           a1[20],
           a1[17],
           a1[23],
           a1[19],
           v11);
}
