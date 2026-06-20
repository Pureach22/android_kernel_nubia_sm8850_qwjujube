__int64 __fastcall hw_fence_destroy_refcount(__int64 a1, unsigned __int64 a2, unsigned int a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  unsigned __int64 v7; // x23
  int v9; // w8
  int v10; // w8
  __int64 result; // x0
  __int64 v12; // x20

  v4 = v3;
  if ( *(unsigned int *)(a1 + 16) <= a2 )
  {
    v12 = v3;
    printk(&unk_23ADB, "_get_hw_fence", 1135, v3, a2);
LABEL_11:
    printk(&unk_26B44, "hw_fence_destroy_refcount", 1275, v12, a2);
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(a1 + 64) + (a2 << 7);
  if ( !v7 )
  {
    v12 = v3;
    goto LABEL_11;
  }
  global_atomic_store(a1, v7 + 40, 1);
  v9 = *(_DWORD *)(v7 + 112);
  if ( (v9 & a3) != 0 )
  {
    v10 = v9 & ~a3;
    *(_DWORD *)(v7 + 112) = v10;
    if ( !v10 )
    {
      *(_DWORD *)(v7 + 4) = 0;
      __dsb(0xEu);
      *(_QWORD *)(v7 + 8) = 0;
      *(_QWORD *)(v7 + 16) = 0;
      *(_QWORD *)(v7 + 24) = 0;
      *(_QWORD *)(v7 + 32) = 0;
      *(_QWORD *)(v7 + 80) = 0;
      *(_QWORD *)(v7 + 88) = 0;
      *(_QWORD *)(v7 + 96) = 0;
      *(_QWORD *)(v7 + 104) = 0;
      *(_QWORD *)(v7 + 48) = 0;
      *(_QWORD *)(v7 + 56) = -1;
      *(_QWORD *)(v7 + 64) = -1;
      *(_QWORD *)(v7 + 72) = -1;
      *(_QWORD *)(v7 + 112) = 0;
      *(_QWORD *)(v7 + 120) = 0;
      *(_DWORD *)v7 = 0;
    }
    global_atomic_store(a1, v7 + 40, 0);
    result = 0;
    if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
    {
      printk(&unk_21759, "hw_fence_destroy_refcount", 1298, a3, a2);
      return 0;
    }
  }
  else
  {
    global_atomic_store(a1, v7 + 40, 0);
    printk(&unk_2A1FD, "hw_fence_destroy_refcount", 1285, v4, *(_QWORD *)(v7 + 8));
    return 4294967274LL;
  }
  return result;
}
