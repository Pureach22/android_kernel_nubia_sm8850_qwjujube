__int64 __fastcall sde_vm_msgq_deinit(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 184);
  if ( v2 )
    kthread_stop(v2);
  result = *(_QWORD *)(a1 + 256);
  if ( result )
    return gh_msgq_unregister(result);
  return result;
}
