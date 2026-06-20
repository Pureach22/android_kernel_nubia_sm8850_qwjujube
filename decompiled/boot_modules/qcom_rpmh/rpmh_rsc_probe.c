__int64 __fastcall rpmh_rsc_probe(_QWORD *a1)
{
  __int64 v2; // x21
  unsigned int irq; // w27
  const char **v4; // x20
  __int64 v5; // x0
  __int64 v6; // x22
  unsigned int variable_u32_array; // w0
  unsigned __int64 v8; // x23
  __int64 v9; // x0
  __int64 v10; // x24
  const char *property; // x28
  __int64 next_child; // x0
  const void *v13; // x26
  unsigned __int64 v14; // x0
  int v15; // w3
  int v16; // w4
  int v17; // w5
  __int64 v18; // x0
  __int64 v19; // x22
  int v20; // w4
  __int64 v21; // x9
  const char *v22; // x2
  __int64 v23; // x0
  int v24; // w8
  __int64 v25; // x9
  unsigned __int64 v26; // x25
  bool v27; // cc
  bool v28; // w11
  void *v29; // x10
  __int64 v30; // x22
  __int64 v31; // x28
  unsigned int v32; // w0
  unsigned int v33; // w27
  int v34; // w21
  __int64 v35; // x0
  char v36; // w8
  __int64 v37; // x25
  unsigned int v38; // w8
  int v39; // w8
  int v40; // w11
  __int64 v41; // x9
  __int64 v42; // x10
  __int64 v43; // x27
  unsigned __int64 v44; // x9
  unsigned int v45; // w12
  unsigned int v46; // w22
  int v47; // w11
  int v48; // w11
  __int64 v49; // x10
  __int64 v50; // x9
  int v51; // w12
  unsigned int v52; // w11
  int v53; // w14
  unsigned int v54; // w12
  int v55; // w11
  __int64 v56; // x10
  __int64 v57; // x9
  int v58; // w12
  unsigned int v59; // w11
  int v60; // w14
  unsigned int v61; // w12
  int v62; // w11
  __int64 v63; // x10
  __int64 v64; // x9
  int v65; // w12
  unsigned int v66; // w11
  int v67; // w14
  unsigned int v68; // w12
  int v69; // w11
  __int64 v70; // x10
  __int64 v71; // x9
  unsigned int v72; // w11
  int v73; // w13
  unsigned int v74; // w8
  int v75; // w0
  unsigned int v76; // w8
  int v77; // w8
  __int64 v78; // x9
  int v79; // w8
  int v80; // w9
  __int64 v81; // x10
  __int64 v82; // x11
  int v83; // w0
  int v84; // w8
  __int64 v85; // x9
  int v86; // w27
  int v87; // w27
  __int64 v88; // x1
  unsigned int v89; // w0
  __int64 v90; // x0
  int v91; // w8
  __int64 v92; // x9
  __int64 v93; // x10
  __int64 v94; // x0
  int v95; // w8
  unsigned __int64 v96; // x9
  __int64 v97; // x10
  __int64 v98; // x11
  __int64 v99; // x12
  __int64 v100; // x0
  int v101; // w8
  __int64 v102; // x9
  __int64 v103; // x10
  _QWORD *v104; // x1
  __int64 v106; // [xsp+10h] [xbp-C0h]
  const char **v107; // [xsp+18h] [xbp-B8h]
  __int64 v108; // [xsp+20h] [xbp-B0h]
  __int64 v109; // [xsp+28h] [xbp-A8h]
  const char *v110; // [xsp+30h] [xbp-A0h]
  __int64 v111; // [xsp+38h] [xbp-98h]
  __int64 v112; // [xsp+40h] [xbp-90h]
  unsigned int v113; // [xsp+4Ch] [xbp-84h]
  unsigned __int64 v114; // [xsp+50h] [xbp-80h]
  unsigned __int64 v115; // [xsp+58h] [xbp-78h]
  __int64 v116; // [xsp+60h] [xbp-70h]
  unsigned __int64 v117; // [xsp+68h] [xbp-68h]
  _BYTE v118[12]; // [xsp+74h] [xbp-5Ch]
  __int64 v119; // [xsp+80h] [xbp-50h]
  __int64 v120; // [xsp+8Ch] [xbp-44h] BYREF
  unsigned int v121; // [xsp+94h] [xbp-3Ch] BYREF
  __int64 v122; // [xsp+98h] [xbp-38h] BYREF
  __int64 v123; // [xsp+A0h] [xbp-30h] BYREF
  __int64 v124; // [xsp+A8h] [xbp-28h] BYREF
  __int64 v125; // [xsp+B0h] [xbp-20h] BYREF
  _QWORD v126[3]; // [xsp+B8h] [xbp-18h] BYREF

  v126[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[95];
  v120 = 0;
  irq = cmd_db_ready();
  if ( irq != -517 )
  {
    v4 = (const char **)(a1 + 2);
    if ( irq )
    {
      dev_err(a1 + 2, "Command DB not available (%d)\n", irq);
      goto LABEL_242;
    }
    rpmh_standalone = cmd_db_is_standalone() & 1;
    if ( rpmh_standalone )
      dev_info(a1 + 2, "RPMH is running in standalone mode.\n");
    v5 = devm_kmalloc(a1 + 2, 56, 3520);
    if ( v5 )
    {
      v6 = v5;
      variable_u32_array = of_property_read_variable_u32_array(v2, "qcom,drv-count", &v120, 1, 0);
      if ( (variable_u32_array & 0x80000000) != 0 )
        goto LABEL_241;
      if ( is_mul_ok((int)v120, 0x698u) )
      {
        v8 = 1688LL * (int)v120;
        v9 = devm_kmalloc(a1 + 2, v8, 3520);
        if ( v9 )
        {
          v10 = v9;
          property = (const char *)of_get_property(v2, "label", 0);
          if ( !property )
          {
            property = (const char *)a1[16];
            if ( !property )
              property = *v4;
          }
          *(_DWORD *)(v6 + 20) = v120;
          *(_QWORD *)(v6 + 24) = v10;
          *(_QWORD *)(v6 + 32) = v4;
          v112 = v6;
          scnprintf(v6, 20, "%s", property);
          next_child = of_get_next_child(v2, 0);
          if ( next_child )
          {
            v13 = (const void *)next_child;
            _ReadStatusReg(SP_EL0);
            v116 = v2;
            v110 = property;
            do
            {
              if ( (of_node_name_eq(v13, "drv") & 1) != 0 )
              {
                variable_u32_array = of_property_read_variable_u32_array(v13, "qcom,drv-id", (char *)&v120 + 4, 1, 0);
                if ( (variable_u32_array & 0x80000000) != 0 )
                  goto LABEL_241;
                scnprintf(v10 + 1688LL * SHIDWORD(v120), 20, "%s-drv-%d", property, HIDWORD(v120));
                v14 = devm_platform_ioremap_resource(a1, HIDWORD(v120));
                if ( v120 < 0 || v8 <= 1688LL * SHIDWORD(v120) + 24 )
                  goto LABEL_243;
                irq = v14;
                *(_QWORD *)(v10 + 1688LL * SHIDWORD(v120) + 24) = v14;
                if ( v14 >= 0xFFFFFFFFFFFFF001LL )
                  goto LABEL_242;
                v18 = _kmalloc_cache_noprof(_init_waitqueue_head, 3520, &print_fmt_rpmh_send_msg[48], v15, v16, v17);
                v19 = v18;
                if ( !v18 )
                  goto LABEL_174;
                v20 = HIDWORD(v120);
                if ( v120 < 0 )
                  goto LABEL_243;
                v21 = 1688LL * SHIDWORD(v120);
                if ( v8 < v21 + 44 )
                  goto LABEL_243;
                *(_DWORD *)(v10 + 1688LL * SHIDWORD(v120) + 44) = HIDWORD(v120);
                if ( v8 <= v21 + 1680 )
                  goto LABEL_243;
                if ( v8 <= 1688LL * v20 + 1680 )
                  goto LABEL_243;
                *(_QWORD *)(v10 + 1688LL * v20 + 1680) = a1;
                if ( v8 <= 1688LL * v20 + 1648 )
                  goto LABEL_243;
                v22 = (const char *)a1[16];
                *(_QWORD *)(v18 + 96) = v4;
                *(_QWORD *)(v18 + 744) = v13;
                *(_QWORD *)(v10 + 1688LL * v20 + 1648) = v18;
                if ( !v22 )
                  v22 = *v4;
                dev_set_name(v18, "%s:%pOFn%d", v22, v13, v20);
                variable_u32_array = device_register(v19);
                if ( variable_u32_array )
                  goto LABEL_241;
                if ( v120 < 0 || v8 <= 1688LL * SHIDWORD(v120) + 24 )
                  goto LABEL_243;
                v23 = readl_relaxed(*(unsigned int **)(v10 + 1688LL * SHIDWORD(v120) + 24));
                v24 = HIDWORD(v120);
                v25 = 1688LL * SHIDWORD(v120);
                v26 = v25 + 1664;
                v27 = v120 >= 0 && v8 > v26;
                v28 = !v27;
                if ( ((unsigned int)v23 & 0xFF0000) <= 0x20000 )
                {
                  v29 = &rpmh_rsc_reg_offset_ver_2_7;
                  if ( v28 )
                    goto LABEL_243;
                }
                else
                {
                  v29 = &rpmh_rsc_reg_offset_ver_3_0;
                  if ( v28 )
                    goto LABEL_243;
                }
                if ( v120 < 0 )
                  goto LABEL_243;
                if ( v8 <= v26 )
                  goto LABEL_243;
                v111 = v19;
                *(_QWORD *)(v26 + v10) = v29;
                if ( v24 < 0 )
                  goto LABEL_243;
                if ( v8 <= v25 + 1648 )
                  goto LABEL_243;
                v30 = 1688LL * v24;
                if ( v8 <= v30 + 1648 )
                  goto LABEL_243;
                v31 = v10 + 1688LL * v24;
                v121 = 0;
                v119 = *(_QWORD *)(*(_QWORD *)(v31 + 1648) + 744LL);
                variable_u32_array = of_property_read_variable_u32_array(v119, "qcom,tcs-offset", &v121, 1, 0);
                if ( (variable_u32_array & 0x80000000) != 0 )
                  goto LABEL_241;
                if ( v8 <= v30 + 24 )
                  goto LABEL_243;
                v115 = v30 + 32;
                if ( v8 <= v30 + 32 )
                  goto LABEL_243;
                *(_QWORD *)(v31 + 32) = *(_QWORD *)(v31 + 24) + v121;
                if ( (of_property_read_variable_u32_array(v119, "qcom,tcs-distance", v31 + 40, 1, 0) & 0x80000000) != 0 )
                {
                  if ( v8 <= v30 + 40 )
                    goto LABEL_243;
                  *(_DWORD *)(v31 + 40) = 0;
                }
                if ( v8 <= v26 )
                  goto LABEL_243;
                if ( v8 <= v30 + 24 )
                  goto LABEL_243;
                v114 = v30 + 1664;
                if ( v8 <= v30 + 1664 )
                  goto LABEL_243;
                v32 = readl_relaxed((unsigned int *)(*(_QWORD *)(v31 + 24)
                                                   + *(unsigned int *)(*(_QWORD *)(v31 + 1664) + 12LL)));
                if ( v8 < v30 + 44 )
                  goto LABEL_243;
                v33 = v32;
                v34 = *(_DWORD *)(v31 + 44);
                v35 = of_get_next_child(v119, 0);
                if ( v35 )
                {
                  v36 = 3 * v34;
                  v2 = v116;
                  v37 = v35;
                  *(_DWORD *)&v118[8] = 0;
                  v106 = v30;
                  v107 = v4;
                  v38 = ((63 << (2 * v36)) & v33) >> (2 * v36);
                  *(_QWORD *)v118 = v33 >> 27;
                  v108 = v31 + 440;
                  v109 = v30 + 440;
                  if ( v38 >= 0x1F )
                    v38 = 31;
                  v113 = v38;
                  v117 = v30 + 48;
                  while ( 1 )
                  {
                    if ( (of_node_name_eq(v37, "channel") & 1) != 0 )
                    {
                      v125 = 0;
                      v126[0] = 0;
                      v123 = 0;
                      v124 = 0;
                      v122 = 0;
                      if ( *(_QWORD *)&v118[4] >= 3u )
                        goto LABEL_244;
                      if ( (unsigned int)of_property_count_elems_of_size(v37, "qcom,tcs-config", 4) != 10 )
                        goto LABEL_235;
                      variable_u32_array = of_property_read_u32_index(v37, "qcom,tcs-config", 0, &v122);
                      if ( variable_u32_array )
                        goto LABEL_241;
                      if ( (unsigned int)v122 > 4 )
                        goto LABEL_235;
                      variable_u32_array = of_property_read_u32_index(v37, "qcom,tcs-config", 1, (char *)&v122 + 4);
                      if ( variable_u32_array )
                        goto LABEL_241;
                      if ( HIDWORD(v122) > 3 )
                        goto LABEL_235;
                      variable_u32_array = of_property_read_u32_index(v37, "qcom,tcs-config", 2, &v123);
                      if ( variable_u32_array )
                        goto LABEL_241;
                      if ( (unsigned int)v123 > 4 )
                        goto LABEL_235;
                      variable_u32_array = of_property_read_u32_index(v37, "qcom,tcs-config", 3, (char *)&v123 + 4);
                      if ( variable_u32_array )
                        goto LABEL_241;
                      if ( HIDWORD(v123) > 3 )
                        goto LABEL_235;
                      variable_u32_array = of_property_read_u32_index(v37, "qcom,tcs-config", 4, &v124);
                      if ( variable_u32_array )
                        goto LABEL_241;
                      if ( (unsigned int)v124 > 4 )
                        goto LABEL_235;
                      variable_u32_array = of_property_read_u32_index(v37, "qcom,tcs-config", 5, (char *)&v124 + 4);
                      if ( variable_u32_array )
                        goto LABEL_241;
                      if ( HIDWORD(v124) > 3 )
                        goto LABEL_235;
                      variable_u32_array = of_property_read_u32_index(v37, "qcom,tcs-config", 6, &v125);
                      if ( variable_u32_array )
                        goto LABEL_241;
                      if ( (unsigned int)v125 > 4 )
                        goto LABEL_235;
                      variable_u32_array = of_property_read_u32_index(v37, "qcom,tcs-config", 7, (char *)&v125 + 4);
                      if ( variable_u32_array )
                        goto LABEL_241;
                      if ( HIDWORD(v125) > 3 )
                        goto LABEL_235;
                      variable_u32_array = of_property_read_u32_index(v37, "qcom,tcs-config", 8, v126);
                      if ( variable_u32_array )
                        goto LABEL_241;
                      if ( LODWORD(v126[0]) > 4 )
                        goto LABEL_235;
                      variable_u32_array = of_property_read_u32_index(v37, "qcom,tcs-config", 9, (char *)v126 + 4);
                      if ( variable_u32_array )
                        goto LABEL_241;
                      v39 = HIDWORD(v126[0]);
                      if ( HIDWORD(v126[0]) > 3 )
                      {
LABEL_235:
                        irq = -22;
                        goto LABEL_242;
                      }
                      v40 = v122;
                      if ( (unsigned int)v122 >= 6 )
                        goto LABEL_244;
                      v41 = 336LL * *(_QWORD *)&v118[4];
                      v4 = (const char **)(v109 + 336LL * *(_QWORD *)&v118[4]);
                      v42 = (__int64)&v4[8 * (unsigned __int64)(unsigned int)v122];
                      if ( v8 <= v42 )
                        goto LABEL_243;
                      v43 = v108 + v41;
                      v44 = v108 + v41 + ((unsigned __int64)(unsigned int)v122 << 6);
                      if ( *(_QWORD *)v44 )
                        goto LABEL_235;
                      if ( v8 <= v42 )
                        goto LABEL_243;
                      *(_QWORD *)v44 = v31;
                      if ( v42 < -8 )
                        goto LABEL_243;
                      if ( v8 <= v42 + 8 )
                        goto LABEL_243;
                      *(_DWORD *)(v44 + 8) = v40;
                      if ( v8 < v42 + 20 )
                        goto LABEL_243;
                      v45 = HIDWORD(v122);
                      *(_DWORD *)(v44 + 20) = HIDWORD(v122);
                      if ( v8 <= v42 + 24 )
                        goto LABEL_243;
                      v46 = 0;
                      *(_DWORD *)(v44 + 24) = *(_DWORD *)v118;
                      if ( v40 != 3 && v45 )
                      {
                        if ( v45 > v113 )
                          goto LABEL_235;
                        if ( v8 <= v117 )
                          goto LABEL_243;
                        if ( v8 < v42 + 12 )
                          goto LABEL_243;
                        v47 = *(_DWORD *)(v31 + 48);
                        *(_DWORD *)(v44 + 12) = ~(-1 << v45) << v47;
                        if ( v8 <= v42 + 16 )
                          goto LABEL_243;
                        v46 = v45;
                        *(_DWORD *)(v44 + 16) = v47;
                      }
                      v48 = v123;
                      if ( (unsigned int)v123 > 5 )
                        goto LABEL_244;
                      v49 = (__int64)&v4[8 * (unsigned __int64)(unsigned int)v123];
                      if ( v8 <= v49 )
                        goto LABEL_243;
                      v50 = v43 + ((unsigned __int64)(unsigned int)v123 << 6);
                      if ( *(_QWORD *)v50 )
                        goto LABEL_235;
                      if ( v8 <= v49 )
                        goto LABEL_243;
                      *(_QWORD *)v50 = v31;
                      if ( v49 < -8 )
                        goto LABEL_243;
                      if ( v8 <= v49 + 8 )
                        goto LABEL_243;
                      *(_DWORD *)(v50 + 8) = v48;
                      if ( v8 < v49 + 20 )
                        goto LABEL_243;
                      v51 = HIDWORD(v123);
                      *(_DWORD *)(v50 + 20) = HIDWORD(v123);
                      if ( v8 <= v49 + 24 )
                        goto LABEL_243;
                      *(_DWORD *)(v50 + 24) = *(_DWORD *)v118;
                      if ( v48 != 3 && v51 )
                      {
                        v52 = v51 + v46;
                        if ( v51 + v46 > v113 )
                          goto LABEL_235;
                        if ( v8 <= v117 )
                          goto LABEL_243;
                        if ( v8 < v49 + 12 )
                          goto LABEL_243;
                        v53 = -1 << v51;
                        v54 = *(_DWORD *)(v31 + 48) + v46;
                        *(_DWORD *)(v50 + 12) = ~v53 << (*(_BYTE *)(v31 + 48) + v46);
                        if ( v8 <= v49 + 16 )
                          goto LABEL_243;
                        v46 = v52;
                        *(_DWORD *)(v50 + 16) = v54;
                      }
                      v55 = v124;
                      if ( (unsigned int)v124 > 5 )
                        goto LABEL_244;
                      v56 = (__int64)&v4[8 * (unsigned __int64)(unsigned int)v124];
                      if ( v8 <= v56 )
                        goto LABEL_243;
                      v57 = v43 + ((unsigned __int64)(unsigned int)v124 << 6);
                      if ( *(_QWORD *)v57 )
                        goto LABEL_235;
                      if ( v8 <= v56 )
                        goto LABEL_243;
                      *(_QWORD *)v57 = v31;
                      if ( v56 < -8 )
                        goto LABEL_243;
                      if ( v8 <= v56 + 8 )
                        goto LABEL_243;
                      *(_DWORD *)(v57 + 8) = v55;
                      if ( v8 < v56 + 20 )
                        goto LABEL_243;
                      v58 = HIDWORD(v124);
                      *(_DWORD *)(v57 + 20) = HIDWORD(v124);
                      if ( v8 <= v56 + 24 )
                        goto LABEL_243;
                      *(_DWORD *)(v57 + 24) = *(_DWORD *)v118;
                      if ( v55 != 3 && v58 )
                      {
                        v59 = v58 + v46;
                        if ( v58 + v46 > v113 )
                          goto LABEL_235;
                        if ( v8 <= v117 )
                          goto LABEL_243;
                        if ( v8 < v56 + 12 )
                          goto LABEL_243;
                        v60 = -1 << v58;
                        v61 = *(_DWORD *)(v31 + 48) + v46;
                        *(_DWORD *)(v57 + 12) = ~v60 << (*(_BYTE *)(v31 + 48) + v46);
                        if ( v8 <= v56 + 16 )
                          goto LABEL_243;
                        v46 = v59;
                        *(_DWORD *)(v57 + 16) = v61;
                      }
                      v62 = v125;
                      if ( (unsigned int)v125 > 5 )
                        goto LABEL_244;
                      v63 = (__int64)&v4[8 * (unsigned __int64)(unsigned int)v125];
                      if ( v8 <= v63 )
                        goto LABEL_243;
                      v64 = v43 + ((unsigned __int64)(unsigned int)v125 << 6);
                      if ( *(_QWORD *)v64 )
                        goto LABEL_235;
                      if ( v8 <= v63 )
                        goto LABEL_243;
                      *(_QWORD *)v64 = v31;
                      if ( v63 < -8 )
                        goto LABEL_243;
                      if ( v8 <= v63 + 8 )
                        goto LABEL_243;
                      *(_DWORD *)(v64 + 8) = v62;
                      if ( v8 < v63 + 20 )
                        goto LABEL_243;
                      v65 = HIDWORD(v125);
                      *(_DWORD *)(v64 + 20) = HIDWORD(v125);
                      if ( v8 <= v63 + 24 )
                        goto LABEL_243;
                      *(_DWORD *)(v64 + 24) = *(_DWORD *)v118;
                      if ( v62 != 3 && v65 )
                      {
                        v66 = v65 + v46;
                        if ( v65 + v46 > v113 )
                          goto LABEL_235;
                        if ( v8 <= v117 )
                          goto LABEL_243;
                        if ( v8 < v63 + 12 )
                          goto LABEL_243;
                        v67 = -1 << v65;
                        v68 = *(_DWORD *)(v31 + 48) + v46;
                        *(_DWORD *)(v64 + 12) = ~v67 << (*(_BYTE *)(v31 + 48) + v46);
                        if ( v8 <= v63 + 16 )
                          goto LABEL_243;
                        v46 = v66;
                        *(_DWORD *)(v64 + 16) = v68;
                      }
                      v69 = v126[0];
                      if ( LODWORD(v126[0]) > 5 )
                        goto LABEL_244;
                      v70 = (__int64)&v4[8 * (unsigned __int64)LODWORD(v126[0])];
                      if ( v8 <= v70 )
                        goto LABEL_243;
                      v71 = v43 + ((unsigned __int64)LODWORD(v126[0]) << 6);
                      if ( *(_QWORD *)v71 )
                        goto LABEL_235;
                      if ( v8 <= v70 )
                        goto LABEL_243;
                      *(_QWORD *)v71 = v31;
                      if ( v70 < -8 )
                        goto LABEL_243;
                      if ( v8 <= v70 + 8 )
                        goto LABEL_243;
                      *(_DWORD *)(v71 + 8) = v69;
                      if ( v8 < v70 + 20 )
                        goto LABEL_243;
                      *(_DWORD *)(v71 + 20) = v39;
                      if ( v8 <= v70 + 24 )
                        goto LABEL_243;
                      *(_DWORD *)(v71 + 24) = *(_DWORD *)v118;
                      if ( v39 && v69 != 3 )
                      {
                        v72 = v46 + v39;
                        if ( v46 + v39 > v113 )
                          goto LABEL_235;
                        if ( v8 <= v117 )
                          goto LABEL_243;
                        if ( v8 < v70 + 12 )
                          goto LABEL_243;
                        v73 = -1 << v39;
                        v74 = *(_DWORD *)(v31 + 48) + v46;
                        *(_DWORD *)(v71 + 12) = ~v73 << (*(_BYTE *)(v31 + 48) + v46);
                        if ( v8 <= v70 + 16 )
                          goto LABEL_243;
                        v46 = v72;
                        *(_DWORD *)(v71 + 16) = v74;
                      }
                      if ( v8 <= v115 || v8 <= v114 )
                        goto LABEL_243;
                      v75 = readl_relaxed((unsigned int *)(*(_QWORD *)(v31 + 32)
                                                         + *(unsigned int *)(*(_QWORD *)(v31 + 1664) + 16LL)));
                      if ( *(_QWORD *)&v118[4] == 2 )
                      {
LABEL_244:
                        __break(0x5512u);
                        goto LABEL_245;
                      }
                      if ( v8 < (unsigned __int64)v4 + 140 )
                        goto LABEL_243;
                      if ( v8 <= v115 )
                        goto LABEL_243;
                      if ( v8 <= v114 )
                        goto LABEL_243;
                      writel_relaxed(
                        *(_DWORD *)(v43 + 140) | v75,
                        (unsigned int *)(*(_QWORD *)(v31 + 32) + *(unsigned int *)(*(_QWORD *)(v31 + 1664) + 16LL)));
                      if ( v8 <= (unsigned __int64)(v4 + 40) )
                        goto LABEL_243;
                      *(_QWORD *)(v43 + 320) = v31;
                      if ( v8 <= (unsigned __int64)(v4 + 41) )
                        goto LABEL_243;
                      v4 = v107;
                      *(_BYTE *)(v43 + 328) = 1;
                      if ( v8 <= v117 )
                        goto LABEL_243;
                      v76 = *(_DWORD *)(v31 + 48) + v46;
                      v30 = v106;
                      *(_DWORD *)(v31 + 48) = v76;
                      ++*(_QWORD *)&v118[4];
                    }
                    v37 = of_get_next_child(v119, v37);
                    if ( !v37 )
                      goto LABEL_170;
                  }
                }
                v2 = v116;
                *(_DWORD *)&v118[4] = 0;
LABEL_170:
                if ( v8 < v30 + 52
                  || (v77 = HIDWORD(v120),
                      v78 = v10 + 1688LL * SHIDWORD(v120),
                      *(_DWORD *)(v31 + 52) = *(_DWORD *)&v118[4],
                      *(_QWORD *)(v111 + 152) = v78,
                      v77 < 0)
                  || v8 < 1688LL * v77 + 61 )
                {
LABEL_243:
                  __break(1u);
                }
                property = v110;
                *(_BYTE *)(v10 + 1688LL * v77 + 61) = 1;
              }
              v13 = (const void *)of_get_next_child(v2, v13);
            }
            while ( v13 );
          }
          v79 = v120;
          HIDWORD(v120) = 0;
          if ( (int)v120 >= 1 )
          {
            v80 = 0;
            do
            {
              if ( v80 < 0 )
                goto LABEL_243;
              v81 = 1688LL * v80;
              if ( v8 < v81 + 61 )
                goto LABEL_243;
              v82 = v10 + 1688LL * v80;
              if ( *(_BYTE *)(v82 + 61) == 1 )
              {
                if ( v8 <= v81 + 1664 )
                  goto LABEL_243;
                if ( v8 <= v81 + 24 )
                  goto LABEL_243;
                if ( v8 <= v81 + 1664 )
                  goto LABEL_243;
                v83 = readl_relaxed((unsigned int *)(*(_QWORD *)(v82 + 24)
                                                   + *(unsigned int *)(*(_QWORD *)(v82 + 1664) + 8LL)));
                v84 = HIDWORD(v120);
                if ( v120 < 0 )
                  goto LABEL_243;
                v85 = 1688LL * SHIDWORD(v120);
                if ( v8 <= v85 + 1120 )
                  goto LABEL_243;
                *(_DWORD *)(v10 + 1688LL * SHIDWORD(v120) + 1120) = 0;
                if ( v8 <= v85 + 1152 || v8 <= 1688LL * v84 + 1152 )
                  goto LABEL_243;
                v86 = v83;
                *(_DWORD *)(v10 + 1688LL * v84 + 1152) = 0;
                if ( of_find_property(v2, "power-domains", 0) && a1[76] )
                {
                  v87 = HIDWORD(v120);
                  pm_runtime_enable(v4);
                  if ( v87 < 0 || v8 <= 1688LL * v87 + 88 )
                    goto LABEL_243;
                  v88 = v10 + 1688LL * v87;
                  *(_QWORD *)(v88 + 88) = rpmh_rsc_pd_callback;
                  v89 = dev_pm_genpd_add_notifier(v4, v88 + 88);
                  if ( v89 )
                  {
                    irq = v89;
                    _pm_runtime_disable(v4, 1);
                    goto LABEL_242;
                  }
                }
                else if ( (v86 & 0x1000000) != 0 )
                {
                  if ( v120 < 0 || v8 <= 1688LL * SHIDWORD(v120) + 1160 )
                    goto LABEL_243;
                  *(_DWORD *)(v10 + 1688LL * SHIDWORD(v120) + 1160) = 1;
                }
                else
                {
                  v90 = of_find_property(v2, "qcom,hw-channel", 0);
                  v91 = HIDWORD(v120);
                  v92 = 1688LL * SHIDWORD(v120);
                  if ( v90 )
                  {
                    if ( v120 < 0 )
                      goto LABEL_243;
                    if ( v8 <= v92 + 1160 )
                      goto LABEL_243;
                    if ( v8 <= 1688LL * SHIDWORD(v120) + 1160 )
                      goto LABEL_243;
                    *(_DWORD *)(v10 + 1688LL * SHIDWORD(v120) + 1160) = 3;
                    if ( v8 < 1688LL * v91 + 1157 )
                      goto LABEL_243;
                    *(_BYTE *)(v10 + 1688LL * v91 + 1157) = 1;
                    if ( v8 < 1688LL * v91 + 60 )
                      goto LABEL_243;
                    *(_BYTE *)(v10 + 1688LL * v91 + 60) = 1;
                    if ( v8 <= v92 + 1664 || v8 <= 1688LL * v91 + 1664 )
                      goto LABEL_243;
                    *(_QWORD *)(v10 + 1688LL * v91 + 1664) = &rpmh_rsc_reg_offset_ver_3_0_hw_channel;
                  }
                  else
                  {
                    if ( v120 < 0 )
                      goto LABEL_243;
                    if ( v8 <= v92 + 64 )
                      goto LABEL_243;
                    if ( v8 <= 1688LL * SHIDWORD(v120) + 64 )
                      goto LABEL_243;
                    v93 = v10 + 1688LL * SHIDWORD(v120);
                    *(_QWORD *)(v93 + 64) = rpmh_rsc_cpu_pm_callback;
                    if ( v8 <= v92 + 80 || v8 <= 1688LL * v91 + 80 )
                      goto LABEL_243;
                    *(_DWORD *)(v10 + 1688LL * v91 + 80) = 0x7FFFFFFF;
                    cpu_pm_register_notifier(v93 + 64);
                  }
                }
                _init_waitqueue_head(v10 + 1688LL * SHIDWORD(v120) + 1128, "&drv[i].tcs_wait", &rpmh_rsc_probe___key);
                if ( v120 < 0 )
                  goto LABEL_243;
                if ( v8 <= 1688LL * SHIDWORD(v120) + 1112 )
                  goto LABEL_243;
                *(_QWORD *)(v10 + 1688LL * SHIDWORD(v120) + 1112) = 0;
                v94 = devm_kmalloc(v4, 8000, 3520);
                v95 = HIDWORD(v120);
                if ( v120 < 0 )
                  goto LABEL_243;
                v96 = 1688LL * SHIDWORD(v120) + 1640;
                if ( v8 <= v96 )
                  goto LABEL_243;
                *(_QWORD *)(v96 + v10) = v94;
                if ( !v94 )
                  goto LABEL_174;
                v97 = 0;
                v98 = 250;
                do
                {
                  if ( v8 <= v96 )
                    goto LABEL_243;
                  --v98;
                  v99 = *(_QWORD *)(v96 + v10) + v97;
                  v97 += 32;
                  *(_QWORD *)(v99 + 16) = v99 + 16;
                  *(_QWORD *)(v99 + 24) = v99 + 16;
                }
                while ( v98 );
                if ( v8 < 1688LL * v95 + 44 )
                  goto LABEL_243;
                irq = platform_get_irq(a1, *(unsigned int *)(v10 + 1688LL * v95 + 44));
                if ( (irq & 0x80000000) != 0 )
                  goto LABEL_242;
                if ( v120 < 0 || v8 <= 1688LL * SHIDWORD(v120) + 56 )
                  goto LABEL_243;
                *(_DWORD *)(v10 + 1688LL * SHIDWORD(v120) + 56) = irq;
                variable_u32_array = devm_request_threaded_irq(v4, irq, tcs_tx_done, 0, 16388);
                if ( variable_u32_array )
                  goto LABEL_241;
                v100 = ipc_log_context_create(2, v10 + 1688LL * SHIDWORD(v120), 0);
                v101 = HIDWORD(v120);
                if ( v120 < 0 || v8 <= 1688LL * SHIDWORD(v120) + 1672 )
                  goto LABEL_243;
                v102 = (unsigned int)_rsc_count;
                *(_QWORD *)(v10 + 1688LL * SHIDWORD(v120) + 1672) = v100;
                if ( (int)v102 <= 4 )
                {
                  _rsc_count = v102 + 1;
                  if ( (unsigned int)v102 > 5 )
                    goto LABEL_243;
                  _rsc_drv[v102] = v10 + 1688LL * v101;
                }
                if ( v8 <= 1688LL * v101 + 1648 )
                  goto LABEL_243;
                variable_u32_array = devm_of_platform_populate(*(_QWORD *)(v10 + 1688LL * v101 + 1648));
                if ( variable_u32_array )
                  goto LABEL_241;
                v79 = v120;
                v80 = HIDWORD(v120);
              }
              HIDWORD(v120) = ++v80;
            }
            while ( v80 < v79 );
          }
          v103 = v112;
          *(_QWORD *)(v112 + 40) = v112 + 40;
          *(_QWORD *)(v112 + 48) = v112 + 40;
          v104 = off_BA0;
          if ( off_BA0 == (_UNKNOWN *)(v112 + 40) || *(_UNKNOWN ***)off_BA0 != &rpmh_rsc_dev_list )
          {
LABEL_245:
            _list_add_valid_or_report();
          }
          else
          {
            off_BA0 = (_UNKNOWN *)(v112 + 40);
            *(_QWORD *)(v112 + 40) = &rpmh_rsc_dev_list;
            *(_QWORD *)(v112 + 48) = v104;
            *v104 = v112 + 40;
          }
          a1[21] = v103;
          variable_u32_array = devm_of_platform_populate(v4);
LABEL_241:
          irq = variable_u32_array;
          goto LABEL_242;
        }
      }
    }
LABEL_174:
    irq = -12;
  }
LABEL_242:
  _ReadStatusReg(SP_EL0);
  return irq;
}
