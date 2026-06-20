__int64 __fastcall dwc3_host_complete(__int64 result)
{
  __int64 v1; // x19

  if ( (*(_WORD *)(result + 268) & 0x200) != 0 )
  {
    v1 = result;
    result = _pm_runtime_resume(result, 0);
    if ( (result & 0x80000000) != 0 )
      return dev_err(v1, "failed to runtime resume, ret %d\n", result);
  }
  return result;
}
