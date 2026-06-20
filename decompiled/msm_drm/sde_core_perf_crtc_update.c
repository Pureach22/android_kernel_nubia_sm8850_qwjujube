__int64 __fastcall sde_core_perf_crtc_update(__int64 result, int a2)
{
  _QWORD *v2; // x20
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 v5; // x26
  __int64 v6; // x19
  int v7; // w27
  unsigned int v8; // w24
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x11
  _QWORD *v17; // x25
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x26
  int v22; // w28
  __int64 v23; // x27
  unsigned __int64 *v24; // x23
  unsigned __int64 v25; // x6
  unsigned __int64 v26; // x7
  int v27; // w10
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x9
  int v30; // w12
  int v32; // w12
  void *v33; // x0
  char v34; // w19
  char v35; // w22
  __int64 v36; // x8
  unsigned __int64 v37; // x8
  __int64 v38; // x4
  unsigned __int64 v39; // x22
  __int64 *v40; // x19
  __int64 *i; // x8
  __int64 v42; // x0
  bool v43; // w8
  char v44; // [xsp+0h] [xbp-80h]
  int v45; // [xsp+3Ch] [xbp-44h]
  __int64 v46; // [xsp+40h] [xbp-40h]
  bool v47; // [xsp+70h] [xbp-10h]

  _ReadStatusReg(SP_EL0);
  if ( !result )
  {
    result = printk(&unk_25E167, "sde_core_perf_crtc_update");
    goto LABEL_103;
  }
  v2 = (_QWORD *)result;
  if ( !*(_QWORD *)result || (v3 = *(_QWORD *)(*(_QWORD *)result + 56LL)) == 0 )
  {
    v33 = &unk_231B33;
LABEL_65:
    printk(v33, "_sde_crtc_get_kms");
    goto LABEL_66;
  }
  v4 = *(_QWORD *)(v3 + 8);
  if ( !v4 )
  {
    v33 = &unk_234896;
    goto LABEL_65;
  }
  if ( !*(_QWORD *)(v4 + 152) )
  {
LABEL_66:
    result = printk(&unk_234896, "sde_core_perf_crtc_update");
    goto LABEL_103;
  }
  v5 = *(_QWORD *)(*(_QWORD *)(v4 + 136) + 56LL);
  if ( *(_DWORD *)(v5 + 5912) == 1 )
    goto LABEL_103;
  v6 = *(_QWORD *)(result + 2008);
  v7 = a2;
  v8 = a2 & 0xFFFFFFFD;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "crtc:%d commit_state:%d core_clk:%llu\n",
      *(_DWORD *)(result + 112),
      a2,
      *(_QWORD *)(v4 + 2008));
  mutex_lock(&sde_core_perf_lock);
  if ( v8 == 1 )
  {
    v9 = *(_QWORD *)(v6 + 4488);
    v10 = *(_QWORD *)(v6 + 4480);
    v2[937] = *(_QWORD *)(v6 + 4496);
    v2[936] = v9;
    v2[935] = v10;
    v11 = *(_QWORD *)(v6 + 4520);
    v12 = *(_QWORD *)(v6 + 4504);
    v13 = *(_QWORD *)(v6 + 4512);
    v2[941] = *(_QWORD *)(v6 + 4528);
    v2[940] = v11;
    v2[939] = v13;
    v2[938] = v12;
    v14 = *(_QWORD *)(v6 + 4552);
    v15 = *(_QWORD *)(v6 + 4536);
    v16 = *(_QWORD *)(v6 + 4544);
    v2[945] = *(_QWORD *)(v6 + 4560);
    v2[944] = v14;
    v2[943] = v16;
    v2[942] = v15;
  }
  v17 = v2 + 935;
  if ( v7 == 2 && *((_BYTE *)v2 + 7944) == 1 )
  {
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_core_perf_crtc_update",
      1155,
      -1,
      *(_QWORD *)(v4 + 136),
      2,
      1,
      -1059143953,
      v44);
    v17 = v2 + 924;
    *((_BYTE *)v2 + 7944) = 0;
  }
  if ( (sde_cesta_is_enabled(**(unsigned int **)(*(_QWORD *)(v4 + 136) + 64LL)) & 1) != 0 )
  {
    v18 = v2[1002];
    if ( !v18 )
      goto LABEL_102;
    if ( *(_BYTE *)(v6 + 481) == 1 && !*(_DWORD *)(v4 + 2024) )
    {
      if ( v6 )
        goto LABEL_19;
    }
    else if ( v6 )
    {
LABEL_19:
      v19 = *(_QWORD *)(v6 + 1696);
LABEL_98:
      v2[944] = v19;
      v43 = (unsigned int)(v7 - 3) < 2 || *(_BYTE *)(v18 + 56) != (v7 != 4);
      v47 = v43;
      sde_cesta_clk_bw_update();
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_core_perf_crtc_cesta_update",
        134,
        -1,
        *((_DWORD *)v2 + 28),
        v7 != 4,
        v7 == 2,
        v47,
        v7);
      goto LABEL_102;
    }
    v19 = 0;
    goto LABEL_98;
  }
  if ( v7 == 4 || !*((_BYTE *)v2 + 172) )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "crtc=%d disable\n", *((_DWORD *)v2 + 28));
    v2[933] = 0;
    v2[934] = 0;
    v34 = 0;
    v2[931] = 0;
    v2[932] = 0;
    v2[929] = 0;
    v2[930] = 0;
    v2[927] = 0;
    v2[928] = 0;
    v2[925] = 0;
    v2[926] = 0;
    v2[924] = 0;
    v35 = -1;
    v17[9] = 0;
    v17[10] = 0;
    v17[7] = 0;
    v17[8] = 0;
    v17[5] = 0;
    v17[6] = 0;
    v17[3] = 0;
    v17[4] = 0;
    v17[1] = 0;
    v17[2] = 0;
    *v17 = 0;
    goto LABEL_78;
  }
  if ( !*v2 || (v20 = *(_QWORD *)(*v2 + 56LL)) == 0 )
  {
    printk(&unk_231B33, "_sde_crtc_get_kms");
    goto LABEL_102;
  }
  v46 = v5;
  v21 = *(_QWORD *)(v20 + 8);
  if ( !v21 )
  {
    printk(&unk_234896, "_sde_crtc_get_kms");
    goto LABEL_102;
  }
  v45 = v7;
  v22 = 0;
  v23 = 0;
  v24 = v2 + 939;
  do
  {
    v25 = *v24;
    v26 = *(v24 - 11);
    v27 = 1 << v23;
    v28 = *(v24 - 4);
    v29 = *(v24 - 15);
    if ( v8 == 1 )
    {
      if ( v28 <= v29 )
      {
        if ( v25 <= v26 )
          v30 = 0;
        else
          v30 = 1 << v23;
        v22 |= v30;
        if ( *(_DWORD *)(v21 + 2088) != 1 )
          goto LABEL_50;
      }
      else
      {
        v22 |= v27;
        if ( *(_DWORD *)(v21 + 2088) != 1 )
          goto LABEL_50;
      }
      if ( v28 == v29 && v25 == v26 )
        v27 = 0;
      v22 |= v27;
    }
    else if ( v28 >= v29 )
    {
      if ( v25 >= v26 )
        v32 = 0;
      else
        v32 = 1 << v23;
      v22 |= v32;
      if ( *(_DWORD *)(v21 + 2088) == 1 )
LABEL_49:
        v22 &= ~v27;
    }
    else
    {
      v22 |= v27;
      if ( *(_DWORD *)(v21 + 2088) == 1 )
        goto LABEL_49;
    }
LABEL_50:
    if ( (((unsigned __int64)v22 >> v23) & 1) != 0 )
    {
      if ( (_drm_debug & 4) != 0 )
      {
        _drm_dev_dbg(
          0,
          0,
          0,
          "crtc=%d p=%d new_bw=%llu,old_bw=%llu new_ib=%llu old_ib=%llu\n",
          *((_DWORD *)v2 + 28),
          v8 == 1,
          v25,
          v26,
          *(v24 - 4),
          v29);
        v25 = *v24;
        v28 = *(v24 - 4);
      }
      *(v24 - 11) = v25;
      *(v24 - 15) = v28;
    }
    ++v23;
    ++v24;
  }
  while ( v23 != 4 );
  if ( *(_BYTE *)(v21 + 2048) == 1 )
  {
    v36 = *(_QWORD *)(v21 + 2032);
    if ( v36 )
      v2[943] = v36;
  }
  v37 = v2[943];
  v7 = v45;
  if ( v8 == 1 )
  {
    if ( v37 > v2[932] )
      goto LABEL_70;
LABEL_69:
    if ( *(_BYTE *)(v21 + 2048) == 1 )
      goto LABEL_70;
    v34 = 1;
  }
  else
  {
    if ( !v37 || v37 >= v2[932] )
      goto LABEL_69;
LABEL_70:
    v34 = 0;
    v2[932] = v37;
    *(_BYTE *)(v21 + 2048) = 0;
  }
  v5 = v46;
  v35 = v22;
  if ( (v22 & 1) == 0 )
  {
    if ( (v22 & 2) == 0 )
      goto LABEL_74;
LABEL_79:
    sde_core_perf_crtc_update_bus(v4, v2, 1u);
    if ( (v35 & 4) != 0 )
      goto LABEL_80;
LABEL_75:
    if ( (v35 & 8) == 0 )
      goto LABEL_76;
LABEL_81:
    sde_core_perf_crtc_update_bus(v4, v2, 3u);
    if ( (v34 & 1) == 0 )
      goto LABEL_82;
    goto LABEL_102;
  }
LABEL_78:
  sde_core_perf_crtc_update_bus(v4, v2, 0);
  if ( (v35 & 2) != 0 )
    goto LABEL_79;
LABEL_74:
  if ( (v35 & 4) == 0 )
    goto LABEL_75;
LABEL_80:
  sde_core_perf_crtc_update_bus(v4, v2, 2u);
  if ( (v35 & 8) != 0 )
    goto LABEL_81;
LABEL_76:
  if ( (v34 & 1) == 0 )
  {
LABEL_82:
    v38 = *(_QWORD *)(v4 + 136);
    v39 = *(_QWORD *)(v4 + 2032);
    v40 = *(__int64 **)(v38 + 864);
    for ( i = (__int64 *)(v38 + 864); v40 != i; i = (__int64 *)(v38 + 864) )
    {
      if ( v40 != &qword_10 && *((_BYTE *)v40 + 156) )
      {
        v42 = clk_round_rate(*(_QWORD *)(v4 + 2000));
        v38 = *(_QWORD *)(v4 + 136);
        v39 = v42;
      }
      v40 = (__int64 *)*v40;
    }
    if ( *(_DWORD *)(v4 + 2024) == 2 && *(_QWORD *)(v4 + 2064) > v39 )
      v39 = *(_QWORD *)(v4 + 2064);
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "clk:%llu\n", v39);
      v38 = *(_QWORD *)(v4 + 136);
    }
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_core_perf_crtc_update", 1196, -1, v38, v7, v39, v2[932], v17[8]);
    if ( (unsigned int)sde_power_clk_set_rate(v5 + 16, *(_QWORD *)(v4 + 1992), v39, 0) )
    {
      printk(&unk_235203, "sde_core_perf_crtc_update");
    }
    else
    {
      *(_QWORD *)(v4 + 2008) = v39;
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "update clk rate = %lld HZ\n", v39);
    }
  }
LABEL_102:
  result = mutex_unlock(&sde_core_perf_lock);
LABEL_103:
  _ReadStatusReg(SP_EL0);
  return result;
}
