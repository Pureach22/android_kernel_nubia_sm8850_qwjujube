__int64 __fastcall cfg80211_change_iface(__int64 *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  int v5; // w19
  unsigned int v6; // w8
  unsigned int v8; // w20
  __int64 *v9; // x21
  __int64 *v10; // x22
  __int64 v11; // x23
  __int64 v12; // x8
  __int64 *v13; // x0
  __int64 (__fastcall *v14)(_QWORD); // x8
  unsigned int v15; // w0
  __int64 v16; // x23
  _QWORD *v17; // x24
  _QWORD *i; // x25
  _QWORD *v19; // x8
  __int64 v20; // x8
  __int64 *v21; // x0
  __int64 v22; // x23
  __int64 (__fastcall *v23)(__int64 *, __int64, __int64); // x8
  int v24; // w8
  __int64 v25; // x8

  v4 = *(_QWORD *)(a2 + 992);
  v5 = *(_DWORD *)(v4 + 8);
  if ( v5 == 4 )
    return (unsigned int)-95;
  v6 = -95;
  if ( (_DWORD)a3 != 10 && (_DWORD)a3 != 12 )
  {
    if ( !*(_QWORD *)(*a1 + 40) || ((*((unsigned __int16 *)a1 + 544) >> a3) & 1) == 0 )
      return (unsigned int)-95;
    v8 = a3;
    v9 = a1;
    v10 = (__int64 *)a2;
    if ( v5 == (_DWORD)a3 )
    {
LABEL_33:
      v20 = *a1;
      v21 = a1 + 124;
      v22 = a4;
      v23 = *(__int64 (__fastcall **)(__int64 *, __int64, __int64))(v20 + 40);
      if ( *((_DWORD *)v23 - 1) != -783753813 )
        __break(0x8228u);
      v6 = v23(v21, a2, a3);
      if ( v6 )
        return v6;
      if ( *(_DWORD *)(v10[124] + 8) == v8 )
      {
        if ( !v22 )
          goto LABEL_40;
      }
      else
      {
        __break(0x800u);
        if ( !v22 )
          goto LABEL_40;
      }
      v24 = *(_DWORD *)(v22 + 4);
      if ( v24 != -1 )
        *(_BYTE *)(v10[124] + 65) = v24 != 0;
LABEL_40:
      v25 = *v10;
      *v10 &= ~0x40uLL;
      if ( v8 > 0xC )
        goto LABEL_47;
      if ( ((1 << v8) & 0x902) == 0 )
      {
        if ( ((1 << v8) & 0x1420) != 0 )
        {
          __break(0x800u);
          goto LABEL_47;
        }
        if ( v8 != 2 || (*(_BYTE *)(v10[124] + 65) & 1) != 0 )
          goto LABEL_47;
      }
      *v10 = v25 | 0x40;
LABEL_47:
      if ( v5 != v8 && (v10[21] & 1) != 0 )
      {
        cfg80211_update_iface_num((__int64)v9, v8, 1);
        cfg80211_update_iface_num((__int64)v9, v5, -1);
      }
      return 0;
    }
    if ( (*(_BYTE *)(a2 + 1) & 2) != 0 && (unsigned int)a3 <= 8 && ((1 << a3) & 0x106) != 0 )
      return (unsigned int)-16;
    *(_BYTE *)(v4 + 65) = 0;
    if ( *(_QWORD *)(*a1 + 736) )
    {
      v11 = a4;
      v12 = *a1;
      v13 = a1 + 124;
      v14 = *(__int64 (__fastcall **)(_QWORD))(v12 + 736);
      if ( *((_DWORD *)v14 - 1) != -824243271 )
        __break(0x8228u);
      v15 = v14(v13);
      a2 = (__int64)v10;
      a3 = v15;
      a1 = v9;
      a4 = v11;
    }
    if ( v5 > 7 )
    {
      if ( v5 != 8 )
      {
        v16 = a4;
        if ( v5 == 11 )
        {
          cfg80211_leave_ocb(v9, a2);
          goto LABEL_29;
        }
        if ( v5 != 9 )
        {
LABEL_30:
          v17 = (_QWORD *)a1[291];
          for ( i = a1 + 291; v17 != i; v17 = (_QWORD *)*v17 )
            ((void (__fastcall *)(_QWORD *, __int64, __int64))cfg80211_process_wdev_events)(v17 - 2, a2, a3);
          ((void (__fastcall *)(__int64, __int64, __int64))cfg80211_mlme_purge_registrations)(v10[124], a2, a3);
          v19 = (_QWORD *)v10[124];
          v19[47] = 0;
          v19[48] = 0;
          v19[45] = 0;
          v19[46] = 0;
          v19[43] = 0;
          v19[44] = 0;
          v19[41] = 0;
          v19[42] = 0;
          v19[39] = 0;
          v19[40] = 0;
          v19[37] = 0;
          v19[38] = 0;
          v19[35] = 0;
          v19[36] = 0;
          memset((void *)(v10[124] + 392), 0, 0x438u);
          a2 = (__int64)v10;
          a3 = v8;
          a1 = v9;
          a4 = v16;
          goto LABEL_33;
        }
        goto LABEL_25;
      }
    }
    else
    {
      if ( v5 == 1 )
      {
        v16 = a4;
        cfg80211_leave_ibss(v9, a2);
        goto LABEL_29;
      }
      if ( v5 != 2 )
      {
        v16 = a4;
        if ( v5 != 3 )
          goto LABEL_30;
LABEL_25:
        cfg80211_stop_ap((__int64)v9, (__int64)v10, 0xFFFFFFFFLL, 1);
LABEL_29:
        a1 = v9;
        goto LABEL_30;
      }
    }
    v16 = a4;
    cfg80211_disconnect(v9, a2, 3u);
    goto LABEL_29;
  }
  return v6;
}
