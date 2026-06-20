__int64 __fastcall drm_dp_dual_mode_detect(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x9
  __int64 v6; // x1
  __int64 result; // x0
  __int64 v8; // x20
  __int64 v9; // x1
  _BOOL4 v11; // w8
  __int64 v12; // x0
  _BYTE v13[4]; // [xsp+0h] [xbp-40h] BYREF
  char v14; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-38h] BYREF
  __int64 v16; // [xsp+10h] [xbp-30h]
  _QWORD v17[5]; // [xsp+18h] [xbp-28h] BYREF

  v17[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v17[0] = 0x100000040LL;
  v17[1] = &v14;
  v13[0] = 0;
  v14 = 0;
  v17[2] = 0x1000010040LL;
  v17[3] = &v15;
  LODWORD(v4) = i2c_transfer(a2, v17, 2);
  kfree(0);
  v5 = -71;
  if ( (_DWORD)v4 == 2 )
    v5 = 0;
  if ( (int)v4 >= 0 )
    v4 = v5;
  else
    v4 = (int)v4;
  if ( a1 )
    v6 = *(_QWORD *)(a1 + 8);
  else
    v6 = 0;
  _drm_dev_dbg(0, v6, 2, "DP dual mode HDMI ID: %*pE (err %zd)\n", 16 * (unsigned int)(v4 == 0), &v15, v4);
  if ( v4 )
  {
    result = 1;
    goto LABEL_31;
  }
  v8 = drm_dp_dual_mode_read(a2, 0x10u, v13, 1u);
  if ( a1 )
    v9 = *(_QWORD *)(a1 + 8);
  else
    v9 = 0;
  _drm_dev_dbg(0, v9, 2, "DP dual mode adaptor ID: %02x (err %zd)\n", v13[0], v8);
  if ( v8 )
    goto LABEL_15;
  v11 = v15 != 0x20494D44482D5044LL || v16 != 0x4524F5450414441LL;
  if ( v13[0] == 168 && !v11 )
  {
    result = 6;
    goto LABEL_31;
  }
  if ( v13[0] != 160 )
  {
    if ( (unsigned int)v13[0] - 255 >= 0xFFFFFF02 )
    {
      if ( a1 )
        v12 = *(_QWORD *)(a1 + 8);
      else
        v12 = 0;
      dev_err(v12, "[drm] *ERROR* Unexpected DP dual mode adaptor ID %02x\n", v13[0]);
    }
LABEL_15:
    if ( v15 ^ 0x20494D44482D5044LL | v16 ^ 0x4524F5450414441LL )
      result = 2;
    else
      result = 3;
    goto LABEL_31;
  }
  if ( v11 )
    result = 4;
  else
    result = 5;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
