__int64 __fastcall dp_power_clk_init(_QWORD *a1, char a2)
{
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 clk; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x0
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x0
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x20
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 ipc_log_context; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0

  if ( (a2 & 1) == 0 )
  {
    if ( a1[5] )
      ((void (*)(void))clk_put)();
    if ( a1[4] )
      ((void (*)(void))clk_put)();
    if ( a1[3] )
      ((void (*)(void))clk_put)();
    if ( a1[8] )
      ((void (*)(void))clk_put)();
    if ( a1[7] )
      ((void (*)(void))clk_put)();
    dp_power_clk_put(a1);
    goto LABEL_41;
  }
  v3 = *a1;
  v4 = a1[2];
  if ( *(_DWORD *)(*a1 + 48LL) )
  {
    clk = msm_dss_get_clk(v4 + 16, *(_QWORD *)(v3 + 56));
    if ( (_DWORD)clk )
    {
      LODWORD(v20) = clk;
      ipc_log_context = get_ipc_log_context(clk);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]failed to get %s clk. err=%d\n",
        *(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800),
        "DP_CORE_PM",
        (unsigned int)v20);
      goto LABEL_55;
    }
    v3 = *a1;
  }
  if ( *(_DWORD *)(v3 + 96) )
  {
    v6 = msm_dss_get_clk(v4 + 16, *(_QWORD *)(v3 + 104));
    if ( (_DWORD)v6 )
    {
      LODWORD(v20) = v6;
      v28 = get_ipc_log_context(v6);
      ipc_log_string(
        v28,
        "[e][%-4d]failed to get %s clk. err=%d\n",
        *(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800),
        "DP_CTRL_PM",
        (unsigned int)v20);
      goto LABEL_55;
    }
    v3 = *a1;
  }
  if ( *(_DWORD *)(v3 + 144) )
  {
    v7 = msm_dss_get_clk(v4 + 16, *(_QWORD *)(v3 + 152));
    if ( (_DWORD)v7 )
    {
      LODWORD(v20) = v7;
      v29 = get_ipc_log_context(v7);
      ipc_log_string(
        v29,
        "[e][%-4d]failed to get %s clk. err=%d\n",
        *(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800),
        "DP_PHY_PM",
        (unsigned int)v20);
      goto LABEL_55;
    }
    v3 = *a1;
  }
  if ( *(_DWORD *)(v3 + 192) )
  {
    v8 = msm_dss_get_clk(v4 + 16, *(_QWORD *)(v3 + 200));
    if ( (_DWORD)v8 )
    {
      LODWORD(v20) = v8;
      v30 = get_ipc_log_context(v8);
      ipc_log_string(
        v30,
        "[e][%-4d]failed to get %s clk. err=%d\n",
        *(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800),
        "DP_STREAM0_PM",
        (unsigned int)v20);
      goto LABEL_55;
    }
    v3 = *a1;
  }
  if ( *(_DWORD *)(v3 + 240) )
  {
    v9 = msm_dss_get_clk(v4 + 16, *(_QWORD *)(v3 + 248));
    if ( (_DWORD)v9 )
    {
      LODWORD(v20) = v9;
      v31 = get_ipc_log_context(v9);
      ipc_log_string(
        v31,
        "[e][%-4d]failed to get %s clk. err=%d\n",
        *(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800),
        "DP_STREAM1_PM",
        (unsigned int)v20);
      goto LABEL_55;
    }
    v3 = *a1;
  }
  if ( *(_DWORD *)(v3 + 288) )
  {
    v10 = msm_dss_get_clk(v4 + 16, *(_QWORD *)(v3 + 296));
    if ( !(_DWORD)v10 )
    {
      v3 = *a1;
      goto LABEL_20;
    }
    LODWORD(v20) = v10;
    v32 = get_ipc_log_context(v10);
    ipc_log_string(
      v32,
      "[e][%-4d]failed to get %s clk. err=%d\n",
      *(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800),
      "DP_LINK_PM",
      (unsigned int)v20);
LABEL_55:
    printk(&unk_214AD5, "dp_power_clk_init");
    return (unsigned int)v20;
  }
LABEL_20:
  if ( *(_DWORD *)(v3 + 336) )
  {
    v11 = msm_dss_get_clk(v4 + 16, *(_QWORD *)(v3 + 344));
    if ( (_DWORD)v11 )
    {
      LODWORD(v20) = v11;
      v33 = get_ipc_log_context(v11);
      ipc_log_string(
        v33,
        "[e][%-4d]failed to get %s clk. err=%d\n",
        *(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800),
        "DP_PLL_PM",
        (unsigned int)v20);
      goto LABEL_55;
    }
  }
  v12 = clk_get(v4 + 16, "pixel_clk_rcg");
  a1[3] = v12;
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    v22 = get_ipc_log_context(v12);
    ipc_log_string(
      v22,
      "[e][%-4d]Unable to get DP pixel clk RCG: %ld\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      a1[3]);
    printk(&unk_27C297, "dp_power_clk_init");
    v20 = a1[3];
    a1[3] = 0;
LABEL_60:
    dp_power_clk_put(a1);
    return (unsigned int)v20;
  }
  v13 = clk_get(v4 + 16, "pixel_parent");
  a1[4] = v13;
  if ( v13 >= 0xFFFFFFFFFFFFF001LL )
  {
    v23 = get_ipc_log_context(v13);
    ipc_log_string(
      v23,
      "[e][%-4d]Unable to get DP pixel RCG parent: %ld\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      a1[4]);
    printk(&unk_23E25E, "dp_power_clk_init");
    v20 = a1[4];
    a1[4] = 0;
LABEL_59:
    clk_put(a1[3]);
    goto LABEL_60;
  }
  v14 = clk_get(v4 + 16, "rpmh_cxo_clk");
  a1[6] = v14;
  if ( v14 >= 0xFFFFFFFFFFFFF001LL )
  {
    v24 = get_ipc_log_context(v14);
    ipc_log_string(v24, "[e][%-4d]Unable to get XO clk: %ld\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), a1[6]);
    printk(&unk_244D52, "dp_power_clk_init");
    v20 = a1[6];
    a1[6] = 0;
LABEL_58:
    clk_put(a1[4]);
    goto LABEL_59;
  }
  if ( *(_BYTE *)(*a1 + 724LL) == 1 )
  {
    v15 = clk_get(v4 + 16, "pixel1_clk_rcg");
    a1[5] = v15;
    if ( v15 >= 0xFFFFFFFFFFFFF001LL )
    {
      v34 = get_ipc_log_context(v15);
      ipc_log_string(
        v34,
        "[e][%-4d]Unable to get DP pixel1 clk RCG: %ld\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        a1[5]);
      printk(&unk_23739E, "dp_power_clk_init");
      v20 = a1[5];
      a1[5] = 0;
LABEL_57:
      clk_put(a1[6]);
      goto LABEL_58;
    }
  }
  v16 = clk_get(v4 + 16, "link_clk_src");
  a1[7] = v16;
  if ( v16 >= 0xFFFFFFFFFFFFF001LL )
  {
    v26 = get_ipc_log_context(v16);
    ipc_log_string(
      v26,
      "[e][%-4d]Unable to get DP link clk RCG: %ld\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      a1[7]);
    printk(&unk_279028, "dp_power_clk_init");
    v27 = a1[5];
    v20 = a1[7];
    a1[7] = 0;
    if ( v27 )
      ((void (*)(void))clk_put)();
    goto LABEL_57;
  }
  *(_DWORD *)(a1[1] + 396LL) = 1000;
  v17 = clk_get(v4 + 16, "link_parent");
  a1[8] = v17;
  if ( v17 < 0xFFFFFFFFFFFFF001LL )
  {
LABEL_41:
    LODWORD(v20) = 0;
    return (unsigned int)v20;
  }
  v18 = get_ipc_log_context(v17);
  ipc_log_string(v18, "[w][%-4d]Unable to get DP link parent: %ld\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), a1[8]);
  printk(&unk_2523FC, "dp_power_clk_init");
  v19 = a1[1];
  LODWORD(v20) = 0;
  a1[8] = 0;
  *(_DWORD *)(v19 + 396) = 1;
  return (unsigned int)v20;
}
