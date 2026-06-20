_QWORD *__fastcall _ieee80211_set_default_key(_QWORD *result, unsigned int a2, char a3, char a4)
{
  __int64 v4; // x22
  _QWORD *v7; // x19
  unsigned __int64 v8; // x24
  __int64 v9; // x23
  _DWORD *v10; // x8
  __int64 v11; // x9
  __int64 v12; // x1

  v4 = *result;
  v7 = result;
  if ( a2 > 3 )
  {
    v8 = 0;
  }
  else
  {
    v8 = *(_QWORD *)(v4 + 8LL * a2 + 1896);
    if ( !v8 )
      v8 = result[a2 + 6];
  }
  if ( (a3 & 1) != 0 )
  {
    atomic_store(v8, (unsigned __int64 *)(v4 + 1928));
    result = (_QWORD *)ieee80211_check_fast_xmit_iface(v4);
    if ( *(_DWORD *)(v4 + 4720) != 4 )
    {
      v9 = *(_QWORD *)(v4 + 1616);
      if ( (*(_BYTE *)(v9 + 1471) & 1) != 0
        || (*(_DWORD *)(v4 + 1624) & 0x20) != 0
        || (drv_set_default_unicast_key___already_done & 1) != 0 )
      {
        if ( (*(_BYTE *)(v4 + 1624) & 0x20) == 0 )
          goto LABEL_17;
      }
      else
      {
        v11 = *(_QWORD *)(v4 + 1608);
        drv_set_default_unicast_key___already_done = 1;
        if ( v11 )
          v12 = v11 + 296;
        else
          v12 = v4 + 1640;
        result = (_QWORD *)_warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v12);
        __break(0x800u);
        if ( (*(_BYTE *)(v4 + 1624) & 0x20) == 0 )
          goto LABEL_17;
      }
      if ( a2 - 4 <= 0xFFFFFFFA )
        __break(0x800u);
      v10 = *(_DWORD **)(*(_QWORD *)(v9 + 464) + 176LL);
      if ( v10 )
      {
        if ( *(v10 - 1) != 1395581230 )
          __break(0x8228u);
        result = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))v10)(v9, v4 + 4720, a2);
      }
    }
  }
LABEL_17:
  if ( (a4 & 1) != 0 )
    atomic_store(v8, v7 + 14);
  return result;
}
