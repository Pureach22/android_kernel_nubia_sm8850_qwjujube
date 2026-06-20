__int64 __fastcall fastrpc_buf_list_free(__int64 a1, _QWORD **a2, char a3)
{
  _QWORD *v6; // x22
  _QWORD *v7; // x8
  __int64 v8; // x9
  __int64 result; // x0

  raw_spin_lock(a1 + 320);
  v6 = *a2;
  if ( *a2 == a2 )
    return raw_spin_unlock(a1 + 320);
  while ( 1 )
  {
    v7 = (_QWORD *)v6[1];
    if ( (_QWORD *)*v7 == v6 && (v8 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
    {
      *(_QWORD *)(v8 + 8) = v7;
      *v7 = v8;
    }
    else
    {
      _list_del_entry_valid_or_report(v6);
    }
    *v6 = 0xDEAD000000000100LL;
    v6[1] = 0xDEAD000000000122LL;
    if ( (a3 & 1) != 0 )
      --*(_DWORD *)(a1 + 272);
    result = raw_spin_unlock(a1 + 320);
    if ( !v6 )
      break;
    fastrpc_buf_free((__int64)v6, 0);
    raw_spin_lock(a1 + 320);
    v6 = *a2;
    if ( *a2 == a2 )
      return raw_spin_unlock(a1 + 320);
  }
  return result;
}
