__int64 __fastcall sde_hw_lm_setup_dim_layer_v1(__int64 result, __int64 a2)
{
  unsigned int v2; // w8
  __int64 v3; // x9
  unsigned int v4; // w19
  int v5; // w21
  __int64 v7; // x20
  __int64 v8; // x2

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)(result + 40) + 48LL);
    if ( *(_DWORD *)(v3 + 4) < v2 )
      return printk(&unk_25BB24, "sde_hw_lm_setup_dim_layer_v1");
    if ( v2 >= 0xD )
    {
      __break(0x5512u);
      JUMPOUT(0x180AA0);
    }
    v4 = *(_DWORD *)(v3 + 4LL * (v2 - 1) + 8);
    if ( (v4 & 0x80000000) != 0 )
    {
      return printk(&unk_25BB24, "sde_hw_lm_setup_dim_layer_v1");
    }
    else
    {
      v5 = *(unsigned __int8 *)(a2 + 20);
      v7 = result;
      sde_reg_write(
        result,
        v4 + 12,
        ((*(_DWORD *)(a2 + 12) & 0x3FF) << 18) | (4 * (*(_DWORD *)(a2 + 8) & 0x3FFu)),
        "LM_BLEND0_FG_COLOR_FILL_COLOR_0_V1 + stage_off");
      sde_reg_write(
        v7,
        v4 + 16,
        (v5 << 20) | (4 * (*(_DWORD *)(a2 + 16) & 0x3FFu)),
        "LM_BLEND0_FG_COLOR_FILL_COLOR_1_V1 + stage_off");
      sde_reg_write(v7, v4 + 20, *(unsigned int *)(a2 + 28), "LM_BLEND0_FG_COLOR_FILL_SIZE_V1 + stage_off");
      sde_reg_write(v7, v4 + 24, *(unsigned int *)(a2 + 24), "LM_BLEND0_FG_COLOR_FILL_XY_V1 + stage_off");
      if ( (*(_DWORD *)a2 & 2) != 0 )
        v8 = 196864;
      else
        v8 = 65792;
      sde_reg_write(v7, v4, v8, "LM_BLEND0_OP + stage_off");
      return sde_reg_write(v7, v4 + 8, (v5 | (v5 << 16)) ^ 0xFFu, "LM_BLEND0_CONST_ALPHA_V1 + stage_off");
    }
  }
  return result;
}
