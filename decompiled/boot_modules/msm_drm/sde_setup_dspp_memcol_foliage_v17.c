__int64 __fastcall sde_setup_dspp_memcol_foliage_v17(_QWORD *a1, _DWORD *a2)
{
  int v4; // w20
  int v5; // w1
  unsigned int v6; // w1
  unsigned int v7; // w2
  int v9; // w8

  if ( !a1 || !a2 )
    return _drm_err("invalid param ctx %pK cfg %pK\n", a1, a2);
  v4 = sde_reg_read((__int64)a1, *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL));
  if ( !*(_QWORD *)a2 )
  {
    _drm_dev_dbg(0, 0, 1, "disable memcolor foliage feature\n");
    v6 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL);
    if ( (v4 & 0xFE0100A0) != 0 )
      v9 = -65;
    else
      v9 = 32440095;
    v7 = v9 & v4;
    return sde_reg_write((__int64)a1, v6, v7, "ctx->cap->sblk->hsic.base");
  }
  v5 = a2[2];
  if ( v5 == 48 )
  {
    _setup_dspp_memcol_0((__int64)a1, 2, *(unsigned int **)a2);
    v6 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 128LL);
    v7 = v4 | 0x100040;
    return sde_reg_write((__int64)a1, v6, v7, "ctx->cap->sblk->hsic.base");
  }
  return _drm_err("invalid size of payload len %d exp %zd\n", v5, 0x30u);
}
