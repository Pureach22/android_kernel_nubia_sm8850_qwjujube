__int64 __fastcall waltgov_stop(__int64 a1)
{
  __int64 v1; // x20
  char v3; // w11
  unsigned __int64 v4; // x11
  unsigned __int64 v5; // x11
  __int64 v6; // x12
  bool v7; // cf
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 88);
  v3 = 0;
  do
  {
    v4 = (unsigned int)(-1LL << v3) & *(_DWORD *)a1;
    if ( !(_DWORD)v4 )
      break;
    v5 = __clz(__rbit64(v4));
    v6 = *((_QWORD *)&_per_cpu_offset + v5);
    v7 = v5 >= 0x1F;
    v3 = v5 + 1;
    *(_QWORD *)((char *)&waltgov_cb_data + v6) = 0;
  }
  while ( !v7 );
  result = synchronize_rcu();
  if ( (*(_BYTE *)(a1 + 609) & 1) == 0 )
  {
    irq_work_sync(v1 + 208);
    result = kthread_cancel_work_sync(v1 + 240);
  }
  waltgov_disabled = 1;
  return result;
}
