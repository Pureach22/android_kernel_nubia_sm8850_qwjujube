void __fastcall android_rvh_cpu_capacity_show(__int64 a1, _QWORD *a2, int a3)
{
  if ( soc_sched_lib_name_capacity
    && ((is_sched_lib_based_app(*(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800)) & 1) != 0
     || (is_sched_lib_task() & 1) != 0)
    && soc_sched_lib_name_capacity > a3 )
  {
    *a2 = 100;
  }
}
