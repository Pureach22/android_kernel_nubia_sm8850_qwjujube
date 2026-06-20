__int64 __fastcall gsi_read_event_ring_rp_ddr(__int64 a1)
{
  return (unsigned int)readl_relaxed(*(_QWORD *)(a1 + 80));
}
