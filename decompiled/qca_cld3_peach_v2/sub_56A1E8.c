__int64 __fastcall sub_56A1E8(int a1, int a2, int a3)
{
  __int16 v3; // w13

  if ( (v3 & 0x2000) != 0 )
    JUMPOUT(0x56BCD4);
  return dp_tx_latency_stats_fetch(a1, a2, a3);
}
