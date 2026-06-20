__int64 __fastcall cm_notify_connect_complete(__int64 *a1, __int64 a2, char a3)
{
  int state; // w21
  int v7; // w23
  int v8; // w23
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
  _QWORD *v27; // x22
  __int64 v28; // x5
  __int64 v29; // x4
  __int64 v30; // x22
  int v31; // w23
  _DWORD *v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x23
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  _QWORD *v51; // [xsp+0h] [xbp-160h] BYREF
  _QWORD s[43]; // [xsp+8h] [xbp-158h] BYREF

  s[42] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  state = cm_get_state(a1);
  mlme_cm_connect_complete_ind(*a1, a2);
  mlo_sta_link_connect_notify(*a1, a2);
  v7 = *(_DWORD *)(a2 + 52);
  if ( v7 && !state )
  {
    if ( (a3 & 1) != 0 )
      cm_req_lock_acquire(a1);
    v8 = *(_DWORD *)(a2 + 4);
    v51 = nullptr;
    s[0] = 0;
    if ( (v8 & 0xF000000) == 0xC000000 )
    {
      qdf_list_peek_front(a1 + 12, s);
      v9 = (_QWORD *)s[0];
      if ( s[0] )
      {
        while ( 1 )
        {
          qdf_list_peek_next(a1 + 12, v9, &v51);
          if ( *(_DWORD *)(s[0] + 16LL) == v8 )
            break;
          v9 = v51;
          v51 = nullptr;
          s[0] = v9;
          if ( !v9 )
            goto LABEL_12;
        }
        if ( (*(_BYTE *)(s[0] + 216LL) & 8) != 0 )
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
            *(unsigned __int8 *)(*a1 + 168),
            v18);
        }
      }
    }
LABEL_12:
    if ( (a3 & 1) != 0 )
      cm_req_lock_release(a1);
    v7 = *(_DWORD *)(a2 + 52);
  }
  memset(s, 0, 0x150u);
  if ( !v7 )
    goto LABEL_18;
  if ( (unsigned int)cm_get_first_candidate_rsp(a1, *(unsigned int *)(a2 + 4), s) )
  {
    v7 = 0;
LABEL_18:
    v27 = (_QWORD *)a2;
    goto LABEL_22;
  }
  if ( (*(_BYTE *)(a2 + 1) & 0x20) != 0 )
  {
    v28 = *(unsigned int *)(a2 + 4);
    v29 = *(unsigned __int8 *)(*a1 + 168);
    BYTE1(s[0]) |= 0x20u;
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
      v29,
      v28);
  }
  v27 = s;
  v7 = 1;
LABEL_22:
  mlme_cm_osif_connect_complete(*a1, v27);
  mlme_cm_osif_roam_connect_complete(*a1);
  if ( v7 )
    cm_free_connect_rsp_ies(v27);
  v30 = *a1;
  v31 = *(_DWORD *)(a2 + 52);
  v32 = (_DWORD *)_qdf_mem_malloc(0x38u, "cm_if_mgr_inform_connect_complete", 1765);
  if ( v32 )
  {
    *v32 = v31;
    v41 = (__int64)v32;
    if_mgr_deliver_event(v30, 1u, (__int64)v32, v33, v34, v35, v36, v37, v38, v39, v40);
    _qdf_mem_free(v41);
  }
  ((void (__fastcall *)(__int64, __int64))mlo_mgr_check_if_all_partner_links_rejected)(*a1, a2);
  if ( *(_QWORD *)(*a1 + 216) )
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
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "cm_inform_dlm_connect_complete",
      *(unsigned __int8 *)(*a1 + 168),
      *(unsigned int *)(a2 + 4));
  }
  if ( *(_DWORD *)(a2 + 52) && !state && (*(_BYTE *)(a2 + 7) & 0x10) == 0 )
    wlan_vdev_mlme_clear_mlo_vdev(*a1, v42, v43, v44, v45, v46, v47, v48, v49);
  _ReadStatusReg(SP_EL0);
  return 0;
}
