unsigned __int64 __fastcall gen8_hwsched_first_open(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x21
  unsigned __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned __int64 v7; // x8
  __int64 v8; // x20
  unsigned __int64 v9; // x8
  __int64 v10; // x20
  unsigned int v13; // w9
  unsigned __int64 v16; // x9
  unsigned __int64 v23; // x11
  unsigned __int64 v26; // x11

  v2 = to_gen8_gmu(a1);
  if ( (*(_QWORD *)(v2 + 1040) & 1) != 0 )
  {
    result = gen8_hwsched_boot((_QWORD *)a1);
    if ( (_DWORD)result )
      return result;
    goto LABEL_32;
  }
  v3 = v2;
  adreno_hwsched_start(a1);
  result = gen8_microcode_read((_QWORD *)a1);
  if ( !(_DWORD)result )
  {
    v5 = *(_QWORD *)(a1 + 14264);
    if ( (*(_BYTE *)(v5 + 34) & 4) == 0
      || (result = adreno_get_firmware((_QWORD *)a1, *(const char **)(v5 + 104), a1 + 14304), !(_DWORD)result) )
    {
      result = gen8_init(a1);
      if ( !(_DWORD)result )
      {
        if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 34LL) & 0x20) != 0 )
        {
          _X8 = (unsigned __int64 *)(a1 + 1528);
          __asm { PRFM            #0x11, [X8] }
          do
            v16 = __ldxr(_X8);
          while ( __stxr(v16 | 0x80, _X8) );
        }
        result = ((__int64 (__fastcall *)(__int64))gen8_gmu_parse_fw)(a1);
        if ( !(_DWORD)result )
        {
          result = gen8_gmu_memory_init(a1);
          if ( !(_DWORD)result )
          {
            v6 = to_gen8_gmu(a1);
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
              v10 = *(_QWORD *)(a1 + 14264);
              result = gmu_core_hwsched_memory_init(a1);
              if ( !(_DWORD)result )
              {
                if ( *(_DWORD *)(v10 + 240) )
                  gmu_core_set_vrb_register(*(_QWORD *)(a1 + 8664), 4);
                result = gen8_hwsched_hfi_init(a1);
                if ( !(_DWORD)result )
                {
                  kgsl_pwrctrl_request_state(a1, 2);
                  result = gen8_hwsched_gmu_first_boot(a1);
                  if ( !(_DWORD)result )
                  {
                    result = gen8_hwsched_gpu_boot(a1);
                    if ( !(_DWORD)result )
                    {
                      *(_BYTE *)(a1 + 19673) = (*(_DWORD *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x200) != 0;
                      _X10 = (unsigned __int64 *)(v3 + 1040);
                      __asm { PRFM            #0x11, [X10] }
                      do
                        v23 = __ldxr(_X10);
                      while ( __stxr(v23 | 1, _X10) );
                      _X10 = (unsigned __int64 *)(v3 + 1040);
                      __asm { PRFM            #0x11, [X10] }
                      do
                        v26 = __ldxr(_X10);
                      while ( __stxr(v26 | 2, _X10) );
                      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x10) != 0 )
                        *(_BYTE *)(a1 + 20437) = 1;
                      if ( *(_BYTE *)(a1 + 14232) == 1 )
                      {
                        *(_BYTE *)(a1 + 12960) = 1;
                        *(_QWORD *)(a1 + 10904) = ktime_get(result);
                      }
                      kgsl_pwrctrl_set_state(a1, 2);
LABEL_32:
                      _X8 = (unsigned int *)(a1 + 11128);
                      __asm { PRFM            #0x11, [X8] }
                      do
                        v13 = __ldxr(_X8);
                      while ( __stxr(v13 + 1, _X8) );
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
