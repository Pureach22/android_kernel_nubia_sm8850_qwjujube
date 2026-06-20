__int64 __fastcall syncobj_destroy_object(__int64 a1)
{
  unsigned int i; // w21
  __int64 v3; // x0
  __int64 v4; // x25
  int v5; // w8
  _QWORD *v6; // x20
  __int64 v7; // x8
  __int64 v9; // x20
  int v15; // w9
  __int64 v16; // x20

  if ( *(_DWORD *)(a1 + 64) )
  {
    for ( i = 0; i < *(_DWORD *)(a1 + 64); ++i )
    {
      v4 = *(_QWORD *)(a1 + 56) + 120LL * (int)i;
      v5 = *(_DWORD *)(v4 + 4);
      if ( v5 == 2 )
      {
        v3 = *(_QWORD *)(v4 + 48);
      }
      else
      {
        if ( v5 != 1 )
          continue;
        v6 = *(_QWORD **)(v4 + 48);
        if ( v6 )
        {
          kfree(*v6);
          kfree(v6);
        }
        v3 = *(_QWORD *)(v4 + 32);
        if ( !v3 )
          continue;
        v7 = *(_QWORD *)(v3 + 24);
        if ( v7 )
        {
          _X8 = (unsigned int *)(v7 + 56);
          __asm { PRFM            #0x11, [X8] }
          do
            v15 = __ldxr(_X8);
          while ( __stlxr(v15 - 1, _X8) );
          if ( v15 == 1 )
          {
            __dmb(9u);
            v9 = v3;
            dma_fence_release(_X8);
            v3 = v9;
          }
          else if ( v15 <= 0 )
          {
            v16 = v3;
            refcount_warn_saturate(_X8, 3);
            v3 = v16;
          }
        }
      }
      kfree(v3);
    }
  }
  kfree(*(_QWORD *)(a1 + 144));
  kfree(*(_QWORD *)(a1 + 56));
  return kfree(a1);
}
