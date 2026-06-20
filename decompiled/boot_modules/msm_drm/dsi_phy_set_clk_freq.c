__int64 __fastcall dsi_phy_set_clk_freq(__int64 a1, _DWORD *a2)
{
  int v2; // w4
  int v3; // w6
  int v5; // w3

  if ( a1 && a2 )
  {
    v2 = *(_DWORD *)(a1 + 8);
    v3 = *(_DWORD *)(a1 + 1356);
    *(_BYTE *)(a1 + 1360) = 1;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: lane_datarate=%u min_datarate=%u required=%d\n", v2, 8 * *a2, v3, 1);
    return 0;
  }
  else
  {
    if ( a1 )
      v5 = *(_DWORD *)(a1 + 8);
    else
      v5 = -1;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Invalid params\n", v5);
    return 4294967274LL;
  }
}
