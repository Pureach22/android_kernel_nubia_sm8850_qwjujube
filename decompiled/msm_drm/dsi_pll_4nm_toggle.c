__int64 __fastcall dsi_pll_4nm_toggle(__int64 a1, char a2)
{
  int v3; // w4
  __int64 v4; // x20
  int v5; // w0
  double v7; // d0
  int v8; // w0
  double v9; // d0
  int v10; // w20
  double v11; // d0
  __int64 v12; // x20
  int v13; // w0
  _QWORD *v14; // x21
  double v15; // d0
  int v16; // w20
  __int64 v17; // x20
  int v18; // w0
  _QWORD *v19; // x21
  double v20; // d0
  int v21; // w20
  __int64 v22; // x20
  int v23; // w0
  _QWORD *v24; // x20
  double v25; // d0
  int v26; // w19
  double v27; // d0
  int v28; // w0
  __int64 v29; // x20
  double v30; // d0
  int v31; // w0
  __int64 v32; // x20
  double v33; // d0
  int v34; // w0
  __int64 v35; // x19
  double v36; // d0
  int v37; // w0

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: dsi pll resources are not available\n", -1);
    return 4294967274LL;
  }
  if ( (a2 & 1) != 0 )
  {
    writel_relaxed_14(1, *(_QWORD *)(a1 + 8) + 60LL);
    __dsb(0xEu);
    if ( (*(_BYTE *)(a1 + 172) & 1) == 0 )
    {
      v3 = readl_11(*(_QWORD *)a1 + 432LL);
      if ( (v3 & 1) == 0 )
      {
        v4 = 5100001;
        while ( 1 )
        {
          v4 -= 100001;
          if ( v4 < 0 )
            break;
          _const_udelay(429500);
          __yield();
          v5 = readl_11(*(_QWORD *)a1 + 432LL);
          if ( (v5 & 1) != 0 )
            goto LABEL_18;
        }
        v5 = readl_11(*(_QWORD *)a1 + 432LL);
LABEL_18:
        v3 = v5;
      }
      if ( (v3 & 1) == 0 )
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: DSI_PLL_%d: lock failed, status=0x%08x\n",
          *(_DWORD *)(a1 + 100),
          v3);
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: lock failed\n", *(_DWORD *)(a1 + 100));
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: DSI_PLL_%d: enable failed: %d\n",
          *(_DWORD *)(a1 + 100),
          -110);
        return 4294967186LL;
      }
    }
    writel_relaxed_14(4, *(_QWORD *)(a1 + 8) + 48LL);
    v28 = readl_relaxed_17(*(_QWORD *)(a1 + 8) + 20LL, v27);
    writel_relaxed_14(v28 | 0x30u, *(_QWORD *)(a1 + 8) + 20LL);
    v29 = *(_QWORD *)(a1 + 120);
    if ( v29 )
    {
      writel_relaxed_14(4, *(_QWORD *)(v29 + 8) + 48LL);
      v31 = readl_relaxed_17(*(_QWORD *)(v29 + 8) + 20LL, v30);
      writel_relaxed_14(v31 | 0x30u, *(_QWORD *)(v29 + 8) + 20LL);
    }
    v32 = *(_QWORD *)(a1 + 128);
    if ( v32 )
    {
      writel_relaxed_14(4, *(_QWORD *)(v32 + 8) + 48LL);
      v34 = readl_relaxed_17(*(_QWORD *)(v32 + 8) + 20LL, v33);
      writel_relaxed_14(v34 | 0x30u, *(_QWORD *)(v32 + 8) + 20LL);
    }
    v35 = *(_QWORD *)(a1 + 136);
    if ( v35 )
    {
      writel_relaxed_14(4, *(_QWORD *)(v35 + 8) + 48LL);
      v37 = readl_relaxed_17(*(_QWORD *)(v35 + 8) + 20LL, v36);
      writel_relaxed_14(v37 | 0x30u, *(_QWORD *)(v35 + 8) + 20LL);
    }
  }
  else
  {
    v7 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_PLL_%d: stop PLL\n", *(_DWORD *)(a1 + 100));
    v8 = readl_relaxed_17(*(_QWORD *)(a1 + 8) + 20LL, v7);
    writel_relaxed_14(v8 & 0xFFFFFFDF, *(_QWORD *)(a1 + 8) + 20LL);
    writel_relaxed_14(0, *(_QWORD *)(a1 + 8) + 60LL);
    writel_relaxed_14(0, *(_QWORD *)(a1 + 8) + 28LL);
    v10 = readl_relaxed_17(*(_QWORD *)(a1 + 8) + 36LL, v9);
    writel_relaxed_14(0, *(_QWORD *)a1 + 40LL);
    writel_relaxed_14(v10 & 0xFFFFFFDF, *(_QWORD *)(a1 + 8) + 36LL);
    _const_udelay(1250);
    v12 = *(_QWORD *)(a1 + 120);
    if ( v12 )
    {
      v13 = readl_relaxed_17(*(_QWORD *)(v12 + 8) + 20LL, v11);
      writel_relaxed_14(v13 & 0xFFFFFFDF, *(_QWORD *)(v12 + 8) + 20LL);
      v14 = *(_QWORD **)(a1 + 120);
      writel_relaxed_14(0, v14[1] + 28LL);
      v16 = readl_relaxed_17(v14[1] + 36LL, v15);
      writel_relaxed_14(0, *v14 + 40LL);
      writel_relaxed_14(v16 & 0xFFFFFFDF, v14[1] + 36LL);
      _const_udelay(1250);
    }
    v17 = *(_QWORD *)(a1 + 128);
    if ( v17 )
    {
      v18 = readl_relaxed_17(*(_QWORD *)(v17 + 8) + 20LL, v11);
      writel_relaxed_14(v18 & 0xFFFFFFDF, *(_QWORD *)(v17 + 8) + 20LL);
      v19 = *(_QWORD **)(a1 + 128);
      writel_relaxed_14(0, v19[1] + 28LL);
      v21 = readl_relaxed_17(v19[1] + 36LL, v20);
      writel_relaxed_14(0, *v19 + 40LL);
      writel_relaxed_14(v21 & 0xFFFFFFDF, v19[1] + 36LL);
      _const_udelay(1250);
    }
    v22 = *(_QWORD *)(a1 + 136);
    if ( v22 )
    {
      v23 = readl_relaxed_17(*(_QWORD *)(v22 + 8) + 20LL, v11);
      writel_relaxed_14(v23 & 0xFFFFFFDF, *(_QWORD *)(v22 + 8) + 20LL);
      v24 = *(_QWORD **)(a1 + 136);
      writel_relaxed_14(0, v24[1] + 28LL);
      v26 = readl_relaxed_17(v24[1] + 36LL, v25);
      writel_relaxed_14(0, *v24 + 40LL);
      writel_relaxed_14(v26 & 0xFFFFFFDF, v24[1] + 36LL);
      _const_udelay(1250);
    }
  }
  __dsb(0xEu);
  return 0;
}
