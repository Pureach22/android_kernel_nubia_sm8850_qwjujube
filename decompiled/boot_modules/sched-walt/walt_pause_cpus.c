__int64 __fastcall walt_pause_cpus(__int64 a1, __int64 a2)
{
  if ( (walt_disabled & 1) != 0 )
    return 4294967285LL;
  else
    return walt_halt_cpus(a1, a2, 0);
}
