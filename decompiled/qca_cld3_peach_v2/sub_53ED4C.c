__int64 __fastcall sub_53ED4C(__int64 a1, __int64 a2)
{
  int v2; // w28

  if ( (v2 & 0x2000000) != 0 )
    JUMPOUT(0x53BC88);
  return dp_rx_check_pkt_len(a1, a2);
}
