__int64 __fastcall sde_setup_dspp_ltm_hist_bufferv1(_QWORD *a1, __int64 a2)
{
  int v3; // w20
  int v4; // w21

  if ( !a1 || !a2 )
    return _drm_err("invalid parameter ctx %pK addr 0x%llx\n", a1, a2);
  v3 = a2 + 0x4000;
  v4 = a2 + 17408;
  sde_reg_write(
    a1,
    (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 380LL) + 112),
    (unsigned int)a2 & 0xFFFFFF00,
    "ctx->cap->sblk->ltm.base + 0x70");
  sde_reg_write(
    a1,
    (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 380LL) + 116),
    v3 & 0xFFFFFF00,
    "ctx->cap->sblk->ltm.base + 0x74");
  return sde_reg_write(
           a1,
           (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 380LL) + 120),
           v4 & 0xFFFFFF00,
           "ctx->cap->sblk->ltm.base + 0x78");
}
