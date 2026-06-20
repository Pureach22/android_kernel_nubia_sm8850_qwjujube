__int64 __fastcall ieee80211_testmode_dump(__int64 a1, __int64 a2, __int64 a3)
{
  char v3; // b13
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0

  if ( a1 )
  {
    v4 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 2000) + 424LL);
    if ( v4 )
    {
      v5 = a1 + 1536;
      if ( *((_DWORD *)v4 - 1) != -1568538990 )
        __break(0x8228u);
      return v4(v5);
    }
    else
    {
      return 4294967201LL;
    }
  }
  else
  {
    __break(0x800u);
    *(_BYTE *)(a3 + 199) = v3;
    return ieee80211_set_bitrate_mask(0, a2, a3 + 199);
  }
}
