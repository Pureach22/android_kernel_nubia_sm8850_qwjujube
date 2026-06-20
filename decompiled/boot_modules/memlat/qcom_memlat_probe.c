__int64 __fastcall qcom_memlat_probe(_QWORD *a1)
{
  const char **v1; // x20
  int *match_data; // x0
  int v4; // w2
  unsigned __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x21
  _DWORD *v8; // x22
  __int64 next_available_child; // x0
  __int64 v10; // x1
  int v11; // w19
  unsigned int v12; // w23
  __int64 v13; // x27
  __int64 v14; // x21
  __int64 v15; // x26
  __int64 v16; // x0
  int v17; // w19
  unsigned int v18; // w23
  unsigned int v19; // w0
  __int64 v20; // x0
  unsigned __int64 v27; // x10
  __int64 v28; // x0
  int v29; // w0
  __int64 v30; // x0
  __int64 v31; // x22
  unsigned int v32; // w0
  unsigned __int64 v33; // x0
  unsigned __int64 v34; // x1
  const char *v35; // x2
  const char **v36; // x0
  __int64 v37; // x22
  __int64 v38; // x0
  _QWORD *v39; // x8
  __int64 v40; // x22
  char v41; // w8
  __int64 v42; // x8
  unsigned __int64 v43; // x27
  __int64 v44; // x0
  unsigned __int64 v45; // x8
  __int64 v46; // x9
  bool v47; // cc
  __int64 ddr_child_node; // x21
  __int64 next_child; // x0
  __int64 v50; // x1
  int v51; // w19
  int v52; // w8
  unsigned __int64 v53; // x23
  __int64 v54; // x0
  int v55; // w10
  __int64 v56; // x22
  unsigned __int64 v57; // x19
  unsigned int v58; // w25
  unsigned int v59; // w25
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x8
  unsigned int v62; // w0
  __int64 v63; // x0
  int v64; // w0
  int v65; // w8
  int v66; // w0
  __int64 v67; // x2
  __int64 v68; // x1
  const char *v69; // x0
  __int64 v70; // x0
  unsigned int v71; // w24
  __int64 v72; // x0
  char v73; // w8
  unsigned __int64 v74; // x8
  unsigned __int64 v75; // x26
  int v76; // w0
  int v77; // w0
  __int64 v78; // x0
  int v79; // w0
  __int64 v80; // x0
  int v81; // w0
  unsigned __int64 v82; // x21
  int v83; // w0
  __int64 v84; // x21
  __int64 v85; // x0
  __int64 v86; // x1
  int v87; // w19
  __int64 v88; // x0
  int v89; // w10
  int v90; // w8
  const char *v91; // x3
  void *v92; // x1
  int v93; // w8
  __int64 v94; // x0
  __int64 v95; // x9
  __int64 v96; // x9
  __int64 v97; // x9
  __int64 v98; // x9
  __int64 v99; // x9
  unsigned __int64 qcom_scmi_device; // x0
  __int64 v101; // x8
  __int64 (*v102)(void); // x8
  unsigned __int64 v103; // x0
  __int64 (__fastcall **v104)(__int64, unsigned __int64 *, __int64, __int64, __int64); // x23
  unsigned int v105; // w25
  __int64 v106; // x0
  int v107; // w8
  unsigned int v108; // w8
  __int64 v109; // x0
  unsigned int v110; // w0
  int v111; // w8
  __int64 v112; // x21
  __int64 v113; // x0
  __int64 v114; // x1
  unsigned int v115; // w19
  __int64 v116; // x0
  int v117; // w0
  __int64 v118; // x0
  char v119; // w8
  unsigned __int64 v120; // x8
  __int64 v121; // x0
  unsigned __int64 v122; // x23
  int v123; // w0
  __int64 v124; // x0
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x19
  __int64 v128; // x8
  __int64 v129; // x21
  __int64 v130; // x0
  __int64 v131; // x1
  int v132; // w19
  __int64 v133; // x8
  __int64 v134; // x9
  __int64 v135; // x0
  unsigned int cpucp_id; // w0
  char v137; // w20
  __int64 v138; // x0
  unsigned int v139; // w0
  char v140; // w19
  __int64 v141; // x0
  unsigned int v142; // w0
  char v143; // w22
  __int64 v144; // x0
  unsigned int v145; // w0
  char v146; // w9
  __int64 v147; // x0
  __int64 (__fastcall *v148)(__int64, unsigned __int64 *, __int64, __int64, __int64); // x9
  unsigned int v149; // w0
  __int64 v150; // x27
  char v151; // w20
  __int64 v152; // x11
  _DWORD *v153; // x28
  __int64 v154; // x0
  __int64 (__fastcall **v155)(__int64, unsigned __int64 *, __int64, __int64, __int64); // x23
  unsigned int v156; // w10
  __int64 (__fastcall *v157)(__int64, unsigned __int64 *, __int64, __int64, __int64); // x8
  unsigned int v158; // w0
  __int64 v159; // x0
  unsigned int v160; // w0
  _DWORD *v161; // x11
  char v162; // w19
  __int64 v163; // x0
  unsigned int v164; // w0
  char v165; // w26
  __int64 v166; // x0
  unsigned int v167; // w0
  char v168; // w8
  int v169; // w9
  __int64 (__fastcall *v170)(__int64, unsigned __int64 *, __int64, __int64, __int64); // x8
  __int64 v171; // x0
  _DWORD *v172; // x23
  unsigned int v173; // w0
  unsigned int v174; // w8
  _DWORD *v175; // x11
  unsigned int i; // w23
  __int64 v177; // x28
  __int64 v178; // x20
  __int64 v179; // x19
  __int64 (__fastcall **v180)(__int64, unsigned int *, __int64, __int64, __int64); // x22
  int v181; // w10
  const char **v182; // x8
  const char *v183; // x26
  char *v184; // x0
  __int64 (__fastcall *v185)(__int64, unsigned int *, __int64, __int64, __int64); // x8
  __int64 v186; // x0
  unsigned int v187; // w0
  __int64 v188; // x0
  __int64 (__fastcall *v189)(__int64, unsigned int *, __int64, __int64, __int64); // x8
  unsigned int v190; // w0
  __int64 v191; // x0
  __int64 (__fastcall *v192)(__int64, unsigned int *, __int64, __int64, __int64); // x8
  unsigned int v193; // w0
  __int64 v194; // x0
  __int64 (__fastcall *v195)(__int64, unsigned int *, __int64, __int64, __int64); // x8
  unsigned int v196; // w0
  __int64 v197; // x0
  __int64 (__fastcall *v198)(__int64, unsigned int *, __int64, __int64, __int64); // x8
  unsigned int v199; // w0
  __int64 v200; // x0
  __int64 (__fastcall *v201)(__int64, unsigned int *, __int64, __int64, __int64); // x8
  unsigned int v202; // w0
  __int64 v203; // x0
  __int64 (__fastcall *v204)(__int64, unsigned int *, __int64, __int64, __int64); // x8
  unsigned int v205; // w0
  __int64 v206; // x0
  __int64 (__fastcall *v207)(__int64, unsigned int *, __int64, __int64, __int64); // x8
  unsigned int v208; // w0
  __int64 v209; // x0
  __int64 (__fastcall *v210)(__int64, unsigned int *, __int64, __int64, __int64); // x8
  unsigned int v211; // w0
  __int64 v212; // x9
  __int64 v213; // x9
  __int64 v214; // x8
  unsigned int *v215; // x10
  __int16 v216; // w11
  unsigned int v217; // t1
  char *v218; // x13
  unsigned int v219; // w12
  __int64 (__fastcall *v220)(__int64, unsigned __int64 *, __int64, __int64, __int64); // x9
  __int64 v221; // x0
  unsigned int v222; // w0
  __int64 v223; // x0
  __int64 (__fastcall *v224)(__int64, unsigned int *, __int64, __int64, __int64); // x8
  unsigned int v225; // w0
  __int64 v226; // x0
  __int64 (__fastcall *v227)(__int64, unsigned int *, __int64, __int64, __int64); // x8
  unsigned int v228; // w0
  __int64 (__fastcall *v229)(__int64, __int64, __int64, __int64, __int64); // x9
  __int64 v230; // x0
  __int64 v231; // x1
  __int64 (__fastcall *v232)(__int64, __int64, __int64, __int64, __int64); // x9
  __int64 v233; // x0
  void *v234; // x0
  void *v235; // x0
  void *v237; // [xsp+8h] [xbp-D8h]
  __int64 (__fastcall **v238)(__int64, __int64, __int64, __int64, __int64); // [xsp+10h] [xbp-D0h]
  __int64 v239; // [xsp+18h] [xbp-C8h]
  unsigned __int64 v240; // [xsp+28h] [xbp-B8h]
  _DWORD *v241; // [xsp+28h] [xbp-B8h]
  __int64 v242; // [xsp+30h] [xbp-B0h]
  __int64 v243; // [xsp+30h] [xbp-B0h]
  const char **v244; // [xsp+38h] [xbp-A8h]
  __int64 v245; // [xsp+40h] [xbp-A0h] BYREF
  unsigned int v246; // [xsp+4Ch] [xbp-94h] BYREF
  int v247; // [xsp+50h] [xbp-90h]
  int v248; // [xsp+54h] [xbp-8Ch]
  unsigned __int64 v249; // [xsp+58h] [xbp-88h] BYREF
  __int64 v250; // [xsp+60h] [xbp-80h] BYREF
  __int64 v251; // [xsp+68h] [xbp-78h]
  __int64 v252; // [xsp+70h] [xbp-70h]
  __int64 v253; // [xsp+78h] [xbp-68h]
  __int64 v254; // [xsp+80h] [xbp-60h]
  __int64 v255; // [xsp+88h] [xbp-58h]
  __int64 v256; // [xsp+90h] [xbp-50h]
  __int64 v257; // [xsp+98h] [xbp-48h]
  __int64 v258; // [xsp+A0h] [xbp-40h]
  unsigned int v259; // [xsp+ACh] [xbp-34h] BYREF
  int v260; // [xsp+B0h] [xbp-30h]
  int v261; // [xsp+B4h] [xbp-2Ch]
  int v262; // [xsp+B8h] [xbp-28h]
  _QWORD v263[2]; // [xsp+BCh] [xbp-24h] BYREF
  int v264; // [xsp+CCh] [xbp-14h]
  __int64 v265; // [xsp+D0h] [xbp-10h]

  v1 = (const char **)(a1 + 2);
  v265 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  match_data = (int *)of_device_get_match_data(a1 + 2);
  if ( !match_data )
  {
    v4 = 3;
    goto LABEL_156;
  }
  v4 = *match_data;
  if ( *match_data == 2 )
  {
    v13 = *(_QWORD *)(a1[14] + 152LL);
    if ( v13 )
    {
      v14 = a1[95];
      mutex_lock(v13 + 112);
      v15 = *(_QWORD *)(v13 + 96) + 240LL * *(unsigned int *)(v13 + 108);
      *(_QWORD *)v15 = v1;
      *(_QWORD *)(v15 + 8) = v13;
      v16 = a1[95];
      v257 = 0;
      v258 = 0;
      v255 = 0;
      v256 = 0;
      v253 = 0;
      v254 = 0;
      v251 = 0;
      v252 = 0;
      v249 = 0;
      v250 = 0;
      if ( (unsigned int)_of_parse_phandle_with_args(v16, "qcom,cpulist", 0, 0, 0, &v249) || !v249 )
        goto LABEL_162;
      v17 = -19;
      v18 = 1;
      do
      {
        v19 = of_cpu_node_to_id();
        if ( (v19 & 0x80000000) == 0 )
        {
          _X9 = (unsigned __int64 *)(v15 + 24 + 8LL * (v19 >> 6));
          __asm { PRFM            #0x11, [X9] }
          do
            v27 = __ldxr(_X9);
          while ( __stxr(v27 | (1LL << v19), _X9) );
          v17 = 0;
          *(_DWORD *)(v15 + 20) |= 1LL << v19;
        }
        v20 = a1[95];
        v257 = 0;
        v258 = 0;
        v255 = 0;
        v256 = 0;
        v253 = 0;
        v254 = 0;
        v251 = 0;
        v252 = 0;
        v249 = 0;
        v250 = 0;
        if ( (unsigned int)_of_parse_phandle_with_args(v20, "qcom,cpulist", 0, 0, v18, &v249) )
          break;
        ++v18;
      }
      while ( v249 );
      if ( v17 )
      {
LABEL_162:
        v94 = dev_err(v1, "Mon missing cpulist\n");
        LODWORD(v82) = -19;
        --*(_DWORD *)(v13 + 104);
      }
      else
      {
        _sw_hweight64(*(unsigned int *)(v15 + 24));
        mutex_lock(&memlat_lock);
        if ( (*(_BYTE *)(memlat_data + 305) & 1) == 0 )
        {
          v37 = *(_QWORD *)memlat_data;
          v38 = alloc_workqueue("%s", (const char *)0x4000E);
          v39 = (_QWORD *)memlat_data;
          *(_QWORD *)(memlat_data + 152) = v38;
          if ( !v38 )
          {
            dev_err(v37, "Couldn't create memlat workqueue.\n");
            mutex_unlock(&memlat_lock);
            LODWORD(v82) = -12;
            goto LABEL_363;
          }
          v39[15] = 0xFFFFFFFE00000LL;
          v39[16] = v39 + 16;
          v39[17] = v39 + 16;
          v39[18] = memlat_update_work;
          hrtimer_init(v39 + 21, 1, 1);
          *(_QWORD *)(memlat_data + 208) = memlat_hrtimer_handler;
          tracepoint_probe_register(&_tracepoint_android_vh_jiffies_update, memlat_jiffies_update_cb, 0);
          *(_BYTE *)(memlat_data + 305) = 1;
        }
        v242 = v13;
        if ( of_find_property(a1[95], "qcom,sampling-enabled", 0) )
        {
          if ( (*(_BYTE *)(memlat_data + 306) & 1) == 0 )
          {
            v40 = *(_QWORD *)memlat_data;
            v41 = 0;
            do
            {
              v42 = -1LL << v41;
              v43 = (unsigned int)v42 & _cpu_possible_mask;
              if ( ((unsigned int)v42 & _cpu_possible_mask) == 0 )
                break;
              v44 = devm_kmalloc(v40, 640, 3520);
              if ( !v44 )
              {
                mutex_unlock(&memlat_lock);
                v13 = v242;
                LODWORD(v82) = -12;
                goto LABEL_363;
              }
              v45 = __clz(__rbit64(v43));
              v46 = _per_cpu_offset[v45];
              v47 = v45 > 0x1E;
              v41 = v45 + 1;
              *(_QWORD *)((char *)&sampling_stats + v46) = v44;
              *(_DWORD *)(v44 + 584) = 0;
            }
            while ( !v47 );
            tracepoint_probe_register(&_tracepoint_android_vh_scheduler_tick, memlat_sched_tick_cb, 0);
            qcom_pmu_idle_register(&memlat_idle_notif);
            v13 = v242;
            *(_BYTE *)(memlat_data + 306) = 1;
          }
          *(_DWORD *)(v15 + 16) |= 1u;
        }
        mutex_unlock(&memlat_lock);
        if ( of_find_property(a1[95], "qcom,threadlat-enabled", 0) )
          *(_DWORD *)(v15 + 16) |= 2u;
        if ( of_find_property(a1[95], "qcom,cpucp-enabled", 0) )
        {
          *(_DWORD *)(v15 + 16) |= 4u;
          *(_BYTE *)(v13 + 28) = 1;
        }
        if ( !*(_DWORD *)(v15 + 16) )
        {
          dev_err(v1, "No types configured for mon!\n");
          LODWORD(v82) = -19;
          goto LABEL_363;
        }
        if ( of_find_property(a1[95], "qcom,compute-mon", 0) )
          *(_BYTE *)(v15 + 184) = 1;
        *(_QWORD *)(v15 + 44) = 400;
        *(_QWORD *)(v15 + 68) = 0x61A800000064LL;
        *(_QWORD *)(v15 + 52) = 0;
        *(_QWORD *)(v15 + 60) = 0x138800001388LL;
        v257 = 0;
        v258 = 0;
        v255 = 0;
        v256 = 0;
        v253 = 0;
        v254 = 0;
        v251 = 0;
        v252 = 0;
        v249 = 0;
        v250 = 0;
        if ( (unsigned int)_of_parse_phandle_with_args(v14, "qcom,cpufreq-memfreq-tbl", 0, 0, 0, &v249)
          || (ddr_child_node = v249) == 0 )
        {
          ddr_child_node = a1[95];
        }
        next_child = of_get_next_child(ddr_child_node, 0);
        if ( next_child )
        {
          v50 = next_child;
          v51 = 0;
          do
          {
            v50 = of_get_next_child(ddr_child_node, v50);
            --v51;
          }
          while ( v50 );
          if ( v51 )
            ddr_child_node = qcom_dcvs_get_ddr_child_node(ddr_child_node, 0);
        }
        LODWORD(v249) = 0;
        v259 = 0;
        if ( !of_find_property(ddr_child_node, "qcom,cpufreq-memfreq-tbl", &v249)
          || (v52 = v249, _CF = (unsigned int)v249 >= 4, LODWORD(v249) = (int)v249 >> 2, !_CF)
          || (v52 & 4) != 0
          || (v240 = (unsigned int)(v52 >> 3), v53 = 8LL * ((int)v240 + 1), (v54 = devm_kmalloc(v1, v53, 3520)) == 0) )
        {
LABEL_160:
          *(_QWORD *)(v15 + 32) = 0;
          dev_err(v1, "error importing cpufreq-memfreq table!\n");
          v13 = v242;
          LODWORD(v82) = -22;
          goto LABEL_363;
        }
        v55 = v240;
        v56 = v54;
        if ( (int)v240 < 1 )
        {
          v61 = 0;
        }
        else
        {
          v57 = 0;
          v58 = 0;
          do
          {
            if ( (of_property_read_u32_index(ddr_child_node, "qcom,cpufreq-memfreq-tbl", v58, &v259) & 0x80000000) != 0 )
              goto LABEL_160;
            if ( 8LL * (unsigned int)(v240 + 1) == v57 || (v57 & 0x8000000000000000LL) != 0 || v53 <= v57 )
              goto LABEL_372;
            v59 = v58 + 1;
            *(_DWORD *)(v56 + v57) = v259 / 0x3E8;
            if ( (of_property_read_u32_index(ddr_child_node, "qcom,cpufreq-memfreq-tbl", v59, &v259) & 0x80000000) != 0 )
              goto LABEL_160;
            if ( v53 < v57 + 4 )
              goto LABEL_372;
            v60 = v56 + v57;
            v57 += 8LL;
            v58 = v59 + 1;
            *(_DWORD *)(v60 + 4) = v259;
          }
          while ( 8LL * (unsigned int)v240 != v57 );
          v55 = v240;
          v61 = v240;
        }
        v13 = v242;
        *(_DWORD *)(v15 + 40) = v55;
        if ( v61 >= (int)v240 + 1 )
        {
LABEL_372:
          __break(1u);
          goto LABEL_373;
        }
        *(_DWORD *)(v56 + 8 * v61) = 0;
        *(_QWORD *)(v15 + 32) = v56;
        v89 = *(unsigned __int8 *)(v15 + 184);
        v90 = *(_DWORD *)(v242 + 84);
        *(_DWORD *)(v15 + 76) = v90;
        *(_DWORD *)(v15 + 80) = *(_DWORD *)(v242 + 88);
        *(_DWORD *)(v15 + 84) = v90;
        v91 = (const char *)a1[16];
        if ( v89 == 1 )
        {
          if ( !v91 )
            v91 = *v1;
          v92 = &compute_mon_ktype;
        }
        else
        {
          if ( !v91 )
            v91 = *v1;
          v92 = &memlat_mon_ktype;
        }
        LODWORD(v82) = kobject_init_and_add(v15 + 88, v92, *(_QWORD *)(v242 + 8), v91);
        if ( (v82 & 0x80000000) != 0 )
        {
          dev_err(v1, "failed to init memlat mon kobj: %d\n", v82);
          kobject_put(v15 + 88);
          goto LABEL_363;
        }
        v93 = *(_DWORD *)(v242 + 108);
        *(_DWORD *)(v242 + 108) = v93 + 1;
        *(_DWORD *)(v15 + 188) = v93;
        v94 = _mutex_init(v15 + 192, "&mon->sysfs_lock", &memlat_mon_probe___key);
      }
      if ( *(_DWORD *)(memlat_data + 292) < *(_DWORD *)(memlat_data + 288) )
        goto LABEL_363;
      v95 = *(_QWORD *)(memlat_data + 248);
      if ( v95 )
      {
        if ( *(_DWORD *)(v95 + 108) < *(_DWORD *)(v95 + 104) )
          goto LABEL_363;
      }
      v96 = *(_QWORD *)(memlat_data + 256);
      if ( v96 )
      {
        if ( *(_DWORD *)(v96 + 108) < *(_DWORD *)(v96 + 104) )
          goto LABEL_363;
      }
      v97 = *(_QWORD *)(memlat_data + 264);
      if ( v97 )
      {
        if ( *(_DWORD *)(v97 + 108) < *(_DWORD *)(v97 + 104) )
          goto LABEL_363;
      }
      v98 = *(_QWORD *)(memlat_data + 272);
      if ( v98 )
      {
        if ( *(_DWORD *)(v98 + 108) < *(_DWORD *)(v98 + 104) )
          goto LABEL_363;
      }
      v99 = *(_QWORD *)(memlat_data + 280);
      if ( v99 )
      {
        if ( *(_DWORD *)(v99 + 108) < *(_DWORD *)(v99 + 104) )
          goto LABEL_363;
      }
      *(_BYTE *)(memlat_data + 307) = 1;
      qcom_scmi_device = get_qcom_scmi_device(v94);
      if ( qcom_scmi_device >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_err(v1, "get_qcom_scmi_device ret: %d\n", qcom_scmi_device);
        goto LABEL_363;
      }
      if ( !qcom_scmi_device || (v101 = *(_QWORD *)(qcom_scmi_device + 928)) == 0 )
      {
        v105 = -22;
        goto LABEL_344;
      }
      v102 = *(__int64 (**)(void))(v101 + 24);
      v245 = 0;
      if ( *((_DWORD *)v102 - 1) != -1171826031 )
        __break(0x8228u);
      v103 = v102();
      v104 = (__int64 (__fastcall **)(__int64, unsigned __int64 *, __int64, __int64, __int64))v103;
      if ( v103 >= 0xFFFFFFFFFFFFF001LL )
      {
        v105 = v103;
        if ( (v103 & 0x80000000) == 0 )
          goto LABEL_363;
        goto LABEL_344;
      }
      v243 = v13;
      v244 = v1;
      mutex_lock(&memlat_lock);
      v133 = memlat_data;
      v134 = v245;
      v135 = *(unsigned int *)(memlat_data + 104);
      *(_QWORD *)(memlat_data + 312) = v104;
      *(_QWORD *)(v133 + 320) = v134;
      if ( (_DWORD)v135 )
      {
        cpucp_id = qcom_get_cpucp_id(v135, 0);
        v133 = memlat_data;
        if ( cpucp_id >= 9 )
          v137 = -1;
        else
          v137 = cpucp_id;
      }
      else
      {
        v137 = -1;
      }
      v138 = *(unsigned int *)(v133 + 108);
      if ( (_DWORD)v138 )
      {
        v139 = qcom_get_cpucp_id(v138, 0);
        v133 = memlat_data;
        if ( v139 >= 9 )
          v140 = -1;
        else
          v140 = v139;
      }
      else
      {
        v140 = -1;
      }
      v141 = *(unsigned int *)(v133 + 112);
      if ( (_DWORD)v141 )
      {
        v142 = qcom_get_cpucp_id(v141, 0);
        v133 = memlat_data;
        if ( v142 >= 9 )
          v143 = -1;
        else
          v143 = v142;
      }
      else
      {
        v143 = -1;
      }
      v144 = *(unsigned int *)(v133 + 116);
      if ( (_DWORD)v144 )
      {
        v145 = qcom_get_cpucp_id(v144, 0);
        v133 = memlat_data;
        if ( v145 >= 9 )
          v146 = -1;
        else
          v146 = v145;
      }
      else
      {
        v146 = -1;
      }
      LOBYTE(v250) = v137;
      BYTE1(v250) = v140;
      v249 = 0xFF00000004LL;
      v147 = *(_QWORD *)(v133 + 320);
      BYTE2(v250) = v143;
      BYTE3(v250) = v146;
      v148 = *v104;
      if ( *((_DWORD *)*v104 - 1) != 1737159351 )
        __break(0x8229u);
      v149 = v148(v147, &v249, 0x4D454D4C4154LL, 18, 12);
      if ( (v149 & 0x80000000) != 0 )
      {
        v105 = v149;
        printk(&unk_C36D);
        goto LABEL_361;
      }
      v150 = 0;
      v151 = 0;
      v237 = &unk_CB98;
      v238 = (__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64))v104;
      while ( 1 )
      {
        v239 = v150;
        v152 = *(_QWORD *)(memlat_data + 8 * v150 + 248);
        if ( v152 && *(_BYTE *)(v152 + 28) == 1 )
        {
          v261 = 0;
          LODWORD(v253) = 0;
          v153 = (_DWORD *)v152;
          v251 = 0;
          v252 = 0;
          v155 = *(__int64 (__fastcall ***)(__int64, unsigned __int64 *, __int64, __int64, __int64))(memlat_data + 312);
          v154 = *(_QWORD *)(memlat_data + 320);
          v156 = *(_DWORD *)(v152 + 16);
          v250 = 0;
          v249 = __PAIR64__(v156, _cpu_possible_mask);
          v157 = *v155;
          if ( *((_DWORD *)*v155 - 1) != 1737159351 )
            __break(0x8228u);
          v158 = v157(v154, &v249, 0x4D454D4C4154LL, 16, 36);
          if ( (v158 & 0x80000000) != 0 )
          {
            v105 = v158;
LABEL_371:
            printk(v237);
            v234 = &unk_C731;
            goto LABEL_360;
          }
          v159 = (unsigned int)v153[18];
          v241 = v153;
          if ( (_DWORD)v159 )
          {
            v160 = qcom_get_cpucp_id(v159, 0);
            v161 = v153;
            if ( v160 >= 9 )
              v162 = -1;
            else
              v162 = v160;
          }
          else
          {
            v161 = v153;
            v162 = -1;
          }
          v163 = (unsigned int)v161[19];
          if ( (_DWORD)v163 )
          {
            v164 = qcom_get_cpucp_id(v163, 0);
            v161 = v153;
            if ( v164 >= 9 )
              v165 = -1;
            else
              v165 = v164;
          }
          else
          {
            v165 = -1;
          }
          v166 = (unsigned int)v161[20];
          if ( (_DWORD)v166 )
          {
            v167 = qcom_get_cpucp_id(v166, 0);
            v161 = v153;
            if ( v167 >= 9 )
              v168 = -1;
            else
              v168 = v167;
          }
          else
          {
            v168 = -1;
          }
          v169 = v161[4];
          LOBYTE(v261) = v162;
          BYTE1(v261) = v165;
          v259 = 3;
          v260 = v169;
          BYTE2(v261) = v168;
          v170 = *v155;
          v171 = *(_QWORD *)(memlat_data + 320);
          v172 = v161;
          if ( *((_DWORD *)v170 - 1) != 1737159351 )
            __break(0x8228u);
          v173 = v170(v171, (unsigned __int64 *)&v259, 0x4D454D4C4154LL, 19, 12);
          if ( (v173 & 0x80000000) != 0 )
          {
            v105 = v173;
            v237 = &unk_CDDC;
            goto LABEL_371;
          }
          v174 = v172[27];
          if ( v174 )
          {
            v175 = v172;
            for ( i = 0; i < v174; ++i )
            {
              v177 = *((_QWORD *)v175 + 12) + 240LL * (int)i;
              if ( (*(_BYTE *)(v177 + 16) & 4) != 0 )
              {
                v178 = *(_QWORD *)(v177 + 8);
                LODWORD(v257) = 0;
                v264 = 0;
                v179 = memlat_data;
                v263[0] = 0;
                v263[1] = 0;
                v255 = 0;
                v256 = 0;
                v180 = *(__int64 (__fastcall ***)(__int64, unsigned int *, __int64, __int64, __int64))(memlat_data + 312);
                v253 = 0;
                v254 = 0;
                v251 = 0;
                v252 = 0;
                v249 = 0;
                v250 = 0;
                v181 = *(_DWORD *)(v178 + 16);
                v182 = *(const char ***)v177;
                v259 = *(_DWORD *)(v177 + 20);
                v260 = v181;
                v183 = v182[14];
                v261 = *(unsigned __int8 *)(v177 + 184);
                v262 = *(_DWORD *)(v177 + 188);
                if ( !v183 )
                  v183 = *v182;
                if ( strrchr(v183, 58) != (char *)-1LL )
                {
                  v184 = strrchr(v183, 58);
                  scnprintf(v263, 20, "%s", v184 + 1);
                  v179 = memlat_data;
                }
                v185 = *v180;
                v186 = *(_QWORD *)(v179 + 320);
                if ( *((_DWORD *)*v180 - 1) != 1737159351 )
                  __break(0x8228u);
                v187 = v185(v186, &v259, 0x4D454D4C4154LL, 17, 36);
                if ( (v187 & 0x80000000) != 0 )
                {
                  v105 = v187;
                  v235 = &unk_C3F6;
                  goto LABEL_359;
                }
                v246 = *(_DWORD *)(v178 + 16);
                v188 = *(_QWORD *)(memlat_data + 320);
                v247 = *(_DWORD *)(v177 + 188);
                v248 = *(_DWORD *)(v177 + 44);
                v189 = *v180;
                if ( *((_DWORD *)*v180 - 1) != 1737159351 )
                  __break(0x8228u);
                v190 = v189(v188, &v246, 0x4D454D4C4154LL, 23, 12);
                if ( (v190 & 0x80000000) != 0 )
                {
                  v105 = v190;
                  v235 = &unk_C979;
                  goto LABEL_359;
                }
                v246 = *(_DWORD *)(v178 + 16);
                v191 = *(_QWORD *)(memlat_data + 320);
                v247 = *(_DWORD *)(v177 + 188);
                v248 = *(_DWORD *)(v177 + 48);
                v192 = *v180;
                if ( *((_DWORD *)*v180 - 1) != 1737159351 )
                  __break(0x8228u);
                v193 = v192(v191, &v246, 0x4D454D4C4154LL, 24, 12);
                if ( (v193 & 0x80000000) != 0 )
                {
                  v105 = v193;
                  v235 = &unk_CD0A;
                  goto LABEL_359;
                }
                v246 = *(_DWORD *)(v178 + 16);
                v194 = *(_QWORD *)(memlat_data + 320);
                v247 = *(_DWORD *)(v177 + 188);
                v248 = *(_DWORD *)(v177 + 52);
                v195 = *v180;
                if ( *((_DWORD *)*v180 - 1) != 1737159351 )
                  __break(0x8228u);
                v196 = v195(v194, &v246, 0x4D454D4C4154LL, 25, 12);
                if ( (v196 & 0x80000000) != 0 )
                {
                  v105 = v196;
                  v235 = &unk_CD3E;
                  goto LABEL_359;
                }
                v246 = *(_DWORD *)(v178 + 16);
                v197 = *(_QWORD *)(memlat_data + 320);
                v247 = *(_DWORD *)(v177 + 188);
                v248 = *(_DWORD *)(v177 + 68);
                v198 = *v180;
                if ( *((_DWORD *)*v180 - 1) != 1737159351 )
                  __break(0x8228u);
                v199 = v198(v197, &v246, 0x4D454D4C4154LL, 26, 12);
                if ( (v199 & 0x80000000) != 0 )
                {
                  v105 = v199;
                  v235 = &unk_C44C;
                  goto LABEL_359;
                }
                v246 = *(_DWORD *)(v178 + 16);
                v200 = *(_QWORD *)(memlat_data + 320);
                v247 = *(_DWORD *)(v177 + 188);
                v248 = *(_DWORD *)(v177 + 72);
                v201 = *v180;
                if ( *((_DWORD *)*v180 - 1) != 1737159351 )
                  __break(0x8228u);
                v202 = v201(v200, &v246, 0x4D454D4C4154LL, 27, 12);
                if ( (v202 & 0x80000000) != 0 )
                {
                  v105 = v202;
                  v235 = &unk_CB1F;
                  goto LABEL_359;
                }
                v246 = *(_DWORD *)(v178 + 16);
                v203 = *(_QWORD *)(memlat_data + 320);
                v247 = *(_DWORD *)(v177 + 188);
                v248 = *(_DWORD *)(v177 + 56);
                v204 = *v180;
                if ( *((_DWORD *)*v180 - 1) != 1737159351 )
                  __break(0x8228u);
                v205 = v204(v203, &v246, 0x4D454D4C4154LL, 28, 12);
                if ( (v205 & 0x80000000) != 0 )
                {
                  v105 = v205;
                  v235 = &unk_CC82;
                  goto LABEL_359;
                }
                v246 = *(_DWORD *)(v178 + 16);
                v206 = *(_QWORD *)(memlat_data + 320);
                v247 = *(_DWORD *)(v177 + 188);
                v248 = *(_DWORD *)(v177 + 60);
                v207 = *v180;
                if ( *((_DWORD *)*v180 - 1) != 1737159351 )
                  __break(0x8228u);
                v208 = v207(v206, &v246, 0x4D454D4C4154LL, 29, 12);
                if ( (v208 & 0x80000000) != 0 )
                {
                  v105 = v208;
                  v235 = &unk_CBFE;
                  goto LABEL_359;
                }
                v246 = *(_DWORD *)(v178 + 16);
                v209 = *(_QWORD *)(memlat_data + 320);
                v247 = *(_DWORD *)(v177 + 188);
                v248 = *(_DWORD *)(v177 + 64);
                v210 = *v180;
                if ( *((_DWORD *)*v180 - 1) != 1737159351 )
                  __break(0x8228u);
                v211 = v210(v209, &v246, 0x4D454D4C4154LL, 30, 12);
                if ( (v211 & 0x80000000) != 0 )
                {
                  v105 = v211;
                  v235 = &unk_C9A7;
                  goto LABEL_359;
                }
                LODWORD(v249) = *(_DWORD *)(v178 + 16);
                HIDWORD(v249) = *(_DWORD *)(v177 + 188);
                v212 = *(unsigned int *)(v177 + 40);
                LODWORD(v250) = v212;
                if ( (_DWORD)v212 )
                {
                  v213 = 4 * v212;
                  v214 = 0;
                  v215 = (unsigned int *)(*(_QWORD *)(v177 + 32) + 4LL);
                  while ( v214 != 56 )
                  {
                    *(_WORD *)((char *)&v250 + v214 + 4) = *(v215 - 1);
                    if ( (unsigned __int64)(v214 - 55) < 0xFFFFFFFFFFFFFFBBLL )
                      goto LABEL_372;
                    v217 = *v215;
                    v215 += 2;
                    v216 = v217;
                    v218 = (char *)&v250 + v214 + 4;
                    v214 += 4;
                    v219 = v217 / 0x3E8;
                    if ( v217 > 0x3E8 )
                      v216 = v219;
                    *((_WORD *)v218 + 1) = v216;
                    if ( v213 == v214 )
                      goto LABEL_325;
                  }
LABEL_373:
                  __break(0x5512u);
                }
LABEL_325:
                v220 = (__int64 (__fastcall *)(__int64, unsigned __int64 *, __int64, __int64, __int64))*v180;
                v221 = *(_QWORD *)(memlat_data + 320);
                if ( *((_DWORD *)*v180 - 1) != 1737159351 )
                  __break(0x8229u);
                v222 = v220(v221, &v249, 0x4D454D4C4154LL, 32, 68);
                if ( (v222 & 0x80000000) != 0 )
                {
                  v105 = v222;
                  v235 = &unk_C83A;
                  goto LABEL_359;
                }
                v246 = *(_DWORD *)(v178 + 16);
                v223 = *(_QWORD *)(memlat_data + 320);
                v247 = *(_DWORD *)(v177 + 188);
                v248 = *(_DWORD *)(v177 + 76);
                v224 = *v180;
                if ( *((_DWORD *)*v180 - 1) != 1737159351 )
                  __break(0x8228u);
                v225 = v224(v223, &v246, 0x4D454D4C4154LL, 33, 12);
                if ( (v225 & 0x80000000) != 0 )
                {
                  v105 = v225;
                  v235 = &unk_CE79;
                  goto LABEL_359;
                }
                v246 = *(_DWORD *)(v178 + 16);
                v226 = *(_QWORD *)(memlat_data + 320);
                v247 = *(_DWORD *)(v177 + 188);
                v248 = *(_DWORD *)(v177 + 80);
                v227 = *v180;
                if ( *((_DWORD *)*v180 - 1) != 1737159351 )
                  __break(0x8228u);
                v228 = v227(v226, &v246, 0x4D454D4C4154LL, 34, 12);
                if ( (v228 & 0x80000000) != 0 )
                {
                  v105 = v228;
                  v235 = &unk_CEA7;
LABEL_359:
                  printk(v235);
                  v234 = &unk_CE4D;
LABEL_360:
                  printk(v234);
LABEL_361:
                  *(_QWORD *)(memlat_data + 312) = 0;
LABEL_362:
                  mutex_unlock(&memlat_lock);
                  v13 = v243;
                  v1 = v244;
                  if ( (v105 & 0x80000000) == 0 )
                  {
LABEL_363:
                    mutex_unlock(v13 + 112);
LABEL_364:
                    if ( (v82 & 0x80000000) != 0 )
                      goto LABEL_366;
                    goto LABEL_365;
                  }
LABEL_344:
                  dev_err(v1, "Err during cpucp_memlat_init: %d\n", v105);
                  goto LABEL_363;
                }
                v175 = v241;
                v151 = 1;
                v174 = v241[27];
              }
            }
          }
        }
        ++v150;
        if ( v239 == 4 )
        {
          v229 = *v238;
          v230 = *(_QWORD *)(memlat_data + 320);
          v231 = memlat_data + 160;
          if ( *((_DWORD *)*v238 - 1) != 1737159351 )
            __break(0x8229u);
          v105 = v229(v230, v231, 0x4D454D4C4154LL, 31, 4);
          if ( (v105 & 0x80000000) != 0 )
          {
            v234 = &unk_C8EE;
            goto LABEL_360;
          }
          if ( (v151 & 1) != 0 )
          {
            v232 = v238[2];
            v233 = *(_QWORD *)(memlat_data + 320);
            if ( *((_DWORD *)v232 - 1) != 1737159351 )
              __break(0x8229u);
            v105 = v232(v233, 0, 0x4D454D4C4154LL, 36, 0);
            if ( (v105 & 0x80000000) != 0 )
            {
              v234 = &unk_CEF3;
              goto LABEL_360;
            }
          }
          goto LABEL_362;
        }
      }
    }
    dev_err(v1, "Mon probe called without memlat_grp inited.\n");
    goto LABEL_237;
  }
  if ( v4 != 1 )
  {
    if ( !v4 )
    {
      if ( memlat_data )
        match_data = (int *)dev_err(v1, "only one memlat device allowed\n");
      LODWORD(v249) = 0;
      v5 = get_qcom_scmi_device(match_data);
      if ( v5 >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( (_DWORD)v5 == -517 )
        {
          LODWORD(v82) = -517;
          goto LABEL_366;
        }
        dev_err(v1, "Error getting scmi_dev ret = %d\n", v5);
      }
      v6 = devm_kmalloc(v1, 336, 3520);
      if ( v6 )
      {
        v7 = a1[95];
        v8 = (_DWORD *)v6;
        *(_QWORD *)v6 = v1;
        *(_DWORD *)(v6 + 160) = 8;
        next_available_child = of_get_next_available_child(v7, 0);
        if ( next_available_child )
        {
          v10 = next_available_child;
          v11 = 0;
          do
          {
            v10 = of_get_next_available_child(v7, v10);
            --v11;
          }
          while ( v10 );
          v8[72] = -v11;
          if ( v11 )
          {
            if ( (of_property_read_variable_u32_array(a1[95], "qcom,inst-ev", &v249, 1, 0) & 0x80000000) != 0 )
            {
              v12 = 8;
              LODWORD(v249) = 8;
            }
            else
            {
              v12 = v249;
            }
            v70 = a1[95];
            v8[26] = v12;
            if ( (of_property_read_variable_u32_array(v70, "qcom,cyc-ev", &v249, 1, 0) & 0x80000000) != 0 )
            {
              v71 = 17;
              LODWORD(v249) = 17;
            }
            else
            {
              v71 = v249;
            }
            v72 = a1[95];
            v8[27] = v71;
            if ( (of_property_read_variable_u32_array(v72, "qcom,fe-stall-ev", &v249, 1, 0) & 0x80000000) == 0 )
              v8[28] = v249;
            if ( (of_property_read_variable_u32_array(a1[95], "qcom,be-stall-ev", &v249, 1, 0) & 0x80000000) == 0 )
              v8[29] = v249;
            v73 = 0;
            do
            {
              v74 = (unsigned int)(-1LL << v73) & _cpu_possible_mask;
              if ( !(_DWORD)v74 )
                break;
              LODWORD(v249) = v12;
              v75 = __clz(__rbit64(v74));
              if ( v12 )
              {
                v76 = qcom_pmu_event_supported(v12, (unsigned int)v75);
                if ( v76 )
                {
                  LODWORD(v82) = v76;
                  if ( v76 == -517 )
                    goto LABEL_366;
                  dev_err(v1, "ev=%u not found on cpu%d: %d\n", v249, v75, v76);
                  if ( (_DWORD)v249 == 8 || (_DWORD)v249 == 17 )
                    goto LABEL_364;
                }
              }
              LODWORD(v249) = v71;
              if ( v71 )
              {
                v77 = qcom_pmu_event_supported(v71, (unsigned int)v75);
                if ( v77 )
                {
                  LODWORD(v82) = v77;
                  if ( v77 == -517 )
                    goto LABEL_366;
                  dev_err(v1, "ev=%u not found on cpu%d: %d\n", v249, v75, v77);
                  if ( (_DWORD)v249 == 8 || (_DWORD)v249 == 17 )
                    goto LABEL_364;
                }
              }
              v78 = (unsigned int)v8[28];
              LODWORD(v249) = v78;
              if ( (_DWORD)v78 )
              {
                v79 = qcom_pmu_event_supported(v78, (unsigned int)v75);
                if ( v79 )
                {
                  LODWORD(v82) = v79;
                  if ( v79 == -517 )
                    goto LABEL_366;
                  dev_err(v1, "ev=%u not found on cpu%d: %d\n", v249, v75, v79);
                  if ( (_DWORD)v249 == 8 || (_DWORD)v249 == 17 )
                    goto LABEL_364;
                }
              }
              v80 = (unsigned int)v8[29];
              LODWORD(v249) = v80;
              if ( (_DWORD)v80 )
              {
                v81 = qcom_pmu_event_supported(v80, (unsigned int)v75);
                if ( v81 )
                {
                  LODWORD(v82) = v81;
                  if ( v81 == -517 )
                    goto LABEL_366;
                  dev_err(v1, "ev=%u not found on cpu%d: %d\n", v249, v75, v81);
                  if ( (_DWORD)v249 == 8 || (_DWORD)v249 == 17 )
                    goto LABEL_364;
                }
              }
              v73 = v75 + 1;
            }
            while ( v75 < 0x1F );
            v82 = qcom_dcvs_kobject_get(5);
            if ( v82 >= 0xFFFFFFFFFFFFF001LL )
            {
              dev_err(v1, "error getting kobj from qcom_dcvs: %d\n", v82);
              goto LABEL_364;
            }
            v83 = kobject_init_and_add(v8 + 2, &memlat_settings_ktype, v82, "memlat_settings");
            if ( v83 < 0 )
            {
              LODWORD(v82) = v83;
              dev_err(v1, "failed to init memlat settings kobj: %d\n", v83);
              kobject_put(v8 + 2);
              goto LABEL_366;
            }
            memlat_data = (__int64)v8;
            v84 = a1[95];
            v85 = of_get_next_available_child(v84, 0);
            if ( !v85 )
              goto LABEL_365;
            v86 = v85;
            v87 = 0;
            do
            {
              v86 = of_get_next_available_child(v84, v86);
              --v87;
            }
            while ( v86 );
            if ( !v87 )
            {
LABEL_365:
              LODWORD(v82) = 0;
              goto LABEL_367;
            }
            v88 = a1[95];
LABEL_212:
            of_platform_populate(v88, 0, 0, v1);
            goto LABEL_365;
          }
        }
        else
        {
          v8[72] = 0;
        }
        dev_err(v1, "No memlat grps provided!\n");
LABEL_237:
        LODWORD(v82) = -19;
        goto LABEL_366;
      }
LABEL_213:
      LODWORD(v82) = -12;
      goto LABEL_366;
    }
LABEL_156:
    dev_err(v1, "Invalid memlat mon type specified: %u\n", v4);
    LODWORD(v82) = -22;
    goto LABEL_367;
  }
  v28 = a1[95];
  v259 = 0;
  v246 = 3;
  LODWORD(v245) = 3;
  v257 = 0;
  v258 = 0;
  v255 = 0;
  v256 = 0;
  v253 = 0;
  v254 = 0;
  v251 = 0;
  v252 = 0;
  v249 = 0;
  v250 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v28, "qcom,target-dev", 0, 0, 0, &v249) || !v249 )
  {
    dev_err(v1, "Unable to find target-dev for grp\n");
LABEL_234:
    LODWORD(v82) = -22;
    goto LABEL_366;
  }
  v29 = of_property_read_variable_u32_array(v249, "qcom,dcvs-hw-type", &v246, 1, 0);
  if ( v29 < 0 || v246 >= 5 )
  {
    dev_err(v1, "invalid dcvs hw_type=%d, ret=%d\n", v246, v29 & (unsigned int)(v29 >> 31));
    goto LABEL_234;
  }
  v30 = devm_kmalloc(v1, 304, 3520);
  if ( !v30 )
    goto LABEL_213;
  v31 = v30;
  v32 = v246;
  *(_QWORD *)v31 = v1;
  *(_DWORD *)(v31 + 16) = v32;
  v33 = ((__int64 (*)(void))qcom_dcvs_kobject_get)();
  *(_QWORD *)(v31 + 8) = v33;
  if ( v33 >= 0xFFFFFFFFFFFFF001LL )
  {
    v34 = v33;
    v35 = "error getting kobj from qcom_dcvs\n";
    v36 = v1;
    goto LABEL_158;
  }
  v62 = qcom_dcvs_hw_minmax_get(v246, v31 + 84, v31 + 88);
  if ( (v62 & 0x80000000) != 0 )
  {
    v34 = v62;
    v35 = "error getting minmax from qcom_dcvs\n";
    v36 = v1;
LABEL_158:
    LODWORD(v82) = dev_err_probe(v36, v34, v35);
    if ( (_DWORD)v82 )
      goto LABEL_364;
LABEL_207:
    v129 = a1[95];
    v130 = of_get_next_available_child(v129, 0);
    if ( !v130 )
      goto LABEL_365;
    v131 = v130;
    v132 = 0;
    do
    {
      v131 = of_get_next_available_child(v129, v131);
      --v132;
    }
    while ( v131 );
    if ( !v132 )
      goto LABEL_365;
    v88 = a1[95];
    goto LABEL_212;
  }
  v63 = a1[95];
  v257 = 0;
  v258 = 0;
  v255 = 0;
  v256 = 0;
  v253 = 0;
  v254 = 0;
  v251 = 0;
  v252 = 0;
  v249 = 0;
  v250 = 0;
  v64 = _of_parse_phandle_with_args(v63, "qcom,sampling-path", 0, 0, 0, &v249);
  v65 = 3;
  if ( !v64 && v249 )
  {
    v66 = of_property_read_variable_u32_array(v249, "qcom,dcvs-path-type", &v245, 1, 0);
    v67 = (unsigned int)v245;
    if ( v66 < 0 || (unsigned int)v245 >= 3 )
    {
LABEL_233:
      dev_err(v1, "invalid dcvs path: %d, ret=%d\n", v67, v66 & (unsigned int)(v66 >> 31));
      goto LABEL_234;
    }
    if ( (_DWORD)v245 == 1 )
    {
      v68 = v246;
      v69 = "memlat_fp";
    }
    else
    {
      v69 = (const char *)a1[16];
      if ( !v69 )
        v69 = *v1;
      v68 = v246;
    }
    LODWORD(v82) = qcom_dcvs_register_voter(v69, v68);
    if ( (v82 & 0x80000000) != 0 )
    {
      dev_err(v1, "qcom dcvs registration error: %d\n", v82);
      goto LABEL_366;
    }
    v65 = v245;
  }
  v106 = a1[95];
  *(_DWORD *)(v31 + 20) = v65;
  v257 = 0;
  v258 = 0;
  v255 = 0;
  v256 = 0;
  v253 = 0;
  v254 = 0;
  v251 = 0;
  v252 = 0;
  v249 = 0;
  v250 = 0;
  if ( !(unsigned int)_of_parse_phandle_with_args(v106, "qcom,threadlat-path", 0, 0, 0, &v249) && v249 )
  {
    v66 = of_property_read_variable_u32_array(v249, "qcom,dcvs-path-type", &v245, 1, 0);
    v67 = (unsigned int)v245;
    if ( (v66 & 0x80000000) == 0 && (unsigned int)v245 < 3 )
    {
      v107 = *(_DWORD *)(v31 + 20);
      *(_DWORD *)(v31 + 24) = v245;
      if ( v107 != 1 && (_DWORD)v67 != 1 )
        goto LABEL_181;
      goto LABEL_177;
    }
    goto LABEL_233;
  }
  v108 = v245;
  *(_DWORD *)(v31 + 24) = 3;
  if ( v108 >= 3 )
  {
    dev_err(v1, "error: no dcvs voting paths\n");
    goto LABEL_237;
  }
  if ( *(_DWORD *)(v31 + 20) == 1 )
  {
LABEL_177:
    v109 = _cpu_possible_mask;
    *(_BYTE *)(v31 + 52) = 1;
    v110 = _sw_hweight64(v109);
    if ( v110 <= 8 )
      v111 = 8;
    else
      v111 = v110;
    *(_QWORD *)(v31 + 64) = devm_kmalloc(v1, 4LL * (unsigned int)(v111 + 1), 3520);
  }
LABEL_181:
  v112 = a1[95];
  v113 = of_get_next_available_child(v112, 0);
  if ( !v113 )
    goto LABEL_227;
  v114 = v113;
  v115 = 0;
  do
  {
    ++v115;
    v114 = of_get_next_available_child(v112, v114);
  }
  while ( v114 );
  if ( !v115 )
  {
LABEL_227:
    dev_err(v1, "No mons provided!\n");
    goto LABEL_237;
  }
  v116 = devm_kmalloc(v1, 240LL * v115, 3520);
  *(_QWORD *)(v31 + 96) = v116;
  if ( !v116 )
    goto LABEL_213;
  *(_DWORD *)(v31 + 104) = v115;
  *(_DWORD *)(v31 + 108) = 0;
  _mutex_init(v31 + 112, "&memlat_grp->mons_lock", &memlat_grp_probe___key);
  _mutex_init(v31 + 160, "&memlat_grp->sysfs_lock", &memlat_grp_probe___key_49);
  v117 = of_property_read_variable_u32_array(a1[95], "qcom,miss-ev", &v259, 1, 0);
  if ( v117 < 0 )
  {
    dev_err(v1, "Cache miss event missing for grp: %d\n", v117);
    goto LABEL_234;
  }
  v118 = a1[95];
  *(_DWORD *)(v31 + 72) = v259;
  if ( (of_property_read_variable_u32_array(v118, "qcom,access-ev", &v259, 1, 0) & 0x80000000) == 0 )
    *(_DWORD *)(v31 + 80) = v259;
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,wb-ev", &v259, 1, 0) & 0x80000000) == 0 )
    *(_DWORD *)(v31 + 76) = v259;
  v119 = 0;
  while ( 1 )
  {
    v120 = (unsigned int)(-1LL << v119) & _cpu_possible_mask;
    if ( !(_DWORD)v120 )
    {
LABEL_202:
      kobject_init_and_add(v31 + 208, &memlat_grp_ktype, *(_QWORD *)(v31 + 8), "memlat");
      v126 = mutex_lock(&memlat_lock);
      v127 = memlat_data;
      v128 = v246;
      v47 = v246 > 4;
      ++*(_DWORD *)(memlat_data + 292);
      if ( v47 )
        goto LABEL_373;
      *(_QWORD *)(v127 + 8 * v128 + 248) = v31;
      if ( (*(_BYTE *)(v127 + 304) & 1) == 0 && (should_enable_memlat_fp(v126) & 1) != 0 )
      {
        *(_QWORD *)(v127 + 296) = 0;
        *(_BYTE *)(v127 + 304) = 1;
      }
      mutex_unlock(&memlat_lock);
      a1[21] = v31;
      goto LABEL_207;
    }
    v121 = *(unsigned int *)(v31 + 72);
    v122 = __clz(__rbit64(v120));
    v259 = v121;
    if ( (_DWORD)v121 )
    {
      v123 = qcom_pmu_event_supported(v121, (unsigned int)v122);
      if ( v123 )
        break;
    }
    v124 = *(unsigned int *)(v31 + 76);
    v259 = v124;
    if ( (_DWORD)v124 )
    {
      v123 = qcom_pmu_event_supported(v124, (unsigned int)v122);
      if ( v123 )
        break;
    }
    v125 = *(unsigned int *)(v31 + 80);
    v259 = v125;
    if ( (_DWORD)v125 )
    {
      v123 = qcom_pmu_event_supported(v125, (unsigned int)v122);
      if ( v123 )
        break;
    }
    v119 = v122 + 1;
    if ( v122 >= 0x1F )
      goto LABEL_202;
  }
  LODWORD(v82) = v123;
  if ( v123 != -517 )
  {
    dev_err(v1, "ev=%d not found on cpu%d: %d\n", v259, v122, v123);
    goto LABEL_364;
  }
LABEL_366:
  dev_err(v1, "Failure to probe memlat device: %d\n", v82);
LABEL_367:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v82;
}
