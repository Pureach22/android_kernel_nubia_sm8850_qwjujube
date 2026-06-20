double __fastcall dsi_phy_hw_v4_0_enable(unsigned int *a1, __int64 a2)
{
  char v4; // w0
  __int64 v5; // x1
  char v6; // w0
  __int64 v7; // x21
  int v8; // w3
  unsigned int v9; // w8
  unsigned int v10; // w23
  unsigned int v11; // w24
  unsigned int v12; // w22
  unsigned int v13; // w21
  unsigned int v14; // w8
  unsigned __int64 v15; // x9
  unsigned int v16; // w23
  int v17; // w11
  int v18; // w12
  unsigned int v19; // w22
  unsigned int v20; // w24
  double result; // d0
  unsigned int v22; // w25
  unsigned int v23; // w26
  __int64 v24; // x8
  unsigned int v25; // w0
  __int64 v26; // x4
  int v27; // w9
  unsigned int v28; // w25
  int v29; // w28
  unsigned int v30; // w26
  unsigned int v31; // w27
  int v32; // w21
  unsigned int v33; // w0
  unsigned int v34; // w22
  unsigned int v35; // w0
  __int64 v36; // x8
  __int64 v37; // x8
  __int64 v38; // x4
  int v39; // [xsp+Ch] [xbp-4h]

  v4 = readl_relaxed_13(*(_QWORD *)a1 + 60LL);
  __dsb(0xFu);
  if ( (v4 & 1) != 0 )
    printk(&unk_2441AA, v5);
  if ( a1[9] >= 5 )
  {
    writel_relaxed_10(1u, (unsigned int *)(*(_QWORD *)a1 + 428LL));
    _const_udelay(2147500);
  }
  v6 = readl_7(*(_QWORD *)a1 + 320LL);
  if ( (v6 & 1) == 0 )
  {
    v7 = 1005001;
    while ( 1 )
    {
      v7 -= 5001;
      if ( v7 < 0 )
        break;
      _const_udelay(21475);
      __yield();
      v6 = readl_7(*(_QWORD *)a1 + 320LL);
      if ( (v6 & 1) != 0 )
        goto LABEL_9;
    }
    if ( (readl_7(*(_QWORD *)a1 + 320LL) & 1) != 0 )
      goto LABEL_13;
LABEL_10:
    if ( a1 )
      v8 = a1[7];
    else
      v8 = -1;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Ref gen not ready. Aborting\n", v8);
    return result;
  }
LABEL_9:
  if ( (v6 & 1) == 0 )
    goto LABEL_10;
LABEL_13:
  if ( *(_DWORD *)(a2 + 308) == 1 )
  {
    v9 = a1[9];
    if ( v9 < 4 )
    {
      if ( v9 == 3 )
        v12 = 0;
      else
        v12 = 3;
      v13 = 60;
      if ( v9 == 3 )
        v10 = 136;
      else
        v10 = 102;
      v11 = v12;
    }
    else
    {
      v10 = 0;
      v11 = 0;
      if ( *(_QWORD *)(a2 + 312) >= 0x59682F01u )
        v12 = 1;
      else
        v12 = 61;
      if ( *(_QWORD *)(a2 + 312) >= 0x59682F01u )
        v13 = 59;
      else
        v13 = 56;
    }
    if ( v9 == 6 )
      v22 = 65;
    else
      v22 = 85;
    if ( v9 == 6 )
      v23 = 69;
    else
      v23 = 81;
    writel_relaxed_10(0x60u, (unsigned int *)(*(_QWORD *)a1 + 36LL));
    writel_relaxed_10(0, (unsigned int *)(*(_QWORD *)a1 + 60LL));
    writel_relaxed_10(0, (unsigned int *)(*(_QWORD *)a1 + 28LL));
    if ( (readl_relaxed_13(*(_QWORD *)a1) & 0xE0) != 0 )
      writel_relaxed_10(4u, (unsigned int *)(*(_QWORD *)a1 + 276LL));
    writel_relaxed_10(
      *(unsigned __int8 *)(a2 + 300) | (16 * *(unsigned __int8 *)(a2 + 301)),
      (unsigned int *)(*(_QWORD *)a1 + 52LL));
    writel_relaxed_10(
      *(unsigned __int8 *)(a2 + 302) | (16 * *(unsigned __int8 *)(a2 + 303)),
      (unsigned int *)(*(_QWORD *)a1 + 56LL));
    writel_relaxed_10(0x40u, (unsigned int *)(*(_QWORD *)a1 + 24LL));
    writel_relaxed_10(v23, (unsigned int *)(*(_QWORD *)a1 + 32LL));
    writel_relaxed_10(v22, (unsigned int *)(*(_QWORD *)a1 + 272LL));
    writel_relaxed_10(v11, (unsigned int *)(*(_QWORD *)a1 + 268LL));
    writel_relaxed_10(v10, (unsigned int *)(*(_QWORD *)a1 + 236LL));
    writel_relaxed_10(0x11u, (unsigned int *)(*(_QWORD *)a1 + 260LL));
    writel_relaxed_10(1u, (unsigned int *)(*(_QWORD *)a1 + 264LL));
    writel_relaxed_10(v12, (unsigned int *)(*(_QWORD *)a1 + 244LL));
    writel_relaxed_10(v13, (unsigned int *)(*(_QWORD *)a1 + 248LL));
    writel_relaxed_10(0x55u, (unsigned int *)(*(_QWORD *)a1 + 256LL));
    writel_relaxed_10(0x7Fu, (unsigned int *)(*(_QWORD *)a1 + 36LL));
    writel_relaxed_10(*(_DWORD *)(a2 + 340) & 0xF | 0x10, (unsigned int *)(*(_QWORD *)a1 + 160LL));
    v24 = *(unsigned int *)(a2 + 292);
    if ( (unsigned int)v24 > 2 )
      v25 = 384;
    else
      v25 = dword_28F8F4[v24];
    writel_relaxed_10(v25, (unsigned int *)(*(_QWORD *)a1 + 20LL));
    writel_relaxed_10(*(unsigned __int8 *)(a2 + 196), (unsigned int *)(*(_QWORD *)a1 + 180LL));
    writel_relaxed_10(*(unsigned __int8 *)(a2 + 200), (unsigned int *)(*(_QWORD *)a1 + 196LL));
    writel_relaxed_10(*(unsigned __int8 *)(a2 + 201), (unsigned int *)(*(_QWORD *)a1 + 200LL));
    writel_relaxed_10(*(unsigned __int8 *)(a2 + 202), (unsigned int *)(*(_QWORD *)a1 + 204LL));
    writel_relaxed_10(*(unsigned __int8 *)(a2 + 203), (unsigned int *)(*(_QWORD *)a1 + 208LL));
    writel_relaxed_10(*(unsigned __int8 *)(a2 + 204), (unsigned int *)(*(_QWORD *)a1 + 212LL));
    writel_relaxed_10(*(unsigned __int8 *)(a2 + 205), (unsigned int *)(*(_QWORD *)a1 + 216LL));
    writel_relaxed_10(*(unsigned __int8 *)(a2 + 206), (unsigned int *)(*(_QWORD *)a1 + 220LL));
    writel_relaxed_10(*(unsigned __int8 *)(a2 + 207), (unsigned int *)(*(_QWORD *)a1 + 224LL));
    ((void (__fastcall *)(unsigned int *, __int64))dsi_phy_hw_v4_0_lane_settings)(a1, a2);
    if ( a1 )
      v26 = a1[7];
    else
      v26 = 0xFFFFFFFFLL;
    return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: C-Phy enabled\n", v26);
  }
  else
  {
    v14 = a1[9];
    v15 = *(_QWORD *)(a2 + 312);
    if ( v14 < 4 )
    {
      if ( v14 == 3 )
      {
        v16 = 0;
        if ( v15 >= 0x59682F01 )
          v17 = 82;
        else
          v17 = 83;
        if ( v15 >= 0x59682F01 )
          v18 = 0;
        else
          v18 = 61;
        if ( v15 >= 0x59682F01 )
          v19 = 60;
        else
          v19 = 57;
        v20 = 136;
      }
      else
      {
        v18 = 3;
        if ( v15 >= 0x59682F01 )
          v17 = 89;
        else
          v17 = 91;
        if ( v15 >= 0x59682F01 )
          v16 = 0;
        else
          v16 = 3;
        v19 = 60;
        if ( v15 >= 0x59682F01 )
          v20 = 136;
        else
          v20 = 102;
      }
    }
    else
    {
      v16 = 0;
      if ( v15 >= 0x59682F01 )
        v17 = 82;
      else
        v17 = 83;
      if ( v15 >= 0x59682F01 )
        v18 = 0;
      else
        v18 = 60;
      if ( v15 < 0x59682F01 )
        v19 = 56;
      else
        v19 = 57;
      v20 = 136;
    }
    if ( v15 >= 0x59682F01 )
      v27 = 1;
    else
      v27 = 61;
    if ( v14 <= 4 )
      v28 = v18;
    else
      v28 = v27;
    v29 = *(unsigned __int8 *)(a2 + 320);
    v39 = *(_DWORD *)(a2 + 328);
    if ( v14 == 6 )
      v30 = 25;
    else
      v30 = 92;
    if ( v14 == 6 )
      v31 = 68;
    else
      v31 = v17;
    v32 = 96;
    writel_relaxed_10(0x60u, (unsigned int *)(*(_QWORD *)a1 + 36LL));
    if ( v29 == 1 )
    {
      v32 = readl_relaxed_13(*(_QWORD *)a1 + 24LL);
      writel_relaxed_10(v32 | 0x20, (unsigned int *)(*(_QWORD *)a1 + 24LL));
    }
    writel_relaxed_10(0, (unsigned int *)(*(_QWORD *)a1 + 60LL));
    writel_relaxed_10(0, (unsigned int *)(*(_QWORD *)a1 + 28LL));
    if ( (readl_relaxed_13(*(_QWORD *)a1) & 0xE0) != 0 )
      writel_relaxed_10(4u, (unsigned int *)(*(_QWORD *)a1 + 276LL));
    writel_relaxed_10(
      *(unsigned __int8 *)(a2 + 300) | (16 * *(unsigned __int8 *)(a2 + 301)),
      (unsigned int *)(*(_QWORD *)a1 + 52LL));
    writel_relaxed_10(
      *(unsigned __int8 *)(a2 + 302) | (16 * *(unsigned __int8 *)(a2 + 303)),
      (unsigned int *)(*(_QWORD *)a1 + 56LL));
    writel_relaxed_10(v31, (unsigned int *)(*(_QWORD *)a1 + 32LL));
    writel_relaxed_10(v30, (unsigned int *)(*(_QWORD *)a1 + 272LL));
    writel_relaxed_10(0, (unsigned int *)(*(_QWORD *)a1 + 48LL));
    writel_relaxed_10(v16, (unsigned int *)(*(_QWORD *)a1 + 268LL));
    writel_relaxed_10(v20, (unsigned int *)(*(_QWORD *)a1 + 236LL));
    writel_relaxed_10(0, (unsigned int *)(*(_QWORD *)a1 + 260LL));
    writel_relaxed_10(v28, (unsigned int *)(*(_QWORD *)a1 + 244LL));
    writel_relaxed_10(v19, (unsigned int *)(*(_QWORD *)a1 + 248LL));
    writel_relaxed_10(0x55u, (unsigned int *)(*(_QWORD *)a1 + 256LL));
    if ( v29 )
    {
      if ( v39 == 1 )
        v33 = 237;
      else
        v33 = 255;
      if ( v39 == 1 )
        v34 = 53;
      else
        v34 = 63;
      writel_relaxed_10(v33, (unsigned int *)(*(_QWORD *)a1 + 36LL));
      writel_relaxed_10(v34, (unsigned int *)(*(_QWORD *)a1 + 160LL));
      v35 = 3;
      v36 = 436;
    }
    else
    {
      writel_relaxed_10(0x7Fu, (unsigned int *)(*(_QWORD *)a1 + 36LL));
      v35 = *(_DWORD *)(a2 + 340) & 0xF | 0x10;
      v36 = 160;
    }
    writel_relaxed_10(v35, (unsigned int *)(*(_QWORD *)a1 + v36));
    writel_relaxed_10(0x40u, (unsigned int *)(*(_QWORD *)a1 + 44LL));
    v37 = *(unsigned int *)(a2 + 292);
    if ( (unsigned int)v37 <= 2 )
      v32 = dword_28F900[v37];
    writel_relaxed_10(4 * v32, (unsigned int *)(*(_QWORD *)a1 + 20LL));
    dsi_phy_hw_v4_0_commit_phy_timing(a1, (unsigned __int8 *)(a2 + 144));
    ((void (__fastcall *)(unsigned int *, __int64))dsi_phy_hw_v4_0_lane_settings)(a1, a2);
    if ( a1 )
      v38 = a1[7];
    else
      v38 = 0xFFFFFFFFLL;
    return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: D-Phy enabled\n", v38);
  }
}
