void __fastcall dsi_phy_hw_v3_0_update_timing_params(__int64 a1, unsigned __int8 *a2)
{
  int v2; // w5
  int v4; // w6
  int v5; // w7
  unsigned __int8 v6; // w9

  *(_BYTE *)(a1 + 40) = 0;
  v2 = a2[44];
  *(_BYTE *)(a1 + 41) = v2;
  v4 = a2[20];
  *(_BYTE *)(a1 + 42) = v4;
  v5 = a2[68];
  *(_BYTE *)(a1 + 43) = v5;
  *(_BYTE *)(a1 + 44) = a2[212];
  *(_BYTE *)(a1 + 45) = a2[116];
  *(_BYTE *)(a1 + 46) = a2[92];
  *(_BYTE *)(a1 + 47) = a2[140];
  v6 = a2[164];
  *(_WORD *)(a1 + 49) = 1026;
  *(_BYTE *)(a1 + 51) = 0;
  *(_BYTE *)(a1 + 48) = v6;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%d %d %d %d]\n", 0, v2, v4, v5);
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: [%d %d %d %d]\n",
    *(unsigned __int8 *)(a1 + 44),
    *(unsigned __int8 *)(a1 + 45),
    *(unsigned __int8 *)(a1 + 46),
    *(unsigned __int8 *)(a1 + 47));
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: [%d %d %d %d]\n",
    *(unsigned __int8 *)(a1 + 48),
    *(unsigned __int8 *)(a1 + 49),
    *(unsigned __int8 *)(a1 + 50),
    *(unsigned __int8 *)(a1 + 51));
  *(_DWORD *)(a1 + 68) = 12;
}
