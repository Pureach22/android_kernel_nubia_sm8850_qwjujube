unsigned __int64 __fastcall ieee80211_recalc_dtim(__int64 a1, __int64 a2)
{
  unsigned __int64 result; // x0
  unsigned __int64 v4; // x9
  __int64 v5; // x10
  unsigned __int64 v6; // x8
  int v7; // w9
  int v8; // w8

  result = drv_get_tsf(a1, a2);
  if ( result != -1 )
  {
    if ( *(_WORD *)(a2 + 4858) << 10 )
    {
      v4 = *(unsigned __int8 *)(a2 + 4857);
      if ( *(_BYTE *)(a2 + 4857) )
      {
        if ( (unsigned int)(*(_DWORD *)(a2 + 4720) - 3) <= 1 )
        {
          v5 = *(_QWORD *)(a2 + 2032);
          if ( v5 )
          {
            v6 = result / (unsigned __int16)(*(_WORD *)(a2 + 4858) << 10) % v4;
            v7 = v4 - v6;
            if ( v6 )
              v8 = v7;
            else
              v8 = 0;
            *(_DWORD *)(v5 + 300) = v8;
          }
        }
      }
    }
  }
  return result;
}
