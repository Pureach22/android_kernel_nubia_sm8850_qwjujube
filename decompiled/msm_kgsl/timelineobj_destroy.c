unsigned int *__fastcall timelineobj_destroy(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  unsigned int *result; // x0
  int v10; // w8

  if ( *(int *)(a1 + 72) >= 1 )
  {
    v2 = 0;
    v3 = 0;
    do
    {
      kgsl_timeline_add_signal(*(_QWORD *)(a1 + 64) + v2);
      ++v3;
      v2 += 48;
    }
    while ( v3 < *(int *)(a1 + 72) );
  }
  result = (unsigned int *)(a1 + 56);
  __asm { PRFM            #0x11, [X0] }
  do
    v10 = __ldxr(result);
  while ( __stlxr(v10 - 1, result) );
  if ( v10 == 1 )
  {
    __dmb(9u);
    return (unsigned int *)drawobj_timelineobj_retire();
  }
  else if ( v10 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate(result, 3);
  }
  return result;
}
