void *__fastcall ieee80211_get_strings(void *result, unsigned int a2, char *dest)
{
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v7; // x19
  __int64 v8; // x0
  _DWORD *v9; // x8

  v5 = (__int64)result;
  if ( a2 == 1 )
  {
    v6 = 672;
    result = memcpy(dest, "rx_packets", 0x2A0u);
  }
  else
  {
    v6 = 0;
  }
  v7 = *(_QWORD *)(v5 + 4304);
  if ( *(_QWORD *)(*(_QWORD *)(v7 + 464) + 560LL) )
  {
    v8 = *(_QWORD *)(v5 + 4304);
    v9 = *(_DWORD **)(*(_QWORD *)(v7 + 464) + 560LL);
    if ( *(v9 - 1) != 1769265932 )
      __break(0x8228u);
    return (void *)((__int64 (__fastcall *)(__int64, __int64, _QWORD, char *))v9)(v8, v5 + 7408, a2, &dest[v6]);
  }
  return result;
}
