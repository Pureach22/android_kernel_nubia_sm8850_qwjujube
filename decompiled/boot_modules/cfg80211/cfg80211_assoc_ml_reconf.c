__int64 __fastcall cfg80211_assoc_ml_reconf(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x0
  unsigned int v7; // w21
  __int64 i; // x22
  unsigned int v12; // w9
  __int64 v13; // x8
  unsigned int v20; // w10
  __int64 v21; // x8

  v5 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)a1 + 1008LL);
  if ( v5 )
  {
    v6 = a1 + 992;
    if ( *((_DWORD *)v5 - 1) != 975299355 )
      __break(0x8228u);
    v7 = v5(v6);
  }
  else
  {
    v7 = -95;
  }
  if ( !v7 )
  {
    for ( i = 0; i != 480; i += 32 )
    {
      if ( *(_QWORD *)(a3 + i) )
      {
        cfg80211_ref_bss(a1 + 992);
        v13 = *(_QWORD *)(a3 + i);
        _X9 = (unsigned int *)(v13 - 32);
        __asm { PRFM            #0x11, [X9] }
        do
          v20 = __ldxr(_X9);
        while ( __stxr(v20 + 1, _X9) );
        v21 = *(_QWORD *)(v13 + 40);
        if ( v21 )
        {
          _X8 = (unsigned int *)(v21 - 32);
          __asm { PRFM            #0x11, [X8] }
          do
            v12 = __ldxr(_X8);
          while ( __stxr(v12 + 1, _X8) );
        }
      }
    }
  }
  return v7;
}
