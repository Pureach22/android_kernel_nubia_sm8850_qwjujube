__int64 __fastcall csr_get_cmd_type(__int64 a1)
{
  int v1; // w9
  __int64 result; // x0
  int v4; // w8
  unsigned int v5; // w9

  v1 = *(_DWORD *)(a1 + 16);
  result = 34;
  if ( v1 <= 262146 )
  {
    if ( v1 > 0x40000 )
    {
      if ( v1 == 262145 )
        return 11;
      else
        return 12;
    }
    else if ( v1 == 65537 )
    {
      v4 = *(_DWORD *)(a1 + 32);
      if ( v4 == 2 )
        v5 = 3;
      else
        v5 = 34;
      if ( v4 == 1 )
        return 2;
      else
        return v5;
    }
    else if ( v1 == 65538 )
    {
      return 5;
    }
  }
  else if ( v1 <= 262148 )
  {
    if ( v1 == 262147 )
      return 16;
    else
      return 17;
  }
  else
  {
    switch ( v1 )
    {
      case 262149:
        return 18;
      case 262150:
        return 19;
      case 262151:
        return 31;
    }
  }
  return result;
}
