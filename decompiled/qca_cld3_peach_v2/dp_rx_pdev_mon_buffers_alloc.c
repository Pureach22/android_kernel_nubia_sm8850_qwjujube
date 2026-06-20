__int64 __fastcall dp_rx_pdev_mon_buffers_alloc(unsigned __int8 *a1)
{
  __int64 v1; // x21
  unsigned int v2; // w24
  __int64 v4; // x20
  int v5; // w0
  __int64 v6; // x1
  unsigned int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w19
  unsigned int v18; // w23
  __int64 v19; // x25
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x1
  __int64 v29; // x22
  unsigned int v30; // w21
  __int64 v31; // x0
  int v32; // w22
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w25
  __int64 v51; // x21
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x0
  int v61; // w26
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned int v70; // w20

  v1 = *((_QWORD *)a1 + 1);
  v2 = *a1;
  v4 = *(_QWORD *)(v1 + 40);
  if ( *(_BYTE *)(v4 + 808) )
  {
    v5 = wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v1 + 40));
    v6 = v2;
    if ( v5 )
    {
      if ( v2 )
        goto LABEL_37;
      v6 = *(unsigned __int8 *)(*(_QWORD *)(v1 + 72) + 1LL);
    }
    v7 = dp_rx_pdev_mon_status_buffers_alloc(a1, v6);
    if ( v7 )
    {
LABEL_6:
      v16 = v7;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: dp_rx_pdev_mon_status_desc_pool_alloc() failed",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "dp_rx_pdev_mon_buffers_alloc");
      return v16;
    }
    if ( *(unsigned __int8 *)(v4 + 808) >= 2u )
    {
      v18 = 1;
      do
      {
        v19 = *((_QWORD *)a1 + 1);
        if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v19 + 40)) )
        {
          if ( v2 )
            goto LABEL_37;
          v28 = *(unsigned __int8 *)(*(_QWORD *)(v19 + 72) + 1LL);
        }
        else
        {
          v28 = v18;
          if ( v2 )
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
            v28 = 0;
          }
        }
        v7 = dp_rx_pdev_mon_status_buffers_alloc(a1, v28);
        if ( v7 )
          goto LABEL_6;
      }
      while ( ++v18 < *(unsigned __int8 *)(v4 + 808) );
    }
  }
  if ( *(_BYTE *)(v4 + 804) )
  {
    v29 = *((_QWORD *)a1 + 1);
    v30 = v2;
    if ( !(unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v29 + 40)) )
      goto LABEL_20;
    if ( !v2 )
    {
      v30 = *(unsigned __int8 *)(*(_QWORD *)(v29 + 72) + 1LL);
LABEL_20:
      v31 = *(_QWORD *)(*((_QWORD *)a1 + 1) + 40LL);
      if ( *(_BYTE *)(v31 + 633) == 1 )
      {
        v32 = *(_DWORD *)(v31 + 716);
        if ( (wlan_cfg_is_delay_mon_replenish(v31) & 1) != 0 )
        {
          v41 = dp_rx_pdev_mon_buf_buffers_alloc(a1, v30, v32 != 0, v33, v34, v35, v36, v37, v38, v39, v40);
          if ( v41 )
          {
LABEL_34:
            v70 = v41;
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: dp_rx_pdev_mon_buf_desc_pool_alloc() failed",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "dp_rx_pdev_mon_dest_buffers_alloc");
            dp_rx_pdev_mon_status_buffers_free(a1, v30);
            return v70;
          }
        }
      }
      if ( *(unsigned __int8 *)(v4 + 804) >= 2u )
      {
        v50 = 1;
        while ( 1 )
        {
          v51 = *((_QWORD *)a1 + 1);
          if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v51 + 40)) )
          {
            if ( v2 )
              goto LABEL_37;
            v30 = *(unsigned __int8 *)(*(_QWORD *)(v51 + 72) + 1LL);
          }
          else
          {
            v30 = v50;
            if ( v2 )
            {
              qdf_trace_msg(
                0x38u,
                2u,
                "%s: Both mac_id and pdev_id cannot be non zero",
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                "dp_get_lmac_id_for_pdev_id");
              v30 = 0;
            }
          }
          v60 = *(_QWORD *)(*((_QWORD *)a1 + 1) + 40LL);
          if ( *(_BYTE *)(v60 + 633) == 1 )
          {
            v61 = *(_DWORD *)(v60 + 716);
            if ( (wlan_cfg_is_delay_mon_replenish(v60) & 1) != 0 )
            {
              v41 = dp_rx_pdev_mon_buf_buffers_alloc(a1, v30, v61 != 0, v62, v63, v64, v65, v66, v67, v68, v69);
              if ( v41 )
                goto LABEL_34;
            }
          }
          if ( ++v50 >= (unsigned int)*(unsigned __int8 *)(v4 + 804) )
            return 0;
        }
      }
      return 0;
    }
LABEL_37:
    __break(0x5512u);
    return dp_rx_pdev_mon_desc_pool_alloc();
  }
  return 0;
}
