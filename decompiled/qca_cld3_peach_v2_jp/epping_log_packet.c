_QWORD *__fastcall epping_log_packet(
        _QWORD *result,
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
  if ( (*(_WORD *)(a2 + 40) & 8) != 0 )
    return (_QWORD *)qdf_trace_msg(
                       0x33u,
                       1u,
                       "%s: cmd = %d, seqNo = %u, flag = 0x%x, ret = %d, txCount = %lu, txDrop =  %lu, txBytes = %lu,rxCo"
                       "unt = %lu, rxDrop = %lu, rxBytes = %lu\n",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       result[18],
                       result[24],
                       result[20],
                       result[17],
                       result[23],
                       result[19]);
  return result;
}
