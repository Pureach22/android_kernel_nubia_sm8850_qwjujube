unsigned __int64 __fastcall tpdm_probe(_QWORD *a1)
{
  unsigned __int64 result; // x0
  __int64 v3; // x8
  int sec_dump_state; // w8
  __int64 v5; // x0
  __int64 v6; // x20
  unsigned __int64 optional_enabled; // x0
  unsigned __int64 v8; // x22
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  _BYTE *v12; // x21
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x10
  __int64 v16; // x0
  unsigned int v17; // w20
  int v18; // [xsp+4h] [xbp-5Ch] BYREF
  _QWORD v19[2]; // [xsp+8h] [xbp-58h] BYREF
  void *v20; // [xsp+18h] [xbp-48h]
  __int64 v21; // [xsp+20h] [xbp-40h]
  _QWORD *v22; // [xsp+28h] [xbp-38h]
  _UNKNOWN **v23; // [xsp+30h] [xbp-30h]
  __int64 v24; // [xsp+38h] [xbp-28h]
  __int64 v25; // [xsp+40h] [xbp-20h]
  unsigned __int64 v26; // [xsp+48h] [xbp-18h]
  __int64 v27; // [xsp+50h] [xbp-10h]
  __int64 v28; // [xsp+58h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = nullptr;
  v23 = nullptr;
  v20 = nullptr;
  v21 = 0;
  v19[0] = 0;
  v19[1] = 0;
  v18 = 0;
  result = coresight_get_platform_data(a1);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_35;
  v3 = a1[93];
  a1[18] = result;
  if ( of_find_property(v3, "qcom,hw-enable-check", 0) )
  {
    sec_dump_state = qcom_scm_get_sec_dump_state(&v18);
    result = 4294967290LL;
    if ( sec_dump_state || !v18 )
      goto LABEL_35;
  }
  v5 = devm_kmalloc(a1, 72, 3520);
  if ( !v5 )
    goto LABEL_34;
  v6 = v5;
  *(_QWORD *)(v5 + 8) = a1;
  a1[19] = v5;
  optional_enabled = devm_clk_get_optional_enabled(a1, "atclk");
  *(_QWORD *)(v6 + 64) = optional_enabled;
  if ( optional_enabled >= 0xFFFFFFFFFFFFF001LL )
  {
    v17 = optional_enabled;
    dev_err(a1, "enable/get atclk fail, ret = %d\n", optional_enabled);
    if ( v17 == -110 )
      result = 4294966779LL;
    else
      result = v17;
    goto LABEL_35;
  }
  result = devm_ioremap_resource(a1, a1 + 114);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_35;
  *(_QWORD *)v6 = result;
  v8 = result;
  v9 = *(_QWORD *)(v6 + 32) | readl_relaxed(result + 4064) & 0x7F;
  *(_QWORD *)(v6 + 32) = v9;
  if ( (v9 & 2) != 0 && !*(_QWORD *)(v6 + 40) )
  {
    v10 = devm_kmalloc(*(_QWORD *)(v6 + 8), 364, 3520);
    *(_QWORD *)(v6 + 40) = v10;
    if ( !v10 )
      goto LABEL_34;
    v9 = *(_QWORD *)(v6 + 32);
  }
  if ( (v9 & 4) != 0 && !*(_QWORD *)(v6 + 48) )
  {
    v11 = devm_kmalloc(*(_QWORD *)(v6 + 8), 176, 3520);
    *(_QWORD *)(v6 + 48) = v11;
    if ( !v11 )
      goto LABEL_34;
    v9 = *(_QWORD *)(v6 + 32);
  }
  if ( (v9 & 0x40) == 0 || *(_QWORD *)(v6 + 48) )
  {
    if ( (v9 & 2) == 0 )
      goto LABEL_21;
    goto LABEL_20;
  }
  v16 = devm_kmalloc(*(_QWORD *)(v6 + 8), 176, 3520);
  *(_QWORD *)(v6 + 48) = v16;
  if ( !v16 || (*(_QWORD *)(*(_QWORD *)(v6 + 48) + 168LL) = devm_kmalloc(*(_QWORD *)(v6 + 8), 2, 3520)) == 0 )
  {
LABEL_34:
    result = 4294967284LL;
    goto LABEL_35;
  }
  if ( (*(_QWORD *)(v6 + 32) & 2) != 0 )
  {
LABEL_20:
    v12 = *(_BYTE **)(v6 + 40);
    memset(v12, 0, 0x16Cu);
    v12[362] = 1;
    *(_BYTE *)(*(_QWORD *)(v6 + 40) + 363LL) = 0;
  }
LABEL_21:
  v13 = *(_QWORD *)(v6 + 48);
  if ( v13 )
  {
    *(_QWORD *)(v13 + 160) = 0;
    *(_QWORD *)(v13 + 168) = 0;
    *(_QWORD *)(v13 + 144) = 0;
    *(_QWORD *)(v13 + 152) = 0;
    *(_QWORD *)(v13 + 128) = 0;
    *(_QWORD *)(v13 + 136) = 0;
    *(_QWORD *)(v13 + 112) = 0;
    *(_QWORD *)(v13 + 120) = 0;
    *(_QWORD *)(v13 + 96) = 0;
    *(_QWORD *)(v13 + 104) = 0;
    *(_QWORD *)(v13 + 80) = 0;
    *(_QWORD *)(v13 + 88) = 0;
    *(_QWORD *)(v13 + 64) = 0;
    *(_QWORD *)(v13 + 72) = 0;
    *(_QWORD *)(v13 + 48) = 0;
    *(_QWORD *)(v13 + 56) = 0;
    *(_QWORD *)(v13 + 32) = 0;
    *(_QWORD *)(v13 + 40) = 0;
    *(_QWORD *)(v13 + 16) = 0;
    *(_QWORD *)(v13 + 24) = 0;
    *(_QWORD *)v13 = 0;
    *(_QWORD *)(v13 + 8) = 0;
    *(_BYTE *)(v13 + 165) = 1;
  }
  v14 = *(_QWORD *)(v6 + 32);
  if ( (v14 & 2) != 0 )
  {
    of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)(v6 + 8) + 744LL), "qcom,dsb-msrs-num", v6 + 56, 1, 0);
    v14 = *(_QWORD *)(v6 + 32);
  }
  if ( (v14 & 4) != 0 )
    of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)(v6 + 8) + 744LL), "qcom,cmb-msrs-num", v6 + 60, 1, 0);
  v24 = coresight_alloc_device_name(&tpdm_devs, a1);
  if ( !v24 )
    goto LABEL_34;
  v15 = a1[18];
  v19[0] = 0x300000003LL;
  LOBYTE(v25) = 1;
  v20 = &tpdm_cs_ops;
  v21 = v15;
  *(_DWORD *)((char *)&v25 + 1) = 0;
  HIDWORD(v25) = 0;
  v26 = v8;
  v27 = 0;
  v22 = a1;
  v23 = &tpdm_attr_grps;
  result = coresight_register(v19);
  *(_QWORD *)(v6 + 16) = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    *(_DWORD *)(v6 + 24) = 0;
    _pm_runtime_idle(a1, 4);
    result = 0;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
