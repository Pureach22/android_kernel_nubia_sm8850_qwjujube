__int64 __fastcall cm_req_lock_release(__int64 a1)
{
  return qdf_mutex_release(a1 + 120);
}
