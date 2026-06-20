__int64 __fastcall adreno_pm_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  void (__fastcall *v3)(_QWORD); // x8
  __int64 v4; // x0

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
  {
    v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 14264) + 40LL) + 160LL);
    rt_mutex_lock(v1 + 11088);
    v3 = *(void (__fastcall **)(_QWORD))(v2 + 32);
    if ( *((_DWORD *)v3 - 1) != 994519391 )
      __break(0x8228u);
    v3(v1);
    v4 = rt_mutex_unlock(v1 + 11088);
    kgsl_reclaim_start(v4);
  }
  return 0;
}
