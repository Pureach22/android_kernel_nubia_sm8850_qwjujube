__int64 __fastcall aw_i2c_probe(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  __int64 (*v6)(void); // x8
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  _QWORD *v10; // x20
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x19
  __int64 v14; // x1
  unsigned int v15; // w0
  __int64 v16; // x1
  unsigned int v17; // w0
  unsigned int v18; // w22
  int v19; // w25
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int16 v24; // w9
  __int64 v25; // x0
  int v26; // w27
  unsigned int v27; // w27
  __int64 v28; // x8
  __int16 v29; // w9
  __int64 v30; // x0
  int v31; // w27
  int named_gpio; // w0
  unsigned int v33; // w21
  int v34; // w0
  void *v35; // x0
  __int64 v36; // x2
  int v37; // w8
  void *v38; // x0
  __int64 v39; // x2
  __int64 (__fastcall *v40)(__int64); // x9
  unsigned int v41; // w0
  unsigned int v42; // w4
  void *v43; // x0
  __int64 v44; // x2
  _DWORD *v45; // x8
  unsigned int v46; // w0
  __int64 v47; // x0
  unsigned int v48; // w4
  void (__fastcall *v49)(_QWORD); // x8
  __int64 v50; // x0
  __int64 free_pages_noprof; // x0
  __int64 v52; // x8
  __int64 v53; // x9
  __int64 v54; // x8
  __int64 v55; // x9
  __int64 v56; // x8
  __int64 v57; // x9
  __int64 v58; // x8
  __int64 v59; // x9
  __int64 v60; // x8
  __int64 v61; // x9
  __int64 v62; // x8
  __int64 v63; // x9
  __int64 v64; // x8
  __int64 v65; // x9
  __int64 v66; // x8
  __int64 v67; // x8
  __int64 v68; // x9
  __int64 v69; // x10
  __int64 v70; // x11
  __int64 v71; // x10
  __int64 v72; // x11
  __int64 v73; // x10
  __int64 v74; // x11
  __int64 v75; // x10
  __int64 v76; // x11
  __int64 v77; // x10
  __int64 v78; // x11
  __int64 v79; // x10
  __int64 v80; // x11
  __int64 v81; // x10
  __int64 v82; // x11
  __int64 v83; // x0
  unsigned int v84; // w0
  unsigned __int64 v90; // x9
  _BYTE v91[4]; // [xsp+0h] [xbp-30h] BYREF
  unsigned __int8 v92[4]; // [xsp+4h] [xbp-2Ch] BYREF
  __int16 v93; // [xsp+8h] [xbp-28h] BYREF
  int v94; // [xsp+Ah] [xbp-26h]
  __int16 v95; // [xsp+Eh] [xbp-22h]
  _BYTE *v96; // [xsp+10h] [xbp-20h]
  __int16 v97; // [xsp+18h] [xbp-18h]
  int v98; // [xsp+1Ah] [xbp-16h]
  __int16 v99; // [xsp+1Eh] [xbp-12h]
  unsigned __int8 *v100; // [xsp+20h] [xbp-10h]
  __int64 v101; // [xsp+28h] [xbp-8h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1[97];
  printk(&unk_14FD9, a2, a3, a4);
  v6 = *(__int64 (**)(void))(*(_QWORD *)(a1[3] + 16LL) + 32LL);
  if ( *((_DWORD *)v6 - 1) != 2093148950 )
    __break(0x8228u);
  if ( (v6() & 1) == 0 )
  {
    printk(&unk_15B33, v7, v8, v9);
    result = 4294967291LL;
    goto LABEL_6;
  }
  v10 = a1 + 4;
  v11 = devm_kmalloc(a1 + 4, 1784, 3520);
  if ( !v11 )
  {
    result = 4294967284LL;
    goto LABEL_6;
  }
  v13 = v11;
  *(_QWORD *)(v11 + 800) = v10;
  *(_QWORD *)(v11 + 808) = a1;
  a1[23] = v11;
  if ( v5 )
  {
    named_gpio = of_get_named_gpio(v5, "reset-gpio", 0);
    *(_DWORD *)(v13 + 92) = named_gpio;
    if ( named_gpio < 0 )
    {
      printk(&unk_15710, "haptic_hv", 336, "parse_dt_gpio");
      printk(&unk_160EE, "haptic_hv", 4346, "aw_i2c_probe");
      v33 = -1;
      goto LABEL_89;
    }
    printk(&unk_1441D, "haptic_hv", 339, "parse_dt_gpio");
    v34 = of_get_named_gpio(v5, "irq-gpio", 0);
    *(_DWORD *)(v13 + 80) = v34;
    if ( v34 < 0 )
      printk(&unk_15E48, "haptic_hv", 342, "parse_dt_gpio");
    else
      printk(&unk_166C7, "haptic_hv", 344, "parse_dt_gpio");
    if ( (of_property_read_variable_u8_array(v5, "mode", v13 + 1120, 1, 0) & 0x80000000) != 0 )
      printk(&unk_14E9F, "haptic_hv", 347, "parse_dt_gpio");
  }
  else
  {
    *(_DWORD *)(v11 + 92) = -1;
    *(_DWORD *)(v11 + 80) = -1;
  }
  v14 = *(unsigned int *)(v13 + 92);
  if ( (v14 & 0x80000000) == 0 )
  {
    v15 = devm_gpio_request_one(a1 + 4, v14, 0, "aw_rst");
    if ( v15 )
    {
      v33 = v15;
      printk(&unk_16114, "haptic_hv", 4358, "aw_i2c_probe");
      goto LABEL_89;
    }
  }
  v16 = *(unsigned int *)(v13 + 80);
  if ( (v16 & 0x80000000) == 0 )
  {
    v17 = devm_gpio_request_one(a1 + 4, v16, 1, "aw_int");
    if ( v17 )
    {
      v33 = v17;
      printk(&unk_16B01, "haptic_hv", 4393, "aw_i2c_probe");
      goto LABEL_87;
    }
  }
  v18 = 0;
  v19 = 0;
  *(_BYTE *)(v13 + 1779) = 32;
  while ( 1 )
  {
    printk(&unk_14A18, "haptic_hv", 369, "hw_reset");
    if ( (*(_DWORD *)(v13 + 92) & 0x80000000) != 0 )
    {
      printk(&unk_14842, "haptic_hv", 376, "hw_reset");
    }
    else
    {
      v21 = ((__int64 (*)(void))gpio_to_desc)();
      gpiod_set_raw_value_cansleep(v21, 0);
      usleep_range_state(1000, 2000, 2);
      v22 = gpio_to_desc(*(unsigned int *)(v13 + 92));
      gpiod_set_raw_value_cansleep(v22, 1);
      usleep_range_state(8000, 8500, 2);
    }
    v23 = *(_QWORD *)(v13 + 808);
    *(_WORD *)v92 = 0;
    v24 = *(_WORD *)(v23 + 2);
    v100 = v92;
    v25 = *(_QWORD *)(v23 + 24);
    v94 = 0x10000;
    v93 = v24;
    v97 = v24;
    v91[0] = 0;
    v95 = 0;
    v96 = v91;
    v98 = 65537;
    v99 = 0;
    v26 = i2c_transfer(v25, &v93, 2);
    if ( (v26 & 0x80000000) == 0 )
    {
      if ( v26 != 2 )
        goto LABEL_27;
      v27 = v92[0];
      if ( (v92[0] & 0x7C) != 0 )
        goto LABEL_26;
      v28 = *(_QWORD *)(v13 + 808);
      v91[0] = 87;
      v29 = *(_WORD *)(v28 + 2);
      v100 = v92;
      v30 = *(_QWORD *)(v28 + 24);
      v94 = 0x10000;
      v93 = v29;
      v97 = v29;
      v95 = 0;
      v96 = v91;
      v98 = 131073;
      v99 = 0;
      v31 = i2c_transfer(v30, &v93, 2);
      if ( (v31 & 0x80000000) == 0 )
      {
        if ( v31 == 2 )
        {
          v27 = __rev16(*(unsigned __int16 *)v92);
LABEL_26:
          printk(&unk_14A4E, "haptic_hv", 445, "parse_chipid");
          v19 = v27;
          goto LABEL_29;
        }
LABEL_27:
        printk(&unk_154F2, "haptic_hv", 104, "i2c_r_bytes");
        goto LABEL_28;
      }
    }
    printk(&unk_147C9, "haptic_hv", 101, "i2c_r_bytes");
LABEL_28:
    printk(&unk_14A4E, "haptic_hv", 445, "parse_chipid");
    printk(&unk_166F6, "haptic_hv", 447, "parse_chipid");
LABEL_29:
    if ( v19 <= 29039 )
    {
      if ( v19 <= 6 )
      {
        switch ( v19 )
        {
          case 4:
            *(_BYTE *)(v13 + 4) = 0;
            *(_DWORD *)(v13 + 72) = 4;
            v35 = &unk_168F1;
            *(_BYTE *)(v13 + 22) = 1;
            v36 = 471;
            goto LABEL_74;
          case 5:
            *(_BYTE *)(v13 + 22) = 0;
            v35 = &unk_163BF;
            *(_DWORD *)(v13 + 72) = 5;
            *(_BYTE *)(v13 + 4) = 0;
            v36 = 465;
            goto LABEL_74;
          case 6:
            v35 = &unk_14064;
            *(_DWORD *)(v13 + 72) = 6;
            *(_BYTE *)(v13 + 22) = 1;
            *(_BYTE *)(v13 + 4) = 1;
            v36 = 483;
            goto LABEL_74;
        }
      }
      else if ( v19 > 150 )
      {
        if ( v19 == 151 )
        {
          v35 = &unk_14BF3;
          v36 = 459;
          *(_DWORD *)(v13 + 72) = 151;
          *(_BYTE *)(v13 + 22) = 1;
          *(_BYTE *)(v13 + 4) = 0;
          goto LABEL_74;
        }
        if ( v19 == 29008 )
        {
          *(_DWORD *)(v13 + 72) = 29008;
          v35 = &unk_1469D;
          *(_BYTE *)(v13 + 4) = 0;
          v36 = 488;
          goto LABEL_74;
        }
      }
      else
      {
        if ( v19 == 7 )
        {
          *(_BYTE *)(v13 + 22) = 0;
          *(_DWORD *)(v13 + 72) = 7;
          v35 = &unk_15737;
          *(_BYTE *)(v13 + 4) = 1;
          v36 = 477;
          goto LABEL_74;
        }
        if ( v19 == 149 )
        {
          *(_BYTE *)(v13 + 22) = 0;
          v35 = &unk_16A59;
          *(_DWORD *)(v13 + 72) = 149;
          *(_BYTE *)(v13 + 4) = 0;
          v36 = 453;
          goto LABEL_74;
        }
      }
      goto LABEL_15;
    }
    if ( v19 <= 37471 )
    {
      if ( v19 > 29055 )
      {
        if ( v19 == 29056 )
        {
          *(_DWORD *)(v13 + 72) = 29056;
          v35 = &unk_147EB;
          *(_BYTE *)(v13 + 4) = 1;
          v36 = 503;
          goto LABEL_74;
        }
        if ( v19 == 37456 )
        {
          *(_DWORD *)(v13 + 72) = 37456;
          v35 = &unk_15B98;
          *(_BYTE *)(v13 + 22) = 0;
          v36 = 508;
          goto LABEL_74;
        }
      }
      else
      {
        if ( v19 == 29040 )
        {
          *(_DWORD *)(v13 + 72) = 29040;
          v35 = &unk_153FE;
          *(_BYTE *)(v13 + 4) = 1;
          v36 = 493;
          goto LABEL_74;
        }
        if ( v19 == 29041 )
        {
          *(_DWORD *)(v13 + 72) = 29041;
          v35 = &unk_15B75;
          *(_BYTE *)(v13 + 4) = 1;
          v36 = 498;
          goto LABEL_74;
        }
      }
      goto LABEL_15;
    }
    if ( v19 <= 37503 )
    {
      if ( v19 == 37472 )
      {
        *(_DWORD *)(v13 + 72) = 37472;
        v35 = &unk_15E6F;
        *(_BYTE *)(v13 + 22) = 0;
        v36 = 513;
        goto LABEL_74;
      }
      if ( v19 == 37488 )
      {
        *(_DWORD *)(v13 + 72) = 37488;
        v35 = &unk_159BA;
        *(_BYTE *)(v13 + 22) = 0;
        v36 = 518;
        goto LABEL_74;
      }
      goto LABEL_15;
    }
    if ( v19 == 37504 )
      break;
    if ( v19 == 37760 )
    {
      *(_DWORD *)(v13 + 72) = 37760;
      v35 = &unk_1428F;
      *(_BYTE *)(v13 + 1779) = 64;
      v36 = 528;
      goto LABEL_74;
    }
LABEL_15:
    printk(&unk_1480E, "haptic_hv", 531, "parse_chipid");
    usleep_range_state(2000, 2500, 2);
    if ( v18++ >= 4 )
    {
      v43 = &unk_14672;
      v44 = 4413;
LABEL_83:
      v33 = -22;
      goto LABEL_84;
    }
  }
  *(_DWORD *)(v13 + 72) = 37504;
  v35 = &unk_15E92;
  *(_BYTE *)(v13 + 22) = 0;
  v36 = 523;
LABEL_74:
  printk(v35, "haptic_hv", v36, "parse_chipid");
  LOBYTE(v93) = -86;
  i2c_w_bytes(v13, 0, &v93, 1u);
  usleep_range_state(3000, 3500, 2);
  v37 = *(_DWORD *)(v13 + 72);
  if ( v37 <= 0 )
  {
    printk(&unk_14B67, "haptic_hv", 543, "ctrl_init");
    v38 = &unk_14447;
    v39 = 544;
    goto LABEL_82;
  }
  if ( v37 != 37760 )
  {
    v38 = &unk_1485A;
    v39 = 576;
LABEL_82:
    printk(v38, "haptic_hv", v39, "ctrl_init");
    v43 = &unk_1659D;
    v44 = 4420;
    goto LABEL_83;
  }
  v40 = (__int64 (__fastcall *)(__int64))off_150[0];
  *(_QWORD *)(v13 + 1480) = aw8693x_func_list;
  if ( *((_DWORD *)v40 - 1) != 1361900016 )
    __break(0x8229u);
  v41 = v40(v13);
  if ( (v41 & 0x80000000) != 0 )
  {
    v42 = v41;
    v43 = &unk_14987;
    v44 = 4427;
    v33 = v42;
LABEL_84:
    printk(v43, "haptic_hv", v44, "aw_i2c_probe");
    goto LABEL_85;
  }
  v45 = *(_DWORD **)(*(_QWORD *)(v13 + 1480) + 224LL);
  if ( *(v45 - 1) != 779604778 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD *, __int64, __int64))v45)(v10, v13, v5);
  v46 = irq_config(v10, v13);
  if ( v46 )
  {
    v48 = v46;
    v43 = &unk_143F3;
    v44 = 4441;
    v33 = v48;
    goto LABEL_84;
  }
  vibrator_init(v13);
  haptic_init(v13);
  v47 = alloc_workqueue("%s", (const char *)0x6000A);
  *(_QWORD *)(v13 + 1096) = v47;
  if ( v47 )
  {
    v49 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v13 + 1480) + 8LL);
    if ( *((_DWORD *)v49 - 1) != 1361900016 )
      __break(0x8228u);
    v49(v13);
    ram_work_init(v13);
    printk(&unk_1598B, "haptic_hv", 4466, "aw_i2c_probe");
    v50 = _kmalloc_large_noprof(16000, 3264);
    *(_QWORD *)(v13 + 1544) = v50;
    if ( v50 )
    {
      free_pages_noprof = get_free_pages_noprof(3264, 2);
      *(_QWORD *)(v13 + 1552) = free_pages_noprof;
      if ( free_pages_noprof )
      {
        _X8 = (unsigned __int64 *)((((unsigned __int64)((free_pages_noprof << 8 >> 8) + 0x8000000000LL) >> 6)
                                  & 0x3FFFFFFFFFFFFC0LL)
                                 - 0x140000000LL);
        __asm { PRFM            #0x11, [X8] }
        do
          v90 = __ldxr(_X8);
        while ( __stxr(v90 | 0x4000, _X8) );
        v52 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v52 + 8) = v52 + 1024;
        v53 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v52 + 1032) = v53 + 2048;
        v54 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v53 + 2056) = v54 + 3072;
        v55 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v54 + 3080) = v55 + 4096;
        v56 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v55 + 4104) = v56 + 5120;
        v57 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v56 + 5128) = v57 + 6144;
        v58 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v57 + 6152) = v58 + 7168;
        v59 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v58 + 7176) = v59 + 0x2000;
        v60 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v59 + 8200) = v60 + 9216;
        v61 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v60 + 9224) = v61 + 10240;
        v62 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v61 + 10248) = v62 + 11264;
        v63 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v62 + 11272) = v63 + 12288;
        v64 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v63 + 12296) = v64 + 13312;
        v65 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v64 + 13320) = v65 + 14336;
        v66 = *(_QWORD *)(v13 + 1552);
        *(_QWORD *)(v65 + 14344) = v66 + 15360;
        *(_QWORD *)(v66 + 15368) = *(_QWORD *)(v13 + 1552);
        v67 = *(_QWORD *)(v13 + 1552);
        v68 = *(_QWORD *)(v67 + 8);
        *(_BYTE *)(v67 + 1) = 0;
        v69 = *(_QWORD *)(v68 + 8);
        *(_BYTE *)(v68 + 1) = 1;
        v70 = *(_QWORD *)(v69 + 8);
        *(_BYTE *)(v69 + 1) = 2;
        v71 = *(_QWORD *)(v70 + 8);
        *(_BYTE *)(v70 + 1) = 3;
        v72 = *(_QWORD *)(v71 + 8);
        *(_BYTE *)(v71 + 1) = 4;
        v73 = *(_QWORD *)(v72 + 8);
        *(_BYTE *)(v72 + 1) = 5;
        v74 = *(_QWORD *)(v73 + 8);
        *(_BYTE *)(v73 + 1) = 6;
        v75 = *(_QWORD *)(v74 + 8);
        *(_BYTE *)(v74 + 1) = 7;
        v76 = *(_QWORD *)(v75 + 8);
        *(_BYTE *)(v75 + 1) = 8;
        v77 = *(_QWORD *)(v76 + 8);
        *(_BYTE *)(v76 + 1) = 9;
        v78 = *(_QWORD *)(v77 + 8);
        *(_BYTE *)(v77 + 1) = 10;
        v79 = *(_QWORD *)(v78 + 8);
        *(_BYTE *)(v78 + 1) = 11;
        v80 = *(_QWORD *)(v79 + 8);
        *(_BYTE *)(v79 + 1) = 12;
        v81 = *(_QWORD *)(v80 + 8);
        *(_BYTE *)(v80 + 1) = 13;
        v82 = *(_QWORD *)(v81 + 8);
        *(_BYTE *)(v81 + 1) = 14;
        *(_BYTE *)(v82 + 1) = 15;
        *(_WORD *)(v13 + 1560) = 1;
        *(_QWORD *)(v13 + 1608) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v13 + 1616) = v13 + 1616;
        *(_QWORD *)(v13 + 1624) = v13 + 1616;
        *(_QWORD *)(v13 + 1632) = richtap_rtp_work;
        *(_QWORD *)(v13 + 1640) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v13 + 1648) = v13 + 1648;
        *(_QWORD *)(v13 + 1656) = v13 + 1648;
        *(_QWORD *)(v13 + 1664) = richtap_stop_work;
        *(_QWORD *)(v13 + 1576) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v13 + 1584) = v13 + 1584;
        *(_QWORD *)(v13 + 1592) = v13 + 1584;
        *(_QWORD *)(v13 + 1600) = tiktap_work_routine;
        *(_DWORD *)(v13 + 1724) = 0;
        misc_register(&richtap_misc);
        result = 0;
        g_aw_haptic = v13;
        goto LABEL_6;
      }
      dev_err(v10, "Error __get_free_pages failed\n");
      kfree(*(_QWORD *)(v13 + 1544));
    }
    else
    {
      dev_err(v10, "malloc rtp memory failed\n");
    }
    v83 = gpio_to_desc(*(unsigned int *)(v13 + 80));
    v84 = gpiod_to_irq(v83);
    devm_free_irq(v10, v84, v13);
    v33 = 0;
  }
  else
  {
    printk(&unk_14BB5, "haptic_hv", 4461, "aw_i2c_probe");
    v33 = 0;
  }
LABEL_85:
  if ( (*(_DWORD *)(v13 + 80) & 0x80000000) == 0 )
    gpio_free();
LABEL_87:
  if ( (*(_DWORD *)(v13 + 92) & 0x80000000) == 0 )
    gpio_free();
LABEL_89:
  devm_kfree(v10, v13);
  result = v33;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
