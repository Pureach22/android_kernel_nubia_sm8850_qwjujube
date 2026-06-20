__int64 __fastcall drm_edp_backlight_set_level(const char **a1, __int64 a2, __int16 a3)
{
  unsigned int v3; // w8
  char v4; // w9
  char v5; // w8
  int v7; // w0
  const char *v9; // x9
  const char **v10; // x8
  int v11; // w19
  __int64 v12; // x0
  __int16 v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v3 = 0;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_BYTE *)(a2 + 4);
  v13 = 0;
  if ( (v4 & 4) != 0 )
  {
    if ( (v4 & 1) != 0 )
    {
      v5 = HIBYTE(a3);
      HIBYTE(v13) = a3;
    }
    else
    {
      v5 = a3;
    }
    LOBYTE(v13) = v5;
    v7 = drm_dp_dpcd_write(a1, 0x722u, (__int64)&v13, 2);
    if ( v7 == 2 )
    {
      v3 = 0;
    }
    else
    {
      v9 = a1[157];
      v10 = a1;
      v11 = v7;
      if ( v9 )
        v12 = *((_QWORD *)v9 + 1);
      else
        v12 = 0;
      dev_err(v12, "[drm] *ERROR* %s: Failed to write aux backlight level: %d\n", *v10, v11);
      if ( v11 >= 0 )
        v3 = -5;
      else
        v3 = v11;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
