__int64 __fastcall mlme_vdev_subst_stop_stop_progress_event(
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
  __int64 v16; // x9
  _DWORD *v17; // x9
  __int64 v18; // x21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x9

  result = 0;
  if ( a2 > 0x19u )
  {
    if ( a2 == 26 )
      goto LABEL_10;
    if ( a2 != 29 )
      return result;
    v16 = *(_QWORD *)(a1 + 528);
    if ( !v16 )
      return 1;
    v17 = *(_DWORD **)(v16 + 112);
    if ( !v17 )
      return 1;
LABEL_13:
    if ( *(v17 - 1) != -1256047138 )
      __break(0x8229u);
    ((void (__fastcall *)(__int64, _QWORD, __int64))v17)(a1, a3, a4);
    return 1;
  }
  if ( a2 == 14 )
  {
    v27 = *(_QWORD *)(a1 + 528);
    if ( !v27 )
      return 1;
    v17 = *(_DWORD **)(v27 + 120);
    if ( !v17 )
      return 1;
    goto LABEL_13;
  }
  if ( a2 == 15 )
  {
LABEL_10:
    v18 = a1;
    wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 0x10u, a5, a6, a7, a8, a9, a10, a11, a12);
    wlan_sm_dispatch(*(_QWORD *)(v18 + 504), 0x1Au, a3, a4, v19, v20, v21, v22, v23, v24, v25, v26);
    return 1;
  }
  return result;
}
