void __fastcall android_rvh_cpu_cgroup_attach(__int64 a1, __int64 a2)
{
  __int64 v3; // x22
  __int64 v4; // x0
  __int64 v5; // x20
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (walt_disabled & 1) == 0 )
  {
    v6[0] = 0;
    cgroup_taskset_first(a2, v6);
    v3 = v6[0];
    if ( v6[0] )
    {
      v4 = cgroup_taskset_first(a2, v6);
      if ( v4 )
      {
        v5 = v4;
        _ReadStatusReg(SP_EL0);
        do
        {
          _sched_set_group_id(v5, (unsigned __int8)byte_268[v3]);
          v5 = cgroup_taskset_next(a2, v6);
        }
        while ( v5 );
      }
    }
  }
  _ReadStatusReg(SP_EL0);
}
