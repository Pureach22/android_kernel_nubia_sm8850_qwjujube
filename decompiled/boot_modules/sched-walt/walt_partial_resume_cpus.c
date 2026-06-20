__int64 __fastcall walt_partial_resume_cpus(unsigned __int64 *a1, char a2)
{
  if ( (walt_disabled & 1) != 0 )
    return 4294967285LL;
  walt_start_cpus(a1, a2, 1u);
  return 0;
}
