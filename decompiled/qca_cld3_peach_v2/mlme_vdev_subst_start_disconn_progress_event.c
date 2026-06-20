__int64 __fastcall mlme_vdev_subst_start_disconn_progress_event(
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
  unsigned int v14; // w8
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
  __int64 v29; // x8
  void (*v30)(void); // x8

  v14 = 0;
  if ( a2 > 5u )
  {
    if ( a2 == 6 )
      goto LABEL_10;
    if ( a2 == 12 )
    {
      v29 = *(_QWORD *)(a1 + 528);
      if ( v29 )
      {
        v30 = *(void (**)(void))(v29 + 200);
        if ( v30 )
        {
          if ( *((_DWORD *)v30 - 1) != -1256047138 )
            __break(0x8228u);
          v30();
        }
      }
      return 1;
    }
    if ( a2 != 13 )
      return v14;
LABEL_9:
    wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 5u, a5, a6, a7, a8, a9, a10, a11, a12);
    v24 = *(_QWORD *)(a1 + 504);
    v25 = 29;
    goto LABEL_11;
  }
  switch ( a2 )
  {
    case 3u:
      goto LABEL_9;
    case 4u:
LABEL_10:
      wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 4u, a5, a6, a7, a8, a9, a10, a11, a12);
      v24 = *(_QWORD *)(a1 + 504);
      v25 = 12;
      goto LABEL_11;
    case 5u:
      wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 0, a5, a6, a7, a8, a9, a10, a11, a12);
      v24 = *(_QWORD *)(a1 + 504);
      v25 = 5;
LABEL_11:
      wlan_sm_dispatch(v24, v25, a3, a4, v16, v17, v18, v19, v20, v21, v22, v23);
      return 1;
  }
  return v14;
}
