bool __fastcall ttlm_state_init_event(
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
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x0
  unsigned int v25; // w1

  if ( a2 > 6u )
  {
    switch ( a2 )
    {
      case 7u:
        wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 1u, a5, a6, a7, a8, a9, a10, a11, a12);
        v24 = *(_QWORD *)(a1 + 720);
        v25 = 7;
        break;
      case 0xCu:
        wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 1u, a5, a6, a7, a8, a9, a10, a11, a12);
        v24 = *(_QWORD *)(a1 + 720);
        v25 = 12;
        break;
      case 0xDu:
        wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 1u, a5, a6, a7, a8, a9, a10, a11, a12);
        v24 = *(_QWORD *)(a1 + 720);
        v25 = 13;
        break;
      default:
        return 0;
    }
  }
  else if ( a2 )
  {
    if ( a2 != 4 )
      return a2 == 6;
    wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 1u, a5, a6, a7, a8, a9, a10, a11, a12);
    v24 = *(_QWORD *)(a1 + 720);
    v25 = 4;
  }
  else
  {
    wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 1u, a5, a6, a7, a8, a9, a10, a11, a12);
    v24 = *(_QWORD *)(a1 + 720);
    v25 = 1;
  }
  return (unsigned int)wlan_sm_dispatch(v24, v25, a3, a4, v16, v17, v18, v19, v20, v21, v22, v23) == 0;
}
