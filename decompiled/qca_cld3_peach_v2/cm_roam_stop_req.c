__int64 __fastcall cm_roam_stop_req(__int64 a1, __int64 a2, unsigned int a3, unsigned __int8 *a4, char a5)
{
  unsigned int v8; // w20
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x22
  unsigned int *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x0
  unsigned int *v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned __int8 *v67; // x22
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int *v76; // x8
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x26
  int v86; // w8
  char v87; // w8
  unsigned __int8 v88; // w25
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  unsigned int *v97; // x8
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned int v106; // w25
  int v107; // w26
  __int64 psoc_ext_obj_fl; // x0
  __int64 v109; // x24
  int v110; // w8

  v8 = a2;
  v10 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v10 )
  {
    v19 = v10;
    if ( (mlo_is_link_recfg_in_progress(v10) & 1) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: skip RSO cmd for vdev %d due to link recfg is in progress",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "cm_roam_stop_req",
        (unsigned __int8)v8);
      wlan_objmgr_vdev_release_ref(v19, 0x4Du, v28, v29, v30, v31, v32, v33, v34, v35, v36);
      return 16;
    }
    mlme_clear_rso_pending_disable_req_bitmap(a1, v8);
    v38 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v8, 2);
    if ( v38 )
    {
      v47 = v38;
      mlme_set_roam_reason_better_ap(v38, 0, v39, v40, v41, v42, v43, v44, v45, v46);
      wlan_objmgr_vdev_release_ref(v47, 2u, v48, v49, v50, v51, v52, v53, v54, v55, v56);
    }
    v57 = _qdf_mem_malloc(0xF58u, "cm_roam_stop_req", 3945);
    if ( !v57 )
    {
      wlan_objmgr_vdev_release_ref(v19, 0x4Du, v58, v59, v60, v61, v62, v63, v64, v65, v66);
      return 2;
    }
    v67 = (unsigned __int8 *)v57;
    if ( (wlan_vdev_mlme_get_is_mlo_link(a1, v8) & 1) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: MLO ROAM: skip RSO cmd for link vdev %d",
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        "cm_roam_stop_req",
        (unsigned __int8)v8);
    }
    else if ( wlan_cm_get_rso_config_fl(v19, "cm_roam_stop_req", 3956) )
    {
      v85 = *(_QWORD *)(v19 + 216);
      if ( v85 )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev:%d process rso stop for reason: %d",
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          "cm_roam_stop_req",
          (unsigned __int8)v8,
          (unsigned __int8)a3);
        v67[2028] = v8;
        if ( (unsigned __int8)a3 == 39 )
        {
          v86 = *((_DWORD *)v67 + 508);
          *((_DWORD *)v67 + 888) = (unsigned __int8)v8;
          *((_DWORD *)v67 + 891) = (unsigned __int8)v8;
          *((_DWORD *)v67 + 898) = (unsigned __int8)v8;
          *((_DWORD *)v67 + 508) = v86 | 1;
          v87 = 39;
          v67[3840] = v8;
          *((_DWORD *)v67 + 490) = (unsigned __int8)v8;
        }
        else
        {
          *((_DWORD *)v67 + 888) = (unsigned __int8)v8;
          *((_DWORD *)v67 + 891) = (unsigned __int8)v8;
          *((_DWORD *)v67 + 898) = (unsigned __int8)v8;
          v67[3840] = v8;
          *((_DWORD *)v67 + 490) = (unsigned __int8)v8;
          if ( (unsigned __int8)a3 == 36 )
          {
            v87 = 36;
          }
          else if ( (a3 & 0xF7) == 0x30 )
          {
            v87 = 38;
          }
          else if ( (unsigned __int8)a3 > 0x36u || (v87 = a3, ((1LL << a3) & 0x40000000008010LL) == 0) )
          {
            v87 = 42;
          }
        }
        v88 = a5 & 1;
        *v67 = v87;
        if ( (wlan_cm_host_roam_in_progress(a1, v8) & 1) != 0 )
          v67[1] = 1;
        if ( a4 )
          v67[3924] = *a4;
        v67[3925] = v88;
        if ( (unsigned int)mlme_get_roam_state(a1, v8) == 5 && *v67 == 38 )
        {
          qdf_trace_msg(
            0x68u,
            4u,
            "%s: vdev_id:%d : Drop RSO stop during roam sync",
            v89,
            v90,
            v91,
            v92,
            v93,
            v94,
            v95,
            v96,
            "cm_roam_stop_req",
            (unsigned __int8)v8);
          wlan_objmgr_vdev_release_ref(v19, 0x4Du, v97, v98, v99, v100, v101, v102, v103, v104, v105);
          _qdf_mem_free((__int64)v67);
          return 16;
        }
        wlan_mlme_defer_pmk_set_in_roaming(a1, v8, 0);
        cm_roam_scan_filter(a1, v85, v8, 2, a3, v67 + 2064);
        v106 = *v67;
        v107 = *(unsigned __int8 *)(v19 + 168);
        psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
        if ( psoc_ext_obj_fl )
        {
          v109 = psoc_ext_obj_fl;
          qdf_mem_set(v67 + 4, 0x7A4u, 0);
          *((_DWORD *)v67 + 1) = v107;
          v67[8] = 1;
          v67[9] = *(_BYTE *)(v109 + 2132);
          *((_DWORD *)v67 + 4) = *(unsigned __int8 *)(v109 + 2092);
          *((_DWORD *)v67 + 5) = *(_DWORD *)(v109 + 2096);
          if ( v106 > 0x36 || (v110 = 0, ((1LL << v106) & 0x40005000000010LL) == 0) )
          {
            if ( *(_BYTE *)(v109 + 1714) )
              v110 = 4;
            else
              v110 = 0;
          }
          *((_DWORD *)v67 + 3) = v110;
        }
        if ( (unsigned int)wlan_cm_tgt_send_roam_stop_req(a1, v8, v67) )
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: fail to send roam stop",
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            "cm_roam_stop_req");
        if ( a4 )
        {
          v76 = (unsigned int *)v67[3924];
          *a4 = (unsigned __int8)v76;
        }
      }
    }
    wlan_objmgr_vdev_release_ref(v19, 0x4Du, v76, v77, v78, v79, v80, v81, v82, v83, v84);
    _qdf_mem_free((__int64)v67);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL for vdev %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "cm_roam_stop_req",
      (unsigned __int8)v8);
  }
  return 0;
}
