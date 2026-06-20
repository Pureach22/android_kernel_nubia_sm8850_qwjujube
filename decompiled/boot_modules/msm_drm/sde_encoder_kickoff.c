__int64 __fastcall sde_encoder_kickoff(__int64 a1, __int64 a2)
{
  __int64 v2; // x26
  char v3; // w21
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned int disp_op; // w0
  _DWORD *v8; // x8
  __int64 result; // x0
  int v10; // w5
  void *v11; // x0
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x2
  __int64 v18; // x1
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x1
  int v23; // w7
  unsigned int v24; // w22
  __int64 v25; // x28
  int v26; // w6
  _BOOL4 v27; // w23
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x8
  unsigned __int64 v31; // x19
  unsigned __int64 v32; // x8
  __int64 v33; // x24
  __int64 v34; // x25
  __int64 (__fastcall *v35)(_QWORD); // x8
  void (__fastcall *v36)(__int64, int *); // x8
  void (__fastcall *v37)(__int64, _BOOL4); // x8
  void (*v38)(void); // x8
  unsigned __int64 i; // x23
  int v40; // w8
  __int64 v41; // x9
  __int64 v42; // x10
  __int64 v43; // x10
  __int64 v44; // x10
  int v45; // w4
  int v46; // w0
  void *v47; // x0
  void *v48; // x0
  __int64 v49; // x9
  __int64 v50; // x9
  __int64 v51; // x9
  int v52; // w5
  unsigned int v59; // w9
  __int64 v60; // x22
  __int64 (__fastcall *v61)(_QWORD); // x8
  __int64 v62; // x0
  int v65; // w6
  int v66; // w7
  unsigned int v68; // w4
  unsigned int v69; // w4
  unsigned int v71; // w4
  unsigned int v72; // w4
  __int64 v73; // x8
  __int64 v74; // x0
  unsigned int v75; // w0
  unsigned int (__fastcall *v76)(_QWORD); // x8
  __int64 v77; // x0
  __int64 v78; // x8
  __int64 v79; // x8
  unsigned int v80; // w8
  __int64 (*v81)(void); // x9
  __int64 (*v82)(void); // x9
  __int64 (*v83)(void); // x9
  __int64 (*v84)(void); // x9
  __int64 v85; // x8
  __int64 v86; // x8
  __int64 v87; // x8
  void (*v88)(void); // x8
  unsigned int v89; // w8
  __int64 v90; // x0
  void (*v91)(void); // x9
  __int64 v92; // x0
  void (*v93)(void); // x9
  __int64 v94; // x0
  void (*v95)(void); // x9
  __int64 v96; // x0
  void (*v97)(void); // x9
  void *v98; // x0
  char v99; // [xsp+0h] [xbp-70h]
  char v100; // [xsp+0h] [xbp-70h]
  _QWORD v101[2]; // [xsp+10h] [xbp-60h] BYREF
  __int64 v102; // [xsp+20h] [xbp-50h] BYREF
  int v103[2]; // [xsp+28h] [xbp-48h] BYREF
  __int64 v104; // [xsp+30h] [xbp-40h]
  __int64 v105; // [xsp+38h] [xbp-38h]
  __int64 v106; // [xsp+40h] [xbp-30h]
  __int64 v107; // [xsp+48h] [xbp-28h]
  __int64 v108; // [xsp+50h] [xbp-20h]
  __int64 v109; // [xsp+58h] [xbp-18h]
  __int64 v110; // [xsp+60h] [xbp-10h]
  __int64 v111; // [xsp+68h] [xbp-8h]

  v111 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = printk(&unk_26FCAB, "sde_encoder_kickoff");
    goto LABEL_235;
  }
  v3 = a2;
  _ReadStatusReg(SP_EL0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "enc%d \n", *(_DWORD *)(a1 + 24));
  if ( !*(_QWORD *)a1 )
  {
    v11 = &unk_26FCAB;
    goto LABEL_40;
  }
  v5 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v5 || (v6 = *(_QWORD *)(v5 + 8)) == 0 )
  {
    v11 = &unk_234896;
LABEL_40:
    printk(v11, "sde_encoder_get_kms");
    disp_op = 0;
    goto LABEL_8;
  }
  disp_op = sde_kms_get_disp_op(v6, a2);
  if ( disp_op >= 3 )
    goto LABEL_269;
LABEL_8:
  v8 = *(_DWORD **)(a1 + 8LL * disp_op + 5224);
  if ( v8 )
  {
    if ( *(v8 - 1) != 1783931719 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD))v8)(a1, v3 & 1);
    if ( (_DWORD)result )
      result = printk(&unk_22E100, "sde_encoder_kickoff");
    goto LABEL_235;
  }
  v2 = a1 + 4096;
  if ( *(_BYTE *)(a1 + 4920) == 1 )
  {
    usleep_range_state(5000, 10000, 2);
    if ( *(_BYTE *)(a1 + 4920) == 1 )
    {
      usleep_range_state(5000, 10000, 2);
      if ( *(_BYTE *)(a1 + 4920) == 1 )
      {
        usleep_range_state(5000, 10000, 2);
        v10 = 2;
        if ( *(_BYTE *)(a1 + 4920) == 1 )
        {
          usleep_range_state(5000, 10000, 2);
          if ( *(_BYTE *)(a1 + 4920) == 1 )
          {
            usleep_range_state(5000, 10000, 2);
            if ( *(_BYTE *)(a1 + 4920) == 1 )
            {
              usleep_range_state(5000, 10000, 2);
              if ( *(_BYTE *)(a1 + 4920) == 1 )
              {
                usleep_range_state(5000, 10000, 2);
                if ( *(_BYTE *)(a1 + 4920) == 1 )
                {
                  usleep_range_state(5000, 10000, 2);
                  if ( *(_BYTE *)(a1 + 4920) == 1 )
                  {
                    usleep_range_state(5000, 10000, 2);
                    if ( *(_BYTE *)(a1 + 4920) == 1 )
                    {
                      usleep_range_state(5000, 10000, 2);
                      if ( *(_BYTE *)(a1 + 4920) == 1 )
                      {
                        usleep_range_state(5000, 10000, 2);
                        if ( *(_BYTE *)(a1 + 4920) == 1 )
                        {
                          usleep_range_state(5000, 10000, 2);
                          if ( *(_BYTE *)(a1 + 4920) == 1 )
                          {
                            usleep_range_state(5000, 10000, 2);
                            if ( *(_BYTE *)(a1 + 4920) == 1 )
                            {
                              usleep_range_state(5000, 10000, 2);
                              if ( *(_BYTE *)(a1 + 4920) == 1 )
                              {
                                usleep_range_state(5000, 10000, 2);
                                if ( *(_BYTE *)(a1 + 4920) == 1 )
                                {
                                  usleep_range_state(5000, 10000, 2);
                                  if ( *(_BYTE *)(a1 + 4920) == 1 )
                                  {
                                    usleep_range_state(5000, 10000, 2);
                                    if ( *(_BYTE *)(a1 + 4920) == 1 )
                                    {
                                      usleep_range_state(5000, 10000, 2);
                                      if ( *(_BYTE *)(a1 + 4920) == 1 )
                                      {
                                        usleep_range_state(5000, 10000, 2);
                                        if ( *(_BYTE *)(a1 + 4920) == 1 )
                                        {
                                          usleep_range_state(5000, 10000, 2);
                                          if ( *(_BYTE *)(a1 + 4920) )
                                            v10 = 20;
                                          else
                                            v10 = 19;
                                        }
                                        else
                                        {
                                          v10 = 18;
                                        }
                                      }
                                      else
                                      {
                                        v10 = 17;
                                      }
                                    }
                                    else
                                    {
                                      v10 = 16;
                                    }
                                  }
                                  else
                                  {
                                    v10 = 15;
                                  }
                                }
                                else
                                {
                                  v10 = 14;
                                }
                              }
                              else
                              {
                                v10 = 13;
                              }
                            }
                            else
                            {
                              v10 = 12;
                            }
                          }
                          else
                          {
                            v10 = 11;
                          }
                        }
                        else
                        {
                          v10 = 10;
                        }
                      }
                      else
                      {
                        v10 = 9;
                      }
                    }
                    else
                    {
                      v10 = 8;
                    }
                  }
                  else
                  {
                    v10 = 7;
                  }
                }
                else
                {
                  v10 = 6;
                }
              }
              else
              {
                v10 = 5;
              }
            }
            else
            {
              v10 = 4;
            }
          }
          else
          {
            v10 = 3;
          }
        }
      }
      else
      {
        v10 = 1;
      }
    }
    else
    {
      v10 = 0;
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_kickoff",
      7129,
      -1,
      *(_DWORD *)(a1 + 24),
      v10,
      13107,
      -1059143953,
      v99);
  }
  if ( !*(_QWORD *)a1 )
  {
    v47 = &unk_26FCAB;
    goto LABEL_118;
  }
  v12 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 8)) == 0 )
  {
    v47 = &unk_234896;
LABEL_118:
    printk(v47, "sde_encoder_get_kms");
    result = printk(&unk_25E374, "sde_encoder_kickoff");
    goto LABEL_235;
  }
  v14 = *(_QWORD *)(a1 + 328);
  if ( v14 )
  {
    v15 = *(_QWORD *)(v14 + 8);
    if ( v15 )
    {
      v16 = *(_QWORD *)(v15 + 2512);
      if ( v16 )
        v17 = *(unsigned int *)(v16 + 1280);
      else
        v17 = 0;
      if ( *(_BYTE *)(v15 + 5120) == 1 )
        sde_fence_update_hw_fences_txq(*(_QWORD *)(v15 + 2864), 0, v17, *(unsigned int *)(v13 + 6400));
    }
    else
    {
      printk(&unk_21D6E4, "_sde_encoder_update_retire_txq");
    }
  }
  sde_connector_frame_handler(a1);
  sde_encoder_delay_kickoff_processing(a1);
  v19 = *(_QWORD *)a1;
  v109 = 0;
  v110 = 0;
  v107 = 0;
  v108 = 0;
  v105 = 0;
  v106 = 0;
  *(_QWORD *)v103 = 0;
  v104 = 0;
  v101[1] = 0;
  v102 = 0;
  v101[0] = 0;
  if ( v19 )
  {
    v20 = *(_QWORD *)(v19 + 56);
    if ( v20 )
    {
      v21 = *(_QWORD *)(v20 + 8);
      if ( v21 )
      {
        v24 = sde_kms_get_disp_op(v21, v18);
        v25 = *(_QWORD *)(a1 + 1360);
        if ( !v25 )
          goto LABEL_58;
        goto LABEL_57;
      }
    }
    v48 = &unk_234896;
  }
  else
  {
    v48 = &unk_26FCAB;
  }
  printk(v48, "sde_encoder_get_kms");
  v24 = 0;
  v25 = *(_QWORD *)(a1 + 1360);
  if ( !v25 )
  {
LABEL_58:
    if ( *(_DWORD *)(a1 + 648) == 1 )
    {
      v27 = 1;
    }
    else
    {
      v28 = *(_QWORD *)(a1 + 328);
      v27 = v28
         && (*(_BYTE *)(a1 + 644) & 2) != 0
         && (v29 = *(_QWORD *)(v28 + 8)) != 0
         && (v30 = *(_QWORD *)(v29 + 2512)) != 0
         && *(_QWORD *)(v30 + 1440) != 0;
    }
    if ( *(_DWORD *)(a1 + 196) )
    {
      v31 = 0;
      do
      {
        if ( v31 == 4 )
          goto LABEL_269;
        v33 = *(_QWORD *)(a1 + 8 * v31 + 200);
        if ( v33 )
        {
          if ( *(_DWORD *)(v33 + 832) != 1 )
          {
            v34 = *(_QWORD *)(v33 + 416);
            if ( v34 )
            {
              v35 = *(__int64 (__fastcall **)(_QWORD))(v33 + 192);
              if ( !v35 )
                goto LABEL_83;
              if ( *((_DWORD *)v35 - 1) != -1375811177 )
                __break(0x8228u);
              if ( (v35(v33) & 1) != 0 )
              {
                if ( v24 > 2 )
                  goto LABEL_269;
                v36 = *(void (__fastcall **)(__int64, int *))(v34 + 8LL * v24 + 712);
                if ( v36 )
                {
                  if ( *((_DWORD *)v36 - 1) != 1851168652 )
                    __break(0x8228u);
                  v36(v34, v103);
                }
              }
              else
              {
LABEL_83:
                if ( (v3 & 1) != 0 )
                {
                  if ( v24 > 2 )
                    goto LABEL_269;
                  v37 = *(void (__fastcall **)(__int64, _BOOL4))(v34 + 8LL * v24 + 1432);
                  if ( v37 )
                  {
                    if ( *((_DWORD *)v37 - 1) != 74273587 )
                      __break(0x8228u);
                    v37(v34, v27);
                  }
                }
                sde_encoder_trigger_flush(a1, v33, 0, v3 & 1);
              }
            }
          }
        }
        v32 = *(unsigned int *)(a1 + 196);
        ++v31;
      }
      while ( v31 < v32 );
    }
    else
    {
      v32 = 0;
    }
    if ( v103[0] )
    {
      v22 = *(_QWORD *)(a1 + 328);
      if ( v22 )
      {
        if ( (v3 & 1) != 0 )
        {
          if ( v24 > 2 )
            goto LABEL_269;
          v38 = *(void (**)(void))(*(_QWORD *)(v22 + 416) + 8LL * v24 + 1432);
          if ( v38 )
          {
            if ( *((_DWORD *)v38 - 1) != 74273587 )
              __break(0x8228u);
            v38();
            v22 = *(_QWORD *)(a1 + 328);
          }
        }
        sde_encoder_trigger_flush(a1, v22, v103, v3 & 1);
        v32 = *(unsigned int *)(a1 + 196);
      }
    }
    if ( v32 )
    {
      for ( i = 0; i < v32; ++i )
      {
        if ( i == 4 )
          goto LABEL_269;
        v60 = *(_QWORD *)(a1 + 200 + 8 * i);
        if ( v60 && *(_DWORD *)(v60 + 832) != 1 )
        {
          v61 = *(__int64 (__fastcall **)(_QWORD))(v60 + 192);
          if ( !v61 )
            goto LABEL_170;
          v62 = *(_QWORD *)(a1 + 200 + 8 * i);
          if ( *((_DWORD *)v61 - 1) != -1375811177 )
            __break(0x8228u);
          if ( (v61(v62) & 1) != 0 )
          {
            _X8 = (unsigned int *)(v60 + 876);
            __asm { PRFM            #0x11, [X8] }
            do
            {
              v71 = __ldxr(_X8);
              v72 = v71 + 1;
            }
            while ( __stlxr(v72, _X8) );
            __dmb(0xBu);
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "_sde_encoder_kickoff_phys",
              5563,
              -1,
              v72,
              v103[0],
              17476,
              -1059143953,
              v99);
          }
          else
          {
LABEL_170:
            _X8 = (unsigned int *)(v60 + 876);
            __asm { PRFM            #0x11, [X8] }
            do
            {
              v68 = __ldxr(_X8);
              v69 = v68 + 1;
            }
            while ( __stlxr(v69, _X8) );
            __dmb(0xBu);
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "_sde_encoder_kickoff_phys",
              5558,
              -1,
              v69,
              13107,
              -1059143953,
              v23,
              v99);
          }
          _X8 = (unsigned int *)(v60 + 888);
          __asm { PRFM            #0x11, [X8] }
          do
            v59 = __ldxr(_X8);
          while ( __stlxr(v59 + 1, _X8) );
          __dmb(0xBu);
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_encoder_kickoff_phys",
            5567,
            -1,
            *(_DWORD *)(v60 + 888),
            -1059143953,
            v65,
            v66,
            v100);
          v32 = *(unsigned int *)(a1 + 196);
        }
      }
    }
    if ( !*(_DWORD *)(a1 + 800) || *(_BYTE *)(a1 + 808) != 1 )
      goto LABEL_187;
    if ( *(_QWORD *)a1 )
    {
      v73 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
      if ( v73 )
      {
        v74 = *(_QWORD *)(v73 + 8);
        if ( v74 )
        {
          v75 = sde_kms_get_disp_op(v74, v22);
          if ( v75 >= 3 )
            goto LABEL_269;
          goto LABEL_181;
        }
      }
      v98 = &unk_234896;
    }
    else
    {
      v98 = &unk_26FCAB;
    }
    printk(v98, "sde_encoder_get_kms");
    v75 = 0;
LABEL_181:
    v76 = *(unsigned int (__fastcall **)(_QWORD))(a1 + 8LL * v75 + 5296);
    if ( v76 )
    {
      if ( *((_DWORD *)v76 - 1) != 17023570 )
        __break(0x8228u);
      if ( v76(a1) )
        printk(&unk_2700D8, "sde_encoder_misr_configure");
    }
    else
    {
      v89 = *(_DWORD *)(a1 + 196);
      if ( v89 )
      {
        v90 = *(_QWORD *)(a1 + 200);
        if ( v90 )
        {
          v91 = *(void (**)(void))(v90 + 200);
          if ( v91 )
          {
            if ( *((_DWORD *)v91 - 1) != -1300760371 )
              __break(0x8229u);
            v91();
            v89 = *(_DWORD *)(a1 + 196);
          }
        }
        if ( v89 >= 2 )
        {
          v92 = *(_QWORD *)(a1 + 208);
          if ( v92 )
          {
            v93 = *(void (**)(void))(v92 + 200);
            if ( v93 )
            {
              if ( *((_DWORD *)v93 - 1) != -1300760371 )
                __break(0x8229u);
              v93();
              v89 = *(_DWORD *)(a1 + 196);
            }
          }
          if ( v89 >= 3 )
          {
            v94 = *(_QWORD *)(a1 + 216);
            if ( v94 )
            {
              v95 = *(void (**)(void))(v94 + 200);
              if ( v95 )
              {
                if ( *((_DWORD *)v95 - 1) != -1300760371 )
                  __break(0x8229u);
                v95();
                v89 = *(_DWORD *)(a1 + 196);
              }
            }
            if ( v89 >= 4 )
            {
              v96 = *(_QWORD *)(a1 + 224);
              if ( v96 )
              {
                v97 = *(void (**)(void))(v96 + 200);
                if ( v97 )
                {
                  if ( *((_DWORD *)v97 - 1) != -1300760371 )
                    __break(0x8229u);
                  v97();
                  v89 = *(_DWORD *)(a1 + 196);
                }
              }
              if ( v89 > 4 )
                goto LABEL_269;
            }
          }
        }
      }
    }
    *(_BYTE *)(a1 + 808) = 0;
LABEL_187:
    sde_crtc_get_misr_info(*(_QWORD *)(a1 + 1360), (__int64)&v102);
    if ( v25 && (v102 & 1) != 0 && *(_BYTE *)(v25 + 7358) == 1 )
    {
      sde_crtc_misr_setup(*(_QWORD *)(a1 + 1360), 1, SHIDWORD(v102));
      *(_BYTE *)(v25 + 7358) = 0;
    }
    v77 = *(_QWORD *)(a1 + 328);
    if ( v77 )
    {
      v78 = *(_QWORD *)(v77 + 496);
      if ( v78 )
      {
        if ( *(_QWORD *)v77 )
        {
          if ( (*(_BYTE *)(v77 + 2290) & 1) == 0 )
          {
            if ( *(_DWORD *)(v77 + 664) == 4 )
            {
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "enc%d skip start pp%d ctl%d\n",
                  *(_DWORD *)(*(_QWORD *)v77 + 24LL),
                  *(_DWORD *)(v78 + 32) - 1,
                  *(_DWORD *)(*(_QWORD *)(v77 + 416) + 64LL) - 1);
            }
            else
            {
              v88 = *(void (**)(void))(v77 + 176);
              if ( v88 && *(_DWORD *)(v77 + 832) != 1 )
              {
                if ( *((_DWORD *)v88 - 1) != -511414616 )
                  __break(0x8228u);
                v88();
              }
            }
          }
        }
        else
        {
          printk(&unk_238493, "_sde_encoder_trigger_start");
        }
      }
      else
      {
        printk(&unk_2198A7, "_sde_encoder_trigger_start");
      }
    }
    else
    {
      printk(&unk_253460, "_sde_encoder_trigger_start");
    }
    result = *(_QWORD *)(a1 + 4960);
    if ( result )
      result = sde_cesta_get_status(result, v101);
    goto LABEL_197;
  }
LABEL_57:
  v26 = *(_DWORD *)(v25 + 7940);
  if ( (v26 & 0x80000000) == 0 )
    goto LABEL_58;
  v40 = *(_DWORD *)(a1 + 196);
  if ( v40 )
  {
    v41 = *(_QWORD *)(a1 + 200);
    if ( v41 && (*(_BYTE *)(v41 + 2290) & 1) != 0 )
      goto LABEL_113;
    if ( v40 == 1 )
      goto LABEL_128;
    v42 = *(_QWORD *)(a1 + 208);
    if ( v42 )
    {
      if ( (*(_BYTE *)(v42 + 2290) & 1) != 0 )
        goto LABEL_113;
    }
    if ( v40 == 2 )
      goto LABEL_128;
    v43 = *(_QWORD *)(a1 + 216);
    if ( v43 )
    {
      if ( (*(_BYTE *)(v43 + 2290) & 1) != 0 )
      {
LABEL_113:
        v45 = *(_DWORD *)(a1 + 24);
        v46 = sde_dbg_base_evtlog;
        if ( !v41 )
          goto LABEL_131;
        goto LABEL_130;
      }
    }
    if ( v40 != 3 )
    {
      v44 = *(_QWORD *)(a1 + 224);
      if ( v44 && (*(_BYTE *)(v44 + 2290) & 1) != 0 )
        goto LABEL_113;
      if ( v40 != 4 )
        goto LABEL_269;
    }
  }
LABEL_128:
  *(_DWORD *)(v25 + 7940) = 0;
  v40 = *(_DWORD *)(a1 + 196);
  v46 = sde_dbg_base_evtlog;
  v45 = *(_DWORD *)(a1 + 24);
  if ( !v40 )
  {
    v26 = 0;
    goto LABEL_142;
  }
  v41 = *(_QWORD *)(a1 + 200);
  v26 = 0;
  if ( !v41 )
  {
LABEL_131:
    if ( v40 != 1 )
    {
      v49 = *(_QWORD *)(a1 + 208);
      if ( v49 && (*(_BYTE *)(v49 + 2290) & 1) != 0 )
        goto LABEL_140;
      if ( v40 != 2 )
      {
        v50 = *(_QWORD *)(a1 + 216);
        if ( v50 && (*(_BYTE *)(v50 + 2290) & 1) != 0 )
          goto LABEL_140;
        if ( v40 != 3 )
        {
          v51 = *(_QWORD *)(a1 + 224);
          if ( v51 && (*(_BYTE *)(v51 + 2290) & 1) != 0 )
            goto LABEL_140;
          if ( v40 != 4 )
            goto LABEL_269;
        }
      }
    }
LABEL_142:
    v52 = 0;
    goto LABEL_143;
  }
LABEL_130:
  if ( (*(_BYTE *)(v41 + 2290) & 1) == 0 )
    goto LABEL_131;
LABEL_140:
  v52 = 1;
LABEL_143:
  result = sde_evtlog_log(v46, "_sde_encoder_kickoff_phys", 5499, -1, v45, v52, v26, -1059143953, v99);
LABEL_197:
  if ( *(_BYTE *)(a1 + 1370) != 1 )
    goto LABEL_203;
  if ( *(_QWORD *)a1 )
  {
    v79 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
    if ( !v79 || !*(_QWORD *)(v79 + 8) )
      goto LABEL_270;
    result = sde_power_scale_reg_bus(v79 + 16, 1, 0);
  }
  else
  {
    result = printk(&unk_26FCAB, "sde_encoder_get_kms");
  }
  while ( 1 )
  {
    *(_BYTE *)(a1 + 1370) = 0;
LABEL_203:
    v80 = *(_DWORD *)(a1 + 196);
    if ( !v80 )
      break;
    result = *(_QWORD *)(a1 + 200);
    if ( result )
    {
      v81 = *(__int64 (**)(void))(result + 160);
      if ( v81 )
      {
        if ( *((_DWORD *)v81 - 1) != -511414616 )
          __break(0x8229u);
        result = v81();
        v80 = *(_DWORD *)(a1 + 196);
      }
    }
    if ( v80 < 2 )
      break;
    result = *(_QWORD *)(a1 + 208);
    if ( result )
    {
      v82 = *(__int64 (**)(void))(result + 160);
      if ( v82 )
      {
        if ( *((_DWORD *)v82 - 1) != -511414616 )
          __break(0x8229u);
        result = v82();
        v80 = *(_DWORD *)(a1 + 196);
      }
    }
    if ( v80 < 3 )
      break;
    result = *(_QWORD *)(a1 + 216);
    if ( result )
    {
      v83 = *(__int64 (**)(void))(result + 160);
      if ( v83 )
      {
        if ( *((_DWORD *)v83 - 1) != -511414616 )
          __break(0x8229u);
        result = v83();
        v80 = *(_DWORD *)(a1 + 196);
      }
    }
    if ( v80 < 4 )
      break;
    result = *(_QWORD *)(a1 + 224);
    if ( result )
    {
      v84 = *(__int64 (**)(void))(result + 160);
      if ( v84 )
      {
        if ( *((_DWORD *)v84 - 1) != -511414616 )
          __break(0x8229u);
        result = v84();
        v80 = *(_DWORD *)(a1 + 196);
      }
    }
    if ( v80 <= 4 )
      break;
LABEL_269:
    __break(0x5512u);
LABEL_270:
    result = printk(&unk_234896, "sde_encoder_get_kms");
  }
  if ( *(_BYTE *)(v2 + 825) == 1 )
  {
    v85 = *(_QWORD *)(a1 + 328);
    if ( !v85
      || (*(_BYTE *)(a1 + 644) & 2) == 0
      || (v86 = *(_QWORD *)(v85 + 8)) == 0
      || (v87 = *(_QWORD *)(v86 + 2512)) == 0
      || !*(_QWORD *)(v87 + 1440) )
    {
      result = ((__int64 (__fastcall *)(__int64, __int64))sde_encoder_update_rsc_client)(a1, 1);
    }
  }
LABEL_235:
  _ReadStatusReg(SP_EL0);
  return result;
}
