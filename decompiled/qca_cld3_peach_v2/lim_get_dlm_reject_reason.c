__int64 __fastcall lim_get_dlm_reject_reason(unsigned __int16 a1)
{
  if ( a1 > 0x81u )
  {
    if ( a1 == 139 )
      return 17;
    if ( a1 != 135 )
    {
      if ( a1 == 130 )
        return 15;
      return 0;
    }
    return 16;
  }
  else
  {
    if ( a1 == 12 )
      return 14;
    if ( a1 != 17 )
    {
      if ( a1 == 18 )
        return 13;
      return 0;
    }
    return 12;
  }
}
