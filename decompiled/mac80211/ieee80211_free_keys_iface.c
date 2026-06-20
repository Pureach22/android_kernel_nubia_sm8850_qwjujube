_DWORD *__fastcall ieee80211_free_keys_iface(_DWORD *result, _QWORD *a2)
{
  int v2; // w23
  _DWORD *v3; // x21
  __int64 lock; // x0
  _QWORD *i; // x8
  int v7; // w8
  _DWORD **v8; // x20
  _DWORD *v9; // x22
  _DWORD *v10; // x21
  _QWORD *v11; // x1

  v2 = result[383];
  v3 = result;
  if ( result[382] < v2 )
    __break(0x800u);
  if ( result[1180] == 3 )
  {
    lock = _rcu_read_lock(result, a2);
    for ( i = *((_QWORD **)v3 + 283); i != (_QWORD *)(v3 + 566); i = (_QWORD *)*i )
      *((_DWORD *)i - 184) -= v2;
    result = (_DWORD *)_rcu_read_unlock(lock);
  }
  v7 = v3[382];
  v8 = *((_DWORD ***)v3 + 189);
  v9 = v3 + 378;
  v3[383] = 0;
  v3[382] = v7 - v2;
  if ( v8 != (_DWORD **)(v3 + 378) )
  {
    do
    {
      v10 = *v8;
      result = (_DWORD *)ieee80211_key_replace(
                           (__int64)*(v8 - 2),
                           nullptr,
                           (__int64)*(v8 - 1),
                           ((_WORD)v8[66] & 8) != 0,
                           (unsigned __int64)(v8 - 3),
                           0);
      v11 = (_QWORD *)a2[1];
      if ( v8 == a2 || v11 == v8 || (_QWORD *)*v11 != a2 )
      {
        result = (_DWORD *)_list_add_valid_or_report(v8, v11);
      }
      else
      {
        a2[1] = v8;
        *v8 = a2;
        v8[1] = v11;
        *v11 = v8;
      }
      v8 = (_DWORD **)v10;
    }
    while ( v10 != v9 );
  }
  return result;
}
