__int64 __fastcall sde_setup_fp16_igcv1(__int64 a1, unsigned int a2, _DWORD *a3)
{
  int v4; // w3
  __int64 v5; // x10
  unsigned int v6; // w20
  int v8; // w0
  __int64 v9; // x2

  if ( a2 == 3 || !a1 || !a3 )
    return _drm_err("invalid parameter\tctx: %pK\tdata: %pK\tindex: %d\n", (const void *)a1, a3, a2);
  v4 = a3[2];
  if ( v4 != 1 )
    return _drm_err("invalid hw_cfg payload\tpipe: %d\tindex: %d\tlen: %d", *(_DWORD *)(a1 + 48), a2, v4);
  v5 = 592;
  if ( a2 < 2 )
    v5 = 556;
  v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 56) + 48LL) + v5);
  if ( !v6 )
    return _drm_err("invalid offset for FP16 IGC CP block\tpipe: %d\tindex: %d\n", *(_DWORD *)(a1 + 48), a2);
  v8 = sde_reg_read(a1, v6);
  if ( *(_QWORD *)a3 && **(_BYTE **)a3 == 1 )
    v9 = v8 | 2u;
  else
    v9 = v8 & 0xFFFFFFFD;
  return sde_reg_write(a1, v6, v9, "igc_base");
}
