__int64 __fastcall cm_handle_connect_disconnect_in_roam(__int64 a1, __int16 a2, unsigned int a3, unsigned int *a4)
{
  unsigned int v4; // w19
  __int64 v6; // x20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
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
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  if ( a2 != 15 )
  {
    if ( a2 == 13 )
    {
      v4 = a3;
      v6 = (__int64)a4;
      if ( !(unsigned int)cm_handle_discon_req_in_non_connected_state((_BYTE *)a1, a4, 4) )
      {
        wlan_sm_transition_to(*(_QWORD *)(a1 + 72), 3u, v26, v27, v28, v29, v30, v31, v32, v33);
        v23 = *(_QWORD *)(a1 + 72);
        v24 = 14;
        goto LABEL_10;
      }
    }
    else if ( !a2 )
    {
      v4 = a3;
      v6 = (__int64)a4;
      if ( !(unsigned int)cm_handle_connect_req_in_non_init_state((_BYTE *)a1, a4, 4) )
      {
        wlan_sm_transition_to(*(_QWORD *)(a1 + 72), 1u, v7, v8, v9, v10, v11, v12, v13, v14);
        v23 = *(_QWORD *)(a1 + 72);
        v24 = 6;
LABEL_10:
        wlan_sm_dispatch(v23, v24, v4, v6, v15, v16, v17, v18, v19, v20, v21, v22);
        return 1;
      }
    }
    return 0;
  }
  cm_disconnect_active((_DWORD *)a1, a4);
  return 1;
}
