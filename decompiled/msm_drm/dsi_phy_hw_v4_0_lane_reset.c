__int64 __fastcall dsi_phy_hw_v4_0_lane_reset(_DWORD *a1)
{
  int v2; // w8
  int v3; // w21
  int v4; // w22
  int v5; // w4
  int v6; // w4

  v2 = 9;
  do
  {
    v3 = v2;
    writel_relaxed_10(0x1Fu, (unsigned int *)(*(_QWORD *)a1 + 172LL));
    __dsb(0xEu);
    _const_udelay(859000);
    v4 = readl_relaxed_13((unsigned int *)(*(_QWORD *)a1 + 332LL));
    if ( a1 )
      v5 = a1[7];
    else
      v5 = -1;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: trial no: %d\n", v5, v3);
    v2 = v3 - 1;
  }
  while ( v4 != 31 && v3 );
  if ( !v3 )
  {
    if ( a1 )
      v6 = a1[7];
    else
      v6 = -1;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: could not reset phy lanes\n", v6);
  }
  writel_relaxed_10(0, (unsigned int *)(*(_QWORD *)a1 + 172LL));
  __dsb(0xEu);
  return 0;
}
