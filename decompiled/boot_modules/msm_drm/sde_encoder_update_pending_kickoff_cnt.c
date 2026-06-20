__int64 __fastcall sde_encoder_update_pending_kickoff_cnt(__int64 a1)
{
  __int64 v1; // x8
  unsigned int v2; // w10
  unsigned int v9; // w12
  unsigned int v10; // w9
  __int64 result; // x0
  unsigned int v14; // w11

  if ( a1 && (v1 = *(_QWORD *)(a1 + 328)) != 0 )
  {
    v2 = *(_DWORD *)(v1 + 876);
    _X9 = (unsigned int *)(v1 + 876);
    do
    {
      if ( !v2 )
        break;
      __asm { PRFM            #0x11, [X9] }
      while ( 1 )
      {
        v9 = __ldxr(_X9);
        if ( v9 != v2 )
          break;
        if ( !__stlxr(v2 - 1, _X9) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v9 == v2;
      v2 = v9;
    }
    while ( !_ZF );
    v10 = *(_DWORD *)(v1 + 880);
    while ( v10 )
    {
      _X13 = (unsigned int *)(v1 + 880);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v14 = __ldxr(_X13);
        if ( v14 != v10 )
          break;
        if ( !__stlxr(v10 - 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      result = 0;
      _ZF = v14 == v10;
      v10 = v14;
      if ( _ZF )
        return result;
    }
    return 0;
  }
  else
  {
    printk(&unk_26FCAB, "sde_encoder_update_pending_kickoff_cnt");
    return 4294967274LL;
  }
}
