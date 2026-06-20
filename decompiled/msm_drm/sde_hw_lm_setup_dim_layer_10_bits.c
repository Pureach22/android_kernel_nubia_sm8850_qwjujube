__int64 __fastcall sde_hw_lm_setup_dim_layer_10_bits(__int64 result, _DWORD *a2)
{
  unsigned int v2; // w8
  __int64 v3; // x9
  unsigned int v4; // w19
  int v5; // w22
  __int64 v7; // x20
  __int64 v8; // x2

  v2 = a2[1];
  if ( v2 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)(result + 40) + 48LL);
    if ( *(_DWORD *)(v3 + 4) < v2 )
      return printk(&unk_25BB24, "sde_hw_lm_setup_dim_layer_10_bits");
    if ( v2 >= 0xD )
    {
      __break(0x5512u);
      return sde_hw_lm_setup_dim_layer_v1();
    }
    v4 = *(_DWORD *)(v3 + 4LL * (v2 - 1) + 8);
    if ( (v4 & 0x80000000) != 0 )
      return printk(&unk_25BB24, "sde_hw_lm_setup_dim_layer_10_bits");
    v5 = a2[5];
    v7 = result;
    sde_reg_write(
      result,
      v4 + 12,
      a2[2] & 0x3FF | ((a2[3] & 0x3FFu) << 16),
      "LM_BLEND0_FG_COLOR_FILL_COLOR_0_V1 + stage_off");
    sde_reg_write(v7, v4 + 16, ((v5 & 0x3FF) << 16) | a2[4] & 0x3FFu, "LM_BLEND0_FG_COLOR_FILL_COLOR_1_V1 + stage_off");
    sde_reg_write(v7, v4 + 20, (unsigned int)a2[7], "LM_BLEND0_FG_COLOR_FILL_SIZE_V1 + stage_off");
    sde_reg_write(v7, v4 + 24, (unsigned int)a2[6], "LM_BLEND0_FG_COLOR_FILL_XY_V1 + stage_off");
    if ( (*a2 & 2) != 0 )
      v8 = 196864;
    else
      v8 = 65792;
    sde_reg_write(v7, v4, v8, "LM_BLEND0_OP + stage_off");
    return sde_reg_write(
             v7,
             v4 + 8,
             (v5 & 0x3FF | ((v5 & 0x3FF) << 16)) ^ 0x3FFu,
             "LM_BLEND0_CONST_ALPHA_V1 + stage_off");
  }
  return result;
}
