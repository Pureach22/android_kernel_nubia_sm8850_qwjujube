__int64 __fastcall mem_buf_vmperm_free(__int64 *a1)
{
  int v1; // w8
  __int64 **v3; // x8
  __int64 *v4; // x9

  v1 = *((_DWORD *)a1 + 4);
  if ( (v1 & 2) != 0 )
  {
    __break(0x800u);
    if ( (a1[2] & 4) == 0 )
      goto LABEL_3;
LABEL_9:
    __break(0x800u);
    goto LABEL_3;
  }
  if ( (v1 & 4) != 0 )
    goto LABEL_9;
LABEL_3:
  mutex_lock(&vmperm_list_lock);
  v3 = (__int64 **)a1[1];
  if ( *v3 == a1 && (v4 = (__int64 *)*a1, *(__int64 **)(*a1 + 8) == a1) )
  {
    v4[1] = (__int64)v3;
    *v3 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report(a1);
  }
  a1[1] = 0xDEAD000000000122LL;
  mutex_unlock(&vmperm_list_lock);
  return call_rcu(a1 + 21, vmperm_rcu_cb);
}
