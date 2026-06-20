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
  unsigned int v10; // w22
  __int64 v11; // x21
  unsigned __int16 *v12; // x28
  int v15; // w23
  const char *v16; // x2
  unsigned int v17; // w1
  __int64 result; // x0
  const void *v19; // x26
  __int64 v20; // x4
  __int64 v21; // x5
  __int64 v22; // x6
  __int64 v23; // x7
  int v24; // w9
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 v27; // x24
  unsigned __int8 *v28; // x25
  unsigned int v29; // w4
  __int64 v30; // x8
  __int64 v31; // x9
  __int64 v32; // x8
  _WORD *v33; // x8
  _QWORD *vdev_by_macaddr_from_psoc; // x27
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w28
  __int64 session_by_vdev_id; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x26
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int updated; // w26
  unsigned int *v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x5
  __int64 v81; // x6
  __int64 v82; // x7
  int v83; // w8
  __int64 v84; // x5
  __int64 v85; // x0
  __int64 v86; // x6
  unsigned __int8 *v87; // x2
  __int64 v88; // x4
  __int64 v89; // x1
  __int64 v90; // x3
  _QWORD *vdev_by_macaddr_from_pdev; // x0
  unsigned int *v92; // x8
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  int v101; // w22
  __int64 mld_ctx_by_mldaddr; // x0
  __int64 v103; // x8
  __int64 v104; // x4
  __int64 v105; // x5
  __int64 v106; // x6
  __int64 v107; // x7
  const char *v108; // x2
  __int64 v109; // x0
  unsigned __int16 *v110; // x20
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  unsigned __int8 *v119; // x21
  unsigned int v120; // w23
  int v121; // w8
  int v122; // w9
  int v123; // w10
  int v124; // w11
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  unsigned int v133; // w19
  __int64 v134; // [xsp+0h] [xbp-60h]
  __int64 v135; // [xsp+8h] [xbp-58h]
  __int64 v136; // [xsp+10h] [xbp-50h]
  int v137; // [xsp+24h] [xbp-3Ch]
  int v138; // [xsp+28h] [xbp-38h]
  unsigned int v139; // [xsp+2Ch] [xbp-34h]
  int v140; // [xsp+30h] [xbp-30h]
  _QWORD v141[4]; // [xsp+40h] [xbp-20h] BYREF

  v141[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *((unsigned __int16 *)a2 + 20);
  if ( !*((_WORD *)a2 + 20) )
  {
    v16 = "%s: Frame len = 0";
LABEL_5:
    v17 = 2;
LABEL_6:
    qdf_trace_msg(0x35u, v17, v16, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_auth_frame_no_session");
    result = 16;
    goto LABEL_70;
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
      v26 += 14000;
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
  v141[2] = *((_QWORD *)v28 + 2);
  v141[0] = v30;
  v141[1] = v31;
  if ( v29 <= 1 )
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
      "lim_process_sae_preauth_frame");
    if ( v15 != 7 )
      goto LABEL_23;
LABEL_47:
    vdev_by_macaddr_from_pdev = wlan_objmgr_get_vdev_by_macaddr_from_pdev(
                                  *(_QWORD *)(a1 + 21632),
                                  (const void *)(v11 + 4),
                                  0x39u);
    if ( vdev_by_macaddr_from_pdev )
    {
      v101 = *((unsigned __int8 *)vdev_by_macaddr_from_pdev + 168);
      wlan_objmgr_vdev_release_ref(
        (__int64)vdev_by_macaddr_from_pdev,
        0x39u,
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        v100);
      if ( v101 == 255 )
        goto LABEL_66;
      goto LABEL_67;
    }
    mld_ctx_by_mldaddr = wlan_mlo_get_mld_ctx_by_mldaddr(v11 + 4);
    if ( mld_ctx_by_mldaddr )
    {
      v103 = *(_QWORD *)(mld_ctx_by_mldaddr + 24);
      if ( v103 )
      {
        v101 = *(unsigned __int8 *)(v103 + 168);
        if ( v101 == 255 )
        {
LABEL_66:
          LOBYTE(v101) = wlan_nan_get_vdev_id_from_bssid(*(_QWORD *)(a1 + 21632), v19, 57);
          if ( (_BYTE)v101 == 0xFF )
          {
            v16 = "%s: NAN vdev_id not found";
            goto LABEL_5;
          }
        }
LABEL_67:
        v119 = *((unsigned __int8 **)a2 + 2);
        v120 = a2[10];
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
          (unsigned __int8)v101);
        v84 = *a2;
        v90 = v120 + 24;
        v86 = a2[2];
        v88 = (unsigned __int8)v101;
        v85 = a1;
        v89 = *v119 >> 4;
        v87 = v119;
        goto LABEL_68;
      }
      if ( v11 == -4 )
      {
        v106 = 0;
        v104 = 0;
        v105 = 0;
        v107 = 0;
        v108 = "%s: vdev is null for macaddr %02x:%02x:%02x:**:**:%02x";
      }
      else
      {
        v104 = *(unsigned __int8 *)(v11 + 4);
        v105 = *(unsigned __int8 *)(v11 + 5);
        v108 = "%s: vdev is null for macaddr %02x:%02x:%02x:**:**:%02x";
        v106 = *(unsigned __int8 *)(v11 + 6);
        v107 = *(unsigned __int8 *)(v11 + 9);
      }
    }
    else
    {
      if ( v11 == -4 )
      {
        v106 = 0;
        v104 = 0;
        v105 = 0;
        v107 = 0;
      }
      else
      {
        v104 = *(unsigned __int8 *)(v11 + 4);
        v105 = *(unsigned __int8 *)(v11 + 5);
        v106 = *(unsigned __int8 *)(v11 + 6);
        v107 = *(unsigned __int8 *)(v11 + 9);
      }
      v108 = "%s: ML dev ctx is null for macaddr %02x:%02x:%02x:**:**:%02x";
    }
    qdf_trace_msg(
      0x35u,
      2u,
      v108,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_get_vdev_id_from_macaddr",
      v104,
      v105,
      v106,
      v107);
    goto LABEL_66;
  }
  v33 = *((_WORD **)a2 + 3);
  if ( *v33 != 3 )
    goto LABEL_46;
  v139 = v29;
  if ( v29 < 6 )
  {
    v137 = 0;
    v138 = 0;
  }
  else
  {
    v137 = (unsigned __int16)v33[2];
    v138 = (unsigned __int16)v33[1];
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
                                *(_QWORD *)(a1 + 21624),
                                *(_BYTE *)(*(_QWORD *)(a1 + 21632) + 40LL),
                                v28 + 4,
                                7u);
  if ( vdev_by_macaddr_from_psoc
    || (vdev_by_macaddr_from_psoc = wlan_objmgr_pdev_get_roam_vdev(*(_QWORD *)(a1 + 21632), 7u)) != nullptr )
  {
    v140 = (int)v12;
    v43 = *((unsigned __int8 *)vdev_by_macaddr_from_psoc + 168);
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, *((unsigned __int8 *)vdev_by_macaddr_from_psoc + 168));
    if ( session_by_vdev_id )
    {
      v53 = session_by_vdev_id;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: sae auth cleanup for vdev_id %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "lim_sae_auth_cleanup_retry",
        v43);
      lim_deactivate_and_change_timer(a1, 20);
      mlme_free_sae_auth_retry(*(_QWORD *)(v53 + 16), v54, v55, v56, v57, v58, v59, v60, v61);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: session not found for given vdev_id %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "lim_sae_auth_cleanup_retry",
        v43);
    }
    updated = lim_update_link_to_mld_address(a1, vdev_by_macaddr_from_psoc, v28);
    wlan_objmgr_vdev_release_ref((__int64)vdev_by_macaddr_from_psoc, 7u, v63, v64, v65, v66, v67, v68, v69, v70, v71);
    if ( !updated )
    {
      wlan_connectivity_mgmt_event(*(_QWORD *)(a1 + 21624), (int)v141, v43, v137, 0, a2[2], 3, v138, v138, 0, 3);
      v84 = *a2;
      v85 = a1;
      v86 = a2[2];
      v87 = v28;
      v88 = 50;
      v89 = *v28 >> 4;
      v90 = v139 + 24;
LABEL_68:
      lim_send_sme_mgmt_frame_ind(v85, v89, v87, v90, v88, v84, v86, 0);
      goto LABEL_69;
    }
    if ( v28 == (unsigned __int8 *)-16LL )
    {
      v82 = 0;
      v80 = 0;
      v81 = 0;
      v83 = 0;
    }
    else
    {
      v80 = v28[16];
      v81 = v28[17];
      v82 = v28[18];
      v83 = v28[21];
    }
    LODWORD(v134) = v83;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev:%d dropping auth frame BSSID: %02x:%02x:%02x:**:**:%02x, SAE address conversion failure",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "lim_process_sae_preauth_frame",
      v43,
      v80,
      v81,
      v82,
      v134);
    v19 = (const void *)(v11 + 16);
    LODWORD(v12) = v140;
LABEL_46:
    if ( v15 == 7 )
      goto LABEL_47;
    goto LABEL_23;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: not able to find roaming vdev",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "lim_process_sae_preauth_frame");
  if ( v15 == 7 )
    goto LABEL_47;
LABEL_23:
  if ( !v27 )
  {
    v16 = "%s: cannot find session id in FT pre-auth phase";
    v17 = 8;
    goto LABEL_6;
  }
  v32 = *(_QWORD *)(v27 + 7432);
  *(_BYTE *)(v27 + 7856) = 0;
  if ( !v32 )
  {
    v16 = "%s: Error: No FT";
    goto LABEL_5;
  }
  if ( (unsigned int)qdf_mem_cmp((const void *)(v32 + 18), v19, 6u) )
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
LABEL_69:
    result = 0;
    goto LABEL_70;
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
  v109 = _qdf_mem_malloc(0x3FFu, "lim_process_auth_frame_no_session", 2534);
  if ( v109 )
  {
    v110 = (unsigned __int16 *)v109;
    if ( (unsigned int)sir_convert_auth_frame2_struct(a1, (int)v12, v10, v109) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: failed to convert Auth frame to struct",
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        "lim_process_auth_frame_no_session");
      _qdf_mem_free((__int64)v110);
      result = 16;
    }
    else
    {
      if ( v11 == -10 )
      {
        v123 = 0;
        v121 = 0;
        v122 = 0;
        v124 = 0;
      }
      else
      {
        v121 = *(unsigned __int8 *)(v11 + 10);
        v122 = *(unsigned __int8 *)(v11 + 11);
        v123 = *(unsigned __int8 *)(v11 + 12);
        v124 = *(unsigned __int8 *)(v11 + 15);
      }
      LODWORD(v136) = v123;
      LODWORD(v135) = v122;
      LODWORD(v134) = v121;
      qdf_trace_msg(
        0x35u,
        4u,
        "%s: Pre-Auth RX: type: %d trans_seqnum: %d status: %d %d from %02x:%02x:%02x:**:**:%02x",
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        "lim_process_auth_frame_no_session",
        *v110,
        v110[1],
        v110[2],
        *(unsigned int *)(a1 + 11404),
        v134,
        v135,
        v136,
        v124);
      if ( v110[1] == 2 )
      {
        if ( v110[2] )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Auth status code received is %d",
            v125,
            v126,
            v127,
            v128,
            v129,
            v130,
            v131,
            v132,
            "lim_process_auth_frame_no_session");
          if ( v110[2] == 17 )
            v133 = 19;
          else
            v133 = 16;
        }
        else
        {
          v133 = 0;
        }
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: Seq. no incorrect expected 2 received %d",
          v125,
          v126,
          v127,
          v128,
          v129,
          v130,
          v131,
          v132,
          "lim_process_auth_frame_no_session");
        v133 = 16;
      }
      _qdf_mem_free((__int64)v110);
      result = v133;
    }
  }
  else
  {
    result = 2;
  }
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
