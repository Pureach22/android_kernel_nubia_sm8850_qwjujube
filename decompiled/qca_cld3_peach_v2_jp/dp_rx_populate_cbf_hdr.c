__int64 __fastcall dp_rx_populate_cbf_hdr(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4, int a5)
{
  unsigned __int8 *v10; // x24
  int v11; // w27
  __int64 v13; // x9
  int v14; // w26
  int v15; // w28
  int *v16; // x25
  int v17; // w8
  int v18; // w8
  unsigned int v19; // w23
  unsigned int v20; // w9
  int v21; // w8
  int v22; // w10
  int v23; // w9
  int v24; // w8
  __int64 v25; // x8

  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), a2) )
  {
    return 4;
  }
  v10 = *(unsigned __int8 **)(a1 + 72);
  if ( !v10 )
    return 4;
  if ( (unsigned __int8)a2 >= 3u )
  {
    __break(0x5512u);
    return dp_mon_set_bsscolor();
  }
  else
  {
    if ( (*(_BYTE *)(a4 + 68) & 4) != 0 )
      v11 = *(unsigned __int16 *)(a4 + 66);
    else
      v11 = 0;
    v13 = *(_QWORD *)(a4 + 40);
    v14 = *(_DWORD *)(*((_QWORD *)v10 + 11945) + 18528LL * (a2 & 3) + 3272);
    if ( v13 )
      *(_QWORD *)(a4 + 40) = v13 - 32;
    v15 = *(_DWORD *)(a4 + 112);
    skb_push(a4, 32);
    v16 = *(int **)(a4 + 224);
    v17 = *v16 | 0x1D;
    *v16 = v17;
    if ( a2 >= 4 )
    {
      printk(
        &unk_881311,
        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/dp_mon.c",
        2253,
        "!((mac_id) & ~((HTT_T2H_PPDU_STATS_MAC_ID_M) >> (HTT_T2H_PPDU_STATS_MAC_ID_S)))");
      v17 = *v16;
    }
    v18 = v17 | (a2 << 8);
    v19 = v15 + v11;
    *v16 = v18;
    v20 = *v10;
    if ( v20 >= 4 )
    {
      printk(
        &unk_881311,
        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/dp_mon.c",
        2254,
        "!((pdev->pdev_id) & ~((HTT_T2H_PPDU_STATS_PDEV_ID_M) >> (HTT_T2H_PPDU_STATS_PDEV_ID_S)))");
      v20 = *v10;
      v18 = *v16;
    }
    v21 = v18 | (v20 << 10);
    *v16 = v21;
    if ( v19 + 19 >= 0x10000 )
    {
      printk(
        &unk_881311,
        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/dp_mon.c",
        2258,
        "!((align4byte) & ~((HTT_T2H_PPDU_STATS_PAYLOAD_SIZE_M) >> (HTT_T2H_PPDU_STATS_PAYLOAD_SIZE_S)))");
      v21 = *v16;
    }
    v22 = v16[1];
    v16[2] = a5;
    v23 = v16[4];
    *v16 = v21 | ((v19 + 19) >> 2 << 18);
    v16[1] = v22 | v14;
    v24 = v23 | 0x11;
    v16[4] = v23 | 0x11;
    if ( v19 + 15 >= 0x1000 )
    {
      printk(
        &unk_881311,
        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/dp_mon.c",
        2276,
        "!((align4byte) & ~((HTT_STATS_TLV_LENGTH_M) >> (HTT_STATS_TLV_LENGTH_S)))");
      v24 = v16[4];
    }
    v16[4] = v24 | ((v19 + 15) >> 2 << 14);
    if ( v19 >= 0x10000 )
      printk(
        &unk_881311,
        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/dp_mon.c",
        2280,
        "!((data_size) & ~((HTT_PPDU_STATS_RX_MGMTCTRL_TLV_FRAME_LENGTH_M) >> (HTT_PPDU_STATS_RX_MGMTCTRL_TLV_FRAME_LENGTH_S)))");
    v16[5] |= v19;
    dp_wdi_event_handler(a3, a1, a4, 0xFFFFu, 0xFFFFFFFF, *v10);
    v25 = *(_QWORD *)(a4 + 40);
    if ( v25 )
      *(_QWORD *)(a4 + 40) = v25 + 32;
    skb_pull(a4, 32);
    return 0;
  }
}
