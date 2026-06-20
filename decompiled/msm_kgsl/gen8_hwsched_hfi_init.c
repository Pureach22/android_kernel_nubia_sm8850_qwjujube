unsigned __int64 __fastcall gen8_hwsched_hfi_init(_QWORD *a1)
{
  __int64 v2; // x0
  unsigned __int64 v3; // x8
  __int64 v4; // x20
  unsigned __int64 result; // x0
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  __int64 v8; // x8
  int v9; // w10
  unsigned __int64 v10; // x20

  v2 = to_gen8_hfi((__int64)a1);
  v3 = a1[3085];
  v4 = v2;
  if ( v3 && v3 < 0xFFFFFFFFFFFFF001LL
    || (result = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                   a1,
                   0,
                   24000,
                   4,
                   0),
        a1[3085] = result,
        result < 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (*(_BYTE *)(a1[1783] + 33LL) & 0x80) == 0
      || (v6 = a1[3086]) != 0 && v6 < 0xFFFFFFFFFFFFF001LL
      || (result = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                     a1,
                     0,
                     24000,
                     4,
                     0),
          a1[3086] = result,
          result < 0xFFFFFFFFFFFFF001LL) )
    {
      v7 = *(_QWORD *)(v4 + 8);
      if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
      {
        result = a1[3081];
        if ( !result )
          goto LABEL_16;
      }
      else
      {
        result = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                   a1,
                   0,
                   13144,
                   4,
                   0);
        *(_QWORD *)(v4 + 8) = result;
        if ( result >= 0xFFFFFFFFFFFFF001LL )
          return result;
        v8 = *(_QWORD *)(result + 8);
        v9 = *(_DWORD *)(result + 184);
        *(_QWORD *)v8 = 0xD200000000LL;
        *(_QWORD *)(v8 + 8) = 0xC00000006LL;
        *(_QWORD *)(v8 + 16) = 0x300000003LL;
        *(_DWORD *)(v8 + 24) = 1;
        *(_DWORD *)(v8 + 28) = v9 + 848;
        *(_QWORD *)(v8 + 32) = 0x40000000000LL;
        *(_QWORD *)(v8 + 40) = 0;
        *(_QWORD *)(v8 + 48) = 0;
        *(_QWORD *)(v8 + 56) = 0;
        *(_DWORD *)(v8 + 72) = 1;
        *(_DWORD *)(v8 + 76) = v9 + 4944;
        *(_QWORD *)(v8 + 64) = 0;
        *(_QWORD *)(v8 + 80) = 0x40000000001LL;
        *(_QWORD *)(v8 + 88) = 0;
        *(_QWORD *)(v8 + 96) = 0;
        *(_QWORD *)(v8 + 104) = 0;
        *(_DWORD *)(v8 + 120) = 1;
        *(_DWORD *)(v8 + 124) = v9 + 9040;
        *(_QWORD *)(v8 + 112) = 0;
        *(_QWORD *)(v8 + 128) = 0x40000000002LL;
        memset((void *)(v8 + 136), 0, 0x2C0u);
        result = a1[3081];
        if ( !result )
          goto LABEL_16;
      }
      if ( result < 0xFFFFFFFFFFFFF001LL )
      {
LABEL_19:
        if ( result <= 0xFFFFFFFFFFFFF000LL )
          return 0;
        else
          return (unsigned int)result;
      }
LABEL_16:
      result = kthread_create_on_node(hfi_f2h_main_1, a1, 0xFFFFFFFFLL, "gmu_f2h");
      if ( result < 0xFFFFFFFFFFFFF001LL )
      {
        v10 = result;
        wake_up_process(result);
        a1[3081] = v10;
        sched_set_fifo(v10);
        result = a1[3081];
      }
      else
      {
        a1[3081] = result;
      }
      goto LABEL_19;
    }
  }
  return result;
}
