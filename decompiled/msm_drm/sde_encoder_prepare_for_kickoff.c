__int64 __fastcall sde_encoder_prepare_for_kickoff(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v9; // x8
  __int64 v11; // x9
  __int64 v12; // x21
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 dyn_hdr_meta; // x0
  __int64 v18; // x1
  unsigned int v19; // w21
  __int64 v20; // x8
  __int64 v21; // x22
  __int64 v22; // x10
  __int64 (__fastcall *v23)(__int64, __int64, __int64, _BOOL8); // x8
  __int64 v24; // x2
  _BOOL8 v25; // x3
  __int64 v26; // x24
  char v27; // w25
  __int64 v28; // x21
  __int64 v29; // x22
  int v30; // w6
  int v31; // w7
  _DWORD *v32; // x8
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x8
  unsigned int v37; // w26
  int v38; // w8
  __int64 *v39; // x23
  char v40; // w28
  void (*v41)(void); // x9
  char v42; // w28
  void (*v43)(void); // x9
  void *v44; // x0
  void *v45; // x0
  __int64 v46; // x8
  __int64 v47; // x0
  unsigned int disp_op; // w8
  __int64 v49; // x9
  __int64 v50; // x0
  void (*v51)(void); // x8
  void *v52; // x0
  const char *v53; // x1
  void *v54; // x0
  unsigned int v55; // w21
  void *v56; // x0
  __int64 v57; // x8
  __int64 v58; // x8
  __int64 v59; // x8
  unsigned int v60; // w0
  unsigned int v61; // w8
  __int64 v62; // x0
  void (*v63)(void); // x9
  __int64 v64; // x0
  void (*v65)(void); // x9
  __int64 v66; // x0
  void (*v67)(void); // x9
  __int64 v68; // x0
  void (*v69)(void); // x9
  int v70; // w22
  __int64 v71; // x8
  __int64 v72; // x8
  __int64 v73; // x8
  int v74; // w6
  __int64 v75; // x9
  int v76; // w21
  int v77; // w10
  __int64 v78; // x9
  int v79; // w10
  unsigned __int64 v80; // x8
  __int64 v81; // x27
  __int64 v82; // x28
  __int64 v83; // x25
  _DWORD *v84; // x9
  int v85; // w24
  __int64 v86; // x21
  __int64 v87; // x0
  unsigned int v88; // w8
  __int64 v89; // x1
  _BOOL4 v90; // w21
  __int64 v91; // x8
  __int64 v92; // x21
  __int64 v93; // x8
  __int64 v94; // x8
  __int16 v95; // w9
  __int64 v96; // x9
  __int64 v97; // x8
  unsigned int v98; // w0
  unsigned int v99; // w0
  __int64 v100; // x1
  __int64 v101; // x23
  __int64 v102; // x20
  unsigned int v103; // w22
  __int64 v104; // x8
  __int64 v105; // x0
  unsigned int v106; // w0
  __int64 v107; // x8
  __int64 v108; // x23
  _DWORD *v109; // x9
  void (__fastcall *v110)(__int64, __int64); // x8
  __int64 v111; // x1
  void *v113; // x0
  char v114; // [xsp+0h] [xbp-70h]
  char v115; // [xsp+0h] [xbp-70h]
  char v116; // [xsp+3Ch] [xbp-34h]
  __int64 v117; // [xsp+40h] [xbp-30h]
  int v118; // [xsp+4Ch] [xbp-24h]
  _QWORD v119[4]; // [xsp+50h] [xbp-20h] BYREF

  v119[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 || (v9 = *(_QWORD *)a1) == 0 || (v11 = *(_QWORD *)(v9 + 56)) == 0 )
  {
    v52 = &unk_211DA1;
    v53 = "sde_encoder_prepare_for_kickoff";
LABEL_91:
    printk(v52, v53);
    v55 = -22;
    goto LABEL_217;
  }
  v12 = *(_QWORD *)(v11 + 8);
  if ( !v12 )
  {
    v52 = &unk_234896;
    v53 = "sde_encoder_get_kms";
    goto LABEL_91;
  }
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "enc%d \n", *(_DWORD *)(a1 + 24));
    v9 = *(_QWORD *)a1;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_prepare_for_kickoff",
    7026,
    -1,
    *(_DWORD *)(a1 + 24),
    **(_DWORD **)(v9 + 64),
    -1059143953,
    a8,
    v114);
  v13 = *(_QWORD *)(a1 + 328);
  if ( v13 )
  {
    v14 = *(_QWORD *)(v13 + 8);
    if ( v14 )
    {
      v15 = *(_QWORD *)(v14 + 2512);
      if ( v15 )
        v15 = *(_QWORD *)(v15 + 1568);
      *(_DWORD *)(a1 + 1316) = v15;
    }
  }
  v117 = v12;
  v118 = *(_DWORD *)(a1 + 648);
  if ( !*(_QWORD *)a1 )
  {
    v54 = &unk_26FCAB;
    goto LABEL_93;
  }
  v16 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v16 || !*(_QWORD *)(v16 + 8) )
  {
    v54 = &unk_234896;
LABEL_93:
    dyn_hdr_meta = printk(v54, "sde_encoder_get_kms");
    v19 = 0;
    goto LABEL_17;
  }
  dyn_hdr_meta = ((__int64 (*)(void))sde_kms_get_disp_op)();
  v19 = dyn_hdr_meta;
LABEL_17:
  v20 = *(_QWORD *)(a1 + 328);
  *(_BYTE *)(a1 + 1320) = 0;
  if ( v20 )
  {
    v21 = *(_QWORD *)(v20 + 408);
    dyn_hdr_meta = sde_connector_get_dyn_hdr_meta(*(_QWORD *)(v20 + 8));
    if ( v21 )
    {
      v18 = dyn_hdr_meta;
      if ( dyn_hdr_meta )
      {
        if ( *(_BYTE *)(dyn_hdr_meta + 36) == 1 )
        {
          if ( v19 >= 3 )
            goto LABEL_225;
          if ( *(_QWORD *)(v21 + 320 + 8LL * v19) )
          {
            v22 = *(_QWORD *)(a1 + 328);
            *(_BYTE *)(a1 + 1320) = 1;
            v23 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _BOOL8))(v21 + 320 + 8LL * v19);
            v24 = *(unsigned int *)(dyn_hdr_meta + 32);
            v25 = *(_DWORD *)(v22 + 672) != 1;
            if ( *((_DWORD *)v23 - 1) != -1811938959 )
              __break(0x8228u);
            dyn_hdr_meta = v23(v21, dyn_hdr_meta, v24, v25);
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(a1 + 196) )
  {
    v26 = 0;
    v27 = 0;
    while ( 1 )
    {
      if ( v26 == 4 )
        goto LABEL_225;
      v28 = *(_QWORD *)(a1 + 200 + 8 * v26);
      *((_DWORD *)a2 + 3) = *(_DWORD *)(a1 + 1316);
      *((_BYTE *)a2 + 8) = *(_BYTE *)(a1 + 1369);
      if ( !v28 )
        goto LABEL_29;
      if ( *(_BYTE *)(a1 + 748) == 1 )
      {
        v29 = *(_QWORD *)(v28 + 2568);
        if ( v29 > ktime_get(dyn_hdr_meta) )
        {
          hrtimer_cancel(v28 + 2544);
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_encoder_prepare_for_kickoff",
            7049,
            -1,
            13107,
            -1059143953,
            v30,
            v31,
            v115);
        }
      }
      v32 = *(_DWORD **)(v28 + 152);
      if ( v32 )
      {
        if ( *(v32 - 1) != 875186399 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD *))v32)(v28, a2);
      }
      v27 |= *(_DWORD *)(v28 + 832) == 5;
      dyn_hdr_meta = sde_encoder_setup_dither(v28);
      v33 = *(_QWORD *)(a1 + 328);
      if ( !v33 )
        goto LABEL_29;
      v34 = *(_QWORD *)(v33 + 8);
      if ( !v34 || *(_BYTE *)(v34 + 4680) != 1 )
        goto LABEL_29;
      memset(v119, 0, 24);
      if ( !*(_QWORD *)v28 )
      {
        dyn_hdr_meta = printk(&unk_26FCAB, "_helper_flush_qsync");
        goto LABEL_29;
      }
      v35 = **(_QWORD **)v28;
      if ( v35 )
      {
        v36 = *(_QWORD *)(v35 + 56);
        if ( v36 && *(_QWORD *)(v36 + 8) )
        {
          v37 = ((__int64 (*)(void))sde_kms_get_disp_op)();
          goto LABEL_47;
        }
        v44 = &unk_234896;
      }
      else
      {
        v44 = &unk_26FCAB;
      }
      printk(v44, "sde_encoder_get_kms");
      v37 = 0;
LABEL_47:
      v38 = *(_DWORD *)(v28 + 668);
      v39 = *(__int64 **)v28;
      if ( v38 == 2 || v38 == 1 && *(_BYTE *)(v28 + 2288) == 1 )
      {
        sde_rm_init_hw_iter(v119, *((unsigned int *)v39 + 6), 8);
        if ( (sde_rm_get_hw(*(_QWORD *)(v28 + 512) + 2144LL, v119) & 1) != 0 )
        {
          v40 = 0;
          do
          {
            if ( v119[0] )
            {
              if ( v37 >= 3 )
                goto LABEL_225;
              v41 = *(void (**)(void))(*(_QWORD *)(v28 + 416) + 8LL * v37 + 1192);
              if ( v41 )
              {
                v40 = 1;
                if ( *((_DWORD *)v41 - 1) != 949740941 )
                  __break(0x8229u);
                v41();
              }
              else
              {
                v40 = 1;
              }
            }
            dyn_hdr_meta = sde_rm_get_hw(*(_QWORD *)(v28 + 512) + 2144LL, v119);
          }
          while ( (dyn_hdr_meta & 1) != 0 );
          if ( (v40 & 1) != 0 )
            goto LABEL_29;
        }
        v45 = &unk_268E6B;
      }
      else
      {
        sde_rm_init_hw_iter(v119, *((unsigned int *)v39 + 6), 2);
        if ( (sde_rm_get_hw(*(_QWORD *)(v28 + 512) + 2144LL, v119) & 1) != 0 )
        {
          v42 = 0;
          do
          {
            if ( v119[0] )
            {
              if ( v37 > 2 )
                goto LABEL_225;
              v43 = *(void (**)(void))(*(_QWORD *)(v28 + 416) + 8LL * v37 + 1072);
              if ( v43 )
              {
                v42 = 1;
                if ( *((_DWORD *)v43 - 1) != -1730422967 )
                  __break(0x8229u);
                v43();
              }
              else
              {
                v42 = 1;
              }
            }
            dyn_hdr_meta = sde_rm_get_hw(*(_QWORD *)(v28 + 512) + 2144LL, v119);
          }
          while ( (dyn_hdr_meta & 1) != 0 );
          if ( (v42 & 1) != 0 )
            goto LABEL_29;
        }
        v45 = &unk_262152;
      }
      dyn_hdr_meta = printk(v45, "_helper_flush_qsync");
LABEL_29:
      if ( ++v26 >= (unsigned __int64)*(unsigned int *)(a1 + 196) )
        goto LABEL_79;
    }
  }
  v27 = 0;
LABEL_79:
  if ( *(_BYTE *)(a1 + 4936) != 1 )
    goto LABEL_100;
  if ( *(_QWORD *)a1 )
  {
    v46 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
    if ( v46 )
    {
      v47 = *(_QWORD *)(v46 + 8);
      if ( v47 )
      {
        disp_op = sde_kms_get_disp_op(v47, v18);
        v49 = *(_QWORD *)(a1 + 328);
        if ( !v49 )
          goto LABEL_100;
        goto LABEL_84;
      }
    }
    v56 = &unk_234896;
  }
  else
  {
    v56 = &unk_26FCAB;
  }
  printk(v56, "sde_encoder_get_kms");
  disp_op = 0;
  v49 = *(_QWORD *)(a1 + 328);
  if ( !v49 )
    goto LABEL_100;
LABEL_84:
  v50 = *(_QWORD *)(v49 + 416);
  if ( v50 )
  {
    if ( disp_op >= 3 )
      goto LABEL_225;
    v51 = *(void (**)(void))(v50 + 8LL * disp_op + 1688);
    if ( v51 )
    {
      if ( *((_DWORD *)v51 - 1) != -1792093723 )
        __break(0x8228u);
      v51();
    }
  }
LABEL_100:
  if ( v118 == 2 )
  {
    v57 = *(_QWORD *)(a1 + 328);
    if ( v57 )
    {
      v58 = *(_QWORD *)(v57 + 8);
      if ( v58 )
      {
        if ( (*(_BYTE *)(v58 + 4680) & 1) != 0
          || (*(_BYTE *)(a1 + 644) & 2) != 0 && (v59 = *(_QWORD *)(v58 + 2512)) != 0 && *(_QWORD *)(v59 + 1440) )
        {
          ((void (__fastcall *)(__int64, __int64))sde_encoder_update_rsc_client)(a1, 1);
        }
      }
    }
  }
  v60 = sde_encoder_resource_control(a1, 1);
  if ( v60 )
  {
    v55 = v60;
    printk(&unk_26C7A6, "sde_encoder_prepare_for_kickoff");
    goto LABEL_217;
  }
  v61 = *(_DWORD *)(a1 + 196);
  if ( (v27 & 1) != 0 )
  {
    if ( !v61 )
      goto LABEL_181;
    v62 = *(_QWORD *)(a1 + 200);
    if ( v62 )
    {
      v63 = *(void (**)(void))(v62 + 216);
      if ( v63 )
      {
        if ( *((_DWORD *)v63 - 1) != -511414616 )
          __break(0x8229u);
        v63();
        v61 = *(_DWORD *)(a1 + 196);
      }
    }
    if ( v61 < 2 )
      goto LABEL_181;
    v64 = *(_QWORD *)(a1 + 208);
    if ( v64 )
    {
      v65 = *(void (**)(void))(v64 + 216);
      if ( v65 )
      {
        if ( *((_DWORD *)v65 - 1) != -511414616 )
          __break(0x8229u);
        v65();
        v61 = *(_DWORD *)(a1 + 196);
      }
    }
    if ( v61 >= 3 )
    {
      v66 = *(_QWORD *)(a1 + 216);
      if ( v66 )
      {
        v67 = *(void (**)(void))(v66 + 216);
        if ( v67 )
        {
          if ( *((_DWORD *)v67 - 1) != -511414616 )
            __break(0x8229u);
          v67();
          v61 = *(_DWORD *)(a1 + 196);
        }
      }
      if ( v61 >= 4 )
      {
        v68 = *(_QWORD *)(a1 + 224);
        if ( v68 )
        {
          v69 = *(void (**)(void))(v68 + 216);
          if ( v69 )
          {
            if ( *((_DWORD *)v69 - 1) != -511414616 )
              __break(0x8229u);
            v69();
            v61 = *(_DWORD *)(a1 + 196);
          }
        }
        if ( v61 > 4 )
          goto LABEL_225;
      }
    }
  }
  if ( v61 >= 2 && (*(_BYTE *)(a1 + 4936) & 1) == 0 )
  {
    v70 = _sw_hweight64(*a2);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "enc%d affected_displays 0x%lx num_active_phys %d\n", *(_DWORD *)(a1 + 24), *a2, v70);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_encoder_update_master",
      5686,
      4,
      *(_DWORD *)(a1 + 24),
      *a2,
      v70,
      -1059143953,
      v115);
    v71 = *(_QWORD *)(a1 + 328);
    if ( v71 )
    {
      v72 = *(_QWORD *)(v71 + 8);
      if ( v72 )
      {
        v73 = *(_QWORD *)(v72 + 2512);
        if ( v73 )
        {
          if ( *(_DWORD *)(v73 + 1376) == 10 )
          {
            if ( (*a2 & 1) == 0 && (*a2 & 2) != 0 )
            {
              v74 = *(unsigned __int8 *)(a1 + 500);
              v76 = 1;
              if ( (v74 & 1) == 0 )
              {
                v78 = *(_QWORD *)(a1 + 200);
                v74 = 1;
                v79 = *(_DWORD *)(v78 + 672);
                *(_DWORD *)(v78 + 672) = *(_DWORD *)(*(_QWORD *)(a1 + 208) + 672LL);
                *(_DWORD *)(*(_QWORD *)(a1 + 208) + 672LL) = v79;
                *(_BYTE *)(a1 + 500) = 1;
              }
            }
            else
            {
              v74 = *(unsigned __int8 *)(a1 + 500);
              if ( v74 == 1 )
              {
                v75 = *(_QWORD *)(a1 + 200);
                v74 = 0;
                v76 = 0;
                v77 = *(_DWORD *)(v75 + 672);
                *(_DWORD *)(v75 + 672) = *(_DWORD *)(*(_QWORD *)(a1 + 208) + 672LL);
                *(_DWORD *)(*(_QWORD *)(a1 + 208) + 672LL) = v77;
                *(_BYTE *)(a1 + 500) = 0;
              }
              else
              {
                v76 = 0;
              }
            }
            if ( (_drm_debug & 4) != 0 )
            {
              _drm_dev_dbg(
                0,
                0,
                0,
                "enc%d right_only %d swapped %d phys0->intf%d, phys1->intf%d\n",
                *(_DWORD *)(a1 + 24),
                v76,
                v74,
                *(_DWORD *)(*(_QWORD *)(a1 + 200) + 672LL) - 1,
                *(_DWORD *)(*(_QWORD *)(a1 + 208) + 672LL) - 1);
              v74 = *(unsigned __int8 *)(a1 + 500);
            }
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "_sde_encoder_ppsplit_swap_intf_for_right_only_update",
              5653,
              -1,
              *(_DWORD *)(a1 + 24),
              v76,
              v74,
              *(_DWORD *)(*(_QWORD *)(a1 + 200) + 672LL) - 1,
              *(_DWORD *)(*(_QWORD *)(a1 + 208) + 672LL) - 1);
            if ( v70 == 1 )
              *a2 = 1;
          }
        }
      }
    }
    v80 = *(unsigned int *)(a1 + 196);
    if ( (_DWORD)v80 )
    {
      v81 = 0;
      v82 = a1 + 200;
      v116 = 0;
      while ( 1 )
      {
        if ( v81 == 4 )
          goto LABEL_225;
        v83 = *(_QWORD *)(v82 + 8 * v81);
        if ( v83 )
        {
          v84 = *(_DWORD **)(v83 + 240);
          if ( v84 )
          {
            if ( *(_QWORD *)(v83 + 496) )
              break;
          }
        }
LABEL_159:
        if ( ++v81 >= v80 )
          goto LABEL_181;
      }
      v85 = *(_DWORD *)(v83 + 664);
      v86 = *a2 & (1LL << v81);
      if ( v86 && v70 == 1 )
      {
        v87 = *(_QWORD *)(v82 + 8 * v81);
        if ( *(v84 - 1) != -1201232701 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v84)(v87, 0);
      }
      else
      {
        if ( (v116 & 1) != 0 )
          v88 = 3;
        else
          v88 = 1;
        if ( v86 )
          v89 = v88;
        else
          v89 = 4;
        if ( *(v84 - 1) != -1201232701 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, __int64))v84)(v83, v89);
        v82 = a1 + 200;
        if ( (v86 == 0) | v116 & 1 )
          goto LABEL_179;
      }
      *(_QWORD *)(a1 + 328) = v83;
      v116 = 1;
LABEL_179:
      v90 = v86 != 0;
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "enc%d pp %d role prv %d new %d active %d\n",
          *(_DWORD *)(a1 + 24),
          *(_DWORD *)(*(_QWORD *)(v83 + 496) + 32LL) - 1,
          v85,
          *(_DWORD *)(v83 + 664),
          v90);
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_encoder_update_master",
        5723,
        -1,
        *(_DWORD *)(a1 + 24),
        *a2,
        *(_DWORD *)(*(_QWORD *)(v83 + 496) + 32LL) - 1,
        v85,
        *(_DWORD *)(v83 + 664));
      v80 = *(unsigned int *)(a1 + 196);
      goto LABEL_159;
    }
  }
LABEL_181:
  v91 = *(_QWORD *)(a1 + 1360);
  v119[0] = 0;
  if ( v91 && *(_QWORD *)(v91 + 2008) )
  {
    v92 = *(_QWORD *)(a1 + 328);
    if ( v92 )
    {
      v93 = *(_QWORD *)(*(_QWORD *)(a1 + 200) + 8LL);
      if ( !v93
        || (v94 = *(_QWORD *)(v93 + 2512)) == 0
        || (sde_kms_rect_merge_rectangles(v94 + 2048, v119), !WORD2(v119[0]))
        || !HIWORD(v119[0]) )
      {
        v95 = *(_WORD *)(v92 + 534);
        WORD2(v119[0]) = *(_WORD *)(v92 + 524);
        HIWORD(v119[0]) = v95;
      }
      v96 = v119[0];
      *(_QWORD *)(a1 + 1352) = *(_QWORD *)(a1 + 1344);
      *(_QWORD *)(a1 + 1344) = v96;
    }
    else
    {
      printk(&unk_220B8E, "_sde_encoder_update_roi");
    }
  }
  else
  {
    printk(&unk_27397B, "_sde_encoder_update_roi");
  }
  v97 = *(_QWORD *)(a1 + 328);
  if ( v97 )
  {
    if ( *(_QWORD *)(v97 + 8) )
    {
      v98 = sde_connector_pre_kickoff();
      v97 = *(_QWORD *)(a1 + 328);
      v55 = v98;
      if ( v98 )
      {
        printk(&unk_23F3F4, "_sde_encoder_prepare_for_kickoff_processing");
        v97 = *(_QWORD *)(a1 + 328);
        if ( !v97 )
          goto LABEL_201;
      }
      else if ( !v97 )
      {
        goto LABEL_201;
      }
    }
    else
    {
      v55 = 0;
    }
    if ( v118 == 2 || (*(_BYTE *)(v97 + 2289) & 1) == 0 )
    {
      v99 = ((__int64 (__fastcall *)(__int64, _QWORD *))sde_encoder_dce_setup)(a1, a2);
      if ( v99 )
      {
        v55 = v99;
        printk(&unk_27D703, "_sde_encoder_prepare_for_kickoff_processing");
      }
    }
  }
  else
  {
    v55 = 0;
  }
LABEL_201:
  ((void (__fastcall *)(__int64))sde_encoder_dce_flush)(a1);
  v101 = *(_QWORD *)(a1 + 328);
  if ( !v101 || (*(_BYTE *)(v101 + 2289) & 1) != 0 )
    goto LABEL_217;
  v102 = *(_QWORD *)(v101 + 440);
  v103 = *(unsigned __int8 *)(v117 + 3745);
  if ( *(_QWORD *)a1 )
  {
    v104 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
    if ( v104 )
    {
      v105 = *(_QWORD *)(v104 + 8);
      if ( v105 )
      {
        v106 = sde_kms_get_disp_op(v105, v100);
        goto LABEL_207;
      }
    }
    v113 = &unk_234896;
  }
  else
  {
    v113 = &unk_26FCAB;
  }
  printk(v113, "sde_encoder_get_kms");
  v106 = 0;
LABEL_207:
  if ( *(unsigned __int8 *)(a1 + 501) == v103 )
    goto LABEL_217;
  *(_BYTE *)(a1 + 501) = v103;
  if ( v106 >= 3 )
LABEL_225:
    __break(0x5512u);
  v107 = *(_QWORD *)(v101 + 408);
  v108 = v106;
  v109 = *(_DWORD **)(v107 + 8LL * v106 + 272);
  if ( v109 )
  {
    if ( *(v109 - 1) != -918579344 )
      __break(0x8229u);
    ((void (__fastcall *)(__int64, _QWORD))v109)(v107, v103);
  }
  v110 = *(void (__fastcall **)(__int64, __int64))(v102 + 8 * v108 + 48);
  if ( v110 )
  {
    v111 = *(unsigned __int8 *)(a1 + 501);
    if ( *((_DWORD *)v110 - 1) != 45982939 )
      __break(0x8228u);
    v110(v102, v111);
  }
LABEL_217:
  _ReadStatusReg(SP_EL0);
  return v55;
}
