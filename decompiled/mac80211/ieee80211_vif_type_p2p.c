__int64 __fastcall ieee80211_vif_type_p2p(unsigned int *a1)
{
  int v1; // w8
  __int64 result; // x0

  v1 = *((unsigned __int8 *)a1 + 1128);
  result = *a1;
  if ( v1 == 1 )
  {
    if ( (_DWORD)result == 2 )
    {
      return 8;
    }
    else if ( (_DWORD)result == 3 )
    {
      return 9;
    }
  }
  return result;
}
