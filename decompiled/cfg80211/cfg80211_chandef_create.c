__int64 __fastcall cfg80211_chandef_create(__int64 result, __int64 a2, int a3)
{
  unsigned __int16 v3; // w8

  if ( a2 )
  {
    v3 = *(_WORD *)(a2 + 8);
    *(_QWORD *)result = a2;
    *(_QWORD *)(result + 8) = 0;
    *(_QWORD *)(result + 16) = 0;
    *(_DWORD *)(result + 24) = 0;
    *(_DWORD *)(result + 28) = v3;
    if ( a3 > 1 )
    {
      if ( a3 == 2 )
      {
        *(_DWORD *)(result + 8) = 2;
        *(_DWORD *)(result + 12) = *(_DWORD *)(a2 + 4) - 10;
        return result;
      }
      if ( a3 == 3 )
      {
        *(_DWORD *)(result + 8) = 2;
        *(_DWORD *)(result + 12) = *(_DWORD *)(a2 + 4) + 10;
        return result;
      }
    }
    else
    {
      if ( !a3 )
      {
LABEL_6:
        *(_DWORD *)(result + 12) = *(_DWORD *)(a2 + 4);
        return result;
      }
      if ( a3 == 1 )
      {
        *(_DWORD *)(result + 8) = 1;
        goto LABEL_6;
      }
    }
  }
  __break(0x800u);
  return result;
}
