bool __fastcall mlme_vdev_subst_up_active_event(
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
  _BOOL8 result; // x0
  __int64 v16; // x0
  unsigned int v17; // w1
  __int64 v18; // x8
  _DWORD *v19; // x8
  __int64 v20; // x8
  _DWORD *v21; // x8
  __int64 v23; // x0
  _QWORD *v24; // x8
  _DWORD *v25; // x9
  _DWORD *v26; // x9
  _DWORD *v27; // x8
  __int64 v28; // x0
  __int64 v29; // x8
  _DWORD *v30; // x8

  result = 0;
  if ( (unsigned __int16)a2 <= 0x14u )
  {
    if ( (unsigned __int16)a2 <= 0x11u )
    {
      if ( (_WORD)a2 )
      {
        if ( (unsigned __int16)a2 != 7 )
        {
          if ( (unsigned __int16)a2 != 12 )
            return result;
          goto LABEL_28;
        }
        v23 = a1[65];
        if ( *(_DWORD *)(v23 + 16) == 1 )
          wlan_vdev_mlme_is_mlo_vdev(v23, a5, a6, a7, a8, a9, a10, a11, a12);
        goto LABEL_32;
      }
LABEL_19:
      v20 = a1[66];
      if ( v20 )
      {
        v21 = *(_DWORD **)(v20 + 72);
        if ( v21 )
        {
          if ( *(v21 - 1) != -1256047138 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64 *, _QWORD, __int64))v21)(a1, a3, a4);
        }
      }
      return 1;
    }
    if ( (unsigned int)(unsigned __int16)a2 - 18 >= 2 )
    {
      if ( (unsigned __int16)a2 != 20 )
        return result;
      v18 = a1[66];
      if ( v18 )
      {
        v19 = *(_DWORD **)(v18 + 88);
        if ( v19 )
        {
          if ( *(v19 - 1) != 801230058 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64 *, __int64, _QWORD))v19)(a1, 2, a3);
        }
      }
      goto LABEL_19;
    }
LABEL_28:
    wlan_sm_transition_to(a1[63], 4u, a5, a6, a7, a8, a9, a10, a11, a12);
    v16 = a1[63];
    v17 = a2;
LABEL_51:
    wlan_sm_dispatch(v16, v17, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
    return 1;
  }
  if ( (unsigned __int16)a2 <= 0x17u )
  {
    if ( (unsigned __int16)a2 == 21 )
    {
      wlan_sm_transition_to(a1[63], 1u, a5, a6, a7, a8, a9, a10, a11, a12);
      v16 = a1[63];
      v17 = 2;
      goto LABEL_51;
    }
    if ( (unsigned __int16)a2 != 22 )
    {
      if ( (unsigned __int16)a2 != 23 )
        return result;
      wlan_sm_transition_to(a1[63], 4u, a5, a6, a7, a8, a9, a10, a11, a12);
      v16 = a1[63];
      v17 = 24;
      goto LABEL_51;
    }
    wlan_sm_transition_to(a1[63], 4u, a5, a6, a7, a8, a9, a10, a11, a12);
    goto LABEL_50;
  }
  if ( (unsigned __int16)a2 == 24 )
    goto LABEL_28;
  if ( (unsigned __int16)a2 != 28 )
  {
    if ( (unsigned __int16)a2 != 31 )
      return result;
LABEL_32:
    v24 = (_QWORD *)a1[66];
    if ( !v24 )
      goto LABEL_46;
    v25 = (_DWORD *)v24[11];
    if ( v25 )
    {
      if ( *(v25 - 1) != 801230058 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64 *, _QWORD, _QWORD, __int64))v25)(a1, 0, a3, a4);
      v24 = (_QWORD *)a1[66];
      if ( !v24 )
        goto LABEL_46;
    }
    v26 = (_DWORD *)v24[8];
    if ( !v26 )
      goto LABEL_42;
    if ( *(v26 - 1) != -1256047138 )
      __break(0x8229u);
    if ( !((unsigned int (__fastcall *)(__int64 *, _QWORD, __int64))v26)(a1, a3, a4) )
    {
      v24 = (_QWORD *)a1[66];
      if ( !v24 )
      {
LABEL_46:
        v28 = a1[65];
        if ( !*(_DWORD *)(v28 + 16) && (wlan_vdev_mlme_is_mlo_vdev(v28, a5, a6, a7, a8, a9, a10, a11, a12) & 1) != 0 )
          mlo_sta_up_active_notify(a1[65]);
        return 1;
      }
LABEL_42:
      v27 = (_DWORD *)v24[9];
      if ( v27 )
      {
        if ( *(v27 - 1) != -1256047138 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64 *, _QWORD, __int64))v27)(a1, a3, a4);
      }
      goto LABEL_46;
    }
LABEL_50:
    v16 = a1[63];
    v17 = 22;
    goto LABEL_51;
  }
  v29 = a1[66];
  if ( !v29 )
    return 1;
  v30 = *(_DWORD **)(v29 + 80);
  if ( !v30 )
    return 1;
  if ( *(v30 - 1) != -1256047138 )
    __break(0x8228u);
  return ((unsigned int (__fastcall *)(__int64 *, _QWORD, __int64))v30)(a1, a3, a4) == 0;
}
