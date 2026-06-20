__int64 __fastcall mgmt_txrx_get_frm_type(unsigned __int8 a1, unsigned __int8 *a2)
{
  __int64 result; // x0
  unsigned __int64 v3; // t2
  bool v4; // zf
  __int64 v5; // x8

  HIDWORD(v3) = a1;
  LODWORD(v3) = a1;
  result = (unsigned int)(v3 >> 4);
  if ( (int)result > 8 )
  {
    if ( (int)result > 11 )
    {
      if ( (unsigned int)(result - 13) >= 2 )
      {
        if ( (_DWORD)result == 12 )
          return 10;
      }
      else
      {
        v5 = *a2;
        if ( (v5 & 0x80) == 0 )
          return ((__int64 (__fastcall *)(__int64))((char *)&loc_1A4B40 + 4 * byte_9DEDF8[v5]))(28);
      }
      return 0xFFFFFFFFLL;
    }
    if ( (_DWORD)result == 9 )
    {
      return 7;
    }
    else if ( (_DWORD)result == 10 )
    {
      return 8;
    }
    else
    {
      return 9;
    }
  }
  else
  {
    if ( (int)result > 2 )
    {
      if ( (int)result <= 5 )
        return result;
      if ( (_DWORD)result == 8 )
        return 6;
      return 0xFFFFFFFFLL;
    }
    if ( (unsigned int)result >= 2 )
    {
      v4 = (_DWORD)result == 2;
      result = 0;
      if ( !v4 )
        return 0xFFFFFFFFLL;
    }
  }
  return result;
}
