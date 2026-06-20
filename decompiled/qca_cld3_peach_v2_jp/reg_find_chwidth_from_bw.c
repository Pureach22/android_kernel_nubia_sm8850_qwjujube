__int64 __fastcall reg_find_chwidth_from_bw(__int64 result)
{
  result = (unsigned __int16)result;
  if ( (unsigned __int16)result > 0x27u )
  {
    switch ( (unsigned __int16)result )
    {
      case 0x28u:
        return 1;
      case 0x50u:
        return 2;
      case 0xA0u:
        return 3;
    }
  }
  else
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
  return 8;
}
