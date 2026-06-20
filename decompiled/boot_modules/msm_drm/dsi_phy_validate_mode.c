__int64 __fastcall dsi_phy_validate_mode(__int64 a1, __int64 a2)
{
  int v3; // w3

  if ( a1 && a2 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Skipping validation\n", *(_DWORD *)(a1 + 8));
    return 0;
  }
  else
  {
    if ( a1 )
      v3 = *(_DWORD *)(a1 + 8);
    else
      v3 = -1;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Invalid params\n", v3);
    return 4294967274LL;
  }
}
