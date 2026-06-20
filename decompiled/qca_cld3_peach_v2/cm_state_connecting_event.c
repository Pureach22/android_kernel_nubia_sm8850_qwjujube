bool __fastcall cm_state_connecting_event(
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
  int v12; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v12 = a2;
  if ( a2 == 6 )
  {
    wlan_sm_transition_to(*(_QWORD *)(a1 + 72), 7u, a5, a6, a7, a8, a9, a10, a11, a12);
    wlan_sm_dispatch(*(_QWORD *)(a1 + 72), 6u, a3, a4, v16, v17, v18, v19, v20, v21, v22, v23);
  }
  return v12 == 6;
}
