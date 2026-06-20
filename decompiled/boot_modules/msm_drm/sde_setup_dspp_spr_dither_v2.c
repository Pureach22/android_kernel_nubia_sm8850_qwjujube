__int64 __fastcall sde_setup_dspp_spr_dither_v2(__int64 result, __int64 *a2)
{
  int v2; // w3
  _DWORD *v3; // x2
  __int64 v4; // x20
  unsigned int v6; // w19
  __int64 v7; // x24
  int v8; // w1
  __int64 v9; // x20
  unsigned int v10; // w19
  __int64 v11; // x0
  unsigned int v12; // w1
  unsigned int v13; // w2
  unsigned int v14; // w23
  __int64 v15; // x25
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  __int64 v20; // x0
  __int64 i; // x26
  int v22; // w8
  int v23; // w8
  int v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  if ( !a2 )
  {
    v3 = nullptr;
    v2 = 0;
    goto LABEL_12;
  }
  v2 = *((_DWORD *)a2 + 2);
  v3 = (_DWORD *)*a2;
  if ( v2 != 1120 )
  {
    if ( !v3 )
      goto LABEL_13;
LABEL_12:
    result = _drm_err("hw %pK payload %pK size %d expected sz %zd\n", a2, v3, v2, 0x460u);
    goto LABEL_15;
  }
  if ( !v3 )
  {
LABEL_13:
    v9 = result;
    v10 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 452LL);
    _drm_dev_dbg(0, 0, 1, "Disable DSPP spr dither feature\n");
    v11 = v9;
    v12 = v10;
    v13 = 0;
LABEL_14:
    result = sde_reg_write(v11, v12, v13, "base");
    goto LABEL_15;
  }
  if ( v3[3] <= 8u && v3[4] <= 8u && v3[5] <= 8u && v3[6] <= 8u )
  {
    v4 = result;
    v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 452LL);
    _drm_dev_dbg(0, 0, 1, "Enable DSPP spr Dither feature\n");
    v7 = *a2;
    v8 = *(_DWORD *)(*a2 + 92);
    if ( (unsigned int)v8 >= 5 )
    {
      result = _drm_err("Invalid dither_matrix_select: %d\n", v8);
      goto LABEL_15;
    }
    if ( v8 > 2 )
    {
      if ( v8 == 3 )
      {
        v14 = 8;
        v15 = 64;
      }
      else
      {
        v14 = 16;
        v15 = 256;
      }
    }
    else
    {
      if ( !v8 )
      {
        sde_reg_write(
          v4,
          v6 + 8,
          *(_DWORD *)(v7 + 28) & 0xF
        | ((*(_WORD *)(v7 + 36) & 0xF) << 8) & 0xFFF
        | (unsigned __int8)(16 * (*(_BYTE *)(v7 + 32) & 0xF))
        | ((*(_DWORD *)(v7 + 40) & 0xF) << 12),
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
        v20 = v4;
        goto LABEL_27;
      }
      if ( v8 == 2 )
      {
        v14 = 6;
        v15 = 36;
      }
      else
      {
        v14 = 4;
        v15 = 16;
      }
    }
    for ( i = 0; i != v15; ++i )
    {
      sde_reg_write(
        v4,
        v6 + 32,
        ((((unsigned int)i / v14) << 12) + (((unsigned int)i % v14) << 8)) & 0xFF00
      | *(_DWORD *)(v7 + 96 + 4 * i) & 0x3F,
        "base + 0x20");
      v20 = v4;
    }
LABEL_27:
    sde_setup_dspp_spr_dither_common(v20, a2, &v24, v16, v17, v18, v19);
    v22 = *(_DWORD *)(v7 + 92);
    v13 = v24 | (16 * *(_DWORD *)v7) & 0x20 | 6;
    if ( v22 )
    {
      switch ( v22 )
      {
        case 4:
          v23 = 200;
          break;
        case 3:
          v23 = 136;
          break;
        case 2:
          v23 = 72;
          break;
        default:
          v13 = v24 | (16 * *(_DWORD *)v7) & 0x20 | 0xE;
          goto LABEL_36;
      }
      v13 |= v23;
    }
LABEL_36:
    v11 = v4;
    v12 = v6;
    goto LABEL_14;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
