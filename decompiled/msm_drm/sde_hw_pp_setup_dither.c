__int64 __fastcall sde_hw_pp_setup_dither(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v4; // w2
  unsigned int v5; // w1
  __int64 v7; // x20
  unsigned int v8; // w19
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  if ( !a1 )
    goto LABEL_10;
  if ( !a2 || a3 == 1120 )
  {
    if ( a2 )
    {
      if ( *(_DWORD *)(a2 + 12) > 8u
        || *(_DWORD *)(a2 + 16) > 8u
        || *(_DWORD *)(a2 + 20) > 8u
        || *(_DWORD *)(a2 + 24) > 8u )
      {
        goto LABEL_10;
      }
      v7 = a1;
      v8 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 48LL) + 128LL);
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
      sde_reg_write(
        v7,
        v8 + 20,
        *(_DWORD *)(a2 + 76) & 0xF
      | ((*(_WORD *)(a2 + 84) & 0xF) << 8) & 0xFFF
      | (unsigned __int8)(16 * (*(_BYTE *)(a2 + 80) & 0xF))
      | ((*(_DWORD *)(a2 + 88) & 0xF) << 12),
        "base + offset");
      ((void (__fastcall *)(__int64, __int64, unsigned int *))sde_hw_pp_setup_dither_common)(v7, a2, &v9);
      v4 = v9;
      a1 = v7;
      v5 = v8;
    }
    else
    {
      v4 = 0;
      v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 48LL) + 128LL);
    }
    sde_reg_write(a1, v5, v4, "base");
    result = 0;
    goto LABEL_11;
  }
  _drm_err("input len %zu, expected len %zu\n", a3, 0x460u);
LABEL_10:
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
