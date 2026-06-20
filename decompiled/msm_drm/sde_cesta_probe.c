__int64 __fastcall sde_cesta_probe(_QWORD *a1)
{
  _QWORD *v1; // x21
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  unsigned int v7; // w0
  unsigned int v8; // w0
  unsigned int v9; // w0
  unsigned int v10; // w0
  int v11; // w22
  __int64 v12; // x8
  __int64 v13; // x8
  unsigned int v14; // w3
  void *v15; // x0
  unsigned int matched; // w22
  unsigned __int64 v17; // x23
  unsigned __int64 v18; // x0
  __int64 v19; // x27
  unsigned __int64 v20; // x0
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x0
  unsigned __int64 device; // x0
  unsigned __int64 v24; // x0
  _QWORD *v25; // x0
  __int64 v26; // x0
  unsigned int v27; // w0
  unsigned __int64 v28; // x0
  void (__fastcall *v29)(_QWORD); // x8
  long double v30; // q0
  int v31; // [xsp+4h] [xbp-4Ch] BYREF
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v33; // [xsp+10h] [xbp-40h]
  __int64 v34; // [xsp+18h] [xbp-38h]
  __int64 v35; // [xsp+20h] [xbp-30h]
  char v36[8]; // [xsp+28h] [xbp-28h] BYREF
  __int64 v37; // [xsp+30h] [xbp-20h]
  __int64 v38; // [xsp+38h] [xbp-18h]
  __int64 v39; // [xsp+40h] [xbp-10h]
  __int64 v40; // [xsp+48h] [xbp-8h]

  v1 = a1 + 2;
  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v38 = 0;
  v39 = 0;
  *(_QWORD *)v36 = 0;
  v37 = 0;
  v3 = devm_kmalloc(a1 + 2, 1184, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_3;
  }
  v5 = v3;
  a1[21] = v3;
  v6 = a1[95];
  *(_QWORD *)(v5 + 8) = v1;
  if ( (of_property_read_variable_u32_array(v6, "cell-index", &v31, 1, 0) & 0x80000000) != 0 )
  {
    v31 = 0;
  }
  else if ( v31 >= 1 )
  {
    printk(&unk_274E09, "sde_cesta_probe");
    result = 4294967274LL;
    goto LABEL_3;
  }
  v7 = sde_power_resource_init((__int64)a1, (unsigned int *)(v5 + 16));
  if ( v7 )
  {
    v14 = v7;
    v15 = &unk_24DA70;
LABEL_22:
    matched = v14;
LABEL_23:
    printk(v15, "sde_cesta_probe");
LABEL_24:
    sde_cesta_deinit(a1, v5);
    result = matched;
    goto LABEL_3;
  }
  v8 = msm_dss_ioremap_byname((__int64)a1, v5 + 736, (__int64)"rscc");
  if ( v8 )
  {
    v14 = v8;
    v15 = &unk_22F889;
    goto LABEL_22;
  }
  v9 = msm_dss_ioremap_byname((__int64)a1, v5 + 752, (__int64)"wrapper");
  if ( v9 )
  {
    v14 = v9;
    v15 = &unk_2583D5;
    goto LABEL_22;
  }
  v10 = msm_dss_ioremap_byname((__int64)a1, v5 + 768, (__int64)"disp_cc");
  if ( v10 )
  {
    v14 = v10;
    v15 = &unk_24DABA;
    goto LABEL_22;
  }
  v11 = 0;
  *(_DWORD *)(v5 + 724) = 0;
  do
  {
    v34 = 0;
    v35 = 0;
    *(_QWORD *)s = 0;
    v33 = 0;
    snprintf(s, 0x20u, "scc_%u", v11);
    v12 = *(unsigned int *)(v5 + 724);
    if ( (unsigned int)v12 >= 0xA )
      goto LABEL_68;
    if ( !(unsigned int)msm_dss_ioremap_byname((__int64)a1, v5 + 544 + 16 * v12, (__int64)s) )
    {
      v13 = *(unsigned int *)(v5 + 724);
      if ( (unsigned int)v13 > 8 )
        goto LABEL_68;
      *(_DWORD *)(v5 + 688 + 4 * v13) = v11;
      ++*(_DWORD *)(v5 + 724);
    }
    ++v11;
  }
  while ( v11 != 9 );
  if ( *(_DWORD *)(v5 + 724) )
  {
    v17 = 0;
    while ( 1 )
    {
      v34 = 0;
      v35 = 0;
      *(_QWORD *)s = 0;
      v33 = 0;
      snprintf(s, 0x20u, "%s-%d", "qcom,sde-data-bus-hw", v17);
      matched = of_property_match_string(a1[95], "interconnect-names", s);
      if ( (matched & 0x80000000) != 0 )
      {
        v15 = &unk_278322;
        goto LABEL_23;
      }
      v18 = of_icc_get(v1, s);
      if ( !v18 || v18 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_47;
      if ( v17 == 9 )
        goto LABEL_68;
      v19 = v5 + 8 * v17;
      *(_QWORD *)(v19 + 928) = v18;
      v20 = of_icc_get(v1, s);
      if ( !v20 || v20 >= 0xFFFFFFFFFFFFF001LL )
        break;
      v21 = *(unsigned int *)(v5 + 724);
      ++v17;
      *(_QWORD *)(v19 + 1000) = v20;
      if ( v17 >= v21 )
        goto LABEL_26;
    }
    printk(&unk_2364A3, "sde_cesta_probe");
    goto LABEL_24;
  }
LABEL_26:
  matched = of_property_match_string(a1[95], "interconnect-names", "qcom,sde-data-bus-sw-0");
  if ( (matched & 0x80000000) != 0 )
  {
    v15 = &unk_278322;
    goto LABEL_23;
  }
  v22 = of_icc_get(v1, "qcom,sde-data-bus-sw-0");
  if ( !v22 || v22 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_47:
    printk(&unk_221E1D, "sde_cesta_probe");
    goto LABEL_24;
  }
  *(_QWORD *)(v5 + 1072) = v22;
  device = crm_get_device("disp_crm");
  *(_QWORD *)(v5 + 1120) = device;
  if ( !device || device >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_24A6FE, "sde_cesta_probe");
    *(_QWORD *)(v5 + 1120) = 0;
    goto LABEL_24;
  }
  if ( a1[76] )
  {
    pm_runtime_enable(v1);
    v25 = v1;
    *(_QWORD *)(v5 + 536) = v1;
    *(_QWORD *)(v5 + 528) = 0;
  }
  else
  {
    if ( !*(_DWORD *)(v5 + 488) )
    {
      v24 = devm_regulator_get(v1, &unk_24414B);
      *(_QWORD *)(v5 + 528) = v24;
      if ( !v24 || v24 >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_263735, "sde_cesta_probe");
        *(_QWORD *)(v5 + 528) = 0;
      }
      *(_QWORD *)(v5 + 536) = 0;
      *(_BYTE *)(v5 + 484) = 1;
      goto LABEL_55;
    }
    v25 = *(_QWORD **)(v5 + 536);
  }
  *(_BYTE *)(v5 + 484) = 1;
  if ( v25 )
  {
    v27 = _pm_runtime_resume(v25, 4);
    goto LABEL_59;
  }
LABEL_55:
  v26 = *(_QWORD *)(v5 + 528);
  if ( v26 )
    v27 = regulator_enable(v26);
  else
    v27 = sde_power_enable_power_domain(v5 + 16, 0, 1);
LABEL_59:
  if ( v27 )
  {
    matched = v27;
    v15 = &unk_23CFB0;
    goto LABEL_23;
  }
  *(_BYTE *)(v5 + 920) = 1;
  *(_QWORD *)(v5 + 784) = v5 + 784;
  *(_QWORD *)(v5 + 792) = v5 + 784;
  _mutex_init(v5 + 800, "&cesta->client_lock", &sde_cesta_probe___key);
  if ( v31 )
LABEL_68:
    __break(0x5512u);
  cesta_list_0 = v5;
  v28 = devm_clk_get(v1, "xo");
  if ( v28 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_254C2D, "sde_cesta_probe");
    matched = 0;
    goto LABEL_24;
  }
  *(_QWORD *)(v5 + 728) = clk_get_rate(v28);
  sde_cesta_hw_init(v5);
  v29 = *(void (__fastcall **)(_QWORD))(v5 + 848);
  if ( *((_DWORD *)v29 - 1) != -815631913 )
    __break(0x8228u);
  v29(v5);
  snprintf(v36, 0x20u, "%s%d", "sde_cesta_", v31);
  sde_cesta_init_debugfs(v5, v36);
  printk(&unk_213A14, "sde_cesta_probe");
  result = component_add(v1, sde_cesta_comp_ops, v30);
  if ( (_DWORD)result )
  {
    matched = result;
    v15 = &unk_24A73C;
    goto LABEL_23;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
