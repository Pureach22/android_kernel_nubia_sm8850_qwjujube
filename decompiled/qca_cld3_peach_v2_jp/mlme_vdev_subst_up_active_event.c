__int64 __fastcall mlme_vdev_subst_up_active_event(
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
  unsigned int v14; // w21
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
  __int64 v28; // x21
  _QWORD *v29; // x8
  void (*v30)(void); // x9
  __int64 v31; // x21
  unsigned int (*v32)(void); // x9
  __int64 v33; // x21
  _DWORD *v34; // x8
  __int64 v35; // x22
  __int64 v37; // x22
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v47; // x8
  __int64 (*v48)(void); // x8

  v14 = 0;
  if ( (unsigned __int16)a2 > 0x14u )
  {
    if ( (unsigned __int16)a2 <= 0x17u )
    {
      switch ( (unsigned __int16)a2 )
      {
        case 0x15u:
          v37 = a1;
          v14 = 1;
          wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 1u, a5, a6, a7, a8, a9, a10, a11, a12);
          wlan_sm_dispatch(*(_QWORD *)(v37 + 488), 2u, a3, a4, v38, v39, v40, v41, v42, v43, v44, v45);
          break;
        case 0x16u:
          v33 = a1;
          wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 4u, a5, a6, a7, a8, a9, a10, a11, a12);
          goto LABEL_41;
        case 0x17u:
          v15 = a1;
          wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 4u, a5, a6, a7, a8, a9, a10, a11, a12);
          v24 = *(_QWORD *)(v15 + 488);
          v25 = 24;
LABEL_42:
          wlan_sm_dispatch(v24, v25, a3, a4, v16, v17, v18, v19, v20, v21, v22, v23);
          return 1;
      }
      return v14;
    }
    if ( (unsigned __int16)a2 != 24 )
    {
      if ( (unsigned __int16)a2 == 28 )
      {
        v47 = *(_QWORD *)(a1 + 512);
        if ( !v47 )
          return 1;
        v48 = *(__int64 (**)(void))(v47 + 80);
        if ( !v48 )
          return 1;
        if ( *((_DWORD *)v48 - 1) != -1256047138 )
          __break(0x8228u);
        return (unsigned int)v48() == 0;
      }
      else if ( (unsigned __int16)a2 == 31 )
      {
        goto LABEL_24;
      }
      return v14;
    }
LABEL_38:
    v35 = a1;
    wlan_sm_transition_to(*(_QWORD *)(a1 + 488), 4u, a5, a6, a7, a8, a9, a10, a11, a12);
    v24 = *(_QWORD *)(v35 + 488);
    v25 = a2;
    goto LABEL_42;
  }
  if ( (unsigned __int16)a2 <= 0x11u )
  {
    if ( (_WORD)a2 )
    {
      if ( (unsigned __int16)a2 != 7 )
      {
        if ( (unsigned __int16)a2 != 12 )
          return v14;
        goto LABEL_38;
      }
LABEL_24:
      v29 = *(_QWORD **)(a1 + 512);
      if ( !v29 )
        return 1;
      v30 = (void (*)(void))v29[11];
      if ( v30 )
      {
        v31 = a1;
        if ( *((_DWORD *)v30 - 1) != 801230058 )
          __break(0x8229u);
        v30();
        v29 = *(_QWORD **)(v31 + 512);
        a1 = v31;
        if ( !v29 )
          return 1;
      }
      v32 = (unsigned int (*)(void))v29[8];
      if ( !v32 )
        goto LABEL_34;
      v33 = a1;
      if ( *((_DWORD *)v32 - 1) != -1256047138 )
        __break(0x8229u);
      if ( !v32() )
      {
        v29 = *(_QWORD **)(v33 + 512);
        a1 = v33;
        if ( !v29 )
          return 1;
LABEL_34:
        v34 = (_DWORD *)v29[9];
        if ( v34 )
        {
          if ( *(v34 - 1) != -1256047138 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64))v34)(a1, a3, a4);
        }
        return 1;
      }
LABEL_41:
      v24 = *(_QWORD *)(v33 + 488);
      v25 = 22;
      goto LABEL_42;
    }
LABEL_19:
    v29 = *(_QWORD **)(a1 + 512);
    if ( !v29 )
      return 1;
    goto LABEL_34;
  }
  if ( (unsigned int)(unsigned __int16)a2 - 18 < 2 )
    goto LABEL_38;
  if ( (unsigned __int16)a2 == 20 )
  {
    v26 = *(_QWORD *)(a1 + 512);
    if ( v26 )
    {
      v27 = *(void (**)(void))(v26 + 88);
      if ( v27 )
      {
        v28 = a1;
        if ( *((_DWORD *)v27 - 1) != 801230058 )
          __break(0x8228u);
        v27();
        a1 = v28;
      }
    }
    goto LABEL_19;
  }
  return v14;
}
