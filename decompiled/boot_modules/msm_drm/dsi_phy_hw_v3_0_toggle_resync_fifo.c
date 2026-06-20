__int64 __fastcall dsi_phy_hw_v3_0_toggle_resync_fifo(_QWORD *a1)
{
  __int64 result; // x0

  writel_relaxed_9(0, *a1 + 28LL);
  __dsb(0xEu);
  result = writel_relaxed_9(1, *a1 + 28LL);
  __dsb(0xEu);
  return result;
}
