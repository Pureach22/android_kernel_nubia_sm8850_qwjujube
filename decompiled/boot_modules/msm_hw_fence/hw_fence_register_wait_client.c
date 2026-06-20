__int64 __fastcall hw_fence_register_wait_client(
        __int64 a1,
        _QWORD *a2,
        unsigned int *a3,
        __int64 a4,
        __int64 a5,
        unsigned __int64 *a6,
        __int64 a7)
{
  __int64 v7; // x30
  __int64 v8; // x23
  __int64 v14; // x4
  unsigned __int64 v15; // x25
  __int64 v16; // x3
  unsigned int v17; // w26
  __int64 v18; // x0
  unsigned int v19; // w9
  __int64 v20; // x8
  unsigned int v21; // w26
  char v22; // w27
  __int64 v23; // x10
  __int64 v24; // x8
  __int64 (__fastcall *v25)(_QWORD); // x9
  __int64 result; // x0
  __int64 v27; // x30
  unsigned int v28; // w23
  __int64 v29; // x22
  __int64 v30; // x4
  __int64 v31; // x4
  unsigned __int64 v38; // x9
  _BYTE v39[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+8h] [xbp-8h]

  v8 = v7;
  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39[0] = 0;
  if ( a7 && a3[1] != 1 )
  {
    printk(&unk_27233, "hw_fence_register_wait_client", 2178, v7, a7);
    result = 4294967274LL;
    goto LABEL_26;
  }
  if ( a2 )
  {
    v15 = hw_fence_find_with_dma_fence(a1, a3, a2, a6, v39, 1);
    if ( !v15 )
    {
      v16 = v8;
LABEL_30:
      printk(&unk_29DED, "hw_fence_register_wait_client", 2191, v16, v14);
      result = 4294967274LL;
      goto LABEL_26;
    }
  }
  else
  {
    if ( a3 )
      v17 = *a3;
    else
      v17 = -1;
    v15 = hw_fence_lookup_and_process_range(
            a1,
            a4,
            a4,
            a5,
            a6,
            0,
            *(_DWORD *)(a1 + 80),
            (__int64 (__fastcall *)(_QWORD))fence_found);
    if ( !v15 )
    {
      printk(&unk_291E6, "msm_hw_fence_find", 1862, v8, v17);
      v16 = v8;
      goto LABEL_30;
    }
  }
  v18 = global_atomic_store(a1, v15 + 40, 1);
  v19 = *a3;
  v20 = *(_QWORD *)(v15 + 48);
  if ( *(_DWORD *)(v15 + 32) != *a3 )
  {
    v22 = 1;
    v23 = *(_QWORD *)(v15 + 24);
    v39[0] = v20 & 1;
    v24 = v23 | (1LL << v19);
    v25 = (__int64 (__fastcall *)(_QWORD))arch_timer_read_counter;
    *(_QWORD *)(v15 + 24) = v24;
    if ( *((_DWORD *)v25 - 1) != -1073338243 )
      __break(0x8229u);
    v21 = 0;
    *(_QWORD *)(v15 + 104) = v25(v18);
    if ( !a7 )
      goto LABEL_19;
    *(_QWORD *)(v15 + 120) = a7;
    goto LABEL_17;
  }
  if ( (v20 & 1) == 0 )
  {
    v21 = 0;
    *(_DWORD *)(v15 + 112) |= 0x80000000;
LABEL_17:
    v22 = 1;
    goto LABEL_19;
  }
  v22 = 0;
  v21 = -22;
LABEL_19:
  __dsb(0xEu);
  global_atomic_store(a1, v15 + 40, 0);
  if ( (v22 & 1) != 0 )
  {
    if ( v39[0] == 1 )
    {
      if ( a2 )
      {
        _X8 = a2 + 6;
        __asm { PRFM            #0x11, [X8] }
        do
          v38 = __ldxr(_X8);
        while ( __stxr(v38 | 0x40000000, _X8) );
      }
      result = fence_ctl_signal(a1, a3, v15, *a6, a7, *(_DWORD *)(v15 + 4), 1);
      if ( (_DWORD)result )
      {
        v27 = v8;
        v28 = result;
        v29 = v27;
        if ( a3 )
          v30 = *a3;
        else
          v30 = 255;
        printk(&unk_286F4, "hw_fence_register_wait_client", 2234, v27, v30);
        if ( (unsigned int)hw_fence_destroy_with_hash(a1, a3, *a6) )
        {
          if ( a3 )
            v31 = *a3;
          else
            v31 = 255;
          printk(&unk_209FF, "hw_fence_register_wait_client", 2238, v29, v31);
        }
        result = v28;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    printk(&unk_23F7A, "hw_fence_register_wait_client", 2222, v8, *(unsigned int *)(v15 + 32));
    result = v21;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
