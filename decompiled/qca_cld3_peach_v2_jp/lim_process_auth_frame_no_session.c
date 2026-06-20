__int64 __fastcall lim_process_auth_frame_no_session(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w21
  __int64 v11; // x22
  unsigned __int16 *v12; // x23
  int v15; // w27
  const char *v16; // x2
  unsigned int v17; // w1
  __int64 result; // x0
  const void *v19; // x28
  __int64 v20; // x4
  __int64 v21; // x5
  __int64 v22; // x6
  __int64 v23; // x7
  int v24; // w9
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 v27; // x24
  unsigned __int8 *v28; // x25
  unsigned int v29; // w26
  __int64 v30; // x8
  __int64 v31; // x9
  _WORD *v32; // x8
  _QWORD *vdev_by_macaddr_from_psoc; // x28
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w21
  __int64 session_by_vdev_id; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x22
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int *v61; // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x5
  __int64 v71; // x3
  __int64 v72; // x6
  __int64 v73; // x0
  unsigned __int8 *v74; // x2
  __int64 v75; // x1
  __int64 v76; // x4
  _QWORD *vdev_by_macaddr_from_pdev; // x0
  unsigned int *v78; // x8
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  int v87; // w21
  __int64 v88; // x8
  __int64 v89; // x4
  __int64 v90; // x5
  __int64 v91; // x6
  __int64 v92; // x7
  unsigned __int8 *v93; // x22
  unsigned int v94; // w23
  __int64 v95; // x0
  unsigned __int16 *v96; // x20
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  int v105; // w8
  int v106; // w9
  int v107; // w10
  int v108; // w11
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  unsigned int v117; // w19
  __int64 v118; // [xsp+0h] [xbp-50h]
  __int64 v119; // [xsp+8h] [xbp-48h]
  __int64 v120; // [xsp+10h] [xbp-40h]
  int v121; // [xsp+28h] [xbp-28h]
  int v122; // [xsp+2Ch] [xbp-24h]
  _QWORD v123[4]; // [xsp+30h] [xbp-20h] BYREF

  v123[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *((unsigned __int16 *)a2 + 20);
  if ( !*((_WORD *)a2 + 20) )
  {
    v16 = "%s: Frame len = 0";
LABEL_5:
    v17 = 2;
LABEL_6:
    qdf_trace_msg(0x35u, v17, v16, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_auth_frame_no_session");
    result = 16;
    goto LABEL_54;
  }
  v11 = *((_QWORD *)a2 + 2);
  v12 = *((unsigned __int16 **)a2 + 3);
  if ( v10 < 3 )
    v15 = 0;
  else
    v15 = *v12;
  v19 = (const void *)(v11 + 16);
  if ( v11 == -16 )
  {
    v22 = 0;
    v20 = 0;
    v21 = 0;
    v23 = 0;
  }
  else
  {
    v20 = *(unsigned __int8 *)(v11 + 16);
    v21 = *(unsigned __int8 *)(v11 + 17);
    v22 = *(unsigned __int8 *)(v11 + 18);
    v23 = *(unsigned __int8 *)(v11 + 21);
  }
  v24 = *((char *)a2 + 8);
  if ( v24 < 0 )
    v24 = -v24;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Auth RX: BSSID %02x:%02x:%02x:**:**:%02x RSSI:%d auth_alg:%d seq:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_process_auth_frame_no_session",
    v20,
    v21,
    v22,
    v23,
    v24,
    v15,
    *(unsigned __int16 *)(v11 + 22) >> 4);
  v25 = *(unsigned __int16 *)(a1 + 3992);
  if ( *(_WORD *)(a1 + 3992) )
  {
    v26 = *(_QWORD *)(a1 + 12264);
    v27 = 0;
    do
    {
      if ( *(_BYTE *)(v26 + 70) == 1 && *(_BYTE *)(v26 + 7856) )
        v27 = v26;
      --v25;
      v26 += 10792;
    }
    while ( v25 );
  }
  else
  {
    v27 = 0;
  }
  v28 = *((unsigned __int8 **)a2 + 2);
  v29 = *((unsigned __int16 *)a2 + 20);
  v30 = *(_QWORD *)v28;
  v31 = *((_QWORD *)v28 + 1);
  v123[2] = *((_QWORD *)v28 + 2);
  v123[0] = v30;
  v123[1] = v31;
  if ( v29 > 1 )
  {
    v32 = *((_WORD **)a2 + 3);
    if ( *v32 == 3 )
    {
      if ( v29 < 6 )
      {
        v122 = 0;
        v121 = 0;
      }
      else
      {
        v122 = (unsigned __int16)v32[1];
        v121 = (unsigned __int16)v32[2];
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: LFR3: SAE auth frame: seq_ctrl:0x%X auth_transaction_num:%d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "lim_process_sae_preauth_frame",
        *((unsigned __int16 *)v28 + 11));
      vdev_by_macaddr_from_psoc = wlan_objmgr_get_vdev_by_macaddr_from_psoc(
                                    *(_QWORD *)(a1 + 21552),
                                    *(_BYTE *)(*(_QWORD *)(a1 + 21560) + 40LL),
                                    v28 + 4,
                                    7u);
      if ( vdev_by_macaddr_from_psoc
        || (vdev_by_macaddr_from_psoc = wlan_objmgr_pdev_get_roam_vdev(*(_QWORD *)(a1 + 21560), 7u)) != nullptr )
      {
        v42 = *((unsigned __int8 *)vdev_by_macaddr_from_psoc + 104);
        session_by_vdev_id = pe_find_session_by_vdev_id(a1, *((unsigned __int8 *)vdev_by_macaddr_from_psoc + 104));
        if ( session_by_vdev_id )
        {
          v52 = session_by_vdev_id;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: sae auth cleanup for vdev_id %d",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "lim_sae_auth_cleanup_retry",
            v42);
          lim_deactivate_and_change_timer(a1, 20);
          mlme_free_sae_auth_retry(*(_QWORD *)(v52 + 16), v53, v54, v55, v56, v57, v58, v59, v60);
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: session not found for given vdev_id %d",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "lim_sae_auth_cleanup_retry",
            v42);
        }
        wlan_objmgr_vdev_release_ref(
          (__int64)vdev_by_macaddr_from_psoc,
          7u,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69);
        wlan_connectivity_mgmt_event(*(_QWORD *)(a1 + 21552), (int)v123, v42, v121, 0, a2[2], 3, v122, v122, 0, 3);
        v70 = *a2;
        v71 = v29 + 24;
        v72 = a2[2];
        v73 = a1;
        v74 = v28;
        v75 = *v28 >> 4;
        v76 = 50;
        goto LABEL_52;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: not able to find roaming vdev",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "lim_process_sae_preauth_frame");
      v19 = (const void *)(v11 + 16);
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: LFR3: Invalid auth frame len:%d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_process_sae_preauth_frame",
      v29);
  }
  if ( v15 == 7 )
  {
    vdev_by_macaddr_from_pdev = wlan_objmgr_get_vdev_by_macaddr_from_pdev(
                                  *(_QWORD *)(a1 + 21560),
                                  (const void *)(v11 + 4),
                                  0x39u);
    if ( vdev_by_macaddr_from_pdev )
    {
      v87 = *((unsigned __int8 *)vdev_by_macaddr_from_pdev + 104);
      wlan_objmgr_vdev_release_ref(
        (__int64)vdev_by_macaddr_from_pdev,
        0x39u,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86);
      if ( v87 != 255 )
      {
LABEL_51:
        v93 = *((unsigned __int8 **)a2 + 2);
        v94 = a2[10];
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev_id:%d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "lim_process_pasn_auth_frame",
          (unsigned __int8)v87);
        v70 = *a2;
        v71 = v94 + 24;
        v72 = a2[2];
        v76 = (unsigned __int8)v87;
        v73 = a1;
        v75 = *v93 >> 4;
        v74 = v93;
LABEL_52:
        lim_send_sme_mgmt_frame_ind(v73, v75, v74, v71, v76, v70, v72, 0);
        goto LABEL_53;
      }
    }
    else
    {
      if ( v11 == -4 )
      {
        v91 = 0;
        v89 = 0;
        v90 = 0;
        v92 = 0;
      }
      else
      {
        v89 = *(unsigned __int8 *)(v11 + 4);
        v90 = *(unsigned __int8 *)(v11 + 5);
        v91 = *(unsigned __int8 *)(v11 + 6);
        v92 = *(unsigned __int8 *)(v11 + 9);
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: ML dev ctx is null for macaddr %02x:%02x:%02x:**:**:%02x",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        "lim_get_vdev_id_from_macaddr",
        v89,
        v90,
        v91,
        v92);
    }
    LOBYTE(v87) = wlan_nan_get_vdev_id_from_bssid(*(_QWORD *)(a1 + 21560), v19, 57);
    if ( (_BYTE)v87 != 0xFF )
      goto LABEL_51;
    v16 = "%s: NAN vdev_id not found";
    goto LABEL_5;
  }
  if ( !v27 )
  {
    v16 = "%s: cannot find session id in FT pre-auth phase";
    v17 = 8;
    goto LABEL_6;
  }
  v88 = *(_QWORD *)(v27 + 7432);
  *(_BYTE *)(v27 + 7856) = 0;
  if ( !v88 )
  {
    v16 = "%s: Error: No FT";
    goto LABEL_5;
  }
  if ( (unsigned int)qdf_mem_cmp((const void *)(v88 + 18), v19, 6u) )
  {
    v16 = "%s: Error: Same bssid as preauth BSSID";
    goto LABEL_5;
  }
  if ( *(_BYTE *)(*(_QWORD *)(v27 + 7432) + 8LL) == 1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Auth rsp already posted to SME (session %pK, FT session %pK)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_process_auth_frame_no_session",
      v27,
      v27);
LABEL_53:
    result = 0;
    goto LABEL_54;
  }
  qdf_trace_msg(
    0x35u,
    3u,
    "%s: Auth rsp not yet posted to SME (session %pK, FT session %pK)",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_process_auth_frame_no_session",
    v27,
    v27);
  *(_BYTE *)(*(_QWORD *)(v27 + 7432) + 8LL) = 1;
  lim_deactivate_and_change_timer(a1, 14);
  v95 = _qdf_mem_malloc(0x3FFu, "lim_process_auth_frame_no_session", 2534);
  if ( v95 )
  {
    v96 = (unsigned __int16 *)v95;
    if ( (unsigned int)sir_convert_auth_frame2_struct(a1, (int)v12, v10, v95) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: failed to convert Auth frame to struct",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "lim_process_auth_frame_no_session");
      _qdf_mem_free((__int64)v96);
      result = 16;
    }
    else
    {
      if ( v11 == -10 )
      {
        v107 = 0;
        v105 = 0;
        v106 = 0;
        v108 = 0;
      }
      else
      {
        v105 = *(unsigned __int8 *)(v11 + 10);
        v106 = *(unsigned __int8 *)(v11 + 11);
        v107 = *(unsigned __int8 *)(v11 + 12);
        v108 = *(unsigned __int8 *)(v11 + 15);
      }
      LODWORD(v120) = v107;
      LODWORD(v119) = v106;
      LODWORD(v118) = v105;
      qdf_trace_msg(
        0x35u,
        4u,
        "%s: Pre-Auth RX: type: %d trans_seqnum: %d status: %d %d from %02x:%02x:%02x:**:**:%02x",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "lim_process_auth_frame_no_session",
        *v96,
        v96[1],
        v96[2],
        *(unsigned int *)(a1 + 11404),
        v118,
        v119,
        v120,
        v108);
      if ( v96[1] == 2 )
      {
        if ( v96[2] )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Auth status code received is %d",
            v109,
            v110,
            v111,
            v112,
            v113,
            v114,
            v115,
            v116,
            "lim_process_auth_frame_no_session");
          if ( v96[2] == 17 )
            v117 = 19;
          else
            v117 = 16;
        }
        else
        {
          v117 = 0;
        }
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: Seq. no incorrect expected 2 received %d",
          v109,
          v110,
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          "lim_process_auth_frame_no_session");
        v117 = 16;
      }
      _qdf_mem_free((__int64)v96);
      result = v117;
    }
  }
  else
  {
    result = 2;
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
