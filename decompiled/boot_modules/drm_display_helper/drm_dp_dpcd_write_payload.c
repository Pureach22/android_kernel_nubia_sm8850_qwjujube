__int64 __fastcall drm_dp_dpcd_write_payload(__int64 a1, char a2, char a3, char a4)
{
  _QWORD *v8; // x0
  _QWORD *v9; // x0
  unsigned int v10; // w0
  unsigned int v11; // w20
  int v12; // w21
  __int64 v13; // x8
  __int64 v14; // x1
  __int64 v15; // x8
  __int64 v16; // x1
  __int64 v18; // x8
  __int64 v19; // x1
  _BYTE v20[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v21[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v22[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD **)(a1 + 128);
  v20[0] = 0;
  v21[0] = 1;
  drm_dp_dpcd_write(v8, 0x2C0u, (__int64)v21, 1);
  v9 = *(_QWORD **)(a1 + 128);
  v22[0] = a2;
  v22[1] = a3;
  v22[2] = a4;
  v10 = drm_dp_dpcd_write(v9, 0x1C0u, (__int64)v22, 3);
  if ( v10 == 3 )
  {
    v11 = drm_dp_dpcd_read(*(_QWORD **)(a1 + 128), 0x2C0u, (__int64)v20, 1);
    if ( (v11 & 0x80000000) != 0 )
    {
LABEL_7:
      v13 = *(_QWORD *)(a1 + 104);
      if ( v13 )
        v14 = *(_QWORD *)(v13 + 8);
      else
        v14 = 0;
      _drm_dev_dbg(0, v14, 2, "failed to read payload table status %d\n", v11);
    }
    else
    {
      v12 = 20;
      while ( 1 )
      {
        if ( (v20[0] & 1) != 0 )
        {
          v11 = 0;
          goto LABEL_15;
        }
        if ( !--v12 )
          break;
        usleep_range_state(10000, 20000, 2);
        v11 = drm_dp_dpcd_read(*(_QWORD **)(a1 + 128), 0x2C0u, (__int64)v20, 1);
        if ( (v11 & 0x80000000) != 0 )
          goto LABEL_7;
      }
      v18 = *(_QWORD *)(a1 + 104);
      if ( v18 )
        v19 = *(_QWORD *)(v18 + 8);
      else
        v19 = 0;
      _drm_dev_dbg(0, v19, 2, "status not set after read payload table status %d\n", v20[0]);
      v11 = -22;
    }
  }
  else
  {
    v15 = *(_QWORD *)(a1 + 104);
    v11 = v10;
    if ( v15 )
      v16 = *(_QWORD *)(v15 + 8);
    else
      v16 = 0;
    _drm_dev_dbg(0, v16, 2, "failed to write payload allocation %d\n", v10);
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v11;
}
