unsigned __int64 __fastcall gen7_hwsched_first_open(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x21
  unsigned __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned __int64 v7; // x8
  __int64 v8; // x20
  unsigned __int64 v9; // x8
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 bus_counters; // x0
  unsigned int v15; // w9
  unsigned __int64 v22; // x9
  unsigned __int64 v25; // x10

  v2 = to_gen7_gmu(a1);
  if ( (*(_QWORD *)(v2 + 1096) & 1) != 0 )
  {
    result = gen7_hwsched_boot((_QWORD *)a1);
    if ( (_DWORD)result )
      return result;
    goto LABEL_27;
  }
  v3 = v2;
  adreno_hwsched_start(a1);
  result = gen7_microcode_read((_QWORD *)a1);
  if ( !(_DWORD)result )
  {
    v5 = *(_QWORD *)(a1 + 14264);
    if ( (*(_BYTE *)(v5 + 34) & 4) == 0
      || (result = adreno_get_firmware((_QWORD *)a1, *(const char **)(v5 + 104), a1 + 14304), !(_DWORD)result) )
    {
      result = gen7_init(a1);
      if ( !(_DWORD)result )
      {
        result = gen7_gmu_parse_fw(a1);
        if ( !(_DWORD)result )
        {
          result = gen7_gmu_memory_init(a1);
          if ( !(_DWORD)result )
          {
            v6 = to_gen7_gmu(a1);
            if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 34LL) & 8) == 0
              || ((v7 = *(_QWORD *)(v6 + 24), v8 = v6, v7) && v7 < 0xFFFFFFFFFFFFF001LL
               || (result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                              a1,
                              0,
                              4096,
                              1,
                              0),
                   *(_QWORD *)(v8 + 24) = result,
                   result < 0xFFFFFFFFFFFFF001LL))
              && ((v9 = *(_QWORD *)(v8 + 32)) != 0 && v9 < 0xFFFFFFFFFFFFF001LL
               || (result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                              a1,
                              0,
                              4096,
                              1,
                              0),
                   *(_QWORD *)(v8 + 32) = result,
                   result < 0xFFFFFFFFFFFFF001LL)) )
            {
              result = gmu_core_hwsched_memory_init(a1);
              if ( !(_DWORD)result )
              {
                result = gen7_hwsched_hfi_init(a1);
                if ( !(_DWORD)result )
                {
                  kgsl_pwrctrl_request_state(a1, 2);
                  result = gen7_hwsched_gmu_first_boot(a1);
                  if ( !(_DWORD)result )
                  {
                    result = gen7_hwsched_gpu_boot(a1);
                    if ( !(_DWORD)result )
                    {
                      bus_counters = adreno_get_bus_counters(a1, v10, v11);
                      *(_BYTE *)(a1 + 19673) = (*(_DWORD *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x200) != 0;
                      _X8 = (unsigned __int64 *)(v3 + 1096);
                      __asm { PRFM            #0x11, [X8] }
                      do
                        v22 = __ldxr(_X8);
                      while ( __stxr(v22 | 1, _X8) );
                      _X9 = (unsigned __int64 *)(v3 + 1096);
                      __asm { PRFM            #0x11, [X9] }
                      do
                        v25 = __ldxr(_X9);
                      while ( __stxr(v25 | 2, _X9) );
                      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x10) != 0 )
                        *(_BYTE *)(a1 + 20437) = 1;
                      *(_BYTE *)(a1 + 12960) = 1;
                      *(_QWORD *)(a1 + 10904) = ktime_get(bus_counters);
                      kgsl_pwrctrl_set_state(a1, 2);
LABEL_27:
                      _X8 = (unsigned int *)(a1 + 11128);
                      __asm { PRFM            #0x11, [X8] }
                      do
                        v15 = __ldxr(_X8);
                      while ( __stxr(v15 + 1, _X8) );
                      adreno_active_count_put(a1);
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
