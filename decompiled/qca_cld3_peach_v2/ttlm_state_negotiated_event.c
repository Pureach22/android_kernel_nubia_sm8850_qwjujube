bool __fastcall ttlm_state_negotiated_event(
        __int64 a1,
        unsigned int a2,
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
  unsigned int v14; // w21
  _BOOL8 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v14 = a2;
  result = 0;
  if ( (unsigned __int16)a2 <= 6u )
  {
    if ( (_WORD)a2 )
    {
      if ( (unsigned __int16)a2 != 4 )
        return result;
    }
    else
    {
      v14 = 1;
    }
LABEL_10:
    wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 1u, a5, a6, a7, a8, a9, a10, a11, a12);
    return (unsigned int)wlan_sm_dispatch(*(_QWORD *)(a1 + 720), v14, a3, a4, v17, v18, v19, v20, v21, v22, v23, v24) == 0;
  }
  if ( (unsigned __int16)a2 == 7 || (unsigned __int16)a2 == 12 || (unsigned __int16)a2 == 13 )
    goto LABEL_10;
  return result;
}
