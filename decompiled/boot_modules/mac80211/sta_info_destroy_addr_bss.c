__int64 __fastcall sta_info_destroy_addr_bss(__int64 a1, const void *a2)
{
  __int64 v2; // x21
  unsigned __int64 v5; // x0
  __int64 *v6; // x19
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 1616);
  _rcu_read_lock(a1, a2);
  v5 = rhltable_lookup((__int64 *)(v2 + 1632), a2, (__int64)&sta_rht_params);
  if ( v5 )
  {
    while ( 1 )
    {
      v7 = *(_QWORD *)(v5 + 32);
      if ( v7 == a1 )
        break;
      v8 = *(_QWORD *)(v7 + 2032);
      if ( v8 )
      {
        if ( v8 == *(_QWORD *)(a1 + 2032) )
          break;
      }
      v5 = *(_QWORD *)(v5 + 8);
      if ( !v5 )
        goto LABEL_2;
    }
    v6 = (__int64 *)(v5 - 48);
  }
  else
  {
LABEL_2:
    v6 = nullptr;
  }
  _rcu_read_unlock(v5);
  result = _sta_info_destroy_part1(v6);
  if ( !(_DWORD)result )
  {
    synchronize_net(result);
    _sta_info_destroy_part2((__int64)v6, 1);
    return 0;
  }
  return result;
}
