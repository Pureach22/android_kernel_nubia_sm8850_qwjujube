__int64 __fastcall walt_get_rtg_status(char *a1)
{
  char v1; // w19
  __int64 lock; // x0
  _QWORD *v4; // x8
  __int64 v5; // x8

  if ( (soc_flags & 0x80) != 0 )
  {
    lock = _rcu_read_lock(a1);
    v4 = &vendor_data_pad;
    if ( a1 != (char *)&init_task )
      v4 = a1 + 5184;
    v5 = v4[30];
    if ( v5 )
      v1 = *(_BYTE *)(v5 + 40);
    else
      v1 = 0;
    _rcu_read_unlock(lock);
  }
  else
  {
    v1 = 0;
  }
  return v1 & 1;
}
