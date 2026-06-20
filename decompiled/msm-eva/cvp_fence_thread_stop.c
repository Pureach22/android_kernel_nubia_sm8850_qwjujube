__int64 __fastcall cvp_fence_thread_stop(__int64 result)
{
  __int64 v1; // x20

  if ( *(_DWORD *)(result + 14852) )
  {
    v1 = result;
    mutex_lock(result + 15272);
    *(_DWORD *)(v1 + 15320) = 3;
    mutex_unlock(v1 + 15272);
    raw_spin_lock(v1 + 232);
    *(_DWORD *)(v1 + 236) = 3;
    raw_spin_unlock(v1 + 232);
    _wake_up(v1 + 15344, 3, 0, 0);
    return _wake_up(v1 + 264, 3, 0, 0);
  }
  return result;
}
