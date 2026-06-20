__int64 __fastcall sde_setup_ucsc_igcv1_common(__int64 a1, unsigned int a2, _DWORD *a3)
{
  __int64 v4; // x10
  unsigned int v5; // w20
  int *v6; // x21
  int v7; // w3
  int v8; // w0
  int v9; // w1
  __int64 v10; // x2
  int v11; // w8

  if ( a2 == 3 || !a1 || !a3 )
    return _drm_err("invalid parameter\tctx: %pK\tdata: %pK\tindex: %d\n", (const void *)a1, a3, a2);
  v4 = 896;
  if ( a2 < 2 )
    v4 = 860;
  v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 56) + 48LL) + v4);
  if ( !v5 )
    return _drm_err("invalid offset for UCSC GC CP block\tpipe: %d\tindex: %d\n", *(_DWORD *)(a1 + 48), a2);
  v6 = *(int **)a3;
  v7 = a3[2];
  if ( !*(_QWORD *)a3 || v7 != 4 )
    return _drm_err(
             "invalid hw_cfg payload\tpipe: %d\tindex: %d\tlen: %d\tpayload: %pK\n",
             *(_DWORD *)(a1 + 48),
             a2,
             v7,
             v6);
  v8 = sde_reg_read(a1, v5);
  v9 = *v6;
  v10 = v8 & 0xFFFFF8FD;
  if ( !*v6 )
    return sde_reg_write(a1, v5, v10, "igc_base");
  if ( v9 <= 2 )
  {
    if ( v9 == 1 )
    {
      v10 = (unsigned int)v10 | 2;
      return sde_reg_write(a1, v5, v10, "igc_base");
    }
    if ( v9 == 2 )
    {
      v11 = 258;
      goto LABEL_23;
    }
    return _drm_err("Invalid UCSC IGC mode \tmode: %d\n", v9);
  }
  if ( v9 == 3 )
  {
    v11 = 514;
    goto LABEL_23;
  }
  if ( v9 == 4 )
  {
    v11 = 770;
    goto LABEL_23;
  }
  if ( v9 != 5 )
    return _drm_err("Invalid UCSC IGC mode \tmode: %d\n", v9);
  v11 = 1026;
LABEL_23:
  v10 = (unsigned int)v10 | v11;
  return sde_reg_write(a1, v5, v10, "igc_base");
}
