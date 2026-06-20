__int64 __fastcall drm_dp_tx_work(__int64 a1)
{
  __int64 v1; // x19

  v1 = a1 - 120;
  mutex_lock(a1 - 120);
  if ( *(_QWORD *)(a1 - 72) != a1 - 72 )
    process_single_down_tx_qlock(a1 - 1056);
  return mutex_unlock(v1);
}
