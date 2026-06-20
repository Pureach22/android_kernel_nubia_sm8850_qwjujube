__int64 __fastcall lpass_bt_swr_remove(__int64 result)
{
  __int64 v1; // x19

  if ( *(_QWORD *)(result + 168) )
  {
    v1 = result;
    _pm_runtime_disable(result + 16, 1);
    _pm_runtime_set_status(v1 + 16, 2);
    return of_platform_depopulate(v1 + 16);
  }
  return result;
}
