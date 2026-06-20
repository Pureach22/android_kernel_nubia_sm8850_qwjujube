bool __fastcall mlme_vdev_state_init_event(
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
  _BOOL4 v12; // w19
  __int64 (**v13)(void); // x8
  __int64 (*v16)(void); // x8
  __int64 *v17; // x19
  int v18; // w22
  int v19; // w8
  __int64 v20; // x8
  __int64 *v21; // x0
  _DWORD *v22; // x8
  __int64 v23; // x8
  void (*v24)(void); // x8
  __int64 *v25; // x19
  __int64 v26; // x8
  void (*v27)(void); // x8
  __int64 *v28; // x22
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  v12 = 0;
  if ( a2 > 0xBu )
  {
    if ( a2 == 12 )
    {
      v23 = a1[64];
      if ( v23 )
      {
        v24 = *(void (**)(void))(v23 + 248);
        if ( v24 )
        {
          v25 = a1;
          if ( *((_DWORD *)v24 - 1) != 329685504 )
            __break(0x8228u);
          v24();
          a1 = v25;
        }
      }
    }
    else if ( a2 != 27 )
    {
      return v12;
    }
LABEL_23:
    v26 = a1[64];
    if ( v26 )
    {
      v27 = *(void (**)(void))(v26 + 136);
      if ( v27 )
      {
        if ( *((_DWORD *)v27 - 1) != -1256047138 )
          __break(0x8228u);
        v27();
      }
    }
    return 1;
  }
  if ( a2 )
  {
    if ( a2 != 5 )
      return v12;
    goto LABEL_23;
  }
  v13 = (__int64 (**)(void))a1[64];
  if ( !v13 )
    goto LABEL_29;
  v16 = *v13;
  if ( !v16 )
    goto LABEL_29;
  v17 = a1;
  v18 = *(_DWORD *)(a1[63] + 16);
  if ( *((_DWORD *)v16 - 1) != -1256047138 )
    __break(0x8228u);
  v19 = v16();
  a1 = v17;
  if ( v19 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: failed to validate vdev init params to move to START state",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "mlme_vdev_state_init_event");
    v20 = v17[64];
    v21 = v17;
    v12 = v18 != 0;
    if ( v20 )
    {
      v22 = *(_DWORD **)(v20 + 136);
      if ( v22 )
      {
        if ( *(v22 - 1) != -1256047138 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64 *, _QWORD, __int64))v22)(v21, a3, a4);
      }
    }
  }
  else
  {
LABEL_29:
    v28 = a1;
    v12 = 1;
    wlan_sm_transition_to(a1[61], 1u, a5, a6, a7, a8, a9, a10, a11, a12);
    wlan_sm_dispatch(v28[61], 1u, a3, a4, v29, v30, v31, v32, v33, v34, v35, v36);
  }
  return v12;
}
