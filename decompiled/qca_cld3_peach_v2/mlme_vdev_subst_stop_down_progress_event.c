__int64 __fastcall mlme_vdev_subst_stop_down_progress_event(
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
  __int64 v14; // x8
  void (*v15)(void); // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  if ( a2 > 0x19u )
  {
    if ( a2 == 27 )
    {
LABEL_12:
      wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 0, a5, a6, a7, a8, a9, a10, a11, a12);
      wlan_sm_dispatch(*(_QWORD *)(a1 + 504), 0x1Bu, a3, a4, v17, v18, v19, v20, v21, v22, v23, v24);
      return 1;
    }
    if ( a2 != 26 )
      return 0;
    v14 = *(_QWORD *)(a1 + 528);
    if ( v14 )
    {
      v15 = *(void (**)(void))(v14 + 128);
      if ( v15 )
      {
        if ( *((_DWORD *)v15 - 1) != -1256047138 )
          __break(0x8228u);
        v15();
      }
    }
  }
  else if ( a2 != 12 )
  {
    if ( a2 != 16 )
      return 0;
    goto LABEL_12;
  }
  return 1;
}
