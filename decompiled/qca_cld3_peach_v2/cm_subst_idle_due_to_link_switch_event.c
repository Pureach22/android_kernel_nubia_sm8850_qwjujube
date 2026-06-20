bool __fastcall cm_subst_idle_due_to_link_switch_event(
        __int64 *a1,
        unsigned int a2,
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  unsigned int v24; // w1
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
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

  if ( (unsigned __int16)a2 == 18 )
  {
    wlan_sm_transition_to(a1[9], 2u, a5, a6, a7, a8, a9, a10, a11, a12);
    if ( (unsigned int)wlan_sm_dispatch(a1[9], 0x12u, a3, (__int64)a4, v34, v35, v36, v37, v38, v39, v40, v41) )
    {
      wlan_sm_transition_to(a1[9], 0, v42, v43, v44, v45, v46, v47, v48, v49);
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    if ( (unsigned __int16)a2 == 13 )
    {
      if ( (unsigned int)cm_handle_discon_req_in_non_connected_state(a1, a4, 14) )
        return 0;
      wlan_sm_transition_to(a1[9], 3u, v25, v26, v27, v28, v29, v30, v31, v32);
      v23 = a1[9];
      v24 = 14;
    }
    else if ( (_WORD)a2 )
    {
      wlan_sm_transition_to(a1[9], 0, a5, a6, a7, a8, a9, a10, a11, a12);
      v23 = a1[9];
      v24 = a2;
    }
    else
    {
      wlan_sm_transition_to(a1[9], 2 * (a4[3] != 17), a5, a6, a7, a8, a9, a10, a11, a12);
      v23 = a1[9];
      v24 = 0;
    }
    return (unsigned int)wlan_sm_dispatch(v23, v24, a3, (__int64)a4, v15, v16, v17, v18, v19, v20, v21, v22) == 0;
  }
}
