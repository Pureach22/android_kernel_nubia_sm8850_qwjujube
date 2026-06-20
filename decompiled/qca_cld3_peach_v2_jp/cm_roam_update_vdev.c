__int64 __fastcall cm_roam_update_vdev(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *context; // x0
  unsigned int v13; // w19
  __int64 *v14; // x22
  void *v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int16 v24; // w9
  __int64 v25; // x23
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 vdev_bssid; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  void *v60; // x24
  unsigned int v61; // w0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned int v70; // w25
  __int64 v72; // x8
  __int64 v73; // x0
  unsigned int param; // w25
  unsigned int v75; // w0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // [xsp+0h] [xbp-10h] BYREF
  __int64 v101; // [xsp+8h] [xbp-8h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"cm_roam_update_vdev", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v70 = 4;
    goto LABEL_13;
  }
  v13 = *(unsigned __int8 *)(a1 + 104);
  v14 = context;
  *(_BYTE *)(context[65] + 488LL * *(unsigned __int8 *)(a1 + 104) + 236) = *(_BYTE *)(a2 + 392);
  *(_DWORD *)(context[65] + 488LL * v13 + 180) = *(_DWORD *)(a2 + 280);
  *(_DWORD *)(context[65] + 488LL * v13 + 436) = *(_DWORD *)(a2 + 64);
  v15 = (void *)_qdf_mem_malloc(0x110u, "wma_roam_update_vdev", 721);
  if ( !v15 )
  {
LABEL_11:
    v70 = 4;
    goto LABEL_12;
  }
  v24 = *(_WORD *)(a2 + 18);
  v25 = (__int64)v15;
  LODWORD(v100) = *(_DWORD *)(a2 + 14);
  WORD2(v100) = v24;
  qdf_mem_set(v15, 0x110u, 0);
  v26 = _qdf_mem_malloc(0x14u, "wma_delete_bss_peer", 583);
  if ( !v26 )
  {
    v70 = 2;
    goto LABEL_9;
  }
  *(_BYTE *)(v26 + 10) = v13;
  wma_delete_sta((__int64)v14, v26, v27, v28, v29, v30, v31, v32, v33, v34);
  wma_delete_bss(v14, v13, v35, v36, v37, v38, v39, v40, v41, v42);
  *(_BYTE *)(v25 + 8) = 0;
  *(_BYTE *)(v25 + 131) = v13;
  qdf_mem_copy((void *)v25, &v100, 6u);
  *(_WORD *)(v25 + 6) = *(_WORD *)(a2 + 304);
  vdev_bssid = wma_get_vdev_bssid(*(_QWORD *)(v14[65] + 488LL * v13), v43, v44, v45, v46, v47, v48, v49, v50);
  if ( !vdev_bssid )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to get bssid for vdev_%d",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "wma_roam_update_vdev",
      v13);
    goto LABEL_11;
  }
  v60 = (void *)vdev_bssid;
  v61 = wma_create_peer((__int64)v14, &v100, 0, 0, v13, 0, 0, v52, v53, v54, v55, v56, v57, v58, v59);
  if ( v61 )
  {
    v70 = v61;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to create peer %02x:%02x:%02x:**:**:%02x",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "wma_roam_update_vdev",
      (unsigned __int8)v100,
      BYTE1(v100),
      BYTE2(v100),
      BYTE5(v100));
LABEL_9:
    _qdf_mem_free(v25);
LABEL_12:
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: VDEV update failed for roam on %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "cm_roam_update_vdev",
      v13,
      v100,
      v101);
    goto LABEL_13;
  }
  v72 = v14[65];
  v73 = *(_QWORD *)(v72 + 488LL * v13);
  if ( !*(_DWORD *)(v73 + 16) )
  {
    wlan_cdp_set_peer_freq(v14[3], &v100, *(unsigned int *)(v72 + 488LL * v13 + 436), v13);
    v73 = *(_QWORD *)(v14[65] + 488LL * v13);
  }
  param = wlan_crypto_get_param(v73, 1u);
  v75 = wlan_crypto_get_param(*(_QWORD *)(v14[65] + 488LL * v13), 4u);
  wma_set_peer_ucast_cipher((unsigned __int8 *)&v100, param, v75, v76, v77, v78, v79, v80, v81, v82, v83);
  wma_add_bss_lfr3((__int64)v14, *(unsigned __int8 **)(a2 + 272), v84, v85, v86, v87, v88, v89, v90, v91);
  wma_add_sta(v14, (unsigned __int8 *)v25, v92, v93, v94, v95, v96, v97, v98, v99);
  qdf_mem_copy(v60, &v100, 6u);
  lim_fill_roamed_peer_twt_caps(v14[2], v13, a2);
  _qdf_mem_free(v25);
  wlan_dp_update_def_link(v14[3], (unsigned __int8 *)(a1 + 74), a1);
  v70 = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v70;
}
