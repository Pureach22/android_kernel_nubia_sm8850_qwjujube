__int64 __fastcall lim_fill_dfs_p2p_group_params(__int64 result)
{
  __int64 v1; // x19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  int v10; // w10
  __int16 v11; // w11
  _BYTE v12[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v13[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v14; // [xsp+10h] [xbp-10h] BYREF
  __int16 v15; // [xsp+14h] [xbp-Ch]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_DWORD *)(result + 7036) & 0xFFFFFFFE) == 2 )
  {
    v1 = result;
    v13[0] = 0;
    v12[0] = 0;
    v14 = 0;
    v15 = 0;
    qdf_mem_set((void *)(result + 10080), 0x2C8u, 0);
    result = wlan_reg_is_dfs_for_freq(
               *(_QWORD *)(*(_QWORD *)(v1 + 16) + 152LL),
               *(_DWORD *)(v1 + 284),
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9);
    if ( (result & 1) != 0 )
    {
      result = wlan_p2p_is_vdev_wfd_r2_mode(*(_QWORD *)(v1 + 16));
      if ( (result & 1) != 0 )
      {
        result = wlan_p2p_get_ap_assist_dfs_params(
                   *(_QWORD *)(v1 + 16),
                   v13,
                   v12,
                   nullptr,
                   (__int64)&v14,
                   nullptr,
                   nullptr);
        if ( (v13[0] & 1) == 0 && v12[0] == 1 )
        {
          v10 = v14;
          v11 = v15;
          *(_BYTE *)(v1 + 10080) |= 1u;
          *(_DWORD *)(v1 + 10081) = v10;
          *(_WORD *)(v1 + 10085) = v11;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
