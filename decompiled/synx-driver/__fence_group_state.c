__int64 __fastcall _fence_group_state(unsigned __int64 a1, char a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v9; // x25
  int v10; // w21
  unsigned int v11; // w23
  unsigned int v12; // w20
  unsigned int v13; // w24
  unsigned int v14; // w0

  if ( a1 && a1 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( *(_UNKNOWN **)(a1 + 8) != &dma_fence_array_ops )
    {
      if ( (synx_debug & 1) != 0 )
      {
        printk(&unk_2A4C0, &unk_29207, "__fence_group_state", 897, a1, a6);
        return 0;
      }
      return 0;
    }
    if ( *(_DWORD *)(a1 + 68) )
    {
      v9 = 0;
      v10 = 0;
      v11 = 0;
      v12 = 0;
      v13 = 0;
      while ( 1 )
      {
        v14 = _fence_state(*(_QWORD *)(*(_QWORD *)(a1 + 80) + 8 * v9), a2 & 1, a3, a4, a5, a6);
        if ( !v10 )
          v13 = v14;
        if ( v14 != 2 )
        {
          if ( v14 == 1 )
          {
            ++v12;
            goto LABEL_11;
          }
          if ( v14 < 0x41 )
          {
            ++v10;
            goto LABEL_11;
          }
        }
        ++v11;
LABEL_11:
        if ( ++v9 >= (unsigned __int64)*(unsigned int *)(a1 + 68) )
          goto LABEL_20;
      }
    }
    v13 = 0;
    v12 = 0;
    v11 = 0;
LABEL_20:
    if ( (synx_debug & 8) != 0 )
      printk(&unk_2AC32, &unk_2A972, "__fence_group_state", 919, v12, v11);
    if ( v12 )
      return 1;
    else
      return v13;
  }
  else
  {
    if ( (synx_debug & 1) == 0 )
      return 0;
    printk(&unk_289DC, &unk_29207, "__fence_group_state", 890, a5, a6);
    return 0;
  }
}
