__int64 __fastcall ttlm_subst_link_recfg_update_mapping_inprogress_event(
        __int64 a1,
        __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  __int64 v12; // x20
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x3
  __int64 first_vdev_by_ml_peer; // x0
  __int64 bsspeer; // x0
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v44; // x2
  const char *v45; // x3
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  const char *v54; // x3

  if ( a2 == 13 )
  {
    if ( a1 )
    {
      first_vdev_by_ml_peer = mlo_get_first_vdev_by_ml_peer(a1);
      if ( first_vdev_by_ml_peer )
      {
        v12 = first_vdev_by_ml_peer;
        bsspeer = wlan_objmgr_vdev_try_get_bsspeer(first_vdev_by_ml_peer, 0x5Au);
        if ( bsspeer )
        {
          v22 = bsspeer;
          if ( (unsigned int)t2lm_deliver_event(v12, bsspeer, 7, 0, 0, 0) )
          {
            v31 = "ttlm_handle_link_recfg_add_mapping_update";
            goto LABEL_13;
          }
LABEL_14:
          wlan_objmgr_peer_release_ref(v22, 0x5Au, v23, v24, v25, v26, v27, v28, v29, v30);
LABEL_26:
          wlan_objmgr_vdev_release_ref(v12, 0x5Au, v34, v35, v36, v37, v38, v39, v40, v41, v42);
          goto LABEL_27;
        }
        v54 = "ttlm_handle_link_recfg_add_mapping_update";
LABEL_25:
        qdf_trace_msg(0x99u, 2u, "%s: peer is null", v14, v15, v16, v17, v18, v19, v20, v21, v54);
        goto LABEL_26;
      }
      v44 = "%s: VDEV is null";
    }
    else
    {
      v44 = "%s: ml_peer is null";
    }
    v45 = "ttlm_handle_link_recfg_add_mapping_update";
  }
  else
  {
    if ( a2 != 12 )
      return 0;
    if ( a1 )
    {
      v11 = mlo_get_first_vdev_by_ml_peer(a1);
      if ( v11 )
      {
        v12 = v11;
        v13 = wlan_objmgr_vdev_try_get_bsspeer(v11, 0x5Au);
        if ( v13 )
        {
          v22 = v13;
          if ( (unsigned int)t2lm_deliver_event(v12, v13, 6, 0, 0, 0) )
          {
            v31 = "ttlm_handle_link_recfg_del_mapping_update";
LABEL_13:
            qdf_trace_msg(0x99u, 2u, "%s: T2LM update peer mapping failed", v23, v24, v25, v26, v27, v28, v29, v30, v31);
            goto LABEL_14;
          }
          goto LABEL_14;
        }
        v54 = "ttlm_handle_link_recfg_del_mapping_update";
        goto LABEL_25;
      }
      v44 = "%s: VDEV is null";
    }
    else
    {
      v44 = "%s: ml_peer is null";
    }
    v45 = "ttlm_handle_link_recfg_del_mapping_update";
  }
  qdf_trace_msg(0x99u, 2u, v44, a3, a4, a5, a6, a7, a8, a9, a10, v45);
LABEL_27:
  wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 2u, v46, v47, v48, v49, v50, v51, v52, v53);
  return 1;
}
