__int64 __fastcall hw_fence_signal_fence(__int64 a1, __int64 a2, unsigned __int64 a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x1
  __int64 v8; // x7
  __int64 v9; // x8
  unsigned __int64 v11; // x20
  __int64 v12; // x19

  if ( !a1 )
  {
    printk(&unk_236CD, "hw_fence_signal_fence", 2575, v5, a5);
    return 4294967274LL;
  }
  if ( *(unsigned int *)(a1 + 16) <= a3 )
  {
    v11 = a3;
    v12 = v5;
    printk(&unk_23ADB, "_get_hw_fence", 1135, v5, a3);
LABEL_12:
    printk(&unk_26B44, "hw_fence_signal_fence", 2581, v12, v11);
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(a1 + 64) + (a3 << 7);
  if ( !v7 )
  {
    v11 = a3;
    v12 = v5;
    goto LABEL_12;
  }
  if ( !a2
    || (v8 = *(_QWORD *)(a2 + 32), v9 = *(_QWORD *)(a2 + 40), *(_QWORD *)(v7 + 8) == v8) && *(_QWORD *)(v7 + 16) == v9 )
  {
    signal_fence_if_unsignaled(a1, v7, a3, a4, a5 & 1);
    return 0;
  }
  else
  {
    printk(&unk_20A70, "hw_fence_signal_fence", 2587, v5, a3);
    return 4294967274LL;
  }
}
