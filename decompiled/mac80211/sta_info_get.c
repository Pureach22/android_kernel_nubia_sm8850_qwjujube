unsigned __int64 __fastcall sta_info_get(__int64 a1, const void *a2)
{
  __int64 v2; // x21
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x19

  v2 = *(_QWORD *)(a1 + 1616);
  _rcu_read_lock(a1, a2);
  v5 = rhltable_lookup((__int64 *)(v2 + 1632), a2, (__int64)&sta_rht_params);
  if ( v5 )
  {
    while ( *(_QWORD *)(v5 + 32) != a1 )
    {
      v5 = *(_QWORD *)(v5 + 8);
      if ( !v5 )
        goto LABEL_4;
    }
    v6 = v5 - 48;
  }
  else
  {
LABEL_4:
    v6 = 0;
  }
  _rcu_read_unlock(v5);
  return v6;
}
