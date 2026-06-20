__int64 __fastcall sub_1C7BC(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (a4 & 0x200000000000000LL) == 0 )
    JUMPOUT(0x2096C);
  return gsi_read_event_ring_rp_reg();
}
