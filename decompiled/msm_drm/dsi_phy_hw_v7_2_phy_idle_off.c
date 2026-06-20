__int64 __fastcall dsi_phy_hw_v7_2_phy_idle_off(__int64 a1, __int64 a2)
{
  char v4; // w0
  int v5; // w0
  __int64 v7; // x1

  if ( (*(_BYTE *)(a1 + 32) & 1) == 0 )
  {
    v4 = readl_relaxed_15((unsigned int *)(*(_QWORD *)a1 + 60LL));
    __dsb(0xFu);
    if ( (v4 & 1) != 0 )
    {
      if ( a1 )
        v7 = *(unsigned int *)(a1 + 28);
      else
        v7 = 0xFFFFFFFFLL;
      printk(&unk_25FC9D, v7);
    }
  }
  writel_relaxed_12(1u, (unsigned int *)(*(_QWORD *)a1 + 276LL));
  writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + 48LL));
  __dsb(0xEu);
  v5 = dsi_phy_conv_logical_to_phy_lane(a2 + 296, 0);
  writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + (v5 << 7) + 532));
  writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + 428LL));
  __dsb(0xEu);
  return _const_udelay(8590);
}
