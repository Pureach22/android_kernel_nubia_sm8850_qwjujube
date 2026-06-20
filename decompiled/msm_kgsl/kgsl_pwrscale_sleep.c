__int64 __fastcall kgsl_pwrscale_sleep(__int64 result)
{
  if ( *(_BYTE *)(result + 11880) == 1 )
    return queue_work_on(32, *(_QWORD *)(result + 11896), result + 11904);
  return result;
}
