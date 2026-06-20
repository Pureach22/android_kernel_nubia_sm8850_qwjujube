bool __fastcall mlme_vdev_subst_start_conn_progress_event(
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
  __int64 v12; // x8
  void (*v13)(void); // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x0
  unsigned int v28; // w1
  unsigned int v29; // w2
  __int64 v30; // x3
  __int64 v32; // x19
  unsigned int v33; // w20
  __int64 v34; // x8
  unsigned int (*v35)(void); // x8

  if ( (unsigned __int16)a2 <= 9u )
  {
    switch ( (unsigned __int16)a2 )
    {
      case 7u:
        v32 = a4;
        v33 = a3;
        wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 3u, a5, a6, a7, a8, a9, a10, a11, a12);
        v27 = *(_QWORD *)(a1 + 488);
        v28 = 7;
        break;
      case 8u:
        v34 = *(_QWORD *)(a1 + 512);
        if ( !v34 )
          return 1;
        v35 = *(unsigned int (**)(void))(v34 + 40);
        if ( !v35 )
          return 1;
        v33 = a3;
        v32 = a4;
        if ( *((_DWORD *)v35 - 1) != -1256047138 )
          __break(0x8228u);
        if ( !v35() )
          return 1;
        v27 = *(_QWORD *)(a1 + 488);
        v28 = 13;
        break;
      case 9u:
        v12 = *(_QWORD *)(a1 + 512);
        if ( v12 )
        {
          v13 = *(void (**)(void))(v12 + 48);
          if ( v13 )
          {
            if ( *((_DWORD *)v13 - 1) != -1256047138 )
              __break(0x8228u);
            v13();
          }
        }
        return 1;
      default:
        return 0;
    }
    goto LABEL_23;
  }
  if ( (unsigned int)(unsigned __int16)a2 - 12 < 2 )
  {
    wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 0xAu, a5, a6, a7, a8, a9, a10, a11, a12);
    v27 = *(_QWORD *)(a1 + 488);
    v28 = a2;
    v29 = a3;
    v30 = a4;
LABEL_24:
    wlan_sm_dispatch(v27, v28, v29, v30, v19, v20, v21, v22, v23, v24, v25, v26);
    return 1;
  }
  if ( (unsigned __int16)a2 == 10 )
  {
    v32 = a4;
    v33 = a3;
    wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 2u, a5, a6, a7, a8, a9, a10, a11, a12);
    v27 = *(_QWORD *)(a1 + 488);
    v28 = 10;
LABEL_23:
    v29 = v33;
    v30 = v32;
    goto LABEL_24;
  }
  return (unsigned __int16)a2 == 23;
}
