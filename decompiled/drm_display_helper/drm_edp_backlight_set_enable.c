__int64 __fastcall drm_edp_backlight_set_enable(__int64 *a1, __int64 a2, char a3)
{
  unsigned int v5; // w0
  unsigned int v6; // w0
  __int64 result; // x0
  __int64 v8; // x9
  unsigned int v9; // w8
  __int64 v10; // x0
  __int64 v11; // x9
  __int64 v12; // x2
  const char *v13; // x1
  int v14; // w19
  char v15[4]; // [xsp+0h] [xbp-10h] BYREF
  char v16[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a2 + 4) & 2) == 0 )
    goto LABEL_4;
  v15[0] = 0;
  v5 = drm_dp_dpcd_read(a1, 0x720u, (__int64)v15, 1);
  if ( v5 == 1 )
  {
    v15[0] = v15[0] & 0xFE | a3 & 1;
    v16[0] = v15[0];
    v6 = drm_dp_dpcd_write(a1, 0x720u, (__int64)v16, 1);
    if ( v6 == 1 )
    {
LABEL_4:
      result = 0;
      goto LABEL_5;
    }
    v11 = a1[157];
    v9 = v6;
    if ( v11 )
      v10 = *(_QWORD *)(v11 + 8);
    else
      v10 = 0;
    v12 = *a1;
    v13 = "[drm] *ERROR* %s: Failed to write eDP display control register: %d\n";
  }
  else
  {
    v8 = a1[157];
    v9 = v5;
    if ( v8 )
      v10 = *(_QWORD *)(v8 + 8);
    else
      v10 = 0;
    v12 = *a1;
    v13 = "[drm] *ERROR* %s: Failed to read eDP display control register: %d\n";
  }
  v14 = v9;
  dev_err(v10, v13, v12, v9);
  if ( v14 >= 0 )
    result = 4294967291LL;
  else
    result = (unsigned int)v14;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
