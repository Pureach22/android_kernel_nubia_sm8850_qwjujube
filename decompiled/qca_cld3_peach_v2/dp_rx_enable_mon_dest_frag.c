__int64 __fastcall dp_rx_enable_mon_dest_frag(
        __int64 result,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  *(_BYTE *)(result + 77) = 0;
  if ( (a2 & 1) != 0 )
    return qdf_trace_msg(
             0x45u,
             8u,
             "%s: Feature DP_RX_MON_MEM_FRAG for mon_dest is disabled",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "dp_rx_enable_mon_dest_frag");
  return result;
}
