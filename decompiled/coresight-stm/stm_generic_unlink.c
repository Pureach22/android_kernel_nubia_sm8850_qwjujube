__int64 __fastcall stm_generic_unlink(__int64 result)
{
  if ( result != 64 )
  {
    result = *(_QWORD *)(result - 40);
    if ( result )
      return coresight_disable_sysfs(result);
  }
  return result;
}
