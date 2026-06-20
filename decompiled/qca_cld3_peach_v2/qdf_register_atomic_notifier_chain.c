__int64 __fastcall qdf_register_atomic_notifier_chain(__int64 a1, __int64 a2)
{
  __int64 v2; // x0

  v2 = atomic_notifier_chain_register(a1, a2);
  return qdf_status_from_os_return(v2);
}
