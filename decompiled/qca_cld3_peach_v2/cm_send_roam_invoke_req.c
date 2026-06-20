__int64 __fastcall cm_send_roam_invoke_req(
        __int64 *a1,
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
  __int64 v10; // x8
  unsigned int v11; // w20
  unsigned int v13; // w21
  __int64 v14; // x24
  __int64 v15; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w20
  const char *v34; // x2
  __int64 v35; // x22
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  int v69; // w8
  __int64 v70; // x0
  int *v71; // x25
  int v73; // w9
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  int v90; // w9
  __int64 v91; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v92[3]; // [xsp+8h] [xbp-18h] BYREF

  v92[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOBYTE(v91) = 0;
  if ( !a2 )
  {
    v33 = 16;
    goto LABEL_17;
  }
  v10 = *a1;
  v11 = *(_DWORD *)(a2 + 16);
  v13 = *(unsigned __int8 *)(a2 + 33);
  WORD2(v92[0]) = 0;
  v14 = *(_QWORD *)(v10 + 216);
  HIDWORD(v91) = v11;
  LODWORD(v92[0]) = 0;
  if ( !v14 )
  {
    v34 = "%s: vdev %d cm_id 0x%x: Failed to find pdev";
LABEL_9:
    qdf_trace_msg(0x68u, 2u, v34, a3, a4, a5, a6, a7, a8, a9, a10, "cm_send_roam_invoke_req", v13, v11, v91, v92[0]);
    goto LABEL_10;
  }
  v15 = *(_QWORD *)(v14 + 80);
  if ( !v15 )
  {
    v34 = "%s: vdev %d cm_id 0x%x: Failed to find psoc";
    goto LABEL_9;
  }
  if ( (wlan_vdev_mlme_get_is_mlo_link(*(_QWORD *)(v14 + 80), v13) & 1) != 0 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: MLO ROAM: skip RSO cmd for link vdev %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "cm_send_roam_invoke_req",
      v13);
  }
  else
  {
    wlan_vdev_get_bss_peer_mac(*a1, v92, v17, v18, v19, v20, v21, v22, v23, v24);
    wlan_mlme_get_self_bss_roam(v15, &v91);
    if ( (_BYTE)v91 || !cm_is_bssid_present_on_any_assoc_link(*a1, a2 + 40, v53, v54, v55, v56, v57, v58, v59, v60) )
    {
      v70 = _qdf_mem_malloc(0x20u, "cm_send_roam_invoke_req", 7507);
      v35 = v70;
      if ( v70 )
      {
        *(_BYTE *)v70 = v13;
        if ( (*(_BYTE *)(a2 + 32) & 1) != 0 )
        {
          *(_BYTE *)(v70 + 25) = 1;
        }
        else
        {
          v71 = (int *)(a2 + 40);
          if ( *(_DWORD *)(a2 + 40) == -1 && *(__int16 *)(a2 + 44) == -1 )
          {
            v90 = *v71;
            *(_WORD *)(v70 + 5) = *(_WORD *)(a2 + 44);
            *(_DWORD *)(v70 + 1) = v90;
          }
          else
          {
            if ( qdf_is_macaddr_equal_0(a2 + 40, (__int64)v92) )
              *(_BYTE *)(v35 + 24) = 1;
            v73 = *v71;
            *(_WORD *)(v35 + 5) = *(_WORD *)(a2 + 44);
            *(_DWORD *)(v35 + 1) = v73;
            *(_DWORD *)(v35 + 8) = *(_DWORD *)(a2 + 52);
            if ( (unsigned int)cm_find_roam_candidate(v14, a2 + 24, v35) )
              qdf_trace_msg(
                0x68u,
                2u,
                "%s: vdev %d cm_id 0x%x: No Candidate found, send roam invoke req, fw will perform scan",
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                v81,
                "cm_send_roam_invoke_req",
                v13,
                v11);
            if ( (wlan_cm_get_ese_assoc(v14, v13) & 1) != 0 )
            {
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: vdev %d cm_id 0x%x: Beacon is not required for ESE",
                v82,
                v83,
                v84,
                v85,
                v86,
                v87,
                v88,
                v89,
                "cm_send_roam_invoke_req",
                v13,
                v11);
              if ( *(_DWORD *)(v35 + 12) )
              {
                _qdf_mem_free(*(_QWORD *)(v35 + 16));
                *(_QWORD *)(v35 + 16) = 0;
                *(_DWORD *)(v35 + 12) = 0;
              }
            }
          }
        }
        if ( !(unsigned int)wlan_cm_tgt_send_roam_invoke_req(v15, v35) )
        {
          v33 = 0;
          if ( !*(_DWORD *)(v35 + 12) )
            goto LABEL_16;
          goto LABEL_15;
        }
      }
      goto LABEL_11;
    }
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: self bss roam disabled. invoke_src:%d",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "cm_send_roam_invoke_req",
      v13,
      v11,
      *(unsigned int *)(a2 + 36));
    v69 = *(_DWORD *)(a2 + 36);
    if ( v69 == 19 || v69 == 1 )
      cm_roam_reject_reassoc_event(v15, *a1, (unsigned __int8 *)v92);
  }
LABEL_10:
  v35 = 0;
LABEL_11:
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: fail to send roam invoke req",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "cm_send_roam_invoke_req",
    v13,
    v11,
    v91);
  v33 = wlan_sm_dispatch(a1[9], 0x13u, 4u, (__int64)&v91 + 4, v36, v37, v38, v39, v40, v41, v42, v43);
  if ( v33 )
    cm_remove_cmd(a1, (unsigned int *)&v91 + 1, v44, v45, v46, v47, v48, v49, v50, v51);
  if ( v35 )
  {
    if ( !*(_DWORD *)(v35 + 12) )
    {
LABEL_16:
      _qdf_mem_free(v35);
      goto LABEL_17;
    }
LABEL_15:
    _qdf_mem_free(*(_QWORD *)(v35 + 16));
    goto LABEL_16;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v33;
}
