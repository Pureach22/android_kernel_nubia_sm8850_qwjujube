__int64 __fastcall sde_setup_dspp_dither_v1_7(__int64 a1, const void **a2)
{
  int v2; // w3
  const void *v3; // x2
  __int64 v4; // x20
  unsigned int v5; // w19
  _DWORD *v7; // x22
  __int64 v8; // x0
  unsigned int v9; // w1
  int v10; // w2
  unsigned int v11; // w2

  if ( !a2 )
  {
    v3 = nullptr;
    v2 = 0;
    return _drm_err("hw %pK payload %pK size %d expected sz %zd\n", a2, v3, v2, 0x50u);
  }
  v2 = *((_DWORD *)a2 + 2);
  v3 = *a2;
  if ( v2 != 80 )
  {
    if ( !v3 )
    {
      v4 = a1;
      v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 272LL);
      goto LABEL_12;
    }
    return _drm_err("hw %pK payload %pK size %d expected sz %zd\n", a2, v3, v2, 0x50u);
  }
  v4 = a1;
  v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 272LL);
  if ( v3 )
  {
    _drm_dev_dbg(0, 0, 1, "Enable DSPP Dither feature\n");
    v7 = *a2;
    sde_reg_write(
      v4,
      v5 + 4,
      v7[4] & 0xF | ((v7[6] & 0xF) << 8) & 0xFFF | (unsigned __int8)(16 * (v7[5] & 0xF)) | ((v7[7] & 0xF) << 12),
      "matrix_off + i");
    sde_reg_write(
      v4,
      v5 + 8,
      v7[8] & 0xF | ((v7[10] & 0xF) << 8) & 0xFFF | (unsigned __int8)(16 * (v7[9] & 0xF)) | ((v7[11] & 0xF) << 12),
      "matrix_off + i");
    sde_reg_write(
      v4,
      v5 + 12,
      v7[12] & 0xF | ((v7[14] & 0xF) << 8) & 0xFFF | (unsigned __int8)(16 * (v7[13] & 0xF)) | ((v7[15] & 0xF) << 12),
      "matrix_off + i");
    sde_reg_write(
      v4,
      v5 + 16,
      v7[16] & 0xF | ((v7[18] & 0xF) << 8) & 0xFFF | (unsigned __int8)(16 * (v7[17] & 0xF)) | ((v7[19] & 0xF) << 12),
      "matrix_off + i");
    v8 = v4;
    v9 = v5;
    if ( v7[3] )
      v10 = 3;
    else
      v10 = 1;
    v11 = v10 & 0xFFFFFF0F | (16 * (v7[2] & 0xF));
    return sde_reg_write(v8, v9, v11, "ctrl_off");
  }
LABEL_12:
  _drm_dev_dbg(0, 0, 1, "Disable DSPP dither feature\n");
  v8 = v4;
  v9 = v5;
  v11 = 0;
  return sde_reg_write(v8, v9, v11, "ctrl_off");
}
