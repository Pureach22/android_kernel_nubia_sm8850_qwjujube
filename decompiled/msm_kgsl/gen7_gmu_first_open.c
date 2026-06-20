unsigned __int64 __fastcall gen7_gmu_first_open(unsigned __int64 a1)
{
  unsigned __int64 result; // x0
  __int64 v4; // x1
  __int64 v5; // x2
  unsigned __int64 profile_buffer; // x0
  unsigned int v9; // w9
  unsigned __int64 v15; // x8
  unsigned __int64 v17; // x9

  _X20 = (unsigned __int64 *)(a1 - 680);
  if ( (*(_QWORD *)(a1 - 680) & 1) != 0 )
  {
    if ( (*_X20 & 2) != 0 || (result = gen7_boot(a1), !(_DWORD)result) )
    {
LABEL_21:
      _X8 = (unsigned int *)(a1 + 11128);
      __asm { PRFM            #0x11, [X8] }
      do
        v9 = __ldxr(_X8);
      while ( __stxr(v9 + 1, _X8) );
      adreno_active_count_put(a1);
      return 0;
    }
  }
  else
  {
    result = ((__int64 (__fastcall *)(unsigned __int64))gen7_ringbuffer_init)(a1);
    if ( !(_DWORD)result )
    {
      result = gen7_microcode_read((_QWORD *)a1);
      if ( !(_DWORD)result )
      {
        result = gen7_init(a1);
        if ( !(_DWORD)result )
        {
          result = gen7_gmu_parse_fw(a1);
          if ( !(_DWORD)result )
          {
            result = *(_QWORD *)(a1 - 1760);
            if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
            {
              result = ((__int64 (__fastcall *)(unsigned __int64, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                         a1,
                         0,
                         0x10000,
                         4,
                         0);
              *(_QWORD *)(a1 - 1760) = result;
            }
            if ( result < 0xFFFFFFFFFFFFF001LL )
            {
              result = gen7_hfi_init(a1);
              if ( !(_DWORD)result )
              {
                kgsl_pwrctrl_request_state(a1, 2);
                result = gen7_gmu_first_boot(a1);
                if ( !(_DWORD)result )
                {
                  result = gen7_gpu_boot(a1);
                  if ( !(_DWORD)result )
                  {
                    adreno_get_bus_counters(a1, v4, v5);
                    *(_BYTE *)(a1 + 19673) = (*(_DWORD *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x200) != 0;
                    profile_buffer = adreno_create_profile_buffer(a1);
                    __asm { PRFM            #0x11, [X20] }
                    do
                      v15 = __ldxr(_X20);
                    while ( __stxr(v15 | 1, _X20) );
                    __asm { PRFM            #0x11, [X20] }
                    do
                      v17 = __ldxr(_X20);
                    while ( __stxr(v17 | 2, _X20) );
                    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x10) != 0 )
                      *(_BYTE *)(a1 + 20437) = 1;
                    *(_BYTE *)(a1 + 12960) = 1;
                    *(_QWORD *)(a1 + 10904) = ktime_get(profile_buffer);
                    kgsl_pwrctrl_set_state(a1, 2);
                    goto LABEL_21;
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
