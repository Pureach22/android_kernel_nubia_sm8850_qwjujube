__int64 __fastcall synx_internal_get_dma_fence(int a1)
{
  unsigned __int64 v2; // x8
  __int64 i; // x10
  __int64 v5; // x10
  __int64 v6; // x19
  unsigned int v13; // w8

  raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152) + 2056LL);
  v2 = 0;
  do
  {
    for ( i = *(_QWORD *)(*(_QWORD *)(synx_dev + 152) + 2064LL + 8 * v2); i; i = *(_QWORD *)(v5 + 16) )
    {
      v5 = i - 16;
      if ( !v5 )
        break;
      if ( *(_DWORD *)v5 == a1 )
      {
        v6 = *(_QWORD *)(v5 + 8);
        if ( v6 )
        {
          _X0 = (unsigned int *)(v6 + 56);
          __asm { PRFM            #0x11, [X0] }
          do
            v13 = __ldxr(_X0);
          while ( __stxr(v13 + 1, _X0) );
          if ( !v13 || (((v13 + 1) | v13) & 0x80000000) != 0 )
            refcount_warn_saturate();
        }
        goto LABEL_12;
      }
    }
  }
  while ( v2++ < 0x3FF );
  v6 = 0;
LABEL_12:
  raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 2056LL);
  return v6;
}
