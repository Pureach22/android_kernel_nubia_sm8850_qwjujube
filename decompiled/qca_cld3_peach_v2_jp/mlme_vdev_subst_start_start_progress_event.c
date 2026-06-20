__int64 __fastcall mlme_vdev_subst_start_start_progress_event(
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
  __int64 v15; // x21
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
  __int64 v26; // x8
  void (*v27)(void); // x8
  __int64 v28; // x8
  void (*v29)(void); // x8
  __int64 v30; // x21
  __int64 v31; // x21
  __int64 v33; // x21
  __int64 v34; // x8
  _DWORD *v35; // x8

  v14 = 0;
  if ( a2 > 4u )
  {
    switch ( a2 )
    {
      case 5u:
        v28 = *(_QWORD *)(a1 + 512);
        if ( v28 )
        {
          v29 = *(void (**)(void))(v28 + 56);
          if ( v29 )
          {
            v30 = a1;
            if ( *((_DWORD *)v29 - 1) != -1256047138 )
              __break(0x8228u);
            v29();
            a1 = v30;
          }
        }
        v31 = a1;
        wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 0, a5, a6, a7, a8, a9, a10, a11, a12);
        v24 = *(_QWORD *)(v31 + 488);
        v25 = 5;
        goto LABEL_20;
      case 0xCu:
        v33 = a1;
        wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 0xAu, a5, a6, a7, a8, a9, a10, a11, a12);
        v34 = *(_QWORD *)(v33 + 512);
        if ( v34 )
        {
          v35 = *(_DWORD **)(v34 + 32);
          if ( v35 )
          {
            if ( *(v35 - 1) != 486479727 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v35)(v33, 0, a3, a4);
          }
        }
        return 1;
      case 0x17u:
        wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 8u, a5, a6, a7, a8, a9, a10, a11, a12);
        return 1;
    }
  }
  else
  {
    if ( (unsigned int)a2 - 3 < 2 )
    {
      v15 = a1;
      wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 9u, a5, a6, a7, a8, a9, a10, a11, a12);
      v24 = *(_QWORD *)(v15 + 488);
      v25 = 8;
LABEL_20:
      wlan_sm_dispatch(v24, v25, a3, a4, v16, v17, v18, v19, v20, v21, v22, v23);
      return 1;
    }
    if ( a2 == 1 )
    {
      v26 = *(_QWORD *)(a1 + 512);
      if ( v26 )
      {
        v27 = *(void (**)(void))(v26 + 16);
        if ( v27 )
        {
          if ( *((_DWORD *)v27 - 1) != -1256047138 )
            __break(0x8228u);
          v27();
        }
      }
      return 1;
    }
  }
  return v14;
}
