__int64 __fastcall _cmdq_write(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = _resume(a1);
  if ( !(_DWORD)result )
  {
    result = venus_hfi_queue_cmd_write(a1, a2);
    if ( !(_DWORD)result )
    {
      _schedule_power_collapse_work(a1);
      return 0;
    }
  }
  return result;
}
