__int64 __fastcall msm_atomic_prepare_fb(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x21
  unsigned int v6; // w20
  __int64 v7; // x0
  __int64 v8; // x8
  int v15; // w8

  result = *(_QWORD *)(a2 + 16);
  if ( result )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 56LL) + 8LL);
    if ( *(_BYTE *)(*(_QWORD *)(result + 72) + 5LL) )
    {
      v6 = 0;
      do
      {
        v7 = msm_framebuffer_bo(result, v6);
        msm_dma_resv_get_excl(a2, v7);
        v8 = *(_QWORD *)(a2 + 24);
        if ( v8 )
        {
          _X0 = (unsigned int *)(v8 + 56);
          __asm { PRFM            #0x11, [X0] }
          do
            v15 = __ldxr(_X0);
          while ( __stlxr(v15 - 1, _X0) );
          if ( v15 == 1 )
          {
            __dmb(9u);
            dma_fence_release(_X0);
          }
          else if ( v15 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
        }
        result = *(_QWORD *)(a2 + 16);
        *(_QWORD *)(a2 + 24) = 0;
        ++v6;
      }
      while ( v6 < *(unsigned __int8 *)(*(_QWORD *)(result + 72) + 5LL) );
    }
    return msm_framebuffer_prepare(result, *(_QWORD *)(v4 + 16));
  }
  return result;
}
