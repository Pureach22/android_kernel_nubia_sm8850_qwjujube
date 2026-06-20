size_t __fastcall sde_setup_mdnie_art_v1(__int64 a1, _DWORD *a2)
{
  int v4; // w22
  __int64 v5; // x21
  int v6; // w1
  int v7; // w4
  int v8; // w5
  size_t v9; // x0
  int v10; // w6
  int v11; // w2
  int v12; // w7
  char v14; // w0

  if ( !a1 || !a2 )
    return _drm_err("invalid parameters ctx %pK cfg %pK\n", (const void *)a1, a2);
  v4 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 604LL);
  if ( !v4 )
    return _drm_err("AIQE not supported on DSPP idx %d", *(_DWORD *)(a1 + 64));
  v5 = *(_QWORD *)a2;
  if ( !*(_QWORD *)a2 )
    goto LABEL_7;
  v6 = a2[2];
  if ( v6 != 16 )
    return _drm_err("invalid size of payload len %d exp %zd\n", v6, 0x10u);
  if ( (*(_BYTE *)(v5 + 8) & 1) != 0 )
  {
    sde_setup_aiqe_common_v1(a1, a2);
    v14 = sde_reg_read(a1, v4 + 256);
    sde_reg_write(a1, v4 + 256, (*(_DWORD *)(v5 + 8) & 0xFFFFFF01 | v14 & 2) ^ 2, "aiqe_base + 0x100");
    v7 = *(_DWORD *)(a1 + 64);
    v8 = *(_DWORD *)(a1 + 1496);
    v9 = sde_dbg_base_evtlog;
    v10 = *(_DWORD *)(a1 + 28);
    v11 = 145;
    v12 = 1;
  }
  else
  {
LABEL_7:
    _drm_dev_dbg(0, 0, 1, "Disable MDNIE ART feature\n");
    sde_setup_aiqe_common_v1(a1, a2);
    sde_reg_write(a1, v4 + 256, 0, "aiqe_base + 0x100");
    v7 = *(_DWORD *)(a1 + 64);
    v8 = *(_DWORD *)(a1 + 1496);
    v9 = sde_dbg_base_evtlog;
    v10 = *(_DWORD *)(a1 + 28);
    v11 = 137;
    v12 = 0;
  }
  return sde_evtlog_log(v9, "sde_setup_mdnie_art_v1", v11, -1, v7, v8, v10, v12, 239);
}
