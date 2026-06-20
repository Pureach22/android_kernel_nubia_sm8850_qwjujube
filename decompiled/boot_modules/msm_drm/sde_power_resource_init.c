__int64 __fastcall sde_power_resource_init(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  int string_helper; // w0
  unsigned int v6; // w23
  __int64 v7; // x0
  __int64 v8; // x20
  __int64 v9; // x22
  __int64 v10; // x28
  char *v11; // x27
  __int64 v12; // x23
  size_t v13; // x0
  unsigned __int64 v14; // x2
  bool v15; // zf
  int v16; // w9
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 child_by_name; // x0
  __int64 v22; // x22
  __int64 next_child; // x0
  __int64 v24; // x1
  __int64 v25; // x8
  __int64 v26; // x20
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x23
  int v30; // w20
  __int64 v31; // x0
  char *v32; // x28
  __int64 v33; // x25
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x28
  int v39; // w0
  int v40; // w8
  int v41; // w0
  int v42; // w8
  int v43; // w0
  int v44; // w8
  int v45; // w0
  int v46; // w8
  unsigned __int64 vreg; // x0
  __int64 v48; // x0
  __int64 v49; // x1
  int v50; // w2
  unsigned __int64 clk; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  int v55; // w22
  __int64 v56; // x0
  unsigned __int64 v57; // x0
  unsigned int *property; // x0
  __int64 v59; // x22
  __int64 v60; // x27
  char **v61; // x20
  char *v62; // x28
  unsigned int *v63; // x23
  unsigned __int64 v64; // x0
  unsigned __int64 v65; // x0
  unsigned int v66; // w26
  unsigned __int64 v67; // x0
  unsigned int v68; // w28
  int v69; // w8
  unsigned __int64 v70; // x26
  __int64 v71; // x3
  unsigned int *v72; // x23
  unsigned int v73; // w8
  __int64 v74; // x0
  __int64 result; // x0
  __int64 v76; // x22
  unsigned int v77; // w22
  void *v78; // x0
  unsigned int v79; // w8
  __int64 v80; // x0
  __int64 v81; // x0
  unsigned int v82; // w8
  __int64 v83; // x0
  __int64 v84; // x0
  unsigned int v85; // w8
  __int64 v86; // x0
  __int64 v87; // x0
  unsigned int v88; // w8
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 v91; // x21
  __int64 v92; // x3
  void *v93; // x0
  __int64 v94; // [xsp+8h] [xbp-48h]
  __int64 v95; // [xsp+10h] [xbp-40h] BYREF
  __int64 v96; // [xsp+18h] [xbp-38h] BYREF
  __int64 v97; // [xsp+20h] [xbp-30h] BYREF
  char *string[5]; // [xsp+28h] [xbp-28h] BYREF

  string[4] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    printk(&unk_22518D, "sde_power_resource_init");
    result = 4294967274LL;
    goto LABEL_147;
  }
  v94 = a1 + 16;
  *((_QWORD *)a2 + 12) = a1 + 16;
  *((_QWORD *)a2 + 43) = a2 + 86;
  *((_QWORD *)a2 + 44) = a2 + 86;
  _mutex_init(a2 + 12, "&phandle->phandle_lock", &sde_power_resource_init___key);
  a2[8] = 0;
  v4 = *(_QWORD *)(a1 + 760);
  string[0] = nullptr;
  LODWORD(v96) = 0;
  v95 = 0;
  string_helper = of_property_read_string_helper(v4, "clock-names", 0, 0, 0);
  if ( string_helper >= 1 )
  {
    v6 = string_helper;
    a2[8] = string_helper;
    v7 = devm_kmalloc(v94, 120LL * (unsigned int)string_helper, 3520);
    *((_QWORD *)a2 + 5) = v7;
    if ( !v7 )
    {
      a2[8] = 0;
      printk(&unk_228486, "sde_power_resource_init");
      result = 4294967284LL;
      goto LABEL_147;
    }
    v8 = 0;
    v9 = 0;
    v10 = v6;
    while ( 1 )
    {
      of_property_read_string_helper(*(_QWORD *)(a1 + 760), "clock-names", string, 1, (unsigned int)v9);
      v11 = string[0];
      v12 = *((_QWORD *)a2 + 5);
      v13 = strnlen(string[0], 0x20u);
      if ( v13 == -1 )
        goto LABEL_160;
      v14 = v13 == 32 ? 32LL : v13 + 1;
      if ( v14 >= 0x21 )
        break;
      sized_strscpy(v12 + v8 + 8, v11);
      of_property_read_u32_index(*(_QWORD *)(a1 + 760), "clock-rate", (unsigned int)v9, &v96);
      v15 = (unsigned int)v96 == 0;
      *(_QWORD *)(*((_QWORD *)a2 + 5) + v8 + 48) = (unsigned int)v96;
      v16 = !v15;
      *(_DWORD *)(*((_QWORD *)a2 + 5) + v8 + 40) = v16;
      v17 = *(_QWORD *)(a1 + 760);
      HIDWORD(v95) = 0;
      of_property_read_u32_index(v17, "clock-mmrm", (unsigned int)v9, (char *)&v95 + 4);
      v18 = *(_QWORD *)(a1 + 760);
      LODWORD(v95) = 0;
      of_property_read_u32_index(v18, "clock-max-rate", (unsigned int)v9++, &v95);
      v19 = *((_QWORD *)a2 + 5) + v8;
      v8 += 120;
      *(_QWORD *)(v19 + 56) = (unsigned int)v95;
      if ( v10 == v9 )
        goto LABEL_15;
    }
LABEL_159:
    v13 = _fortify_panic(7, 32, v14);
LABEL_160:
    _fortify_panic(2, -1, v13 + 1);
  }
LABEL_15:
  v20 = *(_QWORD *)(a1 + 760);
  LODWORD(v96) = 0;
  *a2 = 0;
  child_by_name = of_get_child_by_name(v20, "qcom,platform-supply-entries");
  if ( child_by_name )
  {
    v22 = child_by_name;
    next_child = of_get_next_child(child_by_name, 0);
    if ( next_child )
    {
      v24 = next_child;
      do
      {
        ++*a2;
        v24 = of_get_next_child(v22, v24);
      }
      while ( v24 );
    }
    v25 = *a2;
    if ( (_DWORD)v25 )
    {
      v26 = v94;
      v27 = devm_kmalloc(v94, 72 * v25, 3520);
      *((_QWORD *)a2 + 1) = v27;
      if ( !v27 )
      {
        v76 = 4294967284LL;
        goto LABEL_157;
      }
      v28 = of_get_next_child(v22, 0);
      if ( v28 )
      {
        v29 = v28;
        v30 = 0;
        while ( 1 )
        {
          string[0] = nullptr;
          v31 = of_property_read_string(v29, "qcom,supply-name", string);
          if ( (_DWORD)v31 )
            break;
          v32 = string[0];
          v33 = *((_QWORD *)a2 + 1);
          v13 = strnlen(string[0], 0x20u);
          if ( v13 == -1 )
            goto LABEL_160;
          if ( v13 == 32 )
            v14 = 32;
          else
            v14 = v13 + 1;
          if ( v14 >= 0x21 )
            goto LABEL_159;
          sized_strscpy(v33 + 72LL * v30 + 8, v32);
          v34 = of_property_read_variable_u32_array(v29, "qcom,supply-min-voltage", &v96, 1, 0);
          if ( (v34 & 0x80000000) != 0 )
          {
            v92 = v34;
            v93 = &unk_216CE0;
            goto LABEL_155;
          }
          *(_DWORD *)(*((_QWORD *)a2 + 1) + 72LL * v30 + 40) = v96;
          v35 = of_property_read_variable_u32_array(v29, "qcom,supply-max-voltage", &v96, 1, 0);
          if ( (v35 & 0x80000000) != 0 )
          {
            v92 = v35;
            v93 = &unk_22BA0D;
            goto LABEL_155;
          }
          *(_DWORD *)(*((_QWORD *)a2 + 1) + 72LL * v30 + 44) = v96;
          v36 = of_property_read_variable_u32_array(v29, "qcom,supply-enable-load", &v96, 1, 0);
          if ( (v36 & 0x80000000) != 0 )
          {
            v92 = v36;
            v93 = &unk_277E84;
            goto LABEL_155;
          }
          *(_DWORD *)(*((_QWORD *)a2 + 1) + 72LL * v30 + 48) = v96;
          v37 = of_property_read_variable_u32_array(v29, "qcom,supply-disable-load", &v96, 1, 0);
          if ( (v37 & 0x80000000) != 0 )
          {
            v92 = v37;
            v93 = &unk_21E7E4;
            goto LABEL_155;
          }
          v38 = 72LL * v30;
          *(_DWORD *)(*((_QWORD *)a2 + 1) + v38 + 52) = v96;
          v39 = of_property_read_variable_u32_array(v29, "qcom,supply-pre-on-sleep", &v96, 1, 0);
          v40 = v96;
          if ( v39 < 0 )
            v40 = 0;
          *(_DWORD *)(*((_QWORD *)a2 + 1) + v38 + 56) = v40;
          v41 = of_property_read_variable_u32_array(v29, "qcom,supply-pre-off-sleep", &v96, 1, 0);
          v42 = v96;
          if ( v41 < 0 )
            v42 = 0;
          *(_DWORD *)(*((_QWORD *)a2 + 1) + v38 + 64) = v42;
          v43 = of_property_read_variable_u32_array(v29, "qcom,supply-post-on-sleep", &v96, 1, 0);
          v44 = v96;
          if ( v43 < 0 )
            v44 = 0;
          *(_DWORD *)(*((_QWORD *)a2 + 1) + v38 + 60) = v44;
          v45 = of_property_read_variable_u32_array(v29, "qcom,supply-post-off-sleep", &v96, 1, 0);
          v46 = v96;
          ++v30;
          if ( v45 < 0 )
            v46 = 0;
          *(_DWORD *)(*((_QWORD *)a2 + 1) + v38 + 68) = v46;
          v29 = of_get_next_child(v22, v29);
          if ( !v29 )
            goto LABEL_42;
        }
        v92 = v31;
        v93 = &unk_274AB4;
LABEL_155:
        v76 = v92;
        printk(v93, "sde_power_parse_dt_supply");
        v26 = v94;
        if ( *((_QWORD *)a2 + 1) )
        {
          *((_QWORD *)a2 + 1) = 0;
          *a2 = 0;
        }
LABEL_157:
        printk(&unk_216CAE, "sde_power_resource_init");
        if ( !*((_QWORD *)a2 + 5) )
          goto LABEL_146;
        goto LABEL_145;
      }
    }
  }
LABEL_42:
  v26 = v94;
  vreg = msm_dss_get_vreg(v94, *((_QWORD *)a2 + 1), *a2, 1);
  if ( (_DWORD)vreg )
  {
    v76 = vreg;
    printk(&unk_26D9CE, "sde_power_resource_init");
    if ( !*((_QWORD *)a2 + 1) )
    {
LABEL_144:
      *a2 = 0;
      if ( !*((_QWORD *)a2 + 5) )
      {
LABEL_146:
        a2[8] = 0;
        result = v76;
        goto LABEL_147;
      }
LABEL_145:
      devm_kfree(v26);
      *((_QWORD *)a2 + 5) = 0;
      goto LABEL_146;
    }
LABEL_143:
    devm_kfree(v26);
    *((_QWORD *)a2 + 1) = 0;
    goto LABEL_144;
  }
  v48 = of_count_phandle_with_args(*(_QWORD *)(*((_QWORD *)a2 + 12) + 744LL), "power-domains", "#power-domain-cells");
  if ( (v48 & 0x80000000) != 0 )
  {
    if ( (_DWORD)v48 != -2 )
    {
      v91 = v48;
      printk(&unk_21A96C, "sde_power_update_power_domains_count");
      v76 = v91;
      printk(&unk_274A31, "sde_power_resource_init");
LABEL_142:
      a2[118] = 0;
      if ( !*((_QWORD *)a2 + 1) )
        goto LABEL_144;
      goto LABEL_143;
    }
    LODWORD(v48) = 0;
  }
  v49 = *((_QWORD *)a2 + 5);
  v50 = a2[8];
  a2[118] = v48;
  clk = msm_dss_get_clk(v94, v49, v50);
  if ( (_DWORD)clk )
  {
    v76 = clk;
    printk(&unk_24A336, "sde_power_resource_init");
LABEL_141:
    msm_dss_get_vreg(v26, *((_QWORD *)a2 + 1), *a2, 0);
    goto LABEL_142;
  }
  v52 = msm_dss_mmrm_register(v94, (__int64)a2, (__int64)sde_power_mmrm_callback, (__int64)a2, (_BYTE *)a2 + 377);
  if ( (_DWORD)v52 )
  {
    v76 = v52;
    printk(&unk_2284B2, "sde_power_resource_init");
LABEL_140:
    msm_dss_put_clk(*((_QWORD *)a2 + 5), a2[8]);
    goto LABEL_141;
  }
  v53 = msm_dss_clk_set_rate(*((_QWORD **)a2 + 5), a2[8]);
  if ( (_DWORD)v53 )
  {
    v76 = v53;
    printk(&unk_22F3D5, "sde_power_resource_init");
LABEL_139:
    msm_dss_mmrm_deregister(v26, (__int64)a2);
    goto LABEL_140;
  }
  v54 = *(_QWORD *)(a1 + 760);
  v96 = 0;
  v97 = 0;
  v55 = of_property_count_elems_of_size(v54, "qcom,sde-ib-bw-vote", 4);
  v56 = *(_QWORD *)(a1 + 760);
  if ( v55 >= 1 )
  {
    of_property_read_u32_index(v56, "qcom,sde-ib-bw-vote", 0, &v96);
    *((_QWORD *)a2 + 48) = (unsigned int)(1000 * v96);
    v56 = *(_QWORD *)(a1 + 760);
    if ( v55 != 1 )
    {
      of_property_read_u32_index(v56, "qcom,sde-ib-bw-vote", 1, (char *)&v96 + 4);
      *((_QWORD *)a2 + 49) = (unsigned int)(1000 * HIDWORD(v96));
      v56 = *(_QWORD *)(a1 + 760);
      if ( v55 != 2 )
      {
        of_property_read_u32_index(v56, "qcom,sde-ib-bw-vote", 2, &v97);
        *((_QWORD *)a2 + 50) = (unsigned int)(1000 * v97);
        v56 = *(_QWORD *)(a1 + 760);
        if ( v55 != 3 )
        {
          of_property_read_u32_index(v56, "qcom,sde-ib-bw-vote", 3, (char *)&v97 + 4);
          *((_QWORD *)a2 + 51) = (unsigned int)(1000 * HIDWORD(v97));
          v56 = *(_QWORD *)(a1 + 760);
          if ( v55 != 4 )
          {
            of_property_read_u32_index(v56, "qcom,sde-ib-bw-vote", 4, string);
            goto LABEL_162;
          }
        }
      }
    }
    v26 = v94;
  }
  LODWORD(string[0]) = 0;
  if ( (of_property_match_string(v56, "interconnect-names", "qcom,sde-reg-bus") & 0x80000000) == 0 )
  {
    v57 = of_icc_get(v26, "qcom,sde-reg-bus");
    *((_QWORD *)a2 + 13) = v57;
    if ( v57 && v57 <= 0xFFFFFFFFFFFFF000LL )
    {
      property = (unsigned int *)of_get_property(*(_QWORD *)(a1 + 760), "qcom,sde-reg-bus,vectors-KBps", string);
      if ( property )
      {
        if ( ((__int64)string[0] & 0xFFFFFFFC) == 0x20 )
        {
          *((_QWORD *)a2 + 15) = 1000LL * bswap32(*property);
          *((_QWORD *)a2 + 16) = 1000LL * bswap32(property[1]);
          *((_QWORD *)a2 + 17) = 1000LL * bswap32(property[2]);
          *((_QWORD *)a2 + 18) = 1000LL * bswap32(property[3]);
          *((_QWORD *)a2 + 19) = 1000LL * bswap32(property[4]);
          *((_QWORD *)a2 + 20) = 1000LL * bswap32(property[5]);
          *((_QWORD *)a2 + 21) = 1000LL * bswap32(property[6]);
          *((_QWORD *)a2 + 22) = 1000LL * bswap32(property[7]);
          goto LABEL_61;
        }
        v78 = &unk_2394E3;
      }
      else
      {
        v78 = &unk_25BD46;
      }
      printk(v78, "sde_power_reg_bus_parse");
      v71 = 4294967274LL;
    }
    else
    {
      v77 = v57;
      printk(&unk_235FF9, "sde_power_icc_get");
      v71 = v77;
      *((_QWORD *)a2 + 13) = 0;
      if ( !v77 )
        goto LABEL_61;
    }
LABEL_111:
    v76 = v71;
    printk(&unk_25F915, "sde_power_resource_init");
    icc_put(*((_QWORD *)a2 + 13));
    v79 = a2[84];
    v26 = v94;
    *((_QWORD *)a2 + 13) = 0;
    if ( !v79 )
      goto LABEL_138;
    v80 = *((_QWORD *)a2 + 38);
    if ( v80 )
    {
      icc_put(v80);
      v79 = a2[84];
      *((_QWORD *)a2 + 38) = 0;
    }
    if ( v79 < 2 )
      goto LABEL_138;
    v81 = *((_QWORD *)a2 + 39);
    if ( v81 )
    {
      icc_put(v81);
      v79 = a2[84];
      *((_QWORD *)a2 + 39) = 0;
    }
    if ( v79 <= 2 )
    {
LABEL_138:
      v82 = a2[74];
      if ( !v82 )
        goto LABEL_166;
      v83 = *((_QWORD *)a2 + 33);
      if ( v83 )
      {
        icc_put(v83);
        v82 = a2[74];
        *((_QWORD *)a2 + 33) = 0;
      }
      if ( v82 < 2 )
        goto LABEL_166;
      v84 = *((_QWORD *)a2 + 34);
      if ( v84 )
      {
        icc_put(v84);
        v82 = a2[74];
        *((_QWORD *)a2 + 34) = 0;
      }
      if ( v82 <= 2 )
      {
LABEL_166:
        v85 = a2[64];
        if ( !v85 )
          goto LABEL_167;
        v86 = *((_QWORD *)a2 + 28);
        if ( v86 )
        {
          icc_put(v86);
          v85 = a2[64];
          *((_QWORD *)a2 + 28) = 0;
        }
        if ( v85 < 2 )
          goto LABEL_167;
        v87 = *((_QWORD *)a2 + 29);
        if ( v87 )
        {
          icc_put(v87);
          v85 = a2[64];
          *((_QWORD *)a2 + 29) = 0;
        }
        if ( v85 <= 2 )
        {
LABEL_167:
          v88 = a2[54];
          if ( !v88 )
            goto LABEL_139;
          v89 = *((_QWORD *)a2 + 23);
          if ( v89 )
          {
            icc_put(v89);
            v88 = a2[54];
            *((_QWORD *)a2 + 23) = 0;
          }
          if ( v88 < 2 )
            goto LABEL_139;
          v90 = *((_QWORD *)a2 + 24);
          if ( v90 )
          {
            icc_put(v90);
            v88 = a2[54];
            *((_QWORD *)a2 + 24) = 0;
          }
          if ( v88 <= 2 )
            goto LABEL_139;
        }
      }
    }
LABEL_162:
    __break(0x5512u);
    JUMPOUT(0x19612C);
  }
LABEL_61:
  v59 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,msm-bus,active-only", 0);
  v60 = 0;
  v61 = data_bus_name;
  do
  {
    if ( v60 * 4 )
    {
      v62 = *v61;
      if ( (of_property_match_string(*(_QWORD *)(a1 + 760), "interconnect-names", *v61) & 0x80000000) != 0 )
        goto LABEL_84;
      v63 = &a2[v60];
      v64 = of_icc_get(v94, v62);
      *(_QWORD *)&a2[v60 + 46] = v64;
      if ( v64 && v64 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( v63 != (unsigned int *)-216LL )
          ++v63[54];
        goto LABEL_84;
      }
      v70 = v64;
      printk(&unk_235FF9, "sde_power_icc_get");
      v71 = v70;
      *((_QWORD *)v63 + 23) = 0;
LABEL_83:
      if ( (_DWORD)v71 )
        goto LABEL_111;
      goto LABEL_84;
    }
    memset(string, 0, 32);
    snprintf((char *)string, 0x20u, "%s%d", "qcom,sde-data-bus", 0);
    if ( (of_property_match_string(*(_QWORD *)(a1 + 760), "interconnect-names", string) & 0x80000000) == 0 )
    {
      v65 = of_icc_get(v94, string);
      v66 = v65;
      *((_QWORD *)a2 + 23) = v65;
      if ( v65 && v65 <= 0xFFFFFFFFFFFFF000LL )
      {
        ++a2[54];
      }
      else
      {
        printk(&unk_235FF9, "sde_power_icc_get");
        *((_QWORD *)a2 + 23) = 0;
        if ( v66 )
          goto LABEL_89;
      }
    }
    snprintf((char *)string, 0x20u, "%s%d", "qcom,sde-data-bus", 1);
    if ( (of_property_match_string(*(_QWORD *)(a1 + 760), "interconnect-names", string) & 0x80000000) == 0 )
    {
      v67 = of_icc_get(v94, string);
      v68 = v67;
      *((_QWORD *)a2 + 24) = v67;
      if ( v67 && v67 <= 0xFFFFFFFFFFFFF000LL )
      {
        v69 = a2[54] + 1;
        a2[54] = v69;
        goto LABEL_82;
      }
      printk(&unk_235FF9, "sde_power_icc_get");
      v66 = v68;
      *((_QWORD *)a2 + 24) = 0;
      if ( v68 )
      {
LABEL_89:
        if ( a2[54] )
        {
          printk(&unk_25490A, "sde_power_mnoc_bus_parse");
          goto LABEL_84;
        }
        goto LABEL_90;
      }
    }
    v69 = a2[54];
LABEL_82:
    v66 = 0;
    v71 = 0;
    if ( v69 )
      goto LABEL_83;
LABEL_90:
    printk(&unk_258027, "sde_power_mnoc_bus_parse");
    v71 = v66;
    if ( v66 )
      goto LABEL_111;
LABEL_84:
    if ( v59 )
    {
      v72 = &a2[v60];
      v73 = a2[v60 + 54];
      LOBYTE(a2[v60 + 55]) = 1;
      if ( v73 )
      {
        icc_set_tag(*((_QWORD *)v72 + 23), 3);
        if ( v72[54] >= 2 )
        {
          icc_set_tag(*(_QWORD *)&a2[v60 + 48], 3);
          if ( v72[54] > 2 )
            goto LABEL_162;
        }
      }
    }
    v60 += 10;
    ++v61;
  }
  while ( v60 != 40 );
  v74 = *(_QWORD *)(a1 + 760);
  LODWORD(string[0]) = 0;
  LODWORD(v96) = 0;
  if ( (of_property_read_variable_u32_array(v74, "qcom,hw-fence-sw-version", string, 1, 0) & 0x80000000) == 0
    && LODWORD(string[0])
    && (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,sde-soccp-controller", &v96, 1, 0) & 0x80000000) == 0
    && (_DWORD)v96 )
  {
    *((_BYTE *)a2 + 416) = 1;
  }
  result = 0;
  *((_QWORD *)a2 + 46) = 0;
  *((_BYTE *)a2 + 376) = 0;
LABEL_147:
  _ReadStatusReg(SP_EL0);
  return result;
}
