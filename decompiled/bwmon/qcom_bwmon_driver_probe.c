__int64 __fastcall qcom_bwmon_driver_probe(__int64 a1)
{
  const char **v1; // x25
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 match_data; // x0
  __int64 property; // x22
  _QWORD *resource_byname; // x0
  __int64 v8; // x11
  __int64 v9; // x9
  __int64 v10; // x2
  __int64 v11; // x0
  _QWORD *v12; // x0
  __int64 v13; // x11
  __int64 v14; // x9
  __int64 v15; // x2
  __int64 v16; // x0
  int v17; // w0
  int irq; // w0
  __int64 v19; // x8
  int variable_u32_array; // w0
  unsigned int v21; // w8
  unsigned __int64 v22; // x23
  char v23; // w9
  char v24; // w8
  unsigned int v25; // w9
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 (__fastcall *v28)(); // x10
  __int64 (__fastcall *v29)(); // x11
  __int64 v30; // x12
  __int64 v31; // x22
  char v32; // w14
  int v33; // w13
  const char *v34; // x1
  unsigned __int64 v40; // x17
  unsigned __int64 v42; // x14
  unsigned __int64 v43; // x14
  char *v44; // x15
  int *v45; // x15
  int v46; // t1
  __int64 v47; // x0
  __int64 v48; // x23
  int v49; // w0
  int v50; // w0
  __int64 v51; // x2
  __int64 v52; // x0
  __int64 v53; // x23
  __int64 v54; // x0
  __int64 v55; // x20
  int v56; // w0
  int v57; // w8
  unsigned __int64 v58; // x26
  __int64 v59; // x0
  __int64 v60; // x25
  unsigned __int64 v61; // x24
  unsigned int v62; // w28
  unsigned int v63; // w28
  unsigned __int64 v64; // x8
  unsigned __int64 v65; // x9
  int v66; // w0
  const char *v67; // x3
  const char *v68; // x0
  unsigned int v69; // w0
  const char *v70; // x0
  unsigned int v71; // w0
  __int64 v72; // x0
  __int64 v73; // x23
  __int64 v74; // x9
  _QWORD *v75; // x1
  int *v76; // x23
  unsigned int v77; // w0
  int v78; // w8
  int v79; // w9
  unsigned int v80; // w8
  __int64 v81; // x8
  __int64 v82; // x8
  int v83; // w9
  __int64 v84; // x9
  __int64 v85; // x24
  __int64 v86; // x0
  __int64 v87; // x20
  __int64 v88; // x0
  __int64 (__fastcall *v89)(_QWORD); // x9
  int v90; // w0
  const char *v91; // x3
  int v92; // w0
  __int64 v93; // x20
  void (__fastcall *v94)(_QWORD); // x8
  __int64 v95; // x0
  _QWORD *v96; // x10
  __int64 *v97; // x8
  __int64 v98; // x9
  __int64 v99; // x11
  unsigned __int64 v101; // [xsp+18h] [xbp-78h]
  const char **v102; // [xsp+20h] [xbp-70h]
  int v103; // [xsp+28h] [xbp-68h] BYREF
  unsigned int v104; // [xsp+2Ch] [xbp-64h] BYREF
  unsigned int v105; // [xsp+30h] [xbp-60h] BYREF
  int v106; // [xsp+34h] [xbp-5Ch] BYREF
  __int64 v107; // [xsp+38h] [xbp-58h] BYREF
  __int64 v108; // [xsp+40h] [xbp-50h]
  __int64 v109; // [xsp+48h] [xbp-48h]
  __int64 v110; // [xsp+50h] [xbp-40h]
  __int64 v111; // [xsp+58h] [xbp-38h]
  __int64 v112; // [xsp+60h] [xbp-30h]
  __int64 v113; // [xsp+68h] [xbp-28h]
  __int64 v114; // [xsp+70h] [xbp-20h]
  __int64 v115; // [xsp+78h] [xbp-18h]
  __int64 v116; // [xsp+80h] [xbp-10h]
  __int64 v117; // [xsp+88h] [xbp-8h]

  v1 = (const char **)(a1 + 16);
  v117 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = devm_kmalloc(a1 + 16, 328, 3520);
  if ( v3 )
  {
    v4 = v3;
    *(_QWORD *)(v3 + 32) = v1;
    *(_QWORD *)(v3 + 96) = v1;
    LODWORD(v107) = 0;
    match_data = of_device_get_match_data(v1);
    *(_QWORD *)(v4 + 24) = match_data;
    if ( !match_data )
    {
      dev_err(v1, "Unknown device type!\n");
      LODWORD(v22) = -19;
      goto LABEL_146;
    }
    property = of_find_property(*(_QWORD *)(a1 + 760), "qcom,map-ne", 0);
    resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, "base");
    if ( !resource_byname )
    {
      dev_err(v1, "base not found!\n");
      goto LABEL_128;
    }
    v8 = 0x68000000000713LL;
    v9 = 0x68000000000F0FLL;
    if ( arm64_use_ng_mappings )
      v8 = 0x68000000000F13LL;
    else
      v9 = 0x6800000000070FLL;
    if ( property )
      v10 = v9;
    else
      v10 = v8;
    v11 = ioremap_prot(*resource_byname, resource_byname[1] - *resource_byname + 1LL, v10);
    *(_QWORD *)v4 = v11;
    if ( v11 )
    {
      if ( *(_BYTE *)(*(_QWORD *)(v4 + 24) + 4LL) != 1 )
      {
LABEL_22:
        irq = platform_get_irq(a1, 0);
        *(_DWORD *)(v4 + 20) = irq;
        if ( irq < 0 )
        {
          dev_err(v1, "Unable to get IRQ number\n");
          LODWORD(v22) = *(_DWORD *)(v4 + 20);
          if ( (v22 & 0x80000000) != 0 )
            goto LABEL_146;
        }
        v19 = *(_QWORD *)(v4 + 24);
        LODWORD(v107) = 0;
        if ( *(_BYTE *)(v19 + 3) == 1 )
        {
          variable_u32_array = of_property_read_variable_u32_array(
                                 *(_QWORD *)(a1 + 760),
                                 "qcom,hw-timer-hz",
                                 v4 + 296,
                                 1,
                                 0);
          if ( variable_u32_array < 0 )
          {
            LODWORD(v22) = variable_u32_array;
            dev_err(v1, "HW sampling rate not specified!\n");
            goto LABEL_146;
          }
        }
        if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,count-unit", &v107, 1, 0) & 0x80000000) != 0 )
        {
          v21 = 0x100000;
          LODWORD(v107) = 0x100000;
        }
        else
        {
          v21 = v107;
        }
        v23 = 64 - __clz(v21 - 1LL);
        if ( v21 <= 1 )
          v24 = 0;
        else
          v24 = v23;
        v25 = 0xFFFFFFFF >> v24;
        *(_BYTE *)(v4 + 312) = v24;
        v26 = *(_QWORD *)(v4 + 24);
        *(_DWORD *)(v4 + 316) = v25;
        v27 = *(unsigned int *)(v26 + 8);
        if ( (unsigned int)v27 <= 2 )
        {
          v28 = off_CD58[v27];
          v29 = off_CD70[v27];
          v30 = (__int64)*(&off_CD88 + v27);
          *(_QWORD *)(v4 + 40) = off_CD40[v27];
          *(_QWORD *)(v4 + 48) = v28;
          *(_QWORD *)(v4 + 72) = v29;
          *(_QWORD *)(v4 + v30) = *(&off_CDA0 + v27);
        }
        v31 = v4 + 40;
        of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,byte-mid-match", v4 + 324, 1, 0);
        of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,byte-mid-mask", v4 + 320, 1, 0);
        if ( *(_BYTE *)(*(_QWORD *)(v4 + 24) + 2LL) == 1 )
        {
          *(_QWORD *)(v4 + 80) = mon_set_throttle_adj;
          *(_QWORD *)(v4 + 88) = mon_get_throttle_adj;
        }
        v32 = 0;
        v33 = -1;
        do
        {
          v42 = (unsigned int)(-1LL << v32) & _cpu_possible_mask;
          if ( !(_DWORD)v42 )
            break;
          v43 = __clz(__rbit64(v42));
          v44 = (char *)&cpu_topology + 48 * (unsigned int)v43;
          v46 = *((_DWORD *)v44 + 2);
          v45 = (int *)(v44 + 8);
          if ( v46 != v33 )
          {
            _X16 = (unsigned __int64 *)(v4 + 208);
            __asm { PRFM            #0x11, [X16] }
            do
              v40 = __ldxr(_X16);
            while ( __stxr(v40 | (1LL << v43), _X16) );
            v33 = *v45;
          }
          _CF = v43 >= 0x1F;
          v32 = v43 + 1;
        }
        while ( !_CF );
        v47 = *(_QWORD *)(a1 + 760);
        *(_BYTE *)(v4 + 264) = 0;
        v104 = 3;
        v105 = 3;
        v103 = 0;
        v115 = 0;
        v116 = 0;
        v113 = 0;
        v114 = 0;
        v111 = 0;
        v112 = 0;
        v109 = 0;
        v110 = 0;
        v107 = 0;
        v108 = 0;
        if ( !(unsigned int)_of_parse_phandle_with_args(v47, "qcom,target-dev", 0, 0, 0, &v107) )
        {
          v48 = v107;
          if ( v107 )
          {
            v49 = of_property_read_variable_u32_array(v107, "qcom,dcvs-hw-type", &v105, 1, 0);
            v103 = v49 & (v49 >> 31);
            if ( v49 < 0 || v105 >= 5 )
            {
              dev_err(v1, "invalid dcvs_hw=%d, ret=%d\n", v105);
            }
            else
            {
              *(_DWORD *)(v4 + 104) = v105;
              v50 = of_property_read_variable_u32_array(v48, "qcom,bus-width", v4 + 112, 1, 0);
              v51 = *(unsigned int *)(v4 + 112);
              v103 = v50 & (v50 >> 31);
              if ( v50 < 0 || !(_DWORD)v51 )
              {
                dev_err(v1, "invalid hw width=%d, ret=%d\n", v51);
              }
              else
              {
                v52 = *(_QWORD *)(a1 + 760);
                *(_DWORD *)(v4 + 108) = 0;
                v115 = 0;
                v116 = 0;
                v113 = 0;
                v114 = 0;
                v111 = 0;
                v112 = 0;
                v109 = 0;
                v110 = 0;
                v107 = 0;
                v108 = 0;
                if ( (unsigned int)_of_parse_phandle_with_args(v52, "qcom,second-vote", 0, 0, 0, &v107)
                  || (v53 = v107) == 0 )
                {
LABEL_90:
                  v68 = *(const char **)(a1 + 128);
                  if ( !v68 )
                    v68 = *v1;
                  v69 = qcom_dcvs_register_voter(v68, v105, *(unsigned int *)(v4 + 108));
                  v103 = v69;
                  if ( (v69 & 0x80000000) == 0 )
                  {
                    if ( *(_BYTE *)(v4 + 124) != 1 )
                      goto LABEL_97;
                    v70 = *(const char **)(a1 + 128);
                    if ( !v70 )
                      v70 = *v1;
                    v71 = qcom_dcvs_register_voter(v70, v104, 0);
                    v103 = v71;
                    if ( (v71 & 0x80000000) != 0 )
                    {
                      dev_err(v1, "second hw qcom dcvs reg err: %d\n", v71);
                    }
                    else
                    {
LABEL_97:
                      v72 = devm_kmalloc(*(_QWORD *)(v4 + 96), 544, 3520);
                      if ( v72 )
                      {
                        v73 = v72;
                        *(_QWORD *)(v4 + 216) = v72;
                        *(_QWORD *)(v72 + 108) = 0x32000000BELL;
                        *(_QWORD *)(v72 + 140) = 0;
                        *(_QWORD *)(v72 + 40) = 0x6400000032LL;
                        *(_QWORD *)(v72 + 48) = 0x100000005ALL;
                        *(_QWORD *)(v72 + 116) = 0xA00000000LL;
                        *(_QWORD *)(v72 + 124) = 0x300000000LL;
                        *(_QWORD *)(v72 + 132) = 0x300000000LL;
                        *(_DWORD *)(v72 + 164) = 0;
                        *(_QWORD *)(v72 + 148) = 0x5DC00000190LL;
                        *(_QWORD *)(v72 + 156) = 100;
                        *(_QWORD *)(v72 + 344) = v31;
                        _mutex_init(v72 + 448, "&node->mon_lock", &configure_hwmon_node___key);
                        _mutex_init(v73 + 496, "&node->update_lock", &configure_hwmon_node___key_45);
                        v74 = raw_spin_lock_irqsave(&list_lock);
                        v75 = off_160;
                        if ( off_160 == (_UNKNOWN **)(v73 + 328) || *off_160 != (_UNKNOWN *)&hwmon_list )
                        {
                          _list_add_valid_or_report(v73 + 328);
                        }
                        else
                        {
                          off_160 = (_UNKNOWN **)(v73 + 328);
                          *(_QWORD *)(v73 + 328) = &hwmon_list;
                          *(_QWORD *)(v73 + 336) = v75;
                          *v75 = v73 + 328;
                        }
                        raw_spin_unlock_irqrestore(&list_lock, v74);
                        v76 = *(int **)(v4 + 216);
                        v103 = 0;
                        v77 = qcom_dcvs_hw_minmax_get(v105, v76, v76 + 1);
                        v103 = v77;
                        if ( (v77 & 0x80000000) == 0 )
                        {
                          v78 = *v76;
                          v79 = v76[1];
                          v76[2] = *v76;
                          v76[3] = v79;
                          v76[4] = v78;
                          v76[5] = 0;
                          v80 = v104;
                          v76[6] = v105;
                          v76[9] = v80;
                          v81 = *(_QWORD *)(v4 + 200);
                          if ( v81 )
                          {
                            v82 = v81 - 4;
                            do
                            {
                              v83 = *(_DWORD *)(v82 + 4);
                              v82 += 8;
                            }
                            while ( (unsigned int)(v83 + 1) > 1 );
                            _ZF = v83 == 0;
                            v84 = -8;
                            if ( !_ZF )
                              v84 = 0;
                            *(_DWORD *)(v4 + 128) = *(_DWORD *)(v82 + v84);
                          }
                          goto LABEL_108;
                        }
                        dev_err(v1, "error getting minmax from qcom dcvs: %d\n", v77);
                      }
                      else
                      {
                        v103 = -12;
                        dev_err(v1, "bwmon node configuration failed: %d\n", 4294967284LL);
                      }
                    }
LABEL_135:
                    LODWORD(v22) = v103;
                    if ( v103 < 0 )
                      goto LABEL_146;
LABEL_108:
                    v85 = *(_QWORD *)(v4 + 216);
                    mutex_lock(&bwmon_lock);
                    if ( !bwmon_wq )
                    {
                      bwmon_wq = alloc_workqueue("%s", (const char *)0x4000E);
                      if ( !bwmon_wq )
                      {
                        dev_err(v1, "Couldn't create bwmon workqueue.\n");
                        mutex_unlock(&bwmon_lock);
                        LODWORD(v22) = -12;
                        goto LABEL_140;
                      }
                      tracepoint_probe_register(&_tracepoint_android_vh_jiffies_update, &bwmon_jiffies_update_cb, 0);
                    }
                    v86 = mutex_unlock(&bwmon_lock);
                    v87 = *(_QWORD *)(v4 + 216);
                    v88 = ktime_get(v86);
                    *(_QWORD *)(v87 + 208) = 0;
                    *(_QWORD *)(v87 + 304) = v88;
                    v89 = *(__int64 (__fastcall **)(_QWORD))(v4 + 40);
                    *(_QWORD *)(v4 + 272) = (((((1000 * *(_DWORD *)(v4 + 112)) & 0xFFFF8)
                                             * (unsigned __int64)*(unsigned int *)(v87 + 16)) >> 20)
                                           + (unsigned int)((1000 * (unsigned __int64)*(unsigned int *)(v4 + 112)) >> 20)
                                           * (unsigned __int64)*(unsigned int *)(v87 + 16))
                                          * *(unsigned int *)(v87 + 52)
                                          / 0x64;
                    *(_QWORD *)(v4 + 280) = *(unsigned int *)(v87 + 152);
                    if ( *((_DWORD *)v89 - 1) != 475781791 )
                      __break(0x8229u);
                    v90 = v89(v31);
                    if ( v90 < 0 )
                    {
                      LODWORD(v22) = v90;
                      dev_err(*(_QWORD *)(v4 + 96), "Unable to start HW monitor! (%d)\n", v90);
                      dev_err(v1, "Error starting BWMON monitor: %d\n", (unsigned int)v22);
                    }
                    else
                    {
                      *(_BYTE *)(v87 + 321) = 1;
                      v22 = qcom_dcvs_kobject_get(*(unsigned int *)(v4 + 104));
                      if ( v22 >= 0xFFFFFFFFFFFFF001LL )
                      {
                        dev_err(v1, "error getting kobj from qcom_dcvs: %d\n", (unsigned int)v22);
                      }
                      else
                      {
                        v91 = *(const char **)(a1 + 128);
                        if ( !v91 )
                          v91 = *v1;
                        v92 = kobject_init_and_add(v85 + 352, &bwmon_ktype, v22, v91);
                        if ( (v92 & 0x80000000) == 0 )
                        {
                          LODWORD(v22) = 0;
                          goto LABEL_147;
                        }
                        LODWORD(v22) = v92;
                        dev_err(v1, "failed to init bwmon kobj: %d\n", v92);
                        kobject_put(v85 + 352);
                      }
                    }
LABEL_140:
                    v93 = *(_QWORD *)(v4 + 216);
                    mutex_lock(v93 + 448);
                    *(_BYTE *)(v93 + 321) = 0;
                    mutex_unlock(v93 + 448);
                    v94 = *(void (__fastcall **)(_QWORD))(v4 + 48);
                    if ( *((_DWORD *)v94 - 1) != 1338505325 )
                      __break(0x8228u);
                    v94(v31);
                    v95 = raw_spin_lock_irqsave(&list_lock);
                    v96 = *(_QWORD **)(v85 + 336);
                    v97 = (__int64 *)(v85 + 328);
                    v98 = v95;
                    if ( *v96 == v85 + 328 && (v99 = *v97, *(__int64 **)(*v97 + 8) == v97) )
                    {
                      *(_QWORD *)(v99 + 8) = v96;
                      *v96 = v99;
                    }
                    else
                    {
                      _list_del_entry_valid_or_report(v85 + 328);
                    }
                    *(_QWORD *)(v85 + 328) = 0xDEAD000000000100LL;
                    *(_QWORD *)(v85 + 336) = 0xDEAD000000000122LL;
                    raw_spin_unlock_irqrestore(&list_lock, v98);
                    goto LABEL_146;
                  }
                  if ( v69 != -517 )
                  {
                    dev_err(v1, "qcom dcvs registration error: %d\n", v69);
                    goto LABEL_135;
                  }
                  LODWORD(v22) = -517;
LABEL_146:
                  iounmap(*(_QWORD *)v4);
                  iounmap(*(_QWORD *)(v4 + 8));
                  goto LABEL_147;
                }
                v54 = v107;
                v115 = 0;
                v116 = 0;
                v113 = 0;
                v114 = 0;
                v111 = 0;
                v112 = 0;
                v109 = 0;
                v110 = 0;
                v107 = 0;
                v108 = 0;
                if ( (unsigned int)_of_parse_phandle_with_args(v54, "qcom,target-dev", 0, 0, 0, &v107)
                  || (v55 = v107) == 0 )
                {
                  dev_err(v1, "Unable to find target-dev for second vote\n");
                  goto LABEL_128;
                }
                v56 = of_property_read_variable_u32_array(v107, "qcom,dcvs-hw-type", &v104, 1, 0);
                v103 = v56 & (v56 >> 31);
                if ( v56 < 0 || v104 >= 5 )
                {
                  dev_err(v1, "invalid sec dcvs_hw=%d, ret=%d\n", v104);
                }
                else
                {
                  *(_DWORD *)(v4 + 116) = v104;
                  if ( of_find_property(v53, "qcom,secondary-map", &v103) )
                  {
                    v102 = v1;
                    v106 = 0;
                    LODWORD(v107) = 0;
                    if ( !of_find_property(v53, "qcom,secondary-map", &v107)
                      || (v57 = v107, _CF = (unsigned int)v107 >= 4, LODWORD(v107) = (int)v107 >> 2, !_CF)
                      || (v57 & 4) != 0
                      || (v101 = (unsigned int)(v57 >> 3),
                          v58 = 8LL * ((int)v101 + 1),
                          (v59 = devm_kmalloc(v1, v58, 3520)) == 0) )
                    {
LABEL_123:
                      *(_QWORD *)(v4 + 200) = 0;
                      dev_err(v102, "error importing second map!\n");
                      goto LABEL_128;
                    }
                    v60 = v59;
                    if ( (int)v101 >= 1 )
                    {
                      v61 = 0;
                      v62 = 0;
                      while ( (of_property_read_u32_index(v53, "qcom,secondary-map", v62, &v106) & 0x80000000) == 0 )
                      {
                        if ( 8LL * (unsigned int)(v101 + 1) == v61 || (v61 & 0x8000000000000000LL) != 0 || v58 <= v61 )
                          goto LABEL_149;
                        v63 = v62 + 1;
                        *(_DWORD *)(v60 + v61) = v106;
                        if ( (of_property_read_u32_index(v53, "qcom,secondary-map", v63, &v106) & 0x80000000) != 0 )
                          goto LABEL_123;
                        if ( v58 < v61 + 4 )
                          goto LABEL_149;
                        v64 = v60 + v61;
                        v61 += 8LL;
                        v62 = v63 + 1;
                        *(_DWORD *)(v64 + 4) = v106;
                        if ( 8LL * (unsigned int)v101 == v61 )
                        {
                          v65 = v101;
                          goto LABEL_82;
                        }
                      }
                      goto LABEL_123;
                    }
                    v65 = 0;
LABEL_82:
                    v31 = v4 + 40;
                    if ( v65 >= (int)v101 + 1 )
LABEL_149:
                      __break(1u);
                    *(_QWORD *)(v4 + 200) = v60;
                    *(_DWORD *)(v60 + 8 * v65) = 0;
                    v1 = v102;
                  }
                  v66 = of_property_read_variable_u32_array(v55, "qcom,bus-width", v4 + 120, 1, 0);
                  v103 = v66 & (v66 >> 31);
                  if ( (v66 & 0x80000000) == 0 && *(_DWORD *)(v4 + 120) || *(_QWORD *)(v4 + 200) )
                  {
                    v67 = *(const char **)(a1 + 128);
                    if ( !v67 )
                      v67 = *v1;
                    snprintf((char *)(v4 + 132), 0x41u, "%s_hw-%d", v67, v104);
                    *(_BYTE *)(v4 + 124) = 1;
                    goto LABEL_90;
                  }
                  dev_err(v1, "invalid sec hw width=%d, ret=%d\n", *(unsigned int *)(v4 + 120));
                }
              }
            }
            LODWORD(v22) = -22;
            goto LABEL_146;
          }
        }
        dev_err(v1, "Unable to find target-dev for bwmon device\n");
LABEL_128:
        LODWORD(v22) = -22;
        goto LABEL_146;
      }
      v12 = (_QWORD *)platform_get_resource_byname(a1, 512, "global_base");
      if ( !v12 )
      {
        dev_err(v1, "global_base not found!\n");
        goto LABEL_128;
      }
      v13 = 0x68000000000713LL;
      v14 = 0x68000000000F0FLL;
      if ( arm64_use_ng_mappings )
        v13 = 0x68000000000F13LL;
      else
        v14 = 0x6800000000070FLL;
      if ( property )
        v15 = v14;
      else
        v15 = v13;
      v16 = ioremap_prot(*v12, v12[1] - *v12 + 1LL, v15);
      *(_QWORD *)(v4 + 8) = v16;
      if ( v16 )
      {
        v17 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,mport", &v107, 1, 0);
        if ( v17 < 0 )
        {
          LODWORD(v22) = v17;
          dev_err(v1, "mport not found! (%d)\n", v17);
          goto LABEL_146;
        }
        *(_DWORD *)(v4 + 16) = v107;
        goto LABEL_22;
      }
      v34 = "Unable map global_base!\n";
    }
    else
    {
      v34 = "Unable map base!\n";
    }
    dev_err(v1, v34);
    LODWORD(v22) = -12;
    goto LABEL_146;
  }
  LODWORD(v22) = -12;
LABEL_147:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v22;
}
