__int64 __fastcall synx_get_client(unsigned __int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x10
  __int64 v4; // x8
  __int64 v6; // x8
  unsigned int v13; // w9

  v1 = -22;
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL )
  {
    raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152));
    v3 = *(_QWORD *)(*(_QWORD *)(synx_dev + 152) + 8 * ((0x61C8864680B583EBLL * a1) >> 56) + 8);
    v4 = v3 - 264960;
    if ( v3 )
      _ZF = v3 == 264960;
    else
      _ZF = 1;
    if ( _ZF )
      goto LABEL_15;
    while ( v4 != a1 )
    {
      v6 = *(_QWORD *)(v4 + 264960);
      v1 = 0;
      if ( v6 )
      {
        v4 = v6 - 264960;
        if ( v4 )
          continue;
      }
      goto LABEL_16;
    }
    if ( *(_BYTE *)(v4 + 24) != 1 )
    {
LABEL_15:
      v1 = 0;
    }
    else
    {
      _X0 = (unsigned int *)(v4 + 120);
      __asm { PRFM            #0x11, [X0] }
      do
        v13 = __ldxr(_X0);
      while ( __stxr(v13 + 1, _X0) );
      if ( v13 )
      {
        v1 = v4;
        if ( (((v13 + 1) | v13) & 0x80000000) != 0 )
          refcount_warn_saturate(_X0, 1);
      }
      else
      {
        v1 = v4;
        refcount_warn_saturate(_X0, 2);
      }
    }
LABEL_16:
    raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152));
  }
  return v1;
}
