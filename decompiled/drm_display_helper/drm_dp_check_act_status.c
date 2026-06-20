__int64 __fastcall drm_dp_check_act_status(__int64 a1)
{
  __int64 v2; // x21
  _QWORD *v3; // x0
  int v4; // w0
  unsigned int v5; // w20
  __int64 v6; // x21
  _QWORD *v7; // x0
  int v8; // w0
  _QWORD *v9; // x0
  int v10; // w0
  __int64 v11; // x8
  __int64 v12; // x1
  __int64 v14; // x8
  __int64 v15; // x0
  _BYTE v16[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v17[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ktime_get();
  v3 = *(_QWORD **)(a1 + 128);
  v16[0] = 0;
  v4 = drm_dp_dpcd_read(v3, 0x2C0u, (__int64)v16, 1);
  if ( v4 >= 0 )
    v5 = v16[0];
  else
    v5 = v4;
  if ( (v5 & 0x80000002) == 0 )
  {
    v6 = v2 + 3000000000LL;
    while ( ktime_get() <= v6 )
    {
      usleep_range_state(51, 200, 2);
      __yield();
      v7 = *(_QWORD **)(a1 + 128);
      v16[0] = 0;
      v8 = drm_dp_dpcd_read(v7, 0x2C0u, (__int64)v16, 1);
      if ( v8 >= 0 )
        v5 = v16[0];
      else
        v5 = v8;
      if ( (v5 & 0x80000002) != 0 )
        goto LABEL_15;
    }
    v9 = *(_QWORD **)(a1 + 128);
    v17[0] = 0;
    v10 = drm_dp_dpcd_read(v9, 0x2C0u, (__int64)v17, 1);
    if ( v10 >= 0 )
      v5 = v17[0];
    else
      v5 = v10;
  }
LABEL_15:
  if ( (v5 & 0x80000002) != 0 )
  {
    if ( (v5 & 0x80000000) != 0 )
    {
      v11 = *(_QWORD *)(a1 + 104);
      if ( v11 )
        v12 = *(_QWORD *)(v11 + 8);
      else
        v12 = 0;
      _drm_dev_dbg(0, v12, 2, "Failed to read payload table status: %d\n", v5);
    }
    else
    {
      v5 = 0;
    }
  }
  else
  {
    v14 = *(_QWORD *)(a1 + 104);
    if ( v14 )
      v15 = *(_QWORD *)(v14 + 8);
    else
      v15 = 0;
    dev_err(v15, "[drm] *ERROR* Failed to get ACT after %dms, last status: %02x\n", 3000, v5);
    v5 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
