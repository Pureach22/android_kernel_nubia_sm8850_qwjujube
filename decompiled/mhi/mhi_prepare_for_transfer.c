__int64 __fastcall mhi_prepare_for_transfer(__int64 *a1)
{
  __int64 v1; // x1
  __int64 v2; // x19
  __int64 result; // x0
  __int64 v5; // x1
  __int64 v6; // x1
  unsigned int v7; // w20

  v2 = a1[2];
  v1 = a1[3];
  if ( !v1 || (result = mhi_prepare_channel(a1[2], v1, 0), !(_DWORD)result) )
  {
    v5 = a1[4];
    if ( v5 )
    {
      result = mhi_prepare_channel(v2, v5, 0);
      if ( (_DWORD)result )
      {
        v6 = a1[3];
        if ( v6 )
        {
          v7 = result;
          mhi_unprepare_channel(v2, v6);
          return v7;
        }
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
