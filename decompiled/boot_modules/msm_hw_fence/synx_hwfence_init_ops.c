__int64 __fastcall synx_hwfence_init_ops(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30

  if ( a1 && (unsigned __int64)a1 < 0xFFFFFFFFFFFFF001LL )
  {
    *a1 = synx_hwfence_uninitialize;
    a1[1] = synx_hwfence_create;
    a1[14] = synx_hwfence_release_n;
    a1[4] = synx_hwfence_signal;
    a1[5] = synx_hwfence_signal_n;
    a1[11] = synx_hwfence_get_fence;
    a1[12] = synx_hwfence_release;
    a1[9] = synx_hwfence_get_status;
    a1[10] = synx_hwfence_import;
    a1[7] = synx_hwfence_wait;
    return 0;
  }
  else
  {
    printk(&unk_23466, "synx_hwfence_init_ops", 697, v5, a5);
    return 4294967274LL;
  }
}
