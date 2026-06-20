__int64 __fastcall ieee80211_check_wbrf_support(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(result + 72);
  if ( v1 )
  {
    if ( *(_QWORD *)(v1 + 488) )
      *(_BYTE *)(result + 5464) = 0;
  }
  return result;
}
