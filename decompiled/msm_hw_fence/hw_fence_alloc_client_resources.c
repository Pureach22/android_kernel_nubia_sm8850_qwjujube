__int64 __fastcall hw_fence_alloc_client_resources(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 v3; // x30
  __int64 v4; // x5
  __int64 v5; // x21
  __int64 v6; // x8
  unsigned int inited; // w0
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x8
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x4
  unsigned int v17; // w19

  v4 = *(unsigned int *)a2;
  v5 = v3;
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 16 * v4);
  if ( v6 )
  {
    inited = init_hw_fences_queues(a1, 3, a2 + 1, a2 + 5, *(unsigned int *)(v6 + 20), v4);
    if ( inited )
    {
      v16 = *(unsigned int *)a2;
      v17 = inited;
      printk(&unk_261B7, "hw_fence_alloc_client_resources", 887, v5, v16);
      return v17;
    }
    else if ( a3 && (unsigned __int64)a3 <= 0xFFFFFFFFFFFFF000LL )
    {
      v12 = a2[4];
      v14 = a2[1];
      v15 = a2[2];
      a3[2] = a2[3];
      a3[3] = v12;
      *a3 = v14;
      a3[1] = v15;
      return 0;
    }
    else
    {
      if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
        printk(&unk_26666, "hw_fence_alloc_client_resources", 896, v10, v11);
      return 0;
    }
  }
  else
  {
    printk(&unk_2268C, "hw_fence_alloc_client_resources", 876, v3, (unsigned int)v4);
    return 4294967274LL;
  }
}
