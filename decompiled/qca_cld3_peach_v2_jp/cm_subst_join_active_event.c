__int64 __fastcall cm_subst_join_active_event(
        __int64 a1,
        unsigned __int16 a2,
        unsigned int a3,
        unsigned int *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  char v14; // w0
  unsigned int v15; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  unsigned int v33; // w1
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7

  v14 = 0;
  if ( a2 > 9u )
  {
    if ( a2 > 0xBu )
    {
      if ( a2 == 12 )
      {
        v15 = a3;
        if ( (cm_connect_resp_cmid_match_list_head(a1, (__int64)a4) & 1) != 0 )
        {
          wlan_sm_transition_to(*(_QWORD *)(a1 + 72), 0, v50, v51, v52, v53, v54, v55, v56, v57);
          v32 = *(_QWORD *)(a1 + 72);
          v33 = 12;
          goto LABEL_26;
        }
      }
      else
      {
        if ( a2 != 13 )
          return v14 & 1;
        v15 = a3;
        if ( !(unsigned int)cm_handle_discon_req_in_non_connected_state((_BYTE *)a1, a4, 9) )
        {
          wlan_sm_transition_to(*(_QWORD *)(a1 + 72), 3u, v16, v17, v18, v19, v20, v21, v22, v23);
          v32 = *(_QWORD *)(a1 + 72);
          v33 = 14;
LABEL_26:
          wlan_sm_dispatch(v32, v33, v15, (__int64)a4, v24, v25, v26, v27, v28, v29, v30, v31);
          goto LABEL_27;
        }
      }
    }
    else if ( a2 == 10 )
    {
      if ( (cm_check_cmid_match_list_head(a1, a4) & 1) != 0 )
      {
        cm_resume_connect_after_peer_create((__int64 *)a1, a4);
        goto LABEL_27;
      }
    }
    else
    {
      if ( a2 != 11 )
        return v14 & 1;
      if ( (cm_connect_resp_cmid_match_list_head(a1, (__int64)a4) & 1) != 0 )
      {
        cm_try_next_candidate((__int64 *)a1, (unsigned __int8 *)a4);
        goto LABEL_27;
      }
    }
LABEL_28:
    v14 = 0;
    return v14 & 1;
  }
  if ( a2 > 7u )
  {
    if ( a2 != 8 )
    {
      if ( a2 == 9 )
        v14 = cm_check_cmid_match_list_head(a1, a4);
      return v14 & 1;
    }
    v15 = a3;
    if ( (cm_connect_resp_cmid_match_list_head(a1, (__int64)a4) & 1) != 0 )
    {
      wlan_sm_transition_to(*(_QWORD *)(a1 + 72), 2u, v42, v43, v44, v45, v46, v47, v48, v49);
      v32 = *(_QWORD *)(a1 + 72);
      v33 = 8;
      goto LABEL_26;
    }
    goto LABEL_28;
  }
  if ( !a2 )
  {
    v15 = a3;
    if ( !(unsigned int)cm_handle_connect_req_in_non_init_state((_BYTE *)a1, a4, 9) )
    {
      wlan_sm_transition_to(*(_QWORD *)(a1 + 72), 7u, v34, v35, v36, v37, v38, v39, v40, v41);
      v32 = *(_QWORD *)(a1 + 72);
      v33 = 6;
      goto LABEL_26;
    }
    goto LABEL_28;
  }
  if ( a2 == 7 )
  {
    cm_connect_active((__int64 *)a1, a4, a5, a6, a7, a8, a9, a10, a11, a12);
LABEL_27:
    v14 = 1;
  }
  return v14 & 1;
}
