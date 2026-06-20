__int64 __fastcall ieee80211_set_radar_background(__int64 a1)
{
  __int64 (__fastcall *v1)(_QWORD); // x8
  __int64 v2; // x0
  __int64 v4; // x0

  if ( a1 )
  {
    v1 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 2000) + 904LL);
    if ( v1 )
    {
      v2 = a1 + 1536;
      if ( *((_DWORD *)v1 - 1) != 564822973 )
        __break(0x8228u);
      return v1(v2);
    }
    else
    {
      return 4294967201LL;
    }
  }
  else
  {
    __break(0x800u);
    v4 = MEMORY[0x14C4DA4]();
    return ieee80211_add_link_station(v4);
  }
}
