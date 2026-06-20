__int64 __fastcall wlan_serialization_pdev_create_handler(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  unsigned int v4; // w24
  __int64 v5; // x25
  _QWORD *v6; // x0
  _QWORD *v7; // x23
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  bool v16; // cf
  __int64 v17; // x22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w26
  _QWORD *v27; // x0
  _QWORD *v28; // x24
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w21
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7

  v2 = _qdf_mem_malloc(0xD0u, "wlan_serialization_pdev_create_handler", 242);
  if ( v2 )
  {
    v3 = v2;
    wlan_serialization_create_lock(v2 + 88);
    *(_QWORD *)v3 = v3;
    v4 = 0;
    *(_QWORD *)(v3 + 8) = v3;
    *(_QWORD *)(v3 + 16) = 0x800000000LL;
    *(_QWORD *)(v3 + 24) = v3 + 24;
    v5 = 1;
    *(_QWORD *)(v3 + 32) = v3 + 24;
    *(_QWORD *)(v3 + 40) = 0x1800000000LL;
    *(_QWORD *)(v3 + 48) = v3 + 48;
    *(_QWORD *)(v3 + 56) = v3 + 48;
    *(_QWORD *)(v3 + 64) = 0x2000000000LL;
    do
    {
      v6 = (_QWORD *)_qdf_mem_malloc(0x58u, "wlan_serialization_create_cmd_pool", 193);
      if ( !v6 )
      {
        v17 = v3;
        goto LABEL_14;
      }
      v7 = v6;
      qdf_mem_set(v6, 0x58u, 0);
      qdf_list_insert_back((_QWORD *)(v3 + 48), v7);
      v16 = v4++ >= 0x1F;
      v7[10] = 0;
    }
    while ( !v16 );
    qdf_trace_msg(
      0x4Cu,
      8u,
      "%s: Create cmd pool list %pK, size %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlan_serialization_create_cmd_pool",
      v3 + 48,
      *(unsigned int *)(v3 + 64));
    qdf_mem_set((void *)(v3 + 72), 8u, 0);
    *(_BYTE *)(v3 + 80) = 0;
    v17 = v3 + 104;
    *(_WORD *)(v3 + 82) = 0;
    wlan_serialization_create_lock(v3 + 192);
    qdf_trace_msg(
      0x4Cu,
      8u,
      "%s: max_active_cmds %d max_pending_cmds %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_serialization_pdev_create_handler",
      6,
      104);
    *(_QWORD *)(v3 + 104) = v3 + 104;
    v26 = 0;
    *(_QWORD *)(v3 + 112) = v3 + 104;
    v5 = 2;
    *(_QWORD *)(v3 + 120) = 0x600000000LL;
    *(_QWORD *)(v3 + 128) = v3 + 128;
    *(_QWORD *)(v3 + 136) = v3 + 128;
    *(_QWORD *)(v3 + 144) = 0x6800000000LL;
    *(_QWORD *)(v3 + 152) = v3 + 152;
    *(_QWORD *)(v3 + 160) = v3 + 152;
    *(_QWORD *)(v3 + 168) = 0x6E00000000LL;
    while ( 1 )
    {
      v27 = (_QWORD *)_qdf_mem_malloc(0x58u, "wlan_serialization_create_cmd_pool", 193);
      if ( !v27 )
        break;
      v28 = v27;
      qdf_mem_set(v27, 0x58u, 0);
      qdf_list_insert_back((_QWORD *)(v3 + 152), v28);
      v16 = v26++ >= 0x6D;
      v28[10] = 0;
      if ( v16 )
      {
        qdf_trace_msg(
          0x4Cu,
          8u,
          "%s: Create cmd pool list %pK, size %d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "wlan_serialization_create_cmd_pool",
          v3 + 152,
          *(unsigned int *)(v3 + 168));
        qdf_mem_set((void *)(v3 + 176), 8u, 0);
        *(_BYTE *)(v3 + 184) = 0;
        *(_WORD *)(v3 + 186) = 0;
        v45 = wlan_objmgr_pdev_component_obj_attach(a1, 2u, v3, 0, v37, v38, v39, v40, v41, v42, v43, v44);
        if ( v45 )
        {
          qdf_trace_msg(
            0x4Cu,
            2u,
            "%s: Pdev obj attach failed, status %d",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "wlan_serialization_pdev_create_handler",
            v45);
          v5 = 3;
          goto LABEL_15;
        }
        wlan_minidump_log(v3, 208, *(_QWORD *)(a1 + 80), 55, "wlan_ser_pdev_obj");
        return v45;
      }
    }
LABEL_14:
    wlan_serialization_destroy_cmd_pool(v17);
    v45 = 2;
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: Create cmd pool failed, status %d",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "wlan_serialization_pdev_create_handler",
      2);
LABEL_15:
    wlan_serialization_destroy_cmd_pool(v3);
    if ( *(_DWORD *)(v3 + 40) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "qdf_list_destroy");
    if ( *(_DWORD *)(v3 + 16) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "qdf_list_destroy");
    wlan_serialization_destroy_lock(v3 + 88);
    if ( v5 != 1 )
    {
      wlan_serialization_destroy_cmd_pool(v3 + 104);
      if ( *(_DWORD *)(v3 + 144) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          "qdf_list_destroy");
      if ( *(_DWORD *)(v3 + 120) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          "qdf_list_destroy");
      wlan_serialization_destroy_lock(v3 + 192);
      if ( v5 != 2 )
      {
        wlan_serialization_destroy_cmd_pool(v3 + 208);
        if ( *(_DWORD *)(v3 + 248) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: list length not equal to zero",
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            "qdf_list_destroy");
        if ( *(_DWORD *)(v3 + 224) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: list length not equal to zero",
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            "qdf_list_destroy");
        wlan_serialization_destroy_lock(v3 + 296);
      }
    }
  }
  else
  {
    return 2;
  }
  return v45;
}
