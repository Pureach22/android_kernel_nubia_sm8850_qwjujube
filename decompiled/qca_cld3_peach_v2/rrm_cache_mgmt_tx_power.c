__int64 __fastcall rrm_cache_mgmt_tx_power(
        __int64 a1,
        char a2,
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
  __int64 result; // x0

  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: Cache Mgmt Tx Power: %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "rrm_cache_mgmt_tx_power",
             (unsigned int)a2);
  if ( a3 )
    *(_BYTE *)(a3 + 7040) = a2;
  else
    *(_BYTE *)(a1 + 20225) = a2;
  return result;
}
