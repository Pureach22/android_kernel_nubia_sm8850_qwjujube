__int64 __fastcall cm_notify_connect_complete(__int64 *a1, __int64 a2, char a3)
{
  int state; // w22
  int v7; // w8
  int v8; // w22
  _QWORD *v9; // x1
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x5
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w22
  _QWORD *v28; // x21
  __int64 v29; // x5
  __int64 v30; // x4
  __int64 v31; // x21
  int v32; // w22
  _DWORD *v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x22
  _QWORD *v44; // [xsp+0h] [xbp-B0h] BYREF
  _QWORD v45[21]; // [xsp+8h] [xbp-A8h] BYREF

  v45[20] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  state = cm_get_state(a1);
  mlme_cm_connect_complete_ind(*a1, a2);
  v7 = *(_DWORD *)(a2 + 52);
  if ( v7 && !state )
  {
    if ( (a3 & 1) != 0 )
      cm_req_lock_acquire(a1);
    v8 = *(_DWORD *)(a2 + 4);
    v44 = nullptr;
    v45[0] = 0;
    if ( (v8 & 0xF000000) == 0xC000000 )
    {
      qdf_list_peek_front(a1 + 12, v45);
      v9 = (_QWORD *)v45[0];
      if ( v45[0] )
      {
        while ( 1 )
        {
          qdf_list_peek_next(a1 + 12, v9, &v44);
          if ( *(_DWORD *)(v45[0] + 16LL) == v8 )
            break;
          v9 = v44;
          v44 = nullptr;
          v45[0] = v9;
          if ( !v9 )
            goto LABEL_12;
        }
        if ( (*(_BYTE *)(v45[0] + 216LL) & 8) != 0 )
        {
          v18 = *(unsigned int *)(a2 + 4);
          *(_BYTE *)(a2 + 1) |= 0x20u;
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: vdev %d cm_id 0x%x: Set send disconnect to true to indicate disconnect instead of connect resp",
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            "cm_notify_connect_complete",
            *(unsigned __int8 *)(*a1 + 104),
            v18);
        }
      }
    }
LABEL_12:
    if ( (a3 & 1) != 0 )
      cm_req_lock_release(a1);
    v7 = *(_DWORD *)(a2 + 52);
  }
  memset(v45, 0, 160);
  if ( v7 && !(unsigned int)cm_get_first_candidate_rsp(a1, *(unsigned int *)(a2 + 4), v45) )
  {
    if ( (*(_BYTE *)(a2 + 1) & 0x20) != 0 )
    {
      v29 = *(unsigned int *)(a2 + 4);
      v30 = *(unsigned __int8 *)(*a1 + 104);
      BYTE1(v45[0]) |= 0x20u;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d cm_id 0x%x: sent disconnect rsp for first candidate",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "cm_osif_connect_complete",
        v30,
        v29);
    }
    v28 = v45;
    v27 = 1;
  }
  else
  {
    v27 = 0;
    v28 = (_QWORD *)a2;
  }
  mlme_cm_osif_connect_complete(*a1, v28);
  mlme_cm_osif_roam_connect_complete(*a1);
  if ( v27 )
    cm_free_connect_rsp_ies(v28);
  v31 = *a1;
  v32 = *(_DWORD *)(a2 + 52);
  v33 = (_DWORD *)_qdf_mem_malloc(0x30u, "cm_if_mgr_inform_connect_complete", 1765);
  if ( v33 )
  {
    *v33 = v32;
    v42 = (__int64)v33;
    if_mgr_deliver_event(v31, 1u, (__int64)v33, v34, v35, v36, v37, v38, v39, v40, v41);
    _qdf_mem_free(v42);
  }
  if ( *(_QWORD *)(*a1 + 152) )
  {
    if ( !*(_DWORD *)(a2 + 52) )
      dlm_update_bssid_connect_params();
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: Failed to find pdev",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "cm_inform_dlm_connect_complete",
      *(unsigned __int8 *)(*a1 + 104),
      *(unsigned int *)(a2 + 4));
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
