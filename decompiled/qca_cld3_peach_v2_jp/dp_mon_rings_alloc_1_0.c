__int64 __fastcall dp_mon_rings_alloc_1_0(unsigned __int8 *a1)
{
  _QWORD *v1; // x20
  __int64 v3; // x0
  unsigned int v4; // w8
  __int64 v5; // x21
  unsigned int v6; // w22
  unsigned int dma_mon_stat_ring_size; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v17; // x0
  unsigned int v18; // w26
  int v19; // w24
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w24
  unsigned int v29; // w0
  unsigned int v30; // w3

  v1 = *((_QWORD **)a1 + 1);
  v3 = v1[5];
  v4 = *(unsigned __int8 *)(v3 + 808);
  if ( *(_BYTE *)(v3 + 808) )
  {
    v5 = *((_QWORD *)a1 + 36);
    v6 = *a1;
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(v3) )
    {
      if ( v6 )
        goto LABEL_26;
      v6 = *(unsigned __int8 *)(v1[9] + 1LL);
    }
    dma_mon_stat_ring_size = wlan_cfg_get_dma_mon_stat_ring_size(v5);
    if ( v6 <= 2 )
    {
      if ( (unsigned int)dp_srng_alloc(v1, (__int64)&v1[10 * v6 + 100], 0x11u, dma_mon_stat_ring_size, 0) )
      {
LABEL_7:
        qdf_trace_msg(
          0x92u,
          2u,
          "%s: %pK: SRNG setup failed forrxdma_mon_status_ring",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "dp_mon_rings_alloc_1_0",
          v1);
LABEL_9:
        dp_mon_rings_free_1_0(a1);
        return 2;
      }
      if ( (unsigned int)dp_mon_dest_rings_alloc(a1, v6) )
        goto LABEL_9;
      v17 = v1[5];
      if ( *(unsigned __int8 *)(v17 + 808) < 2u )
        return 0;
      v18 = 1;
      while ( 1 )
      {
        v19 = *a1;
        if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(v17) )
        {
          if ( v19 )
            break;
          v28 = *(unsigned __int8 *)(v1[9] + 1LL);
        }
        else
        {
          if ( v19 )
          {
            qdf_trace_msg(
              0x38u,
              2u,
              "%s: Both mac_id and pdev_id cannot be non zero",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              "dp_get_lmac_id_for_pdev_id");
            v30 = wlan_cfg_get_dma_mon_stat_ring_size(v5);
            v28 = 0;
            goto LABEL_20;
          }
          v28 = v18;
        }
        v29 = wlan_cfg_get_dma_mon_stat_ring_size(v5);
        if ( v28 >= 3 )
          break;
        v30 = v29;
LABEL_20:
        if ( (unsigned int)dp_srng_alloc(v1, (__int64)&v1[10 * v28 + 100], 0x11u, v30, 0) )
          goto LABEL_7;
        if ( (unsigned int)dp_mon_dest_rings_alloc(a1, v28) )
          goto LABEL_9;
        v17 = v1[5];
        ++v18;
        v4 = 0;
        if ( v18 >= *(unsigned __int8 *)(v17 + 808) )
          return v4;
      }
    }
LABEL_26:
    __break(0x5512u);
    JUMPOUT(0x5DA494);
  }
  return v4;
}
