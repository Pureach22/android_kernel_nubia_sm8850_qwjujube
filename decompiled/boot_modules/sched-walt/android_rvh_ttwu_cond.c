void __fastcall android_rvh_ttwu_cond(__int64 a1, int a2, bool *a3)
{
  bool v3; // w8

  if ( (walt_disabled & 1) == 0 )
  {
    v3 = (unsigned int)sysctl_sched_many_wakeup_threshold <= 0x3E7 && *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40) != a2;
    *a3 = v3;
  }
}
