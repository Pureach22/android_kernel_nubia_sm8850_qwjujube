__int64 __fastcall ieee80211_set_sar_specs(__int64 a1)
{
  __int64 (__fastcall *v1)(_QWORD); // x8
  __int64 v2; // x0

  if ( a1 )
  {
    v1 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 2000) + 872LL);
    if ( v1 )
    {
      v2 = a1 + 1536;
      if ( *((_DWORD *)v1 - 1) != 615294861 )
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
    return ieee80211_color_change();
  }
}
