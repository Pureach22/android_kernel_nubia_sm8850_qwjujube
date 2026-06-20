__int64 __fastcall sde_setup_ucsc_unmultv1_common(__int64 a1, unsigned int a2, _DWORD *a3)
{
  int v4; // w3
  _BYTE *v5; // x4
  __int64 v6; // x10
  unsigned int v7; // w20
  int v9; // w0
  __int64 v10; // x2

  if ( a2 == 3 || !a1 || !a3 )
    return _drm_err("invalid parameter\tctx: %pK\tdata: %pK\tindex: %d\n", (const void *)a1, a3, a2);
  v4 = a3[2];
  v5 = *(_BYTE **)a3;
  if ( v4 != 1 || !v5 )
    return _drm_err(
             "invalid hw_cfg payload\tpipe: %d\tindex: %d\tlen: %d\tpayload: %pK\n",
             *(_DWORD *)(a1 + 48),
             a2,
             v4,
             v5);
  v6 = 1124;
  if ( a2 < 2 )
    v6 = 1088;
  v7 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 56) + 48LL) + v6);
  if ( !v7 )
    return _drm_err("invalid offset for UCSC UNMULT CP block\tpipe: %d\tindex: %d\n", *(_DWORD *)(a1 + 48), a2);
  v9 = sde_reg_read(a1, v7);
  if ( *(_QWORD *)a3 && **(_BYTE **)a3 == 1 )
    v10 = v9 | 0x40001u;
  else
    v10 = v9 & 0xFFFBFFFE;
  return sde_reg_write(a1, v7, v10, "unmult_base");
}
