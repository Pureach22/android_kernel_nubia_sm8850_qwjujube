__int64 __fastcall aw882xx_i2c_probe(__int64 a1)
{
  __int64 *v2; // x19
  __int64 v3; // x22
  __int64 (*v4)(void); // x8
  __int64 v5; // x1
  __int64 result; // x0
  __int64 v7; // x0
  __int64 v8; // x21
  _QWORD *v9; // x0
  __int64 v10; // x1
  __int64 v11; // x1
  int named_gpio; // w0
  __int64 *v13; // x8
  __int64 v14; // x1
  void *v15; // x0
  int v16; // w0
  __int64 *v17; // x8
  __int64 v18; // x1
  void *v19; // x0
  __int64 *v20; // x8
  __int64 v21; // x1
  __int64 *v22; // x8
  __int64 v23; // x1
  int v24; // w0
  __int64 *v25; // x8
  __int64 v26; // x1
  char v27; // w8
  __int64 v28; // x9
  __int64 v29; // x0
  int variable_u32_array; // w0
  __int64 *v31; // x8
  __int64 v32; // x1
  __int64 v33; // x9
  __int64 v34; // x0
  int v35; // w0
  __int64 *v36; // x8
  __int64 v37; // x1
  char v38; // w8
  __int64 v39; // x1
  __int64 v40; // x1
  __int64 *v41; // x8
  __int64 v42; // x1
  void *v43; // x0
  __int64 *v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 *v47; // x8
  __int64 v48; // x1
  __int64 v49; // x1
  int v50; // w22
  __int64 *v51; // x8
  __int64 v52; // x1
  __int64 v53; // x1
  __int64 v54; // x0
  __int64 *v55; // x22
  __int64 v56; // x0
  unsigned int v57; // w0
  __int64 *v58; // x8
  __int64 v59; // x23
  __int64 v60; // x0
  __int64 v61; // x1
  __int64 *v62; // x0
  unsigned int v63; // w21
  __int64 v64; // x1
  __int64 *v65; // x22
  __int64 v66; // x8
  int v67; // w4
  __int64 v68; // x0
  __int64 *v69; // x8
  __int64 v70; // x1
  __int64 v71; // x8
  int v72; // w4
  __int64 v73; // x0
  __int64 *v74; // x8
  __int64 v75; // x1
  __int64 v76; // x8
  int v77; // w4
  __int64 v78; // x0
  __int64 *v79; // x8
  __int64 v80; // x1
  __int64 *v81; // x8
  __int64 v82; // x1
  void *v83; // x0
  const char *v84; // x2
  __int64 *v85; // x8
  __int64 v86; // x1
  __int64 *v87; // x8
  __int64 v88; // x1
  __int64 *v89; // x8
  __int64 v90; // x1
  __int64 *v91; // x8
  __int64 v92; // x1
  __int64 *v93; // x8
  __int64 v94; // x1
  __int64 v95; // x8
  __int64 v96; // x9
  __int64 v97; // x0
  __int64 *v98; // x8
  __int64 v99; // x1
  __int64 v100; // x8
  __int64 v101; // x9
  __int64 v102; // x0
  __int64 *v103; // x8
  __int64 v104; // x1
  __int64 v105; // x8
  __int64 v106; // x9
  __int64 v107; // x0
  __int64 *v108; // x8
  __int64 *v109; // x8
  __int64 v110; // x1
  __int64 *v111; // x8
  __int64 v112; // x1
  __int64 *v113; // x8
  __int64 v114; // x1
  __int64 v115; // x0
  __int64 (__fastcall *v116)(__int64, void *, __int64 *, __int64); // x8
  __int64 *v117; // x8
  __int64 v118; // x1
  __int64 *v119; // x8
  __int64 v120; // x1
  unsigned int group; // w0
  __int64 *v122; // x8
  unsigned int v123; // w20
  __int64 v124; // x1
  void (__fastcall *v125)(__int64 *); // x8
  unsigned int v126; // w22
  __int64 v127; // x0
  __int64 v128; // x1
  __int64 v129; // [xsp+0h] [xbp-50h] BYREF
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v131; // [xsp+10h] [xbp-40h]
  __int64 v132; // [xsp+18h] [xbp-38h]
  __int64 v133; // [xsp+20h] [xbp-30h]
  __int64 v134; // [xsp+28h] [xbp-28h]
  __int64 v135; // [xsp+30h] [xbp-20h]
  __int64 v136; // [xsp+38h] [xbp-18h]
  __int64 v137; // [xsp+40h] [xbp-10h]
  __int64 v138; // [xsp+48h] [xbp-8h]

  v2 = (__int64 *)(a1 + 32);
  v138 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 776);
  printk(&unk_275C9, "aw882xx_i2c_probe", *(unsigned __int16 *)(a1 + 2));
  v4 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 16LL) + 32LL);
  if ( *((_DWORD *)v4 - 1) != 2093148950 )
    __break(0x8228u);
  if ( (v4() & 1) == 0 )
  {
    v5 = *(_QWORD *)(a1 + 144);
    if ( !v5 )
      v5 = *v2;
    printk(&unk_23C5B, v5, "aw882xx_i2c_probe");
    result = 4294967291LL;
    goto LABEL_13;
  }
  v7 = devm_kmalloc(v2, 576, 3520);
  if ( !v7 )
    goto LABEL_10;
  v8 = v7;
  *(_QWORD *)(v7 + 40) = 0;
  *(_QWORD *)(v7 + 48) = aw_componet_codec_ops;
  *(_QWORD *)(v7 + 56) = a1;
  *(_QWORD *)(v7 + 64) = v2;
  *(_WORD *)(v7 + 36) = 0;
  *(_WORD *)(v7 + 18) = 257;
  *(_QWORD *)(v7 + 104) = 0;
  _mutex_init(v7 + 528, "&aw882xx->lock", &aw882xx_malloc_init___key);
  v9 = (_QWORD *)devm_kmalloc(v2, 1240, 3520);
  *(_QWORD *)(v8 + 96) = v9;
  if ( !v9 )
  {
    devm_kfree(v2, v8);
LABEL_10:
    v10 = *(_QWORD *)(a1 + 144);
    if ( !v10 )
      v10 = *v2;
    printk(&unk_275E8, v10, "aw882xx_i2c_probe");
    result = 4294967284LL;
    goto LABEL_13;
  }
  v9[14] = v2;
  v9[15] = a1;
  v9[142] = aw882xx_get_version;
  v9[143] = aw882xx_get_dev_num;
  v9[145] = aw882xx_i2c_read;
  v9[144] = aw882xx_i2c_write;
  v9[146] = aw882xx_i2c_write_bits;
  *(_QWORD *)(a1 + 184) = v8;
  v129 = 0;
  if ( !v3 )
  {
    v11 = *(_QWORD *)(a1 + 144);
    *(_QWORD *)(v8 + 28) = -1;
    if ( !v11 )
      v11 = *v2;
    printk(&unk_23C89, v11, "aw882xx_i2c_probe");
    result = 4294967274LL;
    goto LABEL_13;
  }
  named_gpio = of_get_named_gpio(v3, "reset-gpio", 0);
  v13 = *(__int64 **)(v8 + 64);
  *(_DWORD *)(v8 + 28) = named_gpio;
  v14 = v13[14];
  if ( named_gpio < 0 )
  {
    if ( !v14 )
      v14 = *v13;
    v15 = &unk_249D3;
  }
  else
  {
    if ( !v14 )
      v14 = *v13;
    v15 = &unk_28ACF;
  }
  printk(v15, v14, "aw882xx_parse_gpio_dt");
  v16 = of_get_named_gpio(v3, "irq-gpio", 0);
  v17 = *(__int64 **)(v8 + 64);
  *(_DWORD *)(v8 + 32) = v16;
  v18 = v17[14];
  if ( v16 < 0 )
  {
    if ( !v18 )
      v18 = *v17;
    v19 = &unk_286C1;
  }
  else
  {
    if ( !v18 )
      v18 = *v17;
    v19 = &unk_26409;
  }
  printk(v19, v18, "aw882xx_parse_gpio_dt");
  if ( (of_property_read_variable_u32_array(v3, "dc-flag", (char *)&v129 + 4, 1, 0) & 0x80000000) != 0 )
  {
    v22 = *(__int64 **)(v8 + 64);
    HIDWORD(v129) = 0;
    v23 = v22[14];
    if ( !v23 )
      v23 = *v22;
    printk(&unk_26B16, v23, "aw882xx_parse_dt");
  }
  else
  {
    v20 = *(__int64 **)(v8 + 64);
    v21 = v20[14];
    if ( !v21 )
      v21 = *v20;
    printk(&unk_24D5D, v21, "aw882xx_parse_dt");
  }
  *(_BYTE *)(v8 + 17) = BYTE4(v129);
  v24 = of_property_read_variable_u32_array(v3, "sync-flag", &v129, 1, 0);
  v25 = *(__int64 **)(v8 + 64);
  v26 = v25[14];
  if ( v24 < 0 )
  {
    if ( !v26 )
      v26 = *v25;
    printk(&unk_22BAD, v26, "aw882xx_parse_dt");
    v27 = 0;
    LODWORD(v129) = 0;
  }
  else
  {
    if ( !v26 )
      v26 = *v25;
    printk(&unk_28438, v26, "aw882xx_parse_dt");
    v27 = v129;
  }
  v28 = *(_QWORD *)(v8 + 64);
  *(_BYTE *)(v8 + 16) = v27;
  v29 = *(_QWORD *)(v28 + 744);
  *(_DWORD *)s = 0;
  variable_u32_array = of_property_read_variable_u32_array(v29, "rename-flag", s, 1, 0);
  v31 = *(__int64 **)(v8 + 64);
  v32 = v31[14];
  if ( variable_u32_array < 0 )
  {
    if ( !v32 )
      v32 = *v31;
    printk(&unk_24D7D, v32, "aw882xx_parse_rename_flag_dt");
  }
  else
  {
    if ( !v32 )
      v32 = *v31;
    printk(&unk_24510, v32, "aw882xx_parse_rename_flag_dt");
  }
  v33 = *(_QWORD *)(v8 + 64);
  *(_DWORD *)(v8 + 20) = *(_DWORD *)s;
  v34 = *(_QWORD *)(v33 + 744);
  *(_DWORD *)s = 0;
  v35 = of_property_read_variable_u32_array(v34, "sync-load", s, 1, 0);
  v36 = *(__int64 **)(v8 + 64);
  v37 = v36[14];
  if ( v35 < 0 )
  {
    if ( !v37 )
      v37 = *v36;
    printk(&unk_253D9, v37, "aw882xx_parse_sync_load_dt");
    v38 = 0;
  }
  else
  {
    if ( !v37 )
      v37 = *v36;
    printk(&unk_27265, v37, "aw882xx_parse_sync_load_dt");
    v38 = s[0];
  }
  v39 = *(unsigned int *)(v8 + 28);
  *(_BYTE *)(v8 + 24) = v38;
  if ( (v39 & 0x80000000) == 0 && (unsigned int)devm_gpio_request_one(*(_QWORD *)(v8 + 64), v39, 0, "aw882xx_rst") )
  {
    v44 = *(__int64 **)(v8 + 64);
    v42 = v44[14];
    if ( !v42 )
      v42 = *v44;
    v43 = &unk_27652;
    goto LABEL_70;
  }
  v40 = *(unsigned int *)(v8 + 32);
  if ( (v40 & 0x80000000) == 0 && (unsigned int)devm_gpio_request_one(*(_QWORD *)(v8 + 64), v40, 1, "aw882xx_int") )
  {
    v41 = *(__int64 **)(v8 + 64);
    v42 = v41[14];
    if ( !v42 )
      v42 = *v41;
    v43 = &unk_24DBD;
LABEL_70:
    printk(v43, v42, "aw882xx_gpio_request");
  }
  v45 = aw882xx_hw_reset(v8);
  smartpa_count_add_t(v45);
  v46 = *(_QWORD *)(v8 + 56);
  *(_DWORD *)s = 0;
  if ( (aw882xx_i2c_read(v46, 0, s) & 0x80000000) != 0 )
    goto LABEL_72;
  v50 = *(_DWORD *)s;
  if ( (unsigned int)aw882xx_chipid_auth(*(unsigned int *)s) )
  {
    v85 = *(__int64 **)(v8 + 64);
    v86 = v85[14];
    if ( !v86 )
      v86 = *v85;
    printk(&unk_28AF9, v86, "aw882xx_read_chipid");
    msleep(5);
    if ( (aw882xx_i2c_read(*(_QWORD *)(v8 + 56), 0, s) & 0x80000000) != 0 )
      goto LABEL_72;
    v50 = *(_DWORD *)s;
    if ( !(unsigned int)aw882xx_chipid_auth(*(unsigned int *)s) )
      goto LABEL_78;
    v87 = *(__int64 **)(v8 + 64);
    v88 = v87[14];
    if ( !v88 )
      v88 = *v87;
    printk(&unk_28AF9, v88, "aw882xx_read_chipid");
    msleep(5);
    if ( (aw882xx_i2c_read(*(_QWORD *)(v8 + 56), 0, s) & 0x80000000) != 0 )
      goto LABEL_72;
    v50 = *(_DWORD *)s;
    if ( !(unsigned int)aw882xx_chipid_auth(*(unsigned int *)s) )
      goto LABEL_78;
    v89 = *(__int64 **)(v8 + 64);
    v90 = v89[14];
    if ( !v90 )
      v90 = *v89;
    printk(&unk_28AF9, v90, "aw882xx_read_chipid");
    msleep(5);
    if ( (aw882xx_i2c_read(*(_QWORD *)(v8 + 56), 0, s) & 0x80000000) != 0 )
      goto LABEL_72;
    v50 = *(_DWORD *)s;
    if ( !(unsigned int)aw882xx_chipid_auth(*(unsigned int *)s) )
      goto LABEL_78;
    v91 = *(__int64 **)(v8 + 64);
    v92 = v91[14];
    if ( !v92 )
      v92 = *v91;
    printk(&unk_28AF9, v92, "aw882xx_read_chipid");
    msleep(5);
    if ( (aw882xx_i2c_read(*(_QWORD *)(v8 + 56), 0, s) & 0x80000000) != 0 )
    {
LABEL_72:
      v47 = *(__int64 **)(v8 + 64);
      v48 = v47[14];
      if ( !v48 )
        v48 = *v47;
      printk(&unk_24282, v48, "aw882xx_read_chipid");
      v49 = *(_QWORD *)(a1 + 144);
      if ( v49 )
        goto LABEL_76;
      goto LABEL_75;
    }
    v50 = *(_DWORD *)s;
    if ( (unsigned int)aw882xx_chipid_auth(*(unsigned int *)s) )
    {
      v93 = *(__int64 **)(v8 + 64);
      v94 = v93[14];
      if ( !v94 )
        v94 = *v93;
      printk(&unk_28AF9, v94, "aw882xx_read_chipid");
      msleep(5);
      v49 = *(_QWORD *)(a1 + 144);
      if ( v49 )
        goto LABEL_76;
LABEL_75:
      v49 = *v2;
LABEL_76:
      printk(&unk_23CBD, v49, "aw882xx_i2c_probe");
      goto LABEL_81;
    }
  }
LABEL_78:
  v51 = *(__int64 **)(v8 + 64);
  v52 = v51[14];
  if ( !v52 )
    v52 = *v51;
  printk(&unk_2454F, v52, "aw882xx_read_chipid");
  *(_DWORD *)(*(_QWORD *)(v8 + 96) + 4LL) = v50;
LABEL_81:
  if ( (unsigned int)aw882xx_init(*(_QWORD *)(v8 + 96)) )
  {
    v53 = *(_QWORD *)(a1 + 144);
    if ( !v53 )
      v53 = *v2;
    printk(&unk_2252E, v53, "aw882xx_i2c_probe");
  }
  v54 = *(unsigned int *)(v8 + 32);
  v55 = *(__int64 **)(v8 + 64);
  if ( (v54 & 0x80000000) != 0 )
  {
    v61 = v55[14];
    if ( !v61 )
      v61 = *v55;
    printk(&unk_26432, v61, "aw882xx_interrupt_init");
  }
  else
  {
    v56 = gpio_to_desc(v54);
    v57 = gpiod_to_irq(v56);
    if ( (unsigned int)devm_request_threaded_irq(v55, v57, 0, aw882xx_irq, 8194, "aw882xx", v8) )
    {
      v58 = *(__int64 **)(v8 + 64);
      v59 = v58[14];
      if ( !v59 )
        v59 = *v58;
      v60 = gpio_to_desc(*(unsigned int *)(v8 + 32));
      gpiod_to_irq(v60);
      printk(&unk_2221A, v59, "aw882xx_interrupt_init");
    }
  }
  v62 = (__int64 *)devm_kmalloc(*(_QWORD *)(v8 + 64), 208, 3520);
  if ( !v62 )
  {
    v63 = -12;
    v64 = *(_QWORD *)(a1 + 144);
    if ( v64 )
    {
LABEL_96:
      printk(&unk_227F8, v64, "aw882xx_i2c_probe");
      result = v63;
      goto LABEL_13;
    }
LABEL_95:
    v64 = *v2;
    goto LABEL_96;
  }
  v65 = v62;
  memcpy(v62, &aw882xx_dai, 0xD0u);
  if ( *(_DWORD *)(v8 + 20) == 1 )
  {
    v66 = *(_QWORD *)(v8 + 96);
    v136 = 0;
    v137 = 0;
    v67 = *(_DWORD *)(v66 + 52);
    v134 = 0;
    v135 = 0;
    v132 = 0;
    v133 = 0;
    *(_QWORD *)s = 0;
    v131 = 0;
    snprintf(s, 0x40u, "%s-%d", "aw882xx-aif", v67);
    v68 = ((__int64 (__fastcall *)(_QWORD, char *))aw882xx_devm_kstrdup)(*(_QWORD *)(v8 + 64), s);
    *v65 = v68;
    if ( v68 )
    {
      v69 = *(__int64 **)(v8 + 64);
      v70 = v69[14];
      if ( !v70 )
        v70 = *v69;
      printk(&unk_27E09, v70, "aw882xx_append_channel_suffix");
      v71 = *(_QWORD *)(v8 + 96);
      v136 = 0;
      v137 = 0;
      v72 = *(_DWORD *)(v71 + 52);
      v134 = 0;
      v135 = 0;
      v132 = 0;
      v133 = 0;
      *(_QWORD *)s = 0;
      v131 = 0;
      snprintf(s, 0x40u, "%s_%d", "Speaker_Playback", v72);
      v73 = ((__int64 (__fastcall *)(_QWORD, char *))aw882xx_devm_kstrdup)(*(_QWORD *)(v8 + 64), s);
      v65[19] = v73;
      if ( v73 )
      {
        v74 = *(__int64 **)(v8 + 64);
        v75 = v74[14];
        if ( !v75 )
          v75 = *v74;
        printk(&unk_27E09, v75, "aw882xx_append_channel_suffix");
        v76 = *(_QWORD *)(v8 + 96);
        v136 = 0;
        v137 = 0;
        v77 = *(_DWORD *)(v76 + 52);
        v134 = 0;
        v135 = 0;
        v132 = 0;
        v133 = 0;
        *(_QWORD *)s = 0;
        v131 = 0;
        snprintf(s, 0x40u, "%s_%d", "Speaker_Capture", v77);
        v78 = ((__int64 (__fastcall *)(_QWORD, char *))aw882xx_devm_kstrdup)(*(_QWORD *)(v8 + 64), s);
        v65[13] = v78;
        if ( v78 )
        {
          v79 = *(__int64 **)(v8 + 64);
          v80 = v79[14];
          if ( !v80 )
            v80 = *v79;
          printk(&unk_27E09, v80, "aw882xx_append_channel_suffix");
          dev_set_name(*(_QWORD *)(v8 + 64), "%s_%d", "aw882xx_smartpa", *(_DWORD *)(*(_QWORD *)(v8 + 96) + 52LL));
          v81 = *(__int64 **)(v8 + 64);
          v82 = v81[14];
          if ( !v82 )
            v82 = *v81;
          v83 = &unk_22C09;
          v84 = "aw882xx_dai_drv_append_suffix";
LABEL_140:
          printk(v83, v82, v84);
          v109 = *(__int64 **)(v8 + 64);
          v110 = v109[14];
          if ( !v110 )
            v110 = *v109;
          printk(&unk_2224A, v110, "aw882xx_dai_drv_append_suffix");
          v111 = *(__int64 **)(v8 + 64);
          v112 = v111[14];
          if ( !v112 )
            v112 = *v111;
          printk(&unk_2505F, v112, "aw882xx_dai_drv_append_suffix");
          v113 = *(__int64 **)(v8 + 64);
          v114 = v113[14];
          if ( !v114 )
            v114 = *v113;
          printk(&unk_27A81, v114, "aw882xx_dai_drv_append_suffix");
        }
      }
    }
  }
  else
  {
    v95 = *(_QWORD *)(v8 + 56);
    v136 = 0;
    v137 = 0;
    v134 = 0;
    v135 = 0;
    v132 = 0;
    v133 = 0;
    v96 = *(_QWORD *)(v95 + 24);
    *(_QWORD *)s = 0;
    v131 = 0;
    snprintf(s, 0x40u, "%s-%d-%x", "aw882xx-aif", *(_DWORD *)(v96 + 1032), *(unsigned __int16 *)(v95 + 2));
    v97 = ((__int64 (__fastcall *)(_QWORD, char *))aw882xx_devm_kstrdup)(*(_QWORD *)(v8 + 64), s);
    *v65 = v97;
    if ( v97 )
    {
      v98 = *(__int64 **)(v8 + 64);
      v99 = v98[14];
      if ( !v99 )
        v99 = *v98;
      printk(&unk_27E09, v99, "aw882xx_append_i2c_suffix");
      v100 = *(_QWORD *)(v8 + 56);
      v136 = 0;
      v137 = 0;
      v134 = 0;
      v135 = 0;
      v132 = 0;
      v133 = 0;
      v101 = *(_QWORD *)(v100 + 24);
      *(_QWORD *)s = 0;
      v131 = 0;
      snprintf(s, 0x40u, "%s_%d_%x", "Speaker_Playback", *(_DWORD *)(v101 + 1032), *(unsigned __int16 *)(v100 + 2));
      v102 = ((__int64 (__fastcall *)(_QWORD, char *))aw882xx_devm_kstrdup)(*(_QWORD *)(v8 + 64), s);
      v65[19] = v102;
      if ( v102 )
      {
        v103 = *(__int64 **)(v8 + 64);
        v104 = v103[14];
        if ( !v104 )
          v104 = *v103;
        printk(&unk_27E09, v104, "aw882xx_append_i2c_suffix");
        v105 = *(_QWORD *)(v8 + 56);
        v136 = 0;
        v137 = 0;
        v134 = 0;
        v135 = 0;
        v132 = 0;
        v133 = 0;
        v106 = *(_QWORD *)(v105 + 24);
        *(_QWORD *)s = 0;
        v131 = 0;
        snprintf(s, 0x40u, "%s_%d_%x", "Speaker_Capture", *(_DWORD *)(v106 + 1032), *(unsigned __int16 *)(v105 + 2));
        v107 = ((__int64 (__fastcall *)(_QWORD, char *))aw882xx_devm_kstrdup)(*(_QWORD *)(v8 + 64), s);
        v65[13] = v107;
        if ( v107 )
        {
          v108 = *(__int64 **)(v8 + 64);
          v82 = v108[14];
          if ( !v82 )
            v82 = *v108;
          v83 = &unk_27E09;
          v84 = "aw882xx_append_i2c_suffix";
          goto LABEL_140;
        }
      }
    }
  }
  v115 = *(_QWORD *)(v8 + 64);
  v116 = *(__int64 (__fastcall **)(__int64, void *, __int64 *, __int64))(*(_QWORD *)(v8 + 48) + 32LL);
  if ( *((_DWORD *)v116 - 1) != -52928783 )
    __break(0x8228u);
  if ( (v116(v115, &soc_codec_dev_aw882xx, v65, 1) & 0x80000000) != 0 )
  {
    v117 = *(__int64 **)(v8 + 64);
    v118 = v117[14];
    if ( !v118 )
      v118 = *v117;
    printk(&unk_233CC, v118, "aw_componet_codec_register");
    v63 = -22;
    v64 = *(_QWORD *)(a1 + 144);
    if ( v64 )
      goto LABEL_96;
    goto LABEL_95;
  }
  if ( *(_DWORD *)(v8 + 20) == 1 )
  {
    dev_set_name(
      *(_QWORD *)(v8 + 64),
      "%d-00%x",
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 56) + 24LL) + 1032LL),
      *(unsigned __int16 *)(*(_QWORD *)(v8 + 56) + 2LL));
    v119 = *(__int64 **)(v8 + 64);
    v120 = v119[14];
    if ( !v120 )
      v120 = *v119;
    printk(&unk_22EB8, v120, "aw_componet_codec_register");
  }
  group = sysfs_create_group(v2, &aw882xx_attribute_group);
  if ( (group & 0x80000000) != 0 )
  {
    v122 = *(__int64 **)(v8 + 64);
    v123 = group;
    v124 = v122[14];
    if ( !v124 )
      v124 = *v122;
    printk(&unk_230C2, v124, "aw882xx_i2c_probe");
    v125 = (void (__fastcall *)(__int64 *))off_360;
    if ( *((_DWORD *)off_360 - 1) != 1820440776 )
      __break(0x8228u);
    v125(v2);
    result = v123;
  }
  else
  {
    *(_QWORD *)(a1 + 184) = v8;
    v126 = group;
    *(_BYTE *)(v8 + 72) = 0;
    *(_QWORD *)(v8 + 76) = 0xFF00000000LL;
    *(_QWORD *)(v8 + 88) = 0;
    mutex_lock(&g_aw882xx_lock);
    ++g_aw882xx_dev_cnt;
    v127 = mutex_unlock(&g_aw882xx_lock);
    smartpa_stat_update_t(v127);
    v128 = *(_QWORD *)(a1 + 144);
    if ( !v128 )
      v128 = *v2;
    printk(&unk_28113, v128, "aw882xx_i2c_probe");
    result = v126;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
