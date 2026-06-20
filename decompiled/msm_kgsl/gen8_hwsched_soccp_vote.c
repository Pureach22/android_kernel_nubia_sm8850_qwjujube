__int64 __fastcall gen8_hwsched_soccp_vote(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  unsigned __int64 v9; // x9

  v1 = *(_QWORD *)(result + 1544);
  if ( (*(_QWORD *)(result + 22496) & 0x10) != 0 )
  {
    v2 = result;
    result = gmu_core_soccp_vote();
    if ( (_DWORD)result )
    {
      raw_spin_lock(v2 + 23152);
      _X8 = (unsigned __int64 *)(v2 + 23200);
      __asm { PRFM            #0x11, [X8] }
      do
        v9 = __ldxr(_X8);
      while ( __stxr(v9 | 4, _X8) );
      raw_spin_unlock(v2 + 23152);
      adreno_hwsched_log_remove_pending_hw_fences(v2, v1 + 16);
      gmu_core_mark_for_coldboot(v2);
      return adreno_hwsched_deregister_hw_fence(v2);
    }
  }
  return result;
}
