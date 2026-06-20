__int64 __fastcall mlme_vdev_state_init_event(
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
  __int64 v12; // x8
  __int64 result; // x0
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
  __int64 v33; // x8
  void (__fastcall *v34)(_QWORD); // x8
  __int64 v35; // x20
  unsigned int v36; // w21
  __int64 v37; // x8
  _DWORD *v38; // x8
  __int64 v39; // x0
  _DWORD **v40; // x9
  unsigned int v41; // w21
  __int64 v42; // x20
  _DWORD *v43; // x9
  int v44; // w22
  __int64 v45; // x8
  _DWORD *v46; // x8
  _BOOL4 v47; // w22
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7

  v12 = a1[65];
  result = 0;
  if ( a2 > 0xBu )
  {
    switch ( a2 )
    {
      case 0xCu:
        v33 = a1[66];
        if ( v33 )
        {
          v34 = *(void (__fastcall **)(_QWORD))(v33 + 248);
          if ( v34 )
          {
            v35 = a4;
            v36 = a3;
            if ( *((_DWORD *)v34 - 1) != 329685504 )
              __break(0x8228u);
            v34(a1);
            a3 = v36;
            a4 = v35;
          }
        }
        break;
      case 0x1Bu:
        break;
      case 0x1Cu:
        if ( (*(_BYTE *)(v12 + 60) & 2) == 0 )
          return 0;
        v15 = a4;
        v16 = a3;
        wlan_sm_transition_to(a1[63], 3u, a5, a6, a7, a8, a9, a10, a11, a12);
        if ( (unsigned int)wlan_sm_dispatch(a1[63], 0x1Cu, v16, v15, v17, v18, v19, v20, v21, v22, v23, v24) )
        {
          wlan_sm_transition_to(a1[63], 0, v25, v26, v27, v28, v29, v30, v31, v32);
          return 0;
        }
        return 1;
      default:
        return result;
    }
    goto LABEL_17;
  }
  if ( a2 )
  {
    if ( a2 == 5 )
    {
LABEL_17:
      v37 = a1[66];
      if ( v37 )
      {
        v38 = *(_DWORD **)(v37 + 136);
        if ( v38 )
        {
          if ( *(v38 - 1) != -1256047138 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64 *, _QWORD, __int64))v38)(a1, a3, a4);
        }
      }
      v39 = a1[65];
      if ( *(_DWORD *)(v39 + 16) == 1 && (wlan_vdev_mlme_is_mlo_vdev(v39, a5, a6, a7, a8, a9, a10, a11, a12) & 1) != 0 )
        mlo_ap_link_down_cmpl_notify(a1[65]);
      return 1;
    }
  }
  else
  {
    v40 = (_DWORD **)a1[66];
    v41 = a3;
    v42 = a4;
    if ( !v40 )
      goto LABEL_35;
    v43 = *v40;
    if ( !v43 )
      goto LABEL_35;
    v44 = *(_DWORD *)(v12 + 16);
    if ( *(v43 - 1) != -1256047138 )
      __break(0x8229u);
    if ( !((unsigned int (__fastcall *)(__int64 *, _QWORD, __int64))v43)(a1, a3, a4) )
    {
LABEL_35:
      wlan_sm_transition_to(a1[63], 1u, a5, a6, a7, a8, a9, a10, a11, a12);
      wlan_sm_dispatch(a1[63], 1u, v41, v42, v48, v49, v50, v51, v52, v53, v54, v55);
      return 1;
    }
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
    v45 = a1[66];
    result = v44 != 0;
    if ( v45 )
    {
      v46 = *(_DWORD **)(v45 + 136);
      if ( v46 )
      {
        v47 = v44 != 0;
        if ( *(v46 - 1) != -1256047138 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64 *, _QWORD, __int64))v46)(a1, v41, v42);
        return v47;
      }
    }
  }
  return result;
}
