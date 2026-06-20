__int64 __fastcall sde_crtc_atomic_begin(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x19
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x26
  void *v13; // x0
  const char *v14; // x1
  __int64 v15; // x5
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x21
  unsigned int v19; // w6
  __int64 v20; // x27
  __int64 v21; // x24
  __int64 *v22; // x21
  __int64 v23; // x8
  __int64 v24; // x10
  __int64 v25; // x10
  __int64 v26; // x9
  __int64 v27; // x13
  __int64 v28; // x13
  __int64 v29; // x8
  __int64 v30; // x9
  __int64 v31; // x9
  unsigned int v32; // w20
  __int64 v33; // x8
  void *v34; // x0
  const char *v35; // x1
  __int64 v36; // x22
  __int64 (__fastcall *v37)(_QWORD); // x8
  __int64 v38; // x0
  __int64 v39; // x21
  _DWORD *v40; // x8
  _DWORD *v41; // x8
  __int64 (*v42)(void); // x8
  __int64 (*v43)(void); // x8
  __int64 (*v44)(void); // x8
  __int64 (*v45)(void); // x8
  __int64 (*v46)(void); // x8
  __int64 (*v47)(void); // x8
  __int64 (*v48)(void); // x8
  __int64 (*v49)(void); // x8
  unsigned __int64 v50; // x22
  _WORD *v51; // x20
  __int64 *v52; // x21
  __int64 *v53; // x20
  __int64 v54; // x8
  __int64 *i; // x21
  __int64 *j; // x21
  __int64 v57; // x8
  __int64 v58; // x9
  __int64 v59; // x9
  __int64 v60; // x22
  __int64 v61; // x8
  int v62; // w23
  int v63; // w24
  __int64 v64; // x8
  __int64 v65; // x28
  unsigned int v66; // w23
  int v67; // w8
  unsigned int v68; // w9
  __int64 *v69; // x9
  __int64 v70; // x25
  __int64 v71; // x24
  __int64 v72; // x20
  _DWORD *v73; // x10
  __int64 v74; // x2
  int v75; // w7
  __int64 (__fastcall *v76)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v77)(__int64, __int64, __int64); // x8
  __int64 v78; // x1
  __int64 v79; // x20
  __int64 v80; // x9
  __int64 v81; // x8
  __int64 v82; // x8
  unsigned int v83; // w22
  unsigned __int64 v84; // x23
  __int64 *v85; // x24
  __int64 v86; // x9
  __int64 (*v87)(void); // x8
  void *v88; // x0
  __int64 v89; // x8
  __int64 v90; // x8
  unsigned int v91; // w8
  unsigned int v92; // w8
  __int64 (__fastcall *v93)(__int64, __int64); // x8
  __int64 v94; // x8
  __int64 v95; // x8
  __int64 v96; // x22
  int display_id; // w0
  _QWORD *cmd_buf; // x0
  __int64 v99; // x8
  const void *v100; // x22
  __int64 v101; // x8
  _DWORD *v102; // x23
  int v103; // w0
  int v104; // w24
  _DWORD *payload_addr; // x25
  unsigned int size; // w0
  void *v107; // x0
  int v108; // w0
  unsigned __int64 v115; // x10
  char v116; // [xsp+0h] [xbp-80h]
  __int64 v117; // [xsp+30h] [xbp-50h]
  unsigned int v118; // [xsp+44h] [xbp-3Ch]
  __int64 v119; // [xsp+48h] [xbp-38h]
  unsigned int v120; // [xsp+54h] [xbp-2Ch]

  _ReadStatusReg(SP_EL0);
  if ( !result )
  {
    result = printk(&unk_25E167, "sde_crtc_atomic_begin");
    goto LABEL_260;
  }
  v8 = result;
  if ( !*(_QWORD *)result || (v9 = *(_QWORD *)(*(_QWORD *)result + 56LL)) == 0 )
  {
    v13 = &unk_25E167;
    v14 = "sde_crtc_get_disp_op";
LABEL_11:
    result = printk(v13, v14);
    goto LABEL_12;
  }
  v10 = *(_QWORD *)(v9 + 8);
  if ( !v10 )
  {
    v13 = &unk_234896;
    v14 = "_sde_crtc_get_kms";
    goto LABEL_11;
  }
  v11 = *(_QWORD *)(v10 + 152);
  if ( v11 && (*(_QWORD *)(v11 + 22008) & 0x8000000000000LL) != 0 )
  {
    v12 = *(unsigned int *)(v9 + 5912);
    goto LABEL_13;
  }
LABEL_12:
  v12 = 0;
LABEL_13:
  v15 = *(unsigned __int8 *)(*(_QWORD *)(v8 + 2008) + 8LL);
  if ( (v15 & 1) == 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      result = _drm_dev_dbg(0, 0, 0, "crtc%d -> enable %d, skip atomic_begin\n", *(_DWORD *)(v8 + 112), v15);
    goto LABEL_260;
  }
  v16 = *(_QWORD *)v8;
  if ( !*(_QWORD *)v8 || (*(_WORD *)(*(_QWORD *)(v16 + 8) + 488LL) & 7) != 0 )
  {
    result = printk(&unk_24FBDF, "_sde_crtc_atomic_begin");
    goto LABEL_260;
  }
  v17 = *(_QWORD *)(v16 + 56);
  if ( !v17 )
  {
    result = printk(&unk_25E167, "_sde_crtc_get_kms");
    goto LABEL_260;
  }
  v18 = *(_QWORD *)(v17 + 8);
  if ( !v18 )
  {
    result = printk(&unk_234896, "_sde_crtc_get_kms");
    goto LABEL_260;
  }
  _ReadStatusReg(SP_EL0);
  v119 = v18;
  if ( (_drm_debug & 4) != 0 )
    result = _drm_dev_dbg(0, 0, 0, "crtc%d\n", *(_DWORD *)(v8 + 112));
  v19 = *(_DWORD *)(v8 + 2192);
  v20 = *(_QWORD *)(v8 + 2008);
  v21 = *(_QWORD *)v8;
  v22 = &qword_294000;
  if ( v19 && *(_BYTE *)(v20 + 6922) != 1 )
  {
    v33 = *(_QWORD *)(v8 + 2008);
    if ( *(_BYTE *)(v8 + 7757) != 1 )
      goto LABEL_121;
    result = sde_crtc_setup_mixers(v8);
    v19 = *(_DWORD *)(v8 + 2192);
    *(_BYTE *)(v8 + 7757) = 0;
    goto LABEL_119;
  }
  sde_crtc_setup_mixers(v8);
  v23 = *(_QWORD *)(v8 + 2008);
  v24 = *(unsigned int *)(v23 + 464);
  *(_BYTE *)(v23 + 483) = 0;
  if ( (int)v24 > 0 )
  {
    v25 = 8 * v24;
    v26 = 0;
    while ( v26 != 128 )
    {
      v27 = *(_QWORD *)(v23 + 336 + v26);
      if ( v27 )
      {
        v28 = *(_QWORD *)(v27 + 2512);
        if ( v28 )
        {
          if ( *(_QWORD *)(v28 + 1376) == 10 )
            *(_BYTE *)(v23 + 483) = 1;
        }
      }
      v26 += 8;
      if ( v25 == v26 )
        goto LABEL_32;
    }
    goto LABEL_277;
  }
LABEL_32:
  result = sde_crtc_setup_lm_bounds(v8, *(_QWORD *)(v8 + 2008));
  if ( !*(_QWORD *)v8 || (v29 = *(_QWORD *)(*(_QWORD *)v8 + 56LL)) == 0 )
  {
    v34 = &unk_25E167;
    v35 = "sde_crtc_get_disp_op";
LABEL_46:
    result = printk(v34, v35);
    goto LABEL_47;
  }
  v30 = *(_QWORD *)(v29 + 8);
  if ( !v30 )
  {
    v34 = &unk_234896;
    v35 = "_sde_crtc_get_kms";
    goto LABEL_46;
  }
  v31 = *(_QWORD *)(v30 + 152);
  if ( !v31 || (*(_QWORD *)(v31 + 22008) & 0x8000000000000LL) == 0 )
  {
LABEL_47:
    v32 = 0;
    if ( !*(_DWORD *)(v8 + 2192) )
      goto LABEL_131;
    goto LABEL_48;
  }
  v32 = *(_DWORD *)(v29 + 5912);
  if ( !*(_DWORD *)(v8 + 2192) )
    goto LABEL_131;
LABEL_48:
  v36 = *(_QWORD *)(v8 + 2208);
  if ( v36 )
  {
    if ( v32 > 2 )
      goto LABEL_277;
    v37 = *(__int64 (__fastcall **)(_QWORD))(v36 + 8LL * v32 + 1360);
    if ( v37 )
    {
      v38 = *(_QWORD *)(v8 + 2208);
      if ( *((_DWORD *)v37 - 1) != 729814110 )
        __break(0x8228u);
      result = v37(v38);
    }
    v39 = v36 + 8LL * v32;
    v40 = *(_DWORD **)(v39 + 1480);
    if ( v40 )
    {
      if ( *(v40 - 1) != -60854866 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD))v40)(v36, 0);
    }
    v41 = *(_DWORD **)(v39 + 1528);
    v22 = &qword_294000;
    if ( v41 )
    {
      if ( *(v41 - 1) != -60854866 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD))v41)(v36, 0);
    }
  }
  v19 = *(_DWORD *)(v8 + 2192);
  if ( !v19 )
    goto LABEL_131;
  result = *(_QWORD *)(v8 + 2200);
  if ( result )
  {
    if ( v32 > 2 )
      goto LABEL_277;
    v42 = *(__int64 (**)(void))(result + 8LL * v32 + 328);
    if ( v42 )
    {
      if ( *((_DWORD *)v42 - 1) != 1690926117 )
        __break(0x8228u);
      result = v42();
      v19 = *(_DWORD *)(v8 + 2192);
    }
  }
  if ( v19 >= 2 )
  {
    result = *(_QWORD *)(v8 + 2248);
    if ( result )
    {
      if ( v32 > 2 )
        goto LABEL_277;
      v43 = *(__int64 (**)(void))(result + 8LL * v32 + 328);
      if ( v43 )
      {
        if ( *((_DWORD *)v43 - 1) != 1690926117 )
          __break(0x8228u);
        result = v43();
        v19 = *(_DWORD *)(v8 + 2192);
      }
    }
    if ( v19 >= 3 )
    {
      result = *(_QWORD *)(v8 + 2296);
      if ( result )
      {
        if ( v32 > 2 )
          goto LABEL_277;
        v44 = *(__int64 (**)(void))(result + 8LL * v32 + 328);
        if ( v44 )
        {
          if ( *((_DWORD *)v44 - 1) != 1690926117 )
            __break(0x8228u);
          result = v44();
          v19 = *(_DWORD *)(v8 + 2192);
        }
      }
      if ( v19 >= 4 )
      {
        result = *(_QWORD *)(v8 + 2344);
        if ( result )
        {
          if ( v32 > 2 )
            goto LABEL_277;
          v45 = *(__int64 (**)(void))(result + 8LL * v32 + 328);
          if ( v45 )
          {
            if ( *((_DWORD *)v45 - 1) != 1690926117 )
              __break(0x8228u);
            result = v45();
            v19 = *(_DWORD *)(v8 + 2192);
          }
        }
        if ( v19 >= 5 )
        {
          result = *(_QWORD *)(v8 + 2392);
          if ( result )
          {
            if ( v32 > 2 )
              goto LABEL_277;
            v46 = *(__int64 (**)(void))(result + 8LL * v32 + 328);
            if ( v46 )
            {
              if ( *((_DWORD *)v46 - 1) != 1690926117 )
                __break(0x8228u);
              result = v46();
              v19 = *(_DWORD *)(v8 + 2192);
            }
          }
          if ( v19 >= 6 )
          {
            result = *(_QWORD *)(v8 + 2440);
            if ( result )
            {
              if ( v32 > 2 )
                goto LABEL_277;
              v47 = *(__int64 (**)(void))(result + 8LL * v32 + 328);
              if ( v47 )
              {
                if ( *((_DWORD *)v47 - 1) != 1690926117 )
                  __break(0x8228u);
                result = v47();
                v19 = *(_DWORD *)(v8 + 2192);
              }
            }
            if ( v19 >= 7 )
            {
              result = *(_QWORD *)(v8 + 2488);
              if ( result )
              {
                if ( v32 > 2 )
                  goto LABEL_277;
                v48 = *(__int64 (**)(void))(result + 8LL * v32 + 328);
                if ( v48 )
                {
                  if ( *((_DWORD *)v48 - 1) != 1690926117 )
                    __break(0x8228u);
                  result = v48();
                  v19 = *(_DWORD *)(v8 + 2192);
                }
              }
              if ( v19 >= 8 )
              {
                result = *(_QWORD *)(v8 + 2536);
                if ( result )
                {
                  if ( v32 > 2 )
                    goto LABEL_277;
                  v49 = *(__int64 (**)(void))(result + 8LL * v32 + 328);
                  if ( v49 )
                  {
                    if ( *((_DWORD *)v49 - 1) != 1690926117 )
                      __break(0x8228u);
                    result = v49();
                    v19 = *(_DWORD *)(v8 + 2192);
                  }
                }
                if ( v19 > 8 )
                  goto LABEL_277;
              }
            }
          }
        }
      }
    }
  }
LABEL_119:
  if ( v19 )
  {
    v33 = *(_QWORD *)(v8 + 2008);
LABEL_121:
    v50 = 0;
    v51 = (_WORD *)(v33 + 556);
    while ( v50 != 9 )
    {
      if ( !v51 || !*v51 && !v51[1] && !v51[2] && !v51[3] )
      {
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_crtc_validate_lm_rois",
          5038,
          -1,
          *(_DWORD *)(v8 + 112),
          v50,
          v19,
          60333,
          239);
        result = sde_crtc_setup_lm_bounds(v8, *(_QWORD *)(v8 + 2008));
        v19 = *(_DWORD *)(v8 + 2192);
      }
      ++v50;
      v51 += 4;
      if ( v50 >= v19 )
        goto LABEL_131;
    }
    goto LABEL_277;
  }
LABEL_131:
  v52 = *(__int64 **)(v21 + 816);
  v53 = (__int64 *)(v21 + 816);
  while ( v52 != v53 )
  {
    if ( v52[9] == v8 )
    {
      if ( !*(_QWORD *)(v8 + 8016) )
      {
        if ( v52 == (__int64 *)&unk_8 )
        {
          v54 = 0;
        }
        else if ( (((__int64 (*)(void))sde_encoder_in_clone_mode)() & 1) != 0 )
        {
          v54 = 0;
        }
        else
        {
          v54 = v52[619];
        }
        *(_QWORD *)(v8 + 8016) = v54;
      }
      result = sde_encoder_trigger_kickoff_pending();
    }
    v52 = (__int64 *)*v52;
  }
  if ( (*(_BYTE *)(v20 + 480) & 1) == 0 )
  {
    for ( i = (__int64 *)*v53; i != v53; i = (__int64 *)*i )
    {
      if ( ((*(_DWORD *)(*(_QWORD *)(v8 + 2008) + 20LL) >> *((_DWORD *)i + 15)) & 1) != 0 )
      {
        result = sde_encoder_get_rsc_client(i - 1);
        *(_QWORD *)(v20 + 472) = result;
      }
    }
    *(_BYTE *)(v20 + 480) = 1;
  }
  if ( *(_QWORD *)(v8 + 8016) )
  {
    for ( j = (__int64 *)*v53; j != v53; j = (__int64 *)*j )
    {
      if ( ((*(_DWORD *)(*(_QWORD *)(v8 + 2008) + 20LL) >> *((_DWORD *)j + 15)) & 1) != 0 )
      {
        result = ((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(j - 1);
        if ( (result & 1) == 0 )
        {
          result = sde_encoder_check_curr_mode(j - 1, 2);
          if ( (result & 1) == 0 )
            result = sde_encoder_begin_commit(j - 1);
        }
      }
    }
  }
  else
  {
    result = sde_core_perf_crtc_update(v8, 1);
  }
  if ( *(_DWORD *)(v8 + 2192) )
  {
    sde_crtc_blend_setup((char *)v8, 1, a3, a4, a5, v15, v19, a8);
    if ( *(_QWORD *)v8 && (v57 = *(_QWORD *)(*(_QWORD *)v8 + 56LL)) != 0 )
    {
      v58 = *(_QWORD *)(v57 + 8);
      if ( v58 )
      {
        v59 = *(_QWORD *)(v58 + 152);
        if ( v59 && (*(_QWORD *)(v59 + 22008) & 0x8000000000000LL) != 0 )
        {
          v120 = *(_DWORD *)(v57 + 5912);
LABEL_169:
          v60 = *(_QWORD *)(v8 + 2008);
          v118 = v12;
          LODWORD(v22) = v60 + 4096;
          if ( *(_QWORD *)v8 && (v61 = *(_QWORD *)(*(_QWORD *)v8 + 56LL)) != 0 )
          {
            v12 = *(_QWORD *)(v61 + 8);
            if ( !v12 )
              printk(&unk_234896, "_sde_crtc_get_kms");
          }
          else
          {
            printk(&unk_25E167, "_sde_crtc_get_kms");
            v12 = 0;
          }
          v62 = *(_DWORD *)(v8 + 2192);
          if ( v62 && *(_BYTE *)(v60 + 6921) == 1 )
            v62 = *(_DWORD *)(v60 + 7084);
          v63 = *(_DWORD *)(v60 + 2044);
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "crtc%d\n", *(_DWORD *)(v8 + 112));
          result = sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "_sde_crtc_dest_scaler_setup",
                     3104,
                     -1,
                     *(_DWORD *)(v8 + 112),
                     v62,
                     v63,
                     *(_QWORD *)(v60 + 1792),
                     *(_DWORD *)(v60 + 2048));
          if ( (*(_QWORD *)(v60 + 1792) & 1) != 0 )
          {
            if ( v12 && (v64 = *(_QWORD *)(v12 + 152)) != 0 )
            {
              if ( (*(_BYTE *)(v64 + 708) & 1) != 0 )
              {
                result = sde_validate_hw_resources(v8, v60);
                if ( !(_DWORD)result )
                {
                  if ( (*(_BYTE *)(v60 + 4424) & 1) != 0 || *(_DWORD *)(*(_QWORD *)(v12 + 152) + 16LL) == 22 )
                  {
                    if ( v63 >= 1 )
                    {
                      v65 = 0;
                      v66 = 0;
                      v117 = 592LL * (unsigned int)v63;
                      while ( v65 != 2960 )
                      {
                        v22 = (__int64 *)(v60 + v65);
                        v67 = *(_DWORD *)(v60 + v65 + 2060);
                        if ( v67 )
                        {
                          v68 = *((_DWORD *)v22 + 514);
                          if ( v68 > 7 )
                            goto LABEL_277;
                          v69 = (__int64 *)(v8 + 2200 + 48LL * v68);
                          v70 = v69[3];
                          if ( (v67 & 1) != 0 )
                            v66 |= 1LL << ((unsigned __int8)*(_DWORD *)(v70 + 32) - 1);
                          if ( v120 > 2 )
                            goto LABEL_277;
                          v71 = v70 + 8LL * v120;
                          v72 = *v69;
                          v12 = v69[1];
                          v73 = *(_DWORD **)(v71 + 48);
                          if ( v73 )
                          {
                            v74 = *(unsigned int *)(v60 + v65 + 2072);
                            v66 |= (*(_DWORD *)(v60 + 2048) == 2) << 16;
                            if ( *(v73 - 1) != 1853470584 )
                              __break(0x822Au);
                            ((void (__fastcall *)(__int64, _QWORD, __int64))v73)(v70, v66, v74);
                            result = sde_evtlog_log(
                                       sde_dbg_base_evtlog,
                                       "_sde_crtc_dest_scaler_setup",
                                       3137,
                                       4,
                                       *(_DWORD *)(v8 + 112),
                                       v66,
                                       -1059143953,
                                       v75,
                                       v116);
                            v67 = *((_DWORD *)v22 + 515);
                          }
                          if ( (v67 & 6) != 0 )
                          {
                            v76 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v71 + 72);
                            if ( v76 )
                            {
                              if ( *((_DWORD *)v76 - 1) != -1792886520 )
                                __break(0x8228u);
                              result = v76(v70, v60 + v65 + 2080, v60 + 4424);
                            }
                          }
                          if ( v12 )
                          {
                            v77 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v12 + 8LL * v120 + 1072);
                            if ( v77 )
                            {
                              v78 = *(unsigned int *)(v72 + 32);
                              if ( *((_DWORD *)v77 - 1) != -1730422967 )
                                __break(0x8228u);
                              result = v77(v12, v78, 1);
                            }
                          }
                        }
                        v65 += 592;
                        if ( v117 == v65 )
                          goto LABEL_212;
                      }
                      goto LABEL_277;
                    }
                  }
                  else
                  {
                    result = printk(&unk_27D5A9, "_sde_crtc_dest_scaler_setup");
                  }
                }
              }
              else if ( (_drm_debug & 4) != 0 )
              {
                result = _drm_dev_dbg(0, 0, 0, "dest scaler feature not supported\n");
              }
            }
            else
            {
              result = printk(&unk_2535A1, "_sde_crtc_dest_scaler_setup");
            }
          }
          else if ( (_drm_debug & 4) != 0 )
          {
            result = _drm_dev_dbg(0, 0, 0, "no change in settings, skip commit\n");
          }
LABEL_212:
          v79 = *(_QWORD *)(v8 + 2008);
          LODWORD(v22) = v118;
          v12 = v20;
          if ( (*(_QWORD *)(v79 + 1792) & 4) == 0 )
            goto LABEL_239;
          if ( *(_QWORD *)v8 && (v80 = *(_QWORD *)(*(_QWORD *)v8 + 56LL)) != 0 )
          {
            v81 = *(_QWORD *)(v80 + 8);
            if ( v81 )
            {
              v82 = *(_QWORD *)(v81 + 152);
              if ( v82 )
              {
                if ( (*(_QWORD *)(v82 + 22008) & 0x8000000000000LL) != 0 )
                  v83 = *(_DWORD *)(v80 + 5912);
                else
                  v83 = 0;
                if ( *(_DWORD *)(v8 + 2192) )
                {
                  v84 = 0;
                  v85 = (__int64 *)(v8 + 2200);
                  while ( v84 != 8 && v83 <= 2 )
                  {
                    result = *v85;
                    v86 = *v85 + 280;
                    v87 = *(__int64 (**)(void))(v86 + 8LL * v83);
                    if ( v87 )
                    {
                      if ( (*(_QWORD *)(*(_QWORD *)(result + 40) + 32LL) & 0x2000) != 0 )
                        v87 = *(__int64 (**)(void))(v86 + 8LL * v83);
                      if ( *((_DWORD *)v87 - 1) != -435356005 )
                        __break(0x8228u);
                      result = v87();
                      ++v84;
                      v85 += 6;
                      if ( v84 < *(unsigned int *)(v8 + 2192) )
                        continue;
                    }
                    goto LABEL_231;
                  }
                  goto LABEL_277;
                }
LABEL_231:
                if ( (*(_BYTE *)(v79 + 4568) & 1) == 0 )
                {
                  _X8 = (unsigned __int64 *)(v79 + 1792);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v115 = __ldxr(_X8);
                  while ( __stxr(v115 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
                }
LABEL_239:
                v89 = *(_QWORD *)(v8 + 2008);
                if ( (*(_BYTE *)(v89 + 10) & 2) != 0 || *(_BYTE *)(*(_QWORD *)(v119 + 1976) + 21986LL) == 1 )
                {
                  result = sde_core_perf_crtc_update_uidle(v8, 1);
                  v89 = *(_QWORD *)(v8 + 2008);
                  if ( (*(_BYTE *)(v89 + 10) & 8) != 0 )
                    goto LABEL_242;
                }
                else if ( (*(_BYTE *)(v89 + 10) & 8) != 0 )
                {
LABEL_242:
                  *(_DWORD *)(v8 + 7872) = *(_DWORD *)(v89 + 20);
                  v90 = *(_QWORD *)(v119 + 152);
                  if ( !v90 )
                  {
LABEL_254:
                    if ( v118 <= 2 )
                      goto LABEL_255;
                    goto LABEL_277;
                  }
                  goto LABEL_246;
                }
                v90 = *(_QWORD *)(v119 + 152);
                if ( !v90 )
                  goto LABEL_254;
LABEL_246:
                if ( (*(_QWORD *)(v90 + 22008) & 0x400000000LL) == 0 )
                {
                  mutex_lock(v119 + 3696);
                  if ( (*(_QWORD *)(*(_QWORD *)(v119 + 152) + 22008LL) & 0x400000000LL) != 0
                    && *(_DWORD *)(v119 + 3664) == 1
                    && (v91 = *(_DWORD *)(v119 + 3656), v91 <= 6)
                    && ((1 << v91) & 0x64) != 0
                    || (v92 = *(_DWORD *)(v119 + 3656), v92 <= 4) && ((1 << v92) & 0x1A) != 0 )
                  {
                    result = mutex_unlock(v119 + 3696);
                    goto LABEL_254;
                  }
                  mutex_unlock(v119 + 3696);
                }
                if ( v118 == 1 )
                {
                  if ( *(_QWORD *)v8 )
                  {
                    v94 = *(_QWORD *)(*(_QWORD *)v8 + 56LL);
                    if ( v94 )
                    {
                      v95 = *(_QWORD *)(v94 + 8);
                      if ( v95 )
                      {
                        v96 = *(_QWORD *)(v95 + 6440);
                        if ( v96 )
                        {
                          display_id = hfi_crtc_get_display_id((__int64 *)v8, *(_QWORD *)(v8 + 2008));
                          if ( display_id != -1 )
                          {
                            cmd_buf = hfi_kms_get_cmd_buf(v96, display_id, 1);
                            if ( cmd_buf )
                            {
                              v99 = *(_QWORD *)(v8 + 8032);
                              v100 = cmd_buf;
                              if ( v99 )
                                hfi_util_u32_prop_helper_reset(*(unsigned int **)(v99 + 64));
                              result = sde_cp_crtc_apply_properties(v8);
                              v101 = *(_QWORD *)(v8 + 8032);
                              if ( v101 )
                              {
                                v102 = *(_DWORD **)(v101 + 64);
                                result = hfi_util_u32_prop_helper_prop_count((__int64)v102);
                                if ( (_DWORD)result )
                                {
                                  v103 = hfi_crtc_get_display_id((__int64 *)v8, *(_QWORD *)(v8 + 2008));
                                  if ( v103 == -1 )
                                  {
                                    result = printk(&unk_231479, "_sde_crtc_atomic_begin");
                                  }
                                  else
                                  {
                                    v104 = v103;
                                    payload_addr = hfi_util_u32_prop_helper_get_payload_addr(v102);
                                    size = hfi_util_u32_prop_helper_get_size((__int64)v102);
                                    result = hfi_adapter_add_set_property(
                                               (__int64)v100,
                                               33554433,
                                               v104,
                                               2u,
                                               (__int64)payload_addr,
                                               size,
                                               0);
                                    if ( (_DWORD)result )
                                      result = printk(&unk_26C56C, "_sde_crtc_atomic_begin");
                                  }
                                }
                                else if ( (_drm_debug & 4) != 0 )
                                {
                                  v108 = hfi_util_u32_prop_helper_prop_count((__int64)v102);
                                  result = _drm_dev_dbg(0, 0, 0, "cmd_buf %pK, prop_count %d\n", v100, v108);
                                }
                              }
                              goto LABEL_255;
                            }
                            goto LABEL_280;
                          }
                          v107 = &unk_231479;
LABEL_279:
                          printk(v107, "_sde_crtc_get_cmd_buf");
LABEL_280:
                          result = printk(&unk_276D12, "_sde_crtc_atomic_begin");
LABEL_255:
                          v93 = *(__int64 (__fastcall **)(__int64, __int64))(v8 + 8LL * (unsigned int)v22 + 8256);
                          if ( v93 )
                          {
                            if ( *((_DWORD *)v93 - 1) != -1493870922 )
                              __break(0x8228u);
                            result = v93(v8, v12);
                            if ( (_DWORD)result )
                              result = printk(&unk_2490AE, "_sde_crtc_atomic_begin");
                          }
                          goto LABEL_260;
                        }
                      }
                    }
                  }
LABEL_278:
                  v107 = &unk_24C638;
                  goto LABEL_279;
                }
                result = sde_cp_crtc_apply_properties(v8);
                if ( v118 <= 2 )
                  goto LABEL_255;
LABEL_277:
                __break(0x5512u);
                goto LABEL_278;
              }
LABEL_238:
              result = printk(&unk_27D36D, "sde_cp_crtc_apply_noise");
              goto LABEL_239;
            }
            v88 = &unk_234896;
          }
          else
          {
            v88 = &unk_25E167;
          }
          printk(v88, "_sde_crtc_get_kms");
          goto LABEL_238;
        }
      }
      else
      {
        printk(&unk_234896, "_sde_crtc_get_kms");
      }
    }
    else
    {
      printk(&unk_25E167, "sde_crtc_get_disp_op");
    }
    v120 = 0;
    goto LABEL_169;
  }
LABEL_260:
  _ReadStatusReg(SP_EL0);
  return result;
}
