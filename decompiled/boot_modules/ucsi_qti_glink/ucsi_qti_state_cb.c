__int64 __fastcall ucsi_qti_state_cb(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v6; // x8

  mutex_lock(a1 + 224);
  *(_DWORD *)(a1 + 1448) = a2;
  result = mutex_unlock(a1 + 224);
  if ( a2 )
  {
    if ( a2 != 1 )
      return result;
    v5 = 1384;
    v6 = 1416;
  }
  else
  {
    v5 = 1416;
    v6 = 1384;
  }
  cancel_work_sync(a1 + v6);
  return queue_work_on(32, system_wq, a1 + v5);
}
