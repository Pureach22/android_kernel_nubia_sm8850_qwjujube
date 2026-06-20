void __fastcall sde_hw_wb_program_cwb_dither_ctrl_v3(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5)
{
  unsigned int v6; // w19
  __int64 v8; // x21
  __int64 v9; // x8
  unsigned int v10; // w20
  unsigned int v11; // w23
  unsigned int v12; // w1
  int v13; // w8
  unsigned int v14; // w25
  __int64 v15; // x26
  __int64 i; // x27
  int v17; // w9
  int v18; // w8
  unsigned int v19; // w2
  int v20; // w9
  int v21; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v22[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v6 = a2;
  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = a5;
  v21 = 0;
  if ( (unsigned int)sde_hw_wb_program_cwb_dither_validate(a1, a2, a3, a4, v22) )
    goto LABEL_41;
  v8 = a1 + 696;
  if ( a1 == -696 || v6 != 1 )
  {
    v8 = a1 + 1168;
    if ( a1 == -1168 || v6 != 2 )
    {
      v8 = a1 + 1640;
      if ( a1 == -1640 || v6 != 3 )
      {
        v8 = a1 + 2112;
        if ( a1 == -2112 || v6 != 4 )
        {
          _drm_err("Not found pp id %d\n", 14);
          goto LABEL_41;
        }
      }
    }
  }
  v9 = *(_QWORD *)(v8 + 40);
  v10 = *(_DWORD *)(v8 + 32);
  if ( (*(_QWORD *)(v9 + 32) & 0x400) == 0 )
  {
    _drm_err("Invalid ping-pong cwb config dcwb idx %d pp id %d\n", v6, v10);
    goto LABEL_41;
  }
  v11 = *(_DWORD *)(*(_QWORD *)(v9 + 48) + 128LL);
  if ( (v22[0] & 1) != 0 )
  {
    v12 = *(_DWORD *)(a3 + 92);
    if ( v12 >= 5 )
    {
      _drm_err("Invalid dither_matrix_select: %d\n", v12);
      goto LABEL_41;
    }
    ((void (__fastcall *)(__int64, __int64, int *))sde_hw_wb_program_cwb_dither_ctrl_common)(v8, a3, &v21);
    v13 = *(_DWORD *)(a3 + 92);
    if ( v13 > 2 )
    {
      if ( v13 == 3 )
      {
        v14 = 8;
        v15 = 64;
LABEL_28:
        for ( i = 0; i != v15; ++i )
          sde_reg_write(
            v8,
            v11 + 32,
            ((((unsigned int)i / v14) << 12) + (((unsigned int)i % v14) << 8)) & 0xFF00
          | *(_DWORD *)(a3 + 96 + 4 * i) & 0x3F,
            "base + 0x20");
LABEL_30:
        v17 = *(_DWORD *)(a3 + 92);
        v18 = v21 | (16 * *(_DWORD *)a3) & 0x20 | 6;
        v21 = v18;
        if ( v17 )
        {
          v19 = v18 | 8;
          v21 = v18 | 8;
          switch ( v17 )
          {
            case 4:
              v20 = 200;
              break;
            case 3:
              v20 = 136;
              break;
            case 2:
              v20 = 72;
              break;
            default:
              goto LABEL_39;
          }
          v19 = v18 | v20;
          v21 = v18 | v20;
        }
        else
        {
          v19 = v18;
        }
LABEL_39:
        sde_reg_write(v8, v11, v19, "base");
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "cwb dither enabled, dcwb_idx %u pp_id %u\n", v6, v10);
        goto LABEL_41;
      }
      if ( v13 == 4 )
      {
        v14 = 16;
        v15 = 256;
        goto LABEL_28;
      }
    }
    else
    {
      if ( !v13 )
      {
        sde_reg_write(
          v8,
          v11 + 8,
          *(_DWORD *)(a3 + 28) & 0xF
        | ((*(_WORD *)(a3 + 36) & 0xF) << 8) & 0xFFF
        | (unsigned __int8)(16 * (*(_BYTE *)(a3 + 32) & 0xF))
        | ((*(_DWORD *)(a3 + 40) & 0xF) << 12),
          "base + offset");
        sde_reg_write(
          v8,
          v11 + 12,
          *(_DWORD *)(a3 + 44) & 0xF
        | ((*(_WORD *)(a3 + 52) & 0xF) << 8) & 0xFFF
        | (unsigned __int8)(16 * (*(_BYTE *)(a3 + 48) & 0xF))
        | ((*(_DWORD *)(a3 + 56) & 0xF) << 12),
          "base + offset");
        sde_reg_write(
          v8,
          v11 + 16,
          *(_DWORD *)(a3 + 60) & 0xF
        | ((*(_WORD *)(a3 + 68) & 0xF) << 8) & 0xFFF
        | (unsigned __int8)(16 * (*(_BYTE *)(a3 + 64) & 0xF))
        | ((*(_DWORD *)(a3 + 72) & 0xF) << 12),
          "base + offset");
        sde_reg_write(
          v8,
          v11 + 20,
          *(_DWORD *)(a3 + 76) & 0xF
        | ((*(_WORD *)(a3 + 84) & 0xF) << 8) & 0xFFF
        | (unsigned __int8)(16 * (*(_BYTE *)(a3 + 80) & 0xF))
        | ((*(_DWORD *)(a3 + 88) & 0xF) << 12),
          "base + offset");
        goto LABEL_30;
      }
      if ( v13 == 2 )
      {
        v14 = 6;
        v15 = 36;
        goto LABEL_28;
      }
    }
    v14 = 4;
    v15 = 16;
    goto LABEL_28;
  }
  sde_reg_write(v8, v11, 0, "base");
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "cwb dither disabled, dcwb_idx %u pp_id %u\n", v6, v10);
LABEL_41:
  _ReadStatusReg(SP_EL0);
}
