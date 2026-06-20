__int64 __fastcall dsi_phy_hw_v7_2_toggle_resync_fifo(__int64 a1)
{
  __int64 result; // x0

  writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + 28LL));
  __dsb(0xEu);
  result = writel_relaxed_12(1u, (unsigned int *)(*(_QWORD *)a1 + 28LL));
  __dsb(0xEu);
  return result;
}
