__int64 __fastcall sde_core_perf_crtc_check(__int64 *a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x25
  unsigned __int64 v6; // x12
  __int64 v7; // x22
  unsigned __int64 v8; // x8
  bool v9; // zf
  unsigned __int64 v10; // x11
  unsigned __int64 v11; // x13
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x10
  unsigned __int64 v14; // x5
  char v15; // w14
  int v16; // w14
  __int64 v17; // x11
  unsigned __int64 v18; // x12
  __int64 result; // x0
  __int64 v20; // x0
  __int64 v21; // x21
  __int64 v22; // x23
  __int64 v23; // x8
  int v24; // w25
  __int64 *v25; // x27
  __int64 v26; // x26
  __int64 i; // x8
  __int64 *v28; // x8
  __int64 v29; // x24
  int v30; // w9
  __int64 v31; // x22
  unsigned __int64 v32; // x25
  unsigned int v33; // w26
  void *v34; // x0
  __int64 v35; // [xsp+30h] [xbp-40h]

  _ReadStatusReg(SP_EL0);
  if ( !a1 || !a2 )
  {
    printk(&unk_25E167, "sde_core_perf_crtc_check");
    result = 4294967274LL;
    goto LABEL_76;
  }
  if ( !*a1 || (v4 = *(_QWORD *)(*a1 + 56)) == 0 )
  {
    v34 = &unk_231B33;
LABEL_73:
    printk(v34, "_sde_crtc_get_kms");
    goto LABEL_74;
  }
  v5 = *(_QWORD *)(v4 + 8);
  if ( !v5 )
  {
    v34 = &unk_234896;
    goto LABEL_73;
  }
  if ( !*(_QWORD *)(v5 + 152) )
  {
LABEL_74:
    printk(&unk_27D28A, "sde_core_perf_crtc_check");
    goto LABEL_75;
  }
  v6 = *(_QWORD *)(a2 + 1152);
  v7 = *(_QWORD *)(*(_QWORD *)(v5 + 136) + 56LL);
  v8 = *(_QWORD *)(a2 + 1120);
  v9 = *(_BYTE *)(a2 + 482) == 1;
  v10 = v6;
  v11 = v6;
  *(_QWORD *)(a2 + 4560) = 0;
  v12 = v8;
  v13 = v8;
  *(_QWORD *)(a2 + 4552) = 0;
  *(_QWORD *)(a2 + 4544) = 0;
  *(_QWORD *)(a2 + 4536) = 0;
  *(_QWORD *)(a2 + 4528) = 0;
  *(_QWORD *)(a2 + 4520) = 0;
  *(_QWORD *)(a2 + 4504) = 0;
  *(_QWORD *)(a2 + 4512) = v8;
  *(_QWORD *)(a2 + 4480) = v6;
  if ( v9 )
  {
    v12 = *(_QWORD *)(a2 + 1184);
    v11 = *(_QWORD *)(a2 + 1216);
    v13 = *(_QWORD *)(a2 + 1248);
    v10 = *(_QWORD *)(a2 + 1280);
  }
  v14 = *(_QWORD *)(a2 + 1088);
  v15 = *(_BYTE *)(a2 + 481);
  *(_QWORD *)(a2 + 4520) = v12;
  *(_QWORD *)(a2 + 4488) = v11;
  *(_QWORD *)(a2 + 4528) = v13;
  *(_QWORD *)(a2 + 4496) = v10;
  *(_QWORD *)(a2 + 4544) = v14;
  if ( (v15 & 1) != 0 )
  {
    v16 = *(_DWORD *)(v5 + 2024);
    if ( v16 != 2 )
    {
      if ( v16 == 1 )
      {
        BYTE4(v12) = 0;
        v8 = 0;
        LODWORD(v14) = 0;
        v13 = 0;
        *(_QWORD *)(a2 + 4536) = 0;
        *(_QWORD *)(a2 + 4544) = 0;
        *(_QWORD *)(a2 + 4520) = 0;
        *(_QWORD *)(a2 + 4528) = 0;
        *(_QWORD *)(a2 + 4504) = 0;
        *(_QWORD *)(a2 + 4512) = 0;
        *(_QWORD *)(a2 + 4488) = 0;
        *(_QWORD *)(a2 + 4496) = 0;
        *(_QWORD *)(a2 + 4480) = 0;
      }
      goto LABEL_30;
    }
    if ( *(_QWORD *)(v5 + 2080) > v8 )
      v8 = *(_QWORD *)(v5 + 2080);
    *(_QWORD *)(a2 + 4512) = v8;
    if ( *(_QWORD *)(v5 + 2072) > v6 )
      v6 = *(_QWORD *)(v5 + 2072);
    *(_QWORD *)(a2 + 4480) = v6;
    if ( *(_QWORD *)(v5 + 2080) > v12 )
      v12 = *(_QWORD *)(v5 + 2080);
    *(_QWORD *)(a2 + 4520) = v12;
    v18 = *(_QWORD *)(v5 + 2072);
    if ( v18 <= v11 )
      v18 = v11;
    *(_QWORD *)(a2 + 4488) = v18;
    if ( *(_QWORD *)(v5 + 2080) > v13 )
      v13 = *(_QWORD *)(v5 + 2080);
    *(_QWORD *)(a2 + 4528) = v13;
    if ( *(_QWORD *)(v5 + 2072) > v10 )
      v10 = *(_QWORD *)(v5 + 2072);
    *(_QWORD *)(a2 + 4496) = v10;
    *(_QWORD *)(a2 + 4536) = *(_QWORD *)(v5 + 2080);
    *(_QWORD *)(a2 + 4504) = *(_QWORD *)(v5 + 2072);
    if ( *(_QWORD *)(v5 + 2064) > v14 )
      v14 = *(_QWORD *)(v5 + 2064);
  }
  else
  {
    v8 = 1000LL * *(unsigned int *)(*(_QWORD *)(v5 + 152) + 21708LL);
    *(_QWORD *)(a2 + 4512) = v8;
    *(_QWORD *)(a2 + 4480) = v8;
    v12 = 1000LL * *(unsigned int *)(*(_QWORD *)(v5 + 152) + 21708LL);
    *(_QWORD *)(a2 + 4520) = v12;
    *(_QWORD *)(a2 + 4488) = v12;
    v13 = 1000LL * *(unsigned int *)(*(_QWORD *)(v5 + 152) + 21708LL);
    *(_QWORD *)(a2 + 4528) = v13;
    *(_QWORD *)(a2 + 4496) = v13;
    v17 = 1000LL * *(unsigned int *)(*(_QWORD *)(v5 + 152) + 21708LL);
    *(_QWORD *)(a2 + 4536) = v17;
    *(_QWORD *)(a2 + 4504) = v17;
    v14 = *(_QWORD *)(v5 + 2016);
  }
  *(_QWORD *)(a2 + 4544) = v14;
LABEL_30:
  *(_QWORD *)(a2 + 4504) = 0;
  *(_QWORD *)(a2 + 4536) = (unsigned __int16)(126 * (v13 % 0x64)) / 0x64u + 126 * (v13 / 0x64);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_core_perf_calc_crtc",
    220,
    -1,
    *((_DWORD *)a1 + 28),
    v14,
    SHIDWORD(v8),
    v8,
    SBYTE4(v12));
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_core_perf_calc_crtc",
    227,
    -1,
    *((_DWORD *)a1 + 28),
    HIDWORD(*(_QWORD *)(a2 + 4480)),
    *(_QWORD *)(a2 + 4480),
    HIDWORD(*(_QWORD *)(a2 + 4488)),
    *(_QWORD *)(a2 + 4488));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "crtc=%d clk_rate=%llu core_ib=%llu core_ab=%llu llcc_ib=%llu llcc_ab=%llu mem_ib=%llu mem_ab=%llu\n",
      *((_DWORD *)a1 + 28),
      *(_QWORD *)(a2 + 4544),
      *(_QWORD *)(a2 + 4480),
      *(_QWORD *)(a2 + 4512),
      *(_QWORD *)(a2 + 4488),
      *(_QWORD *)(a2 + 4520),
      *(_QWORD *)(a2 + 4496),
      *(_QWORD *)(a2 + 4528));
  if ( (sde_cesta_is_enabled(**(unsigned int **)(*(_QWORD *)(v5 + 136) + 64LL)) & 1) != 0 )
  {
    if ( a1[1002] )
    {
      if ( *(_BYTE *)(a2 + 481) == 1 && !*(_DWORD *)(v5 + 2024) )
        *(_QWORD *)(a2 + 4552) = *(_QWORD *)(a2 + 1696);
      else
        *(_QWORD *)(a2 + 4552) = *(_QWORD *)(a2 + 1696);
      result = sde_cesta_clk_bw_check();
      goto LABEL_76;
    }
LABEL_75:
    result = 0;
    goto LABEL_76;
  }
  if ( *(_QWORD *)(a2 + 4544) > *(_QWORD *)(v5 + 2008) )
  {
    v20 = clk_round_rate(*(_QWORD *)(v5 + 2000));
    if ( (unsigned int)sde_power_clk_set_rate(v7 + 16, *(_QWORD *)(v5 + 1992), v20, 1) )
    {
      printk(&unk_25E9C7, "sde_core_perf_crtc_check");
      goto LABEL_80;
    }
  }
  v21 = 0;
  v22 = v7 + 200;
  v35 = v5;
  while ( 2 )
  {
    if ( !*(_DWORD *)(v22 + 40 * v21 + 32) )
      goto LABEL_41;
    v23 = a1[251];
    if ( v23 )
      v24 = 2 * (*(_QWORD *)(v23 + 472) != 0);
    else
      v24 = 0;
    v25 = *(__int64 **)(*a1 + 864);
    v26 = *(_QWORD *)(a2 + 4512 + 8 * v21);
    for ( i = *a1 + 864; v25 != (__int64 *)i; i = *a1 + 864 )
    {
      v28 = v25 - 2;
      if ( v25 != &qword_10 && *((_BYTE *)v25 + 156) )
      {
        v29 = v25[249];
        if ( v29 )
        {
          v30 = 2 * (*(_QWORD *)(v29 + 472) != 0);
          if ( v28 == a1 )
            goto LABEL_47;
        }
        else
        {
          v30 = 0;
          if ( v28 == a1 )
            goto LABEL_47;
        }
        if ( v30 == v24 )
        {
          v31 = v29 + 8 * v21;
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "crtc:%d bw:%llu ctrl:%d\n",
              *((_DWORD *)v25 + 24),
              *(_QWORD *)(v31 + 4512),
              *(unsigned __int8 *)(v29 + 481));
          if ( *(_BYTE *)(v29 + 481) == 1 )
            v26 += *(_QWORD *)(v31 + 4512);
        }
      }
LABEL_47:
      v25 = (__int64 *)*v25;
    }
    v32 = (v26 + 999) / 0x3E8uLL;
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "calculated bandwidth=%uk\n", v32);
      v33 = *(_DWORD *)(*(_QWORD *)(v35 + 152) + 21708LL);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "final threshold bw limit = %d\n", v33);
    }
    else
    {
      v33 = *(_DWORD *)(*(_QWORD *)(v35 + 152) + 21708LL);
    }
    if ( (*(_BYTE *)(a2 + 481) & 1) == 0 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "bypass bandwidth check\n");
      goto LABEL_41;
    }
    if ( v33 )
    {
      if ( v33 < (unsigned int)v32 )
      {
        printk(&unk_27A3B4, "sde_core_perf_crtc_check");
        goto LABEL_80;
      }
LABEL_41:
      if ( ++v21 == 4 )
        goto LABEL_75;
      continue;
    }
    break;
  }
  printk(&unk_219A81, "sde_core_perf_crtc_check");
LABEL_80:
  result = 4294967289LL;
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return result;
}
