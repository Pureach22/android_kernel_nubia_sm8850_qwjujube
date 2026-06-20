__int64 __fastcall dp_rx_pdev_mon_desc_pool_alloc(unsigned __int8 *a1)
{
  __int64 v1; // x21
  unsigned int v3; // w20
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w22
  unsigned int v14; // w21
  __int64 v15; // x21
  __int64 v16; // x0
  char is_delay_mon_replenish; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  __int64 v27; // x24
  __int64 v28; // x25
  unsigned int v29; // w23
  int dp_soc_rx_sw_desc_weight; // w24
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
  unsigned int v47; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w20
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 result; // x0
  __int64 v84; // x21
  __int64 v85; // x0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x22
  __int64 v95; // x24
  unsigned int v96; // w23
  __int64 v97; // x25
  int v98; // w24
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  unsigned int v115; // w0

  v1 = *((_QWORD *)a1 + 1);
  v3 = *a1;
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v1 + 40)) )
  {
    if ( v3 )
      goto LABEL_41;
    v3 = *(unsigned __int8 *)(*(_QWORD *)(v1 + 72) + 1LL);
  }
  v4 = ((__int64 (__fastcall *)(unsigned __int8 *, _QWORD))dp_rx_pdev_mon_status_desc_pool_alloc)(a1, v3);
  if ( !v4 )
  {
    v15 = *((_QWORD *)a1 + 1);
    v16 = *(_QWORD *)(v15 + 40);
    if ( *(_BYTE *)(v16 + 633) == 1 )
    {
      is_delay_mon_replenish = wlan_cfg_is_delay_mon_replenish(v16);
      v26 = *((_QWORD *)a1 + 1);
      if ( (is_delay_mon_replenish & 1) != 0 )
      {
        if ( v3 >= 3 )
          goto LABEL_41;
        v27 = *(_QWORD *)(v26 + 40);
        v28 = v26 + 120LL * v3;
        v29 = *(_DWORD *)(v26 + 80LL * v3 + 532);
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: Mon RX Desc Pool[%d] entries=%u",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "dp_rx_pdev_mon_buf_desc_pool_alloc",
          *a1,
          v29);
        dp_soc_rx_sw_desc_weight = wlan_cfg_get_dp_soc_rx_sw_desc_weight(v27);
        if ( (unsigned int)dp_rx_desc_pool_is_allocated(
                             (unsigned int *)(v28 + 11408),
                             v31,
                             v32,
                             v33,
                             v34,
                             v35,
                             v36,
                             v37,
                             v38) )
        {
          v47 = dp_rx_desc_pool_alloc(
                  v26,
                  dp_soc_rx_sw_desc_weight * v29,
                  v28 + 11408,
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46);
          if ( v47 )
          {
            v13 = v47;
            v14 = 0;
LABEL_34:
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: dp_rx_pdev_mon_buf_desc_pool_alloc() failed",
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              "dp_rx_pdev_mon_dest_desc_pool_alloc");
LABEL_40:
            ((void (__fastcall *)(unsigned __int8 *, _QWORD))dp_rx_pdev_mon_status_desc_pool_free)(a1, v3);
            goto LABEL_24;
          }
        }
        v65 = ((__int64 (__fastcall *)(__int64, _QWORD))dp_hw_link_desc_pool_banks_alloc)(v15, v3);
        if ( v65 )
        {
          v13 = v65;
          v14 = 0;
          goto LABEL_39;
        }
        v15 = *((_QWORD *)a1 + 1);
      }
      else
      {
        v15 = *((_QWORD *)a1 + 1);
      }
    }
    v56 = *a1;
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v15 + 40)) )
    {
      if ( v56 )
        goto LABEL_41;
      v3 = *(unsigned __int8 *)(*(_QWORD *)(v15 + 72) + 1LL);
    }
    else if ( v56 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Both mac_id and pdev_id cannot be non zero",
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        "dp_get_lmac_id_for_pdev_id");
      v3 = 0;
    }
    else
    {
      v3 = 1;
    }
    v74 = ((__int64 (__fastcall *)(unsigned __int8 *, _QWORD))dp_rx_pdev_mon_status_desc_pool_alloc)(a1, v3);
    if ( v74 )
    {
      v13 = v74;
      v14 = 1;
      goto LABEL_23;
    }
    v84 = *((_QWORD *)a1 + 1);
    v85 = *(_QWORD *)(v84 + 40);
    if ( *(_BYTE *)(v85 + 633) != 1 || (wlan_cfg_is_delay_mon_replenish(v85) & 1) == 0 )
      return 0;
    if ( v3 <= 2 )
    {
      v94 = *((_QWORD *)a1 + 1);
      v95 = *(_QWORD *)(v94 + 40);
      v96 = *(_DWORD *)(v94 + 80LL * v3 + 532);
      v97 = v94 + 120LL * v3;
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: Mon RX Desc Pool[%d] entries=%u",
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        "dp_rx_pdev_mon_buf_desc_pool_alloc",
        *a1,
        v96);
      v98 = wlan_cfg_get_dp_soc_rx_sw_desc_weight(v95);
      if ( (unsigned int)dp_rx_desc_pool_is_allocated(
                           (unsigned int *)(v97 + 11408),
                           v99,
                           v100,
                           v101,
                           v102,
                           v103,
                           v104,
                           v105,
                           v106) )
      {
        v115 = dp_rx_desc_pool_alloc(v94, v98 * v96, v97 + 11408, v107, v108, v109, v110, v111, v112, v113, v114);
        if ( v115 )
        {
          v13 = v115;
          v14 = 1;
          goto LABEL_34;
        }
      }
      result = ((__int64 (__fastcall *)(__int64, _QWORD))dp_hw_link_desc_pool_banks_alloc)(v84, v3);
      if ( !(_DWORD)result )
        return result;
      v13 = result;
      v14 = 1;
LABEL_39:
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: dp_hw_link_desc_pool_banks_alloc() failed",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "dp_rx_pdev_mon_dest_desc_pool_alloc");
      ((void (__fastcall *)(unsigned __int8 *, _QWORD))dp_rx_pdev_mon_status_desc_pool_free)(a1, v3);
      goto LABEL_40;
    }
LABEL_41:
    __break(0x5512u);
    JUMPOUT(0x5DF5B4);
  }
  v13 = v4;
  v14 = 0;
LABEL_23:
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: dp_rx_pdev_mon_status_desc_pool_alloc() failed",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "dp_rx_pdev_mon_cmn_desc_pool_alloc");
LABEL_24:
  qdf_trace_msg(
    0x85u,
    2u,
    "%s: %pK: %d failed",
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    v82,
    "dp_rx_pdev_mon_desc_pool_alloc",
    *((_QWORD *)a1 + 1),
    v14);
  if ( v14 )
    ((void (__fastcall *)(unsigned __int8 *, _QWORD))dp_rx_pdev_mon_cmn_desc_pool_free)(a1, 0);
  return v13;
}
