unsigned __int64 __fastcall put_si_object(unsigned __int64 result)
{
  unsigned __int64 v2; // x19
  __int64 (*v3)(void); // x8
  int v4; // w8
  __int64 v5; // x19
  void (*v6)(void); // x8
  int v12; // w9

  if ( (_UNKNOWN *)result != &static_si_object_primordial && result >= 2 )
  {
    _X8 = (unsigned int *)(result + 8);
    __asm { PRFM            #0x11, [X8] }
    do
      v12 = __ldxr(_X8);
    while ( __stlxr(v12 - 1, _X8) );
    if ( v12 == 1 )
    {
      __dmb(9u);
      v2 = result;
      v3 = *(__int64 (**)(void))(result + 80);
      if ( v3 )
      {
        if ( *((_DWORD *)v3 - 1) != -430973329 )
          __break(0x8228u);
        result = v3();
      }
      synchronize_rcu(result);
      v4 = *(_DWORD *)(v2 + 12);
      result = v2;
      if ( v4 == 2 )
      {
        v5 = *(_QWORD *)v2;
        v6 = **(void (***)(void))(result + 24);
        if ( v6 )
        {
          if ( *((_DWORD *)v6 - 1) != -430973329 )
            __break(0x8228u);
          v6();
        }
        return kfree_const(v5);
      }
      else if ( v4 == 1 )
      {
        return release_user_object(v2);
      }
    }
    else if ( v12 <= 0 )
    {
      return refcount_warn_saturate(result + 8, 3);
    }
  }
  return result;
}
