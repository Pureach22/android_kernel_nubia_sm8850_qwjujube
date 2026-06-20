__int64 __fastcall sde_setup_fp16_gcv1(__int64 a1, unsigned int a2, _DWORD *a3)
{
  __int64 v4; // x21
  int v5; // w3
  __int64 v6; // x4
  __int64 v7; // x10
  unsigned int v8; // w20
  __int64 v9; // x2
  int v10; // w8
  unsigned int v11; // w8

  if ( a2 == 3 || !a1 || !a3 )
    return _drm_err("invalid parameter\tctx: %pK\tdata: %pK\tindex: %d\n", (const void *)a1, a3, a2);
  v4 = *(_QWORD *)a3;
  if ( *(_QWORD *)a3 )
  {
    v5 = a3[2];
    v6 = *(_QWORD *)(v4 + 8);
    if ( v5 != 16 || !v6 )
      return _drm_err(
               "invalid hw_cfg payload\tpipe: %d\tindex: %d\tlen: %d\tmode: %lld",
               *(_DWORD *)(a1 + 48),
               a2,
               v5,
               v6);
  }
  v7 = 668;
  if ( a2 < 2 )
    v7 = 632;
  v8 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 56) + 48LL) + v7);
  if ( !v8 )
    return _drm_err("invalid offset for FP16 GC CP block\tpipe: %d\tindex: %d\n", *(_DWORD *)(a1 + 48), a2);
  v9 = sde_reg_read(a1, v8) & 0xFFFFFF07LL;
  if ( v4 )
  {
    if ( (*(_BYTE *)v4 & 1) != 0 )
      v10 = 24;
    else
      v10 = 16;
    v11 = v10 | v9;
    if ( *(_QWORD *)(v4 + 8) == 2 )
      v9 = v11 | 0x20;
    else
      v9 = v11;
  }
  return sde_reg_write(a1, v8, v9, "gc_base");
}
