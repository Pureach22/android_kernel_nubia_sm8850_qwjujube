__int64 __fastcall csr_continue_peer_disconnect_after_get_stats(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  const char *v12; // x2
  __int64 v14; // x22
  unsigned int v15; // w20
  __int64 active_cmd; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v26; // x4
  __int64 v27; // x6
  const void *v28; // x20
  int v29; // w10
  __int64 v30; // x4
  __int64 v31; // x5
  __int64 v32; // x7
  __int64 v33; // x22
  int v34; // w8
  __int64 v35; // x20
  __int64 v36; // x0
  __int64 v37; // x8
  int v38; // w10
  __int64 v39; // x9
  __int64 v40; // x10
  __int64 v41; // x22
  int v42; // w10
  __int64 v43; // x8
  __int16 v44; // w10
  unsigned int v45; // w0
  __int64 v46; // x4
  unsigned int v52; // w8
  signed int v53; // w8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(a1 + 21552));
  if ( !psoc_ext_obj_fl )
  {
    v12 = "%s: NULL mlme psoc object";
    return qdf_trace_msg(
             0x34u,
             2u,
             v12,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "csr_continue_peer_disconnect_after_get_stats");
  }
  v11 = psoc_ext_obj_fl;
  if ( (unsigned int)sme_acquire_global_lock(a1 + 12768) )
  {
    v12 = "%s: can't acquire sme global lock";
    return qdf_trace_msg(
             0x34u,
             2u,
             v12,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "csr_continue_peer_disconnect_after_get_stats");
  }
  v14 = v11 + 4096;
  v15 = *(unsigned __int8 *)(v11 + 7432);
  active_cmd = wlan_serialization_get_active_cmd(*(_QWORD *)(a1 + 21552), v15, 3u, v3, v4, v5, v6, v7, v8, v9, v10);
  if ( !active_cmd )
  {
    active_cmd = wlan_serialization_get_active_cmd(
                   *(_QWORD *)(a1 + 21552),
                   v15,
                   2u,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24);
    if ( !active_cmd )
    {
      active_cmd = wlan_serialization_get_active_cmd(
                     *(_QWORD *)(a1 + 21552),
                     v15,
                     5u,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     v23,
                     v24);
      if ( !active_cmd )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: sme_cmd is NULL",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "csr_continue_peer_disconnect_after_get_stats");
        return sme_release_global_lock(a1 + 12768);
      }
    }
  }
  _X9 = (unsigned int *)(v14 + 3340);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v52 = __ldxr(_X9);
    v53 = v52 + 1;
  }
  while ( __stlxr(v53, _X9) );
  __dmb(0xBu);
  v26 = *(unsigned int *)(active_cmd + 16);
  if ( v53 < 2 )
  {
    if ( (_DWORD)v26 != 65538 )
    {
      if ( (_DWORD)v26 == 65537 )
      {
        v28 = (const void *)(active_cmd + 36);
        v27 = *(unsigned __int8 *)(active_cmd + 36);
        v29 = *(_DWORD *)(active_cmd + 32);
        v30 = *(unsigned int *)(active_cmd + 24);
        v31 = *(unsigned int *)(active_cmd + 48);
        v32 = *(unsigned __int8 *)(active_cmd + 37);
        if ( v29 == 2 )
        {
          v41 = active_cmd;
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Deauth vdev_id %d with reason: %d peer %02x:%02x:%02x:**:**:%02x",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "csr_process_deauth_disassoc_cmd",
            v30,
            v31,
            v27,
            v32,
            *(unsigned __int8 *)(active_cmd + 38),
            *(unsigned __int8 *)(active_cmd + 41));
          csr_send_mb_deauth_req_msg(a1, *(_DWORD *)(v41 + 24), v28, *(_DWORD *)(v41 + 48));
        }
        else if ( v29 == 1 )
        {
          v33 = active_cmd;
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Disassoc vdev_id %d with reason: %d peer %02x:%02x:%02x:**:**:%02x",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "csr_process_deauth_disassoc_cmd",
            v30,
            v31,
            v27,
            v32,
            *(unsigned __int8 *)(active_cmd + 38),
            *(unsigned __int8 *)(active_cmd + 41));
          csr_send_mb_disassoc_req_msg(a1, *(_DWORD *)(v33 + 24), v28, *(_DWORD *)(v33 + 48));
        }
        else
        {
          qdf_trace_msg(
            0x34u,
            4u,
            "%s: Invalid command, vdev_id %d reason: %d peer %02x:%02x:%02x:**:**:%02x",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "csr_process_deauth_disassoc_cmd",
            v30,
            v31,
            v27,
            v32,
            *(unsigned __int8 *)(active_cmd + 38),
            *(unsigned __int8 *)(active_cmd + 41));
        }
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          4u,
          "%s: Invalid command %d vdev_id %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "csr_continue_peer_disconnect_after_get_stats",
          v26,
          *(unsigned __int8 *)(v14 + 3336));
      }
      return sme_release_global_lock(a1 + 12768);
    }
    v34 = *(_DWORD *)(active_cmd + 32);
    v35 = active_cmd;
    if ( v34 == 1 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: vdev_id %d type %d ",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "csr_roam_lost_link",
        *(unsigned int *)(active_cmd + 24),
        5134);
      v36 = _qdf_mem_malloc(0x18u, "csr_send_mb_deauth_cnf_msg", 6253);
      if ( v36 )
      {
        *(_DWORD *)(v36 + 8) = 0;
        *(_DWORD *)v36 = 1578010;
        v37 = v35;
        *(_BYTE *)(v36 + 4) = *(_BYTE *)(v35 + 40);
        v42 = *(_DWORD *)(v35 + 48);
        *(_WORD *)(v36 + 16) = *(_WORD *)(v35 + 52);
        v39 = v36 + 18;
        *(_DWORD *)(v36 + 12) = v42;
        v40 = 54;
LABEL_26:
        v43 = v37 + v40;
        v44 = *(_WORD *)(v43 + 4);
        LODWORD(v43) = *(_DWORD *)v43;
        *(_WORD *)(v39 + 4) = v44;
        *(_DWORD *)v39 = v43;
        v45 = umac_send_mb_message_to_mac(v36);
        v46 = v45;
        if ( !v45 )
          return sme_release_global_lock(a1 + 12768);
        goto LABEL_31;
      }
    }
    else
    {
      if ( v34 )
      {
        v46 = 16;
LABEL_31:
        qdf_trace_msg(
          0x34u,
          4u,
          "%s: Failed to issue lost link command, status %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "csr_process_wmm_status_change_cmd",
          v46);
        csr_roam_wm_status_change_complete(a1, *(_DWORD *)(v35 + 24));
        return sme_release_global_lock(a1 + 12768);
      }
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: vdev_id %d type %d ",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "csr_roam_lost_link",
        *(unsigned int *)(active_cmd + 24),
        5130);
      v36 = _qdf_mem_malloc(0x18u, "csr_send_mb_disassoc_cnf_msg", 6215);
      if ( v36 )
      {
        *(_DWORD *)(v36 + 8) = 0;
        *(_DWORD *)v36 = 1577995;
        v37 = v35;
        *(_BYTE *)(v36 + 4) = *(_BYTE *)(v35 + 40);
        v38 = *(_DWORD *)(v35 + 54);
        *(_WORD *)(v36 + 22) = *(_WORD *)(v35 + 58);
        v39 = v36 + 12;
        *(_DWORD *)(v36 + 18) = v38;
        v40 = 48;
        goto LABEL_26;
      }
    }
    v46 = 2;
    goto LABEL_31;
  }
  qdf_trace_msg(
    0x34u,
    4u,
    "%s: Command %d already in process",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "csr_continue_peer_disconnect_after_get_stats",
    v26);
  return sme_release_global_lock(a1 + 12768);
}
