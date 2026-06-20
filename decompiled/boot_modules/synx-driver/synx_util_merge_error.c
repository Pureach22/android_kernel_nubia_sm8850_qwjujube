__int64 __fastcall synx_util_merge_error(__int64 a1, unsigned __int64 a2, unsigned int a3, unsigned __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 *v5; // x20
  unsigned __int64 *v6; // x19
  bool v7; // cc
  __int64 v8; // x22
  char v9; // w21
  unsigned __int64 v10; // x8
  int v17; // w8
  unsigned __int64 v18; // x0

  result = 4294967274LL;
  if ( a2 )
  {
    v5 = (unsigned __int64 *)a2;
    if ( a2 <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( a3 )
      {
        v6 = (unsigned __int64 *)a4;
        if ( a4 )
          v7 = a4 > 0xFFFFFFFFFFFFF000LL;
        else
          v7 = 1;
        v8 = a3;
        v9 = v7;
        do
        {
          v10 = *v5;
          if ( *v5 && v10 <= 0xFFFFFFFFFFFFF000LL )
          {
            _X0 = (unsigned int *)(v10 + 56);
            __asm { PRFM            #0x11, [X0] }
            do
              v17 = __ldxr(_X0);
            while ( __stlxr(v17 - 1, _X0) );
            if ( v17 == 1 )
            {
              __dmb(9u);
              dma_fence_release(_X0);
              if ( (v9 & 1) == 0 )
                goto LABEL_21;
            }
            else if ( v17 <= 0 )
            {
              refcount_warn_saturate(_X0, 3);
              if ( (v9 & 1) == 0 )
              {
LABEL_21:
                v18 = *v6;
                if ( *v6 )
                {
                  if ( v18 <= 0xFFFFFFFFFFFFF000LL )
                    synx_util_release_map_entry(v18);
                }
              }
            }
            else if ( (v9 & 1) == 0 )
            {
              goto LABEL_21;
            }
          }
          --v8;
          ++v5;
          ++v6;
        }
        while ( v8 );
      }
      return 0;
    }
  }
  return result;
}
