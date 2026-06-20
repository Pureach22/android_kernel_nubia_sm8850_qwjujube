bool __fastcall mlme_vdev_subst_suspend_csa_restart_event(
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
  __int64 v13; // x0
  __int64 v14; // x22
  __int64 v15; // x20
  unsigned int v16; // w21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x0
  unsigned int v34; // w1
  __int64 v36; // x8
  void (__fastcall *v37)(__int64 *, __int64); // x8
  __int64 v38; // x8
  unsigned int (__fastcall *v39)(_QWORD); // x8

  v13 = *(_QWORD *)(a1[63] + 152);
  if ( v13 )
    v14 = *(_QWORD *)(v13 + 80);
  else
    v14 = 0;
  if ( a2 > 0x17u )
  {
    switch ( a2 )
    {
      case 0x18u:
        v36 = a1[64];
        if ( v36 )
        {
          v37 = *(void (__fastcall **)(__int64 *, __int64))(v36 + 88);
          if ( v37 )
          {
            if ( *((_DWORD *)v37 - 1) != 801230058 )
              __break(0x8228u);
            v37(a1, 3);
          }
        }
        return 1;
      case 0x19u:
        v38 = a1[64];
        v16 = a3;
        v15 = a4;
        if ( !v38 )
          goto LABEL_23;
        v39 = *(unsigned int (__fastcall **)(_QWORD))(v38 + 168);
        if ( !v39 )
          goto LABEL_23;
        if ( *((_DWORD *)v39 - 1) != -1843776435 )
          __break(0x8228u);
        if ( v39(a1) && (mlme_max_chan_switch_is_set(v14) & 1) == 0 )
        {
          wlan_sm_transition_to(a1[61], 0xCu, a5, a6, a7, a8, a9, a10, a11, a12);
          v33 = a1[61];
          v34 = 32;
        }
        else
        {
LABEL_23:
          wlan_sm_transition_to(a1[61], 1u, a5, a6, a7, a8, a9, a10, a11, a12);
          v33 = a1[61];
          v34 = 2;
        }
        goto LABEL_25;
      case 0x1Eu:
        v15 = a4;
        v16 = a3;
        v17 = utils_dfs_radar_enable();
        wlan_sm_transition_to(a1[61], 3u, v17, v18, v19, v20, v21, v22, v23, v24);
        v33 = a1[61];
        v34 = 20;
LABEL_25:
        wlan_sm_dispatch(v33, v34, v16, v15, v25, v26, v27, v28, v29, v30, v31, v32);
        return 1;
    }
    return 0;
  }
  if ( a2 == 12 )
  {
    v15 = a4;
    v16 = a3;
    wlan_sm_transition_to(a1[61], 0xBu, a5, a6, a7, a8, a9, a10, a11, a12);
    v33 = a1[61];
    v34 = 12;
    goto LABEL_25;
  }
  return a2 == 23;
}
