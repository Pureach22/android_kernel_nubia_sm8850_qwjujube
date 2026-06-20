double __fastcall dsi_ctrl_hw_cmn_phy_sw_reset(_DWORD *a1)
{
  int v2; // w4

  writel_relaxed_16(0x1000001u, (unsigned int *)(*(_QWORD *)a1 + 300LL));
  __dsb(0xEu);
  _const_udelay(4295000);
  writel_relaxed_16(0, (unsigned int *)(*(_QWORD *)a1 + 300LL));
  __dsb(0xEu);
  _const_udelay(429500);
  if ( a1 )
    v2 = a1[14];
  else
    v2 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: phy sw reset done\n", v2);
}
