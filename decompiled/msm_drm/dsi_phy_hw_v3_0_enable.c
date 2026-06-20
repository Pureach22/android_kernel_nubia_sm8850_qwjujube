void __fastcall dsi_phy_hw_v3_0_enable(unsigned int *a1, __int64 a2)
{
  char v4; // w0
  char v5; // w0
  __int64 v6; // x21
  int v7; // w3
  unsigned int v8; // w21
  __int64 v9; // x8
  __int64 v10; // x0
  unsigned __int8 *v11; // x20
  unsigned __int8 *v12; // x21
  __int64 i; // x22
  unsigned int v14; // t1
  int v15; // w4
  __int64 v16; // x1

  v4 = readl_relaxed_12((unsigned int *)(*(_QWORD *)a1 + 56LL));
  __dsb(0xFu);
  if ( (v4 & 1) != 0 )
  {
    if ( a1 )
      v16 = a1[7];
    else
      v16 = 0xFFFFFFFFLL;
    printk(&unk_239960, v16);
  }
  v5 = readl_6(*(_QWORD *)a1 + 236LL);
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
      v5 = readl_6(*(_QWORD *)a1 + 236LL);
      if ( (v5 & 1) != 0 )
        goto LABEL_6;
    }
    if ( (readl_6(*(_QWORD *)a1 + 236LL) & 1) != 0 )
      goto LABEL_10;
LABEL_7:
    if ( a1 )
      v7 = a1[7];
    else
      v7 = -1;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Ref gen not ready. Aborting\n", v7);
    return;
  }
LABEL_6:
  if ( (v5 & 1) == 0 )
    goto LABEL_7;
LABEL_10:
  writel_relaxed_9(0x60u, (unsigned int *)(*(_QWORD *)a1 + 36LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 56LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 28LL));
  writel_relaxed_9(0x10u, (unsigned int *)(*(_QWORD *)a1 + 24LL));
  writel_relaxed_9(0x59u, (unsigned int *)(*(_QWORD *)a1 + 32LL));
  writel_relaxed_9(
    *(unsigned __int8 *)(a2 + 300) | (16 * *(unsigned __int8 *)(a2 + 301)),
    (unsigned int *)(*(_QWORD *)a1 + 48LL));
  writel_relaxed_9(
    *(unsigned __int8 *)(a2 + 302) | (16 * *(unsigned __int8 *)(a2 + 303)),
    (unsigned int *)(*(_QWORD *)a1 + 52LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 184), (unsigned int *)(*(_QWORD *)a1 + 172LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 185), (unsigned int *)(*(_QWORD *)a1 + 176LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 186), (unsigned int *)(*(_QWORD *)a1 + 180LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 187), (unsigned int *)(*(_QWORD *)a1 + 184LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 188), (unsigned int *)(*(_QWORD *)a1 + 188LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 189), (unsigned int *)(*(_QWORD *)a1 + 192LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 190), (unsigned int *)(*(_QWORD *)a1 + 196LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 191), (unsigned int *)(*(_QWORD *)a1 + 200LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 192), (unsigned int *)(*(_QWORD *)a1 + 204LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 193), (unsigned int *)(*(_QWORD *)a1 + 208LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 194), (unsigned int *)(*(_QWORD *)a1 + 212LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 195), (unsigned int *)(*(_QWORD *)a1 + 216LL));
  writel_relaxed_9(0x7Fu, (unsigned int *)(*(_QWORD *)a1 + 36LL));
  v8 = readl_relaxed_12((unsigned int *)(*(_QWORD *)a1 + 36LL)) | 0x1F;
  writel_relaxed_9(v8, (unsigned int *)(*(_QWORD *)a1 + 36LL));
  writel_relaxed_9(0x1Fu, (unsigned int *)(*(_QWORD *)a1 + 152LL));
  writel_relaxed_9(0x40u, (unsigned int *)(*(_QWORD *)a1 + 44LL));
  v9 = *(unsigned int *)(a2 + 292);
  if ( (unsigned int)v9 <= 2 )
    v8 = dword_28F8E8[v9];
  writel_relaxed_9(4 * v8, (unsigned int *)(*(_QWORD *)a1 + 20LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 72), (unsigned int *)(*(_QWORD *)a1 + 548LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 552LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 532LL));
  writel_relaxed_9(0x88u, (unsigned int *)(*(_QWORD *)a1 + 536LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 80), (unsigned int *)(*(_QWORD *)a1 + 676LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 680LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 660LL));
  writel_relaxed_9(0x88u, (unsigned int *)(*(_QWORD *)a1 + 664LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 88), (unsigned int *)(*(_QWORD *)a1 + 804LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 808LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 788LL));
  writel_relaxed_9(0x88u, (unsigned int *)(*(_QWORD *)a1 + 792LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 96), (unsigned int *)(*(_QWORD *)a1 + 932LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 936LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 916LL));
  writel_relaxed_9(0x88u, (unsigned int *)(*(_QWORD *)a1 + 920LL));
  writel_relaxed_9(*(unsigned __int8 *)(a2 + 104), (unsigned int *)(*(_QWORD *)a1 + 1060LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 1064LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 1044LL));
  writel_relaxed_9(0x88u, (unsigned int *)(*(_QWORD *)a1 + 1048LL));
  v10 = dsi_phy_conv_logical_to_phy_lane(a2 + 296, 0);
  if ( (unsigned int)v10 >= 5 )
  {
    __break(0x5512u);
    readl_6(v10);
  }
  else
  {
    writel_relaxed_9(
      *(unsigned __int8 *)(a2 + 72 + 8LL * (unsigned int)v10 + 1),
      (unsigned int *)(*(_QWORD *)a1 + (unsigned int)((_DWORD)v10 << 7) + 552LL));
    v11 = (unsigned __int8 *)(a2 + 1);
    v12 = (unsigned __int8 *)&unk_28F8E0;
    for ( i = 556; i != 1196; i += 128 )
    {
      writel_relaxed_9(*(v11 - 1), (unsigned int *)(*(_QWORD *)a1 + i - 44));
      writel_relaxed_9(*v11, (unsigned int *)(*(_QWORD *)a1 + i - 40));
      writel_relaxed_9(v11[1], (unsigned int *)(*(_QWORD *)a1 + i - 36));
      writel_relaxed_9(v11[2], (unsigned int *)(*(_QWORD *)a1 + i - 32));
      writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + i - 16));
      writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + i - 12));
      v14 = *v12++;
      writel_relaxed_9(v14, (unsigned int *)(*(_QWORD *)a1 + i));
      v11 += 8;
    }
    if ( a1 )
      v15 = a1[7];
    else
      v15 = -1;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Phy enabled\n", v15);
  }
}
