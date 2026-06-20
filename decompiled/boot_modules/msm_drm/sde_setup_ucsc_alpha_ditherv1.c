__int64 __fastcall sde_setup_ucsc_alpha_ditherv1(__int64 a1, unsigned int a2, __int64 a3)
{
  int v5; // w3
  _BYTE *v6; // x4
  __int64 v7; // x9
  unsigned int v8; // w21
  int v9; // w0
  __int64 v10; // x2

  if ( !a1 || a2 == 3 )
    return _drm_err("invalid parameter\tctx: %pK\tindex: %d\n", (const void *)a1, a2);
  v5 = *(_DWORD *)(a3 + 8);
  v6 = *(_BYTE **)a3;
  if ( v5 != 1 || !v6 )
    return _drm_err(
             "invalid hw_cfg payload\tpipe: %d\tindex: %d\tlen: %d\tpayload: %pK\n",
             *(_DWORD *)(a1 + 48),
             a2,
             v5,
             v6);
  v7 = 1200;
  if ( a2 < 2 )
    v7 = 1164;
  v8 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 56) + 48LL) + v7);
  if ( !v8 )
    return _drm_err("invalid offset for UCSC ALPHA DITHER CP block\tpipe: %d\tindex: %d\n", *(_DWORD *)(a1 + 48), a2);
  v9 = sde_reg_read(a1, v8);
  if ( *(_QWORD *)a3 && **(_BYTE **)a3 == 1 )
    v10 = v9 | 0x20000u;
  else
    v10 = v9 & 0xFFFDFFFF;
  return sde_reg_write(a1, v8, v10, "alpha_dither_base");
}
