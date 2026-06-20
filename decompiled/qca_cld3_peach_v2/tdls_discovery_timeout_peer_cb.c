__int64 *__fastcall tdls_discovery_timeout_peer_cb(
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
  __int64 v9; // x8
  __int64 v11; // x0
  __int64 *result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 *v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v31; // x26
  __int64 *v32; // x27
  int v33; // w28
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _QWORD *v42; // x25
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w8
  __int64 v56; // x4
  __int64 v57; // x5
  __int64 v58; // x6
  __int64 v59; // x7
  const char *v60; // x2
  const char *v61; // x3
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 *v70; // x19
  unsigned int v76; // w9
  unsigned int v77; // w9
  __int64 v78; // x21
  __int64 tdls_link_vdev; // x0
  __int64 v80; // x22
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 *v89; // x19
  __int64 v90; // x21
  __int64 v91; // x5
  __int64 v92; // x6
  __int64 v93; // x7
  int v94; // w8
  void (__fastcall *v95)(__int64, __int64); // x8
  __int64 v96; // x0
  __int64 v97; // [xsp+0h] [xbp-30h]
  __int64 v98; // [xsp+8h] [xbp-28h]
  __int64 *v99; // [xsp+18h] [xbp-18h]
  _QWORD *v100[2]; // [xsp+20h] [xbp-10h] BYREF

  v100[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v100[0] = nullptr;
  if ( !a1 )
  {
    v60 = "%s: discovery time out vdev is null";
LABEL_25:
    v61 = "tdls_discovery_timeout_peer_cb";
    goto LABEL_26;
  }
  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 || (v11 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v60 = "%s: can't get psoc";
    v61 = "wlan_vdev_get_tdls_soc_obj";
LABEL_26:
    result = (__int64 *)qdf_trace_msg(0, 2u, v60, a2, a3, a4, a5, a6, a7, a8, a9, v61);
    goto LABEL_27;
  }
  result = (__int64 *)wlan_objmgr_psoc_get_comp_private_obj(v11, 0xAu);
  if ( !result )
    goto LABEL_27;
  v21 = result;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v13, v14, v15, v16, v17, v18, v19, v20) & 1) != 0 && !*((_DWORD *)v21 + 157) )
  {
    result = (__int64 *)wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu);
    if ( result )
    {
      v70 = result;
      result = (__int64 *)_qdf_mem_free(result[119]);
      v70[119] = 0;
    }
    goto LABEL_27;
  }
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v22, v23, v24, v25, v26, v27, v28, v29) & 1) == 0 )
    goto LABEL_9;
  _X8 = (unsigned int *)v21 + 157;
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v76 = __ldxr(_X8);
    v77 = v76 - 1;
  }
  while ( __stlxr(v77, _X8) );
  __dmb(0xBu);
  if ( v77 )
  {
LABEL_9:
    result = (__int64 *)wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu);
    if ( result )
    {
      v31 = 0;
      v32 = result + 1;
      v33 = 1;
      v99 = result;
      do
      {
        if ( !(unsigned int)qdf_list_peek_front(&v32[3 * v31], v100) )
        {
          do
          {
            while ( 1 )
            {
              v42 = v100[0];
              if ( v100[0] == (_QWORD *)-24LL )
              {
                v45 = 0;
                v43 = 0;
                v44 = 0;
                v46 = 0;
              }
              else
              {
                v43 = *((unsigned __int8 *)v100[0] + 24);
                v44 = *((unsigned __int8 *)v100[0] + 25);
                v45 = *((unsigned __int8 *)v100[0] + 26);
                v46 = *((unsigned __int8 *)v100[0] + 29);
              }
              LODWORD(v98) = *(unsigned __int8 *)(a1 + 168);
              LODWORD(v97) = *((_DWORD *)v100[0] + 9);
              qdf_trace_msg(
                0,
                8u,
                "%s: Peer: %02x:%02x:%02x:**:**:%02x link status %d, vdev id %d",
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                "tdls_discovery_timeout_peer_cb",
                v43,
                v44,
                v45,
                v46,
                v97,
                v98);
              v55 = *((_DWORD *)v42 + 9);
              v33 = (v55 < 2) & (unsigned __int8)v33;
              if ( v55 != 1 )
                break;
              if ( v42 == (_QWORD *)-24LL )
              {
                v58 = 0;
                v56 = 0;
                v57 = 0;
                v59 = 0;
              }
              else
              {
                v56 = *((unsigned __int8 *)v42 + 24);
                v57 = *((unsigned __int8 *)v42 + 25);
                v58 = *((unsigned __int8 *)v42 + 26);
                v59 = *((unsigned __int8 *)v42 + 29);
              }
              qdf_trace_msg(
                0,
                8u,
                "%s: %02x:%02x:%02x:**:**:%02x to idle state",
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                "tdls_discovery_timeout_peer_cb",
                v56,
                v57,
                v58,
                v59);
              tdls_set_peer_link_status(v42, 0, 4294967294LL);
            }
          }
          while ( !(unsigned int)qdf_list_peek_next(&v32[3 * v31], v100[0], v100) );
        }
        ++v31;
      }
      while ( v31 != 16 );
      result = (__int64 *)wlan_vdev_mlme_is_mlo_vdev(a1, v34, v35, v36, v37, v38, v39, v40, v41);
      if ( ((unsigned int)result & v33 & 1) != 0 )
      {
        qdf_trace_msg(
          0,
          8u,
          "%s: try to set vdev %d to unforce",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "tdls_discovery_timeout_peer_cb",
          *(unsigned __int8 *)(a1 + 168));
        result = (__int64 *)tdls_set_link_unforce(a1);
      }
      *((_DWORD *)v99 + 192) = 0;
    }
    goto LABEL_27;
  }
  tdls_process_mlo_cal_tdls_link_score(a1);
  v78 = tdls_process_mlo_choice_tdls_vdev(a1);
  tdls_link_vdev = tdls_mlo_get_tdls_link_vdev(a1);
  if ( !tdls_link_vdev )
  {
    v60 = "%s: tdls link vdev is null";
    goto LABEL_25;
  }
  if ( !v78 )
  {
    qdf_trace_msg(0, 8u, "%s: no discovery response", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_discovery_timeout_peer_cb");
    goto LABEL_9;
  }
  v80 = tdls_link_vdev;
  result = (__int64 *)wlan_objmgr_vdev_get_comp_private_obj(v78, 0xAu);
  if ( result )
  {
    v89 = result;
    if ( v80 != v78 )
    {
      qdf_trace_msg(
        0,
        8u,
        "%s: tdls link created on vdev %d",
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        "tdls_discovery_timeout_peer_cb",
        *(unsigned __int8 *)(v80 + 168));
LABEL_52:
      result = (__int64 *)_qdf_mem_free(v89[119]);
      v89[119] = 0;
      *((_DWORD *)v89 + 240) = 0;
      goto LABEL_27;
    }
    v90 = result[119];
    if ( v90 )
    {
      if ( v90 == -30 )
      {
        v93 = 0;
        v91 = 0;
        v92 = 0;
        v94 = 0;
      }
      else
      {
        v91 = *(unsigned __int8 *)(v90 + 30);
        v92 = *(unsigned __int8 *)(v90 + 31);
        v93 = *(unsigned __int8 *)(v90 + 32);
        v94 = *(unsigned __int8 *)(v90 + 35);
      }
      qdf_trace_msg(
        0,
        4u,
        "%s: [TDLS] vdev:%d TDLS Discovery Response, %02x:%02x:%02x:**:**:%02x RSSI[%d]<---OTA",
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        "tdls_discovery_timeout_peer_cb",
        *(unsigned __int8 *)(*result + 168),
        v91,
        v92,
        v93,
        v94,
        *(_DWORD *)(v90 + 16));
      v95 = (void (__fastcall *)(__int64, __int64))v21[29];
      if ( v95 )
      {
        v96 = v21[30];
        if ( *((_DWORD *)v95 - 1) != -2109187 )
          __break(0x8228u);
        v95(v96, v90);
      }
      tdls_recv_discovery_resp(v89, v90 + 30);
      tdls_set_rssi(*v89, v90 + 30, *(unsigned int *)(v90 + 16));
      goto LABEL_52;
    }
    result = (__int64 *)qdf_trace_msg(
                          0,
                          8u,
                          "%s: vdev %d doesn't have discovery response cached",
                          v81,
                          v82,
                          v83,
                          v84,
                          v85,
                          v86,
                          v87,
                          v88,
                          "tdls_discovery_timeout_peer_cb",
                          *(unsigned __int8 *)(v80 + 168));
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
