__int64 __fastcall cm_state_init_event(
        __int64 *a1,
        unsigned __int16 a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w19
  __int64 *v13; // x22
  __int64 v14; // x19
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
  __int64 *v32; // x19
  __int64 v33; // x20
  __int64 *v34; // x19
  __int64 v35; // x20
  __int64 *v37; // x19
  __int64 v38; // x21
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x0
  __int64 *v48; // x22
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7

  v12 = 0;
  if ( a2 <= 0xCu )
  {
    if ( !a2 )
    {
      v37 = a1;
      v38 = a4;
      if ( !(unsigned int)cm_add_connect_req_to_list((__int64)a1, (_DWORD *)a4) )
      {
        v47 = v37[9];
        v48 = v37;
        v12 = 1;
        wlan_sm_transition_to(v47, 1u, v39, v40, v41, v42, v43, v44, v45, v46);
        wlan_sm_dispatch(v48[9], 6u, a3, v38, v49, v50, v51, v52, v53, v54, v55, v56);
        return v12;
      }
      return 0;
    }
    if ( a2 != 12 )
      return v12;
    if ( (*(_BYTE *)(a4 + 7) & 0x10) != 0 )
    {
      v32 = a1;
      v33 = a4;
      wlan_sm_transition_to(a1[9], 0xEu, a5, a6, a7, a8, a9, a10, a11, a12);
      a1 = v32;
      a4 = v33;
    }
    cm_connect_complete(a1, a4);
    return 1;
  }
  switch ( a2 )
  {
    case 0xDu:
      return (unsigned int)cm_handle_discon_req_in_non_connected_state(a1, (unsigned int *)a4, 0) == 0;
    case 0x10u:
      if ( (*(_BYTE *)(a4 + 3) & 0x10) != 0 )
      {
        v34 = a1;
        v35 = a4;
        wlan_sm_transition_to(a1[9], 0xEu, a5, a6, a7, a8, a9, a10, a11, a12);
        a1 = v34;
        a4 = v35;
      }
      cm_disconnect_complete(a1, (unsigned int *)a4);
      return 1;
    case 0x12u:
      if ( (*(_BYTE *)(*a1 + 60) & 2) == 0 )
        return 0;
      v13 = a1;
      v14 = a4;
      wlan_sm_transition_to(a1[9], 2u, a5, a6, a7, a8, a9, a10, a11, a12);
      if ( (unsigned int)wlan_sm_dispatch(v13[9], 0x12u, a3, v14, v16, v17, v18, v19, v20, v21, v22, v23) )
      {
        wlan_sm_transition_to(v13[9], 0, v24, v25, v26, v27, v28, v29, v30, v31);
        return 0;
      }
      return 1;
  }
  return v12;
}
