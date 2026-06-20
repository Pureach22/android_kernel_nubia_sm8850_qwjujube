__int64 __fastcall hw_fence_dma_fence_table_add(__int64 a1, unsigned int *a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  int v7; // w21
  __int64 v8; // x1
  __int64 v9; // x10
  __int64 v10; // x9
  _QWORD *v11; // x10
  __int64 v12; // x8
  __int64 v14; // x22

  if ( a2 && a1 && a3 )
  {
    v7 = a4 & 0xFFF;
    if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
    {
      v14 = a4;
      printk(&unk_29D69, "hw_fence_dma_fence_table_add", 1507, a3, *a2);
      a4 = v14;
    }
    *(_DWORD *)(a3 + 136) = v7;
    *(_BYTE *)(a3 + 140) = 1;
    *(_QWORD *)(a3 + 168) = a1;
    *(_QWORD *)(a3 + 176) = a4;
    v8 = raw_spin_lock_irqsave(a1 + 748);
    v9 = a1 + 8LL * ((unsigned int)(1640531527 * v7) >> 20);
    v10 = *(_QWORD *)(v9 + 752);
    v11 = (_QWORD *)(v9 + 752);
    *(_QWORD *)(a3 + 184) = v10;
    v12 = a3 + 184;
    if ( v10 )
      *(_QWORD *)(v10 + 8) = v12;
    *v11 = v12;
    *(_QWORD *)(a3 + 192) = v11;
    raw_spin_unlock_irqrestore(a1 + 748, v8);
    return 0;
  }
  else
  {
    printk(&unk_296F1, "hw_fence_dma_fence_table_add", 1500, v4, a3);
    return 4294967274LL;
  }
}
