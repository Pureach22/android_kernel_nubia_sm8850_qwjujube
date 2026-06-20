__int64 __fastcall hw_fence_update_txq_with_client_data(
        unsigned __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int64 a5)
{
  __int64 v5; // x30
  void *v7; // x0
  const char *v8; // x1
  __int64 v9; // x2

  if ( !hw_fence_drv_data
    || (unsigned __int64)hw_fence_drv_data > 0xFFFFFFFFFFFFF000LL
    || (*(_BYTE *)(hw_fence_drv_data + 8) & 1) == 0 )
  {
    v7 = &unk_217EB;
    v8 = "hw_fence_check_hw_fence_driver";
    v9 = 2743;
LABEL_11:
    printk(v7, v8, v9, v5, a5);
    return 4294967274LL;
  }
  a5 = a2;
  if ( !a1 || a1 >= 0xFFFFFFFFFFFFF001LL )
  {
    v7 = &unk_211E0;
    v8 = "hw_fence_check_valid_client";
    v9 = 2759;
    goto LABEL_11;
  }
  if ( *(unsigned int *)(hw_fence_drv_data + 80) <= a2 )
  {
    printk(&unk_2AD72, "hw_fence_update_txq_with_client_data", 565, v5, a2);
    return 4294967274LL;
  }
  else
  {
    ((void (__fastcall *)(__int64, unsigned __int64, _QWORD, _QWORD))hw_fence_update_queue)(
      hw_fence_drv_data,
      a1,
      *(_QWORD *)(*(_QWORD *)(hw_fence_drv_data + 64) + (a2 << 7) + 8),
      *(_QWORD *)(*(_QWORD *)(hw_fence_drv_data + 64) + (a2 << 7) + 16));
    return 0;
  }
}
