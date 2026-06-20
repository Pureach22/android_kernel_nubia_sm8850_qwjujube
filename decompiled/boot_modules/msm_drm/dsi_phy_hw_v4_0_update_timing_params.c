void __fastcall dsi_phy_hw_v4_0_update_timing_params(__int64 a1, _BYTE *a2, int a3)
{
  int v4; // w7
  int v5; // w6
  int v6; // w5
  char v7; // w9
  char v8; // w9

  if ( a3 == 1 )
  {
    *(_DWORD *)(a1 + 52) = 0;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    *(_BYTE *)(a1 + 56) = a2[212];
    *(_BYTE *)(a1 + 57) = a2[332];
    *(_BYTE *)(a1 + 58) = a2[20];
    *(_BYTE *)(a1 + 59) = a2[308];
    v7 = a2[164];
    *(_WORD *)(a1 + 61) = 1026;
    *(_BYTE *)(a1 + 63) = 0;
    *(_BYTE *)(a1 + 60) = v7;
  }
  else
  {
    *(_BYTE *)(a1 + 52) = 0;
    v6 = (unsigned __int8)a2[44];
    *(_BYTE *)(a1 + 53) = v6;
    v5 = (unsigned __int8)a2[20];
    *(_BYTE *)(a1 + 54) = v5;
    v4 = (unsigned __int8)a2[68];
    *(_BYTE *)(a1 + 55) = v4;
    *(_BYTE *)(a1 + 56) = a2[212];
    *(_BYTE *)(a1 + 57) = a2[116];
    *(_BYTE *)(a1 + 58) = a2[92];
    *(_BYTE *)(a1 + 59) = a2[140];
    v8 = a2[164];
    *(_WORD *)(a1 + 61) = 1026;
    *(_BYTE *)(a1 + 63) = 0;
    *(_BYTE *)(a1 + 60) = v8;
    *(_BYTE *)(a1 + 64) = a2[332];
    *(_BYTE *)(a1 + 65) = a2[308];
  }
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%d %d %d %d]\n", 0, v6, v5, v4);
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: [%d %d %d %d]\n",
    *(unsigned __int8 *)(a1 + 56),
    *(unsigned __int8 *)(a1 + 57),
    *(unsigned __int8 *)(a1 + 58),
    *(unsigned __int8 *)(a1 + 59));
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: [%d %d %d %d]\n",
    *(unsigned __int8 *)(a1 + 60),
    *(unsigned __int8 *)(a1 + 61),
    *(unsigned __int8 *)(a1 + 62),
    *(unsigned __int8 *)(a1 + 63));
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%d %d]\n", *(unsigned __int8 *)(a1 + 64), *(unsigned __int8 *)(a1 + 65));
  *(_DWORD *)(a1 + 68) = 14;
}
