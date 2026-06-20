__int64 __fastcall sde_setup_dspp_gc_v1_7(__int64 a1, _DWORD *a2)
{
  _DWORD *v2; // x20
  int v4; // w3
  int v5; // w24
  __int64 v6; // x25
  int v7; // w24
  __int64 v8; // x0
  unsigned int v9; // w1
  unsigned int v10; // w2

  if ( !a2 )
  {
    v2 = nullptr;
    v4 = 0;
    return _drm_err("hw %pK payload %pK payloadsize %d exp size %zd\n", a2, v2, v4, 0x1E08u);
  }
  v2 = *(_DWORD **)a2;
  if ( *(_QWORD *)a2 )
  {
    v4 = a2[2];
    if ( v4 == 7688 )
    {
      v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 92LL);
      sde_reg_write(a1, v5 + 8, 0, "c0_off");
      sde_reg_write(a1, v5 + 16, 0, "c1_off");
      sde_reg_write(a1, v5 + 24, 0, "c2_off");
      v6 = 0;
      v7 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 92LL);
      do
      {
        sde_reg_write(a1, v7 + 4, v2[v6 + 2], "c0_off");
        sde_reg_write(a1, v7 + 12, v2[v6 + 514], "c1_off");
        sde_reg_write(a1, v7 + 20, v2[v6 + 1026], "c2_off");
        ++v6;
      }
      while ( v6 != 512 );
      sde_reg_write(
        a1,
        *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 92LL) + 28,
        1u,
        "ctx->cap->sblk->gc.base + PGC_LUT_SWAP_OFF");
      v8 = a1;
      v9 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 92LL);
      v10 = (2 * (*v2 & 1)) | 1;
      return sde_reg_write(v8, v9, v10, "ctx->cap->sblk->gc.base");
    }
    return _drm_err("hw %pK payload %pK payloadsize %d exp size %zd\n", a2, v2, v4, 0x1E08u);
  }
  _drm_dev_dbg(0, 0, 1, "Disable pgc feature\n");
  v8 = a1;
  v10 = 0;
  v9 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 92LL);
  return sde_reg_write(v8, v9, v10, "ctx->cap->sblk->gc.base");
}
