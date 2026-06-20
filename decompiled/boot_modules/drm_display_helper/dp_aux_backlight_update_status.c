__int64 __fastcall dp_aux_backlight_update_status(int *a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  unsigned int v3; // w2
  const char **v4; // x8
  char v5; // w9
  const char **v6; // x19
  int v7; // w0
  const char *v8; // x9
  const char **v9; // x8
  int v10; // w19
  __int64 v11; // x0
  __int16 v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *((_QWORD *)a1 + 40);
  if ( a1[2] || (a1[4] & 3) != 0 )
  {
    if ( *(_BYTE *)(v1 + 22) == 1 )
    {
      drm_edp_backlight_set_enable(*(__int64 **)(v1 + 8), v1 + 16, 0);
      result = 0;
      *(_BYTE *)(v1 + 22) = 0;
      goto LABEL_11;
    }
LABEL_10:
    result = 0;
    goto LABEL_11;
  }
  v3 = *a1;
  v4 = *(const char ***)(v1 + 8);
  if ( (*(_BYTE *)(v1 + 22) & 1) == 0 )
  {
    drm_edp_backlight_enable(*(const char ***)(v1 + 8), (char *)(v1 + 16), v3);
    result = 0;
    *(_BYTE *)(v1 + 22) = 1;
    goto LABEL_11;
  }
  v5 = *(_BYTE *)(v1 + 20);
  result = 0;
  v12 = 0;
  if ( (v5 & 4) != 0 )
  {
    if ( (v5 & 1) != 0 )
    {
      HIBYTE(v12) = v3;
      v3 >>= 8;
    }
    LOBYTE(v12) = v3;
    v6 = v4;
    v7 = drm_dp_dpcd_write(v4, 0x722u, (__int64)&v12, 2);
    if ( v7 == 2 )
      goto LABEL_10;
    v8 = v6[157];
    v9 = v6;
    v10 = v7;
    if ( v8 )
      v11 = *((_QWORD *)v8 + 1);
    else
      v11 = 0;
    dev_err(v11, "[drm] *ERROR* %s: Failed to write aux backlight level: %d\n", *v9, v10);
    if ( v10 >= 0 )
      result = 4294967291LL;
    else
      result = (unsigned int)v10;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
