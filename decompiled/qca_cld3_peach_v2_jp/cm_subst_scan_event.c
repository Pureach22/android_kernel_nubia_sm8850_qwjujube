__int64 __fastcall cm_subst_scan_event(__int64 *a1, unsigned int a2, unsigned int a3, unsigned int *a4)
{
  __int64 result; // x0
  __int64 *v8; // x22
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x0
  unsigned int v27; // w1
  unsigned int v28; // w2
  __int64 v29; // x3
  unsigned int v30; // w19
  __int64 *v31; // x21
  unsigned int *v32; // x20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 *v41; // x21
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  result = 0;
  if ( (unsigned __int16)a2 > 0xCu )
  {
    if ( (unsigned __int16)a2 > 0xFu )
    {
      if ( (unsigned __int16)a2 == 16 )
      {
        cm_disconnect_complete(a1, a4);
      }
      else
      {
        if ( (unsigned __int16)a2 != 37 )
          return result;
        cm_disconnect_continue_after_rso_stop(*a1, a4);
      }
      return 1;
    }
    if ( (unsigned __int16)a2 != 13 )
    {
      if ( (unsigned __int16)a2 != 15 )
        return result;
      cm_disconnect_active(a1, a4);
      return 1;
    }
    v30 = a3;
    v31 = a1;
    v32 = a4;
    if ( (unsigned int)cm_handle_discon_req_in_non_connected_state(a1, a4, 8) )
      return 0;
    wlan_sm_transition_to(v31[9], 3u, v33, v34, v35, v36, v37, v38, v39, v40);
    v26 = v31[9];
    v27 = 14;
LABEL_21:
    v28 = v30;
    v29 = (__int64)v32;
    goto LABEL_22;
  }
  if ( (unsigned int)(unsigned __int16)a2 - 2 >= 2 )
  {
    if ( (_WORD)a2 )
    {
      if ( (unsigned __int16)a2 != 1 )
        return result;
      cm_connect_scan_start(a1, a4);
      return 1;
    }
    v30 = a3;
    v41 = a1;
    v32 = a4;
    if ( (unsigned int)cm_handle_connect_req_in_non_init_state(a1, a4, 8) )
      return 0;
    wlan_sm_transition_to(v41[9], 7u, v42, v43, v44, v45, v46, v47, v48, v49);
    v26 = v41[9];
    v27 = 6;
    goto LABEL_21;
  }
  v8 = a1;
  if ( (cm_check_scanid_match_list_head(a1, a4) & 1) == 0 )
    return 0;
  wlan_sm_transition_to(v8[9], 7u, v10, v11, v12, v13, v14, v15, v16, v17);
  v26 = v8[9];
  v27 = a2;
  v28 = a3;
  v29 = (__int64)a4;
LABEL_22:
  wlan_sm_dispatch(v26, v27, v28, v29, v18, v19, v20, v21, v22, v23, v24, v25);
  return 1;
}
