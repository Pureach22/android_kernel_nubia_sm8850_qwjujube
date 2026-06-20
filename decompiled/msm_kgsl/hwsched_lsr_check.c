__int64 __fastcall hwsched_lsr_check(__int64 a1)
{
  rt_mutex_lock(a1 - 11800);
  kgsl_pwrscale_update_stats(a1 - 22888);
  kgsl_pwrscale_update(a1 - 22888);
  rt_mutex_unlock(a1 - 11800);
  return mod_timer(a1 - 40);
}
