__int64 __fastcall cfg80211_remove_virtual_intf(__int64 a1, __int64 a2)
{
  unsigned int v4; // w8
  unsigned __int64 v5; // x21
  __int64 (__fastcall *v7)(__int64, __int64); // x8

  if ( *(_DWORD *)(a2 + 8) == 3 )
  {
    v4 = *(unsigned __int16 *)(a2 + 1472);
    if ( *(_WORD *)(a2 + 1472) )
    {
      v5 = 0;
      do
      {
        if ( ((v4 >> v5) & 1) != 0 )
        {
          cfg80211_remove_link(a2, v5);
          v4 = *(unsigned __int16 *)(a2 + 1472);
        }
        if ( !v4 )
          break;
      }
      while ( v5++ < 0xE );
    }
  }
  v7 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)a1 + 32LL);
  if ( *((_DWORD *)v7 - 1) != -520763295 )
    __break(0x8228u);
  return v7(a1 + 992, a2);
}
