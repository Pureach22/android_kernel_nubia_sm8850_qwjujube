__int64 __fastcall adreno_touch_wakeup(__int64 a1)
{
  kgsl_pwrctrl_change_state(a1, 2);
  _msecs_to_jiffies((unsigned int)adreno_wake_timeout);
  return mod_timer(a1 + 8792);
}
