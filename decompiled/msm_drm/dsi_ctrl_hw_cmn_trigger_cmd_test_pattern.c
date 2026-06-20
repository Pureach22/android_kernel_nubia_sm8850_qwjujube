double __fastcall dsi_ctrl_hw_cmn_trigger_cmd_test_pattern(__int64 a1, unsigned int a2)
{
  int v3; // w4

  if ( a2 <= 2 )
    writel_relaxed_16(1u, (unsigned int *)((char *)*(&off_28FFD0 + a2) + *(_QWORD *)a1));
  if ( a1 )
    v3 = *(_DWORD *)(a1 + 56);
  else
    v3 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Cmd Test pattern trigger\n", v3);
}
