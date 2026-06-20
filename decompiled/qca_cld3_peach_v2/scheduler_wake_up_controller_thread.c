__int64 __fastcall scheduler_wake_up_controller_thread(__int64 a1)
{
  __int64 result; // x0

  result = scheduler_get_context(a1);
  if ( result )
    return _wake_up(result + 592, 1, 1, 0);
  return result;
}
