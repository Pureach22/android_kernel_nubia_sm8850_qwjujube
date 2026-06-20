void __fastcall sde_setup_aiqe_abc_v1(__int64 a1, unsigned int **a2, const void *a3)
{
  __int64 v6; // x8
  int v7; // w22
  unsigned int *v8; // x9
  unsigned int v9; // w10
  unsigned int *v10; // x23
  unsigned int v11; // w11
  unsigned int v12; // w12
  unsigned int v13; // w13
  int v14; // w4
  unsigned int v15; // w11
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x3
  int v24; // w1
  __int64 i; // x24
  int v26; // w4
  int v27; // w5
  size_t v28; // x0
  int v29; // w6
  int v30; // w2
  int v31; // w7

  if ( !a1 || !a2 || !a3 )
  {
    _drm_err("invalid parameters ctx %pK cfg %pK aiqe top %pK\n", (const void *)a1, a2, a3);
    return;
  }
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL);
  v7 = *(_DWORD *)(v6 + 604);
  if ( !v7 )
  {
    _drm_dev_dbg(0, 0, 1, "AIQE not supported on DSPP idx %d", *(_DWORD *)(a1 + 64));
    return;
  }
  v8 = *a2;
  if ( !*a2 )
    goto LABEL_30;
  v10 = v8 + 3;
  v9 = v8[3];
  if ( (v9 & 1) == 0 || (*((_BYTE *)a2 + 100) & 1) == 0 )
  {
    printk(&unk_2581AB, v9 & 1);
    goto LABEL_30;
  }
  v11 = *((_DWORD *)a2 + 24);
  if ( v11 == 1080 )
  {
    v12 = *((_DWORD *)a2 + 23);
    if ( -1431655765 * v12 < 0x55555556 )
    {
      v13 = 3;
      goto LABEL_17;
    }
  }
  else
  {
    if ( (v11 & 3) != 0 )
      goto LABEL_30;
    v12 = *((_DWORD *)a2 + 23);
  }
  if ( (v12 & 3) != 0 )
    goto LABEL_30;
  v13 = 4;
LABEL_17:
  v14 = v11 / v13;
  v15 = v8[4];
  v16 = v15 & 0xFFF;
  v17 = HIWORD(v15) & 0xFFF;
  v18 = v12 / v13;
  if ( v14 != (_DWORD)v16 || (_DWORD)v18 != (_DWORD)v17 )
  {
    _drm_err("invalid plane param h %d w %d exp h %d exp w %d\n", v16, v17, v18);
    goto LABEL_30;
  }
  v20 = *((unsigned int *)a2 + 28);
  v19 = *((unsigned int *)a2 + 29);
  if ( __PAIR64__(v18, (unsigned int)(3 * v14 + 3) >> 2) != __PAIR64__(v19, v20) )
  {
    _drm_err("real plane invalid plane h %d w %d exp h %d exp w %d\n", v19, v20, v18);
    goto LABEL_30;
  }
  if ( (v9 & 2) != 0 )
  {
    if ( ((_BYTE)a2[15] & 1) != 0 )
    {
      v22 = *((unsigned int *)a2 + 33);
      v21 = *((unsigned int *)a2 + 34);
      v23 = HIWORD(v8[27]) & 0xFFF;
      if ( __PAIR64__(v23, (3 * (v8[27] & 0xFFF)) >> 2) == __PAIR64__(v21, v22) )
        goto LABEL_23;
      _drm_err("virt plane invalid plane h %d w %d exp h %d exp w %d\n", v21, v22, v23);
    }
    else
    {
      printk(&unk_2581AB, v9 & 2);
    }
LABEL_30:
    _drm_dev_dbg(0, 0, 1, "Disable ABC feature\n");
    if ( !*a2 )
      sde_setup_aiqe_common_v1(a1, (__int64)a2, (__int64)a3);
    sde_reg_write(a1, v7 + 32, 0, "aiqe_base + 0x020");
    v26 = *(_DWORD *)(a1 + 64);
    v27 = *(_DWORD *)(a1 + 1496);
    v28 = sde_dbg_base_evtlog;
    v29 = *(_DWORD *)(a1 + 28);
    v30 = 890;
    v31 = 0;
    goto LABEL_33;
  }
LABEL_23:
  v24 = *((_DWORD *)a2 + 2);
  if ( v24 != 192 )
  {
    _drm_err("invalid size of payload len %d exp %zd\n", v24, 0xC0u);
    return;
  }
  sde_reg_write(a1, *(_DWORD *)(v6 + 680) + 4, v8[2], "ctx->cap->sblk->aiqe_wrapper.base + 0x4");
  for ( i = 0; i != 44; ++i )
    sde_reg_write(a1, v7 + 32 + i * 4, v10[i], "aiqe_base + 0x020 + (i * sizeof(u32))");
  sde_setup_aiqe_common_v1(a1, (__int64)a2, (__int64)a3);
  v26 = *(_DWORD *)(a1 + 64);
  v27 = *(_DWORD *)(a1 + 1496);
  v28 = sde_dbg_base_evtlog;
  v29 = *(_DWORD *)(a1 + 28);
  v30 = 906;
  v31 = 1;
LABEL_33:
  sde_evtlog_log(v28, "sde_setup_aiqe_abc_v1", v30, -1, v26, v27, v29, v31, 239);
}
