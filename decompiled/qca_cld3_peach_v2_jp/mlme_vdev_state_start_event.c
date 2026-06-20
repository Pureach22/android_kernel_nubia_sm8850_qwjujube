__int64 __fastcall mlme_vdev_state_start_event(
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
  unsigned int v14; // w22
  __int64 result; // x0
  unsigned __int8 v17; // w1
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v14 = a2;
  result = 0;
  if ( (unsigned __int16)a2 > 8u )
  {
    if ( (unsigned __int16)a2 == 9 )
    {
      v17 = 9;
      v14 = 9;
      goto LABEL_10;
    }
    if ( (unsigned __int16)a2 != 23 )
      return result;
    goto LABEL_7;
  }
  if ( (unsigned __int16)a2 == 1 )
  {
    v17 = 7;
    goto LABEL_10;
  }
  if ( (unsigned __int16)a2 == 2 )
  {
LABEL_7:
    v17 = 8;
LABEL_10:
    wlan_sm_transition_to(*(_QWORD *)(a1 + 488), v17, a5, a6, a7, a8, a9, a10, a11, a12);
    wlan_sm_dispatch(*(_QWORD *)(a1 + 488), v14, a3, a4, v18, v19, v20, v21, v22, v23, v24, v25);
    return 1;
  }
  return result;
}
