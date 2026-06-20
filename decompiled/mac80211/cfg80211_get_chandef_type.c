__int64 __fastcall cfg80211_get_chandef_type(unsigned int *a1)
{
  __int64 result; // x0

  result = a1[2];
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result == 2 )
    {
      if ( a1[3] <= *(_DWORD *)(*(_QWORD *)a1 + 4LL) )
        return 2;
      else
        return 3;
    }
    else if ( (_DWORD)result != 1 )
    {
      result = 0;
      __break(0x800u);
    }
  }
  return result;
}
