__int64 __fastcall gic_s2idle_exit(__int64 a1, __int64 a2, char a3)
{
  __int64 result; // x0
  unsigned int v10; // w10

  if ( (a3 & 1) != 0 )
  {
    if ( cpus_in_s2idle == _num_online_cpus )
      result = msm_show_resume_irqs();
    _X9 = &cpus_in_s2idle;
    __asm { PRFM            #0x11, [X9] }
    do
      v10 = __ldxr((unsigned int *)&cpus_in_s2idle);
    while ( __stxr(v10 - 1, (unsigned int *)&cpus_in_s2idle) );
  }
  return result;
}
