size_t __fastcall dsi_ctrl_hw_cmn_set_timing_db(int *a1, char a2)
{
  int v4; // w4
  int v5; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  writel_relaxed_16(a2 & 1, (unsigned int *)(*(_QWORD *)a1 + 488LL));
  __dsb(0xEu);
  if ( a1 )
    v4 = a1[14];
  else
    v4 = -1;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: ctrl timing DB set:%d\n", v4, a2 & 1);
  return sde_evtlog_log(
           sde_dbg_base_evtlog,
           "dsi_ctrl_hw_cmn_set_timing_db",
           416,
           -1,
           a1[14],
           a2 & 1,
           -1059143953,
           v5,
           vars0);
}
