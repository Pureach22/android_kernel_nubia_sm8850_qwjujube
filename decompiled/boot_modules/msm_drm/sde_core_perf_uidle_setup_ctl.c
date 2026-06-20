unsigned int *__fastcall sde_core_perf_uidle_setup_ctl(
        unsigned int *result,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x8
  unsigned int *v9; // x21
  unsigned int *v10; // x19

  v8 = *(_QWORD *)result;
  v9 = *(unsigned int **)(*(_QWORD *)result + 816LL);
  if ( v9 != (unsigned int *)(*(_QWORD *)result + 816LL) )
  {
    v10 = result;
    do
    {
      if ( *((unsigned int **)v9 + 9) == v10 )
      {
        result = sde_encoder_uidle_enable(v9 - 2, a2 & 1, a3, a4, a5, a6, a7, a8);
        v8 = *(_QWORD *)v10;
      }
      v9 = *(unsigned int **)v9;
    }
    while ( v9 != (unsigned int *)(v8 + 816) );
  }
  return result;
}
