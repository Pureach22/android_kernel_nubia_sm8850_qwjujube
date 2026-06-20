unsigned __int64 __fastcall hw_fence_find_with_dma_fence(
        __int64 a1,
        unsigned int *a2,
        _QWORD *a3,
        unsigned __int64 *a4,
        _BYTE *a5,
        char a6)
{
  __int64 v6; // x30
  unsigned int v12; // w20
  __int64 v13; // x25
  __int64 (__fastcall *v14)(_QWORD); // x8
  unsigned int v15; // w8
  unsigned int v16; // w5
  unsigned int v17; // w27
  unsigned int v18; // w6
  unsigned __int64 result; // x0
  __int64 (__fastcall *v20)(_QWORD); // x8

  if ( a2 )
  {
    v12 = *a2;
    if ( (a3[6] & 1) != 0 )
    {
LABEL_22:
      *a5 = 1;
      if ( (a6 & 1) != 0 )
        return create_signaled_hw_fence(a1, v12, a3, a4);
      else
        return 0;
    }
  }
  else
  {
    v12 = 255;
    if ( (a3[6] & 1) != 0 )
      goto LABEL_22;
  }
  v13 = v6;
  v14 = *(__int64 (__fastcall **)(_QWORD))(a3[1] + 32LL);
  if ( v14 )
  {
    if ( *((_DWORD *)v14 - 1) != 1879296680 )
      __break(0x8228u);
    if ( (v14(a3) & 1) != 0 )
    {
LABEL_21:
      dma_fence_signal(a3);
      goto LABEL_22;
    }
  }
  v15 = *(_DWORD *)(a1 + 80);
  if ( v15 )
  {
    v16 = 0;
    while ( 1 )
    {
      v17 = v16 + 10;
      v18 = v16 + 10 >= v15 ? v15 : v16 + 10;
      result = hw_fence_lookup_and_process_range(
                 a1,
                 (__int64)a3,
                 a3[4],
                 a3[5],
                 a4,
                 v16,
                 v18,
                 (__int64 (__fastcall *)(_QWORD))fence_found);
      if ( result )
        break;
      if ( (a3[6] & 1) != 0 )
        goto LABEL_22;
      v20 = *(__int64 (__fastcall **)(_QWORD))(a3[1] + 32LL);
      if ( v20 )
      {
        if ( *((_DWORD *)v20 - 1) != 1879296680 )
          __break(0x8228u);
        if ( (v20(a3) & 1) != 0 )
          goto LABEL_21;
      }
      v15 = *(_DWORD *)(a1 + 80);
      v16 = v17;
      if ( v17 >= v15 )
        goto LABEL_25;
    }
  }
  else
  {
LABEL_25:
    printk(&unk_21175, "hw_fence_find_with_dma_fence", 2445, v13, v12);
    result = 0;
  }
  *a5 = 0;
  return result;
}
