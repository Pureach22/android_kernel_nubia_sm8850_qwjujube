__int64 __fastcall sde_setup_dspp_pccv4(_QWORD *a1, _DWORD *a2)
{
  unsigned int *v3; // x25
  int v4; // w1
  int v5; // w20
  int v6; // w26
  unsigned int *v7; // x24
  int v8; // w27
  int v9; // w27
  __int64 v11; // x8
  _QWORD *v12; // x0
  __int64 v13; // x2

  if ( !a1 || !a2 )
    return _drm_err("invalid param ctx %pK cfg %pK\n", a1, a2);
  v3 = *(unsigned int **)a2;
  if ( *(_QWORD *)a2 )
  {
    v4 = a2[2];
    if ( v4 != 144 )
      return _drm_err("invalid size of payload len %d exp %zd\n", v4, 0x90u);
    v5 = 0;
    v6 = 124;
    while ( 1 )
    {
      v9 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 56LL);
      if ( v5 == 2 )
      {
        sde_reg_write(a1, (unsigned int)(v6 + v9 - 24), v3[32], "base + PCC_RR_OFF");
        sde_reg_write(a1, (unsigned int)(v6 + v9 - 12), v3[33], "base + PCC_GG_OFF");
        sde_reg_write(a1, (unsigned int)(v6 + v9), v3[34], "base + PCC_BB_OFF");
        v7 = v3 + 18;
      }
      else if ( v5 == 1 )
      {
        sde_reg_write(a1, (unsigned int)(v6 + v9 - 24), v3[29], "base + PCC_RR_OFF");
        sde_reg_write(a1, (unsigned int)(v6 + v9 - 12), v3[30], "base + PCC_GG_OFF");
        sde_reg_write(a1, (unsigned int)(v6 + v9), v3[31], "base + PCC_BB_OFF");
        v7 = v3 + 10;
      }
      else
      {
        if ( v5 )
          return _drm_err("invalid pcc plane: %d\n", v5);
        sde_reg_write(a1, (unsigned int)(v6 + v9 - 24), v3[26], "base + PCC_RR_OFF");
        sde_reg_write(a1, (unsigned int)(v6 + v9 - 12), v3[27], "base + PCC_GG_OFF");
        sde_reg_write(a1, (unsigned int)(v6 + v9), v3[28], "base + PCC_BB_OFF");
        v7 = v3 + 2;
      }
      v8 = v6 + v9;
      sde_reg_write(a1, (unsigned int)(v8 - 120), *v7, "base + PCC_C_OFF");
      sde_reg_write(a1, (unsigned int)(v8 - 108), v7[1], "base + PCC_R_OFF");
      sde_reg_write(a1, (unsigned int)(v8 - 96), v7[2], "base + PCC_G_OFF");
      sde_reg_write(a1, (unsigned int)(v8 - 84), v7[3], "base + PCC_B_OFF");
      sde_reg_write(a1, (unsigned int)(v8 - 72), v7[4], "base + PCC_RG_OFF");
      sde_reg_write(a1, (unsigned int)(v8 - 60), v7[6], "base + PCC_RB_OFF");
      sde_reg_write(a1, (unsigned int)(v8 - 48), v7[5], "base + PCC_GB_OFF");
      sde_reg_write(a1, (unsigned int)(v8 - 36), v7[7], "base + PCC_RGB_OFF");
      v6 += 4;
      ++v5;
      if ( v6 == 136 )
      {
        v11 = a1[9];
        v12 = a1;
        v13 = 1;
        return sde_reg_write(v12, *(unsigned int *)(*(_QWORD *)(v11 + 48) + 56LL), v13, "ctx->cap->sblk->pcc.base");
      }
    }
  }
  _drm_dev_dbg(0, 0, 1, "disable pcc feature\n");
  v11 = a1[9];
  v12 = a1;
  v13 = 0;
  return sde_reg_write(v12, *(unsigned int *)(*(_QWORD *)(v11 + 48) + 56LL), v13, "ctx->cap->sblk->pcc.base");
}
