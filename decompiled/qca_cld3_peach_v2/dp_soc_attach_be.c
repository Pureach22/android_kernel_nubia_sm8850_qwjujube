__int64 __fastcall dp_soc_attach_be(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int64 v22; // x4
  unsigned __int64 v23; // x20
  unsigned int v24; // w20
  __int64 v25; // x8
  double num_tx_desc; // d0
  int v27; // w0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  int v36; // w0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  int v45; // w0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  int v54; // w0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  int v63; // w0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  int v72; // w0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double dp_soc_rx_sw_desc_num; // d0
  int v82; // w0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  int v91; // w0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  int v100; // w0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  int v109; // w0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7

  v2 = _qdf_mem_malloc(0x6000u, "dp_soc_attach_be", 1513);
  *(_QWORD *)(a1 + 22608) = v2;
  if ( v2 )
  {
    v11 = *(_QWORD *)(a1 + 20072);
    v12 = *(_QWORD *)(a1 + 20080);
    v13 = *(_QWORD *)(a1 + 20088);
    *(_DWORD *)(a1 + 20060) = 5;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: cmem base 0x%llx, total size 0x%llx avail_size 0x%llx",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dp_get_cmem_chunk",
      v11,
      v12,
      v13);
    v22 = *(_QWORD *)(a1 + 20088);
    if ( v22 > 0xFFF )
    {
      v23 = *(_QWORD *)(a1 + 20080) - v22 + *(_QWORD *)(a1 + 20072);
      *(_QWORD *)(a1 + 20088) = v22 - 4096;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Reserved cmem space 0x%llx, size 0x%llx for client %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "dp_get_cmem_chunk",
        v23,
        4096,
        0);
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: cmem_size 0x%llx bytes < requested size 0x%llx bytes",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "dp_get_cmem_chunk");
      LODWORD(v23) = 0;
    }
    v25 = *(_QWORD *)a1;
    *(_DWORD *)(a1 + 22616) = v23;
    *(_QWORD *)(v25 + 176) = dp_cmn_mlo_ops;
    num_tx_desc = wlan_cfg_get_num_tx_desc(*(_QWORD *)(a1 + 40), 0);
    if ( (unsigned int)dp_hw_cookie_conversion_attach(
                         a1,
                         a1 + 22624,
                         v27,
                         0,
                         0,
                         num_tx_desc,
                         v28,
                         v29,
                         v30,
                         v31,
                         v32,
                         v33,
                         v34)
      || (v35 = wlan_cfg_get_num_tx_desc(*(_QWORD *)(a1 + 40), 1),
          (unsigned int)dp_hw_cookie_conversion_attach(
                          a1,
                          a1 + 22704,
                          v36,
                          0,
                          1u,
                          v35,
                          v37,
                          v38,
                          v39,
                          v40,
                          v41,
                          v42,
                          v43))
      || (v44 = wlan_cfg_get_num_tx_desc(*(_QWORD *)(a1 + 40), 2),
          (unsigned int)dp_hw_cookie_conversion_attach(
                          a1,
                          a1 + 22784,
                          v45,
                          0,
                          2u,
                          v44,
                          v46,
                          v47,
                          v48,
                          v49,
                          v50,
                          v51,
                          v52))
      || (v53 = wlan_cfg_get_num_tx_desc(*(_QWORD *)(a1 + 40), 3),
          (unsigned int)dp_hw_cookie_conversion_attach(
                          a1,
                          a1 + 22864,
                          v54,
                          0,
                          3u,
                          v53,
                          v55,
                          v56,
                          v57,
                          v58,
                          v59,
                          v60,
                          v61))
      || (v62 = wlan_cfg_get_num_tx_desc(*(_QWORD *)(a1 + 40), 4),
          (unsigned int)dp_hw_cookie_conversion_attach(
                          a1,
                          a1 + 22944,
                          v63,
                          0,
                          4u,
                          v62,
                          v64,
                          v65,
                          v66,
                          v67,
                          v68,
                          v69,
                          v70))
      || (v71 = wlan_cfg_get_num_tx_desc(*(_QWORD *)(a1 + 40), 5),
          (unsigned int)dp_hw_cookie_conversion_attach(
                          a1,
                          a1 + 23024,
                          v72,
                          0,
                          5u,
                          v71,
                          v73,
                          v74,
                          v75,
                          v76,
                          v77,
                          v78,
                          v79)) )
    {
      v24 = 16;
LABEL_13:
      dp_soc_detach_be(a1);
      return v24;
    }
    dp_soc_rx_sw_desc_num = wlan_cfg_get_dp_soc_rx_sw_desc_num(*(_QWORD *)(a1 + 40));
    v24 = dp_hw_cookie_conversion_attach(
            a1,
            a1 + 23104,
            v82,
            7,
            0,
            dp_soc_rx_sw_desc_num,
            v83,
            v84,
            v85,
            v86,
            v87,
            v88,
            v89);
    if ( v24 )
      goto LABEL_13;
    v90 = wlan_cfg_get_dp_soc_rx_sw_desc_num(*(_QWORD *)(a1 + 40));
    v24 = dp_hw_cookie_conversion_attach(a1, a1 + 23184, v91, 7, 1u, v90, v92, v93, v94, v95, v96, v97, v98);
    if ( v24 )
      goto LABEL_13;
    v99 = wlan_cfg_get_dp_soc_rx_sw_desc_num(*(_QWORD *)(a1 + 40));
    v24 = dp_hw_cookie_conversion_attach(a1, a1 + 23264, v100, 7, 2u, v99, v101, v102, v103, v104, v105, v106, v107);
    if ( v24 )
      goto LABEL_13;
    v108 = wlan_cfg_get_dp_soc_rx_sw_desc_num(*(_QWORD *)(a1 + 40));
    v24 = dp_hw_cookie_conversion_attach(a1, a1 + 23344, v109, 7, 3u, v108, v110, v111, v112, v113, v114, v115, v116);
    if ( v24 )
      goto LABEL_13;
  }
  else
  {
    v24 = 2;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: spt page descs allocation failed",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dp_soc_attach_be");
  }
  return v24;
}
