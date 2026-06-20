double __fastcall dsi_phy_hw_v3_0_regulator_disable(__int64 a1)
{
  int v1; // w4

  if ( a1 )
    v1 = *(_DWORD *)(a1 + 28);
  else
    v1 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Phy regulators disabled\n", v1);
}
