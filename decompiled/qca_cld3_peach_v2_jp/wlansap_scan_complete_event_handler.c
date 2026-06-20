__int64 __fastcall wlansap_scan_complete_event_handler(
        __int64 result,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x21
  _BYTE *v14; // x8
  __int64 v15; // x23
  _QWORD *vdev_by_id_from_pdev; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x20
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _QWORD *scan_result; // x21
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  char v44; // w9
  __int64 v45; // x0
  const void *v46; // x1
  __int64 v47; // x22
  size_t v48; // x2
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  _WORD v73[2]; // [xsp+4h] [xbp-2Ch] BYREF
  int v74[2]; // [xsp+8h] [xbp-28h] BYREF
  unsigned int *v75[2]; // [xsp+10h] [xbp-20h] BYREF
  _BYTE v76[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v77; // [xsp+28h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v76[0] = 0;
  v75[0] = nullptr;
  v75[1] = nullptr;
  *(_QWORD *)v74 = 0;
  v73[0] = 0;
  if ( !result )
    goto LABEL_23;
  if ( !a2 )
    goto LABEL_23;
  if ( !a3 )
    goto LABEL_23;
  v13 = result;
  result = (__int64)_cds_get_context(
                      52,
                      (__int64)"wlansap_scan_complete_event_handler",
                      a4,
                      a5,
                      a6,
                      a7,
                      a8,
                      a9,
                      a10,
                      a11);
  if ( !result )
    goto LABEL_23;
  if ( *(_DWORD *)(v13 + 16) )
    goto LABEL_23;
  if ( *(_DWORD *)(a3 + 728) != 2 )
    goto LABEL_23;
  v14 = *(_BYTE **)(a3 + 1536);
  if ( !v14 )
    goto LABEL_23;
  if ( !*v14 )
    goto LABEL_23;
  v15 = result;
  result = util_is_scan_completed(a2, v76);
  if ( (result & 1) == 0 )
    goto LABEL_23;
  if ( v76[0] != 1 )
    goto LABEL_23;
  result = wlansap_is_all_2ghz_channel_scanned(a2);
  if ( (result & 1) == 0 )
    goto LABEL_23;
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(v15 + 21560), *(_BYTE *)(a3 + 12), 0x2Cu);
  if ( vdev_by_id_from_pdev )
  {
    v25 = (__int64)vdev_by_id_from_pdev;
    if ( *(_QWORD *)(a3 + 1488) )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: SAP ACS is in progress let's not override vdev id %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlansap_scan_complete_event_handler",
        *(unsigned __int8 *)(a3 + 12));
LABEL_15:
      scan_result = nullptr;
      goto LABEL_16;
    }
    sap_get_freq_list(a3, (__int64 *)v74, v73, v17, v18, v19, v20, v21, v22, v23, v24);
    v26 = (unsigned int *)v73[0];
    scan_result = nullptr;
    if ( v73[0] && *(_QWORD *)v74 )
    {
      wlansap_filter_non_2ghz_freq(*(_QWORD *)v74, v73);
      v44 = v73[0];
      *(_QWORD *)(a3 + 1488) = *(_QWORD *)v74;
      *(_BYTE *)(a3 + 1496) = v44;
      v45 = _qdf_mem_malloc(0x2D0u, "wlansap_scan_complete_event_handler", 480);
      if ( !v45 )
        goto LABEL_15;
      v46 = *(const void **)v74;
      v47 = v45;
      v48 = 4 * (unsigned int)v73[0];
      *(_WORD *)(v45 + 18) = v73[0];
      qdf_mem_copy((void *)(v45 + 268), v46, v48);
      scan_result = scm_get_scan_result(*(_QWORD *)(v15 + 21560), v47, v49, v50, v51, v52, v53, v54, v55, v56);
      _qdf_mem_free(v47);
      if ( scan_result )
      {
        v26 = (unsigned int *)*((unsigned int *)scan_result + 4);
        if ( (_DWORD)v26 )
        {
          if ( !(unsigned int)wlansap_sort_channel_list(*(unsigned __int8 *)(a3 + 12), scan_result, v75, 1) )
          {
            wlan_set_sap_best_channel_2ghz(v25, v75, v57, v58, v59, v60, v61, v62, v63, v64);
            scm_purge_scan_results((__int64)scan_result, v65, v66, v67, v68, v69, v70, v71, v72);
            goto LABEL_15;
          }
          qdf_trace_msg(
            0x39u,
            2u,
            "%s: error vdev %d failed to sort sap channel list",
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            "wlansap_scan_complete_event_handler",
            *(unsigned __int8 *)(a3 + 12));
        }
      }
    }
LABEL_16:
    wlan_objmgr_vdev_release_ref(v25, 0x2Cu, v26, v27, v28, v29, v30, v31, v32, v33, v34);
    if ( v75[0] )
      _qdf_mem_free((__int64)v75[0]);
    goto LABEL_19;
  }
  qdf_trace_msg(
    0x39u,
    2u,
    "%s: Unable to get vdev ref vdev_id:%d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "wlansap_scan_complete_event_handler",
    *(unsigned __int8 *)(a3 + 12));
  scan_result = nullptr;
LABEL_19:
  result = *(_QWORD *)(a3 + 1488);
  if ( result )
  {
    result = _qdf_mem_free(result);
    *(_QWORD *)(a3 + 1488) = 0;
    *(_BYTE *)(a3 + 1496) = 0;
  }
  if ( scan_result )
    result = scm_purge_scan_results((__int64)scan_result, v36, v37, v38, v39, v40, v41, v42, v43);
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
