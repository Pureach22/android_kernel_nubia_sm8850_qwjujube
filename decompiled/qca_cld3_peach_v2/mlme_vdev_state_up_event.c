bool __fastcall mlme_vdev_state_up_event(
        __int64 a1,
        __int16 a2,
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
  __int64 v13; // x0
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
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  v13 = *(_QWORD *)(a1 + 520);
  if ( a2 != 28 )
  {
    if ( a2 == 20 )
    {
      wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 0x13u, a5, a6, a7, a8, a9, a10, a11, a12);
      v24 = *(_QWORD *)(a1 + 504);
      v25 = 20;
LABEL_8:
      wlan_sm_dispatch(v24, v25, a3, a4, v16, v17, v18, v19, v20, v21, v22, v23);
      return 1;
    }
    if ( a2 == 7 )
    {
      if ( *(_DWORD *)(v13 + 16) == 1 )
        wlan_vdev_mlme_is_mlo_vdev(v13, a5, a6, a7, a8, a9, a10, a11, a12);
      wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 0x13u, a5, a6, a7, a8, a9, a10, a11, a12);
      v24 = *(_QWORD *)(a1 + 504);
      v25 = 7;
      goto LABEL_8;
    }
    return 0;
  }
  if ( (*(_BYTE *)(v13 + 60) & 2) == 0 )
    return 0;
  wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 0x13u, a5, a6, a7, a8, a9, a10, a11, a12);
  return (unsigned int)wlan_sm_dispatch(*(_QWORD *)(a1 + 504), 0x1Cu, a3, a4, v27, v28, v29, v30, v31, v32, v33, v34) == 0;
}
