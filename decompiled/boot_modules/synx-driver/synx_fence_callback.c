__int64 __fastcall synx_fence_callback(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v4)(_QWORD); // x8
  unsigned int v5; // w8
  int v6; // w9
  _QWORD *v7; // x19

  if ( (synx_debug & 8) != 0 )
  {
    printk(&unk_25742, &unk_2A972, "synx_fence_callback", 827, a1, *(unsigned int *)(a2 - 32));
    if ( (*(_QWORD *)(a1 + 48) & 1) != 0 )
      goto LABEL_8;
  }
  else if ( (*(_QWORD *)(a1 + 48) & 1) != 0 )
  {
    goto LABEL_8;
  }
  v4 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 32LL);
  if ( !v4 )
    goto LABEL_19;
  if ( *((_DWORD *)v4 - 1) != 1879296680 )
    __break(0x8228u);
  if ( (v4(a1) & 1) == 0 )
  {
    LODWORD(v4) = 0;
    goto LABEL_19;
  }
  dma_fence_signal_locked(a1);
LABEL_8:
  v5 = *(_DWORD *)(a1 + 60);
  if ( v5 <= 1 )
    v6 = 1;
  else
    v6 = *(_DWORD *)(a1 + 60);
  if ( v6 == 1 )
  {
    LODWORD(v4) = 2;
  }
  else if ( v6 == -4 )
  {
    LODWORD(v4) = 4;
  }
  else if ( v5 <= 0xFFFFFFBF )
  {
    LODWORD(v4) = -v6;
  }
  else
  {
    LODWORD(v4) = 5;
  }
LABEL_19:
  *(_QWORD *)(a2 + 24) = 0xFFFFFFFE00000LL;
  v7 = (_QWORD *)(a2 + 24);
  *((_DWORD *)v7 - 13) = (_DWORD)v4;
  v7[1] = v7 + 1;
  v7[2] = v7 + 1;
  v7[3] = synx_signal_handler;
  return queue_work_on(32, *(_QWORD *)(synx_dev + 160), v7);
}
