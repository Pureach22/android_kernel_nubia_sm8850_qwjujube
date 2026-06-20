__int64 __fastcall cm_state_disconnecting_event(
        __int64 *a1,
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
  __int64 result; // x0
  unsigned int v14; // w19
  __int64 *v15; // x21
  unsigned int *v16; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x0
  unsigned int v34; // w1
  __int64 *v35; // x21
  __int64 *v36; // x21
  unsigned int v39; // w2
  __int64 v40; // x3

  result = 0;
  if ( a2 <= 0xEu )
  {
    if ( a2 )
    {
      if ( a2 != 13 )
      {
        if ( a2 != 14 )
          return result;
        cm_disconnect_start(a1, a4);
        return 1;
      }
      v14 = a3;
      v35 = a1;
      v16 = a4;
      if ( (unsigned int)cm_handle_discon_req_in_non_connected_state(a1, a4, 3) )
        return 0;
      v33 = v35[9];
      v34 = 14;
    }
    else
    {
      v14 = a3;
      v15 = a1;
      v16 = a4;
      if ( (unsigned int)cm_handle_connect_req_in_non_init_state(a1, a4, 3) )
        return 0;
      wlan_sm_transition_to(v15[9], 1u, v17, v18, v19, v20, v21, v22, v23, v24);
      v33 = v15[9];
      v34 = 6;
    }
    v39 = v14;
    v40 = (__int64)v16;
    goto LABEL_18;
  }
  if ( a2 != 15 )
  {
    if ( a2 != 16 )
    {
      if ( a2 != 37 )
        return result;
      cm_disconnect_continue_after_rso_stop(*a1, a4);
      return 1;
    }
    v36 = a1;
    wlan_sm_transition_to(a1[9], 0, a5, a6, a7, a8, a9, a10, a11, a12);
    v33 = v36[9];
    v34 = 16;
    v39 = a3;
    v40 = (__int64)a4;
LABEL_18:
    wlan_sm_dispatch(v33, v34, v39, v40, v25, v26, v27, v28, v29, v30, v31, v32);
    return 1;
  }
  cm_disconnect_active(a1, a4);
  return 1;
}
