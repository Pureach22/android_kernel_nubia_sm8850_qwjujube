__int64 __fastcall slim_msg_response(_QWORD *a1, __int64 a2, unsigned __int8 a3, unsigned __int8 a4)
{
  __int64 v8; // x24
  __int64 v9; // x22
  __int64 result; // x0
  __int64 v11; // x24
  __int64 v12; // x23
  __int64 v13; // x0
  __int64 v14; // x20

  v8 = raw_spin_lock_irqsave(a1 + 21);
  v9 = idr_find(a1 + 18, a3);
  result = raw_spin_unlock_irqrestore(a1 + 21, v8);
  if ( v9 )
  {
    v11 = *(_QWORD *)(v9 + 8);
    if ( v11 && *(_QWORD *)(v11 + 8) )
    {
      v12 = raw_spin_lock_irqsave(a1 + 21);
      idr_remove(a1 + 18, *(unsigned __int8 *)(v9 + 6));
      raw_spin_unlock_irqrestore(a1 + 21, v12);
      _memcpy_fromio(*(_QWORD *)(v11 + 8), a2, a4);
      v13 = *(_QWORD *)(v9 + 16);
      if ( v13 )
        v13 = complete();
      v14 = *a1;
      *(_QWORD *)(v14 + 520) = ktime_get_mono_fast_ns(v13);
      return _pm_runtime_suspend(*a1, 13);
    }
    else
    {
      return dev_err(*a1, "Got response to invalid TID:%d, len:%d\n", a3, a4);
    }
  }
  return result;
}
