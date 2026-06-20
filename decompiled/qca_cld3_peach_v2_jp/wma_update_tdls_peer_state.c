__int64 __fastcall wma_update_tdls_peer_state(
        __int64 *a1,
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
  _QWORD *context; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w23
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x0
  __int64 v40; // x22
  unsigned __int64 v41; // x8
  int *v42; // x9
  int v43; // t1
  __int64 v44; // x8
  _DWORD *v45; // x8
  __int64 v46; // x1
  _BOOL8 v47; // x3
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w8
  char is_vdev_restore_last_peer; // w24
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7

  context = _cds_get_context(71, (__int64)"wma_update_tdls_peer_state", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (unsigned int)_wma_validate_handle(a1, "wma_update_tdls_peer_state") )
  {
    v21 = -22;
    goto LABEL_3;
  }
  v21 = -22;
  if ( (unsigned int)_wmi_validate_handle(
                       *a1,
                       (__int64)"wma_update_tdls_peer_state",
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20)
    || !context )
  {
LABEL_3:
    if ( a2 )
      _qdf_mem_free((__int64)a2);
    return v21;
  }
  if ( wlan_cm_is_roam_sync_in_progress(a1[3], *a2) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: roaming in progress, reject peer update cmd!",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wma_update_tdls_peer_state");
    v21 = -1;
    goto LABEL_3;
  }
  if ( ((unsigned __int8)wma_objmgr_peer_exist((__int64)a1, (__int64)(a2 + 1), nullptr) & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: peer:%02x:%02x:%02x:**:**:%02xdoesn't exist",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "wma_update_tdls_peer_state",
      *((unsigned __int8 *)a2 + 4),
      *((unsigned __int8 *)a2 + 5),
      *((unsigned __int8 *)a2 + 6),
      *((unsigned __int8 *)a2 + 9));
    goto LABEL_3;
  }
  if ( a2[3] != 1 )
    qdf_mem_set(a2 + 4, 0x430u, 0);
  if ( !*((_BYTE *)a2 + 23) )
  {
    v40 = 0;
    goto LABEL_22;
  }
  v39 = _qdf_mem_malloc(4LL * *((unsigned __int8 *)a2 + 23), "wma_update_tdls_peer_state", 4752);
  if ( !v39 )
  {
    v21 = -12;
    goto LABEL_3;
  }
  v40 = v39;
  if ( !*((_BYTE *)a2 + 23) )
  {
LABEL_22:
    if ( *context && (v44 = *(_QWORD *)(*context + 72LL)) != 0 )
    {
      v45 = *(_DWORD **)(v44 + 160);
      if ( v45 )
      {
        v46 = *a2;
        v47 = *((_BYTE *)a2 + 20) != 0;
        if ( *(v45 - 1) != 1361958049 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, __int64, unsigned int *, _BOOL8))v45)(context, v46, a2 + 1, v47);
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        1u,
        "%s invalid instance",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "cdp_peer_set_tdls_offchan_enabled");
    }
    if ( (unsigned int)wmi_unified_update_tdls_peer_state_cmd(*a1, a2, v40) )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: failed to send tdls peer update state command",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "wma_update_tdls_peer_state");
      v21 = -5;
    }
    else
    {
      v21 = 0;
    }
    v56 = a2[3];
    if ( v56 == 2 )
    {
      is_vdev_restore_last_peer = cdp_peer_is_vdev_restore_last_peer(context, *a2, a2 + 1);
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: calling wma_remove_peer for peer %02x:%02x:%02x:**:**:%02x vdevId: %d",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "wma_update_tdls_peer_state",
        *((unsigned __int8 *)a2 + 4),
        *((unsigned __int8 *)a2 + 5),
        *((unsigned __int8 *)a2 + 6),
        *((unsigned __int8 *)a2 + 9),
        *a2);
      if ( (unsigned int)wma_remove_peer(a1, a2 + 1, *a2, 0, v66, v67, v68, v69, v70, v71, v72, v73) )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: wma_remove_peer failed",
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          "wma_update_tdls_peer_state");
        v21 = -22;
      }
      cdp_peer_update_last_real_peer(context, *a2, is_vdev_restore_last_peer & 1);
      if ( a2[3] != 1 )
      {
LABEL_34:
        if ( !v40 )
          goto LABEL_3;
        goto LABEL_40;
      }
    }
    else if ( v56 != 1 )
    {
      goto LABEL_34;
    }
    cdp_peer_state_update_0(context, a2 + 1);
    if ( !v40 )
      goto LABEL_3;
LABEL_40:
    _qdf_mem_free(v40);
    goto LABEL_3;
  }
  v41 = 0;
  v42 = (int *)(a2 + 6);
  while ( v41 != 128 )
  {
    v43 = *v42;
    v42 += 2;
    *(_DWORD *)(v39 + 4 * v41++) = v43;
    if ( v41 >= *((unsigned __int8 *)a2 + 23) )
      goto LABEL_22;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))cdp_peer_is_vdev_restore_last_peer)();
}
