__int64 __fastcall dp_pdev_attach_wifi3(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v4)(_QWORD); // x8
  int v5; // w28
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  size_t v15; // x22
  _DWORD *v16; // x8
  __int64 v17; // x20
  __int64 v18; // x22
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x0
  char v29; // w8
  char dp_soc_nss_cfg; // w0
  __int64 v31; // x22
  __int64 v32; // x23
  unsigned int dp_soc_rxdma_refill_ring_size; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v42; // x2
  unsigned __int8 *v43; // x23
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w0
  __int64 v61; // x0
  unsigned int v62; // w25
  __int64 v63; // x26
  __int64 v64; // x0
  unsigned int v65; // w27
  int v66; // w24
  unsigned int v67; // w8
  __int64 v68; // x1
  __int64 v69; // x23
  int num_mac_rings; // w22
  unsigned int rx_dma_buf_ring_size; // w0
  unsigned int v72; // w23
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x8
  _DWORD *v98; // x8
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int64 result; // x0
  __int64 v108; // x8
  __int64 v109; // x8
  unsigned int (__fastcall *v110)(_QWORD); // x8
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  void (__fastcall *v119)(__int64, __int64); // x8
  unsigned int dp_soc_rxdma_err_dst_ring_size; // [xsp+Ch] [xbp-44h]
  char s[8]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v122; // [xsp+18h] [xbp-38h]
  __int64 v123; // [xsp+20h] [xbp-30h]
  __int64 v124; // [xsp+28h] [xbp-28h]
  __int64 v125; // [xsp+30h] [xbp-20h]
  __int64 v126; // [xsp+38h] [xbp-18h]
  __int16 v127; // [xsp+40h] [xbp-10h]
  __int64 v128; // [xsp+48h] [xbp-8h]

  v128 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1464);
  v5 = *(unsigned __int8 *)(a2 + 16);
  if ( *((_DWORD *)v4 - 1) != -1391804861 )
    __break(0x8228u);
  v6 = v4(1);
  if ( !v6 )
    goto LABEL_20;
  v15 = v6;
  v16 = *(_DWORD **)(*(_QWORD *)(a1 + 8) + 216LL);
  if ( !v16 )
  {
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: dp_prealloc_get_context null!",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_context_alloc_mem");
    goto LABEL_10;
  }
  if ( *(v16 - 1) != 1912555561 )
    __break(0x8228u);
  v17 = ((__int64 (__fastcall *)(_QWORD, __int64))v16)(0, v6);
  if ( !v17 )
  {
LABEL_10:
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: switch to dynamic-alloc for type %d, size %zu",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_context_alloc_mem",
      0,
      v15);
    v17 = _qdf_mem_malloc(v15, "dp_context_alloc_mem", 1438);
    if ( v17 )
      goto LABEL_11;
LABEL_20:
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: DP PDEV memory allocation failed",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_pdev_attach_wifi3",
      a1);
    goto LABEL_63;
  }
LABEL_11:
  wlan_minidump_log(v7, v8, v9, v10, v11, v12, v13, v14, v17, 96536, *(_QWORD *)(a1 + 16));
  v18 = *(_QWORD *)(a1 + 40);
  v19 = wlan_cfg_pdev_attach(*(_QWORD *)(a1 + 16));
  *(_QWORD *)(v17 + 288) = v19;
  if ( !v19 )
  {
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: pdev cfg_attach failed",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "dp_pdev_attach_wifi3",
      a1);
    goto LABEL_55;
  }
  *(_QWORD *)(v17 + 8) = a1;
  *(_BYTE *)v17 = v5;
  if ( v5 )
    goto LABEL_80;
  v28 = *(_QWORD *)(a1 + 40);
  *(_QWORD *)(a1 + 72) = v17;
  *(_BYTE *)(v17 + 1) = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_cfg_get_hw_mac_idx)(v28, 0);
  v29 = *(_BYTE *)(a1 + 1120) + 1;
  v127 = 0;
  v125 = 0;
  v126 = 0;
  *(_BYTE *)(a1 + 1120) = v29;
  v123 = 0;
  v124 = 0;
  *(_QWORD *)s = 0;
  v122 = 0;
  snprintf(s, 0x32u, "%s%s%d", "dp_pdev", "_", 0);
  ((void (__fastcall *)(char *, __int64, __int64))qdf_ssr_driver_dump_register_region)(s, v17, 96536);
  dp_soc_nss_cfg = wlan_cfg_get_dp_soc_nss_cfg(v18);
  wlan_cfg_set_dp_pdev_nss_enabled(*(_QWORD *)(v17 + 288), dp_soc_nss_cfg & 1);
  v31 = *(_QWORD *)(v17 + 8);
  v32 = *(_QWORD *)(v31 + 40);
  dp_soc_rxdma_refill_ring_size = wlan_cfg_get_dp_soc_rxdma_refill_ring_size(v32);
  if ( *(_BYTE *)(v31 + 20276) == 1 )
    dp_soc_rxdma_refill_ring_size = wlan_cfg_get_dp_soc_rxdma_scan_radio_refill_ring_size(v32);
  if ( (*(_BYTE *)(v31 + 20096) & 2) == 0 )
  {
    if ( *(unsigned __int8 *)(v17 + 1) >= 2uLL )
      goto LABEL_80;
    if ( (unsigned int)dp_srng_alloc(
                         (_QWORD *)v31,
                         v31 + 80LL * *(unsigned __int8 *)(v17 + 1) + 80,
                         0xEu,
                         dp_soc_rxdma_refill_ring_size,
                         0) )
    {
      v42 = "%s: %pK: dp_srng_alloc failed rx refill ring";
      v43 = (unsigned __int8 *)v17;
      goto LABEL_19;
    }
  }
  dp_soc_rxdma_err_dst_ring_size = wlan_cfg_get_dp_soc_rxdma_err_dst_ring_size(v32);
  v60 = wlan_cfg_per_pdev_lmac_ring(v32);
  v43 = (unsigned __int8 *)v17;
  if ( v60 )
  {
    if ( (*(_BYTE *)(v31 + 20120) & 1) != 0 )
      goto LABEL_45;
  }
  else
  {
    v43 = *(unsigned __int8 **)(v31 + 72);
    if ( (*(_BYTE *)(v31 + 20120) & 1) != 0 )
      goto LABEL_45;
  }
  v61 = *(_QWORD *)(v31 + 40);
  if ( *(_BYTE *)(v61 + 804) )
  {
    v62 = *v43;
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(v61) )
    {
      if ( v62 )
        goto LABEL_80;
      v62 = *(unsigned __int8 *)(*(_QWORD *)(v31 + 72) + 1LL);
    }
    if ( v62 > 2 )
      goto LABEL_80;
    v63 = v31 + 320;
    if ( !*(_QWORD *)(v31 + 320 + 80LL * v62 + 8)
      && (unsigned int)dp_srng_alloc((_QWORD *)v31, v63 + 80LL * v62, 0xFu, dp_soc_rxdma_err_dst_ring_size, 0) )
    {
LABEL_75:
      v42 = "%s: %pK:SRNG setup failed forrxdma_err_dst_ring";
LABEL_19:
      qdf_trace_msg(0x7Cu, 2u, v42, v34, v35, v36, v37, v38, v39, v40, v41, "dp_pdev_srng_alloc", v31);
      dp_pdev_srng_free(v43);
      qdf_trace_msg(
        0x7Cu,
        2u,
        "%s: %pK: dp_pdev_srng_alloc failed",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "dp_pdev_attach_wifi3",
        a1);
      while ( 1 )
      {
        wlan_minidump_remove(v52, v53, v54, v55, v56, v57, v58, v59, *(_QWORD *)(v17 + 288), 40, *(_QWORD *)(a1 + 16));
        wlan_cfg_pdev_detach(*(_QWORD *)(v17 + 288));
LABEL_55:
        if ( !v5 )
          break;
LABEL_80:
        __break(0x5512u);
LABEL_81:
        qdf_trace_msg(
          0x92u,
          8u,
          "%s: callback not registered",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_monitor_pdev_attach");
LABEL_82:
        qdf_trace_msg(
          0x7Cu,
          2u,
          "%s: %pK: dp_monitor_pdev_attach failed",
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          v117,
          v118,
          "dp_pdev_attach_wifi3",
          a1);
        dp_rx_pdev_desc_pool_free(v17);
        if ( !*(_BYTE *)v17 )
        {
LABEL_52:
          dp_srng_free(*(_QWORD *)(v17 + 8), v17 + 112, v81, v82, v83, v84, v85, v86, v87, v88);
          dp_srng_free(*(_QWORD *)(v17 + 8), v17 + 192, v89, v90, v91, v92, v93, v94, v95, v96);
        }
LABEL_53:
        v52 = dp_pdev_srng_free(v17);
      }
      v97 = *(_QWORD *)(a1 + 8);
      *(_QWORD *)(a1 + 72) = 0;
      v98 = *(_DWORD **)(v97 + 224);
      if ( v98 )
      {
        if ( *(v98 - 1) != -754103808 )
          __break(0x8228u);
        if ( !((unsigned int (__fastcall *)(_QWORD, __int64))v98)(0, v17) )
          goto LABEL_63;
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          3u,
          "%s: dp_prealloc_put_context null!",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_context_free_mem");
      }
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Context type %d not pre-allocated",
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        "dp_context_free_mem",
        0);
      _qdf_mem_free(v17);
LABEL_63:
      result = 16;
      goto LABEL_64;
    }
    v64 = *(_QWORD *)(v31 + 40);
    if ( *(unsigned __int8 *)(v64 + 804) >= 2u )
    {
      v65 = 1;
      do
      {
        v66 = *v43;
        if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(v64) )
        {
          if ( v66 )
            goto LABEL_80;
          v67 = *(unsigned __int8 *)(*(_QWORD *)(v31 + 72) + 1LL);
          if ( v67 > 2 )
            goto LABEL_80;
        }
        else if ( v66 )
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
          v67 = 0;
        }
        else
        {
          v67 = v65;
          if ( v65 > 2 )
            goto LABEL_80;
        }
        v68 = v63 + 80LL * v67;
        if ( !*(_QWORD *)(v68 + 8) )
        {
          if ( (unsigned int)dp_srng_alloc((_QWORD *)v31, v68, 0xFu, dp_soc_rxdma_err_dst_ring_size, 0) )
            goto LABEL_75;
        }
        v64 = *(_QWORD *)(v31 + 40);
      }
      while ( ++v65 < *(unsigned __int8 *)(v64 + 804) );
    }
  }
LABEL_45:
  v69 = *(_QWORD *)(v17 + 288);
  num_mac_rings = wlan_cfg_get_num_mac_rings(v69);
  rx_dma_buf_ring_size = wlan_cfg_get_rx_dma_buf_ring_size(v69);
  if ( !*(_BYTE *)v17 && num_mac_rings >= 1 )
  {
    v72 = rx_dma_buf_ring_size;
    if ( (unsigned int)dp_srng_alloc((_QWORD *)a1, v17 + 112, 0xEu, rx_dma_buf_ring_size, 0) )
    {
LABEL_48:
      qdf_trace_msg(
        0x7Cu,
        2u,
        "%s: %pK: failed rx mac ring setup",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "dp_rxdma_ring_alloc",
        a1);
      qdf_trace_msg(
        0x7Cu,
        2u,
        "%s: %pK: dp_rxdma_ring_alloc failed",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        "dp_pdev_attach_wifi3",
        a1);
      goto LABEL_53;
    }
    if ( num_mac_rings != 1 )
    {
      if ( (unsigned int)dp_srng_alloc((_QWORD *)a1, v17 + 192, 0xEu, v72, 0) )
        goto LABEL_48;
      if ( num_mac_rings != 2 )
      {
        if ( (unsigned int)dp_srng_alloc((_QWORD *)a1, v17 + 272, 0xEu, v72, 0) )
          goto LABEL_48;
        if ( num_mac_rings != 3 )
          goto LABEL_80;
      }
    }
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64))dp_rx_pdev_desc_pool_alloc)(v17) )
  {
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: dp_rx_pdev_attach failed",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "dp_pdev_attach_wifi3",
      a1);
    if ( *(_BYTE *)v17 )
      goto LABEL_53;
    goto LABEL_52;
  }
  v108 = *(_QWORD *)(*(_QWORD *)(v17 + 8) + 20112LL);
  if ( v108 )
  {
    v109 = *(_QWORD *)(v108 + 416);
    if ( !v109 )
      goto LABEL_81;
    v110 = *(unsigned int (__fastcall **)(_QWORD))(v109 + 88);
    if ( !v110 )
      goto LABEL_81;
    if ( *((_DWORD *)v110 - 1) != -1116635294 )
      __break(0x8228u);
    if ( v110(v17) )
      goto LABEL_82;
  }
  v119 = *(void (__fastcall **)(__int64, __int64))(a1 + 1208);
  if ( *((_DWORD *)v119 - 1) != -340389300 )
    __break(0x8228u);
  v119(v17, a2);
  result = 0;
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return result;
}
