__int64 __fastcall synx_util_cleanup_merged_fence(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned int v6; // w19
  unsigned __int64 v7; // x25
  unsigned __int64 v9; // x26
  unsigned __int64 v10; // x0
  __int64 v11; // x8

  v6 = -22;
  if ( a1 )
  {
    if ( a1 <= 0xFFFFFFFFFFFFF000LL )
    {
      v7 = *(_QWORD *)(a1 + 64);
      if ( v7 )
      {
        if ( v7 <= 0xFFFFFFFFFFFFF000LL )
        {
          if ( *(_UNKNOWN **)(v7 + 8) == &dma_fence_array_ops && *(_DWORD *)(v7 + 68) )
          {
            v9 = 0;
            v6 = 0;
            do
            {
              v10 = *(_QWORD *)(*(_QWORD *)(v7 + 80) + 8 * v9);
              if ( *(_DWORD *)(v10 + 56) == 1 )
              {
                if ( v10 && v10 < 0xFFFFFFFFFFFFF001LL )
                {
                  if ( !(unsigned int)dma_fence_get_status() )
                  {
                    v11 = *(_QWORD *)(*(_QWORD *)(v7 + 80) + 8 * v9);
                    if ( (*(_QWORD *)(v11 + 48) & 1) != 0 )
                      __break(0x800u);
                    *(_DWORD *)(v11 + 60) = -4;
                    v6 = dma_fence_signal(*(_QWORD *)(*(_QWORD *)(v7 + 80) + 8 * v9));
                    if ( v6 && (synx_debug & 1) != 0 )
                      printk(
                        &unk_29099,
                        &unk_29207,
                        "synx_util_cleanup_merged_fence",
                        373,
                        *(_QWORD *)(*(_QWORD *)(v7 + 80) + 8 * v9),
                        v6);
                  }
                }
                else if ( (synx_debug & 1) != 0 )
                {
                  printk(&unk_289DC, &unk_29207, "__fence_state", 846, a5, a6);
                }
              }
              ++v9;
            }
            while ( v9 < *(unsigned int *)(v7 + 68) );
          }
          else
          {
            return 0;
          }
        }
      }
    }
  }
  return v6;
}
