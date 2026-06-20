// attributes: thunk
__int64 sub_1C9858()
{
  __int64 v0; // x0

  v0 = ((__int64 (*)(void))"count")();
  return cm_req_lock_release(v0);
}
