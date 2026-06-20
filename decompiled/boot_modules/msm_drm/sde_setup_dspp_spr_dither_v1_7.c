__int64 __fastcall sde_setup_dspp_spr_dither_v1_7(__int64 result, _DWORD *a2)
{
  int v2; // w3
  _DWORD *v3; // x2
  __int64 v4; // x20
  unsigned int v6; // w19
  __int64 v7; // x23
  unsigned int v8; // w2
  __int64 v9; // x0
  unsigned int v10; // w1
  __int64 v11; // x20
  unsigned int v12; // w19
  unsigned int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  if ( !a2 )
  {
    v3 = nullptr;
    v2 = 0;
    goto LABEL_11;
  }
  v2 = a2[2];
  v3 = *(_DWORD **)a2;
  if ( v2 != 1120 )
  {
    if ( !v3 )
      goto LABEL_12;
LABEL_11:
    result = _drm_err("hw %pK payload %pK size %d expected sz %zd\n", a2, v3, v2, 0x460u);
    goto LABEL_14;
  }
  if ( !v3 )
  {
LABEL_12:
    v11 = result;
    v12 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 452LL);
    _drm_dev_dbg(0, 0, 1, "Disable DSPP spr dither feature\n");
    v9 = v11;
    v10 = v12;
    v8 = 0;
    goto LABEL_13;
  }
  if ( v3[3] <= 8u && v3[4] <= 8u && v3[5] <= 8u && v3[6] <= 8u )
  {
    v4 = result;
    v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 452LL);
    _drm_dev_dbg(0, 0, 1, "Enable DSPP spr Dither feature\n");
    v7 = *(_QWORD *)a2;
    sde_reg_write(
      v4,
      v6 + 8,
      *(_DWORD *)(*(_QWORD *)a2 + 28LL) & 0xF
    | ((*(_WORD *)(*(_QWORD *)a2 + 36LL) & 0xF) << 8) & 0xFFF
    | (unsigned __int8)(16 * (*(_BYTE *)(*(_QWORD *)a2 + 32LL) & 0xF))
    | ((*(_DWORD *)(*(_QWORD *)a2 + 40LL) & 0xF) << 12),
      "base + offset");
    sde_reg_write(
      v4,
      v6 + 12,
      *(_DWORD *)(v7 + 44) & 0xF
    | ((*(_WORD *)(v7 + 52) & 0xF) << 8) & 0xFFF
    | (unsigned __int8)(16 * (*(_BYTE *)(v7 + 48) & 0xF))
    | ((*(_DWORD *)(v7 + 56) & 0xF) << 12),
      "base + offset");
    sde_reg_write(
      v4,
      v6 + 16,
      *(_DWORD *)(v7 + 60) & 0xF
    | ((*(_WORD *)(v7 + 68) & 0xF) << 8) & 0xFFF
    | (unsigned __int8)(16 * (*(_BYTE *)(v7 + 64) & 0xF))
    | ((*(_DWORD *)(v7 + 72) & 0xF) << 12),
      "base + offset");
    sde_reg_write(
      v4,
      v6 + 20,
      *(_DWORD *)(v7 + 76) & 0xF
    | ((*(_WORD *)(v7 + 84) & 0xF) << 8) & 0xFFF
    | (unsigned __int8)(16 * (*(_BYTE *)(v7 + 80) & 0xF))
    | ((*(_DWORD *)(v7 + 88) & 0xF) << 12),
      "base + offset");
    sde_setup_dspp_spr_dither_common(v4, a2, &v13);
    v8 = v13;
    v9 = v4;
    v10 = v6;
LABEL_13:
    result = sde_reg_write(v9, v10, v8, "base");
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
