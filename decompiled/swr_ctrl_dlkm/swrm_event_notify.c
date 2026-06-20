__int64 __fastcall swrm_event_notify(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x2

  if ( a1 == 15416 || (v2 = *(_QWORD *)(a1 - 6904)) == 0 )
  {
    if ( (unsigned int)__ratelimit(&swrm_event_notify__rs, "swrm_event_notify") )
      printk(&unk_11163, "swrm_event_notify");
    return 4294967274LL;
  }
  if ( a2 != 4 )
  {
    if ( a2 == 1 )
    {
      v3 = a1 + 24;
      goto LABEL_15;
    }
    if ( (unsigned int)__ratelimit(&swrm_event_notify__rs_207, "swrm_event_notify") )
      dev_err(*(_QWORD *)(a1 - 6904), "%s: invalid event type: %lu\n", "swrm_event_notify", a2);
    return 4294967274LL;
  }
  if ( !*(_DWORD *)(a1 + 328) || (*(_BYTE *)(a1 + 333) & 1) != 0 )
    return 0;
  *(_BYTE *)(a1 + 333) = 1;
  pm_stay_awake(v2);
  v3 = a1 + 296;
LABEL_15:
  queue_work_on(32, system_wq, v3);
  return 0;
}
