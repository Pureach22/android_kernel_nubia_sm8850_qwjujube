__int64 __fastcall fastrpc_configure_wakeup_source(__int64 a1)
{
  __int64 v2; // x8

  mutex_lock(a1 + 64056);
  v2 = *(_QWORD *)(a1 + 52704);
  if ( v2 )
    fastrpc_register_wakeup_source(*(const char ***)(v2 + 56), "fastrpc-non_secure", (unsigned __int64 *)(a1 + 64048));
  return mutex_unlock(a1 + 64056);
}
