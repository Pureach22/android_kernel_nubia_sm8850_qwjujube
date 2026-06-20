bool __fastcall mlme_vdev_subst_start_conn_progress_event(
        __int64 *a1,
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
  __int64 *v15; // x22
  __int64 v19; // x0
  unsigned int v20; // w1
  unsigned int v21; // w2
  __int64 v22; // x3
  __int64 *v23; // x21
  __int64 v24; // x19
  unsigned int v25; // w20
  __int64 v26; // x8
  __int64 (*v27)(void); // x8
  __int64 *v29; // x19
  int v31; // w8
  __int64 *v32; // x19
  __int64 *v33; // x21

  if ( (unsigned __int16)a2 <= 9u )
  {
    if ( (unsigned __int16)a2 != 7 )
    {
      if ( (unsigned __int16)a2 != 8 )
      {
        if ( (unsigned __int16)a2 == 9 )
        {
          v12 = a1[66];
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
        }
        return 0;
      }
      v26 = a1[66];
      if ( !v26 )
        goto LABEL_31;
      v27 = *(__int64 (**)(void))(v26 + 40);
      if ( !v27 )
        goto LABEL_31;
      v29 = a1;
      if ( *((_DWORD *)v27 - 1) != -1256047138 )
        __break(0x8228u);
      v31 = v27();
      a1 = v29;
      if ( !v31 )
      {
LABEL_31:
        if ( *(_DWORD *)(a1[65] + 16) == 1 )
        {
          v32 = a1;
          if ( (wlan_vdev_mlme_is_mlo_vdev(a1[65], a5, a6, a7, a8, a9, a10, a11, a12) & 1) != 0 )
            mlo_ap_link_start_rsp_notify(v32[65]);
        }
        return 1;
      }
      v19 = v29[63];
      v21 = a3;
      v22 = a4;
      v20 = 13;
      goto LABEL_27;
    }
    v23 = a1;
    v24 = a4;
    v25 = a3;
    wlan_sm_transition_to(a1[63], 3u, a5, a6, a7, a8, a9, a10, a11, a12);
    v19 = v23[63];
    v20 = 7;
    goto LABEL_26;
  }
  if ( (unsigned int)(unsigned __int16)a2 - 12 < 2 )
  {
    v15 = a1;
    wlan_sm_transition_to(a1[63], 0xAu, a5, a6, a7, a8, a9, a10, a11, a12);
    v19 = v15[63];
    v20 = a2;
    v21 = a3;
    v22 = a4;
LABEL_27:
    wlan_sm_dispatch(v19, v20, v21, v22, a5, a6, a7, a8, a9, a10, a11, a12);
    return 1;
  }
  if ( (unsigned __int16)a2 == 10 )
  {
    v33 = a1;
    v24 = a4;
    v25 = a3;
    wlan_sm_transition_to(a1[63], 2u, a5, a6, a7, a8, a9, a10, a11, a12);
    v19 = v33[63];
    v20 = 10;
LABEL_26:
    v21 = v25;
    v22 = v24;
    goto LABEL_27;
  }
  return (unsigned __int16)a2 == 23;
}
