__int64 __fastcall adc5_gen3_probe(__int64 *a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 regmap; // x0
  __int64 v5; // x21
  __int64 v6; // x0
  __int64 v7; // x23
  __int64 v8; // x26
  unsigned int byname; // w28
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w21
  unsigned int v14; // w0
  __int64 v15; // x19
  __int64 next_available_child; // x0
  __int64 v17; // x1
  __int64 v18; // x2
  unsigned int v19; // w19
  __int64 v20; // x0
  unsigned __int64 v21; // x24
  __int64 v22; // x0
  __int64 v23; // x25
  __int64 v24; // x19
  __int64 matched; // x0
  char **v26; // x8
  __int64 v27; // x0
  const char **v28; // x26
  __int64 v29; // x20
  unsigned __int64 v30; // x27
  __int64 v31; // x8
  const char *v32; // x21
  unsigned int variable_u32_array; // w0
  unsigned __int64 v34; // x28
  __int64 property; // x0
  unsigned __int64 v36; // x22
  char **v37; // x8
  unsigned __int64 v38; // x10
  bool v39; // zf
  _BOOL4 v40; // w9
  unsigned int v41; // w9
  __int64 v42; // x3
  __int64 v43; // x0
  __int64 v44; // x1
  __int64 v45; // x2
  char *v46; // x8
  int v47; // w8
  int v48; // w9
  char *v49; // x8
  int v50; // w8
  unsigned int v51; // w8
  int v52; // w8
  unsigned __int64 v53; // x19
  __int64 v54; // x0
  unsigned __int64 v55; // x23
  int v56; // w8
  unsigned __int64 v57; // x22
  __int64 v58; // x21
  unsigned __int64 v59; // x20
  int v60; // w8
  int v61; // w8
  __int64 v62; // x0
  int v63; // w9
  __int64 v64; // x1
  __int64 v65; // x2
  __int64 v66; // x0
  __int64 v67; // x1
  __int64 v68; // x2
  unsigned __int64 v69; // x8
  __int64 v70; // x10
  unsigned __int64 v71; // x8
  __int64 v72; // x9
  __int64 v73; // x8
  __int64 v74; // x9
  __int64 v75; // x10
  __int64 v76; // x8
  int v78; // w19
  __int64 v79; // x8
  unsigned int v80; // w0
  __int64 v81; // x8
  __int64 v82; // x0
  __int64 v83; // x1
  __int64 v84; // x2
  unsigned int v85; // w8
  unsigned int i; // w19
  __int64 *v87; // [xsp+8h] [xbp-A8h]
  __int64 v88; // [xsp+10h] [xbp-A0h]
  _QWORD *v89; // [xsp+18h] [xbp-98h]
  char **v90; // [xsp+20h] [xbp-90h]
  __int64 v91; // [xsp+28h] [xbp-88h]
  unsigned __int64 v92; // [xsp+30h] [xbp-80h]
  __int64 v93; // [xsp+38h] [xbp-78h]
  unsigned __int64 v94; // [xsp+38h] [xbp-78h]
  __int64 v95; // [xsp+50h] [xbp-60h]
  __int64 v96; // [xsp+58h] [xbp-58h]
  unsigned __int64 v97; // [xsp+60h] [xbp-50h]
  unsigned __int64 v98; // [xsp+68h] [xbp-48h]
  unsigned __int64 v99; // [xsp+70h] [xbp-40h]
  int v100; // [xsp+7Ch] [xbp-34h] BYREF
  __int64 v101; // [xsp+80h] [xbp-30h] BYREF
  _QWORD v102[2]; // [xsp+88h] [xbp-28h] BYREF
  int v103; // [xsp+98h] [xbp-18h]
  _QWORD v104[2]; // [xsp+A0h] [xbp-10h] BYREF

  v104[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[95];
  v3 = a1[14];
  v100 = 0;
  v103 = 0;
  v102[0] = 0;
  v102[1] = 0;
  regmap = dev_get_regmap(v3, 0);
  if ( !regmap )
  {
    byname = -19;
    goto LABEL_152;
  }
  v5 = regmap;
  v6 = devm_iio_device_alloc(a1 + 2, 256);
  if ( !v6 )
    goto LABEL_150;
  v7 = *(_QWORD *)(v6 + 1040);
  v8 = v6;
  *(_QWORD *)v7 = v5;
  *(_QWORD *)(v7 + 8) = a1 + 2;
  byname = of_property_count_elems_of_size(v2, &unk_9274, 4);
  if ( (byname & 0x80000000) != 0 )
    goto LABEL_152;
  v10 = *(_QWORD *)(v7 + 8);
  *(_DWORD *)(v7 + 36) = byname;
  v11 = devm_kmalloc(v10, byname, 3520);
  *(_QWORD *)(v7 + 240) = v11;
  if ( !v11
    || (v12 = devm_kmalloc(*(_QWORD *)(v7 + 8), 24LL * *(unsigned int *)(v7 + 36), 3520),
        (*(_QWORD *)(v7 + 24) = v12) == 0) )
  {
LABEL_150:
    byname = -12;
    goto LABEL_152;
  }
  v96 = v2;
  if ( *(_DWORD *)(v7 + 36) )
  {
    v13 = 0;
    while ( 1 )
    {
      v14 = of_property_read_u32_index(v96, &unk_9274, v13, &v100);
      if ( (v14 & 0x80000000) != 0 )
        break;
      *(_WORD *)(*(_QWORD *)(v7 + 24) + 24LL * (int)v13) = v100;
      scnprintf(v102, 20, "adc-sdam%d", v13);
      byname = of_irq_get_byname(v96, v102);
      if ( (byname & 0x80000000) != 0 )
      {
        printk(&unk_9278, v13, byname);
        goto LABEL_152;
      }
      v15 = 24LL * (int)v13;
      *(_DWORD *)(*(_QWORD *)(v7 + 24) + v15 + 16) = byname;
      *(_QWORD *)(*(_QWORD *)(v7 + 24) + v15 + 8) = devm_kstrdup(*(_QWORD *)(v7 + 8), v102, 3264);
      if ( !*(_QWORD *)(*(_QWORD *)(v7 + 24) + v15 + 8) )
        goto LABEL_150;
      if ( ++v13 >= *(_DWORD *)(v7 + 36) )
        goto LABEL_12;
    }
LABEL_163:
    byname = v14;
    goto LABEL_152;
  }
LABEL_12:
  if ( (of_property_read_variable_u32_array(v96, "qcom,debug-base", &v100, 1, 0) & 0x80000000) == 0 )
    *(_WORD *)(v7 + 32) = v100;
  a1[21] = v7;
  *(_QWORD *)(v8 + 1024) = &adc5_gen3_info;
  *(_DWORD *)(v7 + 64) = 0;
  _init_swait_queue_head(v7 + 72, "&x->wait", &init_completion___key);
  _mutex_init(v7 + 96, "&adc->lock", &adc5_gen3_probe___key);
  *(_DWORD *)(v7 + 248) = 0;
  next_available_child = of_get_next_available_child(v96, 0);
  if ( !next_available_child )
  {
    *(_DWORD *)(v7 + 40) = 0;
LABEL_173:
    byname = -22;
    goto LABEL_174;
  }
  v17 = next_available_child;
  v19 = 0;
  do
  {
    ++v19;
    v17 = of_get_next_available_child(v96, v17);
  }
  while ( v17 );
  *(_DWORD *)(v7 + 40) = v19;
  if ( !v19 )
    goto LABEL_173;
  v20 = devm_kmalloc(*(_QWORD *)(v7 + 8), 160LL * v19, 3520);
  *(_QWORD *)(v7 + 56) = v20;
  if ( !v20
    || (v21 = 200LL * *(unsigned int *)(v7 + 40),
        v22 = devm_kmalloc(*(_QWORD *)(v7 + 8), v21, 3520),
        (*(_QWORD *)(v7 + 48) = v22) == 0) )
  {
    byname = -12;
    goto LABEL_174;
  }
  v23 = v22;
  v24 = *(_QWORD *)(v7 + 56);
  v87 = a1;
  *(_DWORD *)(v7 + 144) = 0;
  matched = of_match_node(&_mod_of__adc5_match_table_device_table, v96);
  v26 = &adc5_gen3_data_pmic;
  v88 = v8;
  v89 = a1 + 2;
  if ( matched )
    v26 = *(char ***)(matched + 192);
  v90 = v26;
  v27 = of_get_next_available_child(v96, 0);
  if ( !v27 )
  {
LABEL_153:
    if ( *(_DWORD *)(v7 + 36) )
    {
      v78 = 0;
      while ( 1 )
      {
        v79 = *(_QWORD *)(v7 + 24) + 24LL * v78;
        v80 = devm_request_threaded_irq(v89, *(unsigned int *)(v79 + 16), adc5_gen3_isr, 0, 0, *(_QWORD *)(v79 + 8), v7);
        if ( (v80 & 0x80000000) != 0 )
          break;
        if ( (unsigned int)++v78 >= *(_DWORD *)(v7 + 36) )
          goto LABEL_157;
      }
    }
    else
    {
LABEL_157:
      v80 = adc_tm_register_tzd(v7);
      if ( (v80 & 0x80000000) == 0 )
      {
        if ( *(_DWORD *)(v7 + 144) )
        {
          *(_QWORD *)(v7 + 176) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v7 + 184) = v7 + 184;
          *(_QWORD *)(v7 + 192) = v7 + 184;
          *(_QWORD *)(v7 + 200) = tm_handler_work;
          *(_QWORD *)(v7 + 208) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v7 + 216) = v7 + 216;
          *(_QWORD *)(v7 + 224) = v7 + 216;
          *(_QWORD *)(v7 + 232) = tm_err_handler_work;
        }
        *(_QWORD *)(v88 + 104) = v89;
        *(_QWORD *)(v88 + 752) = v96;
        v81 = *v87;
        *(_DWORD *)v88 = 1;
        *(_QWORD *)(v88 + 1008) = v81;
        *(_QWORD *)(v88 + 992) = *(_QWORD *)(v7 + 56);
        *(_DWORD *)(v88 + 1000) = *(_DWORD *)(v7 + 40);
        list_add_tail((_QWORD *)(v7 + 152), &adc_tm_device_list);
        *(_QWORD *)(v7 + 168) = &adc_tm_device_list;
        v82 = ipc_log_context_create(10, "adc5-gen3", 0);
        *(_QWORD *)(v7 + 16) = v82;
        if ( !v82 )
          printk(&unk_9813, v83, v84);
        v14 = _devm_iio_device_register(v89, v88, &_this_module);
        goto LABEL_163;
      }
    }
    byname = v80;
    goto LABEL_175;
  }
  v28 = (const char **)v27;
  v29 = 0;
  v30 = 192;
  v91 = v7;
  while ( 1 )
  {
    v31 = *(_QWORD *)(v7 + 8);
    v32 = *v28;
    v95 = v24;
    v101 = 0;
    v93 = v31;
    v104[0] = 0;
    variable_u32_array = of_property_read_variable_u32_array(v28, &unk_9274, (char *)&v101 + 4, 1, 0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      byname = variable_u32_array;
      dev_err(v93, "invalid channel number %s\n", v32);
      goto LABEL_174;
    }
    v34 = v30 - 192;
    property = of_find_property(v28, "qcom,adc5-gen4", 0);
    v36 = v30 - 156;
    v37 = &adc5_gen4_data_pmic;
    if ( !property )
      v37 = v90;
    if ( v21 < v36 )
      goto LABEL_182;
    v38 = v23 + v30;
    v39 = v90 == &adc5_gen3_data_pmic && property == 0;
    v98 = v30 - 128;
    v99 = v23 + v30;
    v40 = !v39;
    *(_DWORD *)(v38 - 156) = v40;
    if ( v21 <= v30 - 128 )
      goto LABEL_182;
    v41 = HIDWORD(v101);
    v97 = v23 + v30;
    v42 = BYTE4(v101);
    *(_QWORD *)(v23 + v30 - 128) = v37;
    HIDWORD(v101) = (unsigned __int8)v41;
    if ( (unsigned __int8)v41 > 0xF8u || !*(_QWORD *)&v37[3][32 * v42] )
    {
      dev_err(v93, "%s invalid channel number %d\n", v32, v42);
      goto LABEL_173;
    }
    if ( v21 <= v30 - 160 )
      goto LABEL_182;
    *(_DWORD *)(v23 + v30 - 160) = (v41 >> 13) & 3;
    if ( v21 <= v34 )
      goto LABEL_182;
    *(_DWORD *)(v38 - 192) = v42;
    if ( v21 < v30 - 180 )
      goto LABEL_182;
    *(_DWORD *)(v23 + v30 - 180) = (v41 >> 8) & 0x1F;
    v43 = of_get_property(v28, "label", 0);
    if ( !v43 )
    {
      v43 = (__int64)*v28;
      if ( !*v28 )
      {
        printk(&unk_98DC, v44, v45);
        goto LABEL_173;
      }
    }
    if ( v21 <= v30 - 144 )
      goto LABEL_182;
    *(_QWORD *)(v23 + v30 - 144) = v43;
    if ( (of_property_read_variable_u32_array(v28, "qcom,decimation", &v101, 1, 0) & 0x80000000) != 0 )
    {
      if ( v21 < v36 )
        goto LABEL_182;
      if ( *(_DWORD *)(v99 - 156) )
      {
        if ( v21 <= v30 - 184 )
          goto LABEL_182;
        v48 = 1;
      }
      else
      {
        if ( v21 <= v30 - 184 )
          goto LABEL_182;
        v48 = 2;
      }
      *(_DWORD *)(v23 + v30 - 184) = v48;
    }
    else
    {
      v46 = v90[5];
      if ( *(_DWORD *)v46 == (_DWORD)v101 )
      {
        v47 = 0;
      }
      else if ( *((_DWORD *)v46 + 1) == (_DWORD)v101 )
      {
        v47 = 1;
      }
      else
      {
        if ( *((_DWORD *)v46 + 2) != (_DWORD)v101 )
        {
          dev_err(v93, "%02x invalid decimation %d\n", HIDWORD(v101), v101);
          byname = -2;
          goto LABEL_174;
        }
        v47 = 2;
      }
      if ( v21 <= v30 - 184 )
        goto LABEL_182;
      *(_DWORD *)(v23 + v30 - 184) = v47;
    }
    if ( (of_property_read_variable_u32_array(v28, "qcom,pre-scaling", v104, 2, 0) & 0x80000000) != 0 )
    {
      if ( v21 <= v98 || v21 <= v34 )
        goto LABEL_182;
      byname = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v97 - 128) + 24LL) + 32LL * *(unsigned int *)(v99 - 192) + 8);
    }
    else
    {
      byname = qcom_adc5_prescaling_from_dt(LODWORD(v104[0]), HIDWORD(v104[0]));
      if ( (byname & 0x80000000) != 0 )
      {
        dev_err(v93, "%02x invalid pre-scaling <%d %d>\n", HIDWORD(v101), LODWORD(v104[0]), HIDWORD(v104[0]));
        goto LABEL_174;
      }
    }
    if ( v21 <= v30 - 176 )
      goto LABEL_182;
    *(_DWORD *)(v23 + v30 - 176) = byname;
    if ( (of_property_read_variable_u32_array(v28, "qcom,hw-settle-time", &v101, 1, 0) & 0x80000000) != 0
      || (v49 = v90[6], *(_DWORD *)v49 == (_DWORD)v101) )
    {
      v50 = 0;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 1) == (_DWORD)v101 )
    {
      v50 = 1;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 2) == (_DWORD)v101 )
    {
      v50 = 2;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 3) == (_DWORD)v101 )
    {
      v50 = 3;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 4) == (_DWORD)v101 )
    {
      v50 = 4;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 5) == (_DWORD)v101 )
    {
      v50 = 5;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 6) == (_DWORD)v101 )
    {
      v50 = 6;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 7) == (_DWORD)v101 )
    {
      v50 = 7;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 8) == (_DWORD)v101 )
    {
      v50 = 8;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 9) == (_DWORD)v101 )
    {
      v50 = 9;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 10) == (_DWORD)v101 )
    {
      v50 = 10;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 11) == (_DWORD)v101 )
    {
      v50 = 11;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 12) == (_DWORD)v101 )
    {
      v50 = 12;
      goto LABEL_69;
    }
    if ( *((_DWORD *)v49 + 13) != (_DWORD)v101 )
      break;
    v50 = 13;
LABEL_149:
    v7 = v91;
LABEL_69:
    if ( v21 < v30 - 172 )
      goto LABEL_182;
    *(_DWORD *)(v23 + v30 - 172) = v50;
    if ( (of_property_read_variable_u32_array(v28, "qcom,avg-samples", &v101, 1, 0) & 0x80000000) != 0 )
    {
      v52 = 0;
    }
    else
    {
      if ( !(_DWORD)v101
        || (unsigned int)v101 > 0x10
        || (v51 = ((v101 - (((unsigned int)v101 >> 1) & 0x55555555)) & 0x33333333)
                + ((((unsigned int)v101 - (((unsigned int)v101 >> 1) & 0x55555555)) >> 2) & 0x33333333),
            (16843009 * ((v51 + (v51 >> 4)) & 0xF0F0F0F)) >> 24 > 1uLL) )
      {
        dev_err(v93, "%02x invalid avg-samples %d\n", HIDWORD(v101), v101);
        goto LABEL_173;
      }
      v52 = __clz(__rbit64((unsigned int)v101));
    }
    if ( v21 <= v30 - 168 )
      goto LABEL_182;
    v53 = v23 + v30;
    *(_DWORD *)(v23 + v30 - 168) = v52;
    if ( v21 <= v30 - 152 )
      goto LABEL_182;
    *(_DWORD *)(v53 - 152) = -22;
    if ( (of_property_read_variable_u32_array(v28, "qcom,scale-fn-type", &v101, 1, 0) & 0x80000000) == 0
      && (unsigned int)v101 <= 0x1B )
    {
      if ( v21 <= v30 - 152 )
        goto LABEL_182;
      *(_DWORD *)(v53 - 152) = v101;
    }
    v54 = of_find_property(v28, "qcom,ratiometric", 0);
    if ( v21 < v30 - 188 )
      goto LABEL_182;
    v92 = v30 - 152;
    v94 = v23 + v30;
    v55 = v30 - 112;
    v56 = v54 ? 1 : 2;
    v57 = v23 + v30;
    *(_DWORD *)(v23 + v30 - 188) = v56;
    if ( v21 <= v55 )
      goto LABEL_182;
    *(_DWORD *)(v57 - 112) = 1;
    if ( v21 <= v30 - 120 )
      goto LABEL_182;
    v58 = v29;
    v59 = v23 + v30;
    *(_DWORD *)(v23 + v30 - 120) = 0;
    if ( (of_property_read_variable_u32_array(v28, "qcom,adc-tm-type", &v101, 1, 0) & 0x80000000) != 0
      || (v60 = v101, (unsigned int)v101 > 3) )
    {
      if ( *(_DWORD *)(v59 - 120) != 3 )
        goto LABEL_96;
    }
    else
    {
      *(_DWORD *)(v59 - 120) = v101;
      if ( v60 != 3 )
        goto LABEL_96;
    }
    if ( (of_property_read_variable_u32_array(v28, "qcom,rscale-type", v23 + v30, 1, 0) & 0x80000000) != 0 )
    {
      if ( v21 <= v30 )
        goto LABEL_182;
      *(_DWORD *)(v23 + v30) = 1;
    }
LABEL_96:
    if ( v21 <= v30 - 120 )
      goto LABEL_182;
    v61 = *(_DWORD *)(v59 - 120);
    v62 = v96;
    if ( (v61 | 2) != 2 )
    {
      v63 = 8 * *(_DWORD *)(v91 + 36);
      v64 = (unsigned int)(*(_DWORD *)(v91 + 144) + 1);
      *(_DWORD *)(v91 + 144) = v64;
      v65 = (unsigned int)(v63 - 1);
      if ( (unsigned int)v64 > (unsigned int)v65 )
      {
        printk(&unk_92AA, v64, v65);
        v7 = v91;
        goto LABEL_173;
      }
      if ( v21 < v30 - 164 )
        goto LABEL_182;
      *(_DWORD *)(v23 + v30 - 164) = (unsigned int)v64 >> 3;
      if ( v21 < v30 - 116 )
        goto LABEL_182;
      *(_DWORD *)(v23 + v30 - 116) = v64 & 7;
      if ( v21 <= v55 )
        goto LABEL_182;
      *(_DWORD *)(v57 - 112) = 4;
      if ( v61 == 3 )
      {
        v66 = alloc_workqueue("adc_tm_notify_wq", 16, 0);
        if ( v21 <= v30 - 56 )
          goto LABEL_182;
        v7 = v91;
        *(_QWORD *)(v23 + v30 - 56) = v66;
        if ( !v66 )
        {
          printk(&unk_979A, v67, v68);
          byname = -12;
          goto LABEL_174;
        }
        if ( v21 <= v30 - 48 )
          goto LABEL_182;
        v69 = v23 + v30;
        *(_QWORD *)(v69 - 48) = 0xFFFFFFFE00000LL;
        v70 = v23 + v30 - 40;
        *(_QWORD *)(v69 - 40) = v70;
        *(_QWORD *)(v69 - 32) = v70;
        if ( v21 <= v30 - 24 )
          goto LABEL_182;
        v62 = v96;
        *(_QWORD *)(v23 + v30 - 24) = notify_adc_tm_fn;
      }
      v71 = v23 + v30;
      *(_QWORD *)(v71 - 16) = v71 - 16;
      *(_QWORD *)(v71 - 8) = v71 - 16;
    }
    if ( v21 <= v30 - 136 )
      goto LABEL_182;
    v7 = v91;
    *(_QWORD *)(v23 + v30 - 136) = v91;
    if ( v21 <= v92 || v21 <= v98 || v21 <= v30 - 192 )
      goto LABEL_182;
    v72 = *(_QWORD *)(v97 - 128);
    v73 = *(unsigned int *)(v99 - 192);
    if ( *(_DWORD *)(v94 - 152) == -22 )
    {
      if ( v21 <= v92 )
        goto LABEL_182;
      *(_DWORD *)(v94 - 152) = *(_DWORD *)(*(_QWORD *)(v72 + 24) + 32 * v73 + 24);
    }
    v74 = *(_QWORD *)(v72 + 24);
    *(_DWORD *)(v95 + 4) = v73;
    if ( v21 <= v30 - 144 )
LABEL_182:
      __break(1u);
    v75 = *(_QWORD *)(v23 + v30 - 144);
    v76 = v74 + 32 * v73;
    *(_QWORD *)(v95 + 136) = v75;
    *(_QWORD *)(v95 + 144) = v75;
    *(_QWORD *)(v95 + 48) = *(_QWORD *)(v76 + 16);
    LODWORD(v76) = *(_DWORD *)(v76 + 12);
    *(_QWORD *)(v95 + 16) = v58;
    v29 = v58 + 1;
    *(_DWORD *)v95 = v76;
    v24 = v95 + 160;
    v28 = (const char **)of_get_next_available_child(v62, v28);
    v30 += 200LL;
    if ( !v28 )
      goto LABEL_153;
  }
  if ( *((_DWORD *)v49 + 14) == (_DWORD)v101 )
  {
    v50 = 14;
    goto LABEL_149;
  }
  if ( *((_DWORD *)v49 + 15) == (_DWORD)v101 )
  {
    v50 = 15;
    goto LABEL_149;
  }
  dev_err(v93, "%02x invalid hw-settle-time %d us\n", HIDWORD(v101), v101);
  v7 = v91;
  byname = -2;
LABEL_174:
  printk(&unk_963A, v17, v18);
LABEL_175:
  v85 = *(_DWORD *)(v7 + 40);
  if ( v85 )
  {
    for ( i = 0; i < v85; ++i )
    {
      if ( *(_QWORD *)(*(_QWORD *)(v7 + 48) + 200LL * (int)i + 136) )
      {
        destroy_workqueue();
        v85 = *(_DWORD *)(v7 + 40);
      }
    }
  }
LABEL_152:
  _ReadStatusReg(SP_EL0);
  return byname;
}
