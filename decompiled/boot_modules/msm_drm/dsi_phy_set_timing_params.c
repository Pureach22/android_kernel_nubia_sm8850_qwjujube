__int64 __fastcall dsi_phy_set_timing_params(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  __int64 v8; // x0
  __int64 v9; // x8
  _DWORD *v10; // x8
  unsigned int v11; // w21
  __int64 v12; // x8
  void (__fastcall *v13)(__int64, __int64); // x8
  int v14; // w3

  if ( !a1 || !a2 || !a3 )
  {
    if ( a1 )
      v14 = *(_DWORD *)(a1 + 8);
    else
      v14 = -1;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Invalid params\n", v14);
    return (unsigned int)-22;
  }
  v8 = mutex_lock(a1 + 32);
  v9 = *(unsigned int *)(a1 + 776);
  if ( (unsigned int)v9 < 3 )
  {
    v10 = *(_DWORD **)(a1 + 8 * v9 + 312);
    if ( !v10 )
      goto LABEL_9;
    if ( *(v10 - 1) != -963459099 )
      __break(0x8228u);
    v8 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v10)(a1 + 960, a2, a3);
    v11 = v8;
    if ( !(_DWORD)v8 )
    {
LABEL_9:
      v11 = 0;
      *(_BYTE *)(a1 + 1032) = 1;
    }
    v12 = *(unsigned int *)(a1 + 776);
    if ( (unsigned int)v12 <= 2 )
    {
      v13 = *(void (__fastcall **)(__int64, __int64))(a1 + 8 * v12 + 456);
      if ( v13 && (a4 & 1) != 0 )
      {
        if ( *((_DWORD *)v13 - 1) != -561327747 )
          __break(0x8228u);
        v13(a1 + 88, a1 + 960);
      }
      mutex_unlock(a1 + 32);
      return v11;
    }
  }
  __break(0x5512u);
  return dsi_phy_conv_phy_to_logical_lane(v8);
}
