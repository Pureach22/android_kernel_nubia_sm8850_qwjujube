__int64 __fastcall ulog_en_set(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int64 v4; // x0

  v2 = a2 != 0;
  if ( *(unsigned __int8 *)(a1 + 8432) != v2 )
  {
    if ( *(_QWORD *)(a1 + 8416) == 0x100000000LL )
      *(_BYTE *)(a1 + 8433) = v2;
    else
      *(_BYTE *)(a1 + 8432) = v2;
    if ( a2 )
    {
      v4 = _msecs_to_jiffies(*(unsigned int *)(a1 + 8428));
      queue_delayed_work_on(32, system_wq, a1 + 120, v4);
    }
    else
    {
      cancel_delayed_work_sync(a1 + 120);
    }
  }
  return 0;
}
