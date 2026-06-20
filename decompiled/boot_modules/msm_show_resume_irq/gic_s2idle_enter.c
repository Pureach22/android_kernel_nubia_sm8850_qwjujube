void __fastcall gic_s2idle_enter(__int64 a1, __int64 a2, char a3)
{
  unsigned int v9; // w9

  if ( (a3 & 1) != 0 )
  {
    _X8 = &cpus_in_s2idle;
    __asm { PRFM            #0x11, [X8] }
    do
      v9 = __ldxr((unsigned int *)&cpus_in_s2idle);
    while ( __stxr(v9 + 1, (unsigned int *)&cpus_in_s2idle) );
  }
}
