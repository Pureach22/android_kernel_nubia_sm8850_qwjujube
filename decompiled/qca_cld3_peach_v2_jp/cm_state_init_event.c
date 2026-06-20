__int64 __fastcall cm_state_init_event(
        __int64 a1,
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
  __int64 v13; // x19
  __int64 v14; // x20
  __int64 v15; // x19
  __int64 v16; // x20
  __int64 v18; // x19
  __int64 v19; // x21
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x0
  __int64 v29; // x22
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  v12 = 0;
  if ( a2 > 0xCu )
  {
    if ( a2 == 13 )
    {
      return (unsigned int)cm_handle_discon_req_in_non_connected_state((_BYTE *)a1, (unsigned int *)a4, 0) == 0;
    }
    else if ( a2 == 16 )
    {
      if ( (*(_BYTE *)(a4 + 3) & 0x10) != 0 )
      {
        v15 = a1;
        v16 = a4;
        wlan_sm_transition_to(*(_QWORD *)(a1 + 72), 0xEu, a5, a6, a7, a8, a9, a10, a11, a12);
        a1 = v15;
        a4 = v16;
      }
      cm_disconnect_complete((_QWORD *)a1, (unsigned int *)a4);
      return 1;
    }
  }
  else if ( a2 )
  {
    if ( a2 == 12 )
    {
      if ( (*(_BYTE *)(a4 + 7) & 0x10) != 0 )
      {
        v13 = a1;
        v14 = a4;
        wlan_sm_transition_to(*(_QWORD *)(a1 + 72), 0xEu, a5, a6, a7, a8, a9, a10, a11, a12);
        a1 = v13;
        a4 = v14;
      }
      cm_connect_complete((__int64 *)a1, a4);
      return 1;
    }
  }
  else
  {
    v18 = a1;
    v19 = a4;
    if ( (unsigned int)cm_add_connect_req_to_list(a1, (_DWORD *)a4) )
    {
      return 0;
    }
    else
    {
      v28 = *(_QWORD *)(v18 + 72);
      v29 = v18;
      v12 = 1;
      wlan_sm_transition_to(v28, 1u, v20, v21, v22, v23, v24, v25, v26, v27);
      wlan_sm_dispatch(*(_QWORD *)(v29 + 72), 6u, a3, v19, v30, v31, v32, v33, v34, v35, v36, v37);
    }
  }
  return v12;
}
