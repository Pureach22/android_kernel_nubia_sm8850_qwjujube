__int64 __fastcall lpass_cdc_remove(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x0

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
  {
    v2 = result;
    v3 = *(_QWORD *)(v1 + 1136);
    if ( v3 )
      proc_remove(v3);
    return of_platform_depopulate(v2 + 16);
  }
  return result;
}
