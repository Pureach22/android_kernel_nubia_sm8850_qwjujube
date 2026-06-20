unsigned int *__fastcall trigger_event(__int64 a1, unsigned int **a2, __int64 a3)
{
  unsigned int *result; // x0
  unsigned int *v7; // x8

  result = *a2;
  if ( *a2 )
  {
    result = (unsigned int *)complete();
    if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
    {
      if ( !print_limit_option
        || (result = (unsigned int *)__ratelimit(&trigger_event__rs_313, "trigger_event"), (_DWORD)result) )
      {
        result = (unsigned int *)printk(&unk_270C6, "trigger_event", **a2);
      }
    }
    if ( a1 && !*(_DWORD *)(a1 + 568) )
      result = (unsigned int *)ipc_log_string(*(_QWORD *)(a1 + 528), "%s: sps: done=%d\n", "trigger_event", **a2);
  }
  if ( a2[1] )
  {
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 4u
      && (!print_limit_option || (unsigned int)__ratelimit(&trigger_event__rs_316, "trigger_event")) )
    {
      printk(&unk_2919C, "trigger_event", "sps:trigger_event.using callback\n");
    }
    if ( a1 && !*(_DWORD *)(a1 + 568) )
      ipc_log_string(*(_QWORD *)(a1 + 528), "%s: %s", "trigger_event", "sps:trigger_event.using callback\n");
    v7 = a2[1];
    if ( *(v7 - 1) != 605010790 )
      __break(0x8228u);
    return (unsigned int *)((__int64 (__fastcall *)(__int64))v7)(a3 + 16);
  }
  return result;
}
