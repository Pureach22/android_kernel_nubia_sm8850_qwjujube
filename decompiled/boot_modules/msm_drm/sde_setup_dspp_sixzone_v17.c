__int64 __fastcall sde_setup_dspp_sixzone_v17(_QWORD *a1, _DWORD *a2)
{
  int v4; // w0
  __int64 v5; // x24
  int v6; // w20
  int v7; // w1
  __int64 v8; // x25
  unsigned int v9; // w21
  int v10; // w21
  int v11; // w0
  unsigned int v12; // w1
  int v13; // w8
  unsigned int v14; // w2
  int v16; // w8

  if ( !a1 || !a2 )
    return _drm_err("invalid param ctx %pK cfg %pK\n", a1, a2);
  v4 = sde_reg_read((__int64)a1, *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL));
  v5 = *(_QWORD *)a2;
  v6 = v4;
  if ( !*(_QWORD *)a2 )
  {
    _drm_dev_dbg(0, 0, 1, "disable sixzone feature\n");
    v12 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL);
    if ( (v6 & 0x1E0100E0) != 0 )
      v16 = 0x1FFFFFFF;
    else
      v16 = 32440095;
    v14 = v16 & v6;
    return sde_reg_write((__int64)a1, v12, v14, "ctx->cap->sblk->hsic.base");
  }
  v7 = a2[2];
  if ( v7 == 4648 )
  {
    sde_reg_write(
      (__int64)a1,
      *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 200LL),
      0x4000000u,
      "ctx->cap->sblk->sixzone.base");
    v8 = 0;
    v9 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 200LL);
    do
    {
      sde_reg_write((__int64)a1, v9 + 4, *(_DWORD *)(v5 + v8 + 28), "addr");
      sde_reg_write((__int64)a1, v9, *(_DWORD *)(v5 + v8 + 32), "(addr - 4)");
      v8 += 8;
    }
    while ( v8 != 3072 );
    v10 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 200LL);
    sde_reg_write((__int64)a1, v10 + 8, *(_DWORD *)(v5 + 8), "addr");
    sde_reg_write((__int64)a1, v10 + 12, *(_DWORD *)(v5 + 12), "(addr + 4)");
    sde_reg_write((__int64)a1, v10 + 16, *(_DWORD *)(v5 + 16), "(addr + 8)");
    v11 = sde_reg_read((__int64)a1, *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL) + 64);
    sde_reg_write(
      (__int64)a1,
      *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL) + 64,
      v11 & 0xFFFF0FFF | ((*(_WORD *)(v5 + 20) & 3) << 12) & 0x3FFF | ((*(_DWORD *)(v5 + 24) & 3) << 14),
      "(ctx->cap->sblk->hsic.base + DSPP_PA_PWL_HOLD_OFF)");
    v12 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL);
    if ( *(_DWORD *)v5 << 29 )
      v13 = ((unsigned __int8)*(_DWORD *)v5 << 29) | 0x100000;
    else
      v13 = 0;
    v14 = v13 | v6 & 0x1FFFFFFF;
    return sde_reg_write((__int64)a1, v12, v14, "ctx->cap->sblk->hsic.base");
  }
  return _drm_err("invalid size of payload len %d exp %zd\n", v7, 0x1228u);
}
