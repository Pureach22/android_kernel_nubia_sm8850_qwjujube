double __fastcall dsi_ctrl_hw_22_setup_lane_map(__int64 a1, unsigned __int8 *a2)
{
  int v3; // w4
  int v4; // w5
  int v5; // w4

  if ( *(_DWORD *)(a1 - 8) )
  {
    if ( a1 )
      v3 = *(_DWORD *)(a1 + 56);
    else
      v3 = -1;
    return _drm_dev_dbg(
             0,
             0,
             0,
             "[msm-dsi-debug]: DSI_%d: DSI controller version is >=2.2, lane swap is performed through PHY",
             v3);
  }
  else
  {
    writel_relaxed_17(a2[4] | (16 * a2[5]) | (a2[6] << 8) | (a2[7] << 12), *(_QWORD *)a1 + 784LL);
    if ( a1 )
    {
      v4 = *(_DWORD *)(a1 + 56);
      v5 = v4;
    }
    else
    {
      v5 = -1;
      v4 = 2747744;
    }
    return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: [DSI_%d] Lane swap setup complete\n", v5, v4);
  }
}
