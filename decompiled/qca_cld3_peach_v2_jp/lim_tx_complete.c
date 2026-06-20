__int64 __fastcall lim_tx_complete(__int64 a1, __int64 a2, char a3)
{
  if ( (a3 & 1) != 0 )
    cds_packet_free(a2);
  return 0;
}
