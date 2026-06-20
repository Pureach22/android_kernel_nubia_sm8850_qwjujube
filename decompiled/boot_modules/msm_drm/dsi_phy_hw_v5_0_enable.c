void __fastcall dsi_phy_hw_v5_0_enable(unsigned int *a1, __int64 a2)
{
  char v4; // w0
  char v5; // w0
  __int64 v6; // x21
  int v7; // w3
  int v8; // w21
  __int64 v9; // x8
  unsigned int v10; // w0
  int v11; // w25
  int v12; // w24
  unsigned int v13; // w23
  unsigned int v14; // w22
  int v15; // w21
  unsigned int v16; // w0
  unsigned int v17; // w22
  unsigned int v18; // w0
  __int64 v19; // x8
  __int64 v20; // x4
  int v21; // w22
  __int64 v22; // x8
  __int64 v23; // x4
  __int64 v24; // x1

  if ( (a1[8] & 1) == 0 )
  {
    v4 = readl_relaxed_14(*(_QWORD *)a1 + 60LL);
    __dsb(0xFu);
    if ( (v4 & 1) != 0 )
    {
      if ( a1 )
        v24 = a1[7];
      else
        v24 = 0xFFFFFFFFLL;
      printk(&unk_239960, v24);
    }
  }
  writel_relaxed_11(1u, (unsigned int *)(*(_QWORD *)a1 + 428LL));
  _const_udelay(2147500);
  if ( (a1[8] & 1) == 0 )
  {
    v5 = readl_8(*(_QWORD *)a1 + 320LL);
    if ( (v5 & 1) == 0 )
    {
      v6 = 1005001;
      while ( 1 )
      {
        v6 -= 5001;
        if ( v6 < 0 )
          break;
        _const_udelay(21475);
        __yield();
        v5 = readl_8(*(_QWORD *)a1 + 320LL);
        if ( (v5 & 1) != 0 )
          goto LABEL_8;
      }
      if ( (readl_8(*(_QWORD *)a1 + 320LL) & 1) != 0 )
        goto LABEL_12;
LABEL_9:
      if ( a1 )
        v7 = a1[7];
      else
        v7 = -1;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Ref gen not ready. Aborting\n", v7);
      return;
    }
LABEL_8:
    if ( (v5 & 1) == 0 )
      goto LABEL_9;
  }
LABEL_12:
  if ( *(_DWORD *)(a2 + 308) == 1 )
  {
    writel_relaxed_11(0x60u, (unsigned int *)(*(_QWORD *)a1 + 36LL));
    writel_relaxed_11(0, (unsigned int *)(*(_QWORD *)a1 + 60LL));
    writel_relaxed_11(0, (unsigned int *)(*(_QWORD *)a1 + 28LL));
    writel_relaxed_11(4u, (unsigned int *)(*(_QWORD *)a1 + 276LL));
    writel_relaxed_11(
      *(unsigned __int8 *)(a2 + 300) | (16 * *(unsigned __int8 *)(a2 + 301)),
      (unsigned int *)(*(_QWORD *)a1 + 52LL));
    writel_relaxed_11(
      *(unsigned __int8 *)(a2 + 302) | (16 * *(unsigned __int8 *)(a2 + 303)),
      (unsigned int *)(*(_QWORD *)a1 + 56LL));
    writel_relaxed_11(0x40u, (unsigned int *)(*(_QWORD *)a1 + 24LL));
    writel_relaxed_11(0x45u, (unsigned int *)(*(_QWORD *)a1 + 32LL));
    writel_relaxed_11(0x41u, (unsigned int *)(*(_QWORD *)a1 + 272LL));
    writel_relaxed_11(0, (unsigned int *)(*(_QWORD *)a1 + 268LL));
    writel_relaxed_11(0, (unsigned int *)(*(_QWORD *)a1 + 236LL));
    writel_relaxed_11(0x11u, (unsigned int *)(*(_QWORD *)a1 + 260LL));
    writel_relaxed_11(1u, (unsigned int *)(*(_QWORD *)a1 + 264LL));
    writel_relaxed_11(0, (unsigned int *)(*(_QWORD *)a1 + 244LL));
    writel_relaxed_11(0, (unsigned int *)(*(_QWORD *)a1 + 248LL));
    writel_relaxed_11(0x55u, (unsigned int *)(*(_QWORD *)a1 + 256LL));
    writel_relaxed_11(0x7Fu, (unsigned int *)(*(_QWORD *)a1 + 36LL));
    writel_relaxed_11(*(_DWORD *)(a2 + 340) & 0xF | 0x10, (unsigned int *)(*(_QWORD *)a1 + 160LL));
    v8 = readl_relaxed_14(*(_QWORD *)a1 + 12LL);
    if ( ((unsigned int)readl_relaxed_14(*(_QWORD *)a1 + 8LL) | (v8 << 8)) >= 4 && *(_DWORD *)(a2 + 292) == 1 )
      writel_relaxed_11(7u, (unsigned int *)(*(_QWORD *)a1 + 432LL));
    v9 = *(unsigned int *)(a2 + 292);
    if ( (unsigned int)v9 > 2 )
      v10 = 384;
    else
      v10 = dword_28F90C[v9];
    writel_relaxed_11(v10, (unsigned int *)(*(_QWORD *)a1 + 20LL));
    writel_relaxed_11(*(unsigned __int8 *)(a2 + 196), (unsigned int *)(*(_QWORD *)a1 + 180LL));
    writel_relaxed_11(*(unsigned __int8 *)(a2 + 200), (unsigned int *)(*(_QWORD *)a1 + 196LL));
    writel_relaxed_11(*(unsigned __int8 *)(a2 + 201), (unsigned int *)(*(_QWORD *)a1 + 200LL));
    writel_relaxed_11(*(unsigned __int8 *)(a2 + 202), (unsigned int *)(*(_QWORD *)a1 + 204LL));
    writel_relaxed_11(*(unsigned __int8 *)(a2 + 203), (unsigned int *)(*(_QWORD *)a1 + 208LL));
    writel_relaxed_11(*(unsigned __int8 *)(a2 + 204), (unsigned int *)(*(_QWORD *)a1 + 212LL));
    writel_relaxed_11(*(unsigned __int8 *)(a2 + 205), (unsigned int *)(*(_QWORD *)a1 + 216LL));
    writel_relaxed_11(*(unsigned __int8 *)(a2 + 206), (unsigned int *)(*(_QWORD *)a1 + 220LL));
    writel_relaxed_11(*(unsigned __int8 *)(a2 + 207), (unsigned int *)(*(_QWORD *)a1 + 224LL));
    ((void (__fastcall *)(unsigned int *, __int64))dsi_phy_hw_v5_0_lane_settings)(a1, a2);
    if ( a1 )
      v20 = a1[7];
    else
      v20 = 0xFFFFFFFFLL;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: C-Phy enabled\n", v20);
  }
  else
  {
    v11 = *(unsigned __int8 *)(a2 + 320);
    v12 = *(_DWORD *)(a2 + 328);
    if ( *(_QWORD *)(a2 + 312) >= 0x59682F01u )
      v13 = 3;
    else
      v13 = 60;
    if ( *(_QWORD *)(a2 + 312) >= 0x59682F01u )
      v14 = 60;
    else
      v14 = 56;
    v15 = 96;
    writel_relaxed_11(0x60u, (unsigned int *)(*(_QWORD *)a1 + 36LL));
    if ( v11 == 1 )
    {
      v15 = readl_relaxed_14(*(_QWORD *)a1 + 24LL);
      writel_relaxed_11(v15 | 0x20, (unsigned int *)(*(_QWORD *)a1 + 24LL));
    }
    writel_relaxed_11(0, (unsigned int *)(*(_QWORD *)a1 + 60LL));
    writel_relaxed_11(0, (unsigned int *)(*(_QWORD *)a1 + 28LL));
    writel_relaxed_11(4u, (unsigned int *)(*(_QWORD *)a1 + 276LL));
    writel_relaxed_11(
      *(unsigned __int8 *)(a2 + 300) | (16 * *(unsigned __int8 *)(a2 + 301)),
      (unsigned int *)(*(_QWORD *)a1 + 52LL));
    writel_relaxed_11(
      *(unsigned __int8 *)(a2 + 302) | (16 * *(unsigned __int8 *)(a2 + 303)),
      (unsigned int *)(*(_QWORD *)a1 + 56LL));
    writel_relaxed_11(0x44u, (unsigned int *)(*(_QWORD *)a1 + 32LL));
    writel_relaxed_11(0x19u, (unsigned int *)(*(_QWORD *)a1 + 272LL));
    writel_relaxed_11(0, (unsigned int *)(*(_QWORD *)a1 + 48LL));
    writel_relaxed_11(0, (unsigned int *)(*(_QWORD *)a1 + 268LL));
    writel_relaxed_11(0x88u, (unsigned int *)(*(_QWORD *)a1 + 236LL));
    writel_relaxed_11(0, (unsigned int *)(*(_QWORD *)a1 + 260LL));
    writel_relaxed_11(v13, (unsigned int *)(*(_QWORD *)a1 + 244LL));
    writel_relaxed_11(v14, (unsigned int *)(*(_QWORD *)a1 + 248LL));
    writel_relaxed_11(0x55u, (unsigned int *)(*(_QWORD *)a1 + 256LL));
    if ( v11 )
    {
      if ( v12 == 1 )
        v16 = 237;
      else
        v16 = 255;
      if ( v12 == 1 )
        v17 = 53;
      else
        v17 = 63;
      writel_relaxed_11(v16, (unsigned int *)(*(_QWORD *)a1 + 36LL));
      writel_relaxed_11(v17, (unsigned int *)(*(_QWORD *)a1 + 160LL));
      v18 = 3;
      v19 = 436;
    }
    else
    {
      writel_relaxed_11(0x7Fu, (unsigned int *)(*(_QWORD *)a1 + 36LL));
      v18 = *(_DWORD *)(a2 + 340) & 0xF | 0x10;
      v19 = 160;
    }
    writel_relaxed_11(v18, (unsigned int *)(*(_QWORD *)a1 + v19));
    writel_relaxed_11(0x40u, (unsigned int *)(*(_QWORD *)a1 + 44LL));
    v21 = readl_relaxed_14(*(_QWORD *)a1 + 12LL);
    if ( ((unsigned int)readl_relaxed_14(*(_QWORD *)a1 + 8LL) | (v21 << 8)) >= 4 && *(_DWORD *)(a2 + 292) == 1 )
      writel_relaxed_11(7u, (unsigned int *)(*(_QWORD *)a1 + 432LL));
    v22 = *(unsigned int *)(a2 + 292);
    if ( (unsigned int)v22 <= 2 )
      v15 = dword_28F918[v22];
    writel_relaxed_11(4 * v15, (unsigned int *)(*(_QWORD *)a1 + 20LL));
    dsi_phy_hw_v5_0_commit_phy_timing(a1, (unsigned __int8 *)(a2 + 144));
    ((void (__fastcall *)(unsigned int *, __int64))dsi_phy_hw_v5_0_lane_settings)(a1, a2);
    if ( a1 )
      v23 = a1[7];
    else
      v23 = 0xFFFFFFFFLL;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: D-Phy enabled\n", v23);
  }
}
