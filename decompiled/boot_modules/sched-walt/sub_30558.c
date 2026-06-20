__int64 sub_30558()
{
  __asm { PRFM            #0, [X20,#0x5A68] }
  return android_rvh_set_cpus_allowed_by_task();
}
