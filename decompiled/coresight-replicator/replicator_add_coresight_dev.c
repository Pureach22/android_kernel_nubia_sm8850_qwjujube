__int64 __fastcall replicator_add_coresight_dev(_QWORD *a1, unsigned __int64 a2)
{
  unsigned __int64 v4; // x0
  unsigned __int64 *v5; // x23
  unsigned __int64 v6; // x21
  __int64 property; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 *v9; // x22
  int v10; // w0
  int v11; // w0
  int v12; // w19
  unsigned __int64 v13; // x21
  int v14; // w22
  int v15; // w0
  unsigned __int64 v16; // x0
  __int64 v17; // x0
  unsigned __int64 platform_data; // x0
  __int64 v19; // x8
  unsigned __int64 v20; // x19
  unsigned __int64 v21; // x19
  unsigned __int64 v22; // x8
  __int64 v24; // [xsp+8h] [xbp-58h] BYREF
  __int64 v25; // [xsp+10h] [xbp-50h]
  void *v26; // [xsp+18h] [xbp-48h]
  __int64 v27; // [xsp+20h] [xbp-40h]
  _QWORD *v28; // [xsp+28h] [xbp-38h]
  char ***v29; // [xsp+30h] [xbp-30h]
  __int64 v30; // [xsp+38h] [xbp-28h]
  __int64 v31; // [xsp+40h] [xbp-20h]
  unsigned __int64 v32; // [xsp+48h] [xbp-18h]
  __int64 v33; // [xsp+50h] [xbp-10h]
  __int64 v34; // [xsp+58h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = nullptr;
  v29 = nullptr;
  v26 = nullptr;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v4 = ((__int64 (*)(void))_dev_fwnode)();
  if ( v4
    && v4 <= 0xFFFFFFFFFFFFF000LL
    && *(_UNKNOWN **)(v4 + 8) == &of_fwnode_ops
    && (unsigned int)of_device_is_compatible(a1[93], "arm,coresight-replicator")
    && (replicator_add_coresight_dev___print_once & 1) == 0 )
  {
    replicator_add_coresight_dev___print_once = 1;
    dev_warn(a1, "Uses OBSOLETE CoreSight replicator binding\n");
  }
  v30 = coresight_alloc_device_name(&replicator_devs, a1);
  if ( !v30 || (v5 = (unsigned __int64 *)a1[19]) == nullptr )
  {
    LODWORD(a2) = -12;
    goto LABEL_47;
  }
  v6 = devm_clk_get(a1, "atclk");
  v5[1] = v6;
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    property = of_find_property(a1[93], "qcom,atclk-dependence", 0);
    v6 = v5[1];
    if ( property )
    {
      dev_err(a1, "get atclk fail %ld\n", v5[1]);
      LODWORD(a2) = *((_DWORD *)v5 + 2);
      goto LABEL_47;
    }
  }
  if ( v6 <= 0xFFFFFFFFFFFFF000LL )
  {
    v10 = clk_prepare(v6);
    if ( !v10 )
    {
      v11 = clk_enable(v6);
      if ( !v11 )
        goto LABEL_12;
      v12 = v11;
      clk_unprepare(v6);
      v10 = v12;
    }
    if ( v10 == -110 )
      LODWORD(a2) = -517;
    else
      LODWORD(a2) = v10;
    goto LABEL_47;
  }
LABEL_12:
  v8 = clk_get(a1, "apb_pclk");
  if ( v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    v5[2] = 0;
    v9 = v5 + 2;
    goto LABEL_27;
  }
  v13 = v8;
  v14 = clk_prepare(v8);
  if ( !v14 )
  {
    v15 = clk_enable(v13);
    if ( !v15 )
      goto LABEL_25;
    v14 = v15;
    clk_unprepare(v13);
  }
  clk_put(v13);
  v13 = v14;
LABEL_25:
  v5[2] = v13;
  v9 = v5 + 2;
  if ( v13 > 0xFFFFFFFFFFFFF000LL )
  {
    LODWORD(a2) = -19;
    goto LABEL_47;
  }
LABEL_27:
  if ( a2 )
  {
    v16 = devm_ioremap_resource(a1, a2);
    LODWORD(a2) = v16;
    if ( v16 > 0xFFFFFFFFFFFFF000LL )
    {
LABEL_34:
      if ( (_DWORD)a2 )
      {
        v20 = v5[1];
        if ( v20 && v20 <= 0xFFFFFFFFFFFFF000LL )
        {
          clk_disable(v5[1]);
          clk_unprepare(v20);
        }
        v21 = *v9;
        if ( *v9 && v21 <= 0xFFFFFFFFFFFFF000LL )
        {
          clk_disable(*v9);
          clk_unprepare(v21);
        }
      }
      goto LABEL_47;
    }
    *v5 = v16;
    v29 = &replicator_groups;
    LOBYTE(v31) = 1;
    *(_DWORD *)((char *)&v31 + 1) = 0;
    HIDWORD(v31) = 0;
    v32 = v16;
    v33 = 0;
  }
  v17 = _dev_fwnode(a1);
  if ( (fwnode_property_present(v17, "qcom,replicator-loses-context") & 1) != 0 )
    *((_BYTE *)v5 + 36) = 1;
  platform_data = coresight_get_platform_data(a1);
  LODWORD(a2) = platform_data;
  if ( platform_data > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_34;
  a1[18] = platform_data;
  *((_DWORD *)v5 + 8) = 0;
  LODWORD(v24) = 1;
  LODWORD(v25) = 1;
  v19 = a1[18];
  v28 = a1;
  v26 = &replicator_cs_ops;
  v27 = v19;
  a2 = coresight_register(&v24);
  v5[3] = a2;
  if ( a2 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_34;
  if ( *v5 )
  {
    writel_relaxed(3316436565LL, *v5 + 4016);
    __dsb(0xFu);
    if ( !(unsigned int)coresight_claim_device_unlocked(a2) )
    {
      writel_relaxed(255, *v5);
      writel_relaxed(255, *v5 + 4);
      coresight_disclaim_device_unlocked(a2);
    }
    v22 = *v5;
    __dsb(0xFu);
    writel_relaxed(0, v22 + 4016);
  }
  _pm_runtime_idle(a1, 4);
  LODWORD(a2) = 0;
  *((_BYTE *)v5 + 88) = 1;
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)a2;
}
