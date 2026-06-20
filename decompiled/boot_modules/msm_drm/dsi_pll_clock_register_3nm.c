__int64 __fastcall dsi_pll_clock_register_3nm(__int64 a1, __int64 a2)
{
  unsigned __int16 v2; // w15
  unsigned __int16 *v3; // x20
  __int64 v4; // x19
  __int64 v5; // x3
  char *v7; // x8
  int v8; // w9
  int v9; // w9
  int v10; // w9
  __int64 v13; // x0
  __int64 v14; // x20
  __int64 v15; // x0
  _QWORD *v16; // x21
  __int64 v17; // x23
  unsigned __int64 v18; // x0
  unsigned __int64 v19; // x0
  int v20; // w0
  unsigned int v21; // w19
  unsigned int v22; // w9
  unsigned int v29; // w11
  unsigned __int64 v30; // x0
  unsigned __int64 v31; // x0

  if ( !a1 || !a2 || !*(_QWORD *)(a1 + 760) )
  {
    if ( !a2 )
    {
      v5 = 0xFFFFFFFFLL;
      goto LABEL_11;
    }
LABEL_9:
    v5 = *(unsigned int *)(a2 + 100);
LABEL_11:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: Invalid params\n", v5);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)a2 || !*(_QWORD *)(a2 + 8) )
    goto LABEL_9;
  v4 = *(unsigned int *)(a2 + 100);
  if ( (int)v4 < 4 )
  {
    if ( (unsigned int)v4 >= 4 )
    {
      __break(0x5512u);
      atomic_store(v2, v3);
      return dsi_pll_3nm_trigger_resets_pre_enable();
    }
    v7 = (char *)&plls_1 + 120 * (unsigned int)v4;
    pll_rsc_db_1[v4] = a2;
    *(_QWORD *)v7 = a2;
    *(_QWORD *)(a2 + 144) = v7;
    *(_DWORD *)(a2 + 84) = 1;
    *(_QWORD *)(a2 + 40) = 19200000;
    *(_QWORD *)(a2 + 48) = 600000000;
    *((_DWORD *)v7 + 4) = 1;
    *((_DWORD *)v7 + 2) = 19200000;
    *((_QWORD *)v7 + 3) = 0x1200000008LL;
    *((_QWORD *)v7 + 4) = 0x7B0C00000040LL;
    v7[12] = 0;
    *((_QWORD *)v7 + 5) = 0x2000012C0LL;
    *((_QWORD *)v7 + 6) = 0x10000000020LL;
    *((_WORD *)v7 + 10) = 0;
    v8 = *(unsigned __int8 *)(a2 + 104);
    v7[22] = v8;
    v7[23] = *(_BYTE *)(a2 + 105);
    if ( v8 == 1 )
    {
      v9 = *(_DWORD *)(a2 + 108);
      if ( v9 )
        *((_DWORD *)v7 + 9) = v9;
      v10 = *(_DWORD *)(a2 + 112);
      if ( v10 )
        *((_DWORD *)v7 + 10) = v10;
    }
    v13 = devm_kmalloc(a1 + 16, 16, 3520);
    if ( !v13 )
      return 4294967284LL;
    v14 = v13;
    v15 = devm_kmalloc(a1 + 16, 32, 3520);
    *(_QWORD *)v14 = v15;
    if ( !v15 )
      return 4294967284LL;
    v16 = (_QWORD *)v15;
    v17 = (__int64)*(&dsi_pllcc_3nm + (unsigned int)(2 * v4));
    *(_DWORD *)(v14 + 8) = 4;
    *(_QWORD *)(v17 + 24) = a2;
    *((_QWORD *)*(&dsi_pllcc_3nm + ((2 * (v4 & 0x3FFFFFFF)) | 1)) + 3) = a2;
    if ( (_pm_runtime_resume(a1 + 16, 4) & 0x80000000) != 0 )
    {
      v22 = *(_DWORD *)(a1 + 496);
      do
      {
        if ( !v22 )
          break;
        _X13 = (unsigned int *)(a1 + 496);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v29 = __ldxr(_X13);
          if ( v29 != v22 )
            break;
          if ( !__stlxr(v22 - 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v29 == v22;
        v22 = v29;
      }
      while ( !_ZF );
    }
    v18 = devm_clk_register(a1 + 16);
    if ( v18 < 0xFFFFFFFFFFFFF001LL )
    {
      *v16 = v18;
      v19 = devm_clk_register(a1 + 16);
      if ( v19 < 0xFFFFFFFFFFFFF001LL )
      {
        v16[1] = v19;
        if ( !(_DWORD)v4 )
        {
          qword_DD80 = a2;
          qword_DDA0 = a2;
          v30 = devm_clk_register(a1 + 16);
          if ( v30 >= 0xFFFFFFFFFFFFF001LL )
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: DSI_PLL_%d: mbyte clk registration failed\n",
              *(unsigned int *)(a2 + 100));
            goto LABEL_28;
          }
          v16[2] = v30;
          v31 = devm_clk_register(a1 + 16);
          if ( v31 >= 0xFFFFFFFFFFFFF001LL )
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: DSI_PLL_%d: mdsi clk registration failed\n",
              *(unsigned int *)(a2 + 100));
            goto LABEL_28;
          }
          v16[3] = v31;
        }
        v20 = of_clk_add_provider(*(_QWORD *)(a1 + 760), &of_clk_src_onecell_get, v14);
        if ( !v20 )
        {
          drm_dev_printk(
            0,
            &unk_2597DF,
            "[msm-dsi-info]: DSI_PLL_%d: Registered clocks successfully\n",
            *(_DWORD *)(a2 + 100));
          v20 = 0;
        }
        goto LABEL_29;
      }
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: DSI_PLL_%d: dsi clk registration failed\n",
        *(unsigned int *)(a2 + 100));
    }
    else
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: DSI_PLL_%d: byte clk registration failed\n",
        *(unsigned int *)(a2 + 100));
    }
LABEL_28:
    v20 = -22;
LABEL_29:
    v21 = v20;
    _pm_runtime_idle(a1 + 16, 4);
    return v21;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: not supported\n", (unsigned int)v4);
  return 4294967274LL;
}
