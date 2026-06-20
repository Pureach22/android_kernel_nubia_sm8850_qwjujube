__int64 __fastcall _qdf_periodic_work_handler(__int64 a1)
{
  __int64 v2; // x0
  void (__fastcall *v3)(_QWORD); // x8
  __int64 result; // x0
  __int64 v5; // x0

  v3 = *(void (__fastcall **)(_QWORD))(a1 + 104);
  v2 = *(_QWORD *)(a1 + 112);
  if ( *((_DWORD *)v3 - 1) != 251140989 )
    __break(0x8228u);
  v3(v2);
  result = *(unsigned int *)(a1 + 120);
  if ( (_DWORD)result )
  {
    v5 = _msecs_to_jiffies(result);
    return queue_delayed_work_on(32, system_wq, a1, v5);
  }
  return result;
}
