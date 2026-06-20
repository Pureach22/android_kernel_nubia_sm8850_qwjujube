__int64 __fastcall sde_setup_pipe_pa_memcol_v1_7(__int64 a1, unsigned int a2, _DWORD *a3)
{
  unsigned int v6; // w20
  int v7; // w24
  int v8; // w21
  unsigned int v9; // w25
  unsigned int v10; // w25
  int v11; // w0
  unsigned int v12; // w2

  if ( a2 >= 3 )
    return _drm_err("Invalid memory color type %d\n", a2);
  v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 56) + 48LL) + 216LL);
  v7 = dword_28D79C[a2];
  v8 = sde_reg_read(a1, v6);
  if ( a3 )
  {
    v9 = v6 + 20 * a2;
    sde_reg_write(a1, v9 + 136, a3[2] & 0xFFFF07FF, "(off + MEMCOL_PWL0_OFF)");
    sde_reg_write(a1, v9 + 140, a3[3], "(off + MEMCOL_PWL1_OFF)");
    sde_reg_write(a1, v9 + 144, a3[8] & 0x7FF07FF, "(off + MEMCOL_HUE_REGION_OFF)");
    sde_reg_write(a1, v9 + 148, a3[9] & 0xFFFFFF, "(off + MEMCOL_SAT_REGION_OFF)");
    sde_reg_write(a1, v9 + 152, a3[10] & 0xFFFFFF, "(off + MEMCOL_VAL_REGION_OFF)");
    v10 = v6 + 8 * a2;
    sde_reg_write(a1, v10 + 536, a3[4], "(off + MEMCOL_PWL2_OFF)");
    sde_reg_write(a1, v10 + 540, a3[5], "(off + MEMCOL_BLEND_GAIN_OFF)");
    v11 = sde_reg_read(a1, v10 + 532);
    sde_reg_write(
      a1,
      v10 + 532,
      ((a3[6] & 3) << (4 * a2)) | ((a3[7] & 3) << ((4 * a2) | 2)) | v11 & ~(15 << (4 * a2)),
      "(off + MEMCOL_PWL_HOLD_OFF)");
    v12 = v7 | v8 | 0x10;
  }
  else if ( (v8 & ~v7 & 0x1E0000E0) != 0 )
  {
    v12 = v8 & ~v7;
  }
  else
  {
    v12 = v8 & 0xE1FFFF0F;
  }
  return sde_reg_write(a1, v6, v12, "base");
}
