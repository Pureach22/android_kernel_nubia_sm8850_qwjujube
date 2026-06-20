double __fastcall dsi_ctrl_hw_cmn_video_engine_en(_DWORD *a1, char a2)
{
  int v4; // w10
  int v5; // w8
  int v6; // w4

  v4 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 4LL)) & 0xFFFFFFFD;
  if ( (a2 & 1) != 0 )
    v5 = 2;
  else
    v5 = 0;
  writel_relaxed_16(v4 | v5, (unsigned int *)(*(_QWORD *)a1 + 4LL));
  if ( a1 )
    v6 = a1[14];
  else
    v6 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Video engine = %d\n", v6, a2 & 1);
}
