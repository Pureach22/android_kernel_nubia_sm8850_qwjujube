__int64 __fastcall adreno_pm_notifier(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 v7; // x8
  __int64 v8; // x21

  if ( (unsigned __int64)(a2 - 5) < 0xFFFFFFFFFFFFFFFELL )
    return 0;
  v3 = *(_QWORD *)(a1 - 15312);
  if ( v3 )
  {
    v4 = *(_QWORD *)(v3 + 592);
    if ( *(_DWORD *)(v4 + 404) )
    {
      if ( (unsigned int)__ratelimit(&adreno_pm_notifier__rs, "adreno_pm_notifier") )
      {
        dev_err(
          *(_QWORD *)(a1 - 24344),
          "unexpected gx pd prepared_count:%d event:%lu\n",
          *(unsigned int *)(v4 + 404),
          a2);
        return 32770;
      }
      return 32770;
    }
  }
  v7 = *(_QWORD *)(a1 - 15320);
  if ( v7 )
  {
    v8 = *(_QWORD *)(v7 + 592);
    if ( *(_DWORD *)(v8 + 404) )
    {
      if ( (unsigned int)__ratelimit(&adreno_pm_notifier__rs_122, "adreno_pm_notifier") )
      {
        dev_err(
          *(_QWORD *)(a1 - 24344),
          "unexpected cx pd prepared_count:%d event:%lu\n",
          *(unsigned int *)(v8 + 404),
          a2);
        return 32770;
      }
      return 32770;
    }
  }
  if ( a2 == 4 )
  {
    complete_all(a1 + 24);
    kthread_queue_work(*(_QWORD *)(a1 + 56), a1 + 64);
    return 0;
  }
  __dmb(9u);
  if ( !*(_DWORD *)(a1 + 104) )
  {
    *(_DWORD *)(a1 + 24) = 0;
    return 0;
  }
  if ( (unsigned int)__ratelimit(&adreno_pm_notifier__rs_124, "adreno_pm_notifier") )
    dev_err(*(_QWORD *)(a1 - 24344), "cancelling suspend because of fault\n");
  complete_all(a1 + 24);
  kthread_queue_work(*(_QWORD *)(a1 + 56), a1 + 64);
  return 32770;
}
