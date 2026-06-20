__int64 __fastcall dsi_ctrl_hw_cmn_phy_reset_config(__int64 a1, char a2)
{
  int v4; // w10
  int v5; // w8

  v4 = readl_relaxed_19((unsigned int *)(*(_QWORD *)(a1 + 16) + 20LL)) & 0xBFFFFFFF;
  if ( (a2 & 1) != 0 )
    v5 = 0x40000000;
  else
    v5 = 0;
  return writel_relaxed_16(v4 | (unsigned int)v5, (unsigned int *)(*(_QWORD *)(a1 + 16) + 20LL));
}
