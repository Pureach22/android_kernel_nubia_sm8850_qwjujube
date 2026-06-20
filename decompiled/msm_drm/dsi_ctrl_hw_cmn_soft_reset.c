size_t __fastcall dsi_ctrl_hw_cmn_soft_reset(int *a1)
{
  unsigned int v2; // w20
  unsigned int v3; // w21
  int v4; // w4
  int v5; // w6
  int v6; // w7
  char v8; // [xsp+0h] [xbp+0h]

  v2 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 4LL));
  writel_relaxed_16(v2 & 0xFFFFFFF8, (unsigned int *)(*(_QWORD *)a1 + 4LL));
  __dsb(0xEu);
  v3 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 284LL));
  writel_relaxed_16(v3 | 0x200B3F, (unsigned int *)(*(_QWORD *)a1 + 284LL));
  __dsb(0xEu);
  writel_relaxed_16(1u, (unsigned int *)(*(_QWORD *)a1 + 280LL));
  __dsb(0xEu);
  _const_udelay(4295);
  writel_relaxed_16(0, (unsigned int *)(*(_QWORD *)a1 + 280LL));
  __dsb(0xEu);
  writel_relaxed_16(v3, (unsigned int *)(*(_QWORD *)a1 + 284LL));
  __dsb(0xEu);
  writel_relaxed_16(v2, (unsigned int *)(*(_QWORD *)a1 + 4LL));
  __dsb(0xEu);
  if ( a1 )
    v4 = a1[14];
  else
    v4 = -1;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: ctrl soft reset done\n", v4);
  return sde_evtlog_log(sde_dbg_base_evtlog, "dsi_ctrl_hw_cmn_soft_reset", 334, -1, a1[14], -1059143953, v5, v6, v8);
}
