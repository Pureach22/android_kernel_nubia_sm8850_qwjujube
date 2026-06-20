__int64 __fastcall kgsl_context_detach(__int64 result)
{
  __int64 v1; // x20
  __int64 (*v3)(void); // x8
  void (__fastcall *v4)(_QWORD); // x8
  unsigned __int64 v11; // x8
  int v13; // w8

  if ( result )
  {
    _X19 = result;
    v1 = *(_QWORD *)(result + 40);
    v3 = *(__int64 (**)(void))(*(_QWORD *)(v1 + 8752) + 280LL);
    if ( *((_DWORD *)v3 - 1) != -1840578834 )
      __break(0x8228u);
    result = v3();
    _X9 = (unsigned __int64 *)(_X19 + 32);
    __asm { PRFM            #0x11, [X9] }
    do
      v11 = __ldxr(_X9);
    while ( __stlxr(v11 | 2, _X9) );
    __dmb(0xBu);
    if ( (v11 & 2) == 0 )
    {
      v4 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(_X19 + 40) + 8752LL) + 128LL);
      if ( *((_DWORD *)v4 - 1) != -940862279 )
        __break(0x8228u);
      v4(_X19);
      kgsl_cancel_events(v1, _X19 + 64);
      kgsl_del_event_group(v1, _X19 + 64);
      result = kgsl_sync_timeline_detach(*(_QWORD *)(_X19 + 56));
      __asm { PRFM            #0x11, [X19] }
      do
        v13 = __ldxr((unsigned int *)_X19);
      while ( __stlxr(v13 - 1, (unsigned int *)_X19) );
      if ( v13 == 1 )
      {
        __dmb(9u);
        return kgsl_context_destroy(_X19);
      }
      else if ( v13 <= 0 )
      {
        return refcount_warn_saturate(_X19, 3);
      }
    }
  }
  return result;
}
