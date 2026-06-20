__int64 __fastcall sde_dimming_bl_notify(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x21
  int v4; // w4
  unsigned int v5; // w5
  __int64 v6; // x8
  unsigned int v7; // w6
  unsigned int v8; // w7
  unsigned int v9; // w8
  __int64 v10; // x19
  __int64 v11; // [xsp+8h] [xbp-38h] BYREF
  __int64 v12; // [xsp+10h] [xbp-30h]
  unsigned __int64 v13; // [xsp+18h] [xbp-28h]
  unsigned __int64 v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h]
  _QWORD v16[2]; // [xsp+30h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v16[0] = 0;
    v11 = 0;
    v12 = 0;
    v13 = 0;
    v14 = 0;
    v15 = 0;
    if ( (_drm_debug & 4) != 0 )
    {
      v2 = result;
      v3 = a2;
      _drm_dev_dbg(
        0,
        0,
        0,
        "bl_config.dimming_status 0x%x user_disable_notify %d\n",
        *(_DWORD *)(a2 + 60),
        *(unsigned __int8 *)(a2 + 64));
      a2 = v3;
      result = v2;
    }
    if ( *(_BYTE *)(result + 4541) == 1 && (*(_BYTE *)(a2 + 64) & 1) == 0 )
    {
      v4 = *(_DWORD *)(a2 + 24);
      v5 = *(_DWORD *)(a2 + 28);
      v6 = *(_QWORD *)(a2 + 16);
      v7 = *(_DWORD *)(a2 + 32);
      LODWORD(v12) = *(_DWORD *)(a2 + 12);
      HIDWORD(v12) = v4;
      v11 = v6;
      v8 = *(_DWORD *)(a2 + 56);
      v9 = *(_DWORD *)(a2 + 60);
      v15 = 0x3FFFC00000400LL;
      v13 = __PAIR64__(v7, v5);
      v14 = __PAIR64__(v8, v9);
      v16[0] = 0x288000000DLL;
      if ( (_drm_debug & 4) != 0 )
      {
        v10 = result;
        _drm_dev_dbg(
          0,
          0,
          0,
          "dimming BL event bl_level %d bl_scale %d, bl_scale_sv = %d min_bl %d status 0x%x\n",
          v4,
          v5,
          v7,
          v8,
          v9);
        result = v10;
      }
      result = msm_mode_object_event_notify(result + 64, *(_QWORD *)result, v16, &v11);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
