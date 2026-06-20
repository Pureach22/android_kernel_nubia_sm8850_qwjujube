double __fastcall dsi_ctrl_hw_cmn_test_pattern_enable(_DWORD *a1, char a2, char a3, int a4)
{
  int v8; // w23
  char v9; // w8
  __int64 v10; // x9
  int v11; // w4

  v8 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 348LL));
  if ( a4 == 2 )
    v9 = a3;
  else
    v9 = a3 + 1;
  v10 = 416;
  if ( a4 != 2 )
    v10 = 412;
  writel_relaxed_16(1LL << v9, (unsigned int *)(*(_QWORD *)a1 + v10));
  writel_relaxed_16(5u, (unsigned int *)(*(_QWORD *)a1 + 420LL));
  writel_relaxed_16(v8 & 0xFFFFFFFE | a2 & 1, (unsigned int *)(*(_QWORD *)a1 + 348LL));
  if ( a1 )
    v11 = a1[14];
  else
    v11 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Test pattern enable=%d\n", v11, a2 & 1);
}
