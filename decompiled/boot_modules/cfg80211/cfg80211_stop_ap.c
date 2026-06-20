__int64 __fastcall cfg80211_stop_ap(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  unsigned int v7; // w22
  __int64 v8; // x8
  unsigned int v9; // w23
  unsigned int v10; // w9
  bool v11; // w10
  unsigned int v12; // w0

  if ( (a3 & 0x80000000) != 0 )
  {
    v8 = *(_QWORD *)(a2 + 992);
    v9 = 0;
    v7 = 0;
    v10 = *(unsigned __int16 *)(v8 + 1472);
    v11 = *(_WORD *)(v8 + 1472) == 0;
    do
    {
      if ( v11 || (((unsigned __int64)v10 >> v9) & 1) != 0 )
      {
        v12 = __cfg80211_stop_ap(a1, a2, v9, a4 & 1);
        v8 = *(_QWORD *)(a2 + 992);
        if ( v12 )
          v7 = v12;
      }
      v10 = *(unsigned __int16 *)(v8 + 1472);
      v11 = *(_WORD *)(v8 + 1472) == 0;
      if ( !*(_WORD *)(v8 + 1472) )
        break;
    }
    while ( v9++ < 0xE );
  }
  else
  {
    return (unsigned int)__cfg80211_stop_ap(a1, a2, a3, a4 & 1);
  }
  return v7;
}
