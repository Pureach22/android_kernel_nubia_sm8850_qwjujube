double __fastcall dsi_ctrl_hw_cmn_cmd_test_pattern_setup(_DWORD *a1, int a2, unsigned int a3, unsigned int a4)
{
  int v4; // w21
  __int64 v5; // x22
  unsigned int v8; // w0
  int v9; // w4
  double result; // d0

  if ( a4 <= 2 )
  {
    v4 = dword_28FF90[a4];
    v5 = (__int64)*(&off_28FFA0 + a4);
    writel_relaxed_16(a3, (unsigned int *)((char *)*(&off_28FFB8 + a4) + *(_QWORD *)a1));
    v8 = 0;
    if ( a2 > 1 )
    {
      if ( a2 == 2 )
      {
        writel_relaxed_16(0xF0F0Fu, (unsigned int *)(*(_QWORD *)a1 + v5));
        v8 = 0;
      }
      else if ( a2 == 3 )
      {
        v8 = 3 << v4;
      }
    }
    else if ( a2 )
    {
      if ( a2 == 1 )
        v8 = 1 << v4;
    }
    else
    {
      v8 = 2 << v4;
    }
    writel_relaxed_16(v8, (unsigned int *)(*(_QWORD *)a1 + 348LL));
    if ( a1 )
      v9 = a1[14];
    else
      v9 = -1;
    return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Cmd test pattern setup done\n", v9);
  }
  return result;
}
