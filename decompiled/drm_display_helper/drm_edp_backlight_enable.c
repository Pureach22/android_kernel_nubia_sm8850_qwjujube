__int64 __fastcall drm_edp_backlight_enable(const char **a1, char *a2, __int16 a3)
{
  int v6; // w22
  int v7; // w5
  const char *v8; // x8
  __int64 v9; // x1
  int v10; // w5
  const char *v11; // x8
  __int64 v12; // x1
  int v13; // w22
  char v14; // w8
  char v15; // w8
  const char *v16; // x8
  __int64 v17; // x1
  __int64 result; // x0
  int v19; // w0
  int v20; // w0
  const char *v21; // x9
  int v22; // w8
  __int64 v23; // x0
  const char *v24; // x2
  int v25; // w19
  char v26[4]; // [xsp+8h] [xbp-18h] BYREF
  char v27[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v28[4]; // [xsp+10h] [xbp-10h] BYREF
  __int16 v29; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = ((unsigned __int8)a2[4] >> 1) & 2;
  if ( *a2 )
  {
    v26[0] = *a2;
    v7 = drm_dp_dpcd_write(a1, 0x724u, (__int64)v26, 1);
    if ( v7 != 1 )
    {
      v8 = a1[157];
      if ( v8 )
        v9 = *((_QWORD *)v8 + 1);
      else
        v9 = 0;
      _drm_dev_dbg(0, v9, 2, "%s: Failed to write aux pwmgen bit count: %d\n", *a1, v7);
    }
  }
  if ( a2[1] )
  {
    v27[0] = a2[1];
    v10 = drm_dp_dpcd_write(a1, 0x728u, (__int64)v27, 1);
    if ( v10 == 1 )
    {
      LOBYTE(v6) = v6 | 8;
    }
    else
    {
      v11 = a1[157];
      if ( v11 )
        v12 = *((_QWORD *)v11 + 1);
      else
        v12 = 0;
      _drm_dev_dbg(0, v12, 2, "%s: Failed to write aux backlight frequency: %d\n", *a1, v10);
    }
  }
  v28[0] = v6;
  v13 = drm_dp_dpcd_write(a1, 0x721u, (__int64)v28, 1);
  if ( v13 == 1 )
  {
    v14 = a2[4];
    v29 = 0;
    if ( (v14 & 4) != 0
      && ((v14 & 1) == 0 ? (v15 = a3) : (v15 = HIBYTE(a3), HIBYTE(v29) = a3),
          LOBYTE(v29) = v15,
          v19 = drm_dp_dpcd_write(a1, 0x722u, (__int64)&v29, 2),
          v19 != 2) )
    {
      v21 = a1[157];
      v22 = v19;
      if ( v21 )
        v23 = *((_QWORD *)v21 + 1);
      else
        v23 = 0;
      v24 = *a1;
      v25 = v22;
      dev_err(v23, "[drm] *ERROR* %s: Failed to write aux backlight level: %d\n", v24, v22);
      if ( v25 >= 0 )
        result = 4294967291LL;
      else
        result = (unsigned int)v25;
    }
    else
    {
      v20 = drm_edp_backlight_set_enable(a1, a2, 1);
      result = v20 & (unsigned int)(v20 >> 31);
    }
  }
  else
  {
    v16 = a1[157];
    if ( v16 )
      v17 = *((_QWORD *)v16 + 1);
    else
      v17 = 0;
    _drm_dev_dbg(0, v17, 2, "%s: Failed to write aux backlight mode: %d\n", *a1, v13);
    if ( v13 >= 0 )
      result = 4294967291LL;
    else
      result = (unsigned int)v13;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
