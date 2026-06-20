__int64 __fastcall dsi_pll_5nm_toggle(__int64 a1, char a2)
{
  int v3; // w4
  __int64 v4; // x20
  int v5; // w0
  int v7; // w0
  int v8; // w20
  __int64 v9; // x20
  int v10; // w0
  _QWORD *v11; // x21
  int v12; // w20
  __int64 v13; // x20
  int v14; // w0
  _QWORD *v15; // x21
  int v16; // w20
  __int64 v17; // x20
  int v18; // w0
  _QWORD *v19; // x20
  int v20; // w19
  __int64 v21; // x20
  __int64 v22; // x20
  __int64 v23; // x20
  int v24; // w0
  __int64 v25; // x20
  int v26; // w0
  __int64 v27; // x20
  int v28; // w0
  __int64 v29; // x19
  int v30; // w0

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: dsi pll resources are not available\n", -1);
    return 4294967274LL;
  }
  if ( (a2 & 1) != 0 )
  {
    writel_relaxed_13(1, *(_QWORD *)(a1 + 8) + 60LL);
    __dsb(0xEu);
    v3 = readl_10(*(_QWORD *)a1 + 432LL);
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
        v5 = readl_10(*(_QWORD *)a1 + 432LL);
        if ( (v5 & 1) != 0 )
          goto LABEL_17;
      }
      v5 = readl_10(*(_QWORD *)a1 + 432LL);
LABEL_17:
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
    writel_relaxed_13(1, *(_QWORD *)(a1 + 8) + 296LL);
    __dsb(0xEu);
    writel_relaxed_13(0, *(_QWORD *)(a1 + 8) + 296LL);
    __dsb(0xEu);
    v21 = *(_QWORD *)(a1 + 120);
    if ( v21 )
    {
      writel_relaxed_13(1, *(_QWORD *)(v21 + 8) + 296LL);
      __dsb(0xEu);
      writel_relaxed_13(0, *(_QWORD *)(v21 + 8) + 296LL);
      __dsb(0xEu);
    }
    v22 = *(_QWORD *)(a1 + 128);
    if ( v22 )
    {
      writel_relaxed_13(1, *(_QWORD *)(v22 + 8) + 296LL);
      __dsb(0xEu);
      writel_relaxed_13(0, *(_QWORD *)(v22 + 8) + 296LL);
      __dsb(0xEu);
    }
    v23 = *(_QWORD *)(a1 + 136);
    if ( v23 )
    {
      writel_relaxed_13(1, *(_QWORD *)(v23 + 8) + 296LL);
      __dsb(0xEu);
      writel_relaxed_13(0, *(_QWORD *)(v23 + 8) + 296LL);
      __dsb(0xEu);
    }
    writel_relaxed_13(4, *(_QWORD *)(a1 + 8) + 48LL);
    v24 = readl_relaxed_16(*(_QWORD *)(a1 + 8) + 20LL);
    writel_relaxed_13(v24 | 0x30u, *(_QWORD *)(a1 + 8) + 20LL);
    v25 = *(_QWORD *)(a1 + 120);
    if ( v25 )
    {
      writel_relaxed_13(4, *(_QWORD *)(v25 + 8) + 48LL);
      v26 = readl_relaxed_16(*(_QWORD *)(v25 + 8) + 20LL);
      writel_relaxed_13(v26 | 0x30u, *(_QWORD *)(v25 + 8) + 20LL);
    }
    v27 = *(_QWORD *)(a1 + 128);
    if ( v27 )
    {
      writel_relaxed_13(4, *(_QWORD *)(v27 + 8) + 48LL);
      v28 = readl_relaxed_16(*(_QWORD *)(v27 + 8) + 20LL);
      writel_relaxed_13(v28 | 0x30u, *(_QWORD *)(v27 + 8) + 20LL);
    }
    v29 = *(_QWORD *)(a1 + 136);
    if ( v29 )
    {
      writel_relaxed_13(4, *(_QWORD *)(v29 + 8) + 48LL);
      v30 = readl_relaxed_16(*(_QWORD *)(v29 + 8) + 20LL);
      writel_relaxed_13(v30 | 0x30u, *(_QWORD *)(v29 + 8) + 20LL);
    }
  }
  else
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_PLL_%d: stop PLL\n", *(_DWORD *)(a1 + 100));
    v7 = readl_relaxed_16(*(_QWORD *)(a1 + 8) + 20LL);
    writel_relaxed_13(v7 & 0xFFFFFFDF, *(_QWORD *)(a1 + 8) + 20LL);
    writel_relaxed_13(0, *(_QWORD *)(a1 + 8) + 60LL);
    writel_relaxed_13(0, *(_QWORD *)(a1 + 8) + 28LL);
    v8 = readl_relaxed_16(*(_QWORD *)(a1 + 8) + 36LL);
    writel_relaxed_13(0, *(_QWORD *)a1 + 40LL);
    writel_relaxed_13(v8 & 0xFFFFFFDF, *(_QWORD *)(a1 + 8) + 36LL);
    _const_udelay(1250);
    v9 = *(_QWORD *)(a1 + 120);
    if ( v9 )
    {
      v10 = readl_relaxed_16(*(_QWORD *)(v9 + 8) + 20LL);
      writel_relaxed_13(v10 & 0xFFFFFFDF, *(_QWORD *)(v9 + 8) + 20LL);
      v11 = *(_QWORD **)(a1 + 120);
      writel_relaxed_13(0, v11[1] + 28LL);
      v12 = readl_relaxed_16(v11[1] + 36LL);
      writel_relaxed_13(0, *v11 + 40LL);
      writel_relaxed_13(v12 & 0xFFFFFFDF, v11[1] + 36LL);
      _const_udelay(1250);
    }
    v13 = *(_QWORD *)(a1 + 128);
    if ( v13 )
    {
      v14 = readl_relaxed_16(*(_QWORD *)(v13 + 8) + 20LL);
      writel_relaxed_13(v14 & 0xFFFFFFDF, *(_QWORD *)(v13 + 8) + 20LL);
      v15 = *(_QWORD **)(a1 + 128);
      writel_relaxed_13(0, v15[1] + 28LL);
      v16 = readl_relaxed_16(v15[1] + 36LL);
      writel_relaxed_13(0, *v15 + 40LL);
      writel_relaxed_13(v16 & 0xFFFFFFDF, v15[1] + 36LL);
      _const_udelay(1250);
    }
    v17 = *(_QWORD *)(a1 + 136);
    if ( v17 )
    {
      v18 = readl_relaxed_16(*(_QWORD *)(v17 + 8) + 20LL);
      writel_relaxed_13(v18 & 0xFFFFFFDF, *(_QWORD *)(v17 + 8) + 20LL);
      v19 = *(_QWORD **)(a1 + 136);
      writel_relaxed_13(0, v19[1] + 28LL);
      v20 = readl_relaxed_16(v19[1] + 36LL);
      writel_relaxed_13(0, *v19 + 40LL);
      writel_relaxed_13(v20 & 0xFFFFFFDF, v19[1] + 36LL);
      _const_udelay(1250);
    }
  }
  __dsb(0xEu);
  return 0;
}
