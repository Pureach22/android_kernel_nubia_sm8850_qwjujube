__int64 __fastcall drm_dp_dual_mode_set_tmds_output(__int64 a1, unsigned int a2, __int64 a3, char a4)
{
  unsigned int v4; // w21
  unsigned int v8; // w23
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x0
  const char *v12; // x8
  bool v13; // zf
  const char *v14; // x9
  const char *v15; // x3
  __int64 v16; // x0
  const char *v17; // x4
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x1
  const char *v23; // x4
  _BYTE v24[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v25[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = a4 ^ 1;
  if ( a2 < 4 )
    goto LABEL_2;
  v24[0] = 0;
  v8 = 1;
  v9 = drm_dp_dual_mode_write(a3, 32, v25, 1u);
  if ( v9 )
  {
    v4 = v9;
LABEL_5:
    if ( a1 )
      v10 = *(_QWORD *)(a1 + 8);
    else
      v10 = 0;
    v12 = "disable";
    v13 = (a4 & 1) == 0;
    v14 = "enable";
    v15 = "Failed to %s TMDS output buffers (%d attempts)\n";
LABEL_18:
    if ( v13 )
      v17 = v12;
    else
      v17 = v14;
    _drm_dev_dbg(0, v10, 2, v15, v17, v8);
    goto LABEL_22;
  }
  v8 = 1;
  v11 = drm_dp_dual_mode_read(a3, 0x20u, v24, 1u);
  if ( v11 )
  {
    v4 = v11;
LABEL_9:
    if ( a1 )
      v10 = *(_QWORD *)(a1 + 8);
    else
      v10 = 0;
    v12 = "disabling";
    v13 = (a4 & 1) == 0;
    v14 = "enabling";
    v15 = "I2C read failed during TMDS output buffer %s (%d attempts)\n";
    goto LABEL_18;
  }
  if ( v24[0] == v25[0] )
    goto LABEL_2;
  v24[0] = 0;
  v16 = drm_dp_dual_mode_write(a3, 32, v25, 1u);
  if ( v16 )
  {
    v4 = v16;
    v8 = 2;
    goto LABEL_5;
  }
  v19 = drm_dp_dual_mode_read(a3, 0x20u, v24, 1u);
  if ( v19 )
  {
    v4 = v19;
    v8 = 2;
    goto LABEL_9;
  }
  if ( v24[0] == v25[0] )
    goto LABEL_2;
  v24[0] = 0;
  v20 = drm_dp_dual_mode_write(a3, 32, v25, 1u);
  if ( v20 )
  {
    v4 = v20;
    v8 = 3;
    goto LABEL_5;
  }
  v21 = drm_dp_dual_mode_read(a3, 0x20u, v24, 1u);
  if ( v21 )
  {
    v4 = v21;
    v8 = 3;
    goto LABEL_9;
  }
  if ( v24[0] == v25[0] )
  {
LABEL_2:
    v4 = 0;
    goto LABEL_22;
  }
  if ( a1 )
    v22 = *(_QWORD *)(a1 + 8);
  else
    v22 = 0;
  if ( (a4 & 1) != 0 )
    v23 = "enabling";
  else
    v23 = "disabling";
  _drm_dev_dbg(0, v22, 2, "I2C write value mismatch during TMDS output buffer %s\n", v23);
  v4 = -5;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v4;
}
