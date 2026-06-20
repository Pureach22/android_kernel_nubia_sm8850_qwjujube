__int64 __fastcall wma_set_per_link_amsdu_cap(__int64 a1, __int64 a2, int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w24
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w23
  unsigned int v56; // w22
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w0

  if ( (unsigned __int8)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 32), 0) )
  {
    v14 = 16;
  }
  else
  {
    v55 = wma_set_tx_rx_aggr_size(0, *(_DWORD *)(a2 + 4), *(_DWORD *)(a2 + 4), a3, v6, v7, v8, v9, v10, v11, v12, v13);
    v56 = 0;
    v14 = 0;
    if ( v55 )
    {
LABEL_20:
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: set_aggr_size failed for vdev: %d, ret %d",
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        "wma_set_per_link_amsdu_cap",
        v56,
        v55);
      return v55;
    }
  }
  if ( !(unsigned __int8)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 32), 1) )
  {
    v56 = 1;
    v65 = wma_set_tx_rx_aggr_size(
            1u,
            *(_DWORD *)(a2 + 4),
            *(_DWORD *)(a2 + 4),
            a3,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22);
    if ( v65 )
      goto LABEL_19;
    v14 = 0;
  }
  if ( !(unsigned __int8)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 32), 2) )
  {
    v56 = 2;
    v65 = wma_set_tx_rx_aggr_size(
            2u,
            *(_DWORD *)(a2 + 4),
            *(_DWORD *)(a2 + 4),
            a3,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30);
    if ( v65 )
      goto LABEL_19;
    v14 = 0;
  }
  if ( (unsigned __int8)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 32), 3) )
    goto LABEL_6;
  v56 = 3;
  v65 = wma_set_tx_rx_aggr_size(
          3u,
          *(_DWORD *)(a2 + 4),
          *(_DWORD *)(a2 + 4),
          a3,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38);
  if ( v65 )
  {
LABEL_19:
    v55 = v65;
    goto LABEL_20;
  }
  v14 = 0;
LABEL_6:
  if ( !(unsigned __int8)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 32), 4) )
  {
    v56 = 4;
    v65 = wma_set_tx_rx_aggr_size(
            4u,
            *(_DWORD *)(a2 + 4),
            *(_DWORD *)(a2 + 4),
            a3,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46);
    if ( !v65 )
    {
      v14 = 0;
      goto LABEL_7;
    }
    goto LABEL_19;
  }
LABEL_7:
  v55 = v14;
  if ( !(unsigned __int8)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 32), 5) )
  {
    v56 = 5;
    v55 = wma_set_tx_rx_aggr_size(
            5u,
            *(_DWORD *)(a2 + 4),
            *(_DWORD *)(a2 + 4),
            a3,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54);
    if ( v55 )
      goto LABEL_20;
  }
  return v55;
}
