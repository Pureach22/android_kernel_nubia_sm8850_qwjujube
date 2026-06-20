__int64 __fastcall cam_common_modify_timer(__int64 a1, int a2)
{
  int v3; // w8
  __int64 v4; // x20
  __int64 v5; // x0
  int v7; // w22

  if ( a1 )
  {
    v3 = timeout_multiplier;
    if ( !timeout_multiplier )
    {
      v3 = 1;
      timeout_multiplier = 1;
    }
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      v7 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_common_modify_timer",
        139,
        "Starting timer to fire in %d ms. (jiffies=%lu)\n",
        v3 * a2,
        jiffies);
      v3 = timeout_multiplier;
      a2 = v7;
    }
    v4 = jiffies;
    v5 = _msecs_to_jiffies((unsigned int)(v3 * a2));
    mod_timer(a1, v5 + v4);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_modify_timer",
      131,
      "Invalid reference to system timer");
    return 4294967274LL;
  }
}
