__int64 __fastcall spi_master_setup(__int64 a1)
{
  __int64 result; // x0

  writel_relaxed(0x19E1u, (unsigned int *)(*(_QWORD *)(a1 + 184) + 576LL));
  result = writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 + 184) + 132LL));
  __dsb(0xEu);
  return result;
}
