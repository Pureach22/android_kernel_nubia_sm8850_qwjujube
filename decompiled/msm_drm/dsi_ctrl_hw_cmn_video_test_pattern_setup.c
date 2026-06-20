double __fastcall dsi_ctrl_hw_cmn_video_test_pattern_setup(_DWORD *a1, int a2, unsigned int a3)
{
  unsigned int v5; // w20
  int v6; // w4

  writel_relaxed_16(a3, (unsigned int *)(*(_QWORD *)a1 + 356LL));
  v5 = 0;
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      writel_relaxed_16(0xF0F0Fu, (unsigned int *)(*(_QWORD *)a1 + 352LL));
      v5 = 0;
    }
    else if ( a2 == 3 )
    {
      v5 = 48;
    }
  }
  else if ( a2 )
  {
    if ( a2 == 1 )
      v5 = 16;
  }
  else
  {
    v5 = 32;
  }
  writel_relaxed_16(0x100u, (unsigned int *)(*(_QWORD *)a1 + 412LL));
  writel_relaxed_16(5u, (unsigned int *)(*(_QWORD *)a1 + 420LL));
  writel_relaxed_16(v5, (unsigned int *)(*(_QWORD *)a1 + 348LL));
  if ( a1 )
    v6 = a1[14];
  else
    v6 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Video test pattern setup done\n", v6);
}
