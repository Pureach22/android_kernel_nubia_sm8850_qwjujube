__int64 __fastcall synx_hwfence_uninitialize(unsigned int **a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  unsigned int v8; // w21

  v6 = v5;
  if ( a1 && (unsigned __int64)a1 <= 0xFFFFFFFFFFFFF000LL && (unsigned int)(*(_DWORD *)a1 - 1024) < 0xC00 )
  {
    v8 = msm_hw_fence_deregister(a1[1], a2, a3, a4, a5);
    if ( v8 )
      printk(&unk_26E7C, "synx_hwfence_uninitialize", 183, v6, *(unsigned int *)a1);
    else
      kfree(a1);
    return hw_fence_interop_to_synx_status(v8);
  }
  else
  {
    printk(&unk_2527A, "synx_hwfence_uninitialize", 177, v5, a1);
    return 4294967274LL;
  }
}
