__int64 __fastcall drm_dp_send_real_edid_checksum(const char **a1, char a2)
{
  int v3; // w8
  unsigned int v4; // w20
  const char *v5; // x8
  __int64 v6; // x0
  const char *v7; // x8
  __int64 v8; // x1
  const char *v9; // x8
  __int64 v10; // x0
  const char *v11; // x8
  __int64 v12; // x0
  const char *v13; // x8
  __int64 v14; // x0
  const char *v15; // x8
  __int64 v16; // x0
  char v18[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v19[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v20[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v21[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = a2;
  v20[0] = 0;
  v19[0] = 0;
  v18[0] = 0;
  if ( drm_dp_dpcd_read(a1, 0x201u, (__int64)v19, 1) <= 0 )
  {
    v9 = a1[157];
    if ( v9 )
      v10 = *((_QWORD *)v9 + 1);
    else
      v10 = 0;
    dev_err(v10, "[drm] *ERROR* %s: DPCD failed read at register 0x%x\n", *a1, 513);
    goto LABEL_32;
  }
  v19[0] &= 2u;
  if ( drm_dp_dpcd_read(a1, 0x218u, (__int64)v20, 1) <= 0 )
  {
    v11 = a1[157];
    if ( v11 )
      v12 = *((_QWORD *)v11 + 1);
    else
      v12 = 0;
    dev_err(v12, "[drm] *ERROR* %s: DPCD failed read at register 0x%x\n", *a1, 536);
    goto LABEL_32;
  }
  v3 = v20[0] & 4;
  v20[0] &= 4u;
  if ( !v19[0] || !v3 )
  {
    v7 = a1[157];
    if ( v7 )
      v8 = *((_QWORD *)v7 + 1);
    else
      v8 = 0;
    _drm_dev_dbg(0, v8, 2, "%s: Source DUT does not support TEST_EDID_READ\n", *a1);
    goto LABEL_32;
  }
  if ( drm_dp_dpcd_write(a1, 0x201u, (__int64)v19, 1) <= 0 )
  {
    v13 = a1[157];
    if ( v13 )
      v14 = *((_QWORD *)v13 + 1);
    else
      v14 = 0;
    dev_err(v14, "[drm] *ERROR* %s: DPCD failed write at register 0x%x\n", *a1, 513);
    goto LABEL_32;
  }
  if ( drm_dp_dpcd_write(a1, 0x261u, (__int64)v21, 1) <= 0 )
  {
    v15 = a1[157];
    if ( v15 )
      v16 = *((_QWORD *)v15 + 1);
    else
      v16 = 0;
    dev_err(v16, "[drm] *ERROR* %s: DPCD failed write at register 0x%x\n", *a1, 609);
    goto LABEL_32;
  }
  v18[0] = 4;
  v4 = 1;
  if ( drm_dp_dpcd_write(a1, 0x260u, (__int64)v18, 1) <= 0 )
  {
    v5 = a1[157];
    if ( v5 )
      v6 = *((_QWORD *)v5 + 1);
    else
      v6 = 0;
    dev_err(v6, "[drm] *ERROR* %s: DPCD failed write at register 0x%x\n", *a1, 608);
LABEL_32:
    v4 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
