__int64 __fastcall wlan_cm_send_connect_rsp(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x21
  __int64 bsspeer; // x0
  __int64 v13; // x22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int *v30; // x8
  unsigned int v31; // w22
  __int64 v33; // x0

  if ( !a1 )
    return 16;
  v1 = *(_QWORD *)(a1 + 8);
  if ( !v1 )
    return 16;
  v2 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)v1,
         *(unsigned __int8 *)(v1 + 8),
         77);
  if ( v2 )
  {
    v11 = v2;
    if ( *(_DWORD *)(v1 + 60) )
    {
      if ( !(unsigned int)wlan_vdev_mlme_is_init_state(v2) )
      {
        bsspeer = wlan_objmgr_vdev_try_get_bsspeer(v11, 0x4Du);
        if ( bsspeer )
        {
          v13 = bsspeer;
          v14 = cm_send_bss_peer_delete_req(v11);
          wlan_objmgr_peer_release_ref(v13, 0x4Du, v14, v15, v16, v17, v18, v19, v20, v21);
        }
      }
      if ( *(_DWORD *)(v1 + 60) )
        cm_update_tried_candidate_freq_list(*(_QWORD *)v1, v11, (unsigned __int8 *)(v1 + 8));
    }
    cm_csr_connect_rsp(v11, v1);
    v30 = (unsigned int *)*(unsigned __int8 *)(v1 + 9);
    if ( ((unsigned __int8)v30 & 4) != 0 )
      v31 = 0;
    else
      v31 = wlan_cm_connect_rsp(v11, v1 + 8);
    wlan_objmgr_vdev_release_ref(v11, 0x4Du, v30, v22, v23, v24, v25, v26, v27, v28, v29);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: vdev not found",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_cm_send_connect_rsp",
      *(unsigned __int8 *)(v1 + 8),
      *(unsigned int *)(v1 + 12));
    v31 = 4;
  }
  _qdf_mem_free(*(_QWORD *)(v1 + 192));
  v33 = *(_QWORD *)(v1 + 176);
  *(_QWORD *)(v1 + 192) = 0;
  *(_DWORD *)(v1 + 184) = 0;
  _qdf_mem_free(v33);
  cm_free_connect_rsp_ies(v1 + 8);
  qdf_mem_set((void *)v1, 0xD0u, 0);
  _qdf_mem_free(v1);
  return v31;
}
