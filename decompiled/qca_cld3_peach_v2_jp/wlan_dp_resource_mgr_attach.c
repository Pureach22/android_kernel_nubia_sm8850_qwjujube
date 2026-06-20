__int64 __fastcall wlan_dp_resource_mgr_attach(__int64 *a1)
{
  __int64 v2; // x21
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x0
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  _DWORD *v23; // x8
  unsigned int v24; // w0
  __int64 v25; // x4
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  const char *v50; // x2
  const char *v51; // x2
  unsigned int v52; // w1
  const char *v53; // x2
  unsigned int v54; // w1
  __int64 result; // x0
  __int64 v56; // x0
  __int64 v57; // x8
  __int64 (*v58)(void); // x8
  unsigned int v59; // w0
  __int64 v60; // x4
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  _QWORD v77[3]; // [xsp+8h] [xbp-38h] BYREF
  char v78; // [xsp+20h] [xbp-20h]
  __int64 v79; // [xsp+21h] [xbp-1Fh]
  _BYTE v80[23]; // [xsp+29h] [xbp-17h]

  *(_QWORD *)&v80[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[30];
  v3 = *a1;
  memset(v77, 0, sizeof(v77));
  if ( (*(_BYTE *)(cfg_psoc_get_values(v3) + 4155) & 1) == 0 )
  {
    v51 = "%s: DP dynamic resourec mgmt cfg disabled";
    v52 = 5;
LABEL_22:
    result = qdf_trace_msg(0x45u, v52, v51, v4, v5, v6, v7, v8, v9, v10, v11, "wlan_dp_resource_mgr_attach");
    goto LABEL_23;
  }
  v12 = _qdf_mem_malloc(0xF0u, "wlan_dp_resource_mgr_attach", 1155);
  if ( !v12 )
  {
    v51 = "%s: Failed to create DP resource mgr context";
    v52 = 2;
    goto LABEL_22;
  }
  v13 = v12;
  qdf_mem_copy((void *)(v12 + 8), &dp_resource_map, 0x10u);
  if ( !v2 || !*(_QWORD *)v2 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v14, v15, v16, v17, v18, v19, v20, v21, "cdp_txrx_get_psoc_param");
LABEL_17:
    v25 = 16;
LABEL_18:
    v53 = "%s: Failed to fetch Refill ring config status:%u";
    v54 = 2;
LABEL_19:
    qdf_trace_msg(0x45u, v54, v53, v14, v15, v16, v17, v18, v19, v20, v21, "wlan_dp_resource_mgr_attach", v25);
    goto LABEL_20;
  }
  v22 = *(_QWORD *)(*(_QWORD *)v2 + 8LL);
  if ( !v22 )
    goto LABEL_17;
  v23 = *(_DWORD **)(v22 + 192);
  if ( !v23 )
    goto LABEL_17;
  if ( *(v23 - 1) != 875927212 )
    __break(0x8228u);
  v24 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))v23)(v2, 18, v77);
  v25 = v24;
  if ( v24 )
    goto LABEL_18;
  if ( SLODWORD(v77[0]) <= (unsigned __int16)word_696CE )
  {
    v53 = "%s: Unsupported RX buffers config:%u, disabling rsrc mgr";
    v54 = 5;
    v25 = LODWORD(v77[0]);
    goto LABEL_19;
  }
  if ( LODWORD(v77[0]) - 1 != (unsigned __int16)word_696D6 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Adjusting Resource lvl_2 rx buffers map_val:%u cfg_val:%u",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_dp_resource_mgr_attach");
    *(_WORD *)(v13 + 22) = LOWORD(v77[0]) - 1;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: DP resource level:%u MAX_TPUT:%u NUM_RX_BUF:%u",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wlan_dp_resource_mgr_attach",
    0,
    *(unsigned __int16 *)(v13 + 12),
    *(unsigned __int16 *)(v13 + 14));
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: DP resource level:%u MAX_TPUT:%u NUM_RX_BUF:%u",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wlan_dp_resource_mgr_attach",
    1,
    *(unsigned __int16 *)(v13 + 20),
    *(unsigned __int16 *)(v13 + 22));
  if ( (unsigned int)wlan_objmgr_register_peer_phymode_change_notify_handler(
                       0x2Eu,
                       (__int64)wlan_dp_resource_mgr_phymode_update,
                       v13,
                       v34,
                       v35,
                       v36,
                       v37,
                       v38,
                       v39,
                       v40,
                       v41) )
  {
    v50 = "%s: Failed to register for peer phymode change notif";
LABEL_37:
    qdf_trace_msg(0x45u, 2u, v50, v42, v43, v44, v45, v46, v47, v48, v49, "wlan_dp_resource_mgr_attach");
    goto LABEL_20;
  }
  v56 = a1[30];
  if ( !v56 || !*(_QWORD *)v56 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v42, v43, v44, v45, v46, v47, v48, v49, "cdp_txrx_set_psoc_param");
LABEL_34:
    v60 = 16;
    goto LABEL_35;
  }
  v57 = *(_QWORD *)(*(_QWORD *)v56 + 8LL);
  if ( !v57 )
    goto LABEL_34;
  v58 = *(__int64 (**)(void))(v57 + 184);
  if ( !v58 )
    goto LABEL_34;
  v79 = 0;
  v78 = 1;
  *(_QWORD *)v80 = 0;
  *(_QWORD *)&v80[7] = 0;
  if ( *((_DWORD *)v58 - 1) != -503247959 )
    __break(0x8228u);
  v59 = v58();
  v60 = v59;
  if ( !v59 )
  {
    *(_DWORD *)(v13 + 216) = 0;
    *(_QWORD *)(v13 + 224) = 0;
    wlan_dp_resource_mgr_list_attach(v13);
    *(_DWORD *)(v13 + 136) = 2;
    *(_QWORD *)(v13 + 184) = wlan_dp_resource_mgr_timer_handler;
    *(_QWORD *)(v13 + 192) = v13;
    init_timer_key(v13 + 144, _os_timer_shim_18, 0x80000, 0, 0);
    *(_QWORD *)v13 = a1;
    a1[375] = v13;
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: DP resource mgr attach done mac_count:%u",
               v61,
               v62,
               v63,
               v64,
               v65,
               v66,
               v67,
               v68,
               "wlan_dp_resource_mgr_attach",
               *(unsigned int *)(v13 + 136));
    goto LABEL_23;
  }
LABEL_35:
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Failed to set dynamic resource mgr support status %d",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    "wlan_dp_resource_mgr_attach",
    v60);
  if ( (unsigned int)wlan_objmgr_unregister_peer_phymode_change_notify_handler(
                       0x2Eu,
                       (__int64)wlan_dp_resource_mgr_phymode_update,
                       v69,
                       v70,
                       v71,
                       v72,
                       v73,
                       v74,
                       v75,
                       v76) )
  {
    v50 = "%s: Failed to unregister peer phymode notification handler";
    goto LABEL_37;
  }
LABEL_20:
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: DP resource mgr attach failure",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    "wlan_dp_resource_mgr_attach");
  result = _qdf_mem_free(v13);
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
