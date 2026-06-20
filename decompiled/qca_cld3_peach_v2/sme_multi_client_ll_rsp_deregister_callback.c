__int64 __fastcall sme_multi_client_ll_rsp_deregister_callback(__int64 a1)
{
  __int64 result; // x0

  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(a1 + 14664) = 0;
    return qdf_mutex_release(a1 + 12848);
  }
  return result;
}
