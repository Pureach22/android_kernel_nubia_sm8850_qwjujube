__int64 __fastcall _power_on_iris4(__int64 a1)
{
  __int64 result; // x0
  _QWORD *v3; // x8
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // x9
  unsigned int v5; // w0
  unsigned int v6; // w20
  __int64 (__fastcall *v7)(__int64, const char *); // x9
  unsigned int v8; // w0
  __int64 (__fastcall *v9)(__int64, const char *); // x9
  void (__fastcall *v10)(__int64, const char *); // x8
  unsigned int v11; // w20
  __int64 (__fastcall *v12)(__int64, const char *); // x9
  void (__fastcall *v13)(__int64, const char *); // x9
  unsigned int v14; // w20
  __int64 (__fastcall *v15)(__int64, const char *); // x9
  void (__fastcall *v16)(__int64, const char *); // x9
  unsigned int v17; // w20
  unsigned int v18; // w0
  __int64 v19; // x8
  void (__fastcall *v20)(__int64, const char *); // x8
  unsigned int v21; // w20
  __int64 v22; // x8
  unsigned int v23; // w23
  __int64 v24; // x25
  bool v25; // w22
  int v26; // w24
  __int64 v27; // x26
  __int64 v28; // x8
  __int64 (__fastcall *v29)(__int64, const char *); // x8
  __int64 v30; // x22
  unsigned int v31; // w24
  __int64 v32; // x26
  bool v33; // w23
  int v34; // w25
  __int64 v35; // x27
  __int64 v36; // x8
  __int64 (__fastcall *v37)(__int64, const char *); // x8
  __int64 (__fastcall *v38)(__int64, const char *); // x8
  __int64 v39; // x8
  __int64 (__fastcall *v40)(_QWORD); // x9
  __int64 (__fastcall *v41)(__int64, const char *); // x8
  __int64 v42; // x8
  __int64 (__fastcall *v43)(__int64, const char *); // x8
  __int64 v44; // x8
  __int64 (__fastcall *v45)(__int64, const char *); // x8
  __int64 v46; // x8
  __int64 (__fastcall *v47)(__int64, const char *); // x8
  __int64 v48; // x8
  __int64 (__fastcall *v49)(__int64, const char *); // x8
  __int64 v50; // x8
  __int64 (__fastcall *v51)(__int64, const char *); // x8
  unsigned int v52; // w0
  unsigned int v53; // w20
  __int64 v54; // x8
  void (__fastcall *v55)(__int64, const char *); // x8
  __int64 v56; // x8
  void (__fastcall *v57)(__int64, const char *); // x8
  unsigned int v58; // w20
  __int64 v59; // x8
  void (__fastcall *v60)(__int64, const char *); // x8
  unsigned int v61; // w20
  __int64 v62; // x8
  void (__fastcall *v63)(__int64, const char *); // x8
  unsigned int v64; // w20
  __int64 v65; // x8
  void (__fastcall *v66)(__int64, const char *); // x8
  unsigned int v67; // w20
  __int64 v68; // x23
  unsigned int v69; // w25
  __int64 v70; // x27
  unsigned int v71; // w22
  bool v72; // w24
  int v73; // w26
  __int64 v74; // x28
  unsigned int v75; // w0
  __int64 v76; // x8
  _DWORD *v77; // x8
  __int64 v78; // x8
  unsigned int (__fastcall *v79)(__int64, __int64); // x8
  __int64 v80; // x1
  __int64 v81; // x8
  __int64 v82; // x8
  void (__fastcall *v83)(__int64, const char *); // x8
  unsigned int v84; // w20
  __int64 v85; // x8
  unsigned int v86; // w24
  __int64 v87; // x26
  unsigned int v88; // w22
  bool v89; // w23
  int v90; // w25
  __int64 v91; // x27
  __int64 v92; // x8
  void (__fastcall *v93)(__int64, const char *); // x8
  unsigned int v94; // w20
  int v95; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v96; // [xsp+8h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (is_core_sub_state(a1, 1) & 1) != 0 )
  {
LABEL_2:
    result = 0;
    goto LABEL_198;
  }
  if ( (core_in_valid_state(a1) & 1) != 0 )
  {
    if ( a1 )
    {
      v3 = *(_QWORD **)(a1 + 6552);
      if ( v3 )
      {
        v4 = (__int64 (__fastcall *)(__int64, __int64, __int64))v3[12];
        if ( !v4 )
          goto LABEL_16;
        if ( *((_DWORD *)v4 - 1) != -219393110 )
          __break(0x8229u);
        v5 = v4(a1, 0x7FFFFFFF, 0x7FFFFFFF);
        if ( v5 )
        {
          v6 = v5;
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_80132, "err ", 0xFFFFFFFFLL, "codec", "__power_on_iris4");
          goto LABEL_197;
        }
        v3 = *(_QWORD **)(a1 + 6552);
        if ( v3 )
        {
LABEL_16:
          v7 = (__int64 (__fastcall *)(__int64, const char *))v3[7];
          if ( !v7 )
            goto LABEL_23;
          if ( *((_DWORD *)v7 - 1) != 841426229 )
            __break(0x8229u);
          v8 = v7(a1, "iris-ctl");
          if ( v8 )
            goto LABEL_20;
          v3 = *(_QWORD **)(a1 + 6552);
          if ( v3 )
          {
LABEL_23:
            v9 = (__int64 (__fastcall *)(__int64, const char *))v3[15];
            if ( !v9 )
              goto LABEL_95;
            if ( *((_DWORD *)v9 - 1) != 841426229 )
              __break(0x8229u);
            v8 = v9(a1, "gcc_video_axi1_clk");
            v3 = *(_QWORD **)(a1 + 6552);
            if ( v8 )
            {
              if ( v3 )
                goto LABEL_28;
LABEL_20:
              v6 = v8;
              if ( (msm_vidc_debug & 1) != 0 )
                printk(&unk_88BEA, "err ", 0xFFFFFFFFLL, "codec", "__power_on_iris4");
              goto LABEL_192;
            }
            if ( v3 )
            {
              v12 = (__int64 (__fastcall *)(__int64, const char *))v3[15];
              if ( !v12 )
                goto LABEL_95;
              if ( *((_DWORD *)v12 - 1) != 841426229 )
                __break(0x8229u);
              v8 = v12(a1, "video_cc_mvs0c_freerun_clk");
              v3 = *(_QWORD **)(a1 + 6552);
              if ( v8 )
              {
                if ( !v3 )
                  goto LABEL_20;
                goto LABEL_38;
              }
              if ( v3 )
              {
                v15 = (__int64 (__fastcall *)(__int64, const char *))v3[15];
                if ( v15 )
                {
                  if ( *((_DWORD *)v15 - 1) != 841426229 )
                    __break(0x8229u);
                  v8 = v15(a1, "video_cc_mvs0c_clk");
                  v3 = *(_QWORD **)(a1 + 6552);
                  if ( v8 )
                  {
                    if ( !v3 )
                      goto LABEL_20;
                    v16 = (void (__fastcall *)(__int64, const char *))v3[14];
                    v17 = v8;
                    if ( !v16 )
                    {
LABEL_28:
                      v10 = (void (__fastcall *)(__int64, const char *))v3[8];
                      if ( v10 )
                      {
                        v11 = v8;
                        if ( *((_DWORD *)v10 - 1) != 841426229 )
                          __break(0x8228u);
                        v10(a1, "iris-ctl");
                        v8 = v11;
                      }
                      goto LABEL_20;
                    }
                    if ( *((_DWORD *)v16 - 1) != 841426229 )
                      __break(0x8229u);
                    v16(a1, "video_cc_mvs0c_freerun_clk");
                    v3 = *(_QWORD **)(a1 + 6552);
                    v8 = v17;
                    if ( !v3 )
                      goto LABEL_20;
LABEL_38:
                    v13 = (void (__fastcall *)(__int64, const char *))v3[14];
                    if ( v13 )
                    {
                      v14 = v8;
                      if ( *((_DWORD *)v13 - 1) != 841426229 )
                        __break(0x8229u);
                      v13(a1, "gcc_video_axi1_clk");
                      v3 = *(_QWORD **)(a1 + 6552);
                      v8 = v14;
                      if ( !v3 )
                        goto LABEL_20;
                    }
                    goto LABEL_28;
                  }
                  v95 = 0;
                  if ( !v3 )
                    goto LABEL_55;
                  goto LABEL_96;
                }
LABEL_95:
                v95 = 0;
LABEL_96:
                v38 = (__int64 (__fastcall *)(__int64, const char *))v3[7];
                if ( v38 )
                {
                  if ( *((_DWORD *)v38 - 1) != 841426229 )
                    __break(0x8228u);
                  v18 = v38(a1, "vcodec");
                  if ( v18 )
                    goto LABEL_63;
                }
LABEL_55:
                v18 = msm_vidc_change_core_sub_state(a1, 0, 1, "__power_on_iris4_hardware");
                if ( v18 )
                  goto LABEL_57;
                v18 = _read_register(a1, 0xB0008u, &v95);
                if ( v18 )
                  goto LABEL_57;
                v22 = *(_QWORD *)(a1 + 3912);
                v23 = *(_DWORD *)(v22 + 40);
                if ( v23 )
                {
                  v24 = *(_QWORD *)(v22 + 32);
                  v25 = 0;
                  v26 = 0;
                  while ( 1 )
                  {
                    v27 = v24 + 16LL * v26;
                    if ( !strcmp(*(const char **)v27, "vpp0") && (*(_BYTE *)(v27 + 9) & 1) == 0 )
                      break;
                    v25 = ++v26 >= v23;
                    if ( v23 == v26 )
                      goto LABEL_71;
                  }
                  if ( (msm_vidc_debug & 2) != 0 )
                  {
                    printk(&unk_8C79B, "high", 0xFFFFFFFFLL, "codec", "is_hw_enabled");
                    if ( !v25 )
                      goto LABEL_79;
                  }
                  else
                  {
LABEL_71:
                    if ( !v25 )
                      goto LABEL_79;
                  }
                }
                if ( a1 )
                {
                  if ( (v95 & 0x20000000) == 0 )
                  {
                    v28 = *(_QWORD *)(a1 + 6552);
                    if ( v28 )
                    {
                      v29 = *(__int64 (__fastcall **)(__int64, const char *))(v28 + 56);
                      if ( v29 )
                      {
                        if ( *((_DWORD *)v29 - 1) != 841426229 )
                          __break(0x8228u);
                        v18 = v29(a1, "vpp0");
                        if ( v18 )
                          goto LABEL_58;
                      }
                    }
                  }
                }
LABEL_79:
                v30 = *(_QWORD *)(a1 + 3912);
                v31 = *(_DWORD *)(v30 + 40);
                if ( v31 )
                {
                  v32 = *(_QWORD *)(v30 + 32);
                  v33 = 0;
                  v34 = 0;
                  while ( 1 )
                  {
                    v35 = v32 + 16LL * v34;
                    if ( !strcmp(*(const char **)v35, "vpp1") && (*(_BYTE *)(v35 + 9) & 1) == 0 )
                      break;
                    v33 = ++v34 >= v31;
                    if ( v31 == v34 )
                      goto LABEL_85;
                  }
                  if ( (msm_vidc_debug & 2) != 0 )
                  {
                    printk(&unk_8C79B, "high", 0xFFFFFFFFLL, "codec", "is_hw_enabled");
                    if ( !v33 )
                      goto LABEL_105;
                    v30 = *(_QWORD *)(a1 + 3912);
                  }
                  else
                  {
LABEL_85:
                    if ( !v33 )
                      goto LABEL_105;
                  }
                }
                if ( *(_DWORD *)(v30 + 328) != 4 || (v95 & 0x10000000) == 0 )
                {
                  if ( !a1 )
                    goto LABEL_131;
                  v36 = *(_QWORD *)(a1 + 6552);
                  if ( v36 )
                  {
                    v37 = *(__int64 (__fastcall **)(__int64, const char *))(v36 + 56);
                    if ( v37 )
                    {
                      if ( *((_DWORD *)v37 - 1) != 841426229 )
                        __break(0x8228u);
                      v18 = v37(a1, "vpp1");
                      if ( v18 )
                      {
LABEL_220:
                        v85 = *(_QWORD *)(a1 + 3912);
                        v86 = *(_DWORD *)(v85 + 40);
                        if ( v86 )
                        {
                          v87 = *(_QWORD *)(v85 + 32);
                          v88 = v18;
                          v89 = 0;
                          v90 = 0;
                          while ( 1 )
                          {
                            v91 = v87 + 16LL * v90;
                            if ( !strcmp(*(const char **)v91, "vpp0") && (*(_BYTE *)(v91 + 9) & 1) == 0 )
                              break;
                            v89 = ++v90 >= v86;
                            if ( v86 == v90 )
                              goto LABEL_226;
                          }
                          if ( (msm_vidc_debug & 2) == 0 )
                          {
LABEL_226:
                            v18 = v88;
                            if ( !v89 )
                              goto LABEL_57;
                            goto LABEL_227;
                          }
                          printk(&unk_8C79B, "high", 0xFFFFFFFFLL, "codec", "is_hw_enabled");
                          v18 = v88;
                          if ( !v89 )
                            goto LABEL_57;
                        }
LABEL_227:
                        if ( (v95 & 0x20000000) == 0 )
                        {
                          v92 = *(_QWORD *)(a1 + 6552);
                          if ( v92 )
                          {
                            v93 = *(void (__fastcall **)(__int64, const char *))(v92 + 64);
                            if ( v93 )
                            {
                              v94 = v18;
                              if ( *((_DWORD *)v93 - 1) != 841426229 )
                                __break(0x8228u);
                              v93(a1, "vpp0");
                              v18 = v94;
                            }
                          }
                          goto LABEL_58;
                        }
LABEL_57:
                        if ( !a1 )
                        {
LABEL_63:
                          v6 = v18;
                          if ( (msm_vidc_debug & 1) != 0 )
                            printk(&unk_96A1D, "err ", 0xFFFFFFFFLL, "codec", "__power_on_iris4");
                          goto LABEL_191;
                        }
LABEL_58:
                        v19 = *(_QWORD *)(a1 + 6552);
                        if ( v19 )
                        {
                          v20 = *(void (__fastcall **)(__int64, const char *))(v19 + 64);
                          if ( v20 )
                          {
                            v21 = v18;
                            if ( *((_DWORD *)v20 - 1) != 841426229 )
                              __break(0x8228u);
                            v20(a1, "vcodec");
                            v18 = v21;
                          }
                        }
                        goto LABEL_63;
                      }
                    }
                  }
                  goto LABEL_106;
                }
LABEL_105:
                if ( !a1 )
                  goto LABEL_131;
LABEL_106:
                v39 = *(_QWORD *)(a1 + 6552);
                if ( !v39 )
                  goto LABEL_131;
                v40 = *(__int64 (__fastcall **)(_QWORD))(v39 + 80);
                if ( v40 )
                {
                  if ( *((_DWORD *)v40 - 1) != -1850880742 )
                    __break(0x8229u);
                  v18 = v40(a1);
                  if ( v18 )
                    goto LABEL_178;
                  v39 = *(_QWORD *)(a1 + 6552);
                  if ( !v39 )
                    goto LABEL_131;
                }
                v41 = *(__int64 (__fastcall **)(__int64, const char *))(v39 + 120);
                if ( !v41 )
                  goto LABEL_131;
                if ( *((_DWORD *)v41 - 1) != 841426229 )
                  __break(0x8228u);
                v18 = v41(a1, "gcc_video_axi0_clk");
                if ( !v18 )
                {
                  v42 = *(_QWORD *)(a1 + 6552);
                  if ( v42 )
                  {
                    v43 = *(__int64 (__fastcall **)(__int64, const char *))(v42 + 120);
                    if ( v43 )
                    {
                      if ( *((_DWORD *)v43 - 1) != 841426229 )
                        __break(0x8228u);
                      v18 = v43(a1, "video_cc_mvs0_freerun_clk");
                      if ( v18 )
                        goto LABEL_173;
                      v44 = *(_QWORD *)(a1 + 6552);
                      if ( v44 )
                      {
                        v45 = *(__int64 (__fastcall **)(__int64, const char *))(v44 + 120);
                        if ( v45 )
                        {
                          if ( *((_DWORD *)v45 - 1) != 841426229 )
                            __break(0x8228u);
                          v18 = v45(a1, "video_cc_mvs0_clk");
                          if ( v18 )
                            goto LABEL_168;
                          v46 = *(_QWORD *)(a1 + 6552);
                          if ( v46 )
                          {
                            v47 = *(__int64 (__fastcall **)(__int64, const char *))(v46 + 120);
                            if ( v47 )
                            {
                              if ( *((_DWORD *)v47 - 1) != 841426229 )
                                __break(0x8228u);
                              v18 = v47(a1, "video_cc_mvs0b_clk");
                              if ( v18 )
                              {
LABEL_163:
                                v59 = *(_QWORD *)(a1 + 6552);
                                if ( v59 )
                                {
                                  v60 = *(void (__fastcall **)(__int64, const char *))(v59 + 112);
                                  if ( v60 )
                                  {
                                    v61 = v18;
                                    if ( *((_DWORD *)v60 - 1) != 841426229 )
                                      __break(0x8228u);
                                    v60(a1, "video_cc_mvs0_clk");
                                    v18 = v61;
                                  }
                                }
LABEL_168:
                                v62 = *(_QWORD *)(a1 + 6552);
                                if ( v62 )
                                {
                                  v63 = *(void (__fastcall **)(__int64, const char *))(v62 + 112);
                                  if ( v63 )
                                  {
                                    v64 = v18;
                                    if ( *((_DWORD *)v63 - 1) != 841426229 )
                                      __break(0x8228u);
                                    v63(a1, "video_cc_mvs0_freerun_clk");
                                    v18 = v64;
                                  }
                                }
LABEL_173:
                                v65 = *(_QWORD *)(a1 + 6552);
                                if ( v65 )
                                {
                                  v66 = *(void (__fastcall **)(__int64, const char *))(v65 + 112);
                                  if ( v66 )
                                  {
                                    v67 = v18;
                                    if ( *((_DWORD *)v66 - 1) != 841426229 )
                                      __break(0x8228u);
                                    v66(a1, "gcc_video_axi0_clk");
                                    v18 = v67;
                                  }
                                }
                                goto LABEL_178;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
LABEL_131:
                  if ( (is_hw_enabled(a1, "vpp0") & 1) != 0 )
                  {
                    if ( a1 )
                    {
                      if ( (v95 & 0x20000000) == 0 )
                      {
                        v48 = *(_QWORD *)(a1 + 6552);
                        if ( v48 )
                        {
                          v49 = *(__int64 (__fastcall **)(__int64, const char *))(v48 + 120);
                          if ( v49 )
                          {
                            if ( *((_DWORD *)v49 - 1) != 841426229 )
                              __break(0x8228u);
                            v18 = v49(a1, "video_cc_mvs0_vpp0_clk");
                            if ( v18 )
                              goto LABEL_158;
                          }
                        }
                      }
                    }
                  }
                  if ( (is_hw_enabled(a1, "vpp1") & 1) != 0 )
                  {
                    if ( *(_DWORD *)(*(_QWORD *)(a1 + 3912) + 328LL) == 4 )
                    {
                      if ( !a1 || (v95 & 0x10000000) != 0 )
                        goto LABEL_187;
LABEL_145:
                      v50 = *(_QWORD *)(a1 + 6552);
                      if ( !v50 )
                        goto LABEL_187;
                      v51 = *(__int64 (__fastcall **)(__int64, const char *))(v50 + 120);
                      if ( !v51 )
                        goto LABEL_187;
                      if ( *((_DWORD *)v51 - 1) != 841426229 )
                        __break(0x8228u);
                      v52 = v51(a1, "video_cc_mvs0_vpp1_clk");
                      if ( !v52 )
                        goto LABEL_187;
                      v53 = v52;
                      if ( (is_hw_enabled(a1, "vpp0") & 1) != 0 )
                      {
                        v18 = v53;
                        if ( (v95 & 0x20000000) != 0 || (v54 = *(_QWORD *)(a1 + 6552)) == 0 )
                        {
LABEL_158:
                          v56 = *(_QWORD *)(a1 + 6552);
                          if ( v56 )
                          {
                            v57 = *(void (__fastcall **)(__int64, const char *))(v56 + 112);
                            if ( v57 )
                            {
                              v58 = v18;
                              if ( *((_DWORD *)v57 - 1) != 841426229 )
                                __break(0x8228u);
                              v57(a1, "video_cc_mvs0b_clk");
                              v18 = v58;
                            }
                          }
                          goto LABEL_163;
                        }
                        v55 = *(void (__fastcall **)(__int64, const char *))(v54 + 112);
                        if ( v55 )
                        {
                          if ( *((_DWORD *)v55 - 1) != 841426229 )
                            __break(0x8228u);
                          v55(a1, "video_cc_mvs0_vpp0_clk");
                        }
                      }
                      v18 = v53;
                      goto LABEL_158;
                    }
                    if ( a1 )
                      goto LABEL_145;
                  }
LABEL_187:
                  v75 = _power_on_iris4_apv(a1);
                  if ( !v75 )
                  {
                    if ( a1 )
                    {
                      v78 = *(_QWORD *)(a1 + 6552);
                      if ( v78 )
                      {
                        v79 = *(unsigned int (__fastcall **)(__int64, __int64))(v78 + 104);
                        if ( v79 )
                        {
                          v80 = *(unsigned int *)(a1 + 6408);
                          if ( *((_DWORD *)v79 - 1) != -1742341011 )
                            __break(0x8228u);
                          if ( v79(a1, v80) && (msm_vidc_debug & 1) != 0 )
                            printk(&unk_831E8, "err ", 0xFFFFFFFFLL, "codec", "__power_on_iris4");
                        }
                      }
                    }
                    _set_registers(a1);
                    _interrupt_init_iris4(a1);
                    v81 = *(_QWORD *)(a1 + 3904);
                    *(_DWORD *)(a1 + 3920) = 0;
                    enable_irq(*(unsigned int *)(v81 + 8));
                    goto LABEL_2;
                  }
                  v6 = v75;
                  if ( (msm_vidc_debug & 1) != 0 )
                    printk(&unk_97577, "err ", 0xFFFFFFFFLL, "codec", "__power_on_iris4");
                  _power_off_iris4_hardware(a1);
LABEL_191:
                  _power_off_iris4_controller(a1);
                  if ( !a1 )
                  {
LABEL_197:
                    msm_vidc_change_core_sub_state(a1, 1, 0, "__power_on_iris4");
                    result = v6;
                    goto LABEL_198;
                  }
LABEL_192:
                  v76 = *(_QWORD *)(a1 + 6552);
                  if ( v76 )
                  {
                    v77 = *(_DWORD **)(v76 + 96);
                    if ( v77 )
                    {
                      if ( *(v77 - 1) != -219393110 )
                        __break(0x8228u);
                      ((void (__fastcall *)(__int64, _QWORD, _QWORD))v77)(a1, 0, 0);
                    }
                  }
                  goto LABEL_197;
                }
LABEL_178:
                v68 = *(_QWORD *)(a1 + 3912);
                v69 = *(_DWORD *)(v68 + 40);
                if ( !v69 )
                {
                  if ( *(_DWORD *)(v68 + 328) == 4 )
                  {
LABEL_209:
                    if ( (v95 & 0x10000000) != 0 )
                      goto LABEL_220;
                  }
                  goto LABEL_210;
                }
                v70 = *(_QWORD *)(v68 + 32);
                v71 = v18;
                v72 = 0;
                v73 = 0;
                while ( 1 )
                {
                  v74 = v70 + 16LL * v73;
                  if ( !strcmp(*(const char **)v74, "vpp1") && (*(_BYTE *)(v74 + 9) & 1) == 0 )
                    break;
                  v72 = ++v73 >= v69;
                  if ( v69 == v73 )
                    goto LABEL_184;
                }
                if ( (msm_vidc_debug & 2) != 0 )
                {
                  printk(&unk_8C79B, "high", 0xFFFFFFFFLL, "codec", "is_hw_enabled");
                  if ( v72 )
                  {
                    v68 = *(_QWORD *)(a1 + 3912);
LABEL_185:
                    v18 = v71;
                    if ( *(_DWORD *)(v68 + 328) == 4 )
                      goto LABEL_209;
LABEL_210:
                    v82 = *(_QWORD *)(a1 + 6552);
                    if ( v82 )
                    {
                      v83 = *(void (__fastcall **)(__int64, const char *))(v82 + 64);
                      if ( v83 )
                      {
                        v84 = v18;
                        if ( *((_DWORD *)v83 - 1) != 841426229 )
                          __break(0x8228u);
                        v83(a1, "vpp1");
                        v18 = v84;
                      }
                    }
                    goto LABEL_220;
                  }
                }
                else
                {
LABEL_184:
                  if ( v72 )
                    goto LABEL_185;
                }
                v18 = v71;
                goto LABEL_220;
              }
            }
          }
        }
      }
    }
    v95 = 0;
    goto LABEL_55;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    core_state_name(*(unsigned int *)(a1 + 3704));
    printk(&unk_86386, "err ", 0xFFFFFFFFLL, "codec", "__power_on_iris4");
  }
  result = 4294967274LL;
LABEL_198:
  _ReadStatusReg(SP_EL0);
  return result;
}
