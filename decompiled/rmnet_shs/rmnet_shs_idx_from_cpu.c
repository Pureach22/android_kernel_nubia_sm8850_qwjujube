__int64 __fastcall rmnet_shs_idx_from_cpu(char a1, unsigned __int8 a2)
{
  bool v3; // zf
  __int64 result; // x0
  unsigned int v5; // w10

  if ( ((a2 >> a1) & 1) == 0 )
    return 0xFFFFFFFFLL;
  v3 = a1 == 0;
  result = a2 & 1;
  if ( v3 )
  {
    if ( (a2 & 1) != 0 )
      return 0;
    return 0xFFFFFFFFLL;
  }
  if ( a1 == 1 )
  {
    if ( (a2 & 2) != 0 )
      return result;
    return 0xFFFFFFFFLL;
  }
  result = (unsigned int)result + ((unsigned __int8)(a2 & 2) >> 1);
  v5 = a2 & 4;
  if ( a1 == 2
    || (result = (unsigned int)result + (v5 >> 2), v5 = a2 & 8, a1 == 3)
    || (result = (unsigned int)result + (v5 >> 3), v5 = a2 & 0x10, a1 == 4)
    || (result = (unsigned int)result + (v5 >> 4), v5 = a2 & 0x20, a1 == 5) )
  {
    if ( !v5 )
      return 0xFFFFFFFFLL;
  }
  else
  {
    result = (unsigned int)result + (v5 >> 5);
    if ( a1 == 7 )
    {
      if ( (a2 & 0x80) != 0 )
        return (unsigned int)result + ((unsigned __int8)(a2 & 0x40) >> 6);
      return 0xFFFFFFFFLL;
    }
    if ( a1 != 6 || (a2 & 0x40) == 0 )
      return 0xFFFFFFFFLL;
  }
  return result;
}
