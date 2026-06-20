__int64 __fastcall synx_hwfence_release(unsigned int **a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  __int64 v8; // x0
  __int64 v10; // x4
  unsigned int v11; // w19

  v6 = v5;
  if ( a1 && (unsigned __int64)a1 <= 0xFFFFFFFFFFFFF000LL && a2 < 0 && (unsigned int)(*(_DWORD *)a1 - 4096) > 0xFFFFF3FF )
  {
    v8 = msm_hw_fence_destroy_with_handle(a1[1], (unsigned __int16)a2, a3, a4, a5);
    if ( (_DWORD)v8 )
    {
      v10 = *(unsigned int *)a1;
      v11 = v8;
      printk(&unk_28EE1, "synx_hwfence_release", 262, v6, v10);
      v8 = v11;
    }
    return hw_fence_interop_to_synx_status(v8);
  }
  else
  {
    printk(&unk_2527A, "synx_hwfence_release", 254, v5, a1);
    return 4294967274LL;
  }
}
