__int64 __fastcall mlme_vdev_state_suspend_event(
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
  int v12; // w8
  unsigned int v15; // w21
  __int64 result; // x0
  unsigned __int8 v18; // w1
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v12 = (unsigned __int16)a2;
  v15 = a2;
  result = 0;
  if ( (unsigned __int16)a2 > 0x12u )
  {
    switch ( (unsigned __int16)a2 )
    {
      case 0x13u:
        v18 = 13;
        break;
      case 0x16u:
        v15 = 12;
        v18 = 11;
        break;
      case 0x18u:
        v18 = 14;
        break;
      default:
        return result;
    }
  }
  else
  {
    v18 = 11;
    if ( v12 != 6 && v12 != 12 )
    {
      if ( v12 != 18 )
        return result;
      v18 = 12;
    }
  }
  wlan_sm_transition_to(*(_QWORD *)(a1 + 488), v18, a5, a6, a7, a8, a9, a10, a11, a12);
  wlan_sm_dispatch(*(_QWORD *)(a1 + 488), v15, a3, a4, v19, v20, v21, v22, v23, v24, v25, v26);
  return 1;
}
