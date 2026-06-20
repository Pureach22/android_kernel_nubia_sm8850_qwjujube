__int64 __fastcall sde_hw_pp_setup_dither_v3(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  __int64 result; // x0
  unsigned int v5; // w2
  unsigned int v6; // w1
  __int64 v7; // x20
  unsigned int v8; // w19
  unsigned int v9; // w22
  __int64 v10; // x24
  _DWORD *v12; // x23
  __int64 v13; // x0
  __int64 v14; // x25
  __int64 v15; // x26
  int v16; // w8
  int v17; // w8
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  if ( !a1 )
    goto LABEL_12;
  if ( !a2 || a3 == 1120 )
  {
    if ( !a2 )
    {
      v5 = 0;
      v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 48LL) + 128LL);
LABEL_15:
      sde_reg_write(a1, v6, v5, "base");
      result = 0;
      goto LABEL_13;
    }
    if ( *(_DWORD *)(a2 + 12) > 8u
      || *(_DWORD *)(a2 + 16) > 8u
      || *(_DWORD *)(a2 + 20) > 8u
      || *(_DWORD *)(a2 + 24) > 8u )
    {
      goto LABEL_12;
    }
    v3 = *(_DWORD *)(a2 + 92);
    if ( (unsigned int)v3 >= 5 )
    {
      _drm_err("Invalid dither_matrix_select: %d\n", v3);
      goto LABEL_12;
    }
    v7 = a1;
    v8 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 48LL) + 128LL);
    if ( v3 > 2 )
    {
      if ( v3 == 3 )
      {
        v9 = 8;
        v10 = 64;
      }
      else
      {
        v9 = 16;
        v10 = 256;
      }
    }
    else
    {
      if ( !v3 )
      {
        sde_reg_write(
          a1,
          v8 + 8,
          *(_DWORD *)(a2 + 28) & 0xF
        | ((*(_WORD *)(a2 + 36) & 0xF) << 8) & 0xFFF
        | (unsigned __int8)(16 * (*(_BYTE *)(a2 + 32) & 0xF))
        | ((*(_DWORD *)(a2 + 40) & 0xF) << 12),
          "base + offset");
        sde_reg_write(
          v7,
          v8 + 12,
          *(_DWORD *)(a2 + 44) & 0xF
        | ((*(_WORD *)(a2 + 52) & 0xF) << 8) & 0xFFF
        | (unsigned __int8)(16 * (*(_BYTE *)(a2 + 48) & 0xF))
        | ((*(_DWORD *)(a2 + 56) & 0xF) << 12),
          "base + offset");
        sde_reg_write(
          v7,
          v8 + 16,
          *(_DWORD *)(a2 + 60) & 0xF
        | ((*(_WORD *)(a2 + 68) & 0xF) << 8) & 0xFFF
        | (unsigned __int8)(16 * (*(_BYTE *)(a2 + 64) & 0xF))
        | ((*(_DWORD *)(a2 + 72) & 0xF) << 12),
          "base + offset");
        v12 = (_DWORD *)a2;
        sde_reg_write(
          v7,
          v8 + 20,
          *(_DWORD *)(a2 + 76) & 0xF
        | ((*(_WORD *)(a2 + 84) & 0xF) << 8) & 0xFFF
        | (unsigned __int8)(16 * (*(_BYTE *)(a2 + 80) & 0xF))
        | ((*(_DWORD *)(a2 + 88) & 0xF) << 12),
          "base + offset");
        v13 = v7;
        goto LABEL_27;
      }
      if ( v3 == 2 )
      {
        v9 = 6;
        v10 = 36;
      }
      else
      {
        v9 = 4;
        v10 = 16;
      }
    }
    v14 = 0;
    v12 = (_DWORD *)a2;
    v15 = a2 + 96;
    do
    {
      sde_reg_write(
        v7,
        v8 + 32,
        ((((unsigned int)v14 / v9) << 12) + (((unsigned int)v14 % v9) << 8)) & 0xFF00
      | *(_DWORD *)(v15 + 4 * v14) & 0x3F,
        "base + 0x20");
      ++v14;
      v13 = v7;
    }
    while ( v10 != v14 );
LABEL_27:
    ((void (__fastcall *)(__int64, _DWORD *, int *))sde_hw_pp_setup_dither_common)(v13, v12, &v18);
    v16 = v12[23];
    v5 = v18 | (16 * *v12) & 0x20 | 6;
    if ( v16 )
    {
      switch ( v16 )
      {
        case 4:
          v17 = 200;
          break;
        case 3:
          v17 = 136;
          break;
        case 2:
          v17 = 72;
          break;
        default:
          v5 = v18 | (16 * *v12) & 0x20 | 0xE;
          goto LABEL_36;
      }
      v5 |= v17;
    }
LABEL_36:
    a1 = v7;
    v6 = v8;
    goto LABEL_15;
  }
  _drm_err("input len %zu, expected len %zu\n", a3, 0x460u);
LABEL_12:
  result = 4294967274LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
