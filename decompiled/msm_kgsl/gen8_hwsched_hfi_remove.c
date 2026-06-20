__int64 __fastcall gen8_hwsched_hfi_remove(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 24648);
  if ( result )
    return kthread_stop();
  return result;
}
