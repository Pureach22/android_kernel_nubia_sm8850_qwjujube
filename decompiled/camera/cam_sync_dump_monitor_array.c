_DWORD *__fastcall cam_sync_dump_monitor_array(_DWORD *result)
{
  int v1; // w10
  __int64 v2; // x8
  int v3; // w9
  int v4; // w10
  __int64 v5; // x8
  int v6; // w12
  __int64 v7; // x8
  int v8; // w9
  int v9; // w11
  bool v10; // zf
  __int64 v11; // x10
  __int64 v12; // x9
  _DWORD *v13; // [xsp+8h] [xbp-48h] BYREF
  int v14; // [xsp+10h] [xbp-40h]
  int v15; // [xsp+14h] [xbp-3Ch]
  __int64 v16; // [xsp+18h] [xbp-38h]
  __int64 v17; // [xsp+20h] [xbp-30h]
  __int64 v18; // [xsp+28h] [xbp-28h]
  __int64 v19; // [xsp+30h] [xbp-20h]
  __int64 v20; // [xsp+38h] [xbp-18h]
  __int64 v21; // [xsp+40h] [xbp-10h]
  __int64 v22; // [xsp+48h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(sync_dev + 8672);
  if ( v2 )
  {
    if ( (cam_sync_monitor_mask & 2) != 0 )
    {
      v3 = result[17];
      v4 = v3 - (v1 & 0xFFFFFF80);
      v5 = *(_QWORD *)(v2 + 8LL * (v3 / 128));
      if ( *(_DWORD *)(v5 + 1616LL * v4 + 140) )
      {
        v6 = result[16];
        v17 = 0;
        v18 = 0;
        v14 = v6;
        v15 = v3;
        v16 = 0;
        v7 = v5 + 1616LL * v4;
        v9 = result[26];
        v8 = result[27];
        v13 = result;
        HIDWORD(v16) = v9;
        LODWORD(v17) = v8;
        v10 = *(_BYTE *)(v7 + 168) == 0;
        v11 = 896;
        HIDWORD(v17) = result[44];
        LODWORD(v18) = 1;
        if ( v10 )
          v12 = 176;
        else
          v12 = 896;
        if ( !v10 )
          v11 = 176;
        v19 = v7;
        v20 = v7 + v12;
        v21 = v7 + v11;
        result = (_DWORD *)cam_generic_fence_dump_monitor_array((__int64)&v13);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
