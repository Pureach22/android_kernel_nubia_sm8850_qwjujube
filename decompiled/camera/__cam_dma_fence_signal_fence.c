__int64 __fastcall _cam_dma_fence_signal_fence(_QWORD *a1, unsigned int a2)
{
  __int64 (__fastcall *v4)(_QWORD); // x8
  unsigned int v5; // w20

  raw_spin_lock_bh(*a1);
  if ( (a1[6] & 1) == 0 )
  {
    v4 = *(__int64 (__fastcall **)(_QWORD))(a1[1] + 32LL);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != 1879296680 )
        __break(0x8228u);
      if ( (v4(a1) & 1) != 0 )
      {
        dma_fence_signal_locked(a1);
        goto LABEL_7;
      }
    }
    if ( !a2 )
    {
LABEL_14:
      v5 = dma_fence_signal_locked(a1);
      goto LABEL_15;
    }
    if ( (a1[6] & 1) != 0 )
    {
      __break(0x800u);
      if ( a2 > 0xFFFFF000 )
        goto LABEL_13;
    }
    else if ( a2 > 0xFFFFF000 )
    {
LABEL_13:
      *((_DWORD *)a1 + 15) = a2;
      goto LABEL_14;
    }
    __break(0x800u);
    goto LABEL_13;
  }
LABEL_7:
  v5 = -1;
  if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x400000000LL,
      4,
      "__cam_dma_fence_signal_fence",
      475,
      "dma fence seqno: %llu is already signaled",
      a1[5]);
LABEL_15:
  raw_spin_unlock_bh(*a1);
  return v5;
}
