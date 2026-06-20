__int64 __fastcall fence_ctl_signal(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        unsigned int a6,
        char a7)
{
  __int64 v7; // x30
  unsigned int v8; // w24
  unsigned int v9; // w25
  __int64 v18; // x28
  __int64 v19; // x28
  unsigned int v20; // w0
  unsigned int v21; // w22
  __int64 v22; // x4

  v8 = *(_DWORD *)(a1 + 632);
  v9 = a2[42];
  if ( (~msm_hw_fence_debug_level & 0x10001) != 0 )
  {
    if ( !a6 )
      goto LABEL_6;
  }
  else
  {
    v18 = v7;
    printk(&unk_2A302, "_fence_ctl_signal", 1875, a4, a5);
    v7 = v18;
    if ( !a6 )
      goto LABEL_6;
  }
  if ( *((_QWORD *)a2 + 18) )
    return hw_fence_utils_fence_error_cb(a2, *(_QWORD *)(a3 + 8), *(_QWORD *)(a3 + 16), a4, 0, a6);
LABEL_6:
  v19 = v7;
  if ( ((*((_BYTE *)a2 + 177) & 1) != 0 || *((_BYTE *)a2 + 176) == 1 && (a7 & 1) == 0)
    && (v20 = ((__int64 (__fastcall *)(__int64, unsigned int *, _QWORD, _QWORD, __int64, _QWORD, __int64, _QWORD, int))hw_fence_update_queue)(
                a1,
                a2,
                *(_QWORD *)(a3 + 8),
                *(_QWORD *)(a3 + 16),
                a4,
                0,
                a5,
                a6,
                1)) != 0 )
  {
    v21 = v20;
    if ( a2 )
      v22 = *a2;
    else
      v22 = 0xFFFFFFFFLL;
    printk(&unk_27376, "_fence_ctl_signal", 1891, v19, v22);
    return v21;
  }
  else if ( (*(_BYTE *)(a1 + 33520) & 1) != 0 || a2[42] != *(_DWORD *)(a1 + 636) )
  {
    if ( (a7 & 1) == 0 || (*((_BYTE *)a2 + 178) & 1) != 0 )
      hw_fence_ipcc_trigger_signal(a1, v8, v9, a2[41]);
    return 0;
  }
  else
  {
    return process_validation_client_loopback(a1, *a2);
  }
}
