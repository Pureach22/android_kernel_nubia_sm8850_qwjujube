unsigned __int64 __fastcall sta_info_get_by_addrs(__int64 a1, const void *a2, __int64 a3)
{
  unsigned __int64 result; // x0

  result = rhltable_lookup((__int64 *)(a1 + 1632), a2, (__int64)&sta_rht_params);
  if ( result )
  {
    while ( *(_DWORD *)(*(_QWORD *)(result + 32) + 5842LL) ^ *(_DWORD *)a3
          | *(unsigned __int16 *)(*(_QWORD *)(result + 32) + 5846LL) ^ *(unsigned __int16 *)(a3 + 4) )
    {
      result = *(_QWORD *)(result + 8);
      if ( !result )
        return result;
    }
    result -= 48LL;
  }
  return result;
}
