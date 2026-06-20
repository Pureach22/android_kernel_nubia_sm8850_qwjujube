bool __fastcall mlme_vdev_subst_start_restart_progress_event(
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
  __int64 v12; // x8
  void (*v13)(void); // x8
  __int64 v15; // x19
  unsigned int v16; // w20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0
  unsigned int v26; // w1
  __int64 v32; // x8
  _DWORD *v33; // x8

  if ( a2 <= 5u )
  {
    if ( (unsigned int)a2 - 2 < 2 )
    {
      v12 = *(_QWORD *)(a1 + 512);
      if ( v12 )
      {
        v13 = *(void (**)(void))(v12 + 24);
        if ( v13 )
        {
          if ( *((_DWORD *)v13 - 1) != -1256047138 )
            __break(0x8228u);
          v13();
        }
      }
      return 1;
    }
    if ( a2 == 4 )
    {
      v15 = a4;
      v16 = a3;
      wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 9u, a5, a6, a7, a8, a9, a10, a11, a12);
      v25 = *(_QWORD *)(a1 + 488);
      v26 = 8;
LABEL_15:
      wlan_sm_dispatch(v25, v26, v16, v15, v17, v18, v19, v20, v21, v22, v23, v24);
      return 1;
    }
    return 0;
  }
  if ( a2 == 6 )
  {
    v15 = a4;
    v16 = a3;
    wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 4u, a5, a6, a7, a8, a9, a10, a11, a12);
    v25 = *(_QWORD *)(a1 + 488);
    v26 = 6;
    goto LABEL_15;
  }
  if ( a2 == 12 )
  {
    wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 0xAu, a5, a6, a7, a8, a9, a10, a11, a12);
    v32 = *(_QWORD *)(a1 + 512);
    if ( v32 )
    {
      v33 = *(_DWORD **)(v32 + 32);
      if ( v33 )
      {
        if ( *(v33 - 1) != 486479727 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v33)(a1, 1, a3, a4);
      }
    }
    return 1;
  }
  return a2 == 23;
}
