__int64 __fastcall mlme_vdev_state_dfs_cac_wait_event(
        __int64 *a1,
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
  __int64 v16; // x0
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
  __int64 v27; // x8
  void (__fastcall *v28)(_QWORD); // x8
  __int64 v29; // x8
  _DWORD *v30; // x8

  result = 0;
  if ( a2 > 0xBu )
  {
    if ( a2 == 12 )
    {
      v29 = a1[66];
      if ( v29 )
      {
        v30 = *(_DWORD **)(v29 + 104);
        if ( v30 )
        {
          if ( *(v30 - 1) != -1256047138 )
            __break(0x8228u);
          a5 = ((double (__fastcall *)(__int64 *, _QWORD, __int64))v30)(a1, a3, a4);
        }
      }
      wlan_sm_transition_to(a1[63], 4u, a5, a6, a7, a8, a9, a10, a11, a12);
      v25 = a1[63];
      v26 = 12;
    }
    else
    {
      if ( a2 != 23 )
        return result;
      wlan_sm_transition_to(a1[63], 1u, a5, a6, a7, a8, a9, a10, a11, a12);
      v25 = a1[63];
      v26 = 2;
    }
  }
  else
  {
    if ( a2 == 10 )
    {
      v27 = a1[66];
      if ( v27 )
      {
        v28 = *(void (__fastcall **)(_QWORD))(v27 + 184);
        if ( v28 )
        {
          if ( *((_DWORD *)v28 - 1) != -1843776435 )
            __break(0x8228u);
          v28(a1);
        }
      }
      return 1;
    }
    if ( a2 != 11 )
      return result;
    v16 = a1[63];
    if ( *(_DWORD *)(a1[65] + 16) )
    {
      wlan_sm_transition_to(v16, 3u, a5, a6, a7, a8, a9, a10, a11, a12);
      v25 = a1[63];
      v26 = 7;
    }
    else
    {
      wlan_sm_transition_to(v16, 1u, a5, a6, a7, a8, a9, a10, a11, a12);
      v25 = a1[63];
      v26 = 9;
    }
  }
  wlan_sm_dispatch(v25, v26, a3, a4, v17, v18, v19, v20, v21, v22, v23, v24);
  return 1;
}
