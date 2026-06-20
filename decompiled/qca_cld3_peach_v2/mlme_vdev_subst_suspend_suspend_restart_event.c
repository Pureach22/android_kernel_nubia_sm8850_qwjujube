__int64 __fastcall mlme_vdev_subst_suspend_suspend_restart_event(
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
  __int64 v14; // x9
  void (__fastcall *v15)(__int64, __int64, __int64, __int64); // x9
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x21
  __int64 v21; // x19
  unsigned int v22; // w20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  unsigned int v32; // w1
  __int64 v33; // x9
  __int64 v34; // x21

  result = 0;
  if ( a2 <= 0x11u )
  {
    if ( a2 == 12 )
    {
      wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 0xBu, a5, a6, a7, a8, a9, a10, a11, a12);
      return 1;
    }
    if ( a2 != 17 )
      return result;
    v20 = a1;
    v21 = a4;
    v22 = a3;
    wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 1u, a5, a6, a7, a8, a9, a10, a11, a12);
    v31 = *(_QWORD *)(v20 + 504);
    v32 = 2;
    goto LABEL_18;
  }
  if ( a2 != 32 )
  {
    if ( a2 != 23 )
    {
      if ( a2 != 18 )
        return result;
      v14 = *(_QWORD *)(a1 + 528);
      if ( !v14 )
        return 1;
      v15 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v14 + 96);
      if ( !v15 )
        return 1;
      v16 = a1;
      v17 = a3;
      v18 = a4;
      v19 = 0;
      goto LABEL_14;
    }
    v34 = a1;
    v21 = a4;
    v22 = a3;
    wlan_sm_transition_to(*(_QWORD *)(a1 + 504), 0xEu, a5, a6, a7, a8, a9, a10, a11, a12);
    v31 = *(_QWORD *)(v34 + 504);
    v32 = 24;
LABEL_18:
    wlan_sm_dispatch(v31, v32, v22, v21, v23, v24, v25, v26, v27, v28, v29, v30);
    return 1;
  }
  v33 = *(_QWORD *)(a1 + 528);
  if ( v33 )
  {
    v15 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v33 + 96);
    if ( v15 )
    {
      v16 = a1;
      v17 = a3;
      v18 = a4;
      v19 = 1;
LABEL_14:
      if ( *((_DWORD *)v15 - 1) != -1464586256 )
        __break(0x8229u);
      v15(v16, v17, v18, v19);
    }
  }
  return 1;
}
