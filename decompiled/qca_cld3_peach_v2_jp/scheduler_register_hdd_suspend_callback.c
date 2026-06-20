__int64 __fastcall scheduler_register_hdd_suspend_callback(__int64 a1)
{
  __int64 result; // x0

  result = scheduler_get_context(a1);
  if ( result )
    *(_QWORD *)(result + 688) = a1;
  return result;
}
