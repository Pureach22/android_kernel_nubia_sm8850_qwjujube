__int64 __fastcall cam_req_mgr_debug_set_bubble_recovery(__int64 **a1, int a2)
{
  __int64 *i; // x8

  mutex_lock(a1 + 2);
  for ( i = *a1; i != (__int64 *)a1; i = (__int64 *)*i )
    *((_DWORD *)i + 16) = a2;
  mutex_unlock(a1 + 2);
  return 0;
}
