__int64 __fastcall crm_timer_callback(__int64 a1)
{
  const void *v1; // x6
  __int64 v3; // x19

  v1 = (const void *)(a1 - 8);
  if ( a1 == 8 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const void *))cam_print_log)(
             3,
             16,
             1,
             "crm_timer_callback",
             26,
             "NULL timer",
             v1);
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    v3 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "crm_timer_callback",
      29,
      "timer %pK parent %pK",
      v1,
      *(const void **)(a1 + 40));
    a1 = v3;
  }
  return cam_common_modify_timer(a1, *(unsigned int *)(a1 - 8));
}
