__int64 __fastcall hfi_map_err_status(__int64 result)
{
  char v1; // w8

  if ( (int)result > 4097 )
  {
    v1 = result - 4;
    if ( (unsigned int)(result - 4100) <= 9 )
    {
      if ( ((1 << v1) & 0x238) != 0 )
        return 2147483653LL;
      if ( ((1 << v1) & 3) != 0 )
        return 2147483651LL;
      if ( (_DWORD)result == 4102 )
        return 2147483654LL;
    }
    if ( (_DWORD)result != 4098 && (_DWORD)result != 4099 )
      return 0x80000000LL;
    return 2147483651LL;
  }
  if ( (int)result > 4 )
  {
    if ( (int)result <= 6 )
    {
      if ( (_DWORD)result == 5 )
        return 2147483655LL;
      else
        return 2415919105LL;
    }
    if ( (_DWORD)result != 7 )
    {
      if ( (_DWORD)result == 20 )
        return 2147483667LL;
      if ( (_DWORD)result == 4097 )
        return 2415919106LL;
      return 0x80000000LL;
    }
    return 2147483651LL;
  }
  if ( (int)result > 1 )
  {
    if ( (unsigned int)(result - 2) >= 2 )
      return 2147483653LL;
    return 2147483651LL;
  }
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result == 1 )
      return 2147483657LL;
    return 0x80000000LL;
  }
  return result;
}
