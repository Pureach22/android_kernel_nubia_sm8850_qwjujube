__int64 __fastcall dsi_pll_clock_register_4nm(__int64 a1, __int64 a2)
{
  unsigned __int16 v2; // w15
  unsigned __int16 *v3; // x20
  __int64 v4; // x19
  __int64 v5; // x3
  const char *v6; // x2
  __int64 result; // x0
  char *v8; // x8
  int v9; // w9
  int v10; // w9
  int v11; // w9
  __int64 v14; // x0
  __int64 v15; // x20
  __int64 v16; // x0
  _QWORD *v17; // x21
  __int64 v18; // x1
  unsigned __int64 v19; // x0
  unsigned __int64 v20; // x0
  unsigned __int64 v21; // x0
  unsigned __int64 v22; // x0

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
    v6 = "*ERROR* [msm-dsi-error]: DSI_PLL_%d: Invalid params\n";
LABEL_12:
    drm_dev_printk(0, &unk_248D72, v6, v5);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)a2 || !*(_QWORD *)(a2 + 8) )
    goto LABEL_9;
  v4 = *(unsigned int *)(a2 + 100);
  if ( (int)v4 >= 4 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: not supported\n", (unsigned int)v4);
    return 4294967274LL;
  }
  if ( (unsigned int)v4 >= 4 )
  {
    __break(0x5512u);
    atomic_store(v2, v3);
    return dsi_pll_4nm_trigger_resets_pre_enable();
  }
  v8 = (char *)&plls_0 + 120 * (unsigned int)v4;
  pll_rsc_db_0[v4] = a2;
  *(_QWORD *)v8 = a2;
  *(_QWORD *)(a2 + 144) = v8;
  *(_DWORD *)(a2 + 84) = 1;
  *(_QWORD *)(a2 + 40) = 19200000;
  *(_QWORD *)(a2 + 48) = 600000000;
  *((_DWORD *)v8 + 4) = 1;
  *((_DWORD *)v8 + 2) = 19200000;
  *((_QWORD *)v8 + 3) = 0x1200000008LL;
  *((_QWORD *)v8 + 4) = 0x7B0C00000040LL;
  v8[12] = 0;
  *((_QWORD *)v8 + 5) = 0x2000012C0LL;
  *((_QWORD *)v8 + 6) = 0x10000000020LL;
  *((_WORD *)v8 + 10) = 0;
  v9 = *(unsigned __int8 *)(a2 + 104);
  v8[22] = v9;
  v8[23] = *(_BYTE *)(a2 + 105);
  if ( v9 == 1 )
  {
    v10 = *(_DWORD *)(a2 + 108);
    if ( v10 )
      *((_DWORD *)v8 + 9) = v10;
    v11 = *(_DWORD *)(a2 + 112);
    if ( v11 )
      *((_DWORD *)v8 + 10) = v11;
  }
  v14 = devm_kmalloc(a1 + 16, 16, 3520);
  if ( !v14 )
    return 4294967284LL;
  v15 = v14;
  v16 = devm_kmalloc(a1 + 16, 32, 3520);
  *(_QWORD *)v15 = v16;
  if ( !v16 )
    return 4294967284LL;
  v17 = (_QWORD *)v16;
  v18 = (__int64)*(&dsi_pllcc_4nm + (unsigned int)(2 * v4));
  *(_DWORD *)(v15 + 8) = 4;
  *(_QWORD *)(v18 + 24) = a2;
  *((_QWORD *)*(&dsi_pllcc_4nm + ((2 * (v4 & 0x3FFFFFFF)) | 1)) + 3) = a2;
  v19 = devm_clk_register(a1 + 16);
  if ( v19 >= 0xFFFFFFFFFFFFF001LL )
  {
    v5 = *(unsigned int *)(a2 + 100);
    v6 = "*ERROR* [msm-dsi-error]: DSI_PLL_%d: byte clk registration failed\n";
    goto LABEL_12;
  }
  *v17 = v19;
  v20 = devm_clk_register(a1 + 16);
  if ( v20 >= 0xFFFFFFFFFFFFF001LL )
  {
    v5 = *(unsigned int *)(a2 + 100);
    v6 = "*ERROR* [msm-dsi-error]: DSI_PLL_%d: dsi clk registration failed\n";
    goto LABEL_12;
  }
  v17[1] = v20;
  if ( !(_DWORD)v4 )
  {
    qword_D470 = a2;
    qword_D490 = a2;
    v21 = devm_clk_register(a1 + 16);
    if ( v21 >= 0xFFFFFFFFFFFFF001LL )
    {
      v5 = *(unsigned int *)(a2 + 100);
      v6 = "*ERROR* [msm-dsi-error]: DSI_PLL_%d: mbyte clk registration failed\n";
      goto LABEL_12;
    }
    v17[2] = v21;
    v22 = devm_clk_register(a1 + 16);
    if ( v22 >= 0xFFFFFFFFFFFFF001LL )
    {
      v5 = *(unsigned int *)(a2 + 100);
      v6 = "*ERROR* [msm-dsi-error]: DSI_PLL_%d: mdsi clk registration failed\n";
      goto LABEL_12;
    }
    v17[3] = v22;
  }
  result = of_clk_add_provider(*(_QWORD *)(a1 + 760), &of_clk_src_onecell_get, v15);
  if ( !(_DWORD)result )
  {
    drm_dev_printk(
      0,
      &unk_2597DF,
      "[msm-dsi-info]: DSI_PLL_%d: Registered clocks successfully\n",
      *(_DWORD *)(a2 + 100));
    return 0;
  }
  return result;
}
