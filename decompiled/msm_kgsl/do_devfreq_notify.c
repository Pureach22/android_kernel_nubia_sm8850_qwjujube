__int64 __fastcall do_devfreq_notify(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 result; // x0
  __int64 v4; // x8

  v1 = (_QWORD *)(a1 - 560);
  mutex_lock(*(_QWORD *)(a1 - 560) + 16LL);
  update_devfreq(*v1);
  result = mutex_unlock(*v1 + 16LL);
  v4 = *(_QWORD *)(a1 + 976);
  if ( v4 )
  {
    mutex_lock(v4 + 16);
    update_devfreq(*(_QWORD *)(a1 + 976));
    return mutex_unlock(*(_QWORD *)(a1 + 976) + 16LL);
  }
  return result;
}
