__int64 __fastcall adreno_pm_suspend(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x20
  __int64 (__fastcall *v3)(_QWORD); // x8
  unsigned int v4; // w20
  __int64 result; // x0
  unsigned __int64 v12; // x10

  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return 0;
  v2 = *(_QWORD *)(*(_QWORD *)(v1[1783] + 40LL) + 160LL);
  if ( !(unsigned int)mutex_trylock(v1 + 3037) )
    return 4294967261LL;
  rt_mutex_lock(v1 + 1386);
  v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 24);
  if ( *((_DWORD *)v3 - 1) != -83892780 )
    __break(0x8228u);
  v4 = v3(v1);
  rt_mutex_unlock(v1 + 1386);
  mutex_unlock(v1 + 3037);
  result = v4;
  if ( !v4 )
  {
    _X8 = v1 + 1780;
    __asm { PRFM            #0x11, [X8] }
    do
      v12 = __ldxr(_X8);
    while ( __stxr(v12 & 0xFFFFFFFFFFFDFFFFLL, _X8) );
    kgsl_reclaim_close();
    kthread_flush_worker(v1[1622]);
    _flush_workqueue(qword_3A908);
    return 0;
  }
  return result;
}
