__int64 __fastcall synx_dma_fence_callback(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v4)(_QWORD); // x8
  unsigned int v5; // w8
  __int64 v6; // x4

  if ( (synx_debug & 8) != 0 )
  {
    printk(&unk_2AB61, &unk_2A972, "synx_dma_fence_callback", 355, a1, a2);
    if ( (*(_QWORD *)(a1 + 48) & 1) != 0 )
      goto LABEL_8;
  }
  else if ( (*(_QWORD *)(a1 + 48) & 1) != 0 )
  {
    goto LABEL_8;
  }
  v4 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 32LL);
  if ( !v4 )
    goto LABEL_13;
  if ( *((_DWORD *)v4 - 1) != 1879296680 )
    __break(0x8228u);
  if ( (v4(a1) & 1) == 0 )
  {
LABEL_13:
    v6 = 0;
    if ( (synx_debug & 8) == 0 )
      return kfree(a2);
LABEL_14:
    printk(&unk_2B290, &unk_2A972, "synx_dma_fence_callback", 361, v6, a1);
    return kfree(a2);
  }
  dma_fence_signal_locked(a1);
LABEL_8:
  v5 = *(_DWORD *)(a1 + 60);
  if ( v5 <= 1 )
    v6 = 1;
  else
    v6 = v5;
  if ( (synx_debug & 8) != 0 )
    goto LABEL_14;
  return kfree(a2);
}
