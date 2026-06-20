__int64 __fastcall synx_hwfence_init_interops(
        unsigned __int64 a1,
        __int64 (__fastcall **a2)(unsigned __int64 a1, __int64 a2, unsigned int *a3, __int64 a4, __int64 a5))
{
  __int64 v2; // x30
  void *v4; // x10
  void *v6; // x8
  void *v7; // x10

  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL && a2 && (unsigned __int64)a2 < 0xFFFFFFFFFFFFF001LL )
  {
    v4 = *(void **)(a1 + 8);
    synx_interops = *(_UNKNOWN **)a1;
    off_2B780 = v4;
    v6 = *(void **)(a1 + 24);
    v7 = *(void **)(a1 + 32);
    off_2B788 = *(_UNKNOWN **)(a1 + 16);
    off_2B790 = v6;
    off_2B798 = v7;
    *a2 = hw_fence_interop_share_handle_status;
    a2[1] = (__int64 (__fastcall *)(unsigned __int64, __int64, unsigned int *, __int64, __int64))hw_fence_interop_get_fence;
    a2[3] = (__int64 (__fastcall *)(unsigned __int64, __int64, unsigned int *, __int64, __int64))hw_fence_interop_signal_hwfence;
    return 0;
  }
  else
  {
    printk(&unk_26F86, "synx_hwfence_init_interops", 459, v2, a1);
    return 4294967274LL;
  }
}
