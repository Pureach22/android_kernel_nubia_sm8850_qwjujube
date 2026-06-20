__int64 __fastcall drawobj_timelineobj_retire(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  unsigned __int64 v4; // x8
  int v11; // w8
  int v14; // w8
  __int64 result; // x0

  if ( *(int *)(a1 + 16) >= 1 )
  {
    v2 = 0;
    v3 = 0;
    do
    {
      kgsl_timeline_signal(*(_QWORD *)(*(_QWORD *)(a1 + 8) + v2), *(_QWORD *)(*(_QWORD *)(a1 + 8) + v2 + 8));
      v4 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + v2);
      if ( v4 && v4 <= 0xFFFFFFFFFFFFF000LL )
      {
        _X0 = (unsigned int *)(v4 + 32);
        __asm { PRFM            #0x11, [X0] }
        do
          v11 = __ldxr(_X0);
        while ( __stlxr(v11 - 1, _X0) );
        if ( v11 == 1 )
        {
          __dmb(9u);
          kgsl_timeline_destroy();
        }
        else if ( v11 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
      _X0 = *(unsigned int **)(*(_QWORD *)(a1 + 8) + v2 + 16);
      if ( _X0 )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v14 = __ldxr(_X0);
        while ( __stlxr(v14 - 1, _X0) );
        if ( v14 == 1 )
        {
          __dmb(9u);
          kgsl_context_destroy((__int64)_X0);
        }
        else if ( v14 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
      ++v3;
      v2 += 48;
    }
    while ( v3 < *(int *)(a1 + 16) );
  }
  result = kvfree(*(_QWORD *)(a1 + 8));
  *(_QWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  return result;
}
