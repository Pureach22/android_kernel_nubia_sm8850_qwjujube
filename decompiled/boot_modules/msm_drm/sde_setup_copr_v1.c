void __fastcall sde_setup_copr_v1(__int64 a1, _DWORD *a2, __int64 a3)
{
  int v5; // w22
  __int64 v6; // x21
  int v7; // w1
  __int64 v8; // x21
  char v9; // t1
  int v11; // w4
  int v12; // w5
  size_t v13; // x0
  int v14; // w6
  int v15; // w2
  int v16; // w7
  __int64 v17; // x23
  int v18; // w22

  if ( !a1 || !a2 )
  {
    _drm_err("invalid parameters ctx %pK cfg %pK\n", (const void *)a1, a2);
    return;
  }
  v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 604LL);
  if ( !v5 )
  {
    _drm_dev_dbg(0, 0, 1, "AIQE not supported on DSPP idx %d", *(_DWORD *)(a1 + 64));
    return;
  }
  v6 = *(_QWORD *)a2;
  if ( !*(_QWORD *)a2 )
    goto LABEL_7;
  v7 = a2[2];
  if ( v7 != 80 )
  {
    _drm_err("invalid size of payload len %d exp %zd\n", v7, 0x50u);
    return;
  }
  v9 = *(_BYTE *)(v6 + 8);
  v8 = v6 + 8;
  if ( (v9 & 1) != 0 )
  {
    sde_setup_aiqe_common_v1(a1, (__int64)a2, a3);
    v17 = 0;
    v18 = v5 + 768;
    do
    {
      sde_reg_write(a1, v18 + v17, *(_DWORD *)(v8 + v17), "aiqe_base + 0x300 + (i * 4)");
      v17 += 4;
    }
    while ( v17 != 68 );
    v11 = *(_DWORD *)(a1 + 64);
    v12 = *(_DWORD *)(a1 + 1496);
    v13 = sde_dbg_base_evtlog;
    v14 = *(_DWORD *)(a1 + 28);
    v15 = 185;
    v16 = 1;
  }
  else
  {
LABEL_7:
    _drm_dev_dbg(0, 0, 1, "Disable COPR feature\n");
    sde_setup_aiqe_common_v1(a1, (__int64)a2, a3);
    sde_reg_write(a1, v5 + 768, 0, "aiqe_base + 0x300");
    v11 = *(_DWORD *)(a1 + 64);
    v12 = *(_DWORD *)(a1 + 1496);
    v13 = sde_dbg_base_evtlog;
    v14 = *(_DWORD *)(a1 + 28);
    v15 = 176;
    v16 = 0;
  }
  sde_evtlog_log(v13, "sde_setup_copr_v1", v15, -1, v11, v12, v14, v16, 239);
}
