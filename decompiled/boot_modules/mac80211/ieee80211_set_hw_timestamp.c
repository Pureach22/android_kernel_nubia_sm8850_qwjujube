__int64 __fastcall ieee80211_set_hw_timestamp(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  int v3; // w8
  __int64 (*v5)(void); // x8
  __int64 v6; // x10
  __int64 v7; // x19
  const char *v8; // x9
  __int64 v9; // x20

  v2 = *(_QWORD *)(a2 + 4304);
  if ( !*(_QWORD *)(*(_QWORD *)(v2 + 464) + 944LL) )
    return 4294967201LL;
  if ( (*(_BYTE *)(v2 + 1471) & 1) == 0 )
  {
    v3 = *(_DWORD *)(a2 + 4312);
    if ( (v3 & 0x20) == 0 && (ieee80211_set_hw_timestamp___already_done & 1) == 0 )
    {
      v6 = *(_QWORD *)(a2 + 4296);
      ieee80211_set_hw_timestamp___already_done = 1;
      v7 = v2;
      if ( v6 )
        v8 = (const char *)(v6 + 296);
      else
        v8 = (const char *)(a2 + 4328);
      v9 = a2;
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v8, v3);
      a2 = v9;
      v2 = v7;
      __break(0x800u);
    }
  }
  if ( (*(_BYTE *)(a2 + 4312) & 0x20) == 0 )
    return 4294967291LL;
  v5 = *(__int64 (**)(void))(*(_QWORD *)(v2 + 464) + 944LL);
  if ( *((_DWORD *)v5 - 1) != 1987188786 )
    __break(0x8228u);
  return v5();
}
