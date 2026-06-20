bool __fastcall ttlm_state_inprogress_event(
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
  _BOOL8 result; // x0
  unsigned __int8 v17; // w1
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  result = 0;
  if ( (unsigned __int16)a2 <= 6u )
  {
    if ( (unsigned __int16)a2 == 1 )
    {
      v17 = 4;
    }
    else
    {
      if ( (unsigned __int16)a2 != 4 )
        return result;
      v17 = 5;
    }
    goto LABEL_11;
  }
  if ( (unsigned __int16)a2 == 7 )
  {
    v17 = 7;
    goto LABEL_11;
  }
  if ( (unsigned __int16)a2 == 12 || (unsigned __int16)a2 == 13 )
  {
    v17 = 9;
LABEL_11:
    wlan_sm_transition_to(*(_QWORD *)(a1 + 720), v17, a5, a6, a7, a8, a9, a10, a11, a12);
    return (unsigned int)wlan_sm_dispatch(*(_QWORD *)(a1 + 720), a2, a3, a4, v18, v19, v20, v21, v22, v23, v24, v25) == 0;
  }
  return result;
}
