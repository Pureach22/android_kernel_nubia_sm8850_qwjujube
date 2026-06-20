__int64 __fastcall cm_roam_stop_req(__int64 a1, __int64 a2, unsigned int a3, unsigned __int8 *a4, char a5)
{
  unsigned int v8; // w21
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
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x23
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x0
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned __int8 *v49; // x23
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x26
  char v60; // w8
  unsigned __int8 v62; // w25
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned int *v71; // x8
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int v80; // w25
  int v81; // w26
  __int64 psoc_ext_obj_fl; // x0
  __int64 v83; // x24
  int v84; // w8

  v8 = a2;
  v10 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v10 )
  {
    v19 = v10;
    mlme_clear_rso_pending_disable_req_bitmap(a1, v8);
    v20 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v8, 2);
    if ( v20 )
    {
      v29 = v20;
      mlme_set_roam_reason_better_ap(v20, 0, v21, v22, v23, v24, v25, v26, v27, v28);
      wlan_objmgr_vdev_release_ref(v29, 2u, v30, v31, v32, v33, v34, v35, v36, v37, v38);
    }
    v39 = _qdf_mem_malloc(0xD78u, "cm_roam_stop_req", 3945);
    if ( !v39 )
    {
      wlan_objmgr_vdev_release_ref(v19, 0x4Du, v40, v41, v42, v43, v44, v45, v46, v47, v48);
      return 2;
    }
    v49 = (unsigned __int8 *)v39;
    if ( wlan_cm_get_rso_config_fl(v19, "cm_roam_stop_req", 3956) )
    {
      v59 = *(_QWORD *)(v19 + 152);
      if ( v59 )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev:%d process rso stop for reason: %d",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "cm_roam_stop_req",
          (unsigned __int8)v8,
          (unsigned __int8)a3);
        v49[2028] = v8;
        *((_DWORD *)v49 + 768) = (unsigned __int8)v8;
        *((_DWORD *)v49 + 771) = (unsigned __int8)v8;
        *((_DWORD *)v49 + 778) = (unsigned __int8)v8;
        v49[3360] = v8;
        *((_DWORD *)v49 + 490) = (unsigned __int8)v8;
        if ( (unsigned __int8)a3 == 36 )
        {
          v60 = 36;
        }
        else if ( (a3 & 0xF7) == 0x30 )
        {
          v60 = 38;
        }
        else if ( (unsigned __int8)a3 > 0x36u || (v60 = a3, ((1LL << a3) & 0x40008000008010LL) == 0) )
        {
          v60 = 42;
        }
        v62 = a5 & 1;
        *v49 = v60;
        if ( (wlan_cm_host_roam_in_progress(a1, v8) & 1) != 0 )
          v49[1] = 1;
        if ( a4 )
          v49[3444] = *a4;
        v49[3445] = v62;
        if ( (unsigned int)mlme_get_roam_state(a1, v8) == 5 && *v49 == 38 )
        {
          qdf_trace_msg(
            0x68u,
            4u,
            "%s: vdev_id:%d : Drop RSO stop during roam sync",
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            "cm_roam_stop_req",
            (unsigned __int8)v8);
          wlan_objmgr_vdev_release_ref(v19, 0x4Du, v71, v72, v73, v74, v75, v76, v77, v78, v79);
          _qdf_mem_free((__int64)v49);
          return 16;
        }
        wlan_mlme_defer_pmk_set_in_roaming(a1, v8, 0);
        cm_roam_scan_filter(a1, v59, v8, 2, a3, v49 + 2064);
        v80 = *v49;
        v81 = *(unsigned __int8 *)(v19 + 104);
        psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
        if ( psoc_ext_obj_fl )
        {
          v83 = psoc_ext_obj_fl;
          qdf_mem_set(v49 + 4, 0x7A4u, 0);
          *((_DWORD *)v49 + 1) = v81;
          v49[8] = 1;
          v49[9] = *(_BYTE *)(v83 + 1928);
          *((_DWORD *)v49 + 4) = *(unsigned __int8 *)(v83 + 1888);
          *((_DWORD *)v49 + 5) = *(_DWORD *)(v83 + 1892);
          if ( v80 > 0x36 || (v84 = 0, ((1LL << v80) & 0x40005000000010LL) == 0) )
          {
            if ( *(_BYTE *)(v83 + 1510) )
              v84 = 4;
            else
              v84 = 0;
          }
          *((_DWORD *)v49 + 3) = v84;
        }
        if ( (unsigned int)wlan_cm_tgt_send_roam_stop_req(a1, v8, v49) )
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: fail to send roam stop",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "cm_roam_stop_req");
        if ( a4 )
        {
          v50 = (unsigned int *)v49[3444];
          *a4 = (unsigned __int8)v50;
        }
      }
    }
    wlan_objmgr_vdev_release_ref(v19, 0x4Du, v50, v51, v52, v53, v54, v55, v56, v57, v58);
    _qdf_mem_free((__int64)v49);
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
