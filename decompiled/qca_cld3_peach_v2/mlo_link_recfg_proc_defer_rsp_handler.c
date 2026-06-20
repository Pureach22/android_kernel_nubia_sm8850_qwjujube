__int64 __fastcall mlo_link_recfg_proc_defer_rsp_handler(
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
  unsigned int v9; // w22
  __int64 v11; // x8
  unsigned __int64 v12; // x26
  unsigned int state; // w20
  const char *v14; // x2
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int *v34; // x8
  __int64 v35; // x21
  unsigned __int64 v36; // x27
  unsigned __int8 *v37; // x28
  unsigned __int8 *ap_link_by_link_id; // x0
  unsigned __int8 *v39; // x24
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  const char *v48; // x2
  unsigned __int64 v49; // x21
  int link_status; // w0
  unsigned int v51; // w8
  int v52; // w0
  unsigned int v53; // w8
  int v54; // w0
  unsigned int v55; // w8
  unsigned int updated; // w0
  __int64 v57; // x23
  __int64 v58; // x21
  __int64 v59; // x8
  _DWORD *v60; // x22
  unsigned int v61; // w20
  __int64 v62; // x8
  _DWORD *v63; // x10
  int v64; // w9
  __int64 v65; // x8
  _DWORD *v66; // x10
  int v67; // w9
  const char *v68; // x2
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x0
  __int64 v78; // x20
  __int64 v79; // x21
  _QWORD *done; // x0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  char v89; // w0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  const char *v98; // x2
  double v99; // d0
  unsigned int *v100; // x8
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  int v108; // w9

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    state = 4;
LABEL_11:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: RX response handler failure status %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlo_link_recfg_response_received",
      state);
    goto LABEL_12;
  }
  v9 = *(char *)(a1 + 3024);
  if ( v9 >= 7 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: unexpected curr_state_idx %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlo_link_recfg_get_curr_tran_req",
      v9);
    goto LABEL_9;
  }
  v11 = a1 + 312LL * *(char *)(a1 + 3024);
  v12 = v11 + 840;
  if ( v11 == -840 )
  {
LABEL_9:
    state = 4;
    v14 = "%s: curr tran ctx null";
    goto LABEL_10;
  }
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 3288) == 21 && (unsigned int)qdf_mc_timer_stop(a1 + 3288) )
  {
    state = 16;
    v14 = "%s: Failed to stop the Link Recfg rsp timer";
LABEL_10:
    qdf_trace_msg(0x8Fu, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "mlo_link_recfg_response_handler");
    goto LABEL_11;
  }
  qdf_trace_msg(0x8Fu, 8u, "%s: RX response success", a2, a3, a4, a5, a6, a7, a8, a9, "mlo_link_recfg_response_handler");
  v24 = *(_QWORD *)(a1 + 8);
  if ( !v24 )
  {
    v48 = "%s: mlo_ctx null";
LABEL_32:
    qdf_trace_msg(
      0x8Fu,
      2u,
      v48,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "mlo_link_recfg_remove_deleted_standby_in_mlo_mgr");
    goto LABEL_33;
  }
  if ( !*(_QWORD *)a1 )
  {
    v48 = "%s: psoc is null";
    goto LABEL_32;
  }
  v25 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)a1,
          *(unsigned __int8 *)(a1 + 16),
          108);
  if ( !v25 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Invalid link recfg VDEV %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "mlo_link_recfg_remove_deleted_standby_in_mlo_mgr",
      *(unsigned __int8 *)(a1 + 16));
LABEL_33:
    if ( a1 + 3024 > v12 )
    {
      v49 = v12;
      while ( *(_DWORD *)v49 != 5 )
      {
        if ( *(_BYTE *)(v49 + 128) )
        {
          link_status = mlo_link_recfg_find_link_status(*(unsigned __int8 *)(v49 + 9), a1 + 576);
          v51 = *(unsigned __int8 *)(v49 + 128);
          *(_DWORD *)(v49 + 28) = link_status;
          if ( v51 >= 2 )
          {
            v52 = mlo_link_recfg_find_link_status(*(unsigned __int8 *)(v49 + 49), a1 + 576);
            v53 = *(unsigned __int8 *)(v49 + 128);
            *(_DWORD *)(v49 + 68) = v52;
            if ( v53 >= 3 )
            {
              v54 = mlo_link_recfg_find_link_status(*(unsigned __int8 *)(v49 + 89), a1 + 576);
              v55 = *(unsigned __int8 *)(v49 + 128);
              *(_DWORD *)(v49 + 108) = v54;
              if ( v55 > 3 )
                goto LABEL_41;
            }
          }
        }
        v49 += 312LL;
        if ( v49 >= a1 + 3024 )
          goto LABEL_42;
      }
    }
    goto LABEL_42;
  }
  v34 = (unsigned int *)*(unsigned __int8 *)(v12 + 256);
  v35 = v25;
  if ( !*(_BYTE *)(v12 + 256) )
  {
LABEL_30:
    wlan_objmgr_vdev_release_ref(v35, 0x6Cu, v34, v26, v27, v28, v29, v30, v31, v32, v33);
    goto LABEL_33;
  }
  v36 = 0;
  v37 = (unsigned __int8 *)(a1 + 312LL * (int)v9 + 977);
  while ( v36 != 3 )
  {
    ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(v24, *v37);
    if ( ap_link_by_link_id )
    {
      if ( (*((_QWORD *)ap_link_by_link_id + 2) & 1) != 0 )
      {
        if ( ap_link_by_link_id[12] == 255 )
        {
          v39 = ap_link_by_link_id;
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: del standby link %d flag 0x%x vdev id %d from mlo mgr",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "mlo_link_recfg_remove_deleted_standby_in_mlo_mgr",
            *v37);
          mlo_link_recfg_update_scan_mlme(v35, v39 + 24, 0);
          mlo_mgr_clear_ap_link_info(v35, (__int64)(v39 + 24));
          ml_nlink_update_force_state_on_link_delete(v35, *v37, v40, v41, v42, v43, v44, v45, v46, v47);
        }
        else
        {
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: skip deleted non standby link %d on vdev %d",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "mlo_link_recfg_remove_deleted_standby_in_mlo_mgr",
            *v37,
            ap_link_by_link_id[12]);
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: link info null for link id %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "mlo_link_recfg_remove_deleted_standby_in_mlo_mgr",
        *v37);
    }
    v34 = (unsigned int *)*(unsigned __int8 *)(v12 + 256);
    ++v36;
    v37 += 40;
    if ( v36 >= (unsigned __int64)v34 )
      goto LABEL_30;
  }
LABEL_41:
  __break(0x5512u);
LABEL_42:
  updated = mlo_link_recfg_update_added_link_in_mlo_mgr(a1, v12 + 8);
  if ( updated )
  {
    state = updated;
    v14 = "%s: RX response failure";
    goto LABEL_10;
  }
  v57 = *(_QWORD *)(a1 + 8);
  if ( !v57 )
  {
    v68 = "%s: mlo_ctx null";
LABEL_63:
    qdf_trace_msg(0x8Fu, 2u, v68, a2, a3, a4, a5, a6, a7, a8, a9, "mlo_link_recfg_update_partner_info");
    goto LABEL_64;
  }
  v58 = *(_QWORD *)(v57 + 2224);
  if ( !v58 )
  {
    v68 = "%s: sta_ctx null";
    goto LABEL_63;
  }
  v59 = *(_QWORD *)(v57 + 3880);
  v60 = (_DWORD *)(v58 + 1176);
  if ( !(*(_DWORD *)(v59 + 24) | *(unsigned __int16 *)(v59 + 28))
    || *(unsigned __int8 *)(v59 + 6) == 255
    || *(_DWORD *)(v59 + 44) )
  {
    v61 = 0;
  }
  else
  {
    v108 = *(_DWORD *)(v59 + 24);
    *(_WORD *)(v58 + 1180) = *(_WORD *)(v59 + 28);
    *v60 = v108;
    *(_BYTE *)(v58 + 1182) = *(_BYTE *)(v59 + 6);
    *(_BYTE *)(v58 + 1188) = *(_BYTE *)(v59 + 12);
    *(_DWORD *)(v58 + 1220) = *(_DWORD *)(v59 + 44);
    *(_WORD *)(v58 + 1186) = **(_WORD **)(v59 + 32);
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: [%d] update partner link id %d vdev %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlo_link_recfg_update_partner_info",
      0);
    v61 = 1;
  }
  v62 = *(_QWORD *)(v57 + 3880);
  if ( *(_DWORD *)(v62 + 72) | *(unsigned __int16 *)(v62 + 76)
    && *(unsigned __int8 *)(v62 + 54) != 255
    && !*(_DWORD *)(v62 + 92) )
  {
    v63 = &v60[12 * v61];
    v64 = *(_DWORD *)(v62 + 72);
    *((_WORD *)v63 + 2) = *(_WORD *)(v62 + 76);
    *v63 = v64;
    *((_BYTE *)v63 + 6) = *(_BYTE *)(v62 + 54);
    *((_BYTE *)v63 + 12) = *(_BYTE *)(v62 + 60);
    v63[11] = *(_DWORD *)(v62 + 92);
    *((_WORD *)v63 + 5) = **(_WORD **)(v62 + 80);
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: [%d] update partner link id %d vdev %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlo_link_recfg_update_partner_info",
      v61++);
  }
  if ( v61 <= 2 )
  {
    v65 = *(_QWORD *)(v57 + 3880);
    if ( *(_DWORD *)(v65 + 120) | *(unsigned __int16 *)(v65 + 124) )
    {
      if ( *(unsigned __int8 *)(v65 + 102) != 255 && !*(_DWORD *)(v65 + 140) )
      {
        v66 = &v60[12 * v61];
        v67 = *(_DWORD *)(v65 + 120);
        *((_WORD *)v66 + 2) = *(_WORD *)(v65 + 124);
        *v66 = v67;
        *((_BYTE *)v66 + 6) = *(_BYTE *)(v65 + 102);
        *((_BYTE *)v66 + 12) = *(_BYTE *)(v65 + 108);
        v66[11] = *(_DWORD *)(v65 + 140);
        *((_WORD *)v66 + 5) = **(_WORD **)(v65 + 128);
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: [%d] update partner link id %d vdev %d",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "mlo_link_recfg_update_partner_info",
          v61);
        LOBYTE(v61) = v61 + 1;
      }
    }
  }
  *(_BYTE *)(v58 + 1168) = v61;
LABEL_64:
  ((void (__fastcall *)(__int64, unsigned __int64))mlo_link_recfg_store_key)(a1, v12 + 8);
  if ( !*(_QWORD *)a1 )
  {
    v98 = "%s: psoc is null";
LABEL_71:
    qdf_trace_msg(0x8Fu, 2u, v98, v69, v70, v71, v72, v73, v74, v75, v76, "mlo_link_recfg_send_status");
    goto LABEL_74;
  }
  if ( *(_BYTE *)(a1 + 574) == 1 )
  {
    v77 = ((__int64 (*)(void))wlan_objmgr_get_vdev_by_id_from_psoc)();
    if ( v77 )
    {
      v78 = v77;
      v79 = *(_QWORD *)(*(_QWORD *)(v77 + 1360) + 3888LL);
      done = (_QWORD *)mlme_cm_populate_link_recfg_done_data();
      if ( done )
      {
        qdf_list_insert_back((_QWORD *)(v79 + 4080), done);
        v89 = queue_work_on(32, system_wq, v79 + 4032);
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: sched recfg work %d",
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          "mlo_link_refg_done_indication",
          v89 & 1);
      }
      else
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: fail to populate recfg done data",
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          "mlo_link_refg_done_indication");
      }
      *(_BYTE *)(a1 + 574) = 0;
      qdf_mem_set((void *)(a1 + 152), 0x28u, 0);
      *(_BYTE *)(a1 + 272) = 0;
      v99 = mlo_link_recfg_ctx_free_ies(a1);
      wlan_objmgr_vdev_release_ref(v78, 0x5Au, v100, v99, v101, v102, v103, v104, v105, v106, v107);
      goto LABEL_74;
    }
    v98 = "%s: link vdev is null";
    goto LABEL_71;
  }
LABEL_74:
  state = mlo_link_recfg_tranistion_to_next_state(a1);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  if ( state )
    return state;
  else
    return 6;
}
