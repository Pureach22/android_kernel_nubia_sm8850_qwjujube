__int64 __fastcall cam_req_mgr_debug_get_bubble_recovery(__int64 a1, _QWORD *a2)
{
  mutex_lock(a1 + 16);
  if ( *(_QWORD *)a1 != a1 )
    *a2 = *(int *)(*(_QWORD *)a1 + 64LL);
  mutex_unlock(a1 + 16);
  return 0;
}
