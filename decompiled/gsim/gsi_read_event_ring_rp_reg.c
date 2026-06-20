__int64 __fastcall gsi_read_event_ring_rp_reg(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  __int64 reg_nk; // x21

  reg_nk = (unsigned int)gsihal_read_reg_nk(71, a3, a2);
  return reg_nk | (gsihal_read_reg_nk(72, a3, a2) << 32);
}
