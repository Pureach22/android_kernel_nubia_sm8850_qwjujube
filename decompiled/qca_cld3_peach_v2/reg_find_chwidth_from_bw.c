__int64 __fastcall reg_find_chwidth_from_bw(__int64 result)
{
  result = (unsigned __int16)result;
  if ( (unsigned __int16)result <= 0x27u )
  {
    switch ( (unsigned __int16)result )
    {
      case 5u:
        return result;
      case 0xAu:
        return 6;
      case 0x14u:
        return 0;
    }
  }
  else if ( (unsigned __int16)result > 0x9Fu )
  {
    if ( (unsigned __int16)result == 160 )
      return 3;
    if ( (unsigned __int16)result == 320 )
      return 7;
  }
  else
  {
    if ( (unsigned __int16)result == 40 )
      return 1;
    if ( (unsigned __int16)result == 80 )
      return 2;
  }
  return 8;
}
