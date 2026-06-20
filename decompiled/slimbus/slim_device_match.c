__int64 __fastcall slim_device_match(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned __int16 *i; // x8

  result = 0;
  if ( a1 && a2 && a2 != 32 )
  {
    if ( *(_QWORD *)(a2 + 176) )
    {
      if ( of_match_device(*(_QWORD *)(a2 + 40), a1) )
      {
        return 1;
      }
      else
      {
        for ( i = *(unsigned __int16 **)(a2 + 176); *i || i[1]; i += 8 )
        {
          if ( *i == *(unsigned __int16 *)(a1 + 916)
            && i[1] == *(unsigned __int16 *)(a1 + 914)
            && i[2] == *(unsigned __int8 *)(a1 + 913)
            && i[3] == *(unsigned __int8 *)(a1 + 912) )
          {
            return i != nullptr;
          }
        }
        i = nullptr;
        return i != nullptr;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
