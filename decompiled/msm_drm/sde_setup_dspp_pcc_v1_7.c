__int64 __fastcall sde_setup_dspp_pcc_v1_7(__int64 a1, const void **a2)
{
  int v2; // w3
  const void *v3; // x2
  __int64 v4; // x19
  _DWORD *v6; // x20
  __int64 v7; // x8
  unsigned int v8; // w2

  if ( !a2 )
  {
    v3 = nullptr;
    v2 = 0;
    return _drm_err("invalid params hw %pK payload %pK payloadsize %d exp size %zd\n", a2, v3, v2, 0x90u);
  }
  v2 = *((_DWORD *)a2 + 2);
  v3 = *a2;
  if ( v2 != 144 )
  {
    if ( !v3 )
      goto LABEL_8;
    return _drm_err("invalid params hw %pK payload %pK payloadsize %d exp size %zd\n", a2, v3, v2, 0x90u);
  }
  if ( !v3 )
  {
LABEL_8:
    v7 = *(_QWORD *)(a1 + 72);
    v8 = 0;
    return sde_reg_write(a1, *(_DWORD *)(*(_QWORD *)(v7 + 48) + 56LL), v8, "ctx->cap->sblk->pcc.base");
  }
  v4 = a1;
  _drm_dev_dbg(0, 0, 1, "Enable PCC feature\n");
  v6 = *a2;
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 4,
    *((unsigned __int16 *)v6 + 4),
    "ctx->cap->sblk->pcc.base + PCC_CONST_COEFF_OFF");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 8,
    *((unsigned __int16 *)v6 + 20),
    "ctx->cap->sblk->pcc.base + PCC_CONST_COEFF_OFF + 4");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 12,
    *((unsigned __int16 *)v6 + 36),
    "ctx->cap->sblk->pcc.base + PCC_CONST_COEFF_OFF + 8");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 16,
    v6[3] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_R_COEFF_OFF");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 20,
    v6[11] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_R_COEFF_OFF + 4");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 24,
    v6[19] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_R_COEFF_OFF + 8");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 28,
    v6[4] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_G_COEFF_OFF");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 32,
    v6[12] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_G_COEFF_OFF + 4");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 36,
    v6[20] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_G_COEFF_OFF + 8");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 40,
    v6[5] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_B_COEFF_OFF");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 44,
    v6[13] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_B_COEFF_OFF + 4");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 48,
    v6[21] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_B_COEFF_OFF + 8");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 52,
    v6[6] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_RG_COEFF_OFF");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 56,
    v6[14] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_RG_COEFF_OFF + 4");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 60,
    v6[22] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_RG_COEFF_OFF + 8");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 64,
    v6[8] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_RB_COEFF_OFF");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 68,
    v6[16] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_RB_COEFF_OFF + 4");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 72,
    v6[24] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_RB_COEFF_OFF + 8");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 76,
    v6[7] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_GB_COEFF_OFF");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 80,
    v6[15] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_GB_COEFF_OFF + 4");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 84,
    v6[23] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_GB_COEFF_OFF + 8");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 88,
    v6[9] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_RGB_COEFF_OFF");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 92,
    v6[17] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_RGB_COEFF_OFF + 4");
  sde_reg_write(
    v4,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 48LL) + 56LL) + 96,
    v6[25] & 0x3FFFF,
    "ctx->cap->sblk->pcc.base + PCC_RGB_COEFF_OFF + 8");
  v7 = *(_QWORD *)(v4 + 72);
  a1 = v4;
  v8 = 1;
  return sde_reg_write(a1, *(_DWORD *)(*(_QWORD *)(v7 + 48) + 56LL), v8, "ctx->cap->sblk->pcc.base");
}
