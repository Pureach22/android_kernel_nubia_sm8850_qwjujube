__int64 __fastcall ieee80211_ap_probereq_get(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x8
  _QWORD *v4; // x8
  _QWORD *v5; // x20
  __int64 elem; // x0
  __int64 v8; // x21
  unsigned int v9; // w1
  __int64 v10; // x6
  __int64 v11; // x19

  if ( *(_DWORD *)a2 != 2 || *(_WORD *)(a2 + 1080) )
  {
    __break(0x800u);
    return 0;
  }
  if ( (*(_BYTE *)(a2 - 2243) & 8) != 0 )
  {
    v3 = (_QWORD *)(*(_QWORD *)(a2 - 160) + 8LL);
  }
  else
  {
    v3 = *(_QWORD **)(a2 - 2240);
    if ( !v3 )
    {
      v4 = *(_QWORD **)(a2 - 2232);
      if ( !v4 )
        return 0;
      v5 = (_QWORD *)*v4;
      if ( !*v4 )
        return 0;
      goto LABEL_11;
    }
  }
  v5 = (_QWORD *)*v3;
LABEL_11:
  _rcu_read_lock(a1, a2);
  elem = ieee80211_bss_get_elem(v5, 0);
  v8 = elem;
  if ( elem )
  {
    v9 = *(unsigned __int8 *)(elem + 1);
    if ( v9 < 0x21 || (ieee80211_ap_probereq_get___already_done & 1) != 0 )
    {
      if ( v9 >= 0x21 )
        v10 = 0;
      else
        v10 = *(unsigned __int8 *)(elem + 1);
    }
    else
    {
      ieee80211_ap_probereq_get___already_done = 1;
      _warn_printk("invalid SSID element (len=%d)", v9);
      v10 = 0;
      __break(0x800u);
    }
  }
  else if ( (ieee80211_ap_probereq_get___already_done & 1) != 0 )
  {
    v10 = 0;
  }
  else
  {
    ieee80211_ap_probereq_get___already_done = 1;
    _warn_printk("invalid SSID element (len=%d)", -1);
    v10 = 0;
    __break(0x800u);
  }
  v11 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64, _QWORD, __int64, __int64, _QWORD, _QWORD, int))ieee80211_build_probe_req)(
          a2 - 4720,
          a2 + 1122,
          v5 + 9,
          0xFFFFFFFFLL,
          *v5,
          v8 + 2,
          v10,
          0,
          0,
          1);
  _rcu_read_unlock(v11);
  return v11;
}
