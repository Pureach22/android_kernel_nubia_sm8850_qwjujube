__int64 __fastcall mlme_vdev_subst_suspend_host_restart_event(
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
  __int64 result; // x0
  __int64 v16; // x21
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
  __int64 v27; // x9
  _DWORD *v28; // x9
  __int64 v29; // x21

  result = 0;
  if ( a2 > 0x12u )
  {
    if ( a2 == 23 )
    {
      v29 = a1;
      wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 0xEu, a5, a6, a7, a8, a9, a10, a11, a12);
      v25 = *(_QWORD *)(v29 + 488);
      v26 = 24;
LABEL_14:
      wlan_sm_dispatch(v25, v26, a3, a4, v17, v18, v19, v20, v21, v22, v23, v24);
      return 1;
    }
    if ( a2 != 19 )
      return result;
    v27 = *(_QWORD *)(a1 + 512);
    if ( v27 )
    {
      v28 = *(_DWORD **)(v27 + 96);
      if ( v28 )
      {
        if ( *(v28 - 1) != -1464586256 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD))v28)(a1, a3, a4, 0);
      }
    }
  }
  else
  {
    if ( a2 != 12 )
    {
      if ( a2 != 17 )
        return result;
      v16 = a1;
      wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 3u, a5, a6, a7, a8, a9, a10, a11, a12);
      v25 = *(_QWORD *)(v16 + 488);
      v26 = 20;
      goto LABEL_14;
    }
    wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 0xBu, a5, a6, a7, a8, a9, a10, a11, a12);
  }
  return 1;
}
