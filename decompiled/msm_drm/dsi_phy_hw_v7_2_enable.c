void __fastcall dsi_phy_hw_v7_2_enable(unsigned int *a1, __int64 a2)
{
  char v4; // w0
  char v5; // w0
  __int64 v6; // x21
  int v7; // w3
  unsigned int v8; // w0
  unsigned int v9; // w21
  unsigned int v10; // w8
  unsigned int v11; // w0
  int v12; // w25
  int v13; // w24
  unsigned int v14; // w23
  unsigned int v15; // w22
  int v16; // w21
  unsigned int v17; // w0
  unsigned int v18; // w22
  unsigned int v19; // w0
  __int64 v20; // x8
  __int64 v21; // x4
  unsigned int v22; // w8
  __int64 v23; // x4
  __int64 v24; // x1

  if ( (a1[8] & 1) == 0 )
  {
    v4 = readl_relaxed_15(*(_QWORD *)a1 + 60LL);
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
  writel_relaxed_12(1u, (unsigned int *)(*(_QWORD *)a1 + 428LL));
  _const_udelay(2147500);
  if ( (a1[8] & 1) == 0 )
  {
    v5 = readl_9(*(_QWORD *)a1 + 320LL);
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
        v5 = readl_9(*(_QWORD *)a1 + 320LL);
        if ( (v5 & 1) != 0 )
          goto LABEL_8;
      }
      if ( (readl_9(*(_QWORD *)a1 + 320LL) & 1) != 0 )
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
    writel_relaxed_12(0x60u, (unsigned int *)(*(_QWORD *)a1 + 36LL));
    writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + 60LL));
    writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + 28LL));
    writel_relaxed_12(4u, (unsigned int *)(*(_QWORD *)a1 + 276LL));
    writel_relaxed_12(
      *(unsigned __int8 *)(a2 + 300) | (16 * *(unsigned __int8 *)(a2 + 301)),
      (unsigned int *)(*(_QWORD *)a1 + 52LL));
    writel_relaxed_12(
      *(unsigned __int8 *)(a2 + 302) | (16 * *(unsigned __int8 *)(a2 + 303)),
      (unsigned int *)(*(_QWORD *)a1 + 56LL));
    writel_relaxed_12(0x40u, (unsigned int *)(*(_QWORD *)a1 + 24LL));
    if ( a1[7] )
      v8 = 68;
    else
      v8 = 87;
    if ( a1[7] )
      v9 = 66;
    else
      v9 = 65;
    writel_relaxed_12(v8, (unsigned int *)(*(_QWORD *)a1 + 32LL));
    writel_relaxed_12(v9, (unsigned int *)(*(_QWORD *)a1 + 272LL));
    writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + 268LL));
    writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + 236LL));
    writel_relaxed_12(0x11u, (unsigned int *)(*(_QWORD *)a1 + 260LL));
    writel_relaxed_12(1u, (unsigned int *)(*(_QWORD *)a1 + 264LL));
    writel_relaxed_12(0x3Du, (unsigned int *)(*(_QWORD *)a1 + 244LL));
    writel_relaxed_12(0x38u, (unsigned int *)(*(_QWORD *)a1 + 248LL));
    writel_relaxed_12(0x55u, (unsigned int *)(*(_QWORD *)a1 + 256LL));
    writel_relaxed_12(0x7Fu, (unsigned int *)(*(_QWORD *)a1 + 36LL));
    writel_relaxed_12(*(_DWORD *)(a2 + 340) & 0xF | 0x10, (unsigned int *)(*(_QWORD *)a1 + 160LL));
    v10 = *(_DWORD *)(a2 + 292);
    if ( v10 == 1 )
    {
      writel_relaxed_12(7u, (unsigned int *)(*(_QWORD *)a1 + 432LL));
      v10 = *(_DWORD *)(a2 + 292);
    }
    if ( v10 > 2 )
      v11 = 384;
    else
      v11 = dword_28F924[v10];
    writel_relaxed_12(v11, (unsigned int *)(*(_QWORD *)a1 + 20LL));
    writel_relaxed_12(*(unsigned __int8 *)(a2 + 196), (unsigned int *)(*(_QWORD *)a1 + 180LL));
    writel_relaxed_12(*(unsigned __int8 *)(a2 + 200), (unsigned int *)(*(_QWORD *)a1 + 196LL));
    writel_relaxed_12(*(unsigned __int8 *)(a2 + 201), (unsigned int *)(*(_QWORD *)a1 + 200LL));
    writel_relaxed_12(*(unsigned __int8 *)(a2 + 202), (unsigned int *)(*(_QWORD *)a1 + 204LL));
    writel_relaxed_12(*(unsigned __int8 *)(a2 + 203), (unsigned int *)(*(_QWORD *)a1 + 208LL));
    writel_relaxed_12(*(unsigned __int8 *)(a2 + 204), (unsigned int *)(*(_QWORD *)a1 + 212LL));
    writel_relaxed_12(*(unsigned __int8 *)(a2 + 205), (unsigned int *)(*(_QWORD *)a1 + 216LL));
    writel_relaxed_12(*(unsigned __int8 *)(a2 + 206), (unsigned int *)(*(_QWORD *)a1 + 220LL));
    writel_relaxed_12(*(unsigned __int8 *)(a2 + 207), (unsigned int *)(*(_QWORD *)a1 + 224LL));
    ((void (__fastcall *)(unsigned int *, __int64))dsi_phy_hw_v7_2_lane_settings)(a1, a2);
    if ( a1 )
      v21 = a1[7];
    else
      v21 = 0xFFFFFFFFLL;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: C-Phy enabled\n", v21);
  }
  else
  {
    v12 = *(unsigned __int8 *)(a2 + 320);
    v13 = *(_DWORD *)(a2 + 328);
    if ( *(_QWORD *)(a2 + 312) >= 0x59682F01u )
      v14 = 3;
    else
      v14 = 60;
    if ( *(_QWORD *)(a2 + 312) >= 0x59682F01u )
      v15 = 60;
    else
      v15 = 56;
    v16 = 96;
    writel_relaxed_12(0x60u, (unsigned int *)(*(_QWORD *)a1 + 36LL));
    if ( v12 == 1 )
    {
      v16 = readl_relaxed_15(*(_QWORD *)a1 + 24LL);
      writel_relaxed_12(v16 | 0x20, (unsigned int *)(*(_QWORD *)a1 + 24LL));
    }
    writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + 60LL));
    writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + 28LL));
    writel_relaxed_12(4u, (unsigned int *)(*(_QWORD *)a1 + 276LL));
    writel_relaxed_12(
      *(unsigned __int8 *)(a2 + 300) | (16 * *(unsigned __int8 *)(a2 + 301)),
      (unsigned int *)(*(_QWORD *)a1 + 52LL));
    writel_relaxed_12(
      *(unsigned __int8 *)(a2 + 302) | (16 * *(unsigned __int8 *)(a2 + 303)),
      (unsigned int *)(*(_QWORD *)a1 + 56LL));
    writel_relaxed_12(0x56u, (unsigned int *)(*(_QWORD *)a1 + 32LL));
    writel_relaxed_12(0x19u, (unsigned int *)(*(_QWORD *)a1 + 272LL));
    writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + 48LL));
    writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + 268LL));
    writel_relaxed_12(0x88u, (unsigned int *)(*(_QWORD *)a1 + 236LL));
    writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + 260LL));
    writel_relaxed_12(v14, (unsigned int *)(*(_QWORD *)a1 + 244LL));
    writel_relaxed_12(v15, (unsigned int *)(*(_QWORD *)a1 + 248LL));
    writel_relaxed_12(0x55u, (unsigned int *)(*(_QWORD *)a1 + 256LL));
    if ( v12 )
    {
      if ( v13 == 1 )
        v17 = 237;
      else
        v17 = 255;
      if ( v13 == 1 )
        v18 = 53;
      else
        v18 = 63;
      writel_relaxed_12(v17, (unsigned int *)(*(_QWORD *)a1 + 36LL));
      writel_relaxed_12(v18, (unsigned int *)(*(_QWORD *)a1 + 160LL));
      writel_relaxed_12(7u, (unsigned int *)(*(_QWORD *)a1 + 432LL));
      v19 = 3;
      v20 = 436;
    }
    else
    {
      writel_relaxed_12(0x7Fu, (unsigned int *)(*(_QWORD *)a1 + 36LL));
      v19 = *(_DWORD *)(a2 + 340) & 0xF | 0x10;
      v20 = 160;
    }
    writel_relaxed_12(v19, (unsigned int *)(*(_QWORD *)a1 + v20));
    writel_relaxed_12(0x40u, (unsigned int *)(*(_QWORD *)a1 + 44LL));
    v22 = *(_DWORD *)(a2 + 292);
    if ( v22 == 1 )
    {
      writel_relaxed_12(7u, (unsigned int *)(*(_QWORD *)a1 + 432LL));
      v22 = *(_DWORD *)(a2 + 292);
    }
    if ( v22 <= 2 )
      v16 = dword_28F930[v22];
    writel_relaxed_12(4 * v16, (unsigned int *)(*(_QWORD *)a1 + 20LL));
    dsi_phy_hw_v7_2_commit_phy_timing(a1, (unsigned __int8 *)(a2 + 144));
    ((void (__fastcall *)(unsigned int *, __int64))dsi_phy_hw_v7_2_lane_settings)(a1, a2);
    if ( a1 )
      v23 = a1[7];
    else
      v23 = 0xFFFFFFFFLL;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: D-Phy enabled\n", v23);
  }
}
