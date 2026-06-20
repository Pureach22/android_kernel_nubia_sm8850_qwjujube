__int64 __fastcall sde_encoder_phys_wb_atomic_check(__int64 a1, __int64 a2, __int64 **a3)
{
  __int64 v6; // x8
  __int64 v7; // x23
  int v8; // w4
  __int64 v9; // x8
  int v10; // w5
  int v11; // w6
  char v12; // w8
  int v13; // w22
  int v14; // w4
  __int64 v15; // x8
  int v16; // w5
  unsigned int output_roi; // w0
  __int64 output_fb; // x0
  __int64 v19; // x22
  int v20; // w28
  const char *sde_format_ext; // x0
  const char *v22; // x24
  int v23; // w4
  __int64 v24; // x8
  int v25; // w5
  __int64 v26; // x26
  __int64 v27; // x23
  char *v28; // x0
  __int64 v29; // x8
  char *v30; // x25
  int v31; // w0
  unsigned int v32; // w8
  int v33; // w9
  int v34; // w10
  _BOOL4 v35; // w12
  int v36; // w3
  int v37; // w11
  __int64 v38; // x4
  int v39; // w8
  char v40; // w8
  unsigned int v41; // w5
  unsigned int v42; // w7
  unsigned int v43; // w6
  unsigned int v44; // w8
  void *v46; // x0
  _BOOL4 v47; // w9
  __int64 v48; // x8
  __int64 v49; // x8
  __int64 v50; // x26
  __int64 v51; // x8
  int v52; // w23
  int *v53; // x25
  int v54; // w8
  int v55; // w0
  unsigned int v56; // w9
  __int64 v57; // x8
  unsigned int v58; // w28
  __int64 v59; // x25
  int v60; // w8
  int *v61; // x25
  int v62; // t1
  int v63; // w25
  int v64; // w25
  int v65; // w5
  int v66; // w0
  int v67; // w5
  unsigned __int16 v68; // w26
  int v69; // w8
  int v70; // w9
  int v71; // w10
  unsigned int v72; // w27
  __int64 v73; // x0
  __int64 v74; // x22
  int num_datapath; // w23
  const char *v76; // x0
  const char *v77; // x24
  int v78; // w0
  int v79; // w5
  unsigned int v80; // w6
  unsigned int v81; // w7
  unsigned int v82; // w10
  unsigned int *v83; // x0
  int v84; // w8
  void *v85; // x0
  unsigned int v86; // w19
  void *v87; // x0
  int v88; // w20
  void *v89; // x0
  int v90; // w4
  int v91; // w20
  int v92; // w8
  void *v93; // x0
  const char *v94; // x1
  void *v95; // x0
  __int64 v96; // x8
  int v97; // w8
  unsigned __int16 v98; // w8
  unsigned __int16 v99; // w9
  int v100; // w5
  int v101; // w9
  _DWORD *v102; // x10
  __int64 result; // x0
  void *v104; // x0
  int v105; // w20
  void *v106; // x0
  int v107; // [xsp+44h] [xbp-3Ch]
  __int64 v108; // [xsp+48h] [xbp-38h]
  __int64 v109; // [xsp+50h] [xbp-30h] BYREF
  __int64 v110; // [xsp+58h] [xbp-28h] BYREF
  __int64 v111; // [xsp+60h] [xbp-20h] BYREF
  __int64 v112; // [xsp+68h] [xbp-18h] BYREF
  _QWORD v113[2]; // [xsp+70h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+80h] [xbp+0h] BYREF

  v113[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 2680);
  v109 = 0;
  v110 = 0;
  v7 = *(_QWORD *)(v6 + 56);
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *(_QWORD *)a1 )
    {
      v8 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      if ( !a1 )
        goto LABEL_8;
    }
    else
    {
      v8 = -1;
      if ( !a1 )
        goto LABEL_8;
    }
    v9 = *(_QWORD *)(a1 + 2864);
    if ( v9 )
    {
      v10 = *(_DWORD *)(v9 + 12) - 1;
LABEL_9:
      _drm_dev_dbg(
        0,
        0,
        0,
        "[enc:%d wb:%d] atomic_check:\"%s\",%d,%d]\n",
        v8,
        v10,
        (const char *)(a2 + 224),
        *(unsigned __int16 *)(a2 + 148),
        *(unsigned __int16 *)(a2 + 158));
      goto LABEL_10;
    }
LABEL_8:
    v10 = -1;
    goto LABEL_9;
  }
LABEL_10:
  if ( !a3 || !*a3 )
  {
    printk(&unk_21381D, "sde_encoder_phys_wb_atomic_check");
    goto LABEL_320;
  }
  if ( *((_DWORD *)*a3 + 48) != 1 )
  {
    printk(&unk_21ACC5, "sde_encoder_phys_wb_atomic_check");
    goto LABEL_320;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 2680) + 56LL) + 33LL) & 0x30) != 0 )
  {
    if ( (*(_DWORD *)(a2 + 20) & ~(1 << *(_DWORD *)(*(_QWORD *)a1 + 68LL))) != 0 )
      v11 = 1 << *(_DWORD *)(*(_QWORD *)a1 + 68LL);
    else
      v11 = 0;
  }
  else
  {
    v11 = 0;
  }
  v12 = _drm_debug;
  v13 = *(unsigned __int8 *)(a1 + 2290);
  *(_DWORD *)(a2 + 1812) = v11;
  if ( (v12 & 4) != 0 )
  {
    if ( *(_QWORD *)a1 )
    {
      v14 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      if ( !a1 )
        goto LABEL_25;
    }
    else
    {
      v14 = -1;
      if ( !a1 )
        goto LABEL_25;
    }
    v15 = *(_QWORD *)(a1 + 2864);
    if ( v15 )
    {
      v16 = *(_DWORD *)(v15 + 12) - 1;
LABEL_26:
      _drm_dev_dbg(
        0,
        0,
        0,
        "[enc:%d wb:%d] detect CWB - status:%d, phys state:%d in_clone_mode:%d\n",
        v14,
        v16,
        v11,
        *(_DWORD *)(a1 + 832),
        *(unsigned __int8 *)(a1 + 2290));
      goto LABEL_27;
    }
LABEL_25:
    v16 = -1;
    goto LABEL_26;
  }
LABEL_27:
  if ( v13 && !*(_DWORD *)(a2 + 1812) )
  {
    printk(&unk_225535, "sde_encoder_phys_wb_atomic_check");
    goto LABEL_320;
  }
  v110 = 0;
  output_roi = sde_wb_connector_state_get_output_roi(a3, &v110);
  if ( output_roi )
  {
    if ( *(_QWORD *)a1 )
    {
      if ( !a1 )
        goto LABEL_210;
    }
    else if ( !a1 )
    {
      goto LABEL_210;
    }
    if ( *(_QWORD *)(a1 + 2864) )
    {
      v86 = output_roi;
      goto LABEL_217;
    }
LABEL_210:
    v86 = output_roi;
LABEL_217:
    v89 = &unk_22557B;
LABEL_330:
    printk(v89, "sde_encoder_phys_wb_atomic_check");
    goto LABEL_331;
  }
  output_fb = sde_wb_connector_state_get_output_fb(a3);
  if ( !output_fb )
  {
    printk(&unk_26A13E, "sde_encoder_phys_wb_atomic_check");
    goto LABEL_320;
  }
  v19 = output_fb;
  v20 = *((_DWORD *)a3 + 472);
  sde_format_ext = sde_get_sde_format_ext(**(_DWORD **)(output_fb + 72), *(_QWORD *)(output_fb + 120));
  if ( !sde_format_ext )
  {
    printk(&unk_26A171, "sde_encoder_phys_wb_atomic_check");
    goto LABEL_320;
  }
  v22 = sde_format_ext;
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *(_QWORD *)a1 )
    {
      v23 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      if ( !a1 )
        goto LABEL_39;
    }
    else
    {
      v23 = -1;
      if ( !a1 )
        goto LABEL_39;
    }
    v24 = *(_QWORD *)(a1 + 2864);
    if ( v24 )
    {
      v25 = *(_DWORD *)(v24 + 12) - 1;
LABEL_40:
      _drm_dev_dbg(
        0,
        0,
        0,
        "[enc:%d wb:%d] fb_id:%u, wxh:%ux%u, fb_fmt:%x,%llx, roi:{%d,%d,%d,%d}, rot:%u\n",
        v23,
        v25,
        *(_DWORD *)(v19 + 24),
        *(_DWORD *)(v19 + 128),
        *(_DWORD *)(v19 + 132),
        **(_DWORD **)(v19 + 72),
        *(_QWORD *)(v19 + 120),
        (unsigned __int16)v110,
        WORD1(v110),
        WORD2(v110),
        HIWORD(v110),
        v20);
      goto LABEL_41;
    }
LABEL_39:
    v25 = -1;
    goto LABEL_40;
  }
LABEL_41:
  v108 = v7;
  v26 = *(_QWORD *)(a1 + 512);
  v27 = *(_QWORD *)(*(_QWORD *)(a1 + 2680) + 56LL);
  v28 = (char *)sde_get_sde_format_ext(**(_DWORD **)(v19 + 72), *(_QWORD *)(v19 + 120));
  if ( !v28 )
  {
    printk(&unk_26A171, "_sde_encoder_phys_wb_validate_output_fmt");
    goto LABEL_234;
  }
  v29 = 64;
  if ( !v20 )
    v29 = 56;
  v30 = v28;
  v31 = sde_format_validate_fmt(v26, v28, *(int **)(v27 + v29));
  if ( v31 )
  {
    if ( a1 && *(_QWORD *)(a1 + 2864) )
      v88 = v31;
    else
      v88 = v31;
    printk(&unk_2713D2, "_sde_encoder_phys_wb_validate_output_fmt");
    v92 = v88;
    if ( !*(_QWORD *)a1 )
    {
LABEL_235:
      if ( !a1 )
        goto LABEL_237;
      goto LABEL_236;
    }
LABEL_229:
    if ( !a1 )
      goto LABEL_237;
LABEL_236:
    if ( *(_QWORD *)(a1 + 2864) )
    {
      v86 = v92;
      goto LABEL_239;
    }
LABEL_237:
    v86 = v92;
LABEL_239:
    printk(&unk_221CA4, "sde_encoder_phys_wb_atomic_check");
LABEL_331:
    result = v86;
    goto LABEL_332;
  }
  if ( (unsigned int)(*((_DWORD *)v30 + 4) - 1) <= 1 )
  {
    v95 = &unk_221CFF;
LABEL_233:
    printk(v95, "_sde_encoder_phys_wb_validate_output_fmt");
LABEL_234:
    v92 = -22;
    if ( !*(_QWORD *)a1 )
      goto LABEL_235;
    goto LABEL_229;
  }
  if ( *((_DWORD *)v30 + 7) == 2 && (*((_QWORD *)v30 + 4) & 4) != 0 && (*(_BYTE *)(v27 + 32) & 0x80) == 0 )
  {
    v95 = &unk_2288B3;
    goto LABEL_233;
  }
  if ( (((unsigned int)*((_QWORD *)v22 + 4) ^ (*(_QWORD *)(a1 + 432) == 0)) & 1) == 0 )
    *(_BYTE *)(a2 + 10) |= 2u;
  if ( a2 )
  {
    v32 = *(_DWORD *)(a2 + 2044);
    v33 = *(_DWORD *)(a2 + 1472);
    if ( v32 )
    {
      v34 = *(_DWORD *)(a2 + 2080);
      v35 = v34 != 0;
      if ( v34 )
      {
        v34 = *(_DWORD *)(a2 + 2064);
        v36 = *(_DWORD *)(a2 + 2224);
        v37 = *(_DWORD *)(a2 + 2068);
        v38 = *(unsigned int *)(a2 + 2228);
        if ( v32 == 1 )
          goto LABEL_69;
      }
      else
      {
        v37 = 0;
        v36 = 0;
        v38 = 0;
        if ( v32 == 1 )
          goto LABEL_69;
      }
      if ( *(_DWORD *)(a2 + 2672) )
      {
        v37 = *(_DWORD *)(a2 + 2660);
        v38 = *(unsigned int *)(a2 + 2820);
        v34 += *(_DWORD *)(a2 + 2656);
        v36 += *(_DWORD *)(a2 + 2816);
        v35 = 1;
      }
      if ( v32 >= 3 )
      {
        if ( *(_DWORD *)(a2 + 3264) )
        {
          v37 = *(_DWORD *)(a2 + 3252);
          v38 = *(unsigned int *)(a2 + 3412);
          v34 += *(_DWORD *)(a2 + 3248);
          v36 += *(_DWORD *)(a2 + 3408);
          v35 = 1;
        }
        if ( v32 != 3 )
        {
          if ( *(_DWORD *)(a2 + 3856) )
          {
            v37 = *(_DWORD *)(a2 + 3844);
            v38 = *(unsigned int *)(a2 + 4004);
            v34 += *(_DWORD *)(a2 + 3840);
            v36 += *(_DWORD *)(a2 + 4000);
            v35 = 1;
          }
          if ( v32 > 4 )
            goto LABEL_333;
        }
      }
    }
    else
    {
      v35 = 0;
      v34 = 0;
      v37 = 0;
      v36 = 0;
      v38 = 0;
    }
  }
  else
  {
    v35 = 0;
    v34 = 0;
    v37 = 0;
    v36 = 0;
    v38 = 0;
    v33 = 0;
  }
LABEL_69:
  v39 = *((_DWORD *)a3 + 816);
  if ( v39 && ((_BYTE)a3[409] & 1) != 0 )
  {
    if ( v39 != 1 )
      goto LABEL_333;
    v41 = *((_DWORD *)a3 + 821);
    v42 = *((_DWORD *)a3 + 823);
    v43 = *((_DWORD *)a3 + 822);
    v44 = *((_DWORD *)a3 + 824);
    if ( !v41 || !v43 || !v42 || !v44 || v41 < v42 || v43 < v44 )
    {
      v46 = &unk_21E9AF;
      goto LABEL_303;
    }
    if ( v33 == 1 && v35 )
    {
      if ( v36 != v41 || (_DWORD)v38 != v43 )
      {
        v46 = &unk_2170D4;
        goto LABEL_303;
      }
    }
    else
    {
      if ( v33 )
        v47 = 0;
      else
        v47 = v35;
      if ( v47 && (v34 != v41 || v37 != v43) )
      {
        v46 = &unk_25829B;
LABEL_303:
        printk(v46, "_sde_enc_phys_wb_validate_dnsc_blur_ds");
        v55 = -22;
        if ( *(_QWORD *)a1 )
        {
LABEL_304:
          if ( !a1 )
            goto LABEL_306;
          goto LABEL_305;
        }
LABEL_290:
        if ( !a1 )
          goto LABEL_306;
LABEL_305:
        if ( *(_QWORD *)(a1 + 2864) )
        {
          v86 = v55;
          goto LABEL_308;
        }
LABEL_306:
        v86 = v55;
LABEL_308:
        v89 = &unk_27EB00;
        goto LABEL_330;
      }
    }
    if ( *(_DWORD *)(a2 + 620) )
    {
      v93 = &unk_23CF1A;
      v94 = "_sde_enc_phys_wb_validate_dnsc_blur_ds";
    }
    else if ( (*((_QWORD *)v22 + 4) & 1) != 0 )
    {
      v93 = &unk_22561C;
      v94 = "_sde_enc_phys_wb_validate_dnsc_blur_ds";
    }
    else
    {
      if ( *((_DWORD *)a3 + 472) )
      {
        if ( WORD2(v110) && v44 != WORD2(v110) || HIWORD(v110) && v42 != HIWORD(v110) )
        {
          v46 = &unk_26353E;
          goto LABEL_303;
        }
      }
      else if ( WORD2(v110) && v42 != WORD2(v110) || HIWORD(v110) && v44 != HIWORD(v110) )
      {
        v46 = &unk_24A5FD;
        goto LABEL_303;
      }
      if ( *a3 && (v48 = **a3) != 0 && (v49 = *(_QWORD *)(v48 + 56)) != 0 )
      {
        v50 = *(_QWORD *)(v49 + 8);
        if ( v50 )
        {
          v51 = *(_QWORD *)(v50 + 152);
          if ( !*(_DWORD *)(v51 + 22096) )
            goto LABEL_148;
          v107 = v20;
          v52 = 0;
          while ( 1 )
          {
            v53 = *(int **)(v51 + 22088);
            v54 = *v53;
            if ( *((_DWORD *)a3 + 825) == *v53 )
            {
              v55 = sde_enc_phys_wb_validate_dnsc_blur_filter(
                      v53,
                      *((unsigned int *)a3 + 821),
                      *((unsigned int *)a3 + 823));
              if ( v55 )
                break;
              v54 = *v53;
            }
            if ( *((_DWORD *)a3 + 826) == v54 )
            {
              v55 = sde_enc_phys_wb_validate_dnsc_blur_filter(
                      v53,
                      *((unsigned int *)a3 + 822),
                      *((unsigned int *)a3 + 824));
              if ( v55 )
                break;
            }
            v51 = *(_QWORD *)(v50 + 152);
            if ( (unsigned int)++v52 >= *(_DWORD *)(v51 + 22096) )
            {
              v55 = 0;
              break;
            }
          }
          v56 = *((_DWORD *)a3 + 816);
          if ( v56 >= 2 )
          {
            v57 = *(_QWORD *)(v50 + 152);
            if ( *(_DWORD *)(v57 + 22096) )
            {
              v58 = 0;
              do
              {
                v59 = *(_QWORD *)(v57 + 22088);
                v62 = *(_DWORD *)(v59 + 64);
                v61 = (int *)(v59 + 64);
                v60 = v62;
                if ( *((_DWORD *)a3 + 995) == v62 )
                {
                  v55 = sde_enc_phys_wb_validate_dnsc_blur_filter(
                          v61,
                          *((unsigned int *)a3 + 991),
                          *((unsigned int *)a3 + 993));
                  if ( v55 )
                    break;
                  v60 = *v61;
                }
                if ( *((_DWORD *)a3 + 996) == v60 )
                {
                  v55 = sde_enc_phys_wb_validate_dnsc_blur_filter(
                          v61,
                          *((unsigned int *)a3 + 992),
                          *((unsigned int *)a3 + 994));
                  if ( v55 )
                    break;
                }
                v57 = *(_QWORD *)(v50 + 152);
                ++v58;
              }
              while ( v58 < *(_DWORD *)(v57 + 22096) );
              v56 = *((_DWORD *)a3 + 816);
              v20 = v107;
            }
            if ( v56 > 2 )
              goto LABEL_333;
          }
          if ( !v55 )
          {
LABEL_148:
            if ( *(_DWORD *)(a2 + 1812) )
              goto LABEL_149;
            if ( !v20 )
              goto LABEL_256;
            v64 = *((_DWORD *)a3 + 472);
            v111 = 0;
            v112 = 0;
            if ( !v64 )
              goto LABEL_256;
            v65 = *((_DWORD *)a3 + 464);
            v113[0] = 0;
            if ( v65 != 3 )
            {
              printk(&unk_2511E3, "_sde_encoder_phys_wb_validate_rotation");
              goto LABEL_324;
            }
            if ( !*((_DWORD *)a3 + 480) )
            {
              printk(&unk_271431, "_sde_encoder_phys_wb_validate_rotation");
              goto LABEL_324;
            }
            v66 = sde_wb_connector_state_get_output_roi(a3, &v112);
            if ( v66 )
            {
              if ( a1 && *(_QWORD *)(a1 + 2864) )
                v105 = v66;
              else
                v105 = v66;
              printk(&unk_251239, "_sde_encoder_phys_wb_validate_rotation");
              goto LABEL_325;
            }
            sde_crtc_get_crtc_roi(a2, &v111);
            if ( !v111 )
            {
              printk(&unk_243FD3, "_sde_encoder_phys_wb_validate_rotation");
              goto LABEL_324;
            }
            if ( *(_WORD *)(v111 + 4) && *(_WORD *)(v111 + 6) )
            {
              printk(&unk_21EA35, "_sde_encoder_phys_wb_validate_rotation");
              goto LABEL_324;
            }
            sde_crtc_get_resolution(*(_QWORD *)a2, a2, a2 + 144, (_DWORD *)v113 + 1, v113);
            v68 = v113[0];
            LOWORD(v67) = WORD2(v113[0]);
            if ( !HIDWORD(v113[0]) || !LODWORD(v113[0]) )
            {
              printk(&unk_22F7BC, "_sde_encoder_phys_wb_validate_rotation");
              goto LABEL_324;
            }
            v69 = *((_DWORD *)a3 + 816);
            if ( !v69 || ((_BYTE)a3[409] & 1) == 0 )
            {
              v70 = 0;
              v71 = 0;
              if ( (_drm_debug & 4) == 0 )
              {
LABEL_164:
                v72 = (unsigned __int16)v67;
                goto LABEL_248;
              }
LABEL_221:
              if ( *(_QWORD *)a1 )
                v90 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
              else
                v90 = -1;
              if ( a1 && (v96 = *(_QWORD *)(a1 + 2864)) != 0 )
                v97 = *(_DWORD *)(v96 + 12) - 1;
              else
                v97 = -1;
              v72 = (unsigned __int16)v67;
              _drm_dev_dbg(
                0,
                0,
                0,
                "[enc:%d wb:%d] wb_src=[%dx%d] dnsc_dst=[%dx%d] wb_roi=[%dx%d]\n",
                v90,
                v97,
                (unsigned __int16)v67,
                v68,
                v70,
                v71,
                WORD2(v112),
                HIWORD(v112));
LABEL_248:
              if ( v72 == HIWORD(v112) && WORD2(v112) == v68 )
              {
                if ( (v112 & 3) == 0 && (v112 & 0x30000) == 0 )
                {
                  if ( v64 != 2 || (v72 & 3) == 0 )
                  {
                    if ( v72 <= 0x1000 && v68 <= 0x1000u )
                    {
LABEL_256:
                      sde_enc_phys_wb_get_out_resolution(a2, a3, (char *)&v109 + 4, &v109, v38);
                      v98 = WORD2(v110);
                      if ( WORD2(v110) && (v99 = HIWORD(v110)) != 0 )
                      {
                        v100 = (unsigned __int16)v110;
                      }
                      else
                      {
                        v99 = v109;
                        v98 = WORD2(v109);
                        v100 = 0;
                        LODWORD(v110) = 0;
                        WORD2(v110) = WORD2(v109);
                        HIWORD(v110) = v109;
                      }
                      if ( (unsigned int)v98 + v100 > *(_DWORD *)(v19 + 128) || HIDWORD(v109) < v98 )
                      {
                        v104 = &unk_2255BE;
                      }
                      else if ( v99 + (unsigned int)WORD1(v110) > *(_DWORD *)(v19 + 132) || (unsigned int)v109 < v99 )
                      {
                        v104 = &unk_247184;
                      }
                      else if ( v20
                             || HIDWORD(v109) <= *(unsigned __int16 *)(a2 + 148)
                             && (unsigned int)v109 <= *(unsigned __int16 *)(a2 + 158) )
                      {
                        v101 = *((_DWORD *)v22 + 7);
                        if ( v101 == 2 && (*((_QWORD *)v22 + 4) & 4) != 0 || (*((_QWORD *)v22 + 4) & 1) != 0 )
                          v102 = *(_DWORD **)(v108 + 48);
                        else
                          v102 = (_DWORD *)(*(_QWORD *)(v108 + 48) + 4LL);
                        if ( *v102 >= (unsigned int)v98 )
                          goto LABEL_273;
                        v104 = &unk_236376;
                      }
                      else
                      {
                        v104 = &unk_251150;
                      }
                      printk(v104, "sde_encoder_phys_wb_atomic_check");
LABEL_320:
                      result = 4294967274LL;
                      goto LABEL_332;
                    }
                    v106 = &unk_26DC63;
                    goto LABEL_323;
                  }
                  printk(&unk_21EA7F, "_sde_encoder_phys_wb_validate_rotation");
LABEL_324:
                  v105 = -22;
LABEL_325:
                  if ( a1 && *(_QWORD *)(a1 + 2864) )
                    v86 = v105;
                  else
                    v86 = v105;
                  v89 = &unk_24D9AD;
                  goto LABEL_330;
                }
                v106 = &unk_221D75;
              }
              else
              {
                v106 = &unk_24DA11;
              }
LABEL_323:
              printk(v106, "_sde_encoder_phys_wb_validate_rotation");
              goto LABEL_324;
            }
            if ( v69 == 1 )
            {
              v67 = *((_DWORD *)a3 + 823);
              v71 = *((_DWORD *)a3 + 824);
              v70 = v67;
              v68 = v71;
              if ( (_drm_debug & 4) == 0 )
                goto LABEL_164;
              goto LABEL_221;
            }
LABEL_333:
            __break(0x5512u);
            if ( !&vars0 )
              JUMPOUT(0x1B0D78);
            JUMPOUT(0x1CC184);
          }
LABEL_289:
          if ( *(_QWORD *)a1 )
            goto LABEL_304;
          goto LABEL_290;
        }
        v87 = &unk_234896;
      }
      else
      {
        v87 = &unk_242658;
      }
      printk(v87, "sde_connector_get_kms");
      v93 = &unk_234896;
      v94 = "_sde_enc_phys_wb_validate_dnsc_blur_filters";
    }
    printk(v93, v94);
    v55 = -22;
    goto LABEL_289;
  }
  if ( *((_DWORD *)a3 + 472) )
    v40 = 1;
  else
    v40 = v35;
  if ( (v40 & 1) != 0 )
    goto LABEL_148;
  if ( !*(_DWORD *)(a2 + 1812) )
  {
    if ( WORD2(v110) && WORD2(v110) != *(unsigned __int16 *)(a2 + 148)
      || HIWORD(v110) && HIWORD(v110) != *(unsigned __int16 *)(a2 + 158) )
    {
      v46 = &unk_2397E2;
      goto LABEL_303;
    }
    goto LABEL_148;
  }
LABEL_149:
  v111 = 0;
  v112 = 0;
  v113[0] = 0;
  if ( a2 )
    v63 = *(_DWORD *)(a2 + 1472);
  else
    v63 = 0;
  v73 = sde_wb_connector_state_get_output_fb(a3);
  if ( v73 )
  {
    v74 = v73;
    num_datapath = sde_crtc_get_num_datapath(*(_QWORD *)a2, (__int64)*a3, a2);
    if ( num_datapath >= 5 )
    {
      printk(&unk_23CF54, "_sde_enc_phys_wb_validate_cwb");
      goto LABEL_277;
    }
    v76 = sde_get_sde_format_ext(**(_DWORD **)(v74 + 72), *(_QWORD *)(v74 + 120));
    if ( !v76 )
    {
      printk(&unk_258318, "_sde_enc_phys_wb_validate_cwb");
      goto LABEL_277;
    }
    v77 = v76;
    v78 = sde_wb_connector_state_get_output_roi(a3, &v112);
    if ( v78 )
    {
      v91 = v78;
      printk(&unk_22BCED, "_sde_enc_phys_wb_validate_cwb");
      goto LABEL_278;
    }
    if ( !WORD2(v112) || !HIWORD(v112) )
    {
      printk(&unk_2511AC, "_sde_enc_phys_wb_validate_cwb");
      goto LABEL_277;
    }
    if ( *((_DWORD *)a3 + 320) )
    {
      printk(&unk_2471E1, "_sde_enc_phys_wb_validate_cwb");
      goto LABEL_277;
    }
    sde_enc_phys_wb_get_out_resolution(a2, a3, (char *)v113 + 4, v113, HIWORD(v112));
    if ( (*((_QWORD *)v77 + 4) & 1) != 0 && v113[0] != __PAIR64__(WORD2(v112), HIWORD(v112)) )
    {
      v85 = &unk_21E9F3;
      goto LABEL_202;
    }
    v79 = WORD2(v112);
    v80 = HIWORD(v112);
    if ( HIDWORD(v113[0]) < WORD2(v112) || LODWORD(v113[0]) < HIWORD(v112) )
    {
      printk(&unk_22F781, "_sde_enc_phys_wb_validate_cwb");
      goto LABEL_277;
    }
    if ( num_datapath == 4
      && (WORD2(v112) != HIDWORD(v113[0]) >> 1
       || WORD2(v112) != (unsigned __int16)v112 && (_WORD)v112 && HIDWORD(v113[0]) >> 2 != (unsigned __int16)v112) )
    {
      printk(&unk_258355, "_sde_enc_phys_wb_validate_cwb");
      goto LABEL_277;
    }
    v81 = *(_DWORD *)(v74 + 128);
    if ( __PAIR64__(v81, *(_DWORD *)(v74 + 132)) == v113[0]
      && ((unsigned __int16)v112 + (unsigned int)WORD2(v112) > HIDWORD(v113[0])
       || WORD1(v112) + (unsigned int)HIWORD(v112) > LODWORD(v113[0])) )
    {
      v85 = &unk_25C170;
      goto LABEL_202;
    }
    v82 = *(_DWORD *)(v74 + 132);
    if ( (v81 < HIDWORD(v113[0]) || v82 < LODWORD(v113[0])) && (v81 < WORD2(v112) || v82 < HIWORD(v112)) )
    {
      v85 = &unk_25C170;
      goto LABEL_202;
    }
    if ( !*(_DWORD *)(a2 + 620) && !*((_DWORD *)a3 + 512) )
      goto LABEL_273;
    if ( a2 )
    {
      if ( v63 )
        v83 = (unsigned int *)(a3 + 256);
      else
        v83 = (unsigned int *)(a2 + 620);
      sde_kms_rect_merge_rectangles(v83, (__int64)&v111);
      v79 = WORD2(v112);
      v84 = WORD2(v111);
      v80 = HIWORD(v112);
      if ( WORD2(v112) > (unsigned int)WORD2(v111) )
        goto LABEL_206;
    }
    else
    {
      v84 = 0;
      if ( WORD2(v112) )
        goto LABEL_206;
    }
    if ( v80 <= HIWORD(v111) )
    {
      if ( WORD1(v112) < (unsigned int)WORD1(v111)
        || (unsigned __int16)v112 < (unsigned int)(unsigned __int16)v111
        || WORD1(v112) + v80 > WORD1(v111) + (unsigned int)HIWORD(v111)
        || v79 + (unsigned int)(unsigned __int16)v112 > (unsigned int)(unsigned __int16)v111 + v84 )
      {
        v85 = &unk_22BD1C;
LABEL_202:
        printk(v85, "_sde_enc_phys_wb_validate_cwb");
LABEL_277:
        v91 = -22;
LABEL_278:
        if ( *(_QWORD *)a1 )
        {
          if ( !a1 )
            goto LABEL_283;
        }
        else if ( !a1 )
        {
          goto LABEL_283;
        }
        if ( *(_QWORD *)(a1 + 2864) )
        {
          v86 = v91;
          goto LABEL_285;
        }
LABEL_283:
        v86 = v91;
LABEL_285:
        v89 = &unk_27138D;
        goto LABEL_330;
      }
      goto LABEL_273;
    }
LABEL_206:
    printk(&unk_25FBDF, "_sde_enc_phys_wb_validate_cwb");
    goto LABEL_277;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "no output framebuffer\n");
LABEL_273:
  result = 0;
LABEL_332:
  _ReadStatusReg(SP_EL0);
  return result;
}
