__int64 __fastcall dsi_ctrl_hw_cmn_get_lanes_in_ulps(unsigned int *a1)
{
  __int16 v2; // w0
  __int64 v3; // x4
  int v4; // w9
  unsigned int v5; // w19

  v2 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 168LL));
  if ( a1 )
    v3 = a1[14];
  else
    v3 = 0xFFFFFFFFLL;
  if ( (v2 & 0x100) != 0 )
    v4 = 2;
  else
    v4 = 3;
  if ( (v2 & 0x200) != 0 )
    v4 = (v2 & 0x100) == 0;
  if ( (v2 & 0x400) == 0 )
    v4 |= 4u;
  if ( (v2 & 0x800) == 0 )
    v4 |= 8u;
  if ( (v2 & 0x1000) != 0 )
    v5 = v4;
  else
    v5 = v4 | 0x10;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: lanes in ulps = 0x%x\n", v3, v5);
  return v5;
}
