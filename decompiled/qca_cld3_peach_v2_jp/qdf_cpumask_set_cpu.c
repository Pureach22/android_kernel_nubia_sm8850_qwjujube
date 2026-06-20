__int64 __fastcall qdf_cpumask_set_cpu(__int64 result, __int64 a2)
{
  unsigned __int64 v8; // x10

  _X9 = (unsigned __int64 *)(a2 + 8LL * ((unsigned int)result >> 6));
  __asm { PRFM            #0x11, [X9] }
  do
    v8 = __ldxr(_X9);
  while ( __stxr(v8 | (1LL << result), _X9) );
  return result;
}
