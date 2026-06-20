__int64 __fastcall wma_map_pcl_weights(__int64 result)
{
  if ( (int)result <= 214 )
  {
    if ( (_DWORD)result == 1 )
      return result;
    if ( (_DWORD)result != 195 )
      return 0;
    return 2;
  }
  switch ( (_DWORD)result )
  {
    case 0xD7:
      return 2;
    case 0xFF:
      return 4;
    case 0xEB:
      return 3;
  }
  return 0;
}
