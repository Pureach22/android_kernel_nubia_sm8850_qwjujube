__int64 __fastcall walt_resume_cpus(__int64 a1, __int64 a2)
{
  if ( (walt_disabled & 1) != 0 )
    return 4294967285LL;
  walt_start_cpus(a1, a2, 0);
  return 0;
}
