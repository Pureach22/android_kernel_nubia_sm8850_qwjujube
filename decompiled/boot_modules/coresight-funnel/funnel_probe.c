__int64 __fastcall funnel_probe(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 platform_data; // x21
  unsigned __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x20
  unsigned __int64 v14; // x23
  __int64 property; // x0
  unsigned __int64 v16; // x0
  unsigned __int64 *v17; // x25
  int v18; // w0
  int v19; // w0
  int v20; // w19
  unsigned __int64 v21; // x23
  int v22; // w24
  int v23; // w0
  unsigned int v24; // w22
  __int64 *v25; // x26
  unsigned __int64 v26; // x0
  _UNKNOWN **v27; // x8
  unsigned __int64 v28; // x0
  unsigned __int64 v29; // x0
  unsigned __int64 v30; // x19
  unsigned __int64 v31; // x19
  __int64 v33; // [xsp+0h] [xbp-C0h] BYREF
  int v34; // [xsp+8h] [xbp-B8h]
  void *v35; // [xsp+10h] [xbp-B0h]
  unsigned __int64 v36; // [xsp+18h] [xbp-A8h]
  _QWORD *v37; // [xsp+20h] [xbp-A0h]
  _UNKNOWN **v38; // [xsp+28h] [xbp-98h] BYREF
  __int64 v39; // [xsp+30h] [xbp-90h]
  __int64 v40; // [xsp+38h] [xbp-88h]
  unsigned __int64 v41; // [xsp+40h] [xbp-80h]
  __int64 v42; // [xsp+48h] [xbp-78h] BYREF
  _QWORD v43[12]; // [xsp+50h] [xbp-70h] BYREF
  const char *v44[2]; // [xsp+B0h] [xbp-10h] BYREF

  v44[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  platform_data = a1[93];
  memset(v43, 0, sizeof(v43));
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = nullptr;
  v38 = nullptr;
  v35 = nullptr;
  v36 = 0;
  v11 = _dev_fwnode(a1, a2, a3, a4, a5, a6, a7, a8, 0, 0);
  if ( v11
    && v11 <= 0xFFFFFFFFFFFFF000LL
    && *(_UNKNOWN **)(v11 + 8) == &of_fwnode_ops
    && (unsigned int)of_device_is_compatible(a1[93], "arm,coresight-funnel")
    && (funnel_probe___print_once & 1) == 0 )
  {
    funnel_probe___print_once = 1;
    dev_warn(a1, "Uses OBSOLETE CoreSight funnel binding\n");
  }
  v39 = coresight_alloc_device_name(&funnel_devs, a1);
  if ( !v39 || (v12 = devm_kmalloc(a1, 112, 3520)) == 0 )
  {
    LODWORD(platform_data) = -12;
    goto LABEL_49;
  }
  v13 = v12;
  v14 = devm_clk_get(a1, "atclk");
  *(_QWORD *)(v13 + 8) = v14;
  if ( v14 >= 0xFFFFFFFFFFFFF001LL )
  {
    property = of_find_property(a1[93], "qcom,atclk-dependence", 0);
    v14 = *(_QWORD *)(v13 + 8);
    if ( property )
    {
      dev_err(a1, "get atclk fail %ld\n", *(_QWORD *)(v13 + 8));
      LODWORD(platform_data) = v14;
      goto LABEL_49;
    }
  }
  if ( v14 <= 0xFFFFFFFFFFFFF000LL )
  {
    v18 = clk_prepare(v14);
    if ( !v18 )
    {
      v19 = clk_enable(v14);
      if ( !v19 )
        goto LABEL_12;
      v20 = v19;
      clk_unprepare(v14);
      v18 = v20;
    }
    if ( v18 == -110 )
      LODWORD(platform_data) = -517;
    else
      LODWORD(platform_data) = v18;
    goto LABEL_49;
  }
LABEL_12:
  v16 = clk_get(a1, "apb_pclk");
  if ( v16 >= 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(v13 + 16) = 0;
    v17 = (unsigned __int64 *)(v13 + 16);
    goto LABEL_27;
  }
  v21 = v16;
  v22 = clk_prepare(v16);
  if ( !v22 )
  {
    v23 = clk_enable(v21);
    if ( !v23 )
      goto LABEL_25;
    v22 = v23;
    clk_unprepare(v21);
  }
  clk_put(v21);
  v21 = v22;
LABEL_25:
  *(_QWORD *)(v13 + 16) = v21;
  v17 = (unsigned __int64 *)(v13 + 16);
  if ( v21 > 0xFFFFFFFFFFFFF000LL )
  {
    LODWORD(platform_data) = -19;
    goto LABEL_49;
  }
LABEL_27:
  if ( !of_find_property(platform_data, "qcom,duplicate-funnel", 0) )
  {
    if ( !a2 )
    {
LABEL_40:
      a1[19] = v13;
      platform_data = coresight_get_platform_data(a1);
      if ( platform_data <= 0xFFFFFFFFFFFFF000LL )
      {
        a1[18] = platform_data;
        LODWORD(v33) = 1;
        *(_DWORD *)(v13 + 40) = 0;
        v34 = 0;
        v35 = &funnel_cs_ops;
        v36 = platform_data;
        v37 = a1;
        v29 = coresight_register(&v33);
        LODWORD(platform_data) = v29;
        *(_QWORD *)(v13 + 24) = v29;
        if ( v29 <= 0xFFFFFFFFFFFFF000LL )
        {
          funnel_init_power_state(a1, v13);
          LODWORD(platform_data) = 0;
          goto LABEL_49;
        }
      }
LABEL_42:
      if ( !(_DWORD)platform_data )
        goto LABEL_49;
      goto LABEL_43;
    }
    v26 = devm_ioremap_resource(a1, a2);
    LODWORD(platform_data) = v26;
    if ( v26 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_42;
    v27 = nullptr;
    v38 = &coresight_funnel_groups;
    v25 = &v42;
    *(_QWORD *)v13 = v26;
    LOBYTE(v40) = 1;
    *(_DWORD *)((char *)&v40 + 1) = 0;
    HIDWORD(v40) = 0;
    v41 = v26;
LABEL_39:
    *v25 = (__int64)v27;
    goto LABEL_40;
  }
  v44[0] = nullptr;
  if ( (of_property_read_string_helper(platform_data, "reg-names", v44, 1, 0) & 0x80000000) != 0 )
  {
LABEL_32:
    LODWORD(platform_data) = -22;
  }
  else
  {
    v24 = 0;
    v25 = (__int64 *)&v38;
    while ( strcmp("funnel-base-real", v44[0]) )
    {
      if ( (of_property_read_string_helper(platform_data, "reg-names", v44, 1, ++v24) & 0x80000000) != 0 )
        goto LABEL_32;
    }
    LODWORD(platform_data) = of_address_to_resource(platform_data, v24, v43);
    if ( !(_DWORD)platform_data )
    {
      v28 = devm_ioremap(a1);
      LODWORD(platform_data) = v28;
      if ( v28 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_42;
      *(_QWORD *)v13 = v28;
      v27 = &coresight_funnel_groups;
      goto LABEL_39;
    }
  }
LABEL_43:
  v30 = *(_QWORD *)(v13 + 8);
  if ( v30 && v30 <= 0xFFFFFFFFFFFFF000LL )
  {
    clk_disable(*(_QWORD *)(v13 + 8));
    clk_unprepare(v30);
  }
  v31 = *v17;
  if ( *v17 && v31 <= 0xFFFFFFFFFFFFF000LL )
  {
    clk_disable(*v17);
    clk_unprepare(v31);
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)platform_data;
}
