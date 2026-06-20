unsigned __int8 *__fastcall dp_rx_pdev_mon_buffers_free(unsigned __int8 *result)
{
  __int64 v1; // x21
  unsigned int v2; // w27
  unsigned __int8 *v3; // x19
  __int64 v4; // x20
  int v5; // w0
  __int64 v6; // x1
  unsigned int i; // w23
  __int64 v8; // x24
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x1
  __int64 v18; // x21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w8
  __int64 v28; // x21
  __int64 v29; // x22
  __int64 v30; // x28
  __int64 v31; // x25
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned __int64 v40; // x8
  __int64 v41; // x25
  __int64 v42; // x26

  v1 = *((_QWORD *)result + 1);
  v2 = *result;
  v3 = result;
  v4 = *(_QWORD *)(v1 + 40);
  if ( *(_BYTE *)(v4 + 808) )
  {
    v5 = wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v1 + 40));
    v6 = v2;
    if ( v5 )
    {
      if ( v2 )
        goto LABEL_36;
      v6 = *(unsigned __int8 *)(*(_QWORD *)(v1 + 72) + 1LL);
    }
    result = (unsigned __int8 *)dp_rx_pdev_mon_status_buffers_free(v3, v6);
    if ( *(unsigned __int8 *)(v4 + 808) >= 2u )
    {
      for ( i = 1; i < *(unsigned __int8 *)(v4 + 808); ++i )
      {
        v8 = *((_QWORD *)v3 + 1);
        if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v8 + 40)) )
        {
          if ( v2 )
            goto LABEL_36;
          v17 = *(unsigned __int8 *)(*(_QWORD *)(v8 + 72) + 1LL);
        }
        else
        {
          v17 = i;
          if ( v2 )
          {
            qdf_trace_msg(
              0x38u,
              2u,
              "%s: Both mac_id and pdev_id cannot be non zero",
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              "dp_get_lmac_id_for_pdev_id");
            v17 = 0;
          }
        }
        result = (unsigned __int8 *)dp_rx_pdev_mon_status_buffers_free(v3, v17);
      }
    }
  }
  if ( !*(_BYTE *)(v4 + 804) )
  {
LABEL_35:
    *(_BYTE *)(*((_QWORD *)v3 + 12057) + 37216LL) = 0;
    return result;
  }
  v18 = *((_QWORD *)v3 + 1);
  result = (unsigned __int8 *)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v18 + 40));
  v27 = v2;
  if ( (_DWORD)result )
  {
    if ( v2 )
      goto LABEL_36;
    v27 = *(unsigned __int8 *)(*(_QWORD *)(v18 + 72) + 1LL);
  }
  v28 = *((_QWORD *)v3 + 1);
  if ( *(_BYTE *)(*(_QWORD *)(v28 + 40) + 633LL) != 1 )
    goto LABEL_21;
  if ( v27 <= 4 )
  {
    v29 = v28 + 120LL * v27 + 11456;
    result = (unsigned __int8 *)qdf_trace_msg(
                                  0x45u,
                                  8u,
                                  "%s: Mon RX Buf buffers Free pdev[%d]",
                                  v19,
                                  v20,
                                  v21,
                                  v22,
                                  v23,
                                  v24,
                                  v25,
                                  v26,
                                  "dp_rx_pdev_mon_buf_buffers_free",
                                  *v3);
    if ( (*(_BYTE *)(v29 + 77) & 1) == 0 )
      result = (unsigned __int8 *)dp_rx_desc_nbuf_free(v28, (int *)v29, 1);
LABEL_21:
    if ( *(unsigned __int8 *)(v4 + 804) >= 2u )
    {
      v30 = 1;
      while ( 1 )
      {
        v31 = *((_QWORD *)v3 + 1);
        result = (unsigned __int8 *)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v31 + 40));
        if ( (_DWORD)result )
          break;
        v40 = v30;
        if ( !v2 )
          goto LABEL_27;
        result = (unsigned __int8 *)qdf_trace_msg(
                                      0x38u,
                                      2u,
                                      "%s: Both mac_id and pdev_id cannot be non zero",
                                      v32,
                                      v33,
                                      v34,
                                      v35,
                                      v36,
                                      v37,
                                      v38,
                                      v39,
                                      "dp_get_lmac_id_for_pdev_id");
        v41 = *((_QWORD *)v3 + 1);
        if ( (*(_BYTE *)(*(_QWORD *)(v41 + 40) + 633LL) & 1) != 0 )
        {
          v40 = 0;
LABEL_33:
          v42 = v41 + 120 * v40 + 11456;
          result = (unsigned __int8 *)qdf_trace_msg(
                                        0x45u,
                                        8u,
                                        "%s: Mon RX Buf buffers Free pdev[%d]",
                                        v32,
                                        v33,
                                        v34,
                                        v35,
                                        v36,
                                        v37,
                                        v38,
                                        v39,
                                        "dp_rx_pdev_mon_buf_buffers_free",
                                        *v3);
          if ( (*(_BYTE *)(v42 + 77) & 1) == 0 )
            result = (unsigned __int8 *)dp_rx_desc_nbuf_free(v41, (int *)v42, 1);
        }
LABEL_23:
        if ( ++v30 >= (unsigned __int64)*(unsigned __int8 *)(v4 + 804) )
          goto LABEL_35;
      }
      if ( v2 )
        goto LABEL_36;
      v40 = *(unsigned __int8 *)(*(_QWORD *)(v31 + 72) + 1LL);
LABEL_27:
      v41 = *((_QWORD *)v3 + 1);
      if ( (*(_BYTE *)(*(_QWORD *)(v41 + 40) + 633LL) & 1) != 0 )
      {
        if ( v40 >= 5 )
          goto LABEL_36;
        goto LABEL_33;
      }
      goto LABEL_23;
    }
    goto LABEL_35;
  }
LABEL_36:
  __break(0x5512u);
  return (unsigned __int8 *)dp_rx_pdev_mon_buffers_alloc();
}
