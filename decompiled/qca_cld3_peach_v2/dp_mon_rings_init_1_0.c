__int64 __fastcall dp_mon_rings_init_1_0(unsigned __int8 *a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  unsigned int v4; // w8
  unsigned int v5; // w21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v15; // x0
  unsigned int v16; // w21
  int v17; // w24
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w24

  v1 = *((_QWORD *)a1 + 1);
  v3 = *(_QWORD *)(v1 + 40);
  v4 = *(unsigned __int8 *)(v3 + 808);
  if ( !*(_BYTE *)(v3 + 808) )
    return v4;
  v5 = *a1;
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(v3) )
  {
    if ( v5 )
      goto LABEL_25;
    v5 = *(unsigned __int8 *)(*(_QWORD *)(v1 + 72) + 1LL);
  }
  if ( v5 <= 2 )
  {
    if ( (unsigned int)dp_srng_init(v1) )
    {
LABEL_7:
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: %pK: SRNG setup failed forrxdma_mon_status_ring",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "dp_mon_rings_init_1_0",
        v1);
    }
    else if ( !(unsigned int)((__int64 (__fastcall *)(unsigned __int8 *, _QWORD))dp_mon_dest_rings_init)(a1, v5) )
    {
      v15 = *(_QWORD *)(v1 + 40);
      if ( *(unsigned __int8 *)(v15 + 808) < 2u )
        return 0;
      v16 = 1;
      while ( 1 )
      {
        v17 = *a1;
        if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(v15) )
        {
          if ( v17 )
            goto LABEL_25;
          v26 = *(unsigned __int8 *)(*(_QWORD *)(v1 + 72) + 1LL);
          if ( v26 >= 3 )
            goto LABEL_25;
        }
        else if ( v17 )
        {
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: Both mac_id and pdev_id cannot be non zero",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            "dp_get_lmac_id_for_pdev_id");
          v26 = 0;
        }
        else
        {
          v26 = v16;
          if ( v16 >= 3 )
            goto LABEL_25;
        }
        if ( (unsigned int)dp_srng_init(v1) )
          goto LABEL_7;
        if ( (unsigned int)((__int64 (__fastcall *)(unsigned __int8 *, _QWORD))dp_mon_dest_rings_init)(a1, v26) )
          break;
        v15 = *(_QWORD *)(v1 + 40);
        ++v16;
        v4 = 0;
        if ( v16 >= *(unsigned __int8 *)(v15 + 808) )
          return v4;
      }
    }
    dp_mon_rings_deinit_1_0(a1);
    return 2;
  }
LABEL_25:
  __break(0x5512u);
  return dp_mon_rings_alloc_1_0();
}
