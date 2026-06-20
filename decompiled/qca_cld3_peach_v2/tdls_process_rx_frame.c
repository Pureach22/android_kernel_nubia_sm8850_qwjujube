__int64 __fastcall tdls_process_rx_frame(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x28
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  __int64 *comp_private_obj; // x0
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _QWORD *v31; // x25
  unsigned __int8 *v32; // x21
  __int64 v33; // x22
  __int64 tdls_link_vdev; // x23
  unsigned int v35; // w4
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x26
  int v45; // w27
  unsigned __int8 *ie_ptr_from_eid; // x0
  _QWORD *correct_vdev; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  _QWORD *v56; // x22
  __int64 v57; // x4
  unsigned int v58; // w21
  _QWORD *v59; // x0
  const char *v60; // x2
  void (__fastcall *v61)(__int64, unsigned __int8 *); // x8
  __int64 v62; // x0
  __int64 v63; // x24
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x23
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x23
  __int64 *v70; // x0
  int v71; // w26
  __int64 v72; // x5
  __int64 v73; // x6
  __int64 v74; // x7
  int v75; // w8
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  void (__fastcall *v84)(__int64, unsigned __int8 *); // x8
  __int64 v85; // x0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x0
  __int64 v103; // x8
  __int64 v104; // x26
  __int64 v105; // x0
  unsigned int v106; // w9
  int v107; // w27
  __int64 v108; // x0
  __int64 v109; // x0
  __int64 v110; // x0
  __int64 v111; // x0
  _DWORD *v112; // x0
  __int64 v114; // x0
  __int64 v115; // x0
  unsigned int v118; // w9
  unsigned int v125; // w9
  unsigned int v128; // w9
  __int64 v129; // [xsp+0h] [xbp-40h]
  __int64 v130; // [xsp+8h] [xbp-38h]
  unsigned int v131; // [xsp+1Ch] [xbp-24h]
  unsigned int *v132; // [xsp+20h] [xbp-20h]
  __int64 v133; // [xsp+28h] [xbp-18h]
  char v134[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v135; // [xsp+38h] [xbp-8h]

  v135 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 8);
  if ( v9 )
  {
    v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            **(_QWORD **)v9,
            *(unsigned int *)(*(_QWORD *)(v9 + 8) + 8LL),
            17);
    if ( !v11 )
    {
      v58 = 16;
LABEL_82:
      _qdf_mem_free(*(_QWORD *)(v9 + 8));
      _qdf_mem_free(*(_QWORD *)(a1 + 8));
      *(_QWORD *)(a1 + 8) = 0;
      goto LABEL_83;
    }
    v20 = v11;
    qdf_trace_msg(
      0,
      8u,
      "%s: vdev:%d tdls rx mgmt frame received",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "tdls_process_rx_frame",
      *(unsigned __int8 *)(v11 + 168));
    comp_private_obj = (__int64 *)wlan_objmgr_vdev_get_comp_private_obj(v20, 0xAu);
    if ( !comp_private_obj )
    {
      v58 = 16;
      goto LABEL_81;
    }
    v31 = *(_QWORD **)v9;
    if ( !*(_QWORD *)v9 || (v32 = *(unsigned __int8 **)(v9 + 8)) == nullptr )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: invalid psoc object or rx mgmt",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "tdls_process_rx_mgmt");
      v58 = 4;
      goto LABEL_81;
    }
    v33 = (__int64)comp_private_obj;
    tdls_link_vdev = *comp_private_obj;
    qdf_trace_msg(
      0,
      8u,
      "%s: soc:%pK, frame_len:%d, rx_freq:%d, vdev_id:%d, frm_type:%d, rx_rssi:%d, buf:%pK",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "tdls_process_rx_mgmt",
      *v31,
      *(unsigned int *)v32,
      *((unsigned int *)v32 + 1),
      *((unsigned int *)v32 + 2),
      *((_DWORD *)v32 + 3),
      *((_DWORD *)v32 + 4),
      v32 + 20);
    v35 = v32[45];
    if ( v35 == 14 )
    {
      if ( (wlan_vdev_mlme_is_mlo_vdev(tdls_link_vdev, v23, v24, v25, v26, v27, v28, v29, v30) & 1) != 0
        && *((_DWORD *)v31 + 157) )
      {
        v44 = *(_QWORD *)v33;
        v132 = (unsigned int *)v31 + 157;
        v134[0] = 107;
        if ( !v44 )
          goto LABEL_13;
        v45 = *(_DWORD *)v32 - 29;
        ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x65u, v32 + 49, *(_WORD *)v32 - 29);
        if ( ie_ptr_from_eid )
          ((void (__fastcall *)(_QWORD, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(
            0,
            8,
            ie_ptr_from_eid,
            (unsigned int)ie_ptr_from_eid[1] + 2);
        if ( wlan_get_ext_ie_ptr_from_ext_id(v134, 1u, v32 + 49, v45) )
        {
LABEL_13:
          qdf_trace_msg(
            0,
            8u,
            "%s: peer is mlo device, timer_cnt %d",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "tdls_process_mlo_rx_mgmt_sync",
            *((unsigned int *)v31 + 157));
          correct_vdev = (_QWORD *)tdls_get_correct_vdev(v33, v32);
          if ( !correct_vdev )
          {
            v57 = 255;
            goto LABEL_37;
          }
          v56 = correct_vdev;
          if ( correct_vdev[119] )
          {
            v57 = *(unsigned __int8 *)(*correct_vdev + 168LL);
LABEL_37:
            qdf_trace_msg(
              0,
              2u,
              "%s: Received duplicate tdls discovery resp on same vdev %d",
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              "tdls_process_mlo_rx_mgmt_sync",
              v57);
            goto LABEL_80;
          }
          if ( *((_DWORD *)v31 + 157) != 1 )
            goto LABEL_75;
          v103 = v44;
          v104 = *(_QWORD *)(v44 + 1360);
          v133 = v103;
          v105 = *(_QWORD *)(v104 + 24);
          if ( v105 && !*(_DWORD *)(v103 + 16) )
          {
            v108 = wlan_objmgr_vdev_get_comp_private_obj(v105, 0xAu);
            v106 = 1;
            v107 = *(_QWORD *)(v108 + 952) != 0;
          }
          else
          {
            v106 = 0;
            v107 = 0;
          }
          v109 = *(_QWORD *)(v104 + 32);
          if ( v109 )
          {
            v44 = v133;
            if ( !*(_DWORD *)(v133 + 16) )
            {
              v131 = v106 + 1;
              v110 = wlan_objmgr_vdev_get_comp_private_obj(v109, 0xAu);
              v106 = v131;
              if ( *(_QWORD *)(v110 + 952) )
                ++v107;
            }
          }
          else
          {
            v44 = v133;
          }
          if ( v106 > v107 + 1 )
          {
            qdf_trace_msg(
              0,
              8u,
              "%s: vdev:%d wait further for tdls response",
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              "tdls_process_mlo_rx_mgmt_sync",
              *(unsigned __int8 *)(v44 + 168));
            v111 = v56[119];
            if ( !v111 )
              goto LABEL_77;
          }
          else
          {
LABEL_75:
            *((_DWORD *)v56 + 192) = 0;
            qdf_mc_timer_stop((__int64)(v56 + 70));
            _X11 = (char *)v31 + 628;
            __asm { PRFM            #0x11, [X11] }
            do
              v118 = __ldxr(v132);
            while ( __stxr(v118 - 1, v132) );
            v111 = v56[119];
            if ( !v111 )
              goto LABEL_77;
          }
          _qdf_mem_free(v111);
          v56[119] = 0;
LABEL_77:
          v112 = qdf_mem_malloc_atomic_fl(*(unsigned int *)v32 + 24LL, (__int64)"tdls_process_mlo_rx_mgmt_sync", 0x188u);
          v56[119] = v112;
          if ( v112 )
          {
            *v112 = *(_DWORD *)v32;
            *(_DWORD *)(v56[119] + 4LL) = *((_DWORD *)v32 + 1);
            *(_DWORD *)(v56[119] + 8LL) = *((_DWORD *)v32 + 2);
            *(_DWORD *)(v56[119] + 12LL) = *((_DWORD *)v32 + 3);
            *(_DWORD *)(v56[119] + 16LL) = *((_DWORD *)v32 + 4);
            qdf_mem_copy((void *)(v56[119] + 20LL), v32 + 20, *(unsigned int *)v32);
          }
          v22 = (unsigned int *)*((unsigned int *)v31 + 157);
          if ( (_DWORD)v22 )
            goto LABEL_80;
          tdls_process_mlo_cal_tdls_link_score(v44);
          v114 = tdls_process_mlo_choice_tdls_vdev(tdls_link_vdev);
          if ( !v114 )
            goto LABEL_80;
          tdls_link_vdev = v114;
          v115 = wlan_objmgr_vdev_get_comp_private_obj(v114, 0xAu);
          if ( !v115 )
          {
            v58 = 14;
            goto LABEL_81;
          }
          v33 = v115;
          v32 = *(unsigned __int8 **)(v115 + 952);
          qdf_trace_msg(
            0,
            8u,
            "%s: choose vdev %d as tdls vdev",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "tdls_process_rx_mgmt",
            *(unsigned __int8 *)(tdls_link_vdev + 168));
          v71 = 1;
          goto LABEL_49;
        }
        v63 = *(_QWORD *)(v44 + 1360);
        v64 = *(_QWORD *)(v63 + 24);
        if ( v64
          && (v65 = wlan_objmgr_vdev_get_comp_private_obj(v64, 0xAu)) != 0
          && (v66 = v65, *(_DWORD *)(v65 + 768) = 0, (unsigned int)qdf_mc_timer_get_current_state(v65 + 560) == 21) )
        {
          qdf_mc_timer_stop(v66 + 560);
          _X11 = (char *)v31 + 628;
          __asm { PRFM            #0x11, [X11] }
          do
            v125 = __ldxr(v132);
          while ( __stxr(v125 - 1, v132) );
          v67 = *(_QWORD *)(v63 + 32);
          if ( !v67 )
            goto LABEL_46;
        }
        else
        {
          v67 = *(_QWORD *)(v63 + 32);
          if ( !v67 )
          {
LABEL_46:
            qdf_trace_msg(
              0,
              8u,
              "%s: peer is legacy device, timer_cnt %d",
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              "tdls_process_mlo_rx_mgmt_sync",
              *((unsigned int *)v31 + 157));
            v70 = (__int64 *)tdls_get_correct_vdev(v33, v32);
            if ( !v70 )
              goto LABEL_80;
            tdls_link_vdev = *v70;
            v33 = (__int64)v70;
            goto LABEL_48;
          }
        }
        v68 = wlan_objmgr_vdev_get_comp_private_obj(v67, 0xAu);
        if ( v68 )
        {
          v69 = v68;
          *(_DWORD *)(v68 + 768) = 0;
          if ( (unsigned int)qdf_mc_timer_get_current_state(v68 + 560) == 21 )
          {
            qdf_mc_timer_stop(v69 + 560);
            _X11 = (char *)v31 + 628;
            __asm { PRFM            #0x11, [X11] }
            do
              v128 = __ldxr(v132);
            while ( __stxr(v128 - 1, v132) );
          }
        }
        goto LABEL_46;
      }
      if ( (wlan_vdev_mlme_is_mlo_vdev(tdls_link_vdev, v36, v37, v38, v39, v40, v41, v42, v43) & 1) == 0 )
      {
LABEL_48:
        v71 = 0;
LABEL_49:
        if ( v32 == (unsigned __int8 *)-30LL )
        {
          v74 = 0;
          v72 = 0;
          v73 = 0;
          v75 = 0;
        }
        else
        {
          v72 = v32[30];
          v73 = v32[31];
          v74 = v32[32];
          v75 = v32[35];
        }
        LODWORD(v130) = *((_DWORD *)v32 + 4);
        LODWORD(v129) = v75;
        qdf_trace_msg(
          0,
          4u,
          "%s: [TDLS] vdev:%d TDLS Discovery Response,%02x:%02x:%02x:**:**:%02x RSSI[%d] <--- OTA",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "tdls_process_rx_mgmt",
          *(unsigned __int8 *)(tdls_link_vdev + 168),
          v72,
          v73,
          v74,
          v129,
          v130);
        v84 = (void (__fastcall *)(__int64, unsigned __int8 *))v31[29];
        if ( v84 )
        {
          v85 = v31[30];
          if ( *((_DWORD *)v84 - 1) != -2109187 )
            __break(0x8228u);
          v84(v85, v32);
        }
        else
        {
          qdf_trace_msg(
            0,
            8u,
            "%s: rx mgmt, but no valid up layer callback",
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            "tdls_process_rx_mgmt");
        }
        tdls_recv_discovery_resp(v33, v32 + 30, v86, v87, v88, v89, v90, v91, v92, v93);
        tdls_set_rssi(*(_QWORD *)v33, v32 + 30, *((_DWORD *)v32 + 4), v94, v95, v96, v97, v98, v99, v100, v101);
        if ( !v71 )
          goto LABEL_80;
        v102 = *(_QWORD *)(v33 + 952);
        if ( !v102 )
          goto LABEL_80;
        _qdf_mem_free(v102);
        v58 = 0;
        *(_QWORD *)(v33 + 952) = 0;
        *(_DWORD *)(v33 + 960) = 0;
LABEL_81:
        wlan_objmgr_vdev_release_ref(v20, 0x11u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
        goto LABEL_82;
      }
      tdls_link_vdev = wlan_mlo_get_tdls_link_vdev(tdls_link_vdev);
      v59 = (_QWORD *)tdls_get_correct_vdev(v33, v32);
      if ( tdls_link_vdev && (v33 = (__int64)v59) != 0 )
      {
        if ( tdls_link_vdev == *v59 )
        {
          v71 = 0;
          *((_DWORD *)v32 + 2) = *(unsigned __int8 *)(tdls_link_vdev + 168);
          goto LABEL_49;
        }
        v60 = "%s: not forward to userspace";
      }
      else
      {
        v60 = "%s: not expected frame";
      }
    }
    else
    {
      if ( v32[44] == 12 )
      {
        if ( v35 < 0xB )
          qdf_trace_msg(
            0,
            4u,
            "%s: [TDLS] %s <--- OTA",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "tdls_process_rx_mgmt",
            tdls_action_frames_type[v32[45]]);
        else
          qdf_trace_msg(
            0,
            8u,
            "%s: [TDLS] unknown[%d] <--- OTA",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "tdls_process_rx_mgmt");
      }
      v61 = (void (__fastcall *)(__int64, unsigned __int8 *))v31[29];
      if ( v61 )
      {
        v62 = v31[30];
        if ( *((_DWORD *)v61 - 1) != -2109187 )
          __break(0x8228u);
        v61(v62, v32);
        goto LABEL_80;
      }
      v60 = "%s: rx mgmt, but no valid up layer callback";
    }
    qdf_trace_msg(0, 8u, v60, v23, v24, v25, v26, v27, v28, v29, v30, "tdls_process_rx_mgmt");
LABEL_80:
    v58 = 0;
    goto LABEL_81;
  }
  qdf_trace_msg(0, 2u, "%s: invalid message body", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_rx_frame");
  v58 = 4;
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return v58;
}
