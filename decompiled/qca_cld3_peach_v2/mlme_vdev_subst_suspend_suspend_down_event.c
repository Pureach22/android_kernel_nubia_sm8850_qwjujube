__int64 __fastcall mlme_vdev_subst_suspend_suspend_down_event(
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
  __int64 v12; // x8
  void (*v13)(void); // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  switch ( a2 )
  {
    case 6:
      goto LABEL_4;
    case 17:
      wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 5u, a5, a6, a7, a8, a9, a10, a11, a12);
      wlan_sm_dispatch(*(_QWORD *)(a1 + 504), 0x1Du, a3, a4, v17, v18, v19, v20, v21, v22, v23, v24);
      return 1;
    case 12:
LABEL_4:
      v12 = *(_QWORD *)(a1 + 528);
      if ( v12 )
      {
        v13 = *(void (**)(void))(v12 + 96);
        if ( v13 )
        {
          if ( *((_DWORD *)v13 - 1) != -1464586256 )
            __break(0x8228u);
          v13();
        }
      }
      return 1;
  }
  return 0;
}
