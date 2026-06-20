__int64 __fastcall sde_crtc_reset_hw(__int64 *a1, __int64 a2, char a3)
{
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v8; // x9
  __int64 v9; // x9
  unsigned int v10; // w25
  void *v11; // x0
  const char *v12; // x1
  int v13; // w4
  unsigned int v14; // w8
  __int64 v15; // x22
  unsigned int (__fastcall *v16)(_QWORD); // x9
  __int64 v17; // x0
  int v18; // w23
  unsigned int (__fastcall *v19)(_QWORD); // x9
  __int64 v20; // x0
  unsigned int (__fastcall *v21)(_QWORD); // x9
  __int64 v22; // x0
  unsigned int (__fastcall *v23)(_QWORD); // x9
  __int64 v24; // x0
  unsigned int (__fastcall *v25)(_QWORD); // x9
  __int64 v26; // x0
  unsigned int (__fastcall *v27)(_QWORD); // x9
  __int64 v28; // x0
  unsigned int (__fastcall *v29)(_QWORD); // x9
  __int64 v30; // x0
  unsigned int (__fastcall *v31)(_QWORD); // x9
  __int64 v32; // x0
  int v33; // w4
  int v34; // w22
  unsigned __int64 v35; // x28
  __int64 *v36; // x20
  unsigned __int64 v37; // x8
  __int64 v38; // x24
  void (__fastcall *v39)(__int64, __int64); // x8
  __int64 v40; // x0
  __int64 v41; // x0
  void (*v42)(void); // x9
  __int64 v43; // x0
  void (*v44)(void); // x9
  __int64 v45; // x0
  void (*v46)(void); // x9
  __int64 v47; // x0
  void (*v48)(void); // x9
  __int64 v49; // x0
  void (*v50)(void); // x9
  __int64 v51; // x0
  void (*v52)(void); // x9
  __int64 v53; // x0
  void (*v54)(void); // x9
  __int64 v55; // x0
  void (*v56)(void); // x9
  __int64 v57; // x8
  __int64 v58; // x9
  __int64 *v59; // x20
  unsigned int v60; // w23
  __int64 v61; // x8
  __int64 *v62; // x20
  __int64 v63; // x21
  __int64 v64; // x22
  __int64 v65; // x9
  _QWORD *i; // x20
  unsigned int v67; // w8
  __int64 v68; // x0
  void (*v69)(void); // x9
  __int64 v70; // x0
  void (*v71)(void); // x9
  __int64 v72; // x0
  void (*v73)(void); // x9
  __int64 v74; // x0
  void (*v75)(void); // x9
  __int64 v76; // x0
  void (*v77)(void); // x9
  __int64 v78; // x0
  void (*v79)(void); // x9
  __int64 v80; // x0
  void (*v81)(void); // x9
  __int64 v82; // x0
  void (*v83)(void); // x9
  _QWORD *v84; // x20
  __int64 j; // x8
  char v86; // [xsp+0h] [xbp-120h]
  char v87; // [xsp+0h] [xbp-120h]
  char v88; // [xsp+Ch] [xbp-114h]
  _QWORD v89[34]; // [xsp+10h] [xbp-110h] BYREF

  v89[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = 4294967274LL;
    goto LABEL_267;
  }
  result = 4294967274LL;
  if ( a2 && *a1 && a1[251] )
  {
    v6 = *(_QWORD *)(*a1 + 56);
    if ( v6 )
    {
      v8 = *(_QWORD *)(v6 + 8);
      if ( v8 )
      {
        v9 = *(_QWORD *)(v8 + 152);
        if ( v9 && (*(_QWORD *)(v9 + 22008) & 0x8000000000000LL) != 0 )
        {
          v10 = *(_DWORD *)(v6 + 5912);
          goto LABEL_15;
        }
LABEL_14:
        v10 = 0;
LABEL_15:
        v13 = *((_DWORD *)a1 + 28);
        memset(v89, 0, 256);
        sde_evtlog_log(sde_dbg_base_evtlog, "sde_crtc_reset_hw", 5554, -1, v13, a3 & 1, 4369, -1059143953, v86);
        sde_dbg_ctrl("sde_crtc_reset_hw", "stop_ftrace", "reset_hw_panic", 0);
        v14 = *((_DWORD *)a1 + 547);
        if ( !v14 )
          goto LABEL_98;
        v15 = a1[276];
        if ( v15 )
        {
          if ( v10 > 2 )
            goto LABEL_272;
          v16 = *(unsigned int (__fastcall **)(_QWORD))(v15 + 8LL * v10 + 928);
          if ( v16 )
          {
            v17 = a1[276];
            if ( *((_DWORD *)v16 - 1) != 1800103338 )
              __break(0x8229u);
            if ( v16(v17) )
            {
              v18 = 0;
LABEL_92:
              v33 = *((_DWORD *)a1 + 28);
              if ( (_drm_debug & 4) != 0 )
              {
                _drm_dev_dbg(0, 0, 0, "crtc%d: ctl%d reset failure\n", v33, *(_DWORD *)(v15 + 64) - 1);
                v33 = *((_DWORD *)a1 + 28);
              }
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "sde_crtc_reset_hw",
                5569,
                -1,
                v33,
                *(_DWORD *)(v15 + 64) - 1,
                60333,
                -1059143953,
                v87);
              v14 = *((_DWORD *)a1 + 547);
              goto LABEL_95;
            }
            v14 = *((_DWORD *)a1 + 547);
          }
        }
        if ( v14 < 2 )
        {
          v18 = 1;
          goto LABEL_95;
        }
        v15 = a1[282];
        if ( v15 )
        {
          if ( v10 > 2 )
            goto LABEL_272;
          v19 = *(unsigned int (__fastcall **)(_QWORD))(v15 + 8LL * v10 + 928);
          if ( v19 )
          {
            v20 = a1[282];
            if ( *((_DWORD *)v19 - 1) != 1800103338 )
              __break(0x8229u);
            if ( v19(v20) )
            {
              v18 = 1;
              goto LABEL_92;
            }
            v14 = *((_DWORD *)a1 + 547);
          }
        }
        if ( v14 < 3 )
        {
          v18 = 2;
          goto LABEL_95;
        }
        v15 = a1[288];
        if ( v15 )
        {
          if ( v10 > 2 )
            goto LABEL_272;
          v21 = *(unsigned int (__fastcall **)(_QWORD))(v15 + 8LL * v10 + 928);
          if ( v21 )
          {
            v22 = a1[288];
            if ( *((_DWORD *)v21 - 1) != 1800103338 )
              __break(0x8229u);
            if ( v21(v22) )
            {
              v18 = 2;
              goto LABEL_92;
            }
            v14 = *((_DWORD *)a1 + 547);
          }
        }
        if ( v14 < 4 )
        {
          v18 = 3;
          goto LABEL_95;
        }
        v15 = a1[294];
        if ( v15 )
        {
          if ( v10 > 2 )
            goto LABEL_272;
          v23 = *(unsigned int (__fastcall **)(_QWORD))(v15 + 8LL * v10 + 928);
          if ( v23 )
          {
            v24 = a1[294];
            if ( *((_DWORD *)v23 - 1) != 1800103338 )
              __break(0x8229u);
            if ( v23(v24) )
            {
              v18 = 3;
              goto LABEL_92;
            }
            v14 = *((_DWORD *)a1 + 547);
          }
        }
        if ( v14 < 5 )
        {
          v18 = 4;
          goto LABEL_95;
        }
        v15 = a1[300];
        if ( v15 )
        {
          if ( v10 > 2 )
            goto LABEL_272;
          v25 = *(unsigned int (__fastcall **)(_QWORD))(v15 + 8LL * v10 + 928);
          if ( v25 )
          {
            v26 = a1[300];
            if ( *((_DWORD *)v25 - 1) != 1800103338 )
              __break(0x8229u);
            if ( v25(v26) )
            {
              v18 = 4;
              goto LABEL_92;
            }
            v14 = *((_DWORD *)a1 + 547);
          }
        }
        if ( v14 < 6 )
        {
          v18 = 5;
          goto LABEL_95;
        }
        v15 = a1[306];
        if ( v15 )
        {
          if ( v10 > 2 )
            goto LABEL_272;
          v27 = *(unsigned int (__fastcall **)(_QWORD))(v15 + 8LL * v10 + 928);
          if ( v27 )
          {
            v28 = a1[306];
            if ( *((_DWORD *)v27 - 1) != 1800103338 )
              __break(0x8229u);
            if ( v27(v28) )
            {
              v18 = 5;
              goto LABEL_92;
            }
            v14 = *((_DWORD *)a1 + 547);
          }
        }
        if ( v14 < 7 )
        {
          v18 = 6;
          goto LABEL_95;
        }
        v15 = a1[312];
        if ( v15 )
        {
          if ( v10 > 2 )
            goto LABEL_272;
          v29 = *(unsigned int (__fastcall **)(_QWORD))(v15 + 8LL * v10 + 928);
          if ( v29 )
          {
            v30 = a1[312];
            if ( *((_DWORD *)v29 - 1) != 1800103338 )
              __break(0x8229u);
            if ( v29(v30) )
            {
              v18 = 6;
              goto LABEL_92;
            }
            v14 = *((_DWORD *)a1 + 547);
          }
        }
        if ( v14 < 8 )
        {
          v18 = 7;
          goto LABEL_95;
        }
        v15 = a1[318];
        if ( v15 )
        {
          if ( v10 > 2 )
            goto LABEL_272;
          v31 = *(unsigned int (__fastcall **)(_QWORD))(v15 + 8LL * v10 + 928);
          if ( v31 )
          {
            v32 = a1[318];
            if ( *((_DWORD *)v31 - 1) != 1800103338 )
              __break(0x8229u);
            if ( v31(v32) )
            {
              v18 = 7;
              goto LABEL_92;
            }
            v14 = *((_DWORD *)a1 + 547);
          }
        }
        if ( v14 > 8 )
          goto LABEL_272;
        v18 = 8;
LABEL_95:
        if ( v18 != v14 && a1[251] != a2 )
        {
          v34 = 0;
LABEL_100:
          if ( (_drm_debug & 4) != 0 )
          {
            _drm_dev_dbg(0, 0, 0, "crtc%d: issuing hard reset\n", *((_DWORD *)a1 + 28));
            v14 = *((_DWORD *)a1 + 547);
          }
          v88 = a3;
          if ( v14 )
          {
            v35 = 0;
            v36 = a1 + 276;
            do
            {
              if ( v35 == 8 )
                goto LABEL_272;
              v38 = *v36;
              if ( *v36 )
              {
                if ( v10 > 2 )
                  goto LABEL_272;
                if ( *(_QWORD *)(v38 + 1000 + 8LL * v10) )
                {
                  sde_evtlog_log(
                    sde_dbg_base_evtlog,
                    "sde_crtc_reset_hw",
                    5594,
                    -1,
                    *((_DWORD *)a1 + 28),
                    *(_DWORD *)(v38 + 64) - 1,
                    v34,
                    -1059143953,
                    v87);
                  v39 = *(void (__fastcall **)(__int64, __int64))(v38 + 1000 + 8LL * v10);
                  if ( v39 )
                  {
                    if ( *((_DWORD *)v39 - 1) != -1792093723 )
                      __break(0x8228u);
                    v39(v38, 1);
                  }
                  v40 = a1[1002];
                  if ( v40 )
                  {
                    sde_cesta_reset_ctrl(v40, 1);
                    sde_cesta_reset_ctrl(a1[1002], 0);
                  }
                }
              }
              v37 = *((unsigned int *)a1 + 547);
              ++v35;
              v36 += 6;
            }
            while ( v35 < v37 );
            if ( (v34 & 1) != 0 )
            {
              if ( (_DWORD)v37 )
              {
                v41 = a1[276];
                if ( v41 )
                {
                  if ( v10 > 2 )
                    goto LABEL_272;
                  v42 = *(void (**)(void))(v41 + 8LL * v10 + 1000);
                  if ( v42 )
                  {
                    if ( *((_DWORD *)v42 - 1) != -1792093723 )
                      __break(0x8229u);
                    v42();
                    LODWORD(v37) = *((_DWORD *)a1 + 547);
                  }
                }
                if ( (unsigned int)v37 >= 2 )
                {
                  v43 = a1[282];
                  if ( v43 )
                  {
                    if ( v10 > 2 )
                      goto LABEL_272;
                    v44 = *(void (**)(void))(v43 + 8LL * v10 + 1000);
                    if ( v44 )
                    {
                      if ( *((_DWORD *)v44 - 1) != -1792093723 )
                        __break(0x8229u);
                      v44();
                      LODWORD(v37) = *((_DWORD *)a1 + 547);
                    }
                  }
                  if ( (unsigned int)v37 >= 3 )
                  {
                    v45 = a1[288];
                    if ( v45 )
                    {
                      if ( v10 > 2 )
                        goto LABEL_272;
                      v46 = *(void (**)(void))(v45 + 8LL * v10 + 1000);
                      if ( v46 )
                      {
                        if ( *((_DWORD *)v46 - 1) != -1792093723 )
                          __break(0x8229u);
                        v46();
                        LODWORD(v37) = *((_DWORD *)a1 + 547);
                      }
                    }
                    if ( (unsigned int)v37 >= 4 )
                    {
                      v47 = a1[294];
                      if ( v47 )
                      {
                        if ( v10 > 2 )
                          goto LABEL_272;
                        v48 = *(void (**)(void))(v47 + 8LL * v10 + 1000);
                        if ( v48 )
                        {
                          if ( *((_DWORD *)v48 - 1) != -1792093723 )
                            __break(0x8229u);
                          v48();
                          LODWORD(v37) = *((_DWORD *)a1 + 547);
                        }
                      }
                      if ( (unsigned int)v37 >= 5 )
                      {
                        v49 = a1[300];
                        if ( v49 )
                        {
                          if ( v10 > 2 )
                            goto LABEL_272;
                          v50 = *(void (**)(void))(v49 + 8LL * v10 + 1000);
                          if ( v50 )
                          {
                            if ( *((_DWORD *)v50 - 1) != -1792093723 )
                              __break(0x8229u);
                            v50();
                            LODWORD(v37) = *((_DWORD *)a1 + 547);
                          }
                        }
                        if ( (unsigned int)v37 >= 6 )
                        {
                          v51 = a1[306];
                          if ( v51 )
                          {
                            if ( v10 > 2 )
                              goto LABEL_272;
                            v52 = *(void (**)(void))(v51 + 8LL * v10 + 1000);
                            if ( v52 )
                            {
                              if ( *((_DWORD *)v52 - 1) != -1792093723 )
                                __break(0x8229u);
                              v52();
                              LODWORD(v37) = *((_DWORD *)a1 + 547);
                            }
                          }
                          if ( (unsigned int)v37 >= 7 )
                          {
                            v53 = a1[312];
                            if ( v53 )
                            {
                              if ( v10 > 2 )
                                goto LABEL_272;
                              v54 = *(void (**)(void))(v53 + 8LL * v10 + 1000);
                              if ( v54 )
                              {
                                if ( *((_DWORD *)v54 - 1) != -1792093723 )
                                  __break(0x8229u);
                                v54();
                                LODWORD(v37) = *((_DWORD *)a1 + 547);
                              }
                            }
                            if ( (unsigned int)v37 >= 8 )
                            {
                              v55 = a1[318];
                              if ( !v55 )
                                goto LABEL_172;
                              if ( v10 <= 2 )
                              {
                                v56 = *(void (**)(void))(v55 + 8LL * v10 + 1000);
                                if ( v56 )
                                {
                                  if ( *((_DWORD *)v56 - 1) != -1792093723 )
                                    __break(0x8229u);
                                  v56();
                                  LODWORD(v37) = *((_DWORD *)a1 + 547);
                                }
LABEL_172:
                                if ( (unsigned int)v37 > 8 )
                                  goto LABEL_272;
                                goto LABEL_175;
                              }
LABEL_272:
                              __break(0x5512u);
LABEL_273:
                              __break(1u);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
LABEL_175:
              result = 0;
              goto LABEL_267;
            }
          }
          else if ( (v34 & 1) != 0 )
          {
            goto LABEL_175;
          }
          v57 = *(_QWORD *)(a2 + 328);
          v58 = *(_QWORD *)(v57 + 8);
          v59 = *(__int64 **)(v58 + 840);
          if ( v59 != (__int64 *)(v58 + 840) )
          {
            v60 = 0;
            while ( 1 )
            {
              if ( ((*(_DWORD *)(a2 + 12) >> *((_DWORD *)v59 + 437)) & 1) != 0 )
              {
                if ( v60 > 0x1F )
                  goto LABEL_183;
                v89[v60] = v59 - 1;
                sde_plane_halt_requests(v59 - 1, 1);
                sde_plane_set_revalidate(v59 - 1, 1);
                v57 = *(_QWORD *)(a2 + 328);
                ++v60;
              }
              v59 = (__int64 *)*v59;
              if ( v59 == (__int64 *)(*(_QWORD *)(v57 + 8) + 840LL) )
                goto LABEL_183;
            }
          }
          v60 = 0;
LABEL_183:
          v61 = *a1;
          v62 = *(__int64 **)(*a1 + 840);
          if ( v62 != (__int64 *)(*a1 + 840) )
          {
            v63 = a1[276];
            do
            {
              if ( ((*(_DWORD *)(a1[251] + 12) >> *((_DWORD *)v62 + 437)) & 1) != 0 && v62[220] )
              {
                ((void (__fastcall *)(__int64 *, __int64, _QWORD))sde_plane_ctl_flush)(v62 - 1, v63, 0);
                v61 = *a1;
              }
              v62 = (__int64 *)*v62;
            }
            while ( v62 != (__int64 *)(v61 + 840) );
          }
          sde_crtc_blend_setup(a1, 0);
          if ( (int)(v60 - 1) >= 0 )
          {
            v64 = v60 - 1;
            while ( v60 - 1 <= 0x1F )
            {
              if ( (v64 & 0x1FFFFFFFFFFFFFE0LL) != 0 )
                goto LABEL_273;
              sde_plane_halt_requests(v89[v64--], 0);
              if ( v64 == -1 )
                goto LABEL_194;
            }
            goto LABEL_272;
          }
LABEL_194:
          v65 = *a1;
          for ( i = *(_QWORD **)(*a1 + 816); i != (_QWORD *)(v65 + 816); i = (_QWORD *)*i )
          {
            if ( (__int64 *)i[9] == a1 && (unsigned int)sde_encoder_get_intf_mode(i - 1) == 2 )
              sde_encoder_poll_line_counts(i - 1);
            v65 = *a1;
          }
          v67 = *((_DWORD *)a1 + 547);
          if ( v67 )
          {
            v68 = a1[276];
            if ( v68 )
            {
              if ( v10 > 2 )
                goto LABEL_272;
              v69 = *(void (**)(void))(v68 + 8LL * v10 + 1000);
              if ( v69 )
              {
                if ( *((_DWORD *)v69 - 1) != -1792093723 )
                  __break(0x8229u);
                v69();
                v67 = *((_DWORD *)a1 + 547);
              }
            }
            if ( v67 >= 2 )
            {
              v70 = a1[282];
              if ( v70 )
              {
                if ( v10 > 2 )
                  goto LABEL_272;
                v71 = *(void (**)(void))(v70 + 8LL * v10 + 1000);
                if ( v71 )
                {
                  if ( *((_DWORD *)v71 - 1) != -1792093723 )
                    __break(0x8229u);
                  v71();
                  v67 = *((_DWORD *)a1 + 547);
                }
              }
              if ( v67 >= 3 )
              {
                v72 = a1[288];
                if ( v72 )
                {
                  if ( v10 > 2 )
                    goto LABEL_272;
                  v73 = *(void (**)(void))(v72 + 8LL * v10 + 1000);
                  if ( v73 )
                  {
                    if ( *((_DWORD *)v73 - 1) != -1792093723 )
                      __break(0x8229u);
                    v73();
                    v67 = *((_DWORD *)a1 + 547);
                  }
                }
                if ( v67 >= 4 )
                {
                  v74 = a1[294];
                  if ( v74 )
                  {
                    if ( v10 > 2 )
                      goto LABEL_272;
                    v75 = *(void (**)(void))(v74 + 8LL * v10 + 1000);
                    if ( v75 )
                    {
                      if ( *((_DWORD *)v75 - 1) != -1792093723 )
                        __break(0x8229u);
                      v75();
                      v67 = *((_DWORD *)a1 + 547);
                    }
                  }
                  if ( v67 >= 5 )
                  {
                    v76 = a1[300];
                    if ( v76 )
                    {
                      if ( v10 > 2 )
                        goto LABEL_272;
                      v77 = *(void (**)(void))(v76 + 8LL * v10 + 1000);
                      if ( v77 )
                      {
                        if ( *((_DWORD *)v77 - 1) != -1792093723 )
                          __break(0x8229u);
                        v77();
                        v67 = *((_DWORD *)a1 + 547);
                      }
                    }
                    if ( v67 >= 6 )
                    {
                      v78 = a1[306];
                      if ( v78 )
                      {
                        if ( v10 > 2 )
                          goto LABEL_272;
                        v79 = *(void (**)(void))(v78 + 8LL * v10 + 1000);
                        if ( v79 )
                        {
                          if ( *((_DWORD *)v79 - 1) != -1792093723 )
                            __break(0x8229u);
                          v79();
                          v67 = *((_DWORD *)a1 + 547);
                        }
                      }
                      if ( v67 >= 7 )
                      {
                        v80 = a1[312];
                        if ( v80 )
                        {
                          if ( v10 > 2 )
                            goto LABEL_272;
                          v81 = *(void (**)(void))(v80 + 8LL * v10 + 1000);
                          if ( v81 )
                          {
                            if ( *((_DWORD *)v81 - 1) != -1792093723 )
                              __break(0x8229u);
                            v81();
                            v67 = *((_DWORD *)a1 + 547);
                          }
                        }
                        if ( v67 >= 8 )
                        {
                          v82 = a1[318];
                          if ( v82 )
                          {
                            if ( v10 > 2 )
                              goto LABEL_272;
                            v83 = *(void (**)(void))(v82 + 8LL * v10 + 1000);
                            if ( v83 )
                            {
                              if ( *((_DWORD *)v83 - 1) != -1792093723 )
                                __break(0x8229u);
                              v83();
                              v67 = *((_DWORD *)a1 + 547);
                            }
                          }
                          if ( v67 > 8 )
                            goto LABEL_272;
                        }
                      }
                    }
                  }
                }
              }
            }
            v65 = *a1;
          }
          v84 = *(_QWORD **)(v65 + 816);
          for ( j = v65 + 816; v84 != (_QWORD *)j; j = *a1 + 816 )
          {
            if ( (__int64 *)v84[9] == a1 && (unsigned int)sde_encoder_get_intf_mode(v84 - 1) == 2 )
              sde_encoder_kickoff(v84 - 1, 1);
            v84 = (_QWORD *)*v84;
          }
          if ( (v88 & 1) != 0 )
            result = 4294967285LL;
          else
            result = 0;
          goto LABEL_267;
        }
LABEL_98:
        if ( !a1[1002] )
          goto LABEL_175;
        v34 = 1;
        goto LABEL_100;
      }
      v11 = &unk_234896;
      v12 = "_sde_crtc_get_kms";
    }
    else
    {
      v11 = &unk_25E167;
      v12 = "sde_crtc_get_disp_op";
    }
    printk(v11, v12);
    goto LABEL_14;
  }
LABEL_267:
  _ReadStatusReg(SP_EL0);
  return result;
}
